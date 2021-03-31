#ifndef __CELULAR_AUTOMATA_H_
#define __CELULAR_AUTOMATA_H_
/**
 * Basic cellular automata behaviour
 * By Juan S. Marquerie
 * */

#include <stdio.h>
#include <string.h>

#define GRID_WIDTH 500
#define GRID_HEIGHT 500

enum eCellType : unsigned char {
    NONE = 0,
    SAND = 1 // i dont like it...
};

inline int index(int x, int y) { return (GRID_HEIGHT * y) + x; }

struct sCellularAutomata {
         bool          swap_chain      = true;

    enum eCellType     grid1 [GRID_WIDTH * GRID_HEIGHT] = { NONE };
    enum eCellType     grid2 [GRID_WIDTH * GRID_HEIGHT] = { NONE };

    // Sets the initial state for the simulation
    void init();

    void update();

    // Physics behabiours
    void sand_behaviour(int x, int y, eCellType *to_write, eCellType *to_read);

    inline eCellType* get_render_target() {
        return (swap_chain) ? grid1 : grid2;
    }
};

#endif // __CELULAR_AUTOMATA_H_
