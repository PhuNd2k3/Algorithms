#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
// #include<stdio_ext.h>
// __fpurge(stdin);

// LIST STRUCTURE =============================================
typedef struct list_s
{
    int data;
    struct list_s *next;
} list_t, *root_t;

void showData(int data) { printf("%d ", data); }

list_t *createNewNode(const int data)
{
    list_t *newNode = (list_t *)malloc(sizeof(list_t));
    if (newNode == NULL)
        return NULL;

    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Traversing a list and show
root_t llPrint(root_t root)
{
    for (list_t *p = root; p != NULL; p = p->next)
        showData(p->data);
    printf("\n");
    return root;
}
int llSearch(root_t root, int data)
{
    for (list_t *p = root; p != NULL; p = p->next)
        if (p->data == data)
            return 1;
    return 0;
}

root_t llInit() { return NULL; }

list_t *llSeek(root_t root, int index)
{
    list_t *p = NULL;
    for (p = root; index > 0 && (p != NULL); index--)
        p = p->next;
    return p;
}

/* === Insert ============================================== */

root_t llInsertHead(root_t root, const int data)
{
    list_t *pNewNode = createNewNode(data);
    pNewNode->next = root;
    return (root_t)pNewNode;
}

root_t llInsertTail(root_t root, const int data)
{
    list_t *pNewNode = createNewNode(data);

    if (root == NULL)
        return (root_t)pNewNode;

    list_t *p = NULL;
    for (p = root; p->next != NULL; p = p->next)
        ;
    p->next = pNewNode;
    return root;
}
root_t llDeleteAll(root_t root)
{
    list_t *p = NULL;
    for (; root != NULL; root = p)
    {
        p = root->next;
        free(root);
    }
    return NULL;
}
int main()
{
    root_t list = llInit();
    char cmd[256];
    while (1)
    {
        int tmp;
        scanf("%s", cmd);
        if (strcmp(cmd, "InsertTail") == 0)
        {
            scanf("%d", &tmp);
            if (tmp > 0 && llSearch(list, tmp) == 0)
            {
                list = llInsertTail(list, tmp);
            }
        }
        else if (strcmp(cmd, "InsertHead") == 0)
        {
            scanf("%d", &tmp);
            if (tmp > 0 && llSearch(list, tmp) == 0)
            {
                list = llInsertHead(list, tmp);
            }
        }
        else if (strcmp(cmd, "Print") == 0)
        {
            scanf("%d", &tmp);
            if (tmp == 0)
            {
                llPrint(list);
            }
            else
            {
                int arr[256];
                int n = 0;
                root_t list_copy = llInit();
                for (list_t *p = list; p != NULL; p = p->next)
                {
                    if (p->data % 2 == 1)
                    {
                        list_copy = llInsertTail(list_copy, p->data);
                    }
                    else
                    {
                        arr[n] = p->data;
                        n++;
                    }
                }
                for (int i = n - 1; i >= 0; i--)
                {
                    list_copy = llInsertHead(list_copy, arr[i]);
                }
                llPrint(list_copy);
                llDeleteAll(list_copy);
            }
            llDeleteAll(list);
            break;
        }
    }
    return 0;
}