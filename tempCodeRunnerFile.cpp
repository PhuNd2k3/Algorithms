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

public:
    Node *head;
    Node *tail;
    // Default constructor
    Linkedlist() { head = NULL; }
    void firstNode(int);
    void insertNode(Node *, int);
    void printList();
    Node *getHead();
    Node *findNodeToInsert(int);
    void insertHead(int);
    int localSearch(int);
};

void printSum(Linkedlist);
void findMinRoute()
{
    Linkedlist cityList;
    cityList.firstNode(s);
    cityList.insertNode(cityList.getHead(), t);
    int count = 2;
    visited[s] = 1;
    visited[t] = 1;
    int Fmin = INT_MAX;
    int f;
    int indexMin;
    while (count != n)
    {
        loop(i, 1, n)
        {
            if (!visited[i])
            {
                if (tsp[cityList.tail->data][i] < Fmin)
                {
                    Fmin = tsp[cityList.tail->data][i];
                    // cout << Fmin << endl;
                    indexMin = i;
                }
            }
        }
        count++;
        visited[indexMin] = 1;
        cityList.insertNode(cityList.tail, indexMin);
        Fmin = INT_MAX;
    }

    loop(i, 1, n / 2)
    {
        int search = 1;
        while (search)
        {
            search = cityList.localSearch(i);
            // cityList.printList();
            printSum(cityList);
        }
    }
    for (int i = n / 2; i >= 1; i--)
    {
        int search = 1;
        while (search)
        {
            search = cityList.localSearch(i);
            // cityList.printList();
            printSum(cityList);
        }
    }

    cityList.printList();
}

int main()
{
    freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin >> n;
    cout << n << "\n";
    loop(i, 1, n)
    {
        loop(j, 1, n)
        {
            cin >> tsp[i][j];
            if (i == j)
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
    int mark[N];
    Node *temp = head;
    memset(mark, 0, sizeof(mark));
    // Traverse the list.
    while (temp != NULL)
    {
        if (mark[temp->data])
        {
            cout << temp->data << " BOOOOOOO!" << endl;
            exit(0);
        }
        visited[temp->data] = 1;
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}
Node *Linkedlist::getHead()
{
    return head;
}
Node *Linkedlist::findNodeToInsert(int data)
{
    Node *minNode = NULL;
    // int Fmin = tsp[data][head->data] + tsp[tail->data][data] - tsp[tail->data][head->data];
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
int Linkedlist::localSearch(int u)
{

    Node *f = head->next;
    Node *s = f;
    loop(i, 1, u)
    {
        s = s->next;
    }
    Node *prevNode = head;

    while (s != tail)
    {

        for (Node *pNode = head; pNode != NULL; pNode = pNode->next)
        {
            if (pNode == prevNode)
                pNode = s->next;
            if (pNode == tail)
            {
                int v = tsp[tail->data][f->data] + tsp[s->data][head->data] - tsp[tail->data][head->data] - tsp[prevNode->data][f->data] - tsp[s->data][s->next->data] + tsp[prevNode->data][s->next->data];
                if (v < 0)
                {
                    prevNode->next = s->next;
                    tail->next = f;
                    tail = s;
                    s->next = NULL;
                    return 1;
                }
                break;
            }
            int v = tsp[pNode->data][f->data] + tsp[s->data][pNode->next->data] - tsp[pNode->data][pNode->next->data] - tsp[prevNode->data][f->data] - tsp[s->data][s->next->data] + tsp[prevNode->data][s->next->data];
            if (v < 0)
            {
                // cout << f->data << " " << s->data << " " << pNode->data << endl;
                prevNode->next = s->next;
                s->next = pNode->next;
                pNode->next = f;
                // cout << "change: " << v << endl;
                return 1;
            }
        }
        f = f->next;
        s = s->next;
        prevNode = prevNode->next;
    }

    f = head;
    s = f;
    loop(i, 1, u)
    {
        s = s->next;
    }
    for (Node *pNode = s->next; pNode != tail; pNode = pNode->next)
    {
        int v = tsp[tail->data][s->next->data] + tsp[pNode->data][f->data] + tsp[s->data][pNode->next->data] - tsp[tail->data][head->data] - tsp[s->data][s->next->data] - tsp[pNode->data][pNode->next->data];
        if (v < 0)
        {
            head = s->next;
            s->next = pNode->next;
            pNode->next = f;
            return 1;
        }
    }

    return 0;
}
void printSum(Linkedlist cityList)
{
    cout << "Sum: ";
    Node *pList = cityList.getHead();
    int sum = 0;
    while (pList->next != NULL)
    {
        sum += tsp[pList->data][pList->next->data];
        if (sum < 0)
        {
            cout << "\n"
                 << pList->data << " " << pList->next->data << " " << tsp[pList->data][pList->next->data] << endl;
            cout << sum << endl;
            // cityList.printList();
            exit(1);
        }
        pList = pList->next;
    }
    sum += tsp[pList->data][cityList.getHead()->data];
    cout << sum << endl;
}
