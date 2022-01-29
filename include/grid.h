#include <vector>

#include <constants.h>
#include <error.h>
#include <math_helpers.h>

enum Shape_type {
    CIRCLE = 0,
};

struct Circle {
    int radius;
    Coord centre;
};

struct Shape
{
    Shape_type type;
    union
    {
        Circle circle;
    };
};

class Grid {
    public:
        Grid();
        STATUS draw(Shape shape);

    private:
        std::vector<std::vector<int>> sugar_grid;
};