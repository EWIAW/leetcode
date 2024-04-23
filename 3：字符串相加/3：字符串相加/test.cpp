3.字符串相加
class Solution {
public:
    string addStrings(string num1, string num2)
    {
        int end1 = num1.size() - 1;
        int end2 = num2.size() - 1;

        string str;//待返回的字符串
        int flag = 0;//一个flag值来判断进位
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
            if (tmp > 9)//进位
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
        if (flag == 1)//如果相加的两个数都是3位数，那么进位后，会被忽略掉进位，所以最后要判断是否要进位
            str += '1';

        reverse(str.begin(), str.end());//反转字符串
        return str;
    }
};