#include <iostream>
#include <cstring>
#define INF 0x3f3f3f3f
#define N 10000
using namespace std;

struct TREE {
    int left,right;//记录当前节点所管辖区间的 左右边界
    int maxl;//记录当前节点所管辖区间的 最大值
} tree[N];

void Built(int root,int l,int r){
//当前节点标号是root，需要建立区间[l,r]的树
    tree[root].left = l;
    tree[root].right = r;
    if(l == r)return;//已经到了叶子节点，不需要再深入
    int mid = (l+r) >> 1;
    Built ( root<<1   , l , mid );//建立左子树
    Built ( root<<1|1 , 1+mid , r);//建立右子树
}

void Fix(int root,int left,int right,int val) {//区间修改函数
    //如果修改的区间覆盖了当前节点的区间，则当前节点的值需要更新
    if (left <= tree[root].left && tree[root].right <= right) {
        tree[root].maxl = val;
        return;
    }
    //修改的区间和当前节点管辖区间没有交集
    if (left > tree[root].right || right < tree[root].left)
        return;
    //修改左子树管辖的区间
    Fix(root << 1, left, right, val);
    //修改右子树管辖的区间
    Fix(root << 1 | 1, left, right, val);
    //当前区间值由左右最值决定。
    tree[root].maxl = max(tree[root << 1].maxl, tree[root << 1 | 1].maxl);
}

int Query_max(int root,int left,int right) {
//如果查询的区间覆盖了当前节点的区间，则返回当前节点记录的值
    if (left <= tree[root].left && tree[root].right <= right)
        return tree[root].maxl;
//查询的区间和当前节点管辖区间没有交集，返回-INF
    if (left > tree[root].right || right < tree[root].left)
        return -INF;
//查询左右子树所管辖区间的最值
    int s1 = Query_max(root << 1, left, right);
    int s2 = Query_max(root << 1 | 1, left, right);
    return max(s1, s2); //返回左右子树的最值
}

int main() {
    int n, m, num;
    int a, b;
    while (cin >> n) {
        memset(tree, 0, sizeof(tree));
        Built(1, 1, n);
        for (int i = 1; i <= n; i++) {
            cin >> num;
            Fix(1, i, i, num);
        }
        cin >> m;
        while (m--) {
            cin >> a >> b;
            cout << Query_max(1, a, b) << endl;
        }
    }
    return 0;
}