#include <iostream>
#include <algorithm>

using namespace std;

const int N = 25;

int n;
string s[N];

//直接比较拼接后结果大小
bool cmp(string x, string y)
{
    return x + y > y + x;
}

int main()
{
    cin >> n;
    for(int i = 1; i <= n; i ++)
    {
        cin >> s[i];
    }
    sort(s + 1, s + n + 1, cmp);

    for(int i = 1; i <= n; i ++)
    {
        cout << s[i];
    }
    
    return 0;
}