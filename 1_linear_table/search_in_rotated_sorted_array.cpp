/*
Suppose a sorted array is rotated at some pivot unknown to you beforehand.
(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    // first find piv index, then binary search two sorted part
    // O(n+lgn)
    int search(vector<int>& nums, int target)
    {
        if (nums.size() == 0)
            return -1;
        if (nums.size() == 1)
            return target == nums[0] ? 0 : -1;

        int piv = 0;
        for (size_t i = 1; i < nums.size(); i++)
        {
            if (nums[i] >= nums[i-1])
                continue;
            piv = i;
            break;
        }

        int ret;
        if ((ret = binary_search(nums, 0, piv-1, target)) == -1)
            return binary_search(nums, piv, nums.size()-1, target);
        else
            return ret;
    }

    int search1(vector<int>& nums, int target)
    {
        if (nums.size() == 0)
            return -1;

        int lo = 0, hi = nums.size() - 1;
        while (lo <= hi)
        {
            int mid = lo + (hi - lo) / 2;
            if (target == nums[mid])
                return mid;
            else if (nums[mid] < nums[lo])
            {
                if (target > nums[mid] && target <= nums[hi])
                    lo = mid + 1;
                else
                    hi = mid - 1;
            }
            else
            {
                if (target < nums[mid] && target >= nums[lo])
                    hi = mid - 1;
                else
                    lo = mid + 1;
            }
        }
        return -1;
    }
private:
    int binary_search(vector<int> &nums, int lo, int hi, int target)
    {
        while (lo <= hi)
        {
            int mid = lo + (hi - lo) / 2;
            if (target < nums[mid])
                hi = mid - 1;
            else if (target > nums[mid])
                lo = mid + 1;
            else
                return mid;
        }
        return -1;
    }
};

int main()
{
    vector<int> nums{4, 5, 6, 7, 0, 1, 2};

    Solution s;
    int idx = -1;

    for (auto d : nums)
        cout << d << " ";
    cout << endl;

    int target;
    cin >> target;

    if ((idx = s.search1(nums, target)) != -1)
        cout << "find "  << target << " at:" << idx << endl;
    else
        cout << "not find " << target << endl;
    return 0;
}
