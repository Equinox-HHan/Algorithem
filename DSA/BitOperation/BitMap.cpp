#include<bits/stdc++.h>
using namespace std;
class BitsMap
{
    public:
        vector<int> arr;
        BitsMap(int size)
        {
            arr.resize((size+31)/32,0);
        }
        void add(int num)
        {
            arr[num/32]|=(1<<(num%32));
        }
        void remove(int num)
        {
            arr[num/32]&=~(1<<(num%32));
        }
        void reverse(int num)
        {
            arr[num/32]^=(1<<(num%32));
        }
        bool contains(int num)
        {
            return (arr[num/32]&(1<<(num%32)))!=0;
        }
};
int main()
{   int n=1000;
    srand((unsigned)time(NULL));
    int num=rand()%n;
    BitsMap bm(n);
    unordered_set<int> HashSet;
    double decision=(double)rand()/RAND_MAX;
    int testTime=100000;
    for(int i=0;i<testTime;i++)
    {
        if(decision<0.333)
        {
            bm.add(num);
            HashSet.insert(num);
        }
        else if(decision<0.666)
        {
            bm.remove(num);
            HashSet.erase(num);
        }
        else
        {
            bm.remove(num);
            if(HashSet.find(num)!=HashSet.end())
            {
                HashSet.insert(num);
            }
            else
            {
                HashSet.erase(num);
            }
        }
    }
    for(int i=0;i<n;i++)
    {
        if(bm.contains(i)!=HashSet.count(i))
        {
            cout<<"Oops!"<<endl;
        }
        else
        {
            cout<<"Yes!"<<endl;
        }
    }
    return 0;
}
