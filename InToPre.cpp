#include <iostream>
#include <stack>

using namespace std;

bool operatorCheck(char c)
{
    if(c == '+' || c == '-' || c == '*' || c == '/' ||c == '^')
    {
        return true;
    }
    else return false;
}

int precedence(char c)
{
    if(c == '+' || c == '-')
        return 1;
    else if(c == '*' || c == '/')
        return 2;
    else if(c == '^')
        return 3;
    else return -1;
}

string reverseString(string a)
{
    string b = "";
    for(int i = a.length()-1; i >= 0; i--)
    {
        if(a[i] == '(')
        {
        b += ')';
        }
        else if(a[i] == ')')
        {
            b += '(';
        }      
        else
            b += a[i];
    }
    return b;
}

// Day la cach khai bao stack ngay trong ham
string inToPre(string infix)
{
    string prefix = "";
    stack <char> s;

    infix = reverseString(infix);

    for(int i = 0; i < infix.length(); i++)
    {
        cout << "here" << endl;

        if( (infix[i] >= 'a' && infix[i] <= 'z') || (infix[i] >= 'A' && infix[i] <= 'Z') )
        {
            prefix += infix[i];
        }

        else if(infix[i] == '(')
            s.push(infix[i]);

        else if(infix[i] == ')')
        {
            while(s.top() != '(' && !s.empty())
            {
                prefix += s.top();
                s.pop();
            }
            s.pop();            
        }

        else if(operatorCheck(infix[i]))
        {
            if(s.empty())
                s.push(infix[i]);
            else
            {
                if (precedence(infix[i]) > precedence(s.top()))
                    s.push(infix[i]);
                else if((precedence(infix[i]) == precedence(s.top())) && infix[i] == '^')
                {
                    while(s.top() == '^')
                    {
                        prefix += s.top();
                        s.pop();
                    }
                    s.push(infix[i]);
                }
                else if((precedence(infix[i]) == precedence(s.top())))
                    s.push(infix[i]);
                else 
                {
                    while((precedence(infix[i]) < precedence(s.top())) && !s.empty())
                    {
                        prefix += s.top();
                        s.pop();
                    }
                    s.push(infix[i]);
                }
            }
        }
    }
    while(!s.empty())
    {
        if(operatorCheck(s.top()))
            prefix += s.top();
        s.pop();        
    }
    prefix = reverseString(prefix);
    return prefix;
}

int main()
{
    string infix;
    string prefix;
    cout << "Enter an infix expression: ";
    cin >> infix;
    cout << "Infix Expression: " << infix << endl;
    prefix = inToPre(infix);
    cout << "Prefix Expression: " << prefix << endl;

    return 0;
}