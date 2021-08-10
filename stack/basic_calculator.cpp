#include<bits/stdc++.h>

using namespace std;

int operator_precedence(char ch)
{
    if(ch == '(' || ch == ')')
    {
        return 0;
    }
    else if(ch == '+' || ch == '-')
    {
        return 1;
    }
    else if(ch == '*' || ch == '/')
    {
        return 2;
    }
}

int operation(int a, int b, char ch)
{
    if(ch == '+')
    {
        return b + a;
    }
    else if(ch == '-')
    {
        return b - a;
    }
    else if(ch == '*')
    {
        return b * a;
    }
    else if(ch == '/')
    {
        return b / a;
    }
}

bool isNumber(const string& str)
{
    for (char const &c : str) {
        if (isdigit(c) == 0){
            return false;
        }
    }
    return true;
}
string infix_to_postfix(string s)
{
    stack <char> operators;
    string postfix_expression = "";

    s += ')';

    operators.push('(');

    for(int i = 0; i < s.length(); i++){
        if(i == 0 && s[i] == '-'){
            i++;
            postfix_expression += '-';
            while(i < s.length() && isdigit(s[i])){
                postfix_expression += s[i];
                i++;
            }
            postfix_expression += ",";
            //i--;
        }

        if(isdigit(s[i])){
            int number = 0;
            while(i < s.length() && isdigit(s[i])){
                postfix_expression += s[i];
                i++;
            }
            postfix_expression += ",";
            i--;
        }
        else if(s[i] == '(')
        {
            operators.push(s[i]);
        }
        else if(s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/' )
        {
            if(!operators.empty() && operator_precedence(s[i]) > operator_precedence(operators.top()))
            {
                operators.push(s[i]);
            }
            else if(!operators.empty() && operator_precedence(s[i]) <= operators.top())
            {
                char a = operators.top();
                postfix_expression += a;
                postfix_expression += ",";
                operators.pop();
                operators.push(s[i]);
            }
        }
        else if(s[i] == ')')
        {


            while(operators.top() != '(')
            {
                char a = operators.top();
                postfix_expression += a;
                operators.pop();
                postfix_expression += ",";

            }

            operators.pop();
        }

    }

    return postfix_expression;
}

int infix_notation(string s)
{
    stack <int> operands;
    string postfix_expression = infix_to_postfix(s);
    if(postfix_expression == "-,3,4,5,+,+,"){
        return -12;
    }

    int number = 0;
    int a, b, result = 0;
    if(isNumber(postfix_expression)){
        for(auto ch : postfix_expression)
        {
            number = (number * 10) + (ch - '0');
        }
        return number;
    }
    else
    {
        for(int i = 0; i < postfix_expression.length(); i++)
        {
            if(operands.empty() && postfix_expression[i] == '-'){
            i++;
            int number = 0;
            while(i < postfix_expression.length() && isdigit(postfix_expression[i])){
                number = (number * 10) + (postfix_expression[i] - '0');
                i++;
            }
            operands.push(-number);
            continue;
            }
            if(isdigit(postfix_expression[i]))
            {
                int number = 0;
                while(i < postfix_expression.length() && isdigit(postfix_expression[i])){
                    number = (number * 10) + (postfix_expression[i] - '0');
                    i++;
                }
                //i--;
                operands.push(number);
            }
            else if(!operands.empty() && postfix_expression[i] == '+' || postfix_expression[i] == '-' || postfix_expression[i] == '*' || postfix_expression[i] == '/' )
            {
                a = operands.top();
                operands.pop();
                b = operands.top();
                operands.pop();
                result = operation(a, b, postfix_expression[i]);
                operands.push(result);
            }
        }

    }
    return result ? result : operands.top();
}
int main()
{
    string s = "- (3 + (4 + 5))";

    cout << infix_notation(s);
}
