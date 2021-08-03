#include<iostream>
#include<stack>

using namespace std;

int longestValidParentheses(string s)
{
    int n = s.size();
    int open = 0, close = 0;
    int max_value = 0;
    for(int i = 0; i < n; i++){
        char c = s.at(i);
        if(c == '('){
            open++;
           }else{
               close++;
           }

           if(open == close){
                int len = open + close;
                max_value = max(max_value, len);
           }else if(close > open){
               open = close = 0;
           }
    }
    open = close = 0;
    for(int i = n-1; i >= 0; i--){
        char c = s.at(i);
        if(c == '('){
            open++;
           }else{
               close++;
           }

           if(open == close){
                int len = open + close;
                max_value = max(max_value, len);
           }else if(open > close){
               open = close = 0;
           }
    }
    return max_value;
}

int main()
{
    string s = "(()))())";

    cout << longestValidParentheses(s);
}
