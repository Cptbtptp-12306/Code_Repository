#include <iostream>

using namespace std;

#define T 86400

const int N = 1e5 + 10;
typedef pair<int, int> PII;

queue<PII> q;
int cur[N];
int kinds;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin >> n;
    while(n --)
    {
        int t, k;
        cin >> t >> k;
        for(int i = 0; i < k; i ++)
        {
            int x;
            cin >> x;
            q.push({t, x});
            if(cur[x] ++ == 0) kinds ++;
        }

        while(!q.empty() && q.front().first <= t - T)
        {
            int x = q.front().second;
            q.pop();
            if(cur[x] -- == 1) kinds --;
        }

        cout << kinds<< "\n";
    }
    
    return 0;
}
    