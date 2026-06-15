#include<bits/stdc++.h>
using namespace std;
class CirculateDeque
{
    public:
        CirculateDeque(int number)
        {
            l=r=size=0;
            arr=new int[number];
            limit=number;
        }
        ~CirculateDeque()
        {
            delete []arr;
        }
        bool isEmpty()
        {
            return size==0;
        }
        bool isFull()
        {
            return limit==size;
        }
        bool insertFront(int number)
        {
            if(isFull())
            {
                return false;
            }
            else
            {
                if(size==0)
                {
                    l=0;
                    r=0;
                    arr[l]=number;
                }
                else
                {
                    l=l==0?limit-1:l-1;
                    arr[l]=number;
                }
                size+=1;
                return true;
            }
        }
        bool insertRear(int number)
        {
            if(isFull())
            {
                return false;
            }
            else
            {
                if(size==0)
                {
                    l=0;
                    r=0;
                    arr[r]=number;
                }
                else
                {
                    r=r==limit-1?0:r+1;
                    arr[r]=number;
                }
                size+=1;
                return true;
            }
        }
        bool deleteFront()
        {
            if(isEmpty())
            {
                return false;
            }
            else
            {
                l=l==limit-1?0:l+1;
                size-=1;
                return true;
            }
        }
        bool deleteRear()
        {
            if(isEmpty())
            {
                return false;
            }
            else
            {
                r=r==0?limit-1:r-1;
                size-=1;
                return true;
            }
        }
        int getFront()
        {
            if(isEmpty())
            {
                return -1;
            }
            else
            {
                return arr[l];
            }
        }
        int getRear()
        {
            if(isEmpty())
            {
                return -1;
            }
            else
            {
                return arr[r];
            }
        }
    private:
        int l;
        int r;
        int size;
        int limit;
        int *arr;
};
int main()
{
    CirculateDeque cd(5);
    cd.insertRear(10);
    cd.insertRear(20);
    cd.insertFront(5);
    cout<<cd.getFront()<<endl; // Outputs 5
    cout<<cd.getRear()<<endl;  // Outputs 20
    cd.deleteFront();
    cout<<cd.getFront()<<endl; // Outputs 10
    return 0;
}