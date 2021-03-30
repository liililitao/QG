#include "linkedList.h"
#include <stdio.h>
#include <stdlib.h>
/**
 *  @name        : Status InitList(LinkList *L);
 *	@description : initialize an empty linked list with only the head node without value
 *	@param		 : L(the head node)
 *	@return		 : Status
 *  @notice      : None
 */
Status InitList(LinkedList *L) {
    *L = (LinkedList)malloc(sizeof(LinkedList));		//给第一个结点申请空间
	if(!(*L))											//若申请失败返回错误
		return ERROR;
	(*L)->next = NULL;
	return SUCCESS;
}

/**
 *  @name        : void DestroyList(LinkedList *L)
 *	@description : destroy a linked list, free all the nodes
 *	@param		 : L(the head node)
 *	@return		 : None
 *  @notice      : None
 */
void DestroyList(LinkedList *L) {
    LinkedList p;
	while(*L){
		p = (*L)->next;
		free(*L);
		*L = p;
	}
}

/**
 *  @name        : Status InsertList(LNode *p, LNode *q)
 *	@description : insert node q after node p
 *	@param		 : p, q
 *	@return		 : Status
 *  @notice      : None
 */
Status InsertList(LNode *p, LNode *q) {
    if(!p)					//如果p结点不存在，返回错误
		return ERROR;
	q->next = p->next;
	p->next = q;
	return SUCCESS;
}
/**
 *  @name        : Status DeleteList(LNode *p, ElemType *e)
 *	@description : delete the first node after the node p and assign its value to e
 *	@param		 : p, e
 *	@return		 : Status
 *  @notice      : None
 */
Status DeleteList(LNode *p, ElemType *e) {
    if(!p && !p->next)
		return ERROR;
	LNode *q;
	q = p->next;
	*e = q->data;		//调用前检查e是否有指向一个已知的内存空间
	p->next = q->next;
	free(q);
	return SUCCESS;
}

/**
 *  @name        : void TraverseList(LinkedList L, void (*visit)(ElemType e))
 *	@description : traverse the linked list and call the funtion visit
 *	@param		 : L(the head node), visit
 *	@return		 : None
 *  @notice      : None
 */
void TraverseList(LinkedList L, void (*visit)(ElemType e)) {
    LNode *p;
	p = L;
	while(p){
		visit(p->data);
		p = p->next;
	}
}

/**
 *  @name        : Status SearchList(LinkedList L, ElemType e)
 *	@description : find the first node in the linked list according to e
 *	@param		 : L(the head node), e
 *	@return		 : Status
 *  @notice      : None
 */
Status SearchList(LinkedList L, ElemType e) {
    LNode *p;
	p = L;
	while(p){
		if(p->data == e)
			return SUCCESS;
		else
			p = p->next;
	}
	return ERROR;
}

/**
 *  @name        : Status ReverseList(LinkedList *L)
 *	@description : reverse the linked list
 *	@param		 : L(the head node)
 *	@return		 : Status
 *  @notice      : None
 */
Status ReverseList(LinkedList *L) {
    if(!(*L) && !(*L)->next)
		return ERROR;
	LNode *pre, *cur, *Next;		//定义前中后三个指针
	pre = *L;
	cur = (*L)->next;				//先将第一个结点的指针域指向NULL
	pre->next = NULL;
	while(cur){
		Next = cur->next;			//后指针后移
		cur->next = pre;			//将中间的指针指向前一个结点
		pre = cur;					//前中指针后移
		cur = Next;
	}
	*L = pre;						//头指针指向“原尾结点”
	return SUCCESS;
}

/**
 *  @name        : Status IsLoopList(LinkedList L)
 *	@description : judge whether the linked list is looped
 *	@param		 : L(the head node)
 *	@return		 : Status
 *  @notice      : None
 */
Status IsLoopList(LinkedList L) {
    LNode *fast, *slow;
	fast = slow = L;				//快慢指针在相同起点
	while(fast && fast->next){
		slow = slow->next;			//slow走一个结点
		fast = fast->next->next;	//fast走两个结点
		if(slow == fast)
			return SUCCESS;
	}
	return ERROR;
}

/**
 *  @name        : LNode* ReverseEvenList(LinkedList *L)
 *	@description : reverse the nodes which value is an even number in the linked list, input: 1 -> 2 -> 3 -> 4  output: 2 -> 1 -> 4 -> 3
 *	@param		 : L(the head node)
 *	@return		 : LNode(the new head node)
 *  @notice      : choose to finish
 */
LNode* ReverseEvenList(LinkedList *L) {
    LNode *pre, *cur, *Next;		//定义前中后指针，用途和反转相似
	pre = *L;
	*L = pre->next;
	while(pre && pre->next){
		cur = pre->next;
		Next = cur->next;
		if(cur->next && cur->next->next){			//如果cur->next不存在，结点个数为偶数
			pre->next = cur->next->next;			//如果cur->next->next不存在，结点个数为奇数
		}else{										//如果都存在，遍历未结束
			pre->next = cur->next;
		}
		cur->next = pre;							//将偶数结点反转
		pre = Next;
	}
	return *L;
}

/**
 *  @name        : LNode* FindMidNode(LinkedList *L)
 *	@description : find the middle node in the linked list
 *	@param		 : L(the head node)
 *	@return		 : LNode
 *  @notice      : choose to finish
 */
LNode* FindMidNode(LinkedList *L) {
    LNode *mid = *L;
	int cnt;
	for(cnt=0; mid; cnt++)
		mid = mid->next;
	mid = *L;
	for(int i=0; i<cnt/2; i++)
		mid = mid->next;
	return mid;
}

