#include <iostream>

using namespace std;

const int N = 1e6 + 10, M = 2e3 + 10;

//mp数组统计窗口每个元素出现的个数，kinds统计窗口内有效元素的个数
int n, m, kinds;
int a[N], mp[M];

int main()
{
    cin >> n >> m;
    for(int i = 1; i <= n; i ++)
    {
        cin >> a[i];
    }

    //求区间可以直接用长度比较，当len最小时，修改res同时让begin = left
    int left = 1, right = 1;
    int res = n, begin = 1; //res默认为整个数组长度，begin初始等于left

    while(right <= n)
    {
        //进窗口
        if(++ mp[a[right]] == 1) kinds ++; //进窗口该编号对应次数 ++，若次数为1表示第一次进入窗口，kinds ++
        while(kinds == m)
        {
            //更新结果
            int len = right - left + 1;
            if(len < res)
            {
                res = len;
                begin = left;
            }
            //出窗口
            if(-- mp[a[left]] == 0) kinds --; //出窗口该编号对应次数 --，若次数为0表示第一次出窗口，kinds --
            left ++;
        }
        right ++;
    }
    cout << begin << " " << begin + res - 1 << endl;
    
    return 0;
}