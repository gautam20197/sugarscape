#include <vector>
#include <stdio.h>

#include <constants.h>
#include <error.h>
#include <math_helpers.h>
#include <shape.h>

class Grid {
    public:
        Grid();
        STATUS draw(Shape shape);
        STATUS print();
        STATUS get(int x, int y, int& sugar);

    private:
        std::vector<std::vector<int>> sugar_grid;
};