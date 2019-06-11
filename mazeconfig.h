#ifndef MAZECONFIG_H
#define MAZECONFIG_H

#include <stdint.h>

enum Direction :uint8_t
{
    North,
    West,
    South,
    East,
};

enum Action :uint8_t
{
    Front,
    Left,
    Rear,
    Right,
};


#endif // MAZECONFIG_H
