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