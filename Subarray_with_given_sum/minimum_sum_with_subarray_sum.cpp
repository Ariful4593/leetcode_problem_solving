#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int min_subarray(vector <int>& nums, int target)
{
    int left = 0,right = 0;
    int n = nums.size();
    int result = INT_MAX;
    for(int i = 0; i < n; i++){
        right += nums[i];

        while(right >= target){
            result = min(result, i+1 - left);
            right -= nums[left];
            left++;
        }
    }
    return (result != INT_MAX) ? result : 0;
}

int main()
{
    vector <int> data;

    int n, left = 0,right = 0;

    cin >> n;
    for(int i =0; i<n; i++){
        int a;
        cin >> a;
        data.push_back(a);
    }


    cout << min_subarray(data, 7);
}
