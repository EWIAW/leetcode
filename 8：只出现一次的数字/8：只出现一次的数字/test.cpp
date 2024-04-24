8.只出现一次的数字
class Solution {
public:
    int singleNumber(vector<int>& nums)
    {
        int ret = 0;
        for (int i = 0; i < nums.size(); i++)//将所有数按位异或在一起
        {
            ret = ret ^ nums[i];
        }
        return ret;
    }
};