#include<bits/stdc++.h>
using namespace std;
class Solution
{
    public:
    static const int MAX=100;
    int HeapArr[MAX];
    int size=0;//size实际上是一个位置指针，指向堆的下一个填数位置
    void Heapify(int i,int Heapsize)//建立小根堆而不是大根堆
    {
        int leftpoint=i*2+1;
        int rightpoint=i*2+2;
        while(leftpoint<Heapsize)
        {
            int bestson=(rightpoint<Heapsize&&HeapArr[leftpoint]>HeapArr[rightpoint])?rightpoint:leftpoint;
            bestson=(HeapArr[bestson]<HeapArr[i])?bestson:i;
            if(bestson==i)
            {
                return;
            }
            swap(HeapArr[bestson],HeapArr[i]);
            i=bestson;
            leftpoint=i*2+1;
        }
    }
    void insertNumber(int x)//已经是时间最优因为新的数只能放在堆的最后一个位置，向上交换直到满足小根堆的性质
    {
        HeapArr[size]=x;
        int i=size++;//i等于size的值，size自增1
        while(HeapArr[i]<HeapArr[(i-1)/2])
        {
            swap(HeapArr[i],HeapArr[(i-1)/2]);
            i=(i-1)/2;
        }
    }
    void deleteNumber()
    {
        swap(HeapArr[0],HeapArr[--size]);
        Heapify(0,size);//只有堆顶一个元素被修改了，所以只需要从堆顶开始调整就可以了
    }
    int maxCover(vector<vector<int>>& intervals)
    {
        size=0;
        sort(intervals.begin(),intervals.end(),
        [](const vector<int>& a,const vector<int>& b)
        {
            return a[0]<b[0];
        });
        int ans=0;
        for(int i=0;i<intervals.size();i++)
        {
            while(size>0&&HeapArr[0]<=intervals[i][0])
            {
                deleteNumber();
            }
            insertNumber(intervals[i][1]);
            ans=max(ans,size);
        }
        return ans;
    }
};
int main()
{
    Solution s;
    vector<vector<int>> intervals={{1,3},{2,5},{4,6}};
    cout<<s.maxCover(intervals)<<endl; // Output: 2
    return 0;
}