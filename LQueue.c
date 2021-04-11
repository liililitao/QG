#include<stdio.h>
#include<stdlib.h>
#include<LQueue.h>
void InitLQueue(LQueue *Q){
    LQueue * Q = (LQueue*)malloc(sizeof(LQueue));
    Q->front = Q->rear = NULL;
    return Q;
}
Status IsEmptyLQueue(const LQueue *Q){
    return Q->front == NULL;
}
Status GetHeadLQueue(LQueue *Q, void *e){
    if (IsEmptyAQueue(Q))
	{
		printf("队列为空！没有队头！\n");
		return FALSE;
	}
    return TRUE;
}
int LengthLQueue(LQueue *Q){
    return (Q->rear-Q->front+Q->length)%Q->length;
}
Status EnLQueue(LQueue *Q, void *data){
    Node *n = (Node *)malloc(sizeof(Node));
    if(n == NULL)//内存分配失败
        return ;
    n->data = data;
    n->next = NULL;//尾插法，插入元素指向空
    if(Q->rear == NULL)
    {
        Q->front = n;
        Q->rear = n;
    }
    else{
        Q->rear->next = n;//让n成为当前的尾部节点下一节点
        Q->rear= n;//尾部指针指向n
    }
}
Status DeLQueue(LQueue *Q){
    Node * n = Q->front;
    if(Q->front == NULL)//判断队列是否为空
        return ;
    if(Q->front == Q->rear)//是否只有一个元素
    {
        Q->front = NULL;
        Q->rear = NULL;
    }
    else{
        Q->front = Q->front->next;
        free(n);
    }
}
void ClearLQueue(LQueue *Q){
    if (IsEmptyAQueue(Q))
	{
		printf("队列已经是空的了！\n");
		return;
	}
    Q->front = Q->rear = 0;
}
void LPrint(LQueue *q){
    Node * n = (Node *)malloc(sizeof(Node));
    n = q->front;
    if(n == NULL)
    {
        return ;//队列为空
    }
    while(n != NULL)
    {
        printf("%c ",n->data);
        n = n->next;
    }
    printf("\n");
}
int main(){
    int i=5,j=5;
    LQueue * q;
    q = InitQueue();
    printf("开始入队:\n");
    while(i--)
    {
        printf("元素%c入队，队列为：",'A'+i);
        InsertQueue(q,'A'+i);
        Display(q);
    }
    printf("开始出队:\n");
    while(j--)
    {
        printf("第%d个元素出队，队列为：",5-j);
        DeleteQueue(q);
        Display(q);
    }
    printf("\n");
    return 0;
}