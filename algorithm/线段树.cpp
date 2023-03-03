  1 const int INFINITE = INT_MAX;
  2 const int MAXNUM = 1000;
  3 struct SegTreeNode
  4 {
  5     int val;
  6     int addMark;//�ӳٱ��
  7 }segTree[MAXNUM];//�����߶���
  8 
  9 /*
 10 ���ܣ������߶���
 11 root����ǰ�߶����ĸ��ڵ��±�
 12 arr: ���������߶���������
 13 istart���������ʼλ��
 14 iend������Ľ���λ��
 15 */
 16 void build(int root, int arr[], int istart, int iend)
 17 {
 18     segTree[root].addMark = 0;//----���ñ��ӳټ���
 19     if(istart == iend)//Ҷ�ӽڵ�
 20         segTree[root].val = arr[istart];
 21     else
 22     {
 23         int mid = (istart + iend) / 2;
 24         build(root*2+1, arr, istart, mid);//�ݹ鹹��������
 25         build(root*2+2, arr, mid+1, iend);//�ݹ鹹��������
 26         //���������������ڵ��ֵ�����µ�ǰ���ڵ��ֵ
 27         segTree[root].val = min(segTree[root*2+1].val, segTree[root*2+2].val);
 28     }
 29 }
 30 
 31 /*
 32 ���ܣ���ǰ�ڵ�ı�־�����ӽڵ㴫��
 33 root: ��ǰ�߶����ĸ��ڵ��±�
 34 */
 35 void pushDown(int root)
 36 {
 37     if(segTree[root].addMark != 0)
 38     {
 39         //�������Һ��ӽڵ�ı�־����Ϊ���ӽڵ���ܱ�����ӳٱ����û�����´���
 40         //������ ��+=��
 41         segTree[root*2+1].addMark += segTree[root].addMark;
 42         segTree[root*2+2].addMark += segTree[root].addMark;
 43         //���ݱ�־�����ú��ӽڵ��ֵ����Ϊ��������������Сֵ����˵�������ÿ��Ԫ
 44         //�ؼ���һ��ֵʱ���������СֵҲ�������ֵ
 45         segTree[root*2+1].val += segTree[root].addMark;
 46         segTree[root*2+2].val += segTree[root].addMark;
 47         //���ݺ󣬵�ǰ�ڵ��������
 48         segTree[root].addMark = 0;
 49     }
 50 }
 51 
 52 /*
 53 ���ܣ��߶����������ѯ
 54 root����ǰ�߶����ĸ��ڵ��±�
 55 [nstart, nend]: ��ǰ�ڵ�����ʾ������
 56 [qstart, qend]: �˴β�ѯ������
 57 */
 58 int query(int root, int nstart, int nend, int qstart, int qend)
 59 {
 60     //��ѯ����͵�ǰ�ڵ�����û�н���
 61     if(qstart > nend || qend < nstart)
 62         return INFINITE;
 63     //��ǰ�ڵ���������ڲ�ѯ������
 64     if(qstart <= nstart && qend >= nend)
 65         return segTree[root].val;
 66     //�ֱ������������ѯ���������߲�ѯ����Ľ�Сֵ
 67     pushDown(root); //----�ӳٱ�־�����´���
 68     int mid = (nstart + nend) / 2;
 69     return min(query(root*2+1, nstart, mid, qstart, qend),
 70                query(root*2+2, mid + 1, nend, qstart, qend));
 71 
 72 }
 73 
 74 /*
 75 ���ܣ������߶�����ĳ��������Ҷ�ӽڵ��ֵ
 76 root����ǰ�߶����ĸ��ڵ��±�
 77 [nstart, nend]: ��ǰ�ڵ�����ʾ������
 78 [ustart, uend]: �����µ�����
 79 addVal: ���µ�ֵ��ԭ����ֵ����addVal��
 80 */
 81 void update(int root, int nstart, int nend, int ustart, int uend, int addVal)
 82 {
 83     //��������͵�ǰ�ڵ�����û�н���
 84     if(ustart > nend || uend < nstart)
 85         return ;
 86     //��ǰ�ڵ���������ڸ���������
 87     if(ustart <= nstart && uend >= nend)
 88     {
 89         segTree[root].addMark += addVal;
 90         segTree[root].val += addVal;
 91         return ;
 92     }
 93     pushDown(root); //�ӳٱ�����´���
 94     //�������Һ��ӽڵ�
 95     int mid = (nstart + nend) / 2;
 96     update(root*2+1, nstart, mid, ustart, uend, addVal);
 97     update(root*2+2, mid+1, nend, ustart, uend, addVal);
 98     //��������������ֵ���ݸ��µ�ǰ�ڵ��ֵ
 99     segTree[root].val = min(segTree[root*2+1].val, segTree[root*2+2].val);
100 }