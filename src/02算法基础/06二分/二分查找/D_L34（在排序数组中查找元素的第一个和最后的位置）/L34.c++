/*

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        if(n == 0) return {-1, -1}; //空数组判断

        int l = 0, r = n - 1;

        //第一轮二分，r = l时位置一定是第一个target下标（因为此时目标就是找到>=的mid)
        while(l < r)
        {
            int mid = l + (r - l) / 2; //计算中点
            if(nums[mid] >= target) r = mid; //此条件下，大难一定在mid或mid左侧
            else l = mid + 1; //不满足条件时，答案一定不在mid左侧，故l = mid + 1
        }

        int st = l; //存储左边界
        if(nums[st] != target) return{-1, -1}; //若l = r时未发现target，则整个数组中没有目标值

        l = 0, r = n - 1;
        while(l < r)
        {
            int mid = l + ((r - l + 1) / 2); //此时需要向上取整（右边界）
            if(nums[mid] <= target) l = mid;
            else r = mid - 1;
        }

        int ed = l;
        return {st, ed};

    }
};

*/
