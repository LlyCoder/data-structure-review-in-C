//ֻ����һ��
#pragma once
#define bool int
#define LIST_INIT_SIZE 100
#define	LIST_INCREAMENT 10
 
typedef enum Status {
	//0 , 1 , ...
	success, fail, fatal,range_error
}Status;

typedef int ElemType;

typedef struct SqList {
	ElemType *elem; //�����ռ��׵�ַ(elem����������)
	int length;  //��ǰ���Ա�Ԫ�ظ�����Ĭ��Ϊ 0 
	int list_size;  //��ǰ������ռ�ĳ��ȣ�Ĭ��LIST_INIT_SIZE
}SqList, *ptr, *SqListPtr;

Status List_Init(SqListPtr L);
void List_Destory(SqListPtr L);
void List_Clear(SqListPtr L);
bool List_Empty(SqListPtr L);
int List_Size(SqListPtr L);
Status List_Retrival(SqListPtr L, int pos, ElemType *elem);
Status List_Locate(SqListPtr L, ElemType elem, int *pos);
Status List_Insert(SqListPtr L, int pos, ElemType elem);
Status List_Delete(SqListPtr L, int pos);
Status List_Prior(SqListPtr L, int pos, ElemType *elem);
Status List_Next(SqListPtr L, int pos, ElemType *elem);

//test
void List_Print(SqListPtr L);