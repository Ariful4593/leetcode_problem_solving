#include<bits/stdc++.h>


using namespace std;


vector <int> getTwoSum(vector <int>& nums, int target)
{
    int left = 0, right = nums.size() - 1;

    while(left <= right){
        int first = nums[left];
        int last = nums[right];
        int sum = first + last;

        if(sum > target){
            right--;
        }else if(sum < target){
            left++;
        }

        if(sum == target){
            return {left+1, right+1};
        }
    }
    return nums;
}
int main()
{
    vector <int> data, nums;
    int n;
    cin >> n;

    for(int i = 0; i < n; i++){
        int a;
        cin >> a;
        data.push_back(a);
    }

    nums = getTwoSum(data, 6);
    for(int i = 0; i < nums.size(); i++){
        cout << nums[i] << " ";
    }
}
