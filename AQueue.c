#include<stdio.h>
#include<stdlib.h>
#include<AQueue.h>
void InitAQueue(AQueue *Q){
    int i;
	Q->length = MAXQUEUE;
    for(i = 0; i < MAXQUEUE; i++)
        Q->data[i] = (void *)malloc(21);
	Q->front = Q->rear = 0;
}
void DestoryAQueue(AQueue *Q){
    if(Q->data[0] == NULL)
    {
        printf("队列目前未初始化！请先初始化队列！\n");
        return;
    }
	for(int i = 0; i < MAXQUEUE; i++)
        free(Q->data[i]);
	Q->data[0] = NULL;
}
Status IsFullAQueue(const AQueue *Q){
    if(Q->data[0] == NULL)
    {
        printf("队列目前未初始化！请先初始化队列！\n");
        return FALSE;
    }
    if(IsEmptyAQueue(Q))
        return FALSE;
    if(LengthAQueue(Q)==MAXQUEUE-1)
    {
        return TRUE;
    }
    else
        return FALSE;
}
Status IsEmptyAQueue(const AQueue *Q){
    if(Q->data[0] == NULL)
    {
        printf("队列目前未初始化！请先初始化队列！\n");
        return FALSE;
    }
	return (LengthAQueue(Q) == 0 ? TRUE : FALSE);
}
Status GetHeadAQueue(AQueue *Q, void *e){
    if (IsEmptyAQueue(Q))
	{
		printf("队列为空！没有队头！\n");
		return FALSE;
	}
	memcpy(e, Q->data[Q->front],20);
    return TRUE;
}
int LengthAQueue(AQueue *Q){
    return (Q->rear-Q->front+Q->length)%Q->length;
}
Status EnAQueue(AQueue *Q, void *data){
    if (IsFullAQueue(Q))
	{
		printf("队列满了！不能再入队了！\n");
		return FALSE;
	}
	if (IsEmptyAQueue(Q))
	{
		memcpy(Q->data[Q->front], data, 20);
		Q->rear = (Q->rear + 1) % Q->length;
		return TRUE;
	}
    memcpy(Q->data[Q->rear], data, 20);
	Q->rear = (Q->rear + 1) % Q->length;
    return TRUE;
}
Status DeAQueue(AQueue *Q){
    if (IsEmptyAQueue(Q))
    {
    	printf("队列是空的！出不了队！\n");
    	return FALSE;
    }
    Q->front = (Q->front+1)%Q->length;
    return TRUE;
}
void ClearAQueue(AQueue *Q){
    if (IsEmptyAQueue(Q))
	{
		printf("队列已经是空的了！\n");
		return;
	}
    Q->front = Q->rear = 0;
}
Status TraverseAQueue(const AQueue *Q, void (*foo)(void *q,int typeData)){
    if(Q->data[0] == NULL)
        {
            printf("队列目前未初始化！请先初始化队列！\n");
            return FALSE;
        }
    	if (IsEmptyAQueue(Q))
    	{
    		printf("队列里面什么都没有!\n");
    		return FALSE;
    	}
    	int i = 0;
    	while (i < (MAXQUEUE - Q->front + Q->rear) % MAXQUEUE) {
    		foo(Q->data[Q->front+i], Q->type[Q->front+i]);
    		i = (i + 1) % MAXQUEUE;
    	}
        return TRUE;
}
void APrint(void *q,int typeData){
    if(typeData == 3)
            printf("--> %.2lf", *(double*)q);
        if(typeData == 2)
            printf("--> %c", *(char*)q);
        if(typeData == 1)
            printf("--> %d ", *(int*)q);
        if(typeData == 4)
            printf("--> %s ", (char*)q);
}
int main(){
    int t;
    AQueue *Q;
    printf("你想入队哪种类型？:\n");
    printf("1. 整型 2. 字符型 3. 浮点型(精确到小数点后2位) 4. 字符串\n");
    scanf("%d", &t);
    while(t<1 || t>4)
    {
     	printf("应输入在[1,4]之间的整数！\n请重输：");
      	scanf("%d", &t);
    }
	printf("想入队的数据 :");
    switch(t)
    {
     	case 1:{
			int a;
			scanf("%d", &a);
			Q->type[Q->rear]=t;
			EnAQueue(Q, &a);
		break;
		}
		case 2: {
			char a ;
			scanf("%c", &a);
			Q->type[Q->rear]=t;
			EnAQueue(Q, &a);
			break;
		}
        case 3:{
			double a ;
			scanf("%lf", &a);
			Q->type[Q->rear]=t;
			EnAQueue(Q, &a);
			break;
		}
        case 4:{
			char a[20];
			printf("最大长度为20哦！\n");
			scanf("%s", a);
			Q->type[Q->rear]=t;
			EnAQueue(Q, a);
			break;
		}
}