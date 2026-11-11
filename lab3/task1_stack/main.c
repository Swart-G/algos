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



static void handle_exit(int *running) {
    printf("Выход из программы...\n");
    *running = 0;
}

static void handle_stack_create(Stack **stack, int *exit_code) {
    if (*stack != NULL) {
        printf("Стек уже создан\n");
        return;
    }

    *stack = stack_create();
    if (*stack == NULL) {
        switch_error(-ENOMEM);
        *exit_code = ENOMEM;
    }
}

static void handle_stack_push(Stack *stack, int *exit_code) {
    int value;
    printf("Введите значение для записи в стек: ");
    if (scanf("%d", &value) != 1) {
        switch_error(-EIO);
        *exit_code = EIO;
        return;
    }

    int err = stack_push(stack, value);
    if (err != 0) {
        switch_error(err);
    }
}

static void handle_stack_pop(Stack *stack) {
    int value;
    int err = stack_pop(stack, &value);
    if (err == 0) {
        printf("Удалённый элемент: %d\n", value);
    } else {
        switch_error(err);
    }
}

static void handle_stack_is_empty(Stack *stack) {
    int res = stack_is_empty(stack);
    if (res < 0) {
        switch_error(res);
    } else if (res == 0) {
        printf("Стек не пуст\n");
    } else {
        printf("Стек пуст\n");
    }
}

static void handle_stack_print(Stack *stack) {
    int err = stack_print(stack);
    if (err != 0) {
        switch_error(err);
    }
}

static void handle_stack_autotest(void) {
    Stack *test_stack = stack_create();
    puts(test_stack != NULL ? "OK" : "FAIL");
    if (test_stack == NULL) {
        return;
    }

    int value = 0;
    puts(stack_is_empty(test_stack) == 1 ? "OK" : "FAIL");
    puts(stack_pop(test_stack, &value) == -ENOENT ? "OK" : "FAIL");
    puts(stack_push(test_stack, 10) == 0 ? "OK" : "FAIL");
    puts(stack_push(test_stack, 20) == 0 ? "OK" : "FAIL");
    puts(stack_is_empty(test_stack) == 0 ? "OK" : "FAIL");
    puts(stack_print(test_stack) == 0 ? "OK" : "FAIL");
    puts(stack_pop(test_stack, &value) == 0 && value == 20 ? "OK" : "FAIL");
    puts(stack_pop(test_stack, &value) == 0 && value == 10 ? "OK" : "FAIL");
    puts(stack_is_empty(test_stack) == 1 ? "OK" : "FAIL");
    puts(stack_destroy(test_stack) == 0 ? "OK" : "FAIL");
}

static void handle_unknown_command(void) {
    printf("Неизвестная команда\n");
}

int main(void) {
    int operation_id;
    int running = 1;
    int exit_code = 0;
    Stack *stack = NULL;

    printf("Task 1: Stack\n");

    while (running && exit_code == 0) {
        printf("------------------------------------\n"
            "0 - Выход\n"
            "1 - Создать стек\n"
            "2 - Добавить элемент в стек (push)\n"
            "3 - Извлечь элемент из стека (pop)\n"
            "4 - Проверка стека на пустоту\n"
            "5 - Вывод всех элементов стека\n"
            "6 - Автотест\n"
            "Введите команду цифрой: ");

        if (scanf("%d", &operation_id) != 1) {
            switch_error(-EIO);
            exit_code = EIO;
            break;
        }

        switch (operation_id) {
            case 0:
                handle_exit(&running);
                break;
            case 1:
                handle_stack_create(&stack, &exit_code);
                break;
            case 2:
                handle_stack_push(stack, &exit_code);
                break;
            case 3:
                handle_stack_pop(stack);
                break;
            case 4:
                handle_stack_is_empty(stack);
                break;
            case 5:
                handle_stack_print(stack);
                break;
            case 6:
                handle_stack_autotest();
                break;
            default:
                handle_unknown_command();
                break;
        }
    }

    stack_destroy(stack);
    return exit_code;
}
