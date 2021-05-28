顺序存储结构：
#include <iostream>
#include "string"
using namespace std;
#define MAXSIZE 225
typedef struct {
    char ch[MAXSIZE+1];
    int length;
}HString;
int Strlength(HString &T){
    return T.length;
}
int StrAssign(HString &T,char cstr[]){
    int i;
    for(i=0;cstr[i]!='\0';i++)
        T.ch[i]=cstr[i];
    T.length=i;
    return 0;
}
int Concat(HString &T,HString A,HString B){
    int i;
    T.length=A.length+B.length;
    for(i=0;i<A.length;i++)
        T.ch[i]=A.ch[i];
    for(i=0;i<B.length;i++)
        T.ch[A.length+i]=B.ch[i];
    return 0;
}
int disStr(HString T){
    int i;
    if(T.length>0){
        for(i=0;i<T.length;i++)
            cout<<T.ch[i];
        cout<<endl;
    }
}
int main() {
    HString T;
    StrAssign(T,"123");
    HString H;
    StrAssign(H,"accb");
    HString L;
    Concat(L,T,H);
    disStr((L));
    return 0;
}
堆存储结构：
#include <iostream>
#include "string"
using namespace std;
#define MAXSIZE 225
typedef struct {
    char *ch;
    int length;
}HString;
int StrAssign(HString &T,char *chars){
    char*temp=chars;
    T.length=0;
    while(*temp){
        ++T.length;
        ++temp;
    }
    T.ch=new char[T.length+1];
    char *tmp=T.ch;
    while (*chars){
        *tmp++=*chars++;
    }
    *tmp='\0';
    return 0;
}
int Concat(HString &T,HString A,HString B){
    T.length=A.length+B.length;
    T.ch=new char[T.length+1];
    char *tmp=T.ch;
    while(*A.ch){
        *tmp++=*A.ch++;
    }
    while(*B.ch){
        *tmp++=*B.ch++;
    }
    *tmp='\0';
    return 0;
}
void disStr(HString T){
    while(*T.ch){
        cout<<*T.ch++;
    }
    cout<<endl;
}
int main(){
    HString T;
    StrAssign(T,"123");
    HString H;
    StrAssign(H,"accb");
    HString L;
    Concat(L,T,H);
    disStr(L);
}
