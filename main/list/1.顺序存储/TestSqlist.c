#include <stdio.h>
#include <stdlib.h>
#include "TestSqList.h"

Status Test_CreateList(SqListPtr list, ElemType data[], int n) {
	Status s = fail;
	int i;
	s = List_Init(list);
	if (s == success) {
		for (i = 1; i <= n; ++i) {
			s = List_Insert(list, i, data[i]);
			if (s != success) {
				break;
			}
		}
		List_Print(list);
	}
	return s;
}
Status Test_ClearList(SqListPtr list) {
	Status s = fail;
	if (!List_Empty(list)) {
		List_Clear(list);
		if (List_Empty(list)) {
			s = success;
		}
	}
	return s;
}
Status Test_RetrivalPriorNext(SqListPtr list, int pos) {
	Status s = range_error;
	ElemType e;
	s = List_Retrival(list, pos, &e);
	if (s == success) {
		printf("pos[%d] 是 %d\n", pos, e);
		s = List_Prior(list, pos, &e);
		if (s == success) {
			printf("前驱元素是 %d\n", e);
		}
		else printf("没有直接前驱元素\n");
		s = List_Next(list, pos, &e);
		if (s == success) {
			printf("后继元素元素是 %d\n", e);
		} 
		else printf("没有直接后继元素\n");
	}
	else {
		printf("位置不合法\n");
	}
	return s;
}

Status Test_Locate(SqListPtr list, ElemType e) {
	Status s;
	int pos;
	s = List_Locate(list, e, &pos);
	if (s == success) {
		printf("元素%d在pos %d 的位置\n", e, pos);
	}
	else printf("查找失败\n");
	return s;
}
void Test_Size(SqListPtr list) {
	int len;
	len = List_Size(list);
	printf("线性表的长度是 %d \n", len);

}