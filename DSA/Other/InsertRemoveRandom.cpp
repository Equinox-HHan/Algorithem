#include<bits/stdc++.h>
using namespace std;
class RandomizeSet
{
    private:
        vector<int> arr;
        unordered_map<int ,int> Hashmap;
    public:
        RandomizeSet(){}
        bool insertNumber(int value)
        {
            if(Hashmap.count(value))
            {
                return false;
            }
            Hashmap[value]=arr.size();
            arr.push_back(value);
            return true;
        }
        bool removeNumber(int value)
        {
            if(!Hashmap.count(value))
            {
                return false;
            }
            int valIndex=Hashmap[value];
            int endValue=arr.back();
            arr[valIndex]=endValue;
            Hashmap[endValue]=valIndex;
            Hashmap.erase(value);
            arr.pop_back();
            return true;
        }
        int getRandom()
        {
            int randomIndex=rand()%arr.size();
            return arr[randomIndex];
        }
};
int main()
{
    RandomizeSet RS;
    RS.insertNumber(10);
    RS.insertNumber(21);
    return 0;
}