#include<bits/stdc++.h>
#include"Queue.h"
using namespace std;
//用两个队列实现一个栈
class QueueConvertStack
{
    public:
        QueueConvertStack(){}
        void offerIn(int x)
        {
            q.offer(x);
            for(int i=0;i<q.size();i++)
            {
                int number=q.poll();
                q.offer(number);
            }
        }
        int pollOut()
        {
            return q.poll();
        }
        int peekOut()
        {
            return q.peek();
        }  
    private:
        Queue1 q;
};
//用数组队列实现一个栈
class QueueConvertStack2
{
    public:
        QueueConvertStack2(int n):q(n){}
        void offerIn(int x)
        {
            q.offer(x);
            for(int i=0;i<q.size();i++)
            {
                int number=q.poll();
                q.offer(number);
            }
        }
        int pollOut()
        {
            return q.poll();
        }
        int peekOut()
        {
            return q.peek();
        }  
    private:
        Queue2 q;
};
int main()
{
    QueueConvertStack s;
    s.offerIn(1);
    s.offerIn(2);
    s.offerIn(3);
    s.offerIn(4);
    s.offerIn(5);
    cout<<s.peekOut()<<endl;
    cout<<s.pollOut()<<endl;
    cout<<s.pollOut()<<endl;
    cout<<s.pollOut()<<endl;
    cout<<s.pollOut()<<endl;
    cout<<s.pollOut()<<endl;
    QueueConvertStack2 s2(10);
    s2.offerIn(1);
    s2.offerIn(2);
    s2.offerIn(3);
    s2.offerIn(4);
    s2.offerIn(5);
    cout<<s2.peekOut()<<endl;
    cout<<s2.pollOut()<<endl;
    cout<<s2.pollOut()<<endl;
    cout<<s2.pollOut()<<endl;
    cout<<s2.pollOut()<<endl;
    cout<<s2.pollOut()<<endl;
    return 0;    
}
