#define _STUDENT
#define _REFEREE

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>

extern int amount;//声明全局变量amount 
struct  Student//student 结构体 
{
	int id;
	char name;
    char sex;
    char program;
    char type;
    char number;
    char cclass;
    double score[10];
    double sum;
    double average;
    double max;
    double min;
};
struct  Student s[50];//结构体数组 

struct Referee
{
    char name;
    char sex;
    char tel;
};
struct  Referee r[50];//结构体数组 




//添加模块
void inputBystudent()
{
	int i;
	i=amount;
	printf("请输入编号:\n");
	scanf("%d",&s[i].id);
	printf("请输入姓名:\n");
	scanf("%s",&s[i].name);
    printf("请输入性别:\n");
    scanf("%s",&s[i].sex);
	printf("请输入节目名称:\n");
	scanf("%s",&s[i].program);
	printf("请输入节目类型:\n");
	scanf("%s",&s[i].type);
	printf("请输入电话号码:\n");
	scanf("%s",&s[i].number);
	printf("请输入班级:\n");
	scanf("%s",&s[i].cclass);
	amount=amount+1;
}
void inputByreferee()
{
	int i;
	i=amount;
	printf("请输入姓名:\n");
	scanf("%s",&r[i].name);
    printf("请输入性别:\n");
    scanf("%s",&r[i].sex);
	printf("请输入电话号码:\n");
	scanf("%d",&r[i].tel);
	amount=amount+1;
}
void input()
{
    char menuItem;
    printf("	| --------------------------------------------|\n");
    printf("	|                  查询子菜单项               |\n");
    printf("	| --------------------------------------------|\n");
    printf("	|                    1---添加学生             |\n");
    printf("	|                    2---添加裁判             |\n");
    printf("	| --------------------------------------------|\n");
	do
	{
		printf("\n请输入菜单项数字(0-2):");
		fflush(stdin);
		scanf("%c",&menuItem);
	}while(menuItem<'1'||menuItem>'2');
	switch(menuItem)
	{
	    case  '1':
		         inputBystudent();
		         break;
	    case  '2':
		         inputByreferee();
		         break;	
			     
	}
}

//显示模块
void outputBystudent()
{
	printf("|  编号  |  姓名  |  性别  |  节目名称  |  节目类型  |  电话号码  |  班级  |\n");
	int i;
	for(i=0;i<amount;i++)
	{	
	    printf("|%8d",s[i].id);
	    printf("|%8s",s[i].name);		
		printf("|%8s",s[i].sex);	
		printf("|%12s",s[i].program);
		printf("|%12s",s[i].type);
		printf("|%12s",s[i].number);
		printf("|%8s|\n",s[i].cclass);
	}
}
void outputByreferee()
{
	printf("|  姓名  |  性别  |  电话号码  |\n");
	int i;
	for(i=0;i<amount;i++)
	{	
	    printf("|%8s",r[i].name);		
		printf("|%8s",r[i].sex);	
		printf("|%12s",r[i].tel);
}
void output()
{
    char menuitem;
    printf("	| --------------------------------------------|\n");
    printf("	|                  查询子菜单项               |\n");
    printf("	| --------------------------------------------|\n");
    printf("	|                    1---显示学生             |\n");
    printf("	|                    2---显示裁判             |\n");
    printf("	| --------------------------------------------|\n");
	do
	{
		printf("\n请输入菜单项数字(0-2):");
		fflush(stdin);
		scanf("%c",&menuItem);
	}while(menuitem<'1'||menuitem>'2');
	switch(menuitem)
	{
	    case  '1':
		         outputBystudent();
		         break;
	    case  '2':
		         outputByreferee();
		         break;	
			     
	}
}

int mark()
{
    int i,n;
    int flag=1;
    while (flag)
    {
        printf("请输入要评分的参赛者编号:\n");
        scanf("%d",&n);
        for (i=0; i<amount;)
        {
            if (s[i].id!=n)
            {
                i++;
            }
            else
            {
                break;
            }
        }
        if(i>=amount||n<=0)
        {
            printf("输入编码错误，请重新输入!\n");
            
        }
        else
        {
            printf("请输入第一个裁判打的分数:\n");
	        scanf("%l",&s[n-1].score[0]);
            printf("请输入第二个裁判打的分数:\n");
	        scanf("%l",&s[n-1].score[1]);
	        printf("请输入第三个裁判打的分数:\n");
	        scanf("%l",&s[n-1].score[2]);
	        printf("请输入第四个裁判打的分数:\n");
	        scanf("%l",&s[n-1].score[3]);
	        printf("请输入第五个裁判打的分数:\n");
	        scanf("%l",&s[n-1].score[4]);
            flag=0;
        }
    }
    printf("裁判评分成功!\n");
    return 0;
}
int average()
{
    int i,j;
    s[i].sum=0;
    s[i].average=0;
    for(i=0;i<amount;i++)
    {
        s[i].max=s[i].score[0];
        s[i].min=s[i].score[0];
        for(j=0;j<5;j++)
        {
            if(s[i].score[j]>s[i].max)
            {
                s[i].max=s[i].score[j];
            }
            if(s[i].score[j]<s[i].min)
            {
                s[i].min=s[i].score[j];
            }
            s[i].sum+=s[i].score[j];
        }
        s[i].sum=s[i].sum - s[i].max - s[i].min;
        s[i].average = s[i].sum / 3;
    }
    printf("计算平均分成功!\n");
    return 0;
}

int show()
{
    int i;
    for(i=0;i<amount;i++)
    {
    	printf("参赛者姓名为:",s[i].name);
    	printf("编号:",s[i].id);
    	printf("性别:",s[i].sex);
    	printf("节目名称:",s[i].program);
    	printf("节目类别:",s[i].type);
    	printf("电话:",s[i].number);
    	printf("班级:",s[i].cclass);
    	printf("第一个评委",r[0].name);
    	printf("分数是:",s[i].score[0]);
    	printf("第二个评委",r[1].name);
    	printf("分数是:",s[i].score[1]);
    	printf("第三个评委",r[2].name);
    	printf("分数是:",s[i].score[2]);
    	printf("第四个评委",r[3].name);
    	printf("分数是:",s[i].score[3]);
    	printf("第五个评委",r[4].name);
    	printf("分数是:",s[i].score[4]);
    	printf("去掉一个最低分为:",s[i].min);
    	printf("去掉一个最高分为:",s[i].max);
    	printf("所得的平均成绩是:",s[i].average);
    return 0;
}

//菜单模块 
int menu_select()
{
	int MenuItem;

	printf("\n ");
	printf("          | *********打分系统********* |          \n");
	printf("          | ---------------------------------- |          \n");
	printf("          |              主菜单项              |          \n");
	printf("          | ---------------------------------- |          \n");
	printf("          |	  1 --- 添加信息  	       |          \n");
	printf("          |	  2 --- 显示信息	       |          \n");
	printf("          |	  3 --- 裁判打分	       |          \n");
	printf("          |	  4 --- 计算分值	       |          \n");
	printf("          |	  5 --- 显示分值	       |          \n");
	printf("          |	  0 --- 退出系统  	       |          \n");		
	
do
	{		
		printf("\n请输入选项（0－5）：");
		fflush(stdin);  //清空输入缓冲区       
		scanf("%d",&MenuItem);
	}while(MenuItem<0||MenuItem>5);
	return MenuItem;
}
int main()
{ 
	struct Student s[50];
    struct Referee r[50];
	while(1)//循环一直为真且执行 
	{
		switch(menu_select())//选择菜单 
		{
			case 1:
				input(s,r);//添加				
				break;
			case 2:
				output(s,r);//输出 
				break;
			case 3:
				mark(s);//打分
				break;
			case 4:
				compute(s);//计算 
				break;
			case 5:
				display(s,r);//显示
			    break;
			case 0:
				printf("Thank you for using！\n");
				system("pause");
				return 0;
	    }
    }
}



