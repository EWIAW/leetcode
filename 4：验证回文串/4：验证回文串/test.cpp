4.��֤���Ĵ�
class Solution {
public:
    bool isPalindrome(string s)
    {
        for (int i = 0; i < s.size(); i++)//���ַ���ȫ��תΪСд
        {
            s[i] = tolower(s[i]);
        }

        int begin = 0;
        int end = s.size() - 1;
        while (begin < end)
        {
            while (begin < end && (!isalpha(s[begin]) && !isalnum(s[begin])))//��ͷ��ʼ����Ч�ַ�������
            {
                begin++;
            }
            while (begin < end && (!isalpha(s[end]) && !isalnum(s[end])))//��β��ʼ����Ч�ַ�������
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