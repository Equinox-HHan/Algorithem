#include<bits/stdc++.h>
using namespace std;
class AllinOne
{
    private:
        struct Bucket
        {
            unordered_set<string> key;
            int count;
            Bucket *pre;
            Bucket *next;
            Bucket(const string &str,int count)
            {
                pre=nullptr;
                next=nullptr;
                this->count=count;
                if(!key.empty())
                {
                    key.insert(str);
                }
            }
        };
        Bucket *Head;
        Bucket *Tail;
        unordered_map<string,Bucket*> map;
        void insertNode(Bucket *current,Bucket *position)
        {
            current->next->pre=position;
            position->next=current->next;
            current->next=position;
            position->pre=current;
        }
        void removeNode(Bucket *position)
        {
            position->pre->next=position->next;
            position->next->pre=position->pre;
        }
    public:
        AllinOne()
        {
            Head=new Bucket(" ",0);
            Tail=new Bucket(" ",INT_MAX);
            Head->next=Tail;
            Tail->pre=Head;
        }
        ~AllinOne()
        {
            Bucket *current=Head;
            while(current!=nullptr)
            {
                Bucket *Next=current->next;
                delete current;
                current=Next;
            }
        }
        void inc(string keyWord)
        {
            if(!map.count(keyWord))
            {
                if(Head->next->count==1)
                {
                    map[keyWord]=Head->next;
                    Head->next->key.insert(keyWord);
                }
                else
                {
                    Bucket *newNode=new Bucket(keyWord,1);
                    map[keyWord]=newNode;
                    insertNode(Head,newNode);
                }
            }
            else
            {
                Bucket *current=map[keyWord];
                if(current->next->count==current->count+1)
                {
                    map[keyWord]=current->next;
                    current->next->key.insert(keyWord);
                }
                else
                {
                    Bucket *newNode=new Bucket(keyWord,current->count+1);
                    map[keyWord]=newNode;
                    insertNode(current,newNode);
                }
                current->key.erase(keyWord);
                if(current->key.empty())
                {
                    removeNode(current);
                    delete current;
                }
            }
        }
        void dec(string keyWord)
        {
            if(!map.count(keyWord))
            {
                return;
            }
            Bucket *current=map[keyWord];
            if(current->count==1)
            {
                map.erase(keyWord);
            }
            else
            {
                if(current->pre->count==current->count-1)
                {
                    map[keyWord]=current->pre;
                    current->pre->key.insert(keyWord);
                }
                else
                {
                    Bucket *newNode=new Bucket(keyWord,current->count-1);
                    map[keyWord]=newNode;
                    insertNode(current,newNode);
                }
            }
            current->key.erase(keyWord);
            if(current->key.empty())
            {
                removeNode(current);
                delete current;
            }
        }
        string getMin()
        {
            if(Head->next==Tail)
            {
                return " ";
            }
            else
            {
                return *(Head->next->key.begin());
            }
        }
        string getMax()
        {
            if(Tail->pre==Head)
            {
                return " ";
            }
            else
            {
                return *(Tail->pre->key.begin());
            }
        }
};
int main()
{
    return 0;
}