#include <vector>

#include <constants.h>
#include <error.h>
#include <grid.h>

class Simulation {
    public:
        Simulation(std::vector<Shape>& shapes);
        STATUS setup();
        STATUS run();
    private:

        std::vector<Shape> sugar_shapes;
        Grid* grid;
};