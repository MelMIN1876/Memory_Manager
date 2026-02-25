Scott Hendren CS-370 HW1: Memory Allocations/deallocations

## Driver.c ##
#
#       Header Files imported include: <stdio.h> <stdlib.h> "MemoryManager.h"
#
# Contains 1 method:
#       int main(int argc, char *argv[])
#
#           This is the entry point of the program where the argument(s) are taken from the command line, seed,
#           then the seed is casted to an int type using the method call "atoi()". This seed is used to seed 
#           the random number generator utilizing the method call "srand(seed)". Then a message is printed to 
#           the console that displays the seed and which file it is from, [Driver]. Then, the program declares 
#           and initializes the variable "running_ratio" to the method call "get_running_ratio()". Finally, 
#           after the program has ran its course a final message is printed displaying the average perfect square 
#           to nonperfect square ration, accurately to 6 decimal places, which is the value returned to the 
#           variable "running_ratio". 
#
## MemoryManager.c ##
#
#       Header Files imported include: <stdio.h> <stdlib.h> "MemoryManager.h" <math.h>
#
# Global Variable(s):
#       static int memory_allocations
#
# Contains 7 methods:
#       float get_running_ratio()
#             
#           calculates the running ration of perfect squares to nonperfect squares in each array, method calls
#           for allocating and deallocating memory for the arrays onto the heap (safely), and returns the average
#           perfect squares to nonperfect squares that occured during execution.
# 
#       int random_in_range(int lower_bound, int upper_bound)
#
#           utilizes radnom number generator seeded in Driver file, returns a number between "lower_bound" and 
#           "upper_bound", (inclusive, exclusive). 
#
#       int* safe_malloc(int size)
#
#           function performs a NULL check upon allocation of memory, terminates program gracefully with a message
#           if the system is out of memory (prevents undefined behavior). Returns a pointer to the allocated memory block
#
#       int* tracked_malloc(int size)
#
#           function calls "safe_malloc" to allocate memory and increments the internal "memory_allocations" counter
#
#       void tracked_free(void *pointer, int size)
#
#           function performs memory deallocation and decrements the internal "memory_allocations" counter.
#
#       void print_memory_summary()
#
#           prints the final summary of memory blocks that are till allocated, "0" if successful. Or prints a message
#           displaying that there is a potential memory leak.
#
#       int count_perfect_sqr(int *array, int size)
#
#           loops through the current array and counts the perfect squares inside of the array, returns the count of perfect squares
#
#
## MemoryManager.h ##
#
# Header file containing the methods described in "MemoryManager.c"
#