#include<iostream>
#include<vector>

using namespace std;


int main()
{
    vector <int> data;

    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        int a;
        cin >> a;
        data.push_back(a);
    }

    int sum = 27;
    int right = 0;
    int left = 0;
    int counter = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(right < sum){
                right = right + data[j];
                ++counter;
            }
            if(right > sum){
                right = right - data[left];
                left++;
            }
        }
        if(right == sum){
            cout << left <<" " << counter << endl;
            break;
        }
    }
    cout << endl;

    for(int i = left; i < counter; i++){
        cout << data[i] << " ";
    }
}
