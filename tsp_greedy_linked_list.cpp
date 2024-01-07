#include <bits/stdc++.h>
using namespace std;
#define N 1001
#define loop(i, a, b) for (int i = a; i <= b; i++)
int n;
int tsp[N][N];
int s, t;
int dmin = INT_MAX;
int visited[N];
class Node
{
public:
    int data;
    Node *next;

    // Default constructor
    Node()
    {
        data = 0;
        next = NULL;
    }

    // Parameterised Constructor
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};
class Linkedlist
{
    Node *head;
    Node *tail;

public:
    // Default constructor
    Linkedlist() { head = NULL; }
    void firstNode(int);
    void insertNode(Node *, int);
    void printList();
    Node *getHead();
    Node *findNodeToInsert(int);
    void insertHead(int);
    Node *lastCheck();
};
void printSum(Linkedlist);
int countSum(int res[])
{
    int sum = 0;
    loop(i, 1, n - 1)
    {
        sum += tsp[res[i]][res[i + 1]];
    }
    sum += tsp[res[n]][res[1]];
    return sum;
}
void findMinRoute()
{
    Linkedlist cityList;
    cityList.firstNode(s);
    cityList.insertNode(cityList.getHead(), t);
    int count = 2;
    visited[s] = 1;
    visited[t] = 1;
    while (count != n)
    {
        loop(i, 1, n)
        {
            if (!visited[i])
            {
                Node *nodeFounded = cityList.findNodeToInsert(i);
                if (nodeFounded != NULL)
                {
                    cityList.insertNode(nodeFounded, i);
                }
                else
                    cityList.insertHead(i);
                visited[i] = 1;
                count++;
                break;
            }
        }
    }
    // cityList.printList();
    // printSum(cityList);
    // cout << endl;
    int res[N];
    int newRes[N];
    Node *temp = cityList.getHead();
    for (int i = 1; i <= n; i++)
    {
        res[i] = temp->data;
        temp = temp->next;
    }
    int change = 0;
    do
    {
        change = 0;
        int ia;
        int ic;
        int a;
        int b;
        int c, d;
        loop(j, 1, n - 4)
        {
            ia = j;
            a = res[j];
            b = res[j + 1];
            loop(i, ia + 2, n - 1)
            {
                ic = i;
                c = res[i];
                d = res[i + 1];
                if ((tsp[a][b] + tsp[c][d]) > (tsp[a][c] + tsp[b][d]))
                {
                    loop(k, 1, ia)
                    {
                        newRes[k] = res[k];
                    }
                    loop(k, ic + 1, n)
                    {
                        newRes[k] = res[k];
                    }
                    newRes[ia + 1] = c;
                    newRes[ic] = b;
                    int k = ia + 1 + 1;
                    int j = ic - 1;
                    int size = j - k + 1;
                    loop(q, 1, size)
                    {
                        newRes[k++] = res[j--];
                    }
                    cout << countSum(newRes) << endl;
                    change = 1;
                    loop(i, 1, n)
                    {
                        res[i] = newRes[i];
                    }
                    break;
                }
            }
        }
    } while (change == 1);

    loop(i, 1, n)
    {
        cout << res[i] << " ";
    }
    cout << "\n"
         << countSum(res) << endl;
}

int main()
{
    freopen("input.txt", "r", stdin);

    cin >> n;
    cout << n << "\n";
    loop(i, 1, n)
    {
        loop(j, 1, n)
        {
            cin >> tsp[i][j];
            if (tsp[i][j] == 0)
                tsp[i][j] = INT_MAX;
            if (dmin > tsp[i][j])
            {
                dmin = tsp[i][j];
                s = i;
                t = j;
            }
        }
    }
    findMinRoute();
}
void Linkedlist::insertHead(int data)
{
    Node *newNode = new Node(data);
    newNode->next = head;
    head = newNode;
}

void Linkedlist::firstNode(int data)
{
    // Create the new Node.
    Node *newNode = new Node(data);

    head = newNode;
    tail = newNode;
}
void Linkedlist::insertNode(Node *curNode, int data)
{
    // Create the new Node.
    Node *newNode = new Node(data);
    if (curNode == tail)
        tail = newNode;
    newNode->next = curNode->next;
    curNode->next = newNode;
}
void Linkedlist::printList()
{
    Node *temp = head;

    // Traverse the list.
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}
Node *Linkedlist::getHead()
{
    return head;
}
Node *Linkedlist::findNodeToInsert(int data)
{
    Node *minNode = NULL;
    // int Fmin = tsp[data][head->data];
    int Fmin = INT_MAX;
    for (Node *pNode = head; pNode->next != NULL; pNode = pNode->next)
    {
        int f = tsp[pNode->data][data] + tsp[data][pNode->next->data] - tsp[pNode->data][pNode->next->data];
        if (f < Fmin)
        {
            Fmin = f;
            minNode = pNode;
        }
    }
    return minNode;
}
Node *Linkedlist::lastCheck()
{
    int Fmin = tsp[tail->data][head->data];
    Node *minNode = NULL;
    Node *prevNode = head;
    Node *tailNode = tail;
    Node *headNode = head;

    for (Node *pNode = head->next; pNode->next != NULL; pNode = pNode->next)
    {

        int f = tsp[prevNode->data][pNode->next->data] + tsp[prevNode->data][pNode->next->data] + tsp[tail->data][pNode->data] + tsp[pNode->data][head->data] - tsp[prevNode->data][pNode->data] - tsp[pNode->data][pNode->next->data];
        prevNode = pNode;
        if (f < Fmin)
        {
            Fmin = f;
            minNode = pNode;
        }
    }
    if (minNode != NULL)
    {
        prevNode = head;
        while (prevNode->next != minNode)
        {
            prevNode = prevNode->next;
        }

        prevNode->next = minNode->next;
        tailNode->next = minNode;
        minNode->next = NULL;
        tail = minNode;
    }
    return minNode;
}
void printSum(Linkedlist cityList)
{
    Node *pList = cityList.getHead();
    int sum = 0;
    while (pList->next != NULL)
    {
        sum += tsp[pList->data][pList->next->data];
        pList = pList->next;
    }
    sum += tsp[pList->data][cityList.getHead()->data];
    cout << endl;
    cout << sum << endl;
}
