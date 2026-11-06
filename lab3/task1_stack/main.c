#include "stack.h"

#include <stdio.h>
#include <errno.h>


void switch_error(int err) {
    switch (err) {
        case -EINVAL:
        printf("Ошибка аргумента, возможно стек не существует\n");
        break;

        case -ENOMEM:
        printf("Ошибка выделения памяти\n");
        break;

        case -ENOENT:
        printf("Стек пуст\n");
        break;

        case -EIO:
        printf("Ошибка ввода/вывода\n");
        break;

        default:
        printf("Неизвестная ошибка\n");
        break;
    }
}



int main(void) {

    int err, operation_id, value, res;
    Stack *stack = NULL;

    printf("Task 1: Stack\n");

    while (1) {
        printf("------------------------------------\n"
            "0 - Выход\n"
            "1 - Создать стек\n"
            "2 - Добавить элемент в стек (push)\n"
            "3 - Извлечь элемент из стека (pop)\n"
            "4 - Проверка стека на пустоту\n"
            "5 - Вывод всех элементов стека\n"
            "6 - Автопроверка\n"
            "Введите команду цифрой: ");


        err = scanf("%d", &operation_id);
        if (err != 1) {
            switch_error(-EIO);
            stack_destroy(stack);
            return EIO;
        }

        switch (operation_id) {
            case 0:
            stack_destroy(stack);
            return 0;

            case 1:
            if (stack == NULL) {
                stack = create_stack();
                if (stack == NULL) {
                    printf("Ошибка выделения памяти\n");
                    return ENOMEM;
                }
            } else {
                printf("Стек уже создан\n");
            }
            break;

            case 2:
            printf("Введите значение для записи в стек: ");
            err = scanf("%d", &value);
            if (err != 1) {
                switch_error(-EIO);
                stack_destroy(stack);
                return EIO;
            }
            err = stack_push(stack, value);
            if (err != 0) switch_error(err);
            break;

            case 3:
            err = stack_pop(stack, &value);
            if (err == 0) {
                printf("Удалённый элемент: %d\n", value);
            } else {
                switch_error(err);
            }
            break;

            case 4:
            res = stack_is_empty(stack);
            if (res < 0) {
                switch_error(res);
            } else {
                switch (res) {
                case 0:
                    printf("Стек не пуст\n");
                    break;
                case 1:
                    printf("Стек пуст\n");
                    break;
                }
            }
            break;

            case 5:
            err = stack_print(stack);
            if (err != 0) {
                switch_error(err);
            }
            break;

            case 6:
            test_stack(stack);
            break;

            default:
            printf("Неизвестная команда\n");
            break;
        }
    }
    return 0;
}