#include <iostream>

using namespace std;

const int N = 1e6 + 100;
int a[N], b[N], c[N]; //a + b = c
int la, lb, lc; //a,b,c的长度

void add(int c[], int a[], int b[])
{
    for(int i = 0; i < lc; i ++)
    {
        c[i] += a[i] + b[i]; //模拟竖式加法
        c[i + 1] += c[i] / 10; //模拟进位
        c[i] = c[i] % 10; //模拟取余
    }

    if(c[lc]) lc ++; //如果位数增加，让lc也增加
}

int main()
{
    string x, y;
    cin >> x >> y;
    la = x.size(), lb = y.size();
    lc = max(la, lb); //lc长度为la和lb中较大者

    //逆序存储a和b
    for(int i = 0; i < la; i ++)
    {
        a[la - i - 1] = x[i] - '0';
    }

    for(int i = 0; i < lb; i ++)
    {
        b[lb - i - 1] = y[i] - '0';
    }

    add(c, a, b);

    //逆序输出结果
    for(int i = lc - 1; i >= 0; i --)
    {
        cout << c[i];
    }
    
    return 0;
}