#include<stdio.h>
#include<malloc.h>
#include<SqStack.h>
int main()
{
        int j;
        SqStack s;
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
Status initStack(SqStack *s,int sizes){
    if(s!=NULL)
    {
        s->top=-1;             //置为空栈 
        return SUCCESS;
    }
    else 
        return ERROR;        //内存空间不足 
}
Status isEmptyStack(SqStack s){
    if (s.size == 0)
        return SUCCESS;
    else
        return ERROR;
}
Status getTopStack(SqStack *s,ElemType *e){
    if(s->top==-1)
    {               //栈为空，操作失败 
        return ERROR;
    }
    else
    {
        s=s->elem[s->top];   //读取栈顶元素成功 
        return SUCCESS;
    }
}
Status clearStack(SqStack *s){
    s->top=-1;
    return SUCCESS;
}
Status destroyStack(SqStack *s){
    free(s->elem);
	s->elem = NULL;
	s->top = NULL;
	s->size = 0;
	printf("销毁成功\n");
	return SUCCESS;
}
Status stackLength(SqStack s,int *length){
    return s.top - *s.elem;   //实际元素
}
Status pushStack(SqStack *s,ElemType data){
    if(s->top-*s->elem==s->size) 
		return ERROR;
	s->top=data;     
	s->top++;  //栈顶指针加1
	return SUCCESS;
}
Status popStack(SqStack *s,ElemType *data){
    if(s->top==s->elem) //栈空
		return ERROR;
	s->top--;
	data=s->top; 
	return SUCCESS;
}