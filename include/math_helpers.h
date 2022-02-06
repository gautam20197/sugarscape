#pragma once

#include <algorithm>
#include <math.h>

struct Coord {
    public:
        int x;
        int y;
        Coord(int x, int y) : x(x), y(y) {};

        static int distance(Coord a, Coord b) {
            int distance_squared = (a.x - b.x) * (a.x - b.x);
            distance_squared += (a.y - b.y) * (a.y -b.y);
            return (int) sqrt(distance_squared);
        };
};