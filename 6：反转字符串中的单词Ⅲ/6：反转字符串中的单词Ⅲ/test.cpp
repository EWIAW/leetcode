6.��ת�ַ����еĵ��� III
class Solution {
public:
    string reverseWords(string s)
    {
        int end = s.size() - 1;//���һ���ַ����±�

        int begin = 0;

        while (begin < end)
        {
            int ret = s.find(" ", begin);//��beginλ�ÿ�ʼ��" "
            if (ret == -1)//����Ҳ�����˵���������һ�����ʣ��˳�ѭ��
            {
                break;
            }
            reverse(s.begin() + begin, s.begin() + ret);
            begin = ret + 1;
        }

        reverse(s.begin() + begin, s.end());//��ת���һ������

        return s;
    }
};