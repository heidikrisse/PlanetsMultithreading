// main.cpp
#include "include/planet.h"
#include "include/position_comparison.h"

#include <iostream>
#include <vector>
#include <thread>
#include <future>

int main()
{
    std::vector<Planet> planets{{0, 5, 2}, {-10, 7, -94}, {6042, 4, 8}, {-42, 55, 92}, {0, -54189072, 0}};

    std::vector<std::future<void>> results;

    int time_units{0};

    while (true)
    {
        results.clear();

        for (size_t i{0}; i < planets.size(); ++i)
        {
            for (size_t j{i + 1}; j < planets.size(); ++j)
            {
                results.emplace_back(std::launch::async, update_positions, std::ref(planets[i]), std::ref(planets[j]));
            }
        }

        for (auto &result : results)
        {
            result.get();
        }

        time_units++;

        bool all_planets_back_to_starting_position{true};

        for (const auto &planet : planets)
        {
            if (planet.position_change.x != 0 || planet.position_change.y != 0 || planet.position_change.z != 0)
            {
                all_planets_back_to_starting_position = false;
                break;
            }
        }

        if (all_planets_back_to_starting_position)
        {
            break;
        }
    }

    std::cout << time_units << '\n';

    return 0;
}
