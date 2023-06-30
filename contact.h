#pragma once
#define _CRT_SECURE_NO_WARNINGS_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME 20
#define MAX_SEX 20
#define MAX_TELE 20
#define MAX_ADDR 20
#define MAX 1000


//通讯录需要存放的是结构类型
struct data_peo
{
	char name[MAX_NAME];
	char sex[MAX_SEX];
	int  age;
	char tele[MAX_TELE];
	char addr[MAX_ADDR];
}data_peo;


struct address_list
{
	struct data_peo data[MAX];
	int sz ;
}address_list;


void InitialContact(struct address_list * pc);

void AddData(struct address_list* pc);

void PrintData(const struct address_list* pc);

void DeleteData(struct address_list* pc);

void GetOneData(struct address_list* pc);