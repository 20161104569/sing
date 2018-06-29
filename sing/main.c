//
//  main.c
//  sing
//
//  Created by 20161104569 on 18/6/29.
//  Copyright © 2018年 20161104569. All rights reserved.
//

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#define M 10
#define N 5
struct singer
{
    char name[30];
    int rank,score[5];
    float avg;
} s[M];
int flag=0;
int append()
{
    int i,j;
    for(i=0; i<M; i++)
    {
        printf("请输入第 %d 个歌手的姓名：",i+1);
        scanf("%s",s[i].name);
        printf("\n");
    }
    for(i=0; i<M; i++)
    {
        printf("请输入裁判给第 %d 个歌手 %s 打的 5 个演唱分数:\n",i+1,s[i].name);
        for(j=0; j<N; j++)
            scanf("%d",&s[i].score[j]);
    }
    printf("\n");
    return 0;
}
int load()
{
    FILE *fp;
    int i,j=0;
    fp=fopen("Users/a201611104569/Desktop/score.txt","r");
    for(i=0; i<M; i++)
        fscanf(fp,"%s%d%d%d%d%d",s[i].name,&s[i].score[j],&s[i].score[j+1],&s[i].score[j+2],&s[i].score[j+3],&s[i].score[j+4]);
    printf("%d 位歌手的信息读入完毕，随意按一键......\n",M);
    getchar(); getchar();
    fclose(fp);
    return 0;
}
void list()
{
    int i,j;
    if(flag==0)
    {
        printf("歌手信息为空，请利用键盘输入或文件读入！\n");
        printf("按任意键返回\n");
        getchar(); getchar();
        
    }
    for(i=0; i<M; i++)
    {
        printf("第 %d 个歌手的姓名是：%s\n",i+1,s[i].name);
        for(j=0; j<N; j++)
            printf("裁判 %d：%d 分 ",j+1,s[i].score[j]);
        printf("\n");
    }
    printf("按任意键返回！！！");
    
}
void sort()
{
    int i,j,k,t;
    float t1;
    char xm[30];
    if(flag==0)
    {
        printf("\n歌手信息为空，请利用键盘输入或文件读入！\n\n");
        printf("按任意键返回......");
        getchar(); getchar();
    }
    for(i=0; i<M; i++)
        for(j=0; j<N-1; j++)
            for(k=j+1; k<N; k++)
                if(s[i].score[j]<s[i].score[k])
                {
                    t=s[i].score[j]; s[i].score[j]=s[i].score[k]; s[i].score[k]=t;
                }
    for(i=0; i<M; i++)
    {
        s[i].avg=0;
        for(j=1; j<N-1; j++)
            s[i].avg+=s[i].score[j];
        s[i].avg=s[i].avg/(N-2);
    }
    for(i=0; i<M-1; i++)
        for(j=i+1; j<M; j++)
            if(s[i].avg<s[j].avg)
            {
                strcpy(xm,s[i].name); strcpy(s[i].name,s[j].name); strcpy(s[j].name,xm);
                t1=s[i].avg; s[i].avg=s[j].avg; s[j].avg=t1;
                t=s[i].score[0]; s[i].score[0]=s[j].score[0]; s[j].score[0]=t;
                t=s[i].score[1]; s[i].score[1]=s[j].score[1]; s[j].score[1]=t;
                t=s[i].score[2]; s[i].score[2]=s[j].score[2]; s[j].score[2]=t;
                t=s[i].score[3]; s[i].score[3]=s[j].score[3]; s[j].score[3]=t;
                t=s[i].score[4]; s[i].score[4]=s[j].score[4]; s[j].score[4]=t;
            }
    for(i=0; i<M; i++)
        s[i].rank=i+1;
    for(i=1; i<M; i++)
    {
        if(fabs(s[i].avg-s[i-1].avg)<1e-5)
            s[i].rank=s[i-1].rank;
    }
    printf("\n歌手分数计算结果及最终名次如下：\n\n");
    for(i=0; i<M; i++)
        printf("获得第 %d 名的歌手姓名是：%s，最后得分：%.2f\n\n",s[i].rank,s[i].name,s[i].avg);
    printf("按任意键返回 ......");
    getchar(); getchar();
}
void save1()
{
    FILE *fp;
    int i,j;
    
    
    if(flag==0)
    {
        printf("\n歌手信息为空，请利用键盘输入或文件读入！\n\n");
        printf("按任意键返回......");
        getchar(); getchar();
        
    }
    fp=fopen("Users/a201611104569/Desktop/caipan.txt","w");
    for(i=0; i<M; i++)
    {
        fprintf(fp,"第 %d 个歌手的姓名是：%s\n",i+1,s[i].name);
        for(j=0; j<N; j++)
            fprintf(fp,"裁判 %d：%d 分 ",j+1,s[i].score[j]);
        fprintf(fp,"\n\n");
    }
    printf("\n%d 位歌手的信息保存完毕，随意按一键......\n",M);
    getchar(); getchar();
    fclose(fp);
}
void save2()
{
    FILE *fp;
    int i;
    if(flag==0)
    {
        printf("\n歌手信息为空，请利用键盘输入或文件读入！\n\n");
        printf("按任意键返回......");
        getchar(); getchar();
        
    }
    fp=fopen("Users/a201611104569/Desktop/dafen.txt","w");
    fprintf(fp,"歌手分数计算结果及最终名次如下：\n\n");
    for(i=0; i<M; i++)
        fprintf(fp,"获得第 %d 名的歌手姓名是：%s，最后得分：%.2f\n\n",s[i].rank,s[i].name,s[i].avg);
    printf("\n%d 位歌手的信息保存完毕，随意按一键......\n",M);
    getchar(); getchar();
    fclose(fp);
}
void main()
{
    int choice;
    while(1)
    {
        do
        {
            system("cls");
            printf("1、键盘输入歌手的姓名及裁判打分信息\n\n");
            printf("2、文件载入歌手的姓名及裁判打分信息\n\n");
            printf("3、显示歌手的姓名及裁判打分信息\n\n");
            printf("4、计算歌手的最终得分并排序\n\n");
            printf("5、保存歌手的姓名及裁判打分信息\n\n");
            printf("6、保存歌手的得分结果及最终名次\n\n");
            printf("7、退出\n\n");
            printf("请您选择：");
            scanf("%d",&choice);
        } while(choice<1 || choice>7);
        printf("\n");
        switch(choice)
        {
            case 1: system("cls");
                flag=append();
                break;
            case 2: system("cls");
                flag=load();
                break;
            case 3: system("cls");
                list();
                break;
            case 4: system("cls");
                sort();
                break;
            case 5: system("cls");
                save1();
                break;
            case 6: system("cls");
                save2();
                break;
            case 7: system("cls");
                printf("\n再见！欢迎下次继续使用！\n\n");
                
        }
    }
}



