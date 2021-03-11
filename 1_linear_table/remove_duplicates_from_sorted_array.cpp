/*
Given a sorted array, remove the duplicates in place such that each element appear only
once and return the new length. Do not allocate extra space for another array, you must do this in place with constant memory. 
For example, Given input array A = [1,1,2], Your function should return length = 2, and A is now [1,2].
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int removeDuplicates(vector<int>& nums)
    {
        if (nums.size() <= 1)
            return nums.size();

        int index = 0;
        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i] != nums[index])
                nums[++index] = nums[i];
        }

        return index + 1;
    }
};

int main()
{
    //vector<int> nums = {1,1,2,2,3,4};
    vector<int> nums = {1,2,3,4};
    Solution t;
    int len = t.removeDuplicates(nums);

    for (int i = 0; i < len; i++)
        cout << nums[i] << " ";
    cout << endl;
    return 0;
}
