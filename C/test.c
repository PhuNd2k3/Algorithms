#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct Product
{
    char type[256];
    char name[256];
    int cost;
} Product;

typedef struct Transaction
{
    int id;
    char date[256];
    int money;
    int isPayment;
} Transaction;

typedef struct Buyer
{
    char id[256];
    char name[256];
    int *numOfBoughtItems; // so san pham ma nguoi khach mua
    int *paymentForItems;  // so tien ma ho bo ra mua san pham
    int isReal;            // Khach da co du thong tin
    int allItems;          // Tong so san pham da mua
    int refund;
} Buyer;

// Tim kiem Buyer theo id
int getBuyer(Buyer *buyers, int N, char *id)
{
    int index = -1;
    for (int i = 0; i < N; i++)
    {
        if (buyers[i].isReal)
        {
            if (strcmp(buyers[i].id, id) == 0)
            {
                return i;
            }
            else
            {
                // index = i;
            }
        }
    }
    return -1; // index + 1;
}

// Tim ra buyer chua duoc gan thong tin
int findUnRealBuyer(Buyer *buyers, int N)
{
    for (int i = 0; i < N; i++)
    {
        if (!buyers[i].isReal)
            return i;
    }
    return -1;
}

// Tim kiem Product theo type
int getProduct(Product *products, int M, char *type)
{
    // int index = 0;
    for (int i = 0; i < M; i++)
    {
        // if(products[i].isReal)
        {
            if (strcmp(products[i].type, type) == 0)
            {
                return i;
            }
        }
    }
    return -1;
}

// Tim kiem Product theo type
int getProductByName(Product *products, int M, char *name)
{
    // int index = 0;
    for (int i = 0; i < M; i++)
    {
        // if(products[i].isReal)
        {
            if (strcmp(products[i].name, name) == 0)
            {
                return i;
            }
        }
    }
    return -1;
}

