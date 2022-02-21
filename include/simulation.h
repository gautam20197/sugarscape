#include <vector>
#include <constants.h>
#include <grid.h>

#include "../lodepng/lodepng.h"

class Simulation {
    public:
        Simulation(std::vector<Shape>& shapes);
        STATUS setup();
        STATUS run();
        STATUS print_grid();
        ~Simulation();
    private:
        std::vector<Shape> sugar_shapes;
        unsigned char *image;
        Grid* grid;

        STATUS point_coordinates_to_pixel(int height, int width, int sugar);
        STATUS grid_to_image();
        STATUS save_image(int iteration);
};