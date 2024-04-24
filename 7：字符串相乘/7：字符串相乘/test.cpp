7.字符串相乘
string addStrings(string num1, string num2)//字符串相加函数
{
    int end1 = num1.size() - 1;
    int end2 = num2.size() - 1;

    string str;
    int flag = 0;
    while (end1 >= 0 || end2 >= 0)
    {
        int val1 = 0;
        int val2 = 0;
        if (end1 < 0)
            val1 = 0;
        else
            val1 = num1[end1] - '0';
        if (end2 < 0)
            val2 = 0;
        else
            val2 = num2[end2] - '0';
        int tmp = val1 + val2 + flag;
        if (tmp > 9)
        {
            tmp %= 10;
            flag = 1;
        }
        else
        {
            flag = 0;
        }
        str += tmp + '0';
        end1--;
        end2--;
    }
    if (flag == 1)
        str += '1';
    reverse(str.begin(), str.end());
    return str;
}

class Solution {
public:
    string multiply(string num1, string num2)
    {
        string ret;
        string str("0");//要返回的字符串

        int end1 = num1.size() - 1;
        int end2 = num2.size() - 1;
        int j = end2;//负责判断是否加0
        int flag = 0;//判断进位
        while (end2 >= 0)
        {
            int i = end1;
            while (i >= 0)
            {
                int tmp = (num1[i] - '0') * (num2[end2] - '0') + flag;
                flag = tmp / 10;
                tmp %= 10;
                ret += tmp + '0';
                i--;
            }
            if (flag > 0)
            {
                ret += flag + '0';
                flag = 0;
            }
            reverse(ret.begin(), ret.end());
            int k = end2;
            while (j > k)
            {
                ret += '0';
                k++;
            }
            for (int i = 0; i < ret.size(); i++)//判断是否全为0
            {
                if (ret[i] != '0')
                {
                    goto xy;
                }
            }
            ret = "0";
        xy:
            str = addStrings(ret, str);
            ret.resize(0);
            end2--;
        }
        return str;
    }
};