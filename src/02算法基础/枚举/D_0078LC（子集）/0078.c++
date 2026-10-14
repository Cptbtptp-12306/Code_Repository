#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res; 
        int len = nums.size();

        // st是状态掩码，从0到(1 << len) - 1，每一位代表选/不选nums对应下标元素
        for(int st = 0; st < (1 << len); st++)
        {
            vector<int> temp;
            for(int i = 0; i < len; i++)
            {
                //判断第i位是不是1
                if( (st >> i) & 1 ){
                    temp.push_back(nums[i]); //如果该位为1，就把nums[i]加入当前子集
                }
            }
            res.push_back(temp); //内层循环结束，把当前子集temp放进结果集res
        }
    }
};