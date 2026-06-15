#include<bits/stdc++.h>
using namespace std;
class RadixSort
{
    public:
        const int BASE=10;
        vector<int> sortArray(vector<int> &arr)
        {
            if(arr.size()>0)
            {
                int n=arr.size();
                int minNumber=arr[0];
                for(int i=1;i<n;i++)
                {
                    minNumber=min(minNumber,arr[i]);
                }
                int maxNumber=0;
                for(int i=0;i<n;i++)
                {
                    arr[i]-=minNumber;
                    maxNumber=max(maxNumber,arr[i]);
                }
                radixSortFunction(n,arr,maxNumber);
                for(int i=0;i<n;i++)
                {
                    arr[i]+=minNumber;
                }
            }
            return arr;
        }
    private:
        int getBits(int number)
        {
            int ans=0;
            while(number>0)
            {
                number/=BASE;
                ans++;
            }
            return ans;
        }
        void radixSortFunction(int n,vector<int>& arr,int MaxNumber)
        {
            int Bits=getBits(MaxNumber);
            vector<int> help(n);
            int cnts[BASE];
            for(int offset=1;Bits>0;offset*=BASE,Bits--)
            {
                fill(cnts,cnts+BASE,0);
                for(int i=0;i<n;i++)
                {
                    cnts[(arr[i]/offset)%BASE]++;
                }
                for(int i=1;i<BASE;i++)
                {
                    cnts[i]+=cnts[i-1];
                }
                for(int i=n-1;i>=0;i--)
                {
                    int digit=(arr[i]/offset)%BASE;
                    help[--cnts[digit]]=arr[i];
                }
                for(int i=0;i<n;i++)
                {
                    arr[i]=help[i];
                }
            }
        }      
};
int main()
{
    vector<int> arr={170,45,75,90,802,24,2,66};
    RadixSort radixSort;
    vector<int> sortedArr=radixSort.sortArray(arr);
    for(int num:sortedArr)
    {
        cout<<num<<" ";
    }
    cout<<endl;
    return 0;
}