#ifndef ALGOS_ARRAY_H
#define ALGOS_ARRAY_H

int reverse_array(int* array, int size);
int print_array(int *array, int size);
int scan_array(int *array, int size);
int shift_array(int *array, int size, int shift);
long long count_inversions(int *array, int *buffer, int left_index, int right_index);
long long merge_count(int *array, int *buffer, int left_index, int middle_index, int right_index);

#endif //ALGOS_ARRAY_H
