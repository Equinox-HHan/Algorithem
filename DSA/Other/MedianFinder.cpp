#include<bits/stdc++.h>
using namespace std;
class MediaFinder
{
    private:
        priority_queue<int> maxHeap;
        priority_queue<int,vector<int>,greater<int>> minHeap;
        void balance()
        {
            if(abs((int)maxHeap.size()-(int)minHeap.size()==2))
            {
                if(maxHeap.size()>minHeap.size())
                {
                    minHeap.push(maxHeap.top());
                    maxHeap.pop();
                }
                else
                {
                    maxHeap.push(minHeap.top());
                    minHeap.pop();
                }
            }
        }
    public:
        void AppendNumber(int number)
        {
            if(maxHeap.empty()||maxHeap.top()>=number)
            {
                maxHeap.push(number);
            }
            else
            {
                minHeap.push(number);
            }
            balance();
        }
        double getMedian()
        {
            if(minHeap.size()==maxHeap.size())
            {
                double number=(minHeap.top()+maxHeap.top())/2.00;
                return number;
            }
            else
            {
                return (maxHeap.size()>minHeap.size())?
                maxHeap.top():minHeap.top();
            }
        }
};
int main()
{
    MediaFinder FINDER;
    FINDER.AppendNumber(21);
    FINDER.AppendNumber(10);
    FINDER.AppendNumber(17);
    cout<<FINDER.getMedian()<<endl;
    return 0;
}