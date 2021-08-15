#include<bits/stdc++.h>

using namespace std;

vector<int> sortArrayByParity(vector<int>& nums) {
        int left = 0, right = nums.size() - 1;

        while(left < right){
            if(nums[left] %2 !=0){
                swap(nums[left] , nums[right]);
                right--;
            }
            else{
                left++;
            }
        }
        return nums;
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

    data = sortArrayByParity(nums);
    for(int i = 0; i < data.size(); i++){
        cout << data[i] << " ";
    }
}
