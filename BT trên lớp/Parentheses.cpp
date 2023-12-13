#include <iostream>
#include <stack>

using namespace std; // Sử dụng using namespace std để không cần viết std:: trước mỗi thành phần

int main()
{
    char k;
    stack<char> parentheses;

    while (k != '\n')
    {
        k = fgetc(stdin);
        if (k == '{' || k == '(' || k == '[')
        {
            parentheses.push(k);
        }
        else if (k == '}' || k == ')' || k == ']')
        {
            if (parentheses.empty())
            {
                cout << "0";
                return 0;
            }

            char openBracket = parentheses.top();
            parentheses.pop();

            char expectedBracket;
            switch (openBracket)
            {
            case '{':
                expectedBracket = '}';
                break;
            case '(':
                expectedBracket = ')';
                break;
            case '[':
                expectedBracket = ']';
                break;
            default:
                break;
            }

            if (k != expectedBracket)
            {
                cout << "0";
                return 0;
            }
        }
    }

    if (!parentheses.empty())
    {
        cout << "0";
    }
    else
    {
        cout << "1";
    }

    return 0;
}
