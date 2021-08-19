#include<bits/stdc++.h>


using namespace std;

int singleNumber(vector<int>& nums) {
    sort(nums.begin(), nums.end());

    if(nums.size() == 1){
        return nums[0];
    }
    for(int i = 0; i < nums.size(); i++){
        if(nums[i] == nums[i + 1]){
            i++;
        }else{
            return nums[i];
        }
    }
    return 0;
}
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

    cout << singleNumber(data);
}
