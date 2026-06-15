#include<bits/stdc++.h>
using namespace std;
class Employee
{
    public:
        Employee(int idNumber,int number)
        {
            ID=idNumber;
            age=number;
        }
        friend ostream& operator<<(ostream& os,const Employee& em)
        {
            os<<"#"<<em.ID<<" "<<em.age<<endl;
            return os;
        }
        int ID;
        int age;    
};
struct employeeComparator
{
    bool operator()(Employee& em1,Employee& em2)const
    {
        return em1.age<em2.age;
    }
};
int main()
{
    Employee em1(266348,26);
    Employee em2(604597,30);
    Employee em3(298046,42);
    vector<Employee> vec;
    vec.push_back(em1);
    vec.push_back(em2);
    vec.push_back(em3);
    sort(vec.begin(),vec.end(),employeeComparator());
    {
        for(const auto& element:vec)
        {
            cout<<element;
        }
    }
    sort(vec.begin(),vec.end(),[](const Employee& em1,const Employee& em2)
    {
        if(em1.ID!=em2.ID)
        {
            return em1.ID<em2.ID;
        }
        else
        {
            return em1.age<em2.age;
        }
    });
    for(const auto& element:vec)
    {
        cout<<element;
    }
    return 0;
}