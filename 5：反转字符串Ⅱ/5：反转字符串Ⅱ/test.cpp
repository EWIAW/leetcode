5.��ת�ַ�����
void Reverse(string & str, int begin, int end)//��һ�����䣬�������ڵ��ַ����з�ת
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
            if ((i + (k - 1)) <= (size - 1))//���ʣ���ַ�����k������ǰk����ת
            {
                j = i + (k - 1);
            }
            else//���ʣ���ַ�С��k������ʣ����ַ���ת
            {
                j = size - 1;
            }
            Reverse(s, i, j);
            i += (2 * k);
        }
        return s;
    }
};