#include <stdlib.h>
#include "utils.h"

// Clear screen function (cross-platform)
void clear_screen() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}
