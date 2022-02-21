#include <algorithm>
#include <math.h>
#include <stdio.h>

#include <simulation.h>

int main() {
    // Centre = (10,10); Radius = 5
    Shape s1(SHAPE_TYPE::CIRCLE, Circle(10, 10, 5));

    // Centre = (35,35); Radius = 5
    Shape s2(SHAPE_TYPE::CIRCLE, Circle(35, 35, 5));

    std::vector<Shape> shapes{s1, s2};

    Simulation* sim = (Simulation*) new Simulation(shapes);
    sim->setup();

    // sim->print_grid();
    sim->run();

    return 0;
}
