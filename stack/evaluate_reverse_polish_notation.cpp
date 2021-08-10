#include<bits/stdc++.h>
using namespace std;

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
    return 0;
}
int evalRPN(vector <string> &tokens)
{
    stack<int> nums;
        for (int i = 0; i < tokens.size(); i++) {
            string s = tokens[i];
            if (isdigit(s[0]) || s.size() > 1) {
                nums.push(stoi(s));
                continue;
            }
            int a = nums.top();
            nums.pop();
            int b = nums.top();
            nums.pop();
            if (s == "+") {
                nums.push(a+b);
            } else if (s == "-") {
                nums.push(b-a);
            } else if (s == "*") {
                nums.push(a*b);
            } else {
                nums.push(b/a);
            }
        }
        return nums.top();
}

int main()
{
    //10,6,9,3,+,-11,*,/,*,17,+,5,+

    vector <string> s = {"10","6","9","3","+","-11","*","/","*","17","+","5","+"};
    //5,6,2,+,*,12,4,/,-
    cout << evalRPN(s);




}

