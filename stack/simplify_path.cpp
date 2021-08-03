#include<iostream>
#include<string>
#include<bits/stdc++.h>
using namespace std;

void split(string str)
{
    string temp = "";
    int n = str.size();

    for(int i = 0; i < n; i++){
        if(str[i] != '/' ){
            temp += str[i];
        }else{
            temp += "";
        }
    }

    cout << temp;
}

string simplifyPath(string path)
{
    int index=path.size()-1;
        string ans = "";
        int back = 0;

        while(index >= 0)
        {
            string temp = "";
            while(index >= 0 && path[index] !='/')
            {
                temp += path[index];
                index--;
            }

            index--;

            if(temp == "" || temp == ".")
                continue;

            if(temp == "..")
                back++;
            else if(back > 0)
            {
                back--;
            }
            else{
                ans += temp;
                ans += "/";
            }


        }
        reverse(ans.begin(),ans.end());
        if(ans == "")
            return "/";
        return ans;

}
int main()
{
    string s = "/home/";

    cout << simplifyPath(s);


    return 0;
}
