#include <iostream>
using namespace std;
#define  MAXSIZE 100
typedef int SElemtype;
typedef struct{
    SElemtype *base;
    SElemtype *top;
    int stacksize;
}SqStack;

int main(){
    void InitStack(SqStack &s);
    void Push(SqStack &s,int k);
    int Pop(SqStack &s,int k);
    void Conversion(int n,int m);
    int n,m;
    cout<<"请输入你想要转换的10进制数："<<endl;
    cin>>n;
    cout<<"请输入你想要转换的进制："<<endl;
    cin>>m;
    Conversion(n,m);
    return 0;
}
void InitStack(SqStack &s){
    s.base=new SElemtype [MAXSIZE];
    if(!s.base)
        cout<<"there is a wrong";
    s.top=s.base;
    s.stacksize=MAXSIZE;
}
void Push(SqStack &s,int k){
    if(s.top-s.base == s.stacksize)
        cout<<"栈满"<<endl;
    *s.top++ = k;
}
int Pop(SqStack &s,int k){
    if(s.top == s.base)
        cout<<"栈空"<<endl;
    k=*--s.top;
    return k;
}
void Conversion(int n,int m){
    int reminder;
    SqStack s;
    InitStack(s);
    while(!(n == 0))
    {
        reminder = n % m;
        Push(s,reminder);
        n=n / m;
    }
    while(!(s.top == s.base)){
        cout<<Pop(s,reminder);
    }
}
