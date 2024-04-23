6.反转字符串中的单词 III
class Solution {
public:
    string reverseWords(string s)
    {
        int end = s.size() - 1;//最后一个字符的下标

        int begin = 0;

        while (begin < end)
        {
            int ret = s.find(" ", begin);//从begin位置开始找" "
            if (ret == -1)//如果找不到，说明到了最后一个单词，退出循环
            {
                break;
            }
            reverse(s.begin() + begin, s.begin() + ret);
            begin = ret + 1;
        }

        reverse(s.begin() + begin, s.end());//反转最后一个单词

        return s;
    }
};