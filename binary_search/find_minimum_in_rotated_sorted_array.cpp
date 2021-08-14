#include<bits/stdc++.h>

using namespace std;

int b_search(vector <int>& nums)
{
    int n = nums.size();
        int mid, left = 0, right = n - 1;
        if(n == 1){
            return nums[0];
        }
        if(nums[right] > nums[left]){
            return nums[left];
        }
        while(left <= right){
            mid = left + (right - left) / 2;


            if(mid < n-1 && nums[mid] > nums[mid + 1]){
                return nums[mid + 1];
            }
            if(mid > 0 && nums[mid-1] > nums[mid]){
                return nums[mid];
            }

            if(nums[mid] > nums[0]){
                left = mid + 1;
            }else{
                right = mid - 1;
            }
        }
        return -1;
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

    cout << b_search(data);
}
