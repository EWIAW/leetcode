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