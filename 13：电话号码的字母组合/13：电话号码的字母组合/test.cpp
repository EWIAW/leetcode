13.�绰�������ĸ���
class Solution {
public:
    vector<string> letterCombinations(string digits)
    {
        vector<string> ret;//������Ҫ���ص�vector<string>

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

        //�����п��ܵ�����������  �ж�����
        int sz = 1;
        for (int i = 0; i < digits.size(); i++)
        {
            int flag = digits[i] - '0';
            sz *= vs[flag].size();
        }

        ret.resize(sz);

        for (int i = 0; i < digits.size(); i++)//����digits ��"237"
        {
            int flag = digits[i] - '0';//���ַ� ת��Ϊ ����
            sz /= vs[flag].size();//szΪÿ���ַ�Ҫ��������Ĵ���

            int count = 0;//��¼ÿ���ַ������˼���
            int pos = 0;//��¼������ַ����Ƿ�Խ�磬����ǣ�����ݵ�0  �磺"abc"��c��������л��ݵ�a

            for (int j = 0; j < ret.size(); j++)//������ret��  �����ַ�
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