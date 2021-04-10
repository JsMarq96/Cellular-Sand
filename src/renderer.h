#ifndef __RENDERER_H_
#define __RENDERER_H_

//**
// Rendering functions
//*/
#include <stdlib.h>
#include <GL/gl3w.h>
#include "cellular_automata.h"

struct sRenderer {
    unsigned int     grid_VBO;
    unsigned int     grid_VAO;

    void config_renderer(unsigned int   grid_width,
                         unsigned int   grid_height);

};

#endif // __RENDERER_H_
