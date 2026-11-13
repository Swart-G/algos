#include "tree.h"

#include <stdio.h>
#include <errno.h>


void switch_error(int err) {
    switch (err) {
        case -EINVAL:
        printf("Ошибка аргумента, возможно дерево не существует\n");
        break;

        case -ENOMEM:
        printf("Ошибка выделения памяти\n");
        break;

        case -ENOENT:
        printf("Элемент не найден\n");
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

static void handle_tree_create(Tree **tree, int *exit_code) {
    if (*tree != NULL) {
        printf("Дерево уже создано\n");
        return;
    }

    *tree = tree_create();
    if (*tree == NULL) {
        switch_error(-ENOMEM);
        *exit_code = ENOMEM;
    } else {
        printf("Дерево создано\n");
    }
}

static void handle_tree_insert(Tree *tree, int *exit_code) {
    int value;
    printf("Введите значение для добавления в дерево: ");
    if (scanf("%d", &value) != 1) {
        switch_error(-EIO);
        *exit_code = EIO;
        return;
    }

    int err = tree_insert(tree, value);
    if (err != 0) {
        switch_error(err);
    } else {
        printf("Добавлен элемент: %d\n", value);
    }
}

static void handle_tree_delete(Tree *tree, int *exit_code) {
    int value;
    printf("Введите значение для удаления из дерева: ");
    if (scanf("%d", &value) != 1) {
        switch_error(-EIO);
        *exit_code = EIO;
        return;
    }

    TreeNode *node = NULL;
    int err = tree_search(tree, value, &node);
    if (err != 0) {
        switch_error(err);
        return;
    }
    if (node == NULL) {
        switch_error(-ENOENT);
        return;
    }

    err = tree_delete(tree, node);
    if (err == 0) {
        printf("Удалённый элемент: %d\n", value);
    } else {
        switch_error(err);
    }
}

static void handle_tree_search(Tree *tree, int *exit_code) {
    int value;
    printf("Введите значение для поиска в дереве: ");
    if (scanf("%d", &value) != 1) {
        switch_error(-EIO);
        *exit_code = EIO;
        return;
    }

    TreeNode *node = NULL;
    int err = tree_search(tree, value, &node);
    if (err != 0) {
        switch_error(err);
    } else if (node == NULL) {
        switch_error(-ENOENT);
    } else {
        printf("Найденный элемент: %d\n", node->value);
    }
}

static void handle_tree_print(Tree *tree) {
    if (tree == NULL) {
        switch_error(-EINVAL);
        return;
    }
    if (tree->root == NULL) {
        printf("Дерево пусто\n");
        return;
    }

    printf("Элементы дерева: ");
    tree_print_inorder(tree->root);
    printf("\n");
}

static void handle_tree_validate(Tree *tree) {
    if (tree == NULL) {
        switch_error(-EINVAL);
        return;
    }

    if (tree_validate(tree->root, NULL, NULL) == 0) {
        printf("Дерево является бинарным деревом поиска\n");
    } else {
        printf("Дерево не является бинарным деревом поиска\n");
    }
}

static void handle_tree_autotest(void) {
    Tree *test_tree = tree_create();
    puts(test_tree != NULL ? "OK" : "FAIL");
    if (test_tree == NULL) {
        return;
    }

    TreeNode *node = NULL;

    // Пустое дерево и ошибочные аргументы.
    puts(test_tree->root == NULL ? "OK" : "FAIL");
    puts(tree_search(test_tree, 10, &node) == 0 && node == NULL ? "OK" : "FAIL");
    puts(tree_validate(test_tree->root, NULL, NULL) == 0 ? "OK" : "FAIL");
    puts(tree_delete(test_tree, NULL) == -EINVAL ? "OK" : "FAIL");
    puts(tree_insert(NULL, 10) == -EINVAL ? "OK" : "FAIL");
    puts(tree_search(NULL, 10, &node) == -EINVAL ? "OK" : "FAIL");
    puts(tree_search(test_tree, 10, NULL) == -EINVAL ? "OK" : "FAIL");

    // Один элемент: поиск и удаление единственного узла.
    puts(tree_insert(test_tree, 10) == 0 ? "OK" : "FAIL");
    puts(tree_search(test_tree, 10, &node) == 0 && node != NULL && node->value == 10 ? "OK" : "FAIL");
    puts(tree_delete(test_tree, node) == 0 ? "OK" : "FAIL");
    puts(test_tree->root == NULL ? "OK" : "FAIL");

    // Удаление узла с двумя потомками и удаление листьев.
    puts(tree_insert(test_tree, 10) == 0 ? "OK" : "FAIL");
    puts(tree_insert(test_tree, 5) == 0 ? "OK" : "FAIL");
    puts(tree_insert(test_tree, 20) == 0 ? "OK" : "FAIL");
    puts(tree_validate(test_tree->root, NULL, NULL) == 0 ? "OK" : "FAIL");
    puts(tree_search(test_tree, 10, &node) == 0 && node != NULL && node->value == 10 ? "OK" : "FAIL");
    puts(tree_delete(test_tree, node) == 0 ? "OK" : "FAIL");
    puts(tree_search(test_tree, 10, &node) == 0 && node == NULL ? "OK" : "FAIL");
    puts(tree_validate(test_tree->root, NULL, NULL) == 0 ? "OK" : "FAIL");
    puts(tree_search(test_tree, 5, &node) == 0 && node != NULL && node->value == 5 ? "OK" : "FAIL");
    puts(tree_delete(test_tree, node) == 0 ? "OK" : "FAIL");
    puts(tree_search(test_tree, 20, &node) == 0 && node != NULL && node->value == 20 ? "OK" : "FAIL");
    puts(tree_delete(test_tree, node) == 0 ? "OK" : "FAIL");
    puts(test_tree->root == NULL ? "OK" : "FAIL");

    // Удаление корня с единственным левым потомком.
    puts(tree_insert(test_tree, 10) == 0 ? "OK" : "FAIL");
    puts(tree_insert(test_tree, 5) == 0 ? "OK" : "FAIL");
    puts(tree_search(test_tree, 10, &node) == 0 && node != NULL && node->value == 10 ? "OK" : "FAIL");
    puts(tree_delete(test_tree, node) == 0 ? "OK" : "FAIL");
    puts(tree_search(test_tree, 10, &node) == 0 && node == NULL ? "OK" : "FAIL");
    puts(tree_search(test_tree, 5, &node) == 0 && node != NULL && node->value == 5 ? "OK" : "FAIL");
    puts(tree_validate(test_tree->root, NULL, NULL) == 0 ? "OK" : "FAIL");

    // Удаление корня с единственным правым потомком.
    puts(tree_insert(test_tree, 20) == 0 ? "OK" : "FAIL");
    puts(tree_search(test_tree, 5, &node) == 0 && node != NULL && node->value == 5 ? "OK" : "FAIL");
    puts(tree_delete(test_tree, node) == 0 ? "OK" : "FAIL");
    puts(tree_search(test_tree, 5, &node) == 0 && node == NULL ? "OK" : "FAIL");
    puts(tree_search(test_tree, 20, &node) == 0 && node != NULL && node->value == 20 ? "OK" : "FAIL");
    puts(tree_validate(test_tree->root, NULL, NULL) == 0 ? "OK" : "FAIL");
    puts(tree_delete(test_tree, node) == 0 ? "OK" : "FAIL");
    puts(test_tree->root == NULL ? "OK" : "FAIL");

    // Несколько уровней, повторяющееся значение и удаление корня.
    puts(tree_insert(test_tree, 10) == 0 ? "OK" : "FAIL");
    puts(tree_insert(test_tree, 5) == 0 ? "OK" : "FAIL");
    puts(tree_insert(test_tree, 20) == 0 ? "OK" : "FAIL");
    puts(tree_insert(test_tree, 15) == 0 ? "OK" : "FAIL");
    puts(tree_insert(test_tree, 25) == 0 ? "OK" : "FAIL");
    puts(tree_insert(test_tree, 12) == 0 ? "OK" : "FAIL");
    puts(tree_insert(test_tree, 17) == 0 ? "OK" : "FAIL");
    puts(tree_insert(test_tree, 15) == 0 ? "OK" : "FAIL");
    puts(tree_search(test_tree, 99, &node) == 0 && node == NULL ? "OK" : "FAIL");
    puts(tree_search(test_tree, 10, &node) == 0 && node != NULL && node->value == 10 ? "OK" : "FAIL");
    puts(tree_delete(test_tree, node) == 0 ? "OK" : "FAIL");
    puts(tree_search(test_tree, 10, &node) == 0 && node == NULL ? "OK" : "FAIL");
    puts(tree_validate(test_tree->root, NULL, NULL) == 0 ? "OK" : "FAIL");

    puts(tree_destroy(test_tree) == 0 ? "OK" : "FAIL");
}

static void handle_unknown_command(void) {
    printf("Неизвестная команда\n");
}

int main(void) {
    int operation_id;
    int running = 1;
    int exit_code = 0;
    Tree *tree = NULL;

    printf("Task 3: Binary Tree\n");

    while (running && exit_code == 0) {
        printf("------------------------------------\n"
            "0 - Выход\n"
            "1 - Создать дерево\n"
            "2 - Добавить элемент в дерево (insert)\n"
            "3 - Удалить элемент из дерева (delete)\n"
            "4 - Найти элемент в дереве (search)\n"
            "5 - Вывод всех элементов дерева (inorder)\n"
            "6 - Проверка дерева (validate)\n"
            "7 - Автотест\n"
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
                handle_tree_create(&tree, &exit_code);
                break;
            case 2:
                handle_tree_insert(tree, &exit_code);
                break;
            case 3:
                handle_tree_delete(tree, &exit_code);
                break;
            case 4:
                handle_tree_search(tree, &exit_code);
                break;
            case 5:
                handle_tree_print(tree);
                break;
            case 6:
                handle_tree_validate(tree);
                break;
            case 7:
                handle_tree_autotest();
                break;
            default:
                handle_unknown_command();
                break;
        }
    }

    tree_destroy(tree);
    return exit_code;
}
