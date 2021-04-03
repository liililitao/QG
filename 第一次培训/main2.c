#include "duLinkedList.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void select(DuLinkedList h);
void pri(ElemType e);
DuLinkedList refresh(DuLinkedList h);
DuLinkedList getNode(DuLinkedList h,int n);
DuLinkedList creatNode();
int sgets();
int main(void)
{
    int n = 0;
    DuLinkedList p1,p2,h;
    while(n <= 0 || n > 1000){
        puts("请输入要创建的链表节点数(1~1000):");
        n = sgets();
    }
    for(int i = 1;i <= n;i++)
        if(i == 1) {
           InitList_DuL(&h);
           h->data = i;
           p1 = h;
       }
       else{
           p2 = (DuLinkedList)malloc(sizeof(DuLNode));
           p2->data = i;
           p2->next = NULL;
           p2->prior = p1;
           p1->next = p2;
           p1 = p2;
       }
       puts("\t\t\t\t****请选择链表操作****");
       puts("\t\t\t\t1.销毁链表并退出程序");
       puts("\t\t\t\t2.插入一个节点到链表指定节点前");
       puts("\t\t\t\t3.插入一个节点到链表指定节点后");
       puts("\t\t\t\t4.删除一个节点并输出节点数据");
       puts("\t\t\t\t5.遍历链表并输出链表数据");
       select(h);
    return 0;
}
void select(DuLinkedList h)
{
   char ch;
   ElemType a,*e;
   fflush(stdin);
   e = &a;
   puts("请选择你要进行的操作(取第一个输入）：");
   switch(ch = getchar()) {
       case '1':
           DestroyList_DuL(&h);
           exit(0);
       case '2':
           puts("请输入你要在第几个节点前插入：");
           a = sgets();
           if(InsertBeforeList_DuL(getNode(h,a), creatNode())) puts("操作成功");
           else puts("操作失败：指定节点不存在");
           h = refresh(h);
           break;
       case '3':
           puts("请输入你要在第几个节点后后插入：");
           a = sgets();
           if(InsertAfterList_DuL(getNode(h,a), creatNode())) puts("操作成功");
           else puts("操作失败：指定节点不存在");
           break;
       case '4':
           puts("请输入你要删除第几个节点之后的节点：");
           a = sgets();
           if(DeleteList_DuL(getNode(h,a),e)) printf("操作成功，删除节点数据为%d\n",*e);
           else puts("操作失败");
           break;
       case '5':
           TraverseList_DuL(h,pri);break;
       default :puts("请在正确的范围输入！");
   }
    select(h);
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
//找到需要用到的节点
DuLinkedList getNode(DuLinkedList h,int n)
{
   if(n<1) return NULL;
   DuLinkedList p = h;

   for(int i = 1;i < n;i++)
   {
       p = p->next;
       if(i < n-1 && p->next == NULL)
           return NULL;
   }
   return p;
}
//创建一个节点
DuLinkedList creatNode()
{
   DuLinkedList q;
   q = (DuLinkedList)malloc(sizeof(DuLNode));
   puts("请输入您要插入的数据：");
   q->data = sgets();
   q->next = q->prior = NULL;
   return q;
}
void pri(ElemType e)
{
   printf("%d->",e);
}
DuLinkedList refresh(DuLinkedList h)
{
   while(h->prior) h = h->prior;
   return h;
}