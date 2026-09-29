#include <iostream>

using namespace std;

const int N = 1e6 + 10;
int a[N], b[N], c[N];
int la, lb, lc;

void mul(int a[], int b[], int c[])
{
    //模拟乘法
    for(int i = 0; i < la; i ++)
    {
        for(int j = 0; j < lb; j ++)
        {
            c[i + j] += a[i] * b[j];
        }
    }

    //统一处理进位
    for(int i = 0; i < lc; i ++)
    {
        c[i + 1] += c[i] / 10;
        c[i] %= 10;
    }

    //在lc存在的条件下保证前导0都被删除
    while(lc > 1 && c[lc - 1] == 0) lc --;
}

int main()
{
    string x, y;
    cin >> x >> y;

    la = x.size(), lb = y.size();
    lc = la + lb;

    for(int i = 0; i < la; i ++)
    {
        a[la - i - 1] = x[i] - '0';
    }

    for(int i = 0; i < lb; i ++)
    {
        b[lb - i - 1] = y[i] - '0';
    }

    mul(a, b, c);

    for(int i = lc - 1; i >= 0; i --)
    {
        cout << c[i];
    }
    
    return 0;
}