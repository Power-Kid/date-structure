在舞会上，男、女各自排成一队。舞会开始时，依次从男队和女队的队头各出一人配成舞伴。
如果两队初始人数不等，则较长的那一队中未配对者等待下一轮舞曲。假设初始男、女人数及性别已经固定，舞会的轮数从键盘输入。
试模拟解决上述舞伴配对问题。要求：从屏幕输出每一轮舞伴配对名单，如果在该轮有未配对的，能够从屏幕显示下一轮第一个出场的未配对者的姓名。
————————————————
#include <iostream>
#include <string>
using namespace std;
typedef struct Person {
    char name[20];
    char sex;                           //'F'表示女性，其他任意字母表示男性
}Person;
#define MAXSIZE 100                     //队列可能达到的最大长度
typedef int QElemtype;
typedef struct SqQueue {
    Person *base;                       //存储空间的基地址
    int front;                          //头指针
    int rear;                           //尾指针
}SqQueue;
int InitQueue(SqQueue & Q) {            //初始化队列
    Q.base = new Person[MAXSIZE];
    if (!Q.base)
        cout << "存储分配失败" << endl;
    Q.front = Q.rear = 0;               //头指针和尾指针置为零，队列为空
    return 0;
}
Person EnQueue(SqQueue &Q,Person e) {   //插入元素e为Q的新的队尾元素
    if ((Q.rear + 1) % MAXSIZE == Q.front)
        cout << "队满" << endl;
    Q.base[Q.rear] = e;                 //新元素插入队尾
    Q.rear = (Q.rear + 1) % MAXSIZE;    //队尾指针加1
    return e;
}
Person DeQueue(SqQueue &Q,Person &e) {  //删除Q的队头元素，用e返回其值
    if (Q.front == Q.rear)
        cout << "队空" << endl;
    e = Q.base[Q.front];                //保存队头元素
    Q.front = (Q.front + 1) % MAXSIZE;  //队头指针加1
    return e;
}
Person GetHead(SqQueue Q) {
    if (Q.front != Q.rear)
        return Q.base[Q.front];         //返回队头元素的值，队头指针不变
}
bool QueueEmpty(SqQueue &Q) {           //判断队列是否为空
    if (Q.front == Q.rear )
        return true;
    else
        return false;
}
void DancePartener(Person dancer[]) {   //结构数组dancer[]存放跳舞的男女
    SqQueue Mdancers, Fdancers;         //声明两个队列，Mdancers队列和Fdancers队列
    InitQueue(Mdancers);            //初始化两个队列
    InitQueue(Fdancers);
    int N;
    cout << "请输入参加舞会的总人数：";
    cin >> N;
    Person p;
    for (int j = 0; j < N; j++)
    {
        cout << "请输入参加舞会第" << j + 1 << "个人的姓名: ";
        cin >> dancer[j].name;
        cout << "请输入参加舞会第" << j + 1 << "个人的性别: ";
        cin >> dancer[j].sex;
    }
    for (int i = 0; i < N; i++) {
        p = dancer[i];
        if (p.sex == 'F') EnQueue(Fdancers, p); //插入女队
        else EnQueue(Mdancers, p);              //插入男队
    }
    cout << "The dancing partners are: \n";
    while (!QueueEmpty(Fdancers) && !QueueEmpty(Mdancers)) {
        DeQueue(Fdancers, p);
        cout << p.name << " ";
        DeQueue(Mdancers, p);
        cout << p.name << " ";
        cout<<endl;
    }
    if (!QueueEmpty(Fdancers)) {
        p = GetHead(Fdancers);
        cout << "The first woman to get a partner is : " << p.name << endl;
    }
    else if (!QueueEmpty(Mdancers)) {
        p = GetHead(Mdancers);
        cout << "The first man to get a partner is : " << p.name << endl;
    }
}
int main()
{
    Person dancers[100];
    DancePartener(dancers);
    return 0;
}

