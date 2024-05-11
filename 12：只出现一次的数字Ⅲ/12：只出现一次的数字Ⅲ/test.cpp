12.只出现一次的数字 III
class Solution {
public:
    vector<int> singleNumber(vector<int>& nums)
    {
        //将nums中的数全部异或在一起，找到唯一的两个数的异或结果
        int result = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            result ^= nums[i];
        }

        //对异或的结果进行与它的相反数异或，可以获得result结果的只有第一位为1的数
        int flag = (result == INT_MIN ? result : result & (-result));

        int ret1 = 0;//第一组所有数异或的结果
        int ret2 = 0;//第二组所有数异或的结果
        //遍历nums进行分组
        for (int i = 0; i < nums.size(); i++)
        {
            //cout<<tmp<<endl;
            if ((nums[i] & flag) == 0)
            {
                ret1 ^= nums[i];
            }
            else
            {
                ret2 ^= nums[i];
            }
        }

        vector<int> ret;
        ret.push_back(ret1);
        ret.push_back(ret2);
        return ret;
    }
};