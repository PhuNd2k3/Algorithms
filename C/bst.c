#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
// #include<stdio_ext.h>
// __fpurge(stdin);

typedef struct
{
    char maLop[10];
    char phongThi[10];
} data_t;
typedef data_t key_t;
typedef struct node_s
{
    key_t key;
    struct node_s *left;
    struct node_s *right;
} node_t;

typedef node_t *tree_t;
int countStep = 0;
tree_t Search(char x[], tree_t Root)
{
    if (Root == NULL)
        return NULL;
    else if (strcmp(Root->key.maLop, x) == 0)
    {
        countStep++;
        return Root;
    }
    else if (strcmp(Root->key.maLop, x) < 0)
    {
        countStep++;
        return Search(x, Root->right);
    }
    else
    {
        countStep++;
        return Search(x, Root->left);
    }
}

void Insertnode_t(key_t x, tree_t *pRoot)
{
    if (*pRoot == NULL)
    {

        *pRoot = (node_t *)malloc(sizeof(node_t));
        (*pRoot)->key = x;
        (*pRoot)->left = NULL;
        (*pRoot)->right = NULL;
    }
    else if (strcmp(x.maLop, (*pRoot)->key.maLop) < 0)
        Insertnode_t(x, &((*pRoot)->left));
    else if (strcmp(x.maLop, (*pRoot)->key.maLop) > 0)
        Insertnode_t(x, &((*pRoot)->right));
}

key_t DeleteMin(tree_t *pRoot)
{
    key_t k;
    if ((*pRoot)->left == NULL)
    {
        k = (*pRoot)->key;
        (*pRoot) = (*pRoot)->right;
        return k;
    }
    else
        return DeleteMin(&(*pRoot)->left);
}

void Deletenode_t(char x[], tree_t *pRoot)
{
    if (*pRoot != NULL)
        if (strcmp(x, (*pRoot)->key.maLop) < 0)
            Deletenode_t(x, &(*pRoot)->left);
        else if (strcmp(x, (*pRoot)->key.maLop) > 0)
            Deletenode_t(x, &(*pRoot)->right);
        else if (((*pRoot)->left == NULL) && ((*pRoot)->right == NULL))
            *pRoot = NULL;
        else if ((*pRoot)->left == NULL)
            *pRoot = (*pRoot)->right;
        else if ((*pRoot)->right == NULL)
            *pRoot = (*pRoot)->left;
        else
            (*pRoot)->key = DeleteMin(&(*pRoot)->right);
}

void freetree(tree_t tree)
{
    if (tree != NULL)
    {
        freetree(tree->left);
        freetree(tree->right);
        free((void *)tree);
    }
}
tree_t mostRight;
void showData(key_t key)
{
    printf("%s", key.maLop);
    if (strcmp(key.maLop, mostRight->key.maLop) == 0)
    {
        printf("!");
    }
    else
    {
        printf(" ");
    }
}
void inOrderPrint(tree_t tree)
{
    if (tree != NULL)
    {
        inOrderPrint(tree->left);
        showData(tree->key);
        inOrderPrint(tree->right);
    }
}

void postOrderPrint(tree_t tree)
{
    if (tree != NULL)
    {
        postOrderPrint(tree->left);
        postOrderPrint(tree->right);
        showData(tree->key);
    }
}

void preOrderPrint(tree_t tree)
{
    if (tree != NULL)
    {
        showData(tree->key);
        preOrderPrint(tree->left);
        preOrderPrint(tree->right);
    }
}

int main()
{
    tree_t tree = NULL;
    char cmd[256];
    data_t tmp;
    // char check[256][256];
    // int n = 0;
    while (1)
    {
        scanf("%s", cmd);
        if (strcmp(cmd, "insert") == 0)
        {
            scanf("%s", tmp.maLop);
            scanf("%s", tmp.phongThi);
            Insertnode_t(tmp, &tree);
        }
        else if (strcmp(cmd, "inOrder") == 0)
        {
            mostRight = tree;
            while (1)
            {
                if (mostRight->right != NULL)
                    mostRight = mostRight->right;
                else
                {
                    break;
                }
            }
            inOrderPrint(tree);
            printf("\n");
        }
        else if (strcmp(cmd, "countStep") == 0)
        {
            char v[10];
            scanf("%s", v);
            Search(v, tree);
            printf("%d\n", countStep);
            countStep = 0;
        }
        else
        {
            break;
        }
    }
    return 0;
}