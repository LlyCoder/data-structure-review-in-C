# include <stdio.h>

int main () {
	//����ö������ 
	//��һ��ö�ٳ�ԱĬ��ֵΪ0������ĳ�Ա����ǰһ����Ա�Ļ����ϼ� 1 �����������޶���һ����ԱΪ 1 
	enum DAY {
		MON = 1, TUE, WED, THU, FFI, SAT, SUN
	};
	
	enum season = {spring, summer=3, autumn, winter}; // 0 3 4 5
	
	
	
	//����ö�ٱ���
	//1. �ȴ���ö�������ٶ������ 
	enum DAY = {
		mon = 1, tue, wed, thu. fri ,sat, sun 
	};
	enum DAY day;
	
	//2. ����ö�����͵�ͬʱ����ö�ٱ��� 
	enum DAY = {
		mon = 1, tue, wed, thu, fri, sta, sun
	} day;
	
	//3. ʡ��ö������ֱ�Ӵ���ö�ٱ���
	enum {
		mon = 1, tue, wed, thu, fri, sta, sun
	} day;
	
	return 0;
}