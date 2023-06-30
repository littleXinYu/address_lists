#define _CRT_SECURE_NO_WARNINGS

#include "contact.h"

//��ʼ��ͨѶ¼
void InitialContact(struct address_list* pc)
{
	pc->sz = 0;
	memset(pc->data, 0, sizeof(pc->data));
}

void AddData(struct address_list* pc)
{
	if (pc->sz == MAX)
	{
		printf("ͨѶ¼�������޷����\n");
		return;
	}
	printf("���������֣�");
	scanf("%s", pc->data[pc->sz].name);
	printf("�������Ա�");
	scanf("%s", pc->data[pc->sz].sex);
	printf("���������䣺");
	scanf("%d", &pc->data[pc->sz].age);
	printf("������绰���룺");
	scanf("%s", pc->data[pc->sz].tele);
	printf("�������ַ��");
	scanf("%s", pc->data[pc->sz].addr);

	pc->sz++;
	printf("��Ϣ¼��ɹ���\n");
}


void PrintData(const struct address_list* pc)
{
	int i = 0;

	if (pc->sz == 0)
	{
		printf("ͨѶ¼�������ݣ��޷���ӡ\n");
		return;
	}


	//��ӡ����
	printf("\n%-5s\t%-5s\t%-5s\t%-15s\t%-20s\n", "����", "�Ա�", "����", "�绰", "��ַ");

	//��ӡ����
	for (i =0; i < pc->sz; i++)
	{
		printf("%-5s\t%-5s\t%-5d\t%-15s\t%-20s\n",
				pc->data[i].name,
				pc->data[i].sex,
				pc->data[i].age,
				pc->data[i].tele,
				pc->data[i].addr);
	}
	printf("\n�Ѵ�ӡ��ϣ�\n\n");
}

int FindData(struct address_list* pc)
{
	int i = 0;
	char name_1[MAX_NAME] = { 0 };
	printf("������������");
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
		printf("ͨѶ¼�������ݣ��޷�ɾ��\n");
		return;
	}

	int ret = FindData(pc);
	if (ret == -1)
	{
		printf("������������ͨѶ¼�У��޷�����ɾ����\n");
		return;
	}

	for (i = ret; i < pc->sz-1; i++)
	{
		pc->data[i] = pc->data[i + 1];
	}

	pc->sz--;
	printf("ɾ�����ݳɹ���\n");
}

void GetOneData(struct address_list* pc)
{
	int i = 0;
	int count = 0;
	char name_1[MAX_NAME] = { 0 };
	printf("������������");
	scanf("%s", &name_1);

	for (i = 0; i < pc->sz; i++)
	{
		if (strcmp(name_1, pc->data[i].name) == 0)
		{
			//��ӡ��ͷ
			if (count == 0)
			{
				printf("\n%-5s\t%-5s\t%-5s\t%-15s\t%-20s\n", "����", "�Ա�", "����", "�绰", "��ַ");
				count++;
			}

			//��ӡ����
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
		printf("������������ͨѶ¼�У�\n");
	}
}

void ModifyData(struct address_list* pc)
{
	int i = 0;
	if (pc->sz == 0)
	{
		printf("ͨѶ¼�������ݣ��޷��޸�\n");
		return;
	}

	int ret = FindData(pc);
	if (ret == -1)
	{
		printf("������������ͨѶ¼�У��޷������޸ģ�\n");
		return;
	}
	printf("���������֣�");
	scanf("%s", pc->data[ret].name);
	printf("�������Ա�");
	scanf("%s", pc->data[ret].sex);
	printf("���������䣺");
	scanf("%d", &pc->data[ret].age);
	printf("������绰���룺");
	scanf("%s", pc->data[ret].tele);
	printf("�������ַ��");
	scanf("%s", pc->data[ret].addr);

	printf("�޸ĳɹ���\n");
}