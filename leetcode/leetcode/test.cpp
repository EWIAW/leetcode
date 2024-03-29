//1.仅仅反转字母
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

//2.字符串中的第一个唯一字符
//class Solution {
//public:
//    int firstUniqChar(string s)
//    {
//        int arr[26] = { 0 };
//        //先记录每个字符的出现次数
//        for (auto& ch : s)
//        {
//            arr[ch - 'a']++;
//        }
//        //在遍历数组，去找出现次数为一的字符，一定要从字符开头开始找
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