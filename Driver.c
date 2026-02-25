#include <stdio.h>
#include <stdlib.h>
#include "MemoryManager.h"

//entry point of program, initializes random number generator, prints seed to console,
//calls method to get the running ratio of perfect to nonperfect sqaures
int main(int argc, char *argv[])
{
    int seed = atoi(argv[1]);
    srand(seed);

    printf("[Driver] With seed: %d\n", seed);

    float running_ratio = get_running_ratio();
    printf("[Driver] AVG perfect_sqr/non_perfect_sqr ratio: %.6f\n", running_ratio);
}