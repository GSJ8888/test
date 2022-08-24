#include "listtongxunlu.h"
int main()
{
    person *p = PERSONCREATE();
    LoadFromFile(p);
    char choice = 0;
    do
    {
        MENU();
        scanf("%c",&choice);
        switch (choice)
        {
        case '1':
            ADD(p);
            break;
        case '2':
            //swapnode(p,p->next, p->next->next->next);
            INFOPRINT(p);
            break;
        case '3':
            SEARCH(p);
            break;
        case '4':
            DELETE(p);
            break;
        case '5':
            MODIFY(p);
            break;
        case '6':
            printf("已退出系统！\n");
            SaveToFile(p);
            exit(0);
            break;
        case '7':
            FOZU();
            break;
        default:
            printf("choice输入有误，请重新输入：\n");
            break;
        }
    }while(choice);
}