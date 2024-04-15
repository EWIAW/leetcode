1.仅仅反转字母
class Solution {
public:
    string reverseOnlyLetters(string s)
    {
        int begin = 0;
        int end = s.size();
        while (begin < end)
        {
            while (begin < end && !isalpha(s[begin]))
            {
                begin++;
            }
            while (begin < end && !isalpha(s[end]))
            {
                end--;
            }
            swap(s[begin++], s[end--]);
        }
        return s;
    }
};

2.字符串中的第一个唯一字符
class Solution {
public:
    int firstUniqChar(string s)
    {
        int arr[26] = { 0 };
        //先记录每个字符的出现次数
        for (auto& ch : s)
        {
            arr[ch - 'a']++;
        }
        //在遍历数组，去找出现次数为一的字符，一定要从字符开头开始找
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

3.字符串相加
class Solution {
public:
    string addStrings(string num1, string num2)
    {
        int end1 = num1.size() - 1;
        int end2 = num2.size() - 1;

        string str;//待返回的字符串
        int flag = 0;//一个flag值来判断进位
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
            if (tmp > 9)//进位
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
        if (flag == 1)//如果相加的两个数都是3位数，那么进位后，会被忽略掉进位，所以最后要判断是否要进位
            str += '1';

        reverse(str.begin(), str.end());//反转字符串
        return str;
    }
};


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


5.反转字符串Ⅱ
void Reverse(string& str, int begin, int end)//给一个区间，将区间内的字符进行反转
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
            if ((i + (k - 1)) <= (size - 1))//如果剩余字符大于k个，则将前k个反转
            {
                j = i + (k - 1);
            }
            else//如果剩余字符小于k个，则将剩余的字符反转
            {
                j = size - 1;
            }
            Reverse(s, i, j);
            i += (2 * k);
        }
        return s;
    }
};


6.反转字符串中的单词 III
class Solution {
public:
    string reverseWords(string s)
    {
        int end = s.size() - 1;//最后一个字符的下标

        int begin = 0;

        while (begin < end)
        {
            int ret = s.find(" ", begin);//从begin位置开始找" "
            if (ret == -1)//如果找不到，说明到了最后一个单词，退出循环
            {
                break;
            }
            reverse(s.begin() + begin, s.begin() + ret);
            begin = ret + 1;
        }

        reverse(s.begin() + begin, s.end());//反转最后一个单词

        return s;
    }
};


7.字符串相乘
string addStrings(string num1, string num2)//字符串相加函数
{
    int end1 = num1.size() - 1;
    int end2 = num2.size() - 1;

    string str;
    int flag = 0;
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
        if (tmp > 9)
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
    if (flag == 1)
        str += '1';
    reverse(str.begin(), str.end());
    return str;
}

class Solution {
public:
    string multiply(string num1, string num2)
    {
        string ret;
        string str("0");//要返回的字符串

        int end1 = num1.size() - 1;
        int end2 = num2.size() - 1;
        int j = end2;//负责判断是否加0
        int flag = 0;//判断进位
        while (end2 >= 0)
        {
            int i = end1;
            while (i >= 0)
            {
                int tmp = (num1[i] - '0') * (num2[end2] - '0') + flag;
                flag = tmp / 10;
                tmp %= 10;
                ret += tmp + '0';
                i--;
            }
            if (flag > 0)
            {
                ret += flag + '0';
                flag = 0;
            }
            reverse(ret.begin(), ret.end());
            int k = end2;
            while (j > k)
            {
                ret += '0';
                k++;
            }
            for (int i = 0; i < ret.size(); i++)//判断是否全为0
            {
                if (ret[i] != '0')
                {
                    goto xy;
                }
            }
            ret = "0";
        xy:
            str = addStrings(ret, str);
            ret.resize(0);
            end2--;
        }
        return str;
    }
};

8.只出现一次的数字
class Solution {
public:
    int singleNumber(vector<int>& nums)
    {
        int ret = 0;
        for (int i = 0; i < nums.size(); i++)//将所有数按位异或在一起
        {
            ret = ret ^ nums[i];
        }
        return ret;
    }
};

