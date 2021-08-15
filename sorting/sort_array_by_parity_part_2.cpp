#include<bits/stdc++.h>

using namespace std;

vector<int> sortArrayByParityII(vector<int>& nums) {
    vector <int> even;
    vector <int> odd;
    vector <int> res;

    for(int i = 0; i < nums.size(); i++) {
        if(nums[i] % 2 == 0) {
            even.push_back(nums[i]);
        } else {
            odd.push_back(nums[i]);
        }
    }

    int a = 0;
    int b = 0;

    while(a != even.size() || b != odd.size() ) {
        res.push_back(even[a++]);
        res.push_back(odd[b++]);
    }
    return res;

}
int main()
{
    vector <int> nums, data;

    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        int a;
        cin >> a;
        nums.push_back(a);
    }

    data = sortArrayByParityII(nums);
    for(int i = 0; i < data.size(); i++){
        cout << data[i] << " ";
    }
}
