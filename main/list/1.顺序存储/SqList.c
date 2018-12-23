#include <stdio.h>
#include <stdio.h>
#include "sqList.h"

Status List_Init(SqListPtr L) {
	Status s = fail;
	if (L != NULL) {
		//Ϊ�˱�֤�߼�������洢һ�£������һ���ռ����Ա��1��ʼ����������pos 0.
		L->elem = (ElemType *)malloc(sizeof(ElemType)*(LIST_INIT_SIZE+1));
		if (L->elem) {
			L->list_size = LIST_INIT_SIZE;
			L->length = 0;
			s = success;
		}
	}
	return s;
}
void List_Destory(SqListPtr L) {
	if (L) {
		if (L->elem) {
			free(L->elem);
			L->elem = NULL;
			L->length = 0;
		}	
	}
}
void List_Clear(SqListPtr L) {
	if (L) {
		L->length = 0;
	}
}
bool List_Empty(SqListPtr L) {
	return (L->length == 0);
}
int List_Size(SqListPtr L) {
	return L->length;
}
Status List_Retrival(SqListPtr L, int pos, ElemType *elem) {
	//����ָ��λ�õ�Ԫ��
	Status s = range_error;
	if (L) {
		if (pos >= 1 && pos <= L->length) {
			*elem = L->elem[pos];
			s = success;
		}
	}
	return s;
}
Status List_Locate(SqListPtr L, ElemType elem, int *pos) {
	Status s = range_error;
	int i;
	if (L) {
		for (i = 1; i <= L->length; i++) {
			if (elem == L->elem[i]) {
				*pos = i;
				s = success;
				break;
			}
		}
	}
	return s;
}
Status List_Insert(SqListPtr L, int pos, ElemType elem) {
	Status s = range_error;
	int i;
	if (L) {
		if (pos >= 1 && pos <= L->length+1) {
			if (L->length < L->list_size) {
				for (i = L->length; i >= pos; i--) {
					L->elem[i+1] = L->elem[i];
				}
				//��ʼ��ʱlength����0��������Ӧ�ð����ŵ���һ��λ��,pos[1]��ʼ�洢
				L->elem[i+1] = elem;
				L->length++;
				s = success;
			}	
		}
	}
	return s;
}
Status List_Delete(SqListPtr L, int pos) {
	Status s = range_error;
	int i;
	if (L) {
		if (pos >= 1 && pos <= L->length) {
			if (L->length) {
				//��pos��һ��Ԫ�ؿ�ʼ��ǰŲ
				for (i = pos+1; i <= L->length; i++) {
					L->elem[i-1] = L->elem[i];
				}
				L->length--;
				s = success;
			}
		}
	}
	return s;
}
Status List_Prior(SqListPtr L, int pos, ElemType *elem) {
	Status s = range_error;
	if (L) {
		if (pos > 1 && pos <= L->length) {
			*elem = L->elem[pos - 1];
			s = success;
		}
	}
	return s;
}
Status List_Next(SqListPtr L, int pos, ElemType *elem) {
	Status s = range_error;
	if (L) {
		if (pos >= 1 && pos < L->length) {
			*elem = L->elem[pos + 1];
			s = success;
		}
	}
	return s;
}

//test
void List_Print(SqListPtr L) {
	int i;
	if (L) {
		for (i = 1; i <= L->length; i++) {
			//10��Ԫ������һ��
			printf("%d ", L->elem[i]);
			if (i % 10 == 0) {
				printf("/n");
			}
		}
	}
}