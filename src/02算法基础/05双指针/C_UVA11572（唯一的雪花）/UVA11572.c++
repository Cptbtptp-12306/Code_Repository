#include <iostream>
#include <unordered_map> //哈希

using namespace std;

const int N = 1e6 + 10;

int n, a[N];

//利用双指针维护滑动窗口，由于数据规模大且离散，使用哈希数组
int main()
{
    int T; cin >> T;

    while(T --)
    {
        cin >> n;
        for(int i = 1; i <= n ; i++)
        {
            cin >> a[i];
        }

        int left = 1, right = 1, res = 0;
        unordered_map<int, int> mp; //哈希数组定义
        //维护滑动窗口
        while(right <= n)
        {
            mp[a[right]] ++; //把哈希数组对应a[right]的编号 + 1

            //若此时编号的值 > 1，left指针持续向右移动
            while(mp[a[right]] > 1)
            {
                mp[a[left]] --;
                left ++;
            }

            //比较res和当前窗口的大小
            res = max(res, right - left + 1);
            right ++;
        }
        cout << res << endl;
    }

    return 0;
}