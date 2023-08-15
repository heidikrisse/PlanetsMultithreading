#ifndef PLANET_H
#define PLANET_H

struct Position
{
    int x;
    int y;
    int z;
};

class Planet
{
public:
    Position current_position; // current position
    Position position_change;  // How many steps per time unit
};

#endif
