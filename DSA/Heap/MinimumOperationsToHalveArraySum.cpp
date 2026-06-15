#include<bits/stdc++.h>
using namespace std;
class Solution
{
    public:
    static const int MAX=100;
    long heap[MAX];
    void Heapify(int i,int Heapsize)
    {
        int left=i*2+1;
        while(left<Heapsize)
        {
            int best=(left+1<Heapsize && heap[left+1]>heap[left])?left+1:left;
            best=(heap[best]>heap[i])?best:i;
            if(best==i)
            {
                return;
            }
            swap(heap[best],heap[i]);
            i=best;
            left=i*2+1;
        }
    }
    int minimumOperations(vector<int>& nums)
    {
        long sum=0;
        for(int i=nums.size()-1;i>=0;i--)
        {
            heap[i]=(long)nums[i]<<20;
            sum+=heap[i];
            Heapify(i,nums.size());
        }
        sum/=2;
        int ans=0;
        for(long minus=0;minus<sum;ans++)
        {
            heap[0]/=2;
            minus+=heap[0];
            Heapify(0,nums.size());
        }
        return ans;
    }
};
int main()
{
    Solution s;
    vector<int> nums={5,19,8,1};
    cout<<s.minimumOperations(nums)<<endl;
    return 0;
}
