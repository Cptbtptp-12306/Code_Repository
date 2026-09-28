#include <iostream>

using namespace std;

const int N = 10010;
int a[N];
int h , t = 0;
int sum = 0;

int main()
{
    int n = 0;
    cin >> n;
    while(n --)
    {
        int m;
        cin >> m;
        switch(m)
        {
            case 1:
                int x;
                cin >> x;
                a[++t] = x;
                sum ++;
                break;
            case 2:
                if(sum == 0) cout << "ERR_CANNOT_POP" << endl;
                else if(sum != 0)
                {
                   ++ h;
                    sum --;
                }
                break;
            case 3:
                if(sum == 0) cout << "ERR_CANNOT_QUERY" << endl;
                else if(sum != 0) cout << a[h + 1] << endl;
                break;
            case 4:
                cout << sum << endl;
                break;
        }
    }
    return 0;
}