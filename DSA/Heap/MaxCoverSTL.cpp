#include<bits/stdc++.h>
using namespace std;
class Solution
{
    public:
    int maxCover(vector<vector<int>>& intervals)
    {
        int n=intervals.size();
        sort(intervals.begin(),intervals.end(),[](const vector<int> &a,const vector<int> &b)
        {
            return a[0]<b[0];
        });
        int ans=0;
        priority_queue<int,vector<int>,greater<int>> heap;
        for(int i=0;i<n;i++)
        {
            while(!heap.empty()&&heap.top()<=intervals[i][0])
            {
                heap.pop();
            }
            heap.push(intervals[i][1]);
            ans=max(ans,(int)heap.size());
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