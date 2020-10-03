//cpp
#include "loops.h"

int factorial(int num) {
    int result = 1;
    for (int i = num; i > 0; i--) {
        result = result * i;
    }

    return result;
}