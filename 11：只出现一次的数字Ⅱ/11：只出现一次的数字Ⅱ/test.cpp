11.ֻ����һ�ε����� II
class Solution {
public:
    int singleNumber(vector<int>& nums)
    {
        vector<int> v;
        v.resize(32);
        for (int i = 0; i < nums.size(); i++)//��ȡÿ��nums��ֵ��
        {
            for (int j = 0; j < 32; j++)
            {
                int tmp = nums[i];//����һ����ʱ��������ʾnums[i]��ֵ
                tmp = tmp >> j;//��nums[i]�������Ʋ���
                if ((tmp & 1) == 1)//�������֮���nums[i]��1��λ�����1������nums[i]�ĵ�һλ��1����¼����++
                {
                    v[31 - j]++;
                }
            }
        }

        //һ�������������һ�����Ķ�������λ��Ҫ�����������λת����int���͵����ķ����ǣ�
        //�����鰴λ����0����

        int ret = 0;
        for (int i = v.size() - 1; i >= 0; i--)//��������v
        {
            v[i] %= 3;//��ÿ��v[i]����ȡģ3����󼴿ɱ���Ψһ����һ�����ֵĶ�������
            if (v[i] == 1)
            {
                ret |= v[i] << (31 - i);
            }
        }

        return ret;
    }
};