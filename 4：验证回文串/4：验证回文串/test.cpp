4.验证回文串
class Solution {
public:
    bool isPalindrome(string s)
    {
        for (int i = 0; i < s.size(); i++)//将字符串全部转为小写
        {
            s[i] = tolower(s[i]);
        }

        int begin = 0;
        int end = s.size() - 1;
        while (begin < end)
        {
            while (begin < end && (!isalpha(s[begin]) && !isalnum(s[begin])))//从头开始找有效字符或数字
            {
                begin++;
            }
            while (begin < end && (!isalpha(s[end]) && !isalnum(s[end])))//从尾开始找有效字符或数字
            {
                end--;
            }
            if (s[begin] == s[end])
            {
                begin++;
                end--;
            }
            else
            {
                return false;
            }
        }
        return true;
    }
};