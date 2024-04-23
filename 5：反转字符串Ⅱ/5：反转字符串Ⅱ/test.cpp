5.反转字符串Ⅱ
void Reverse(string & str, int begin, int end)//给一个区间，将区间内的字符进行反转
{
    while (begin < end)
    {
        char ch = str[begin];
        str[begin] = str[end];
        str[end] = ch;
        begin++;
        end--;
    }
}

class Solution {
public:
    string reverseStr(string s, int k)
    {
        int size = s.size();
        int i = 0;
        while (i <= (size - 1))
        {
            int j;
            if ((i + (k - 1)) <= (size - 1))//如果剩余字符大于k个，则将前k个反转
            {
                j = i + (k - 1);
            }
            else//如果剩余字符小于k个，则将剩余的字符反转
            {
                j = size - 1;
            }
            Reverse(s, i, j);
            i += (2 * k);
        }
        return s;
    }
};