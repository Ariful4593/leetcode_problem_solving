#include <iostream>
#include<vector>

using namespace std;

int b_search(vector <int> &nums, int target)
{

    int n = nums.size();
    int firstPosition = n;
    int mid, left = 0, right = n - 1;


    while(left <= right){
        mid = left + (right - left) / 2;

        if(nums[mid] >= target){
            firstPosition = mid;
            right = mid - 1;
        }else{
            left = mid + 1;
        }
    }

    return firstPosition;
}


vector <int> search_range(vector <int> &a, int target)
{
    int first = b_search(a, target);
    int last = b_search(a, target + 1);

    if(first <= last && first != last){
        return {first, last-1};
    }
    return {-1,-1};
}

int main()
{

    //5 7 7 8 8 10

    vector <int> nums, data;

    for(int i = 0; i < 8; i++){
        int a;
        cin >> a;
        nums.push_back(a);
    }
    data = search_range(nums, 8);
    for(int i = 0; i < data.size(); i++){
        cout << data[i] << " ";
    }
    return 0;
}
