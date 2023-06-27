#include "quantum.h"

#ifdef SWAP_HANDS_ENABLE

__attribute__ ((weak))
const keypos_t PROGMEM hand_swap_config[MATRIX_ROWS][MATRIX_COLS] = 
{
    // left
    { {2, 3}, {1, 3}, {0, 3}},
    { {2, 4}, {1, 4}, {0, 4}},
    { {2, 5}, {1, 5}, {0, 5}},
    // right
    { {2, 0}, {1, 0}, {0, 0}},
    { {2, 1}, {1, 1}, {0, 1}},
    { {2, 2}, {1, 2}, {0, 2}},
};
#endif 