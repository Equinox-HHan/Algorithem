#include<bits/stdc++.h>
using namespace std;
//用时间戳实现对数据的不遍历覆盖
class SetAllHashmap
{
    public:
        unordered_map<int,pair<int,int>> Hashmap;
        int Timestamp=-1;//修改元素的时间戳
        int Value=0;
        int count=0;//自然时间戳
        void put(int key,int value)
        {
            count+=1;
            Hashmap[key]={value,count};
        }
        void setAll(int value)
        {
            Timestamp=count;
            Value=value;
        }
        int get(int key)
        {
            if(Hashmap.find(key)==Hashmap.end())
            {
                return -1;
            }
            pair<int,int> temp=Hashmap[key];
            if(temp.second<Timestamp)
            {
                return Value;
            }
            else
            {
                return temp.first;
            }
        }
        void clear()
        {
            Hashmap.clear();
            Timestamp=-1;
            Value=0;
            count=0;
        }  
};
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin.tie(nullptr);
    SetAllHashmap HASHMAP;
    const int n=5;
    for(int i=0;i<n;i++)
    {
        HASHMAP.clear();
        for(int i=0;i<n;i++)
        {
            int opnumber,number1,number2;
            cout<<"Enter OPnumber (1,2,3)"<<endl;
            cin>>opnumber;
            if(opnumber==1)
            {
                cout<<"Enter number1,number2"<<endl;
                cin>>number1>>number2;
                HASHMAP.put(number1,number2);
            }
            else if(opnumber==2)
            {
                cout<<"Enter number"<<endl;
                cin>>number1;
                HASHMAP.setAll(number1);
            }
            else
            {
                cout<<"Enter number"<<endl;
                cin>>number1;
                cout<<HASHMAP.get(number1)<<endl;
            }
        }
    }
    return 0;
}