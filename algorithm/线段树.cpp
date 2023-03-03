  1 const int INFINITE = INT_MAX;
  2 const int MAXNUM = 1000;
  3 struct SegTreeNode
  4 {
  5     int val;
  6     int addMark;//延迟标记
  7 }segTree[MAXNUM];//定义线段树
  8 
  9 /*
 10 功能：构建线段树
 11 root：当前线段树的根节点下标
 12 arr: 用来构造线段树的数组
 13 istart：数组的起始位置
 14 iend：数组的结束位置
 15 */
 16 void build(int root, int arr[], int istart, int iend)
 17 {
 18     segTree[root].addMark = 0;//----设置标延迟记域
 19     if(istart == iend)//叶子节点
 20         segTree[root].val = arr[istart];
 21     else
 22     {
 23         int mid = (istart + iend) / 2;
 24         build(root*2+1, arr, istart, mid);//递归构造左子树
 25         build(root*2+2, arr, mid+1, iend);//递归构造右子树
 26         //根据左右子树根节点的值，更新当前根节点的值
 27         segTree[root].val = min(segTree[root*2+1].val, segTree[root*2+2].val);
 28     }
 29 }
 30 
 31 /*
 32 功能：当前节点的标志域向孩子节点传递
 33 root: 当前线段树的根节点下标
 34 */
 35 void pushDown(int root)
 36 {
 37     if(segTree[root].addMark != 0)
 38     {
 39         //设置左右孩子节点的标志域，因为孩子节点可能被多次延迟标记又没有向下传递
 40         //所以是 “+=”
 41         segTree[root*2+1].addMark += segTree[root].addMark;
 42         segTree[root*2+2].addMark += segTree[root].addMark;
 43         //根据标志域设置孩子节点的值。因为我们是求区间最小值，因此当区间内每个元
 44         //素加上一个值时，区间的最小值也加上这个值
 45         segTree[root*2+1].val += segTree[root].addMark;
 46         segTree[root*2+2].val += segTree[root].addMark;
 47         //传递后，当前节点标记域清空
 48         segTree[root].addMark = 0;
 49     }
 50 }
 51 
 52 /*
 53 功能：线段树的区间查询
 54 root：当前线段树的根节点下标
 55 [nstart, nend]: 当前节点所表示的区间
 56 [qstart, qend]: 此次查询的区间
 57 */
 58 int query(int root, int nstart, int nend, int qstart, int qend)
 59 {
 60     //查询区间和当前节点区间没有交集
 61     if(qstart > nend || qend < nstart)
 62         return INFINITE;
 63     //当前节点区间包含在查询区间内
 64     if(qstart <= nstart && qend >= nend)
 65         return segTree[root].val;
 66     //分别从左右子树查询，返回两者查询结果的较小值
 67     pushDown(root); //----延迟标志域向下传递
 68     int mid = (nstart + nend) / 2;
 69     return min(query(root*2+1, nstart, mid, qstart, qend),
 70                query(root*2+2, mid + 1, nend, qstart, qend));
 71 
 72 }
 73 
 74 /*
 75 功能：更新线段树中某个区间内叶子节点的值
 76 root：当前线段树的根节点下标
 77 [nstart, nend]: 当前节点所表示的区间
 78 [ustart, uend]: 待更新的区间
 79 addVal: 更新的值（原来的值加上addVal）
 80 */
 81 void update(int root, int nstart, int nend, int ustart, int uend, int addVal)
 82 {
 83     //更新区间和当前节点区间没有交集
 84     if(ustart > nend || uend < nstart)
 85         return ;
 86     //当前节点区间包含在更新区间内
 87     if(ustart <= nstart && uend >= nend)
 88     {
 89         segTree[root].addMark += addVal;
 90         segTree[root].val += addVal;
 91         return ;
 92     }
 93     pushDown(root); //延迟标记向下传递
 94     //更新左右孩子节点
 95     int mid = (nstart + nend) / 2;
 96     update(root*2+1, nstart, mid, ustart, uend, addVal);
 97     update(root*2+2, mid+1, nend, ustart, uend, addVal);
 98     //根据左右子树的值回溯更新当前节点的值
 99     segTree[root].val = min(segTree[root*2+1].val, segTree[root*2+2].val);
100 }