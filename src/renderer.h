#ifndef __RENDERER_H_
#define __RENDERER_H_

//**
// Rendering functions
//*/
#include <stdlib.h>
#include <GL/gl3w.h>

#include "cellular_automata.h"
#include "shader.h"

struct sRenderer {
    unsigned int     grid_VBO;
    unsigned int     grid_VAO;
    int              grid_elem_count;

    sShader          grid_shader;

    void prepare_shaders();

    void config_renderer(unsigned int   grid_width,
                         unsigned int   grid_height);

    void render_frame(sCellularAutomata    *actual_state);

    void cleanup() {};

};

#endif // __RENDERER_H_