9.杨辉三角
class Solution {
public:
    vector<vector<int>> generate(int numRows)
    {
        vector<vector<int>> v;//定义一个二维vector
        v.resize(numRows);//给二维vector调整为有numsRows个一维vector
        for (int i = 0; i < numRows; i++)
        {
            v[i].resize(i + 1);//调整每个一维vector的size
            //给每一个一维vector的第一个和最后一个位置赋值为1
            v[i][0] = 1;
            v[i][i] = 1;
        }

        for (int i = 2; i < numRows; i++)
        {
            for (int j = 1; j < v[i].size() - 1; j++)
            {
                v[i][j] = v[i - 1][j - 1] + v[i - 1][j];
            }
        }
        return v;
    }
};

10.删除有序数组中的重复项
class Solution {
public:
    int removeDuplicates(vector<int>& nums)
    {
        vector<int>::iterator prev = nums.begin();//定义前迭代器，指向第0个位置
        vector<int>::iterator tail = nums.begin() + 1;//定义后迭代器，指向第1个位置
        while (tail != nums.end())
        {
            if (*prev == *tail)
            {
                tail = nums.erase(tail);
            }
            if (*prev != *tail)
            {
                prev++;
                tail++;
            }
        }
        return nums.size();
    }
};

11.只出现一次的数字 II
class Solution {
public:
    int singleNumber(vector<int>& nums)
    {
        vector<int> v;
        v.resize(32);
        for (int i = 0; i < nums.size(); i++)//获取每个nums的值；
        {
            for (int j = 0; j < 32; j++)
            {
                int tmp = nums[i];//定义一个临时变量来表示nums[i]的值
                tmp = tmp >> j;//对nums[i]进行右移操作
                if ((tmp & 1) == 1)//如果右移之后的nums[i]与1按位与等于1，即该nums[i]的第一位是1，记录下来++
                {
                    v[31 - j]++;
                }
            }
        }

        //一个数组里面存着一个数的而二进制位，要把这个二进制位转换成int类型的数的方法是：
        //用数组按位与上0即可

        int ret = 0;
        for (int i = v.size() - 1; i >= 0; i--)//遍历数组v
        {
            v[i] %= 3;//对每个v[i]进行取模3，最后即可保留唯一出现一次数字的二进制码
            if (v[i] == 1)
            {
                ret |= v[i] << (31 - i);
            }
        }

        return ret;
    }
};

12.只出现一次的数字 III
class Solution {
public:
    vector<int> singleNumber(vector<int>& nums)
    {
        //将nums中的数全部异或在一起，找到唯一的两个数的异或结果
        int result = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            result ^= nums[i];
        }

        //对异或的结果进行与它的相反数异或，可以获得result结果的只有第一位为1的数
        int flag = (result == INT_MIN ? result : result & (-result));

        int ret1 = 0;//第一组所有数异或的结果
        int ret2 = 0;//第二组所有数异或的结果
        //遍历nums进行分组
        for (int i = 0; i < nums.size(); i++)
        {
            //cout<<tmp<<endl;
            if ((nums[i] & flag) == 0)
            {
                ret1 ^= nums[i];
            }
            else
            {
                ret2 ^= nums[i];
            }
        }

        vector<int> ret;
        ret.push_back(ret1);
        ret.push_back(ret2);
        return ret;
    }
};

13.电话号码的字母组合
class Solution {
public:
    vector<string> letterCombinations(string digits)
    {
        vector<string> ret;//开辟是要返回的vector<string>

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

        //把所有可能的情况计算出来  有多少种
        int sz = 1;
        for (int i = 0; i < digits.size(); i++)
        {
            int flag = digits[i] - '0';
            sz *= vs[flag].size();
        }

        ret.resize(sz);

        for (int i = 0; i < digits.size(); i++)//遍历digits 如"237"
        {
            int flag = digits[i] - '0';//将字符 转换为 数字
            sz /= vs[flag].size();//sz为每个字符要连续插入的次数

            int count = 0;//记录每个字符插入了几次
            int pos = 0;//记录插入的字符串是否越界，如果是，则回溯到0  如："abc"，c插入完后，有回溯到a

            for (int j = 0; j < ret.size(); j++)//依次往ret里  插入字符
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