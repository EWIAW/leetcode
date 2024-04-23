3.�ַ������
class Solution {
public:
    string addStrings(string num1, string num2)
    {
        int end1 = num1.size() - 1;
        int end2 = num2.size() - 1;

        string str;//�����ص��ַ���
        int flag = 0;//һ��flagֵ���жϽ�λ
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
            if (tmp > 9)//��λ
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
        if (flag == 1)//�����ӵ�����������3λ������ô��λ�󣬻ᱻ���Ե���λ���������Ҫ�ж��Ƿ�Ҫ��λ
            str += '1';

        reverse(str.begin(), str.end());//��ת�ַ���
        return str;
    }
};