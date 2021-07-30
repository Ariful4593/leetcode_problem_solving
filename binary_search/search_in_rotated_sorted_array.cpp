#include<iostream>
#include<vector>

using namespace std;

int search(vector<int>& nums, int target) {
        int n = nums.size();
        for(int i = 0; i < n; i++){
            if(nums[i] == target){
                return i;
            }
        }

        return -1;
    }
int main()
{
    vector <int> data;

    int n = 7;
    int target = 0;
    for(int i = 0; i < n; i++){
        int a;
        cin >> a;
        data.push_back(a);
    }

    cout << search(data, target);
}
