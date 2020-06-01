#include <iostream>
#include <stack>

/* In a given string, check if the parenthesis used are balanced */

using namespace std;

stack <char> mystack;

bool is_open_brace(const char& c)
{
    if (c == '(' || c == '{' || c == '[')
        return true;
    else
        return false;
}

bool match_paranthesis(const char& closing)
{
    if ((mystack.top() == '(' && closing == ')') ||
        (mystack.top() == '{' && closing == '}') ||
        (mystack.top() == '[' && closing == ']'))
        return true;
    else
        return false;
}

void check_balanced_paranthesis(string expr)
{
    for (char expr_char: expr )
    {
        if (is_open_brace(expr_char))
        {
            mystack.push(expr_char);
        }
        else if(expr_char == ')' || expr_char == '}' || expr_char == ']')
        {
                if (mystack.empty() || !match_paranthesis(expr_char))
                {
                    cout << "\nParanthesis not matched";
                    return;
                }
                else {
                    mystack.pop();
                    cout << "\nParanthesis matched ";
                }
        }
    }
    if (!mystack.empty())
        cout << "\n Paranthesis not matched";
}

int main()
{
    string str;

    cout << "\nEnter an expression of paranthesis";
    cin >> str;
    check_balanced_paranthesis(str);
}
