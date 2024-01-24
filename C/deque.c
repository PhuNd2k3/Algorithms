#include <stdio.h>

#define MAX 10

void pushFront(int *, int, int *, int *);
void pushBack(int *, int, int *, int *);
int popFront(int *, int *, int *);
int popback(int *, int *, int *);
int count(int *);
void display(int *arr)
{
    int i;

    printf("\n front:  ");
    for (i = 0; i < MAX; i++)
        printf("  %d", arr[i]);
    printf("  :rear");
}
int main()
{
    int a1[MAX];
    int f1, b1;

    f1 = b1 = -1;
    for (int i = 0; i < MAX; i++)
        a1[i] = -1;

    int a2[MAX];
    int f2, b2;

    f2 = b2 = -1;
    for (int i = 0; i < MAX; i++)
        a2[i] = -1;

    char cmd;
    int list;
    int m;
    while (1)
    {
        char c;
        do
        {
            scanf("%c", &c);
        } while (c == ' ' || c == '\n');
        cmd = c;
        if (cmd == '#')
            break;
        scanf("%c", &c);
        scanf("%d %d", &list, &m);
        if (cmd == 'I')
        {
            if (list == 1)
            {
                pushFront(a1, m, &f1, &b1);
            }
            else
            {
                pushFront(a2, m, &f2, &b2);
            }
        }
        else
        {
            if (list == 1)
            {
                pushBack(a1, m, &f1, &b1);
            }
            else
            {
                pushBack(a2, m, &f2, &b2);
            }
        }
    }
    int v1[MAX];
    int v2[MAX];
    int i1 = 1;
    int i2 = 1;
    do
    {
        int v = popFront(a1, &f1, &b1);
        if (v == -1)
        {
            break;
        }
        v1[i1] = v;
        i1++;
    } while (1);
    do
    {
        int v = popFront(a2, &f2, &b2);
        if (v == -1)
        {
            break;
        }
        v1[i2] = v;
        i2++;
    } while (1);
    int i = 1;
    int n1 = 1;
    int n2 = 1;
    while (n1 < i1 && n2 < i2)
    {
        if (i % 2 == 1)
        {
            printf("%d ", v1[n1]);
            n1++;
        }
        else
        {
            printf("%d ", v2[n2]);
            n2++;
        }
        i++;
    }
    while (n1 < i1)
    {
        printf("%d ", v1[i]);
    }
    while (n2 < i2)
    {
        printf("%d ", v2[i]);
    }
}

void pushFront(int *arr, int item, int *pfront, int *pback)
{
    int i, k, c;

    if (*pfront == 0 && *pback == MAX - 1)
    {
        // printf("\nDeque is full.\n");
        return;
    }

    if (*pfront == -1)
    {
        *pfront = *pback = 0;
        arr[*pfront] = item;
        return;
    }

    if (*pback != MAX - 1)
    {
        c = count(arr);
        k = *pback + 1;
        for (i = 1; i <= c; i++)
        {
            arr[k] = arr[k - 1];
            k--;
        }
        arr[k] = item;
        *pfront = k;
        (*pback)++;
    }
    else
    {
        (*pfront)--;
        arr[*pfront] = item;
    }
}

void pushBack(int *arr, int item, int *pfront, int *pback)
{
    int i, k;

    if (*pfront == 0 && *pback == MAX - 1)
    {
        // printf("\nDeque is full.\n");
        return;
    }

    if (*pfront == -1)
    {
        *pback = *pfront = 0;
        arr[*pback] = item;
        return;
    }

    if (*pback == MAX - 1)
    {
        k = *pfront - 1;
        for (i = *pfront - 1; i < *pback; i++)
        {
            k = i;
            if (k == MAX - 1)
                arr[k] = -1;
            else
                arr[k] = arr[i + 1];
        }
        (*pback)--;
        (*pfront)--;
    }
    (*pback)++;
    arr[*pback] = item;
}

int popFront(int *arr, int *pfront, int *pback)
{
    int item;

    if (*pfront == -1)
    {
        // printf("\nDeque is empty.\n");
        return -1;
    }

    item = arr[*pfront];
    arr[*pfront] = -1;

    if (*pfront == *pback)
        *pfront = *pback = -1;
    else
        (*pfront)++;

    return item;
}

int popback(int *arr, int *pfront, int *pback)
{
    int item;

    if (*pfront == -1)
    {
        // printf("\nDeque is empty.\n");
        return -1;
    }

    item = arr[*pback];
    arr[*pback] = -1;
    (*pback)--;
    if (*pback == -1)
        *pfront = -1;
    return item;
}

int count(int *arr)
{
    int c = 0, i;

    for (i = 0; i < MAX; i++)
    {
        if (arr[i] != -1)
            c++;
    }
    return c;
}