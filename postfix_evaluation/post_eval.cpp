#include <iostream>
#include <stack>
#include <string.h>
#include <math.h>
#define max 20
using namespace std;
int eval(char a, char b, char c)
{
    if (c == '+')
        return (a + b);
    else if (c == '-')
    {
        return (b - a);
    }
    else if (c == '*')
    {
        return (a * b);
    }
    else if (c == '/')
    {
        return (b / a);
    }
    else
        return 0;
}
void posteval(string post)
{
    stack<int> s;
    int a, b, c;
    for (int i = 0; i < post.length(); i++)
    {
        if (isalnum(post[i]))
        {
            s.push(post[i] - '0');
        }
        else
        {

            a = int(s.top());
            s.pop();
            b = int(s.top());
            s.pop();
            c = eval(a, b, post[i]);
            s.push(c);
        }
    }
    cout << "ans :" << s.top();
    s.pop();
}

int main()
{
    char p[max];
    int n;
    cout << "how many elements are there in your expression?";
    cin >> n;
    cout << "enter the expression";
    for (int i = 0; i < n; i++)
    {
        cin >> p[i];
    }
    posteval(p);

    return 0;
}
