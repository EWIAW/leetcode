11.只出现一次的数字 II
class Solution {
public:
    int singleNumber(vector<int>& nums)
    {
        vector<int> v;
        v.resize(32);
        for (int i = 0; i < nums.size(); i++)//获取每个nums的值；
        {
            for (int j = 0; j < 32; j++)
            {
                int tmp = nums[i];//定义一个临时变量来表示nums[i]的值
                tmp = tmp >> j;//对nums[i]进行右移操作
                if ((tmp & 1) == 1)//如果右移之后的nums[i]与1按位与等于1，即该nums[i]的第一位是1，记录下来++
                {
                    v[31 - j]++;
                }
            }
        }

        //一个数组里面存着一个数的而二进制位，要把这个二进制位转换成int类型的数的方法是：
        //用数组按位与上0即可

        int ret = 0;
        for (int i = v.size() - 1; i >= 0; i--)//遍历数组v
        {
            v[i] %= 3;//对每个v[i]进行取模3，最后即可保留唯一出现一次数字的二进制码
            if (v[i] == 1)
            {
                ret |= v[i] << (31 - i);
            }
        }

        return ret;
    }
};