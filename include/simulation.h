#include <vector>
#include <constants.h>
#include <grid.h>

class Simulation {
    public:
        Simulation(std::vector<Shape>& shapes);
        STATUS setup();
        STATUS run();
        STATUS print_grid();
    private:

        std::vector<Shape> sugar_shapes;
        Grid* grid;
};