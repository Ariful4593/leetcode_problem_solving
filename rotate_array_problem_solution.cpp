#include<iostream>
#include<vector>

using namespace std;


int main()
{
    int data[10];
    int n;
    cin >> n;

    for(int i = 0; i < n; i++){
        cin >> data[i];
    }
    int temp;
    for(int i = 0; i < 2; i++){
        temp = data[n-1];
        for(int j = n-1; j > 0; j--){
            data[j] = data[j-1];
        }
        data[0] = temp;
    }

    for(int i = 0; i < n; i++){
        cout << data[i] << " ";
    }

}
