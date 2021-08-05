#include<bits/stdc++.h>
using namespace std;

int postfix_expressions(string s)
{
    stack <int> st;
    int a,b,result;


    for(int i = 0; i < s.length(); i++){
        if(s[i] != ',' && s[i] != ' ' && s[i] != '+' && s[i] != '-' && s[i] != '*' && s[i] != '/'){
            int cal = s[i] - 48;
            st.push(cal);
        }
        else if(s[i] == ',' || s[i] == ' ')
        {
            continue;
        }
        else{
            a = st.top();
            st.pop();
            b = st.top();
            st.pop();
            if(s[i] == '+'){
                result = b + a;
            }else if(s[i] == '-'){
                result = b - a;
            }else if(s[i] == '/'){
                result = b / a;
            }else if(s[i] == '*'){
                result = b * a;
            }
            st.push(result);
        }
    }

    return st.top();
}
int main()
{

    string s = "546+*493/+*";

    cout << postfix_expressions(s);
    return 0;
}
