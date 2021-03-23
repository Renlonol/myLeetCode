/* 
编写一个函数来查找字符串数组中的最长公共前缀。
如果不存在公共前缀，返回空字符串 ""。
 */

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ret;

        if (strs.size() == 0)
            return ret;

        size_t idx = 0;
        while (true) {
            char ch;
            size_t i;
            for (i = 0; i < strs.size(); i++)
            {
                if (strs[i].size() <= idx)
                    return ret;
                
                if (i == 0)
                {
                    ch = strs[i][idx];
                    continue;
                }
                if (strs[i][idx] != ch)
                    return ret;
            }
            
            ret += ch;
            idx++;
        }
    }
};

int main()
{
    //vector<string> strs{"flower","fll","flight"};
    vector<string> strs{""};

    Solution s;
    
    cout << s.longestCommonPrefix(strs) << endl;

    return 0;
}