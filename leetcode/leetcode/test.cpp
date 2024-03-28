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