2.�ַ����еĵ�һ��Ψһ�ַ�
class Solution {
public:
    int firstUniqChar(string s)
    {
        int arr[26] = { 0 };
        //�ȼ�¼ÿ���ַ��ĳ��ִ���
        for (auto& ch : s)
        {
            arr[ch - 'a']++;
        }
        //�ڱ������飬ȥ�ҳ��ִ���Ϊһ���ַ���һ��Ҫ���ַ���ͷ��ʼ��
        for (int i = 0; i < s.size(); i++)
        {
            if (arr[s[i] - 'a'] == 1)
            {
                return i;
            }
        }

        return -1;
    }
};