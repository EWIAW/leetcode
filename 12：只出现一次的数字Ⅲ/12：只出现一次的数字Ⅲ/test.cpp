12.ֻ����һ�ε����� III
class Solution {
public:
    vector<int> singleNumber(vector<int>& nums)
    {
        //��nums�е���ȫ�������һ���ҵ�Ψһ���������������
        int result = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            result ^= nums[i];
        }

        //�����Ľ�������������෴����򣬿��Ի��result�����ֻ�е�һλΪ1����
        int flag = (result == INT_MIN ? result : result & (-result));

        int ret1 = 0;//��һ�����������Ľ��
        int ret2 = 0;//�ڶ������������Ľ��
        //����nums���з���
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