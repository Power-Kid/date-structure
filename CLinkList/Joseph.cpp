前言：
约瑟夫环（约瑟夫问题）是一个数学的应用问题：已知 n 个人（以编号1，2，3…n分别表示）围坐在一张圆桌周围。从编号为 k 的人开始报数，数到 m 的那个人出圈；他的下一个人又从 1 开始报数，数到 m 的那个人又出圈；依此规律重复下去，直到剩余最后一个胜利者。
利用循环链表实现。
#include <iostream>
using namespace std;
struct CLionList{           //定义结点
    CLionList(int a_date) : m_date(a_date),m_pNext(NULL){}
    int m_date;
    CLionList *m_pNext;
};
class Joseph{
    public:
        Joseph(int a_N,int a_K,int a_M) : m_N(a_N), m_K(a_K), m_M(a_M){
            createList();   //循环链表的创造
            outputList();   //输出循环链表结点的数据
        }
    protected:
        void createList();
        void outputList();
    private:
        CLionList *m_pHead; //头结点
        int m_N;
        int m_K;
        int m_M;
};
void Joseph::createList(){
    CLionList *p=new CLionList(1);
    CLionList *cur=NULL;    //记录最新的结点
    CLionList *pre=NULL;    //记录上一个结点
    cur=p;
    m_pHead=p;              //把P作为头结点
    for(int i=2;i<=m_N;i++){
        p=new CLionList(i);
        pre=cur;
        cur=p;
        pre->m_pNext=p;     //尾插法
    }
    cur->m_pNext=m_pHead;   //循环链表最关键一步，尾指针指向头结点
    p=m_pHead;              //把头结点赋给p
    int n=m_N;
    cout<<"初始序列"<<endl;
    while(n--){
        cout<<p->m_date<<",";
        p=p->m_pNext;       //顺序输出数据
    }
}
void Joseph::outputList() { //将第一个开始的点作为头结点
    CLionList *pStart = m_pHead;
    int count = 1;
    while (count < m_K) {   //寻找第一个开始的点
        pStart = pStart->m_pNext;
        count++;
    }
    CLionList *temp = pStart;
    CLionList *pre = NULL;
    CLionList *numdelete=NULL;
    cout<<endl;
    cout<<"被排除出去的人的序号："<<endl;
    while (temp->m_pNext != temp) { //如果存在temp->m_pNext == temp，那么链表只有这一个结点
        int count=1;
        while (count < m_M) {
            pre = temp;
            temp = temp->m_pNext;
            count++;        //找到被淘汰的人的结点
        }
        numdelete=temp;
        temp=temp->m_pNext;
        pre->m_pNext=temp;  //删掉被淘汰的人的结点
        cout<<numdelete->m_date<<",";
    }
    cout<<endl<<"最终留下的人的序号为："<<endl;
    cout<<temp->m_date;
}
int main(){
    int total_people;
    int begin_people;
    int step;
    cout<<"请输入总人数："<<endl;
    cin>>total_people;
    cout<<"请输入从多少序号开始："<<endl;
    cin>>begin_people;
    cout<<"请输入几号数字为爆炸数字："<<endl;
    cin>>step;
    Joseph(total_people,begin_people,step);
}
