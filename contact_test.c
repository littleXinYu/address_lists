#define _CRT_SECURE_NO_WARNINGS

#include "contact.h"

//制作通讯录
//要求：
//1.存放1000人信息
//2.信息格式为：姓名+年龄+性别+电话+地址
//3.增加个人的信息
//4.删除个人的信息
//5.查找个人的信息
//6.修改个人的信息

void Menu()
{
	printf("------------------------------------------\n");
	printf("--------------1.add   2.dele--------------\n");
	printf("--------------3.find  4.modify------------\n");
	printf("--------------5.print 0.exit--------------\n");
	printf("------------------------------------------\n");
}
	
enum Option
{
	EXIT,
	ADD,
	DELE,
	FIND,
	MODIFY,
	PRINT,
};


int main()
{
	int input = 0;

	//创造一个通讯录（就是创造一个数组，里面的每个元素都是一个结构类型）
	struct address_list contact;
	InitialContact(&contact);

	do
	{
		Menu();
		printf("请选择：");
		scanf("%d", &input);
		switch (input)
		{
			case ADD:
				AddData(&contact);
				break;
			case DELE:
				DeleteData(&contact);
				break;
			case FIND:
				GetOneData(&contact);
				break;
			case MODIFY:
				ModifyData(&contact);
				break;
			case PRINT:
				PrintData(&contact);
				break;
			case EXIT:
				printf("已退出程序！\n");
				break;
			default:
				printf("输入错误,请重新选择！\n");
				break;
		}
	} while (input);
	return 0;
}