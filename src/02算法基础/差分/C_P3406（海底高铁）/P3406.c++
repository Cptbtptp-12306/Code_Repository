#include <iostream>

using namespace std;

typedef long long ll;

const int N = 1e5 + 10;

int a, b, c; //对应三种金额
//f为经过i段铁路的次数，sum为总金额
ll f[N], sum; //f[N]后续会原地求和，故不能int

int main()
{
    int n, m; cin >> n >> m;
    int x; cin >> x;
    //出差i站到j站，会经历[i, j]区间的所有铁路，直接差分对整个区间进行操作
    for(int i = 2; i <= m; i ++)
    {
        int y; cin >> y;
        if(x > y)
        {
            f[y] ++;
            f[x] --;
        }
        else if(x < y)
        {
            f[x] ++;
            f[y] --;
        }
        x = y; //注意更新x
    }
    //边对f[N]求前缀和边计算最小值并加入到sum
    for(int i = 1; i < n; i ++)
    {
        cin >> a >> b >> c;
        f[i] += f[i - 1];
        sum += min(a * f[i], b * f[i] + c); //第i段铁路买票和买卡所需金额的最小值
    }

    cout << sum << endl;
    return 0;
}