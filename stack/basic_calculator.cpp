#include<bits/stdc++.h>
using namespace std;


int operator_pecedence(char op)
{
    if(op == '+'){
        return 1;
    }else if(op == '-'){
        return 1;
    }else if(op == '*'){
        return 2;
    }else{
        return 2;
    }
}

int operation(int v1, int v2, char op)
{
    if(op == '+'){
        return v1 + v2;
    }else if(op == '-'){
        return v1 - v2;
    }else if(op == '+'){
        return v1 * v2;
    }else{
        return v1 / v2;
    }
}


int infix_expressions(string s)
{

    stack <int> operands;
    stack <char> operat;

    int counter = 0;
    for(int i = 0; i < s.length(); i++){
       if(s[i] == '+' || s[i] == '-'){
            counter++;
        }
    }
    string test = s;
    if(counter == 0){
        return stoi(s);
    }

    for(int i = 0; i < s.length(); i++){

        if(s[i] == '(')
        {
            operat.push(s[i]);
        }
        else if(s[i] != '(' && s[i] != ')' && s[i] != '+' && s[i] != '-' && s[i] != '*' && s[i] != '/' && s[i] != ' ' && s[i] != ',')
        {
            int cal = s[i] - 48;
            operands.push(cal);
        }
        else if(s[i] == ')')
        {
            while(operat.top() != '(')
            {
                char operator_ = operat.top();
                operat.pop();
                int v2 = operands.top();
                operands.pop();
                int v1 = operands.top();
                operands.pop();

                int operation_value = operation(v1, v2, operator_);
                operands.push(operation_value);
            }
            operat.pop();
        }
        else if(s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/' )
        {
            while(operat.size() > 0 && operat.top() != '(' && operator_pecedence(s[i]) <= operator_pecedence(operat.top()))
            {
                char operator_ = operat.top();
                operat.pop();
                int v2 = operands.top();
                operands.pop();
                int v1 = operands.top();
                operands.pop();

                int operation_value = operation(v1, v2, operator_);
                operands.push(operation_value);
            }
            operat.push(s[i]);
        }
    }

    while(operat.size() != 0)
    {
        char operator_ = operat.top();
        operat.pop();
        int v2 = operands.top();
        operands.pop();
        int v1 = operands.top();
        operands.pop();

        int operation_value = operation(v1, v2, operator_);
        operands.push(operation_value);
    }

    return operands.top();

}
int main()
{
    string s = "2147483647";

    cout << infix_expressions(s);

    return 0;
}
