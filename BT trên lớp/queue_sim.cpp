// C++
#include <bits/stdc++.h>
using namespace std;
int main()
{
    stack<int> stack1;
    stack<int> stack2;
    while (true)
    {
        string k;
        cin >> k;
        if (k == "#")
            break;
        if (k == "PUSH")
        {
            while (!stack1.empty())
            {
                stack2.push(stack1.top());
                stack1.pop();
            }
            int n;
            cin >> n;
            stack1.push(n);
            while (!stack2.empty())
            {
                stack1.push(stack2.top());
                stack2.pop();
            }
        }
        if (k == "POP")
        {
            if (stack1.empty())
            {
                cout << "NULL" << endl;
            }
            else
            {
                cout << stack1.top() << endl;
                stack1.pop();
            }
        }
    }
    return 0;
}