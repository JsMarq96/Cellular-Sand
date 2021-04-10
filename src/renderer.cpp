#include "renderer.h"

void sRenderer::config_renderer(unsigned int    grid_width,
                                unsigned int    grid_height) {
    // Prepare the Grid
    float* grid_vertex = (float*) malloc(sizeof(float) * (grid_width + grid_height));

    // Since the grid is going to drawn using the line primitive,
    // we just use two points in clip space just for declaring
    // the grid
    int v_index = 0;
    for (int x = 0; x < grid_width; x++) {
        int tmp = v_index;
        // Point 1
        grid_vertex[v_index++] = (1.f / grid_width) * x;
        grid_vertex[v_index++] = 0.0f;

        // Point 2
        grid_vertex[v_index++] = grid_vertex[tmp];
        grid_vertex[v_index++] = 1.0f;
    }

    for (int y = 0; y < grid_width; y++) {
        int tmp = v_index;
        grid_vertex[v_index++] = 0.0f;
        grid_vertex[v_index++] = (1.f / grid_height) * y; // U coordinate;

        grid_vertex[v_index++] = 1.0f;
        grid_vertex[v_index++] = grid_vertex[tmp];
    }

    glGenVertexArrays(1, &grid_VAO);
    glGenBuffers(1, &grid_VBO);
    glBindVertexArray(grid_VAO);

    glBindBuffer(GL_ARRAY_BUFFER, grid_VBO);
    glBufferData(GL_ARRAY_BUFFER, (grid_width + grid_height) * sizeof(float), grid_vertex, GL_STATIC_DRAW);
    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), (void*) 0);

    glEnableVertexAttribArray(0);
    glBindVertexArray(0);
};
