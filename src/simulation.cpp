#include <../include/simulation.h>

Simulation::Simulation(std::vector<Shape>& shapes): sugar_shapes(shapes) {
    grid = new Grid();
}
 
STATUS Simulation::setup() {
    for (Shape shape : sugar_shapes) {
        grid->draw(shape);
    }
    return STATUS::SIMULATION_SUCCESS;
}

STATUS Simulation::run() {
    return STATUS::SIMULATION_SUCCESS;
}