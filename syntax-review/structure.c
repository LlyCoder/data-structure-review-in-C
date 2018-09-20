# include <stdio.h>

//先声明结构体类型 
struct person {
	//不像对象，属性后面加 ; 分号 
	int id;
	char name[20];
	char sex;	
}; //这里一定要加分号！！！ 

int main() {
	//在创建结构体变量，并用对象方法赋值  
	struct person student1 = {101, "吕林洋", 'M'};
	//创建变量后逐一赋值 
	struct person student2;
	student2.id = 102;
	student2.name[20] = "余英兰";
	student2.sex = 'W';
	printf("%d %s %c\n",student1.id, student1.name, student1.sex); 
 	printf("%d %s %c\n",student2.id, student2.name, student2.sex);
 	
	return 0;
}
