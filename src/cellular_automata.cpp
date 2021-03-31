#include "cellular_automata.h"

void sCellularAutomata::init() {
    for (int i = 125; i < 350; i++) {
        for (int j = 470; j < 500; j++) {
            grid1[index(i, j)] = SAND;
        }
    }
}


void sCellularAutomata::update() {
    eCellType *current, *to_write;

    // Based on the swapchain, assign the grids
    if (swap_chain) {
        current = grid1;
        to_write = grid2;
    } else {
        current = grid2;
        to_write = grid1;
    }

    // Clean the recipient
    memset(to_write, NONE, GRID_WIDTH * GRID_HEIGHT);

    for (int x = 0; x < GRID_WIDTH; x++ ) {
        for (int y = 0; y < GRID_HEIGHT; y++) {
            switch(current[index(x, y)]) {
                case NONE:
                    break;
                case SAND: sand_behaviour(x, y,
                                          to_write,
                                          current);
                    break;
            }
        }
    }

    // Update swapchain marker
    swap_chain = !swap_chain;
};


inline void sCellularAutomata::sand_behaviour(int x,
                                              int y,
                                              eCellType *to_write,
                                              eCellType *to_read) {
    // Behaviour of particles, with bounds testing
    if (x > 0) {
         if (to_read[index(x, y-1)] == NONE) {
             to_write[index(x, y-1)] = SAND;
             return;
         }

         if (to_read[index(x-1, y-1)] == NONE) {
             to_write[index(x-1, y-1)] = SAND;
             return;
         }

         if (to_read[index(x+1, y-1)] == NONE) {
             to_write[index(x+1, y-1)] = SAND;
             return;
         }
    }

    to_write[index(x,y)] = SAND;
}
