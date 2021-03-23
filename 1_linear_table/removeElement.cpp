/* 
给你一个数组 nums 和一个值 val，你需要 原地 移除所有数值等于 val 的元素，并返回移除后数组的新长度。

不要使用额外的数组空间，你必须仅使用 O(1) 额外空间并 原地 修改输入数组。

元素的顺序可以改变。你不需要考虑数组中超出新长度后面的元素。

输入：nums = [3,2,2,3], val = 3
输出：2, nums = [2,2]
 */

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        if (nums.size() == 0)
            return 0;

        size_t l = 0;
        int r = nums.size() - 1;

        while (true)
        {
            while (nums[l] != val) {
                l++;
                if (l >= nums.size())
                    return l;
            }

            while (nums[r] == val)
            {
                r--;
                if (r < 0)
                    return l;
                else
                    break;
            }

            if (l < r)
                swap(nums[l], nums[r]);
            else
                break;
        }
        return l;
    }

    int removeElement1(vector<int>& nums, int val)
    {
        //双指针， 一个指向可以覆盖的下个位置， 一个遍历查找目标元素
        int k = 0;
        for (size_t i = 0; i < nums.size(); i++)
        {
            if (nums[i] != val)
                nums[k++] = nums[i];
        }
        return k;
    }
};

int main()
{
    vector<int> nums{3,2,2,3};
    //vector<int> nums{1};

    Solution s;
    cout << s.removeElement1(nums, 3) << endl;

    return 0;
}