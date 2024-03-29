//1.������ת��ĸ
//class Solution {
//public:
//    string reverseOnlyLetters(string s)
//    {
//        int begin = 0;
//        int end = s.size();
//        while (begin < end)
//        {
//            while (begin < end && !isalpha(s[begin]))
//            {
//                begin++;
//            }
//            while (begin < end && !isalpha(s[end]))
//            {
//                end--;
//            }
//            swap(s[begin++], s[end--]);
//        }
//        return s;
//    }
//};

//2.�ַ����еĵ�һ��Ψһ�ַ�
//class Solution {
//public:
//    int firstUniqChar(string s)
//    {
//        int arr[26] = { 0 };
//        //�ȼ�¼ÿ���ַ��ĳ��ִ���
//        for (auto& ch : s)
//        {
//            arr[ch - 'a']++;
//        }
//        //�ڱ������飬ȥ�ҳ��ִ���Ϊһ���ַ���һ��Ҫ���ַ���ͷ��ʼ��
//        for (int i = 0; i < s.size(); i++)
//        {
//            if (arr[s[i] - 'a'] == 1)
//            {
//                return i;
//            }
//        }
//
//        return -1;
//    }
//};