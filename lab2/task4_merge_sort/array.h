#ifndef ALGOS_ARRAY_H
#define ALGOS_ARRAY_H

int reverse_array(int* array, int size);
int print_array(int *array, int size);
int scan_array(int *array, int size);
int shift_array(int *array, int size, int shift);
/* Границы включены; вызывающий код гарантирует, что они внутри массива.
 * Возвращает 0 при успехе, EINVAL при некорректных аргументах. */
int merge_sort(int *array, int left_index, int right_index);
int merge_groups(int *array, int left_index, int middle_index, int right_index);

#endif //ALGOS_ARRAY_H
