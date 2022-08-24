#ifndef _LISTTONGXUNLU_H_
#define _LISTTONGXUNLU_H_
#include <stdio.h>
#include <stdlib.h>
//#include <string.h>
#include <stdbool.h>
#include <unistd.h>
typedef struct person
{
  int id;
  int age;
  char name[20];
  char sex[10];
  char tel[12];
  struct person *next;
}person;
//召唤佛祖
void FOZU();
//自己封装strcmp
int  mystrcmp(char *str1, char *str2);
//菜单
void MENU();
//创建头节点
person * PERSONCREATE();
//判断是否为空
bool EMPTYJUDGE(person *p);
//添加用户
void ADD(person *p);
//遍历通讯录
void INFOPRINT(person *p);
//查找
person *SEARCH(person *p);
//删除
person *DELETE(person *p);
//修改
void MODIFY(person *p);
//排序
void SORT(person *p);
// 交换节点
void swapnode(person *head, person *node1, person *node2);
void SaveToFile(person *head);
void LoadFromFile(person *head);
#endif