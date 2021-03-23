/* 
给定两个大小分别为 m 和 n 的正序（从小到大）数组 nums1 和 nums2。请你找出并返回这两个正序数组的 中位数 。

 */

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int sz1 = nums1.size();
        int sz2 = nums2.size();

        if (sz1 == 0 && sz2 == 0)
            return 0.0;

        vector<int> merged(sz1 + sz2, 0);
        //merge two sorted vector and find the median
        //O(n+m)
        int i = 0, j = 0;
        for (size_t k = 0; k < merged.size(); k++)
        {
            if (i >= sz1)                 
                merged[k] = nums2[j++];
            else if (j >= sz2)            
                merged[k] = nums1[i++];
            else if (nums1[i] < nums2[j]) 
                merged[k] = nums1[i++];
            else                          
                merged[k] = nums2[j++]; 
        }

        if ((sz1+sz2) % 2 == 0)
            return (merged[(sz1+sz2)/2 - 1] + merged[(sz1+sz2)/2]) / 2.0;
        else
            return (merged[(sz1+sz2)/2]);
    }
};

int main()
{
    vector<int> nums1{1,3};
    vector<int> nums2{2};

    Solution s;
    double ret = s.findMedianSortedArrays(nums1, nums2);
    cout << "Median: " << ret  << endl;

    return 0;
}