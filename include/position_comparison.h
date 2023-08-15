#ifndef POSITION_COMPARISON_H
#define POSITION_COMPARISON_H

#include "planet.h"

// Function to compare x axis
void compare_position_x(Planet &planet1, Planet &planet2)
{
    if (planet1.current_position.x > planet2.current_position.x)
    {
        planet1.position_change.x--;
        planet2.position_change.x++;
    }
    else
    {
        planet1.position_change.x++;
        planet2.position_change.x--;
    }
}

// Function to compare y axis
void compare_position_y(Planet &planet1, Planet &planet2)
{
    if (planet1.current_position.y > planet2.current_position.y)
    {
        planet1.position_change.y--;
        planet2.position_change.y++;
    }
    else
    {
        planet1.position_change.y++;
        planet2.position_change.y--;
    }
}

// Function to compare z axis
void compare_position_z(Planet &planet1, Planet &planet2)
{

    if (planet1.current_position.z > planet2.current_position.z)
    {
        planet1.position_change.z--;
        planet2.position_change.z++;
    }
    else
    {
        planet1.position_change.z++;
        planet2.position_change.z--;
    }
}

// Function to update the positions with the position_change
void update_positions(Planet &planet1, Planet &planet2)
{
    compare_position_x(planet1, planet2);
    compare_position_y(planet1, planet2);
    compare_position_z(planet1, planet2);

    planet1.current_position.x += planet1.position_change.x;
    planet1.current_position.y += planet1.position_change.y;
    planet1.current_position.z += planet1.position_change.z;

    planet2.current_position.x += planet2.position_change.x;
    planet2.current_position.y += planet2.position_change.y;
    planet2.current_position.z += planet2.position_change.z;

    planet1.position_change.x = 0;
    planet1.position_change.y = 0;
    planet1.position_change.z = 0;

    planet2.position_change.x = 0;
    planet2.position_change.y = 0;
    planet2.position_change.z = 0;
}

#endif
