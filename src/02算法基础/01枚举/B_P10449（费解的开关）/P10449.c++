#include <iostream>
#include <cstring>

using namespace std;

const int N = 10;

int n = 5;
int a[N]; //二进制存储，存储灯的状态
int t[N]; //拷贝数组a

//计算x的二进制表示中有多少1，可以确定本行按动开关的次数
int calc(int x)
{
    int cnt = 0;
    while(x)
    {
        cnt ++;
        x &= x - 1;
    }
    return cnt;
}

int main()
{
    int T;
    cin >> T;

    while(T --)
    {
        memset(a, 0, sizeof(a));

        for(int i = 0; i < n; i ++)
        {
            for(int j = 0; j < n; j ++)
            {
                char ch;
                cin >> ch;

                //反向存储
                if(ch == '0') a[i] |= 1 << j; //初始a数组全0，只要改变1即可
            }
        }

        int ret = 0x3f3f3f3f; //统计最小值

        //枚举第一行的全部按法
        for(int st = 0; st < (1 << n); st ++)
        {
            memcpy(t, a, sizeof(a));
            int push = st; //当前行的按法
            int cnt = 0; //统计当前按法下一共按了多少次

            //依次计算后续的结果和按法
            for(int i = 0; i < n; i ++)
            {
                cnt += calc(push); //第一行是枚举产生的，所有的1一定会被翻转

                //修改当前航被按的结果
                t[i] = t[i] ^ push ^ (push << 1) ^ (push >> 1); //表示本行相邻全部翻转
                t[i] &= (1 << n) - 1; //掩码清理，只保留低n位的状态，清除高位左移的垃圾（1000000->011111）

                //修改下一行的状态
                t[i + 1] ^= push; //不必考虑上一行，因为是枚举，上一行一定会被正确翻转

                //下一行的按法
                push = t[i]; //第一行会处理两次，因为会被更新一次（第一行需要翻转两次）
            }
            //选择最小值
            if(t[n - 1] == 0) ret = min(ret, cnt); //表示最后一行全亮（因为反转存储了）
        }

        if(ret > 6) cout << -1 << endl;
        else cout << ret << endl;
    }
    return 0;
}