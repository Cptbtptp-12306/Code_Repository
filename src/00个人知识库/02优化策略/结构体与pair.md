# 结构体与pair的关系

## 什么时候适合用结构体（或者 pair）

核心一句话：**当你有一组绑定在一起、不能拆开的信息，排序的时候要整体一起移动，就用结构体 /pair**

> 
> 本质：普通数组是「下标 ↔ 一个值」；结构体是「一包数据，多个字段绑定，排序时整体挪位置」

✅ 典型场景 1：排序的时候，要保留附属信息

需要排序的关键字是 A，但是排序之后，**你还需要拿到和 A 配套的 B、C、D**

- 排座椅：排序关键字是 `cnt（收益）`，配套信息是 `index（通道编号）`
如果只开数组 `kk[id] = cnt`，直接 sort 数组，id 和 cnt 解绑，编号丢了。
必须打包：`{编号，cnt}`，按 cnt 排序，编号跟着走。
- 同类例题：
  1. 奖学金、成绩排序：按总分排序，同时要记住学生姓名、学号

```
  struct stu{
    int id;
    int score;
    string name;
};
```

  2. 区间问题：每个区间有 l,r，按右端点排序，但是 l 不能丢（活动选择、区间选点）
  3. 二维坐标：按 x 排序，同时保留 y；或者按距离排序，保留原来的点编号

> 
> 对比：单纯数组能用的情况：只需要排序值本身，不需要原始下标 / 附属信息。比如单纯给一串数字从小到大排序，只看数字，不用管它原来是第几个，直接数组 sort 就行。

##  典型场景 2：一个对象有多个不同含义的属性，逻辑上属于同一个东西

一个事物天然包含多个属性，放一起好管理：

- 图论：边（结构体存 u，v，w）—— 最小生成树 Kruskal 最经典！

```
struct Edge{
    int u, v, w;
};
// 按边权w排序，u、v跟着这条边一起走
```

- 点：坐标、权值、编号
- 任务：开始时间、结束时间、价值（贪心调度）

## ✅ 典型场景 3：需要自定义多个不同排序规则（像排座椅 cmp1、cmp2 两套排序）

同一个结构体，写多个 cmp：

- cmp1：按收益降序（选通道）
- cmp2：按编号升序（输出）
如果分开存好几个数组，很容易对应错位，结构体一包就不会乱。

## ✅ 典型场景 4：需要批量存储、传递一组关联数据

函数要同时返回 / 传入多个关联的值，打包结构体比传一堆参数清爽很多。

# 📌 区分：什么时候用 pair，什么时候用 struct

- **pair**：只有两个字段，简单场景，比如 `pair<int, int>`，第一个是收益，第二个是编号。
缺点：字段没有名字，只能用 `.first` `.second`，字段多了可读性很差。
- **struct 结构体**：字段≥2，字段有明确含义（index、cnt、u、v、score），可读性强，字段多的时候优先结构体。

> 
> 排座椅两个字段，pair 和 struct 都能写；Kruskal 边有 u,v,w 三个，必须结构体。

## ❌ 什么时候完全不需要结构体

1. 只存一类数据，排序只看这个值，不需要原始下标：比如单纯数组 `a[]` 存数字，sort (a)
2. 信息天然独立、不需要绑定：比如前缀和数组、差分数组，下标就是含义，不需要额外绑定

# pair 详解

## 1. pair是什么

`pair` 是C++自带的**二元组模板**，可以一次性存两个绑定在一起的值，相当于一个极简版结构体，只有两个成员：

- `.first`：第一个元素
- `.second`：第二个元素

头文件：不需要额外头文件，`<algorithm>` / `<iostream>` 一般就够用；规范写法需要 `<utility>`

```
#include <utility>
```

定义格式：

```
pair<类型1, 类型2> 变量名;
```

示例：

```
// pair<int, int> 第一个是通道编号，第二个是收益
pair<int, int> p;
p.first = 2;    // 通道编号
p.second = 1;   // 收益cnt=1
```

## 2. pair初始化的几种写法

```
// 写法1：直接赋值
pair<int, int> a;
a.first = 3;
a.second = 5;

// 写法2：大括号初始化（C++11及以后，考场最常用）
pair<int, int> b = {2, 1};

// 写法3：make_pair
pair<int, int> c = make_pair(4, 3);
```

> 
> 对比结构体：
> struct 可以自己起名 `index、cnt`，可读性强；
> pair 只能固定叫 `.first` `.second`，适合**只有两个数据**的场景。
> 三个及以上数据，就必须用struct，pair装不下。

## 3. pair自带排序规则（重点！）

pair默认比较规则：**先比first，如果first相等，再比second**

```
pair<int,int> p1={2,5}, p2={3,1};
p1 < p2 → true，因为 2 < 3
```

⚠️ 这个默认规则很多时候和我们想要的不一样！
我们排座椅：想要**按收益（second）降序排序**，不是按first，所以要自己写cmp。

## 4. 用pair重写【排座椅】，和你刚才的struct版本对照

我们约定：`pair<int, int> p`

- `p.first`：通道编号 index
- `p.second`：收益 cnt

```
#include <iostream>
#include <algorithm>
#include <utility>
using namespace std;

const int N = 1010;
pair<int, int> row[N], col[N]; // row[i].first=编号，row[i].second=收益

int m, n, k, l, d;

// 按收益second从大到小（对应原来cmp1）
bool cmp1(pair<int,int> x, pair<int,int> y)
{
    return x.second > y.second;
}
// 按编号first从小到大（对应原来cmp2）
bool cmp2(pair<int,int> x, pair<int,int> y)
{
    return x.first < y.first;
}

int main()
{
    cin >> m >> n >> k >> l >> d;
    for(int i = 1; i <= m; i++)
    {
        row[i].first = i;
        row[i].second = 0;
    }
    for(int i = 1; i <= n; i++)
    {
        col[i].first = i;
        col[i].second = 0;
    }

    while(d--)
    {
        int x,y,p,q;
        cin >> x >> y >> p >> q;
        if(x == p)
        {
            col[min(y,q)].second ++;
        }
        else
        {
            row[min(x,p)].second ++;
        }
    }

    sort(row+1, row+m+1, cmp1);
    sort(col+1, col+n+1, cmp1);

    sort(row+1, row+k+1, cmp2);
    sort(col+1, col+l+1, cmp2);

    for(int i=1;i<=k;i++) cout << row[i].first << " ";
    cout << endl;
    for(int i=1;i<=l;i++) cout << col[i].first << " ";
    return 0;
}
```

✅ 逻辑和结构体版本**完全一模一样**，只是把 `node.index` → `.first`，`node.cnt` → `.second`

## 5. pair什么时候用、什么时候不用

✅ 适合pair：

- 只有两个绑定数据，不想写struct、不想起名字
- 比如：坐标(x,y)、（权值，编号）、（距离，点号）

❌ 不适合pair：

- 超过2个属性（比如边：u,v,w，三个量 → 必须结构体）
- 字段含义复杂，想代码可读性高（比如学生：学号、姓名、分数，struct更清楚）

## 6. 高频坑点

1. 不要搞反first和second！
比如你写 `pair<int,int> p = {cnt, index}`，排序就会默认按cnt排序，有时候偷懒可以这么写，但是容易乱。
2. pair默认是升序，如果你要降序，必须手写cmp，不能直接sort。
3. pair是值类型，sort的时候也是整体移动，和结构体一样，两个数据不会拆开！
👉 这就是它解决你之前的问题：**排序的时候，编号和收益一起走，不会解绑**

## 7. 快速对比

| 写法 | 访问 | 优点 | 缺点 |
| --- | --- | --- | --- |
| struct | `.index` `.cnt` | 名字清晰，多字段扩展方便 | 要自己定义结构体 |
| pair | `.first` `.second` | 不用定义，开箱即用 | 只有两个成员，名字没有含义 |

## 8. 拓展小技巧（很多贪心题爱用）

有时候我们写成 `pair<int, int> p = {-cnt, id}`，利用pair默认升序，实现按cnt从大到小排序，省去写cmp：

```
// 收益大的，-cnt更小，排在前面
pair<int,int> p1 = {-1, 2}, p2 = {0, 1};
```

这个写法在PTA、洛谷刷题很常见。

要不要我给你写一个极简版本，用vector+pair写这道题？