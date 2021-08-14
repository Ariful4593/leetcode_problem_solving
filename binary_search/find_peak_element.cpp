#include<bits/stdc++.h>

using namespace std;

int b_search(vector <int>& nums)
{
    int left=0, right = nums.size();

        while (left < right) {
        int mid = left + (right-left) /2;
        if (mid < nums.size()-1 && nums[mid] < nums[mid+1]) {
            left = mid + 1;
        }
        else {
            right = mid;
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

    cout << b_search(data);
}
