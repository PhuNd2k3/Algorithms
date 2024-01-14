#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct Question
{
    int numberInS[4][101];
    int key[101];
} Question;

typedef struct Human
{
    int numberInKey[4];
    int Answer[101];
    int point;
    int atYear;
    int atHour;
    char id[256];
} Human;

int getIndexById(Human H[], int N, char *id)
{
    for (int i = 0; i < N; i++)
    {
        if (strcmp(H[i].id, id) == 0)
        {
            return i;
        }
    }
    return -1;
}

int main()
{
    int N, M;
    scanf("%d %d", &N, &M);
    // printf("%d %d\n", N, M);
    Human H[N];
    Question Q;

    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 101; j++)
        {
            Q.numberInS[i][j] = 0;
        }
    }
    for (int i = 0; i < N; i++)
    {
        int d, m, y, h, mt, s;
        char id[256];
        for (int k = 0; k < 4; k++)
        {
            H[i].numberInKey[k] = 0;
        }
        H[i].point = 0;
        scanf("%d-%d-%d-%d-%d-%d", &d, &m, &y, &h, &mt, &s);
        scanf("%s", id);
        H[i].atYear = y;
        H[i].atHour = h;
        // printf("%d-%d-%d-%d-%d-%d %s\n", d, m, y, h, mt, s, id);

        strcpy(H[i].id, id);
        for (int j = 0; j < M; j++)
        {
            char c;
            scanf("%c", &c);
            while (c == ' ')
            {
                scanf("%c", &c);
            }

            H[i].Answer[j] = c - 65;
            H[i].numberInKey[c - 65]++;
            Q.numberInS[c - 65][j]++;
        }
    }
    char strCmd[256];
    scanf("%s", strCmd);
    if (strcmp(strCmd, "Times:") == 0)
    {
        int X;
        char c;
        char check[256][256];
        scanf("%d %c", &X, &c);
        // printf("%d %c\n", X, c);
        int count = 0;
        for (int i = 0; i < N; i++)
        {
            if (H[i].numberInKey[c - 65] > X)
            {
                if (count == 0)
                {
                    strcpy(check[count], H[i].id);
                    count++;
                }
                else
                {
                    int flag = 0;
                    for (int j = 0; j < count; j++)
                    {
                        if (strcmp(check[j], H[i].id) == 0)
                            flag++;
                    }
                    if (flag == 0)
                    {
                        strcpy(check[count], H[i].id);
                        count++;
                    }
                }
            }
        }
        printf("%d", count);
    }
    else if (strcmp(strCmd, "Hour:") == 0)
    {
        int Hour;
        scanf("%d", &Hour);
        char check[256][256];
        int count = 0;
        for (int i = 0; i < N; i++)
        {
            if (H[i].atHour == Hour)
            {
                if (count == 0)
                {
                    strcpy(check[count], H[i].id);
                    count++;
                }
                else
                {
                    int flag = 0;
                    for (int j = 0; j < count; j++)
                    {
                        if (strcmp(check[j], H[i].id) == 0)
                            flag++;
                    }
                    if (flag == 0)
                    {
                        strcpy(check[count], H[i].id);
                        count++;
                    }
                }
            }
        }
        printf("%d", count);
    }
    else if (strcmp(strCmd, "At") == 0)
    {
        int S;
        char c;
        scanf("%d %c", &S, &c);
        char check[256][256];

        int count = 0;
        for (int i = 0; i < N; i++)
        {
            if (H[i].Answer[S - 1] == c - 65)
            {
                if (count == 0)
                {
                    strcpy(check[count], H[i].id);
                    count++;
                }
                else
                {
                    int flag = 0;
                    for (int j = 0; j < count; j++)
                    {
                        if (strcmp(check[j], H[i].id) == 0)
                            flag++;
                    }
                    if (flag == 0)
                    {
                        strcpy(check[count], H[i].id);
                        count++;
                    }
                }
            }
        }
        printf("%d", count);
    }
    else if (strcmp(strCmd, "Review:") == 0)
    {
        for (int i = 0; i < M; i++)
        {
            char c;
            scanf("%c", &c);
            while (c == ' ')
            {
                scanf("%c", &c);
            }
            Q.key[i] = c - 65;
            for (int j = 0; j < N; j++)
            {
                if (H[j].Answer[i] == Q.key[i])
                {
                    H[j].point++;
                }
            }
        }
        int Fmax = 0;
        int indexMax;
        int count = 0;
        char check[256][256];

        for (int i = 0; i < N; i++)
        {
            if (H[i].point > Fmax)
            {
                Fmax = H[i].point;
                indexMax = i;
            }
        }
        for (int i = 0; i < N; i++)
        {
            if (H[i].point == Fmax)
            {
                if (count == 0)
                {
                    strcpy(check[count], H[i].id);
                    count++;
                }
                else
                {
                    int flag = 0;
                    for (int j = 0; j < count; j++)
                    {
                        if (strcmp(check[j], H[i].id) == 0)
                            flag++;
                    }
                    if (flag == 0)
                    {
                        strcpy(check[count], H[i].id);
                        count++;
                    }
                }
            }
        }
        if (count >= 2)
        {
            printf("%d", count);
        }
        else
        {
            printf("%s", H[indexMax].id);
        }
    }
    else
    {
        int cmd = atoi(strCmd);
        if (cmd >= 2020)
        {
            char check[256][256];
            int count = 0;
            for (int i = 0; i < N; i++)
            {
                if (H[i].atYear == cmd - 2000)
                {
                    if (count == 0)
                    {
                        strcpy(check[count], H[i].id);
                        count++;
                    }
                    else
                    {
                        int flag = 0;
                        for (int j = 0; j < count; j++)
                        {
                            if (strcmp(check[j], H[i].id) == 0)
                                flag++;
                        }
                        if (flag == 0)
                        {
                            strcpy(check[count], H[i].id);
                            count++;
                        }
                    }
                }
            }
            printf("%d", count);
        }
    }
    return 0;
}