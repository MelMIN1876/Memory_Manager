#include <stdio.h>
#include <stdlib.h>
#include "MemoryManager.h"
#include <math.h>

static int memory_allocations = 0;

//calculate running ratio of perfect to nonperfect squares, calls methods for memory allocation and deallocation
//returns running ratio
float get_running_ratio()
{
    int maxIteration = 0;
    int numIterations = random_in_range(50, 200);
    float maxRatio = 0.0;
    float sumRatio = 0.0;

    printf("[MemoryManager] Number of iterations is: %d\n", numIterations);

    for(int i = 0; i < numIterations; i++)
    {
        int arraySize = random_in_range(50, 200);
        int *array = tracked_malloc(arraySize);

        for(int j = 0; j < arraySize; j++)
        {
            array[j] = random_in_range(50, 200);
        }

        int perfectSquares = count_perfect_sqr(array, arraySize);
        int nonPerfectSquares = arraySize - perfectSquares;
        float currentRatio = 0.0;

        if(nonPerfectSquares > 0)
        {
            currentRatio = (float)perfectSquares/nonPerfectSquares;
        }else{
            currentRatio = 0.0;
        }

        sumRatio += currentRatio;

        if(currentRatio > maxRatio)
        {
            maxRatio = currentRatio;
            maxIteration = i;
        }

        tracked_free(array, arraySize);
    }

    printf("[MemoryManager] Iteration with MAX perfect_sqr/non_perfect_sqr ratio: %d\n", maxIteration);

    print_memory_summary();

    return sumRatio / numIterations;
}

//returns random number in range [lower_bound, upper_bound)
int random_in_range(int lower_bound, int upper_bound)
{
    return ((rand() % (upper_bound - lower_bound)) + lower_bound);
}

//safely allocates memory 
int* safe_malloc(int size)
{
    int *pointer = (int*)malloc(size * sizeof(int));
    if(pointer == NULL)
    {
        printf("[MemoryManager] Error: pointer to memory was NULL\n");
        exit(EXIT_FAILURE);
    }
    return pointer;
}

//calls function for safe memory allocation and increments memory_allocations counter
int* tracked_malloc(int size)
{
    int *pointer = safe_malloc(size);
    memory_allocations++;
    return pointer;
}

//frees memory for array
void tracked_free(void *pointer, int size)
{
    if(pointer != NULL)
    {
        free(pointer);
        memory_allocations--;
    }
}

//prints summary for memory blocks still allocated OR warns user about potential memory leak
void print_memory_summary()
{
    if(memory_allocations > 0)
    {
        printf("[MemoryManager] WARNING: Potential memory leak detected!\n");
    }else{
        printf("[MemoryManager] Final summary - 0 memory blocks still allocated\n");
        printf("[MemoryManager] All Memory successfully freed\n");
    }
}

//returns count of perfect squares in the array
int count_perfect_sqr(int *array, int size)
{
    int count = 0;
    for(int i = 0; i < size; i++)
    {
        int sqrRoot = (int)sqrt(array[i]);
        if((sqrRoot * sqrRoot) == array[i])
        {
            count++;
        }
    }
    return count;
}