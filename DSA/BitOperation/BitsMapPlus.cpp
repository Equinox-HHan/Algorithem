#include<bits/stdc++.h>
using namespace std;
class BitsMapPlus
{
    public:
        vector<int> arr;
        BitsMapPlus(int n)
        {
            arr.resize((n+31)/32);
            ones=0;
            zeros=n;
            reverse=false;
        }
        void fix(int num)
        {
            int bits=num%32;
            int index=num/32;
            if(!reverse)
            {
                if((arr[index]&(1<<bits))==0)
                {
                    arr[index]|=(1<<bits);
                    ones++;
                    zeros--;
                }
            }
            else
            {
                if((arr[index]&(1<<bits))!=0)
                {
                    arr[index]&=~(1<<bits);
                    ones--;
                    zeros++;
                }
            }
        }
        void unfix(int num)
        {
            int bits=num%32;
            int index=num/32;
            if(!reverse)
            {
                if((arr[index]&(1<<bits))!=0)
                {
                    arr[index]&=~(1<<bits);
                    ones--;
                    zeros++;
                }
            }
            else
            {
                if((arr[index]&(1<<bits))==0)
                {
                    arr[index]|=(1<<bits);
                    ones++;
                    zeros--;
                }
            }
        }
        void flip()
        {
            reverse=!reverse;
            int temp=ones;
            zeros=ones;
            zeros=temp;
        }
        int count()
        {
            return ones;
        }
        string toString()const
        {
            ostringstream ss;
            for(int i=0,k=0;i<arr.size();k++)
            {
                int status;
                int number=arr[k];
                for(int j=0;j<32&&i<arr.size();j++,i++)
                {
                    status=(number>>j)&1;
                    status^=reverse?1:0;
                    ss<<status;
                }
            }
            return ss.str();
        }
    private:
        int ones;
        int zeros;
        bool reverse;
};
int main()
{
    BitsMapPlus bmp(10);
    bmp.fix(3);
    bmp.fix(5);
    cout<<bmp.toString()<<endl;
    cout<<bmp.count()<<endl;
    bmp.flip();
    cout<<bmp.toString()<<endl;
    cout<<bmp.count()<<endl;
    return 0;
}