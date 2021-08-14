#include<bits/stdc++.h>

using namespace std;

int b_search(vector <int>& nums, int target)
{
    int mid, left = 0, right = nums.size() -1;
    for(int i = 0; i < nums.size(); i++){
        if(nums[i] == target){
            return i;
        }
        else if(nums[i] != target)
        {
            while(left <= right){
                mid = left + (right - left) / 2;

                if(nums[mid] == target){
                    return mid;
                }
                if(nums[mid] < target){
                    left = mid + 1;
                }
                else if(nums[mid] > target){
                    right = mid - 1;
                }
            }
        }
    }
    return left;
}
int main()
{
    vector <int> data, nums;

    int n;
    cin >> n;

    for(int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        data.push_back(a);
    }

    cout << b_search(data, 7);
}
