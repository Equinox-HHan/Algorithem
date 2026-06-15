#include<bits/stdc++.h>
using namespace std;
//数组中两个数字出现了奇数次，其他数字都出现了偶数次，找出这两个数字
vector<int> findNumber(vector<int>& arr)
{
    int ExclusiveOr1=0;
    for(int i=0;i<arr.size();i++)
    {
        ExclusiveOr1^=arr[i];
    }
    int ExclusiveOr2=0;
    int rightPoint=ExclusiveOr1&(-ExclusiveOr1);
    for(int i=0;i<arr.size();i++)
    {
        if((arr[i]&rightPoint)==0)
        {
            ExclusiveOr2^=arr[i];
        }
    }
    return {ExclusiveOr2,ExclusiveOr1^ExclusiveOr2};
}
int main()
{
    vector<int> arr={1,2,3,4,5,6,7,8,9,10,1,2,3,4,5,6,7,8};
    vector<int> res=findNumber(arr);
    cout<<res[0]<<" "<<res[1]<<endl;
    return 0;
}