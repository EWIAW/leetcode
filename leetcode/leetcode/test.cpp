1.������ת��ĸ
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


5.��ת�ַ�����
void Reverse(string& str, int begin, int end)//��һ�����䣬�������ڵ��ַ����з�ת
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


7.�ַ������
string addStrings(string num1, string num2)//�ַ�����Ӻ���
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
        string str("0");//Ҫ���ص��ַ���

        int end1 = num1.size() - 1;
        int end2 = num2.size() - 1;
        int j = end2;//�����ж��Ƿ��0
        int flag = 0;//�жϽ�λ
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
            for (int i = 0; i < ret.size(); i++)//�ж��Ƿ�ȫΪ0
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

8.ֻ����һ�ε�����
class Solution {
public:
    int singleNumber(vector<int>& nums)
    {
        int ret = 0;
        for (int i = 0; i < nums.size(); i++)//����������λ�����һ��
        {
            ret = ret ^ nums[i];
        }
        return ret;
    }
};

9.�������
class Solution {
public:
    vector<vector<int>> generate(int numRows)
    {
        vector<vector<int>> v;//����һ����άvector
        v.resize(numRows);//����άvector����Ϊ��numsRows��һάvector
        for (int i = 0; i < numRows; i++)
        {
            v[i].resize(i + 1);//����ÿ��һάvector��size
            //��ÿһ��һάvector�ĵ�һ�������һ��λ�ø�ֵΪ1
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

10.ɾ�����������е��ظ���
class Solution {
public:
    int removeDuplicates(vector<int>& nums)
    {
        vector<int>::iterator prev = nums.begin();//����ǰ��������ָ���0��λ��
        vector<int>::iterator tail = nums.begin() + 1;//������������ָ���1��λ��
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

11.ֻ����һ�ε����� II
