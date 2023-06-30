#define _CRT_SECURE_NO_WARNINGS

#include "contact.h"

//初始化通讯录
void InitialContact(struct address_list* pc)
{
	pc->sz = 0;
	memset(pc->data, 0, sizeof(pc->data));
}

void AddData(struct address_list* pc)
{
	if (pc->sz == MAX)
	{
		printf("通讯录已满，无法添加\n");
		return;
	}
	printf("请输入名字：");
	scanf("%s", pc->data[pc->sz].name);
	printf("请输入性别：");
	scanf("%s", pc->data[pc->sz].sex);
	printf("请输入年龄：");
	scanf("%d", &pc->data[pc->sz].age);
	printf("请输入电话号码：");
	scanf("%s", pc->data[pc->sz].tele);
	printf("请输入地址：");
	scanf("%s", pc->data[pc->sz].addr);

	pc->sz++;
	printf("信息录入成功！\n");
}


void PrintData(const struct address_list* pc)
{
	int i = 0;

	if (pc->sz == 0)
	{
		printf("通讯录暂无数据，无法打印\n");
		return;
	}


	//打印标题
	printf("\n%-5s\t%-5s\t%-5s\t%-15s\t%-20s\n", "名字", "性别", "年龄", "电话", "地址");

	//打印数据
	for (i =0; i < pc->sz; i++)
	{
		printf("%-5s\t%-5s\t%-5d\t%-15s\t%-20s\n",
				pc->data[i].name,
				pc->data[i].sex,
				pc->data[i].age,
				pc->data[i].tele,
				pc->data[i].addr);
	}
	printf("\n已打印完毕！\n\n");
}

int FindData(struct address_list* pc)
{
	int i = 0;
	char name_1[MAX_NAME] = { 0 };
	printf("请输入人名：");
	scanf("%s", &name_1);

	for (i = 0; i < pc->sz; i++)
	{
		if (strcmp(name_1, pc->data[i].name) == 0)
		{
			return i;
		}
	}

	return -1;
}


void DeleteData(struct address_list* pc)
{
	int i = 0;
	if (pc->sz == 0)
	{
		printf("通讯录暂无数据，无法删除\n");
		return;
	}

	int ret = FindData(pc);
	if (ret == -1)
	{
		printf("该人名不存在通讯录中，无法进行删除！\n");
		return;
	}

	for (i = ret; i < pc->sz-1; i++)
	{
		pc->data[i] = pc->data[i + 1];
	}

	pc->sz--;
	printf("删除数据成功！\n");
}

void GetOneData(struct address_list* pc)
{
	int i = 0;
	int count = 0;
	char name_1[MAX_NAME] = { 0 };
	printf("请输入人名：");
	scanf("%s", &name_1);

	for (i = 0; i < pc->sz; i++)
	{
		if (strcmp(name_1, pc->data[i].name) == 0)
		{
			//打印开头
			if (count == 0)
			{
				printf("\n%-5s\t%-5s\t%-5s\t%-15s\t%-20s\n", "名字", "性别", "年龄", "电话", "地址");
				count++;
			}

			//打印数据
			printf("%-5s\t%-5s\t%-5d\t%-15s\t%-20s\n",
					pc->data[i].name,
					pc->data[i].sex,
					pc->data[i].age,
					pc->data[i].tele,
					pc->data[i].addr);
		}
	}
	if (count == 0)
	{
		printf("该人名不存在通讯录中！\n");
	}
}

void ModifyData(struct address_list* pc)
{
	int i = 0;
	if (pc->sz == 0)
	{
		printf("通讯录暂无数据，无法修改\n");
		return;
	}

	int ret = FindData(pc);
	if (ret == -1)
	{
		printf("该人名不存在通讯录中，无法进行修改！\n");
		return;
	}
	printf("请输入名字：");
	scanf("%s", pc->data[ret].name);
	printf("请输入性别：");
	scanf("%s", pc->data[ret].sex);
	printf("请输入年龄：");
	scanf("%d", &pc->data[ret].age);
	printf("请输入电话号码：");
	scanf("%s", pc->data[ret].tele);
	printf("请输入地址：");
	scanf("%s", pc->data[ret].addr);

	printf("修改成功！\n");
}