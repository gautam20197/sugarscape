#include <simulation.h>

Simulation::Simulation(std::vector<Shape>& shapes): sugar_shapes(shapes) {
    grid = new Grid();
    image = new unsigned char[HEIGHT_IMAGE * WIDTH_IMAGE * 4];
}
 
STATUS Simulation::setup() {
    for (Shape shape : sugar_shapes) {
        grid->draw(shape);
    }
    return STATUS::SIMULATION_SUCCESS;
}

STATUS Simulation::print_grid() {
    grid->print();
    return STATUS::SIMULATION_SUCCESS;
}

STATUS Simulation::point_coordinates_to_pixel(int height, int width, int sugar) {
    int scaling_to_height = HEIGHT_IMAGE/HEIGHT_GRID;
    int scaling_to_width = WIDTH_IMAGE/WIDTH_GRID;

    for (int i = height * scaling_to_height; i < (height * scaling_to_height + scaling_to_height); i++) {
        for (int j = width * scaling_to_width; j < (width * scaling_to_width + scaling_to_width); j++) {
            int target_pixel = i * WIDTH_IMAGE + j;
            float sugar_f = (float) sugar;
            float a = 255.0 * float(sugar_f/MAX_SUGAR);
            image[target_pixel * 4] = 255;
            image[target_pixel * 4 + 1] = 255;
            image[target_pixel * 4 + 2] = 0;
            image[target_pixel * 4 + 3] = (int) a;
        }
    }
}

STATUS Simulation::grid_to_image() {
    for (int i = 0; i < HEIGHT_GRID; i++) {
        for (int j = 0; j < WIDTH_GRID; j++) {
            int sugar = 0;
            grid->get(i,j,sugar);
            if (sugar > 0) {
                point_coordinates_to_pixel(i, j, sugar);
            }
        }
    }
    return STATUS::SIMULATION_SUCCESS;
}

STATUS Simulation::save_image(int iteration) {
    char path[256];
    sprintf(path, "images/Frame%05d.png", iteration);
    lodepng_encode32_file(path, image, HEIGHT_IMAGE, WIDTH_IMAGE);
}

STATUS Simulation::run() {
    grid_to_image();
    for (int i = 0; i < TIME_STEPS; i++) {
        save_image(i);
    }
    return STATUS::SIMULATION_SUCCESS;
}

Simulation::~Simulation() {
    delete(image);
}