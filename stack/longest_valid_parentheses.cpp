//It's for testing purposes
#include<iostream>
#include<stack>

using namespace std;

int longestValidParentheses(string s)
{
    int n = s.size();
    stack <char> st;

    st.push(-1);

    int results = 0;
    for(int i = 0; i < n; i++){
        char c = s.at(i);
        if(c == '('){
            st.push(i);
           }else{
               st.pop();
               if(st.empty()){
                    st.push(i);
               }else{
                   results = i - st.top();
               }
           }
    }
    return results;
}

int main()
{
    string s = "(()";

    cout << longestValidParentheses(s);
}
