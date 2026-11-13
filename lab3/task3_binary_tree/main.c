#include "tree.h"

#include <stdio.h>
#include <errno.h>


void switch_error(int err) {
    switch (err) {
        case -EINVAL:
        printf("Ошибка аргумента, возможно очередь не существует\n");
        break;

        case -ENOMEM:
        printf("Ошибка выделения памяти\n");
        break;

        case -ENOENT:
        printf("Очередь пуста\n");
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

static void handle_queue_create(Queue **queue, int *exit_code) {
    if (*queue != NULL) {
        printf("Очередь уже создана\n");
        return;
    }

    *queue = queue_create();
    if (*queue == NULL) {
        switch_error(-ENOMEM);
        *exit_code = ENOMEM;
    }
}

static void handle_queue_enqueue(Queue *queue, int *exit_code) {
    int value;
    printf("Введите значение для записи в очередь: ");
    if (scanf("%d", &value) != 1) {
        switch_error(-EIO);
        *exit_code = EIO;
        return;
    }

    int err = queue_enqueue(queue, value);
    if (err != 0) {
        switch_error(err);
    }
}

static void handle_queue_dequeue(Queue *queue) {
    int value;
    int err = queue_dequeue(queue, &value);
    if (err == 0) {
        printf("Удалённый элемент: %d\n", value);
    } else {
        switch_error(err);
    }
}

static void handle_queue_is_empty(Queue *queue) {
    if (queue == NULL) {
        switch_error(-EINVAL);
        return;
    }

    int res = queue_is_empty(queue);
    if (res < 0) {
        switch_error(res);
    } else if (res == 0) {
        printf("Очередь не пуста\n");
    } else {
        printf("Очередь пуста\n");
    }
}

static void handle_queue_print(Queue *queue) {
    int err = queue_print(queue);
    if (err != 0) {
        switch_error(err);
    }
}

static void handle_queue_autotest(void) {
    Queue *test_queue = queue_create();
    puts(test_queue != NULL ? "OK" : "FAIL");
    if (test_queue == NULL) {
        return;
    }

    int value = 0;
    puts(queue_is_empty(test_queue) == 1 ? "OK" : "FAIL");
    puts(queue_dequeue(test_queue, &value) == -ENOENT ? "OK" : "FAIL");
    puts(queue_enqueue(test_queue, 10) == 0 ? "OK" : "FAIL");
    puts(queue_enqueue(test_queue, 20) == 0 ? "OK" : "FAIL");
    puts(queue_is_empty(test_queue) == 0 ? "OK" : "FAIL");
    puts(queue_print(test_queue) == 0 ? "OK" : "FAIL");
    puts(queue_front(test_queue, &value) == 0 && value == 10 ? "OK" : "FAIL");
    puts(queue_dequeue(test_queue, &value) == 0 && value == 10 ? "OK" : "FAIL");
    puts(queue_dequeue(test_queue, &value) == 0 && value == 20 ? "OK" : "FAIL");
    puts(queue_is_empty(test_queue) == 1 ? "OK" : "FAIL");
    puts(queue_destroy(test_queue) == 0 ? "OK" : "FAIL");
}

static void handle_unknown_command(void) {
    printf("Неизвестная команда\n");
}

int main(void) {
    int operation_id;
    int running = 1;
    int exit_code = 0;
    Queue *queue = NULL;

    printf("Task 2: Queue\n");

    while (running && exit_code == 0) {
        printf("------------------------------------\n"
            "0 - Выход\n"
            "1 - Создать очередь\n"
            "2 - Добавить элемент в очередь (enqueue)\n"
            "3 - Извлечь элемент из очереди (dequeue)\n"
            "4 - Проверка очереди на пустоту\n"
            "5 - Вывод всех элементов очереди\n"
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
                handle_queue_create(&queue, &exit_code);
                break;
            case 2:
                handle_queue_enqueue(queue, &exit_code);
                break;
            case 3:
                handle_queue_dequeue(queue);
                break;
            case 4:
                handle_queue_is_empty(queue);
                break;
            case 5:
                handle_queue_print(queue);
                break;
            case 6:
                handle_queue_autotest();
                break;
            default:
                handle_unknown_command();
                break;
        }
    }

    queue_destroy(queue);
    return exit_code;
}