int main()
{
    int M, N;
    scanf("%d %d", &M, &N);
    Product products[M];
    for (int i = 0; i < M; i++)
    {
        char type[256];
        char name[256];
        int cost;
        scanf("%s %s %d", type, name, &cost);
        strcpy(products[i].type, type);
        strcpy(products[i].name, name);
        products[i].cost = cost;
    }

    Buyer buyers[N]; // Khai bao toi da co N khach
    for (int i = 0; i < N; i++)
    {
        buyers[i].isReal = 0;
        buyers[i].allItems = 0;
        buyers[i].numOfBoughtItems = (int *)malloc(M * sizeof(int));
        buyers[i].paymentForItems = (int *)malloc(M * sizeof(int));
        for (int j = 0; j < M; j++)
        {
            buyers[i].numOfBoughtItems[j] = 0;
            buyers[i].paymentForItems[j] = 0;
        }
        buyers[i].refund = 0;
    }

    int money, isPayment; //, isPayment;

    int maxRefund = -1;
    int countRefund = 0;
    int idRefund = -1;

    for (int i = 0; i < N; i++)
    {
        char idBuyer[256];
        char name[256];
        char date[256];
        char idProduct[256];
        int idTrans;
        char type[256];
        scanf("%d %s %s %s %s %s %d %d", &idTrans, date, idBuyer, name,
              idProduct, type,
              &money, &isPayment);
        int index = getBuyer(buyers, N, idBuyer);
        if (index == -1)
        {
            index = findUnRealBuyer(buyers, N);
        }
        if (index != -1)
        {
            buyers[index].isReal = 1;
            strcpy(buyers[index].name, name);
            strcpy(buyers[index].id, idBuyer);
            if (isPayment)
            {
                int indexProduct = getProduct(products, M, type);

                buyers[index].numOfBoughtItems[indexProduct] += money /
                                                                products[indexProduct].cost;
                buyers[index].allItems += buyers[index].numOfBoughtItems[indexProduct];
                buyers[index].paymentForItems[indexProduct] += money;
            }
            else
            {
                buyers[index].refund = 1;
                if (money > maxRefund)
                {
                    maxRefund = money;
                    idRefund = idTrans;
                    countRefund = 0;
                }
                if (money == maxRefund)
                {
                    countRefund++;
                }
            }
        }
    }

    char strCmd[256];
    scanf("%s", strCmd);
    // printf("%s\n", strCmd);
    if (strcmp(strCmd, "0") == 0 || strcmp(strCmd, "1") == 0 ||
        strcmp(strCmd, "2") == 0 || strcmp(strCmd, "3") == 0)
    {
        int count = 0;
        int maxPaymentForOneProduct = -1;
        int maxBoughtItems = -1;
        // char nameOfBuyer[256];
        int indexOfBuyer = -1;
        int cmd = atoi(strCmd);

        switch (cmd)
        {
        case 0:
            for (int i = 0; i < N; i++)
            {
                if (buyers[i].isReal)
                {
                    for (int j = 0; j < M; j++)
                    {
                        if (buyers[i].paymentForItems[j] >
                            maxPaymentForOneProduct)
                        {
                            maxPaymentForOneProduct = buyers[i].paymentForItems[j];
                            // strcpy(nameOfBuyer, buyers[i].name);
                            indexOfBuyer = i;
                        }
                    }
                }
            }

            // printf("%d\n", indexOfBuyer);
            if (indexOfBuyer != -1)
            {
                for (int i = 0; i < N; i++)
                {
                    if (buyers[i].isReal)
                    {
                        for (int j = 0; j < M; j++)
                        {
                            if (buyers[i].paymentForItems[j] ==
                                maxPaymentForOneProduct)
                            {
                                count++;
                            }
                        }
                    }
                }
            }
            if (count >= 2)
            {
                printf("%d", count);
            }
            else if (count == 0)
            {
                printf("-1");
            }
            else if (indexOfBuyer != -1)
            {
                printf("%s", buyers[indexOfBuyer].name);
            }
            break;
        case 1:
            for (int i = 0; i < N; i++)
            {
                if (buyers[i].isReal)
                {
                    // for(int j = 0; j < M; j++)
                    {
                        if (buyers[i].allItems >
                            maxBoughtItems)
                        {
                            maxBoughtItems = buyers[i].allItems;
                            // strcpy(nameOfBuyer, buyers[i].name);
                            indexOfBuyer = i;
                        }
                    }
                }
            }

            // printf("%d\n", indexOfBuyer);
            if (indexOfBuyer != -1)
            {
                for (int i = 0; i < N; i++)
                {
                    if (buyers[i].isReal)
                    {
                        // for(int j = 0; j < M; j++)
                        {
                            if (buyers[i].allItems == maxBoughtItems)
                            {
                                count++;
                            }
                        }
                    }
                }
            }
            if (count >= 2)
            {
                printf("%d", count);
            }
            else if (count == 0)
            {
                printf("-1");
            }
            else if (indexOfBuyer != -1)
            {
                printf("%s", buyers[indexOfBuyer].name);
            }
            break;
        case 2:
            // printf("=====%d====\n", countRefund);
            if (countRefund >= 2)
            {
                printf("%d", countRefund);
            }
            else if (countRefund == 0)
            {
                printf("-1");
            }
            else
            {
                printf("%d", idRefund);
            }
            break;
        case 3:
            count = 0;
            for (int i = 0; i < N; i++)
            {
                if (buyers[i].isReal == 1 && buyers[i].refund == 0)
                {
                    count++;
                }
            }
            printf("%d", count);
        }
    }
    else
    {
        int indexProduct = getProductByName(products, M, strCmd);
        if (indexProduct != -1)
        {
            int sum = 0;
            int buyersForProduct = 0;
            for (int i = 0; i < N; i++)
            {
                if (buyers[i].isReal)
                {
                    if (buyers[i].numOfBoughtItems[indexProduct] > 0)
                    {
                        sum += buyers[i].paymentForItems[indexProduct];
                        buyersForProduct++;
                    }
                }
            }
            if (buyersForProduct > 0)
            {
                double dblAvg = sum * 1.0 / buyersForProduct;
                int avg = (int)dblAvg;
                if (avg < dblAvg)
                {
                    avg++;
                }
                printf("%d", avg);
            }
        }
    }

    return 0;
}
