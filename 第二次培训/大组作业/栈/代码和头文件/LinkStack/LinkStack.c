#include<stdio.h>
#include<malloc.h>
#include<LinkStack.h>
int main()
{
        int j;
        LinkStack s;
        int e;
        if(InitStack(&s) == SUCCESS)
            for(j = 1;j <= 10;j++)
                 push(&s,j);
        printf("栈中元素依次为：");
        traversestack(s);
        pop(&s,&e);
        printf("弹出的栈顶元素 e=%d\n",e);
        printf("栈空否：%d(1:空 0:否)\n",stackempty(s));
        GetTop(s,&e);
        printf("栈顶元素 e=%d 栈的长度为%d\n",e,StackLength(s));
        ClearStack(&s);
        printf("清空栈后，栈空否：%d(1:空 0:否)\n",stackempty(s));
        return 0;
}
Status initLStack(LinkStack *s){
    s -> top = (LinkStackPtr)malloc(sizeof(StackNode));
        if(!s -> top)
            return ERROR;
        s -> top = NULL;
        s -> count = 0;
        return SUCCESS;
}
Status isEmptyLStack(LinkStack s){
    if (s.count == 0)
        return SUCCESS;
    else
        return ERROR;
}
Status getTopLStack(LinkStack s,ElemType *e){
    if (s.top == NULL)
         return ERROR;
    else
        *e = s.top -> data;
    return SUCCESS;
}
Status clearLStack(LinkStack *s){
    LinkStackPtr p,q;
        p = s -> top;
        while(p)
        {  
            q = p;
            p = p -> next;
            free(q);		//对每一个节点进行释放 
        } 
        s -> count = 0;
        return SUCCESS;
}
Status destroyLStack(LinkStack *s){

}
Status LStackLength(LinkStack s,int *length){
    return s.count;
}   
Status pushLStack(LinkStack *s,ElemType data){
    LinkStackPtr s = (LinkStackPtr)malloc(sizeof(StackNode));
	s -> data = data;
	s -> next = s -> top;		//把当前的栈顶赋值给新的元素的后继(指针的指向)
	s -> top = s;		//新的节点赋值给栈顶指针（即让新元素成为栈顶元素）
	s -> count++;
	return SUCCESS;
}
Status popLStack(LinkStack *s,ElemType *data){
    LinkStackPtr p;		//临时节点
	if(stackempty(*s))
		return 0;
	else
	{
		*data = s -> top -> data;
		p = s -> top;		//将栈顶指针交给p 
		s -> top = s -> top -> next;	//使得栈顶指针下移一位
		free(p);		//因为节点被删除，所以要释放临时节点		
		s -> count--;			//计数器减一个 
		return SUCCESS;
	}
}