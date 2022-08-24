#include "listtongxunlu.h"
int id = 1;

void FOZU()
{
    printf("///\n\
//                          _ooOoo_                          //\n\
//                         o8888888o                         //\n\
//                         88\" . \"88                         //\n\
//                         (| ^_^ |)                         //\n\
//                         O\\  =  /O                         //\n\
//                      ____/`---'\\____                      //\n\
//                    .'  \\\\|     |//  `.                    //\n\
//                   /  \\\\|||  :  |||//  \\                   //\n\
//                  /  _||||| -:- |||||-  \\                  //\n\
//                  |   | \\\\\\  -  /// |   |                  //\n\
//                  | \\_|  ''\\---/''  |   |                  //\n\
//                  \\  .-\\__  `-`  ___/-. /                  //\n\
//                ___`. .'  /--.--\\  `. . ___                //\n\
//               ."
           " '<  `.___\\_<|>_/___.'  >'"
           ".                //\n\
//            | | :  `- \\`.;`\\ _ /`;.`/ - ` : | |            //\n\
//            \\  \\ `-.   \\_ __\\ /__ _/   .-` /  /            //\n\
//     ========`-.____`-.___\\_____/___.-`____.-'========     //\n\
//                          `=---='                          //\n\
//     ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^     //\n\
//           佛祖保佑       永不宕机     永无BUG             //\n\
///\n");
    getchar();
}

void SaveToFile(person *head)
{
    FILE *fp;
    fp = fopen("./1.txt", "w");
    if (fp == NULL)
    {
        perror("fopen");
        exit(-1);
    }
    int ret;
    person *tmp = head->next;
    while (tmp != NULL)
    {
        ret = fwrite(tmp, sizeof(person), 1, fp);
        if (ret != 1)
        {
            perror("fwrite");
            exit(-1);
        }
        tmp = tmp->next;
    }
    fclose(fp);
}

void LoadFromFile(person *head)
{
    FILE *fp;
    fp = fopen("./1.txt", "r");
    if (fp == NULL)
    {
        perror("fopen");
        exit(-1);
    }
    person *tmp2 = head;
    int ret;
    // person *tmp = PERSONCREATE();
    // while ((ret = fread(tmp, sizeof(person), 1, fp)) != 0)
    // {
    while (1)
    {
        person *tmp = PERSONCREATE();
        if (ret = fread(tmp, sizeof(person), 1, fp) == 0)
            break;
        while (tmp2->next != NULL && mystrcmp(tmp2->next->name, tmp->name) < 0)
        {
            tmp2 = tmp2->next;
        }
        tmp->next = tmp2->next;
        tmp2->next = tmp;
    }
    if (feof(fp) == 0)
    {
        perror("feof");
        exit(-1);
    }
    else
        printf("通讯录加载成功！\n");
    fclose(fp);
}

//自己封装strcmp
int mystrcmp(char *str1, char *str2)
{
    while (*str1 == *str2 && *str1 != '\0')
    {
        str1++;
        str2++;
    }
    if (*str1 > *str2)
    {
        return 1;
    }
    else if (*str1 < *str2)
    {
        return -1;
    }
    else
    {
        return 0;
    }
}

//菜单
void MENU()
{
    printf("\n**********欢迎使用本通讯录*********\n");
    printf("***********************************\n");
    printf("*****1.添加用户*****2.查看用户*****\n");
    printf("***********************************\n");
    printf("*****3.搜索用户*****4.删除用户*****\n");
    printf("***********************************\n");
    printf("*****5.修改信息*****6.退出系统*****\n");
    printf("***********************************\n");
    printf("************7.召唤佛祖************\n");
    printf("**********请输入指令序号:**********\n");
}

//创建头节点
person *PERSONCREATE()
{
    person *p = (person *)malloc(sizeof(person));
    p->next = NULL;
    return p;
}

//判断是否为空
bool EMPTYJUDGE(person *p)
{
    return p->next == NULL ? 1 : 0;
}

//添加用户
void ADD(person *p)
{
    while (1)
    {
        person *tmp = PERSONCREATE();
        tmp->id = id;
        getchar();
        printf("请输入用户姓名：\n");
        scanf("%s", tmp->name);
        getchar();
        printf("请输入用户性别：\n");
        scanf("%s", tmp->sex);
        getchar();
        printf("请输入用户年龄：\n");
        scanf("%d", &tmp->age);
        getchar();
        printf("请输入用户电话：\n");
        scanf("%s", tmp->tel);
        person *tmp2 = p;
        while (tmp2->next != NULL && mystrcmp(tmp2->next->name, tmp->name) < 0)
        {
            tmp2 = tmp2->next;
        }
        tmp->next = tmp2->next;
        tmp2->next = tmp;
        id++;
        printf("添加成功！\n");
        printf("是否继续添加？\n");
        printf("1.是  2.否\n");
        int choice = 0;
        scanf("%d", &choice);
        if (choice == 2)
        {
            break;
        }
    }
    getchar();
}
//遍历通讯录
void INFOPRINT(person *p)
{
    if (EMPTYJUDGE(p))
    {
        printf("通讯录为空！\n");
        getchar();
        return;
    }
    person *tmp = p->next;
    printf("------------------------------------------\n");
    printf("%-4s\t%-4s\t%-4s\t%-4s\t%-12s\t\n", "id", "姓名", "性别", "年龄", "电话");
    printf("------------------------------------------\n");
    while (tmp != NULL)
    {
        printf("%-4d\t%-4s\t%-4s\t%-4d\t%-12s\t\n",
               tmp->id,
               tmp->name,
               tmp->sex,
               tmp->age,
               tmp->tel);
        printf("------------------------------------------\n");
        tmp = tmp->next;
    }
    getchar();
}

//查找
person *SEARCH(person *p)
{
    person *tmp = p;
    int choice = 0;
    char sname[32];
    int sid;
    printf("请选择查询方式：1.姓名  2.id\n");
    scanf("%d", &choice);
    switch (choice)
    {
    case 1:
        printf("请输入要搜索的姓名：\n");
        getchar();
        scanf("%s", sname);
        while (mystrcmp(tmp->name, sname) && tmp->next != NULL)
        {
            tmp = tmp->next;
            if (tmp->next == NULL && mystrcmp(tmp->name, sname) != 0)
            {
                printf("此用户不存在！\n");
                getchar();
                return tmp;
            }
            // tmp = tmp->next;
        }
        printf("------------------------------------------\n");
        printf("%-4s\t%-4s\t%-4s\t%-4s\t%-12s\t\n", "id", "姓名", "性别", "年龄", "电话");
        printf("------------------------------------------\n");
        printf("%-4d\t%-4s\t%-4s\t%-4d\t%-12s\t\n",
               tmp->id,
               tmp->name,
               tmp->sex,
               tmp->age,
               tmp->tel);
        printf("------------------------------------------\n");
        break;
    case 2:
        printf("请输入要搜索的id：\n");
        scanf("%d", &sid);
        while (tmp->id != sid && tmp->next != NULL)
        {
            tmp = tmp->next;
            if (tmp->next == NULL && tmp->id != sid)
            {
                printf("此用户不存在！\n");
                getchar();
                return tmp;
            }
        }
        printf("------------------------------------------\n");
        printf("%-4s\t%-4s\t%-4s\t%-4s\t%-12s\t\n", "id", "姓名", "性别", "年龄", "电话");
        printf("------------------------------------------\n");
        printf("%-4d\t%-4s\t%-4s\t%-4d\t%-12s\t\n",
               tmp->id,
               tmp->name,
               tmp->sex,
               tmp->age,
               tmp->tel);
        printf("------------------------------------------\n");
        break;
    default:
        printf("输入有误！");
        break;
    }
    getchar();
    return tmp;
}
//删除
person *DELETE(person *p)
{
    person *tmp = p;
    int did = 0;
    printf(" 请输入要删除的id：\n");
    scanf("%d", &did);
    while (tmp->next != NULL && tmp->id != did)
    {
        tmp = tmp->next;
        if (tmp->next == NULL && tmp->id != did)
        {
            printf("找不到此id对应的用户!\n");
            getchar();
            return tmp;
        }
    }
    tmp = p;
    while (tmp->next->id != did)
    {
        tmp = tmp->next;
    }
    tmp->next = tmp->next->next;
    printf("删除成功！\n");
    getchar();
    return tmp->next;
}

//修改
void MODIFY(person *p)
{
    person *tmp = p;
    int mid = 0;
    printf(" 请输入需要修改的用户的id：\n");
    scanf("%d", &mid);
    while (tmp->next != NULL && tmp->id != mid)
    {
        tmp = tmp->next;
        if (tmp->next == NULL && tmp->id != mid)
        {
            printf("找不到此id对应的用户\n");
            getchar();
            return;
        }
    }
    getchar();
    printf("请输入用户姓名：\n");
    scanf("%s", tmp->name);
    getchar();
    printf("请输入用户性别：\n");
    scanf("%s", tmp->sex);
    getchar();
    printf("请输入用户年龄：\n");
    scanf("%d", &tmp->age);
    getchar();
    printf("请输入用户电话：\n");
    scanf("%s", tmp->tel);
    getchar();
}

// 交换节点
void swapnode(person *head, person *node1, person *node2)
{
    person *p1 = head, *p2 = head;
    if (node1->next != node2)
    {
        while (p1 != NULL)
        {
            if (p1->next == node1)
                break;
            p1 = p1->next;
        }
        while (p2 != NULL)
        {
            if (p2->next == node2)
                break;
            p2 = p2->next;
        }
        p1->next = node1->next;
        p2->next = node2->next;
        node2->next = p1->next;
        p1->next = node2;
        node1->next = p2->next;
        p2->next = node1;
    }
    else
    {
        //连续的情况
    }
}

//排序
void SORT(person *p)
{

    // person *m;
    // person *n;
    // person *tail = p;
    // int count = 0;
    // while (p->next != NULL)
    // {
    //     count++;
    //     p = p->next;
    // }
    // p = tail;
    // int i = 0;
    // for ( i = 0; i < count-1; i++)
    // {
    //     int num = count-1-i;
    //     m = p->next;
    //     n = m->next;
    //     tail = p;
    //     while (num--)
    //     {
    //         if (mystrcmp(m->name,n->name)>0)
    //         {
    //             m->next = n->next;
    //             n->next = m;
    //             tail->next = p;
    //         }
    //         tail = tail->next;
    //         m = tail->next;
    //         n = m->next;
    //     }
    // }

    // person *m = p;
    // person *n = m->next;
    // while (n->next != NULL)
    // {
    //     if (mystrcmp(n->name,n->next->name)>0)
    //     {
    //         person *tmp = m->next;
    //         m->next = tmp->next;
    //         // person *tmp2 = n->next->next;
    //         tmp = n->next->next;
    //         m->next->next = n;
    //         n->next = tmp;
    //         // n->next = tmp;
    //     }
    //     m = m->next;
    //     n = n->next;
    // }
    getchar();
}