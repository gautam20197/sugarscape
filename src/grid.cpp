#include <../include/grid.h>

Grid::Grid() {
    sugar_grid.resize(HEIGHT_GRID);
    for (auto row : sugar_grid) {
        row.resize(WIDTH_GRID);
    }

    for (int i = 0; i < sugar_grid.size(); i++) {
        for (int j = 0; j < sugar_grid[0].size(); j++) {
            sugar_grid[i][j] = 0;
        }
    }
}

STATUS Grid::draw(Shape s) {
    if (s.type == CIRCLE) {
        Circle c = s.circle;
        for (int i = 0; i < sugar_grid.size(); i++) {
            for (int j = 0; j < sugar_grid[0].size(); j++) {
                Coord curr(i,j);
                int distance = Coord::distance(curr, c.centre);
                if (distance <= c.radius) {
                    int sugar_to_add = MAX_SUGAR * ((c.radius - distance)/c.radius);
                    sugar_grid[i][j] = std::min(MAX_SUGAR, sugar_grid[i][j] + sugar_to_add);
                }
            }
        }
    }

    return STATUS::GRID_SUCCESS;
}