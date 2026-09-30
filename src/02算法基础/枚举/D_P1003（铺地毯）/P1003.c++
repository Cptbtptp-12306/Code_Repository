#include <iostream>

using namespace std;

const int N = 1e5 + 10;

int n, a[N], b[N], g[N], k[N];
int x, y;

int find() 
{
    //逆序遍历，判断(x, y)是否在范围内
    for(int i = n - 1; i >= 0; i--)
    {
        if(a[i] <= x && b[i] <= y && a[i] + g[i] >= x && b[i] + k[i] >= y)
        {
            return i + 1;
        }
    }
    return -1;
}

int main()
{
    cin >> n;
    for(int i = 0; i <= n - 1; i++)
    {
        cin >> a[i] >> b[i] >> g[i] >> k[i];
    }
    cin >> x >> y;
    cout << find() << endl;
    return 0;
}

/*
思路：
不考虑二维数组，因为1e5 * 1e5会导致栈溢出，考虑逆序遍历，直接从后向前找到第一个符合要求的范围即可
*/
