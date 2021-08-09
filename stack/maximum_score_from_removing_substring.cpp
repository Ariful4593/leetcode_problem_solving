#include<bits/stdc++.h>
using namespace std;


int remaining(string &s, char c1, char c2)
{
    stack <char> ch;
    int ans = 0;
    for(int i = 0; i < s.length(); i++)
    {
        char indexValue = s.at(i);
        if(!ch.empty() && c1 == ch.top() && indexValue == c2){
            ch.pop();
            ans++;
        }else{
            ch.push(indexValue);
        }
    }
    s="";

    while (ch.size()){
        s.push_back(ch.top());
        ch.pop();
    }
    reverse(s.begin(),s.end());

    return ans;
}

int maximumGain(string s, int x, int y)
{
    int ab = 0, ba = 0;
    if(y > x){
        ba = y * remaining(s,'b','a');
        ab = x * remaining(s,'a','b');
    }
    else{
        ab = x * remaining(s,'a','b');
        ba = y * remaining(s,'b','a');
    }

    return ab + ba;
}
int main()
{
    //aabbaaxybbaabb
    string s = "cdbcbbaaabab";
    //x = 4074, y = 9819;
    int x = 4, y = 5;
    cout << maximumGain(s, x, y);

    return 0;
}
