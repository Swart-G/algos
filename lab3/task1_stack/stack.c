#include "stack.h"
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>

Stack *create_stack(void) {
    Stack *stack = malloc(sizeof(Stack));
    if (stack == NULL) {
        return NULL;
    }
    stack->top = NULL;
    return stack;
}

int stack_push(Stack *stack, int value) {
    if (stack == NULL) {
        return -EINVAL;
    }

    StackNode *newNode = malloc(sizeof(StackNode));
    if (newNode == NULL) {
        return -ENOMEM;
    }

    newNode->value = value;
    newNode->next = stack->top;
    stack->top = newNode;
    return 0;
}

int stack_pop(Stack *stack, int *value) {
    if (stack == NULL) {
        return -EINVAL;
    }
    if (stack->top == NULL) {
        return -ENOENT;
    }

    StackNode *oldtop = stack->top;

    if (value != NULL) {
        *value = stack->top->value;
    }
    stack->top = stack->top->next;
    free(oldtop);
    return 0;
}

int stack_is_empty(Stack *stack) {
    if (stack == NULL) {
        return -EINVAL;
    }
    if (stack->top == NULL) {
        return 1;
    }
    return 0;
}

int stack_destroy(Stack *stack) {
    if (stack == NULL) {
        return -EINVAL;
    }

    while (stack_is_empty(stack) == 0) {
        stack_pop(stack, NULL);
    }
    free(stack);
    return 0;
}

int stack_print(Stack *stack) {
    if (stack == NULL) {
        return -EINVAL;
    }
    if (stack_is_empty(stack) == 1) {
        return -ENOENT;
    }

    StackNode *currentNode = stack->top;
    printf("Элементы стека:\n");
    while (currentNode != NULL) {
        printf("%d\n", currentNode->value);
        currentNode = currentNode->next;
    }
    return 0;
}

int test_stack(Stack *stack) {
    int errors = 0, value;

    if (stack != NULL) {
        printf("Стек уже существует\n");
        return 1;
    }

    printf("\n=== Автоматическое тестирование ===\n");

    stack = create_stack();
    if (stack == NULL) {
        printf("[FAIL] Создание стека\n");
        return 1;
    }
    printf("[OK] Стек создан\n");

    // Пустой стек
    if (stack_is_empty(stack) == 1) {
        printf("[OK] Новый стек пуст\n");
    } else {
        printf("[FAIL] Новый стек должен быть пуст\n");
        errors++;
    }

    // Один элемент
    printf("\n--- Один элемент ---\n");

    if (stack_push(stack, 10) != 0) {
        printf("[FAIL] push(10)\n");
        errors++;
    } else {
        printf("[OK] push(10)\n");

        if (stack_is_empty(stack) == 0) {
            printf("[OK] Стек не пуст\n");
        } else {
            printf("[FAIL] Стек должен быть не пуст\n");
            errors++;
        }

        if (stack_pop(stack, &value) == 0 && value == 10) {
            printf("[OK] pop: получено %d, ожидалось 10\n", value);
        } else {
            printf("[FAIL] pop: ожидалось 10\n");
            errors++;
        }
    }

    if (stack_is_empty(stack) == 1) {
        printf("[OK] После извлечения стек пуст\n");
    } else {
        printf("[FAIL] После извлечения стек должен быть пуст\n");
        errors++;
    }

    // Несколько элементов
    printf("\n--- Несколько элементов ---\n");

    if (stack_push(stack, 10) != 0 ||
        stack_push(stack, 20) != 0 ||
        stack_push(stack, 30) != 0) {
        printf("[FAIL] Добавление элементов\n");
        errors++;
    } else {
        printf("[OK] Добавлены элементы 10, 20, 30\n");

        printf("Ожидаемый стек: 30, 20, 10\n");

        if (stack_print(stack) == 0) {
            printf("[OK] Вывод стека выполнен\n");
        } else {
            printf("[FAIL] Вывод стека\n");
            errors++;
        }

        if (stack_is_empty(stack) == 0) {
            printf("[OK] После вывода стек не пуст\n");
        } else {
            printf("[FAIL] Вывод изменил состояние стека\n");
            errors++;
        }

        // Проверка порядка LIFO
        int expected[] = {30, 20, 10};

        for (int i = 0; i < 3; i++) {
            if (stack_pop(stack, &value) == 0 &&
                value == expected[i]) {
                printf("[OK] pop: получено %d\n", value);
            } else {
                printf("[FAIL] pop: ожидалось %d\n", expected[i]);
                errors++;
            }
        }
    }

    if (stack_is_empty(stack) == 1) {
        printf("[OK] Стек пуст после извлечения элементов\n");
    } else {
        printf("[FAIL] Стек должен быть пуст\n");
        errors++;
    }

    // Очистка перед следующим тестом
    while (stack_is_empty(stack) == 0) {
        if (stack_pop(stack, NULL) != 0) {
            printf("[FAIL] Очистка стека\n");
            errors++;
            break;
        }
    }

    // Удаление без получения значения
    printf("\n--- Удаление без получения значения ---\n");

    if (stack_is_empty(stack) != 1) {
        printf("[FAIL] Стек не пуст перед проверкой\n");
        errors++;
    } else if (stack_push(stack, 40) == 0 &&
               stack_pop(stack, NULL) == 0 &&
               stack_is_empty(stack) == 1) {
        printf("[OK] push(40), pop(NULL)\n");
        printf("[OK] После удаления стек пуст\n");
    } else {
        printf("[FAIL] Удаление без получения значения\n");
        errors++;
    }

    // Уничтожение заполненного стека
    printf("\n--- Уничтожение заполненного стека ---\n");

    Stack *temp = create_stack();

    if (temp == NULL) {
        printf("[FAIL] Создание временного стека\n");
        errors++;
    } else {
        printf("[OK] Временный стек создан\n");

        if (stack_push(temp, 100) == 0 &&
            stack_push(temp, 200) == 0 &&
            stack_push(temp, 300) == 0) {
            printf("[OK] Временный стек заполнен: 300, 200, 100\n");
        } else {
            printf("[FAIL] Заполнение временного стека\n");
            errors++;
        }

        if (stack_destroy(temp) == 0) {
            printf("[OK] Временный стек уничтожен\n");
        } else {
            printf("[FAIL] Уничтожение временного стека\n");
            errors++;
        }
    }

    // Очистка основного тестового стека
    printf("\n--- Завершение тестирования ---\n");

    while (stack_is_empty(stack) == 0) {
        if (stack_pop(stack, NULL) != 0) {
            printf("[FAIL] Очистка основного стека\n");
            errors++;
            break;
        }
    }

    if (stack_is_empty(stack) == 1) {
        printf("[OK] Основной стек пуст\n");
    } else {
        printf("[FAIL] Основной стек не очищен\n");
        errors++;
    }

    if (stack_destroy(stack) == 0) {
        printf("[OK] Основной стек уничтожен\n");
    } else {
        printf("[FAIL] Уничтожение основного стека\n");
        errors++;
    }

    printf("\n=== Тестирование завершено ===\n");
    printf("Ошибок: %d\n", errors);

    if (errors == 0) {
        printf("[OK] Все тесты пройдены\n");
    } else {
        printf("[FAIL] Некоторые тесты не пройдены\n");
    }

    return errors;
}