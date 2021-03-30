#include "linkedList.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void select(LinkedList h);
LinkedList getNode(LinkedList h,int n);
LinkedList creatNode();
void pri(ElemType e);
int sgets();
int main(void)
{
    int n = 0;
    LinkedList p1,h;
    while(n <= 0 || n > 1000){
        puts("请输入要创建的链表节点数(1~1000):");
        n = sgets();
    }
    for(int i=1;i<=n;i++)
        if(i == 1) {
            InitList(&h);
            h->data = i;
        }
        else{
            p1 = (LinkedList)malloc(sizeof(LNode));
            p1->data = i;
            p1->next = h;
            h = p1;
        }
        puts("\t\t\t\t****请选择链表操作****");
        puts("\t\t\t\t1.销毁链表并退出程序");
        puts("\t\t\t\t2.插入一个节点到链表");
        puts("\t\t\t\t3.删除一个节点并输出节点数据");
        puts("\t\t\t\t4.遍历链表并输出链表数据");
        puts("\t\t\t\t5.查询链表是否包含某数");
        puts("\t\t\t\t6.反转链表");
        puts("\t\t\t\t7.判断链表是否出现循环");
        puts("\t\t\t\t8.将链表中偶数节点和前节点交换");
        puts("\t\t\t\t9.查找中间节点");
        select(h);
        return 0;
}
//选项调用
void select(LinkedList h)
{
    char ch;
    ElemType a,*e;
    fflush(stdin);
    e = &a;
    puts("请选择你要进行的操作(取第一个输入)：");
    switch(ch = getchar()){
            case '1':
                DestroyList(&h);
                exit(0);
            case '2':
                puts("请输入你要在第几个节点后插入：");
                a = sgets();
                if(InsertList(getNode(h,a), creatNode()))puts("操作成功");
                else puts("操作失败");
                break;
            case '3':
                puts("请输入你要删除第几个节点之后的节点：");
                a = sgets();
                if(DeleteList(getNode(h,a),e))printf("操作成功，删除节点数据为%d\n",*e);
                else puts("操作失败");
                break;
            case '4':
                TraverseList(h,pri);break;
            case '5':
                puts("请输入要查询的数：");
                a = sgets();
                if(SearchList(h, a))puts("链表中有该数据");
                else puts("链表中不存在该数据");
                break;
            case '6':
                if(ReverseList(&h))puts("操作成功");
                else puts("未知错误");
                break;
            case '7':
                if(IsLoopList(h))puts("链表存在循环");
                else puts("链表不存在循环");
                break;
            case '8':
                h = ReverseEvenList(&h);
                puts("操作成功");
                break;
            case '9':
                FindMidNode(&h);
                break;
            default :puts("请在正确的范围输入！");
        }
        select(h);
}
//找到需要用到的节点
LinkedList getNode(LinkedList h,int n)
{
    if(n<1) return NULL;
    LinkedList p = h;

    for(int i = 1;i < n;i++)
    {
        p = p->next;
        if(i < n-1 && p->next == NULL)
            return NULL;
    }
    return p;
}
//创建一个节点
LinkedList creatNode()
{
    LinkedList q;
    q = (LinkedList)malloc(sizeof(LNode));
    puts("请输入您要插入的数据：");
    q->data = sgets();
    return q;
}
void pri(ElemType e)
{
    printf("%d->",e);
}
//自定义输入函数
int sgets()
{
    char * ret_val;
    char * find;
    char  st[100];
    fflush(stdin);
    ret_val = fgets(st,100,stdin);
    if(ret_val){
        find = strchr(st,'\n');
        if(find)*find = '\0';
        else while(getchar() != '\n')
                continue;
    }
   return atoi(ret_val);
}