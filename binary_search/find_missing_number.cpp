class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int sa = 0, n = nums.size();
        for(int i = 0; i < n; i++){
            sa += nums[i];
        }
        int sn = (n * (n + 1) / 2);
        return sn - sa;
    }
};