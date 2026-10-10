#include <iostream>

using namespace std;

const int N = 1e4 + 10;
int n, a[N], b[N];

//b[i] = a[i - 1] + a[i] + a[i - 1]，考虑a[1]可能的两种情况，若能把格子占满，则方案通过，re++
int check1()
{
    a[1] = 0;
    for(int i = 2; i <= n + 1; i ++) //从2到n + 1，b也要对应+1
    {
        a[i] = b[i - 1] - a[i -1] - a[i - 2];
        if(a[i] < 0 || a[i] > 1) return 0;
    }

    if(a[n + 1] == 0) return 1;
    else return 0;
}
int check2()
{
    a[1] = 1;
    for(int i = 2; i <= n + 1; i ++)
    {
        a[i] = b[i - 1] - a[i - 1] - a[i - 2];
        if(a[i] < 0 || a[i] > 1) return 0;
    }

    if(a[n + 1] == 0) return 1;
    else return 0;
}

int main()
{
    cin >> n;
    for(int i = 1; i <= n; i ++)
    {
        cin >> b[i];
    }
    int re = 0;
    re += check1();
    re += check2();
    cout << re << endl;
    return 0;
}