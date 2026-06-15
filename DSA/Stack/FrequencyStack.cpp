#include<bits/stdc++.h>
using namespace std;
class FreStack
{
    private:
        int topTimes;
        unordered_map<int,int> valueTimes;//值->该值当前出现的频率
        unordered_map<int,vector<int>> countTimes;//楼层->压入vector的内容
    public:
        FreStack()
        {
            topTimes=0;
        }
        void putNumber(int number)
        {
            int curTopTime=valueTimes[number]+1;
            countTimes[curTopTime].push_back(number);
            topTimes=max(topTimes,curTopTime);
        }
        int popNumber()
        {
            int ans=countTimes[topTimes].back();
            countTimes[topTimes].pop_back();
            if(countTimes[topTimes].empty())
            {
                countTimes.erase(topTimes);
                topTimes-=1;
            }
            valueTimes[ans]-=1;
            if(valueTimes[ans]==0)
            {
                valueTimes.erase(ans);
            }
            return ans;
        }
};
int main()
{
    return 0;
}