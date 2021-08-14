#include<bits/stdc++.h>

using namespace std;

int b_search(vector <int>& nums, int target)
{
    int first = 0, last = nums.size() - 1;
    while(first <= last){
        int mid = first + (last - first) / 2;

        if(target == nums[mid]){
            return mid;
        }
        if(nums[first] <= nums[mid]){
            if(target >= nums[first] && target <= nums[mid])
            {
                last = mid - 1;
            }
            else
            {
                first = mid + 1;
            }
        } else {
            if(target <= nums[last] && target >= nums[mid]){
                first = mid + 1;
            }
            else{
                last = mid - 1;
            }
        }
    }
    return -1;
}

int main()
{
    vector <int> data;

    int n;
    cin >> n;

    for(int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        data.push_back(a);
    }

    cout << b_search(data, 0);
}
