int reverse_array(int* arr, int arr_len) {
    for (int i = 0; i < arr_len/2; i++) {
        int current = arr[i];

        arr[i] = arr[arr_len - i - 1];
        arr[arr_len - i - 1] = current;
    }
    return 0;
}