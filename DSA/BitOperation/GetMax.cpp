#include<bits/stdc++.h>
using namespace std;
//不用任何条件判断语句求最大值
int flip(int n)
{
    return n^1;
}
//非负数返回1，负数返回0
int sign(int n)
{
    return flip(((unsigned)n)>>31);
}
int getMax(int number1,int number2)
{
    int number=number1-number2;
    int sign1=sign(number1);
    int sign2=sign(number2);
    int sign0=sign(number);
    //判断number1和number2的符号是否相同
    int diff=sign1^sign2;
    int same=flip(diff);
    //number1,number2符号不同，看number1的正负
    int returnA=diff*sign1+same*sign0;
    int returnB=flip(returnA);
    return number1*returnA+number2*returnB;
}
int main()
{
    int number1,number2;
    cin>>number1>>number2;
    cout<<getMax(number1,number2)<<endl;
    return 0;
}