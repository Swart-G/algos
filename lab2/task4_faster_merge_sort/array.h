#ifndef ALGOS_ARRAY_H
#define ALGOS_ARRAY_H

int print_array(int *array, int size);
int scan_array(int *array, int size);
/* Границы включены; вызывающий код гарантирует, что они внутри массива.
 * buffer — отдельный массив того же размера, без перекрытия с array.
 * Возвращает 0 при успехе, EINVAL при некорректных аргументах. */
int merge_sort(int *array, int *buffer, int left_index, int right_index);
int merge_groups(int *array, int *buffer, int left_index, int middle_index, int right_index);

#endif //ALGOS_ARRAY_H
