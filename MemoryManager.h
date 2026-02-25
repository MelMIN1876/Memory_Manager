#ifndef MEMORY_MANAGER_H
#define MEMORY_MANAGER_H

float get_running_ratio();
int random_in_range(int lower_bound, int upper_bound);
int* safe_malloc(int size);
int* tracked_malloc(int size);
void tracked_free(void* pointer, int size);
void print_memory_summary();
int count_perfect_sqr(int *array, int size);

#endif