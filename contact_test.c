#define _CRT_SECURE_NO_WARNINGS

#include "contact.h"

//����ͨѶ¼
//Ҫ��
//1.���1000����Ϣ
//2.��Ϣ��ʽΪ������+����+�Ա�+�绰+��ַ
//3.���Ӹ��˵���Ϣ
//4.ɾ�����˵���Ϣ
//5.���Ҹ��˵���Ϣ
//6.�޸ĸ��˵���Ϣ

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

	//����һ��ͨѶ¼�����Ǵ���һ�����飬�����ÿ��Ԫ�ض���һ���ṹ���ͣ�
	struct address_list contact;
	InitialContact(&contact);

	do
	{
		Menu();
		printf("��ѡ��");
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
				printf("���˳�����\n");
				break;
			default:
				printf("�������,������ѡ��\n");
				break;
		}
	} while (input);
	return 0;
}