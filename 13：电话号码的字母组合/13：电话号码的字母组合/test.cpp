13.电话号码的字母组合
class Solution {
public:
    vector<string> letterCombinations(string digits)
    {
        vector<string> ret;//开辟是要返回的vector<string>

        if (digits.size() == 0)
        {
            return ret;
        }

        vector<string> vs;
        vs.resize(10);
        vs[2] += "abc";
        vs[3] += "def";
        vs[4] += "ghi";
        vs[5] += "jkl";
        vs[6] += "mno";
        vs[7] += "pqrs";
        vs[8] += "tuv";
        vs[9] += "wxyz";

        //把所有可能的情况计算出来  有多少种
        int sz = 1;
        for (int i = 0; i < digits.size(); i++)
        {
            int flag = digits[i] - '0';
            sz *= vs[flag].size();
        }

        ret.resize(sz);

        for (int i = 0; i < digits.size(); i++)//遍历digits 如"237"
        {
            int flag = digits[i] - '0';//将字符 转换为 数字
            sz /= vs[flag].size();//sz为每个字符要连续插入的次数

            int count = 0;//记录每个字符插入了几次
            int pos = 0;//记录插入的字符串是否越界，如果是，则回溯到0  如："abc"，c插入完后，有回溯到a

            for (int j = 0; j < ret.size(); j++)//依次往ret里  插入字符
            {
                if (pos == vs[flag].size())
                {
                    pos = 0;
                }
                if (count < sz)
                {
                    ret[j] += vs[flag][pos];
                }
                else
                {
                    count = 0;
                    pos++;
                    j--;
                    continue;
                }
                count++;
            }
        }

        return ret;
    }
};