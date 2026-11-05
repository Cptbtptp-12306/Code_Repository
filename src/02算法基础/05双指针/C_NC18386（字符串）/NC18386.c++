#include <iostream>

using namespace std;

int kinds; //记录26个字母当前存放的种类
int mp[26]; //记录每种字母出现的次数

int main()
{
    string str; cin >> str;
    
    int len = str.size();
    int left = 0, right = 0, res = len; //初始化
    
    while(right < len)
    {
        //进窗口（right++）
        if(++ mp[str[right] - 'a'] == 1) kinds ++;
        
        //当符合条件时固定窗口
        while(kinds == 26)
        {
            //更新结果（当满足条件时才能更新，本题为小写字母种类为26时更新结果）
            res = min(res, right - left + 1);

            //出窗口（left--）
            if(-- mp[str[left] - 'a'] == 0) kinds --;
            left ++;
        }
        
        //窗口继续移动
        right ++;
    }
    
    cout << res << endl;
    return 0;
}