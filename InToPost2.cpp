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

string Infix2Postfix(string infix)
{
    
    stack <string> operand;
    stack <char> symbol;
    int length = infix.length();
    bool flag = false;
    for(int i = 0; i < length; i++)
    {
        if(infix[i] >= '0' && infix[i] <= '9')
        {
            if(!flag)
            {
                string a(1, infix[i]);
                if(i == length -1)
                {
                    a += " ";
                }
                operand.push(a);
                flag = true;
            }
            else if(flag && i == length - 1)
            {
                string temp = operand.top();
                operand.pop();
                temp += infix[i];
                temp += " ";
                operand.push(temp);
            }
            else if(flag)
            {
                string temp = operand.top();
                operand.pop();
                temp += infix[i];
                operand.push(temp);
            }
            
        }
        else 
        {
            if(flag)
            {
                flag = false;   
                string temp = operand.top();
                temp += " ";
                operand.pop();
                operand.push(temp);
            }
            if(operatorCheck(infix[i]))
            {
                if(symbol.empty())
                    symbol.push(infix[i]);

                // else if( precedence(infix[i]) == precedence(symbol.top()) && infix[i] == '^' )
                // {
                //     symbol.push(infix[i]);
                // }
                else if(precedence(infix[i]) > precedence(symbol.top()))
                {
                    symbol.push(infix[i]);
                }
                else if (precedence(infix[i]) <= precedence(symbol.top()))
                {
                    while(!symbol.empty() && (precedence(infix[i]) <= precedence(symbol.top())) )
                    {
                    string op2 = operand.top();
                    operand.pop();
                    string op1 = operand.top();
                    operand.pop();
                    string subEx = op1 + op2 + symbol.top() + " ";
                    operand.push(subEx);
                    symbol.pop();
                    }
                    symbol.push(infix[i]);                        
                }
            }
            else if(infix[i] =='(')
            {
                symbol.push(infix[i]);
            }
            else if(infix[i] == ')')
            {
                while(!symbol.empty() && symbol.top() != '(')
                {
                    string op2 = operand.top();
                    operand.pop();
                    string op1 = operand.top();
                    operand.pop();
                    string subEx = op1 + op2 + symbol.top() + " ";
                    operand.push(subEx);
                    symbol.pop();
                }
                symbol.pop();
            }
        }
    }
    while(!symbol.empty())
    {
        string op2 = operand.top();
        operand.pop();
        string op1 = operand.top();
        operand.pop();
        string subEx = op1 + op2 + symbol.top() + " ";
        operand.push(subEx);
        symbol.pop();
    }
   
    return operand.top();
}
int main()
{
    string infix = "4^5^(6^7)";
    cout << Infix2Postfix(infix);

    return 0;
}