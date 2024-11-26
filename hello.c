#include<stdio.h>
#include<stdlib.h>
#include<string.h>
 void input(){
   FILE* fp=fopen("scoresystem.txt","a");
     if(fp==NULL){
      printf("无法打开或创建\n");
       EXIT_FAILURE;
     }
       
    char name[10];
    printf("请输入姓名：\n");
    scanf("%9s", name); 
    fprintf(fp, "\n姓名:%s\n", name);
 
    int year;
    printf("请输入出生年：\n");
    scanf("%d", &year);
    fprintf(fp, "出生年：%d\n", year);
 
    char gender;
    printf("请输入性别(M/F): \n");
    scanf(" %c", &gender); 
    fprintf(fp, "性别:%c\n", gender);
 
    char class[5];
    printf("请输入班级：\n");
    scanf("%4s", class);  
    fprintf(fp, "班级:%s\n", class);
 
    char major[99];
    printf("请输入专业:\n");
    scanf("%98s", major); 
    fprintf(fp, "专业:%s\n", major);
 
    char college[99];
    printf("请输入学院: \n");
    scanf("%98s", college);
    fprintf(fp, "学院:%s\n", college);
 
    int math, introduction, c, PE, politics;
    printf("请输入高数成绩:\n");
    scanf("%d", &math);
    fprintf(fp, "高数成绩:%d\n", math);
 
    printf("请输入导论成绩:\n");
    scanf("%d", &introduction);
    fprintf(fp, "导论成绩:%d\n", introduction);
 
    printf("请输入c语言成绩:\n");
    scanf("%d", &c);
    fprintf(fp, "c语言成绩:%d\n", c);
 
    printf("请输入体育成绩\n");
    scanf("%d", &PE);
    fprintf(fp, "体育成绩:%d\n", PE);
 
    printf("请输入政治成绩:\n");
    scanf("%d", &politics);
    fprintf(fp, "政治成绩:%d\n", politics);
 
    fclose(fp);
    

      system("pause");
 }
 void del(){
    printf("成绩删除\n"); 
    printf("请输入需要删除的姓名\n");
      char name[50]; 
    scanf("%49s", name); 
 
    FILE *fdelname = fopen("scoresystem.txt", "r");
    if (fdelname == NULL) {
        perror("Failed to open file");
        return;
    }
 
    FILE *Newflie = fopen("new.txt", "w");
    if (Newflie == NULL) {
        perror("Failed to create new file");
        fclose(fdelname);
        return;
    }
 
    char temp[100]; 
    char name_in_file[50]; 
    while (fgets(temp, sizeof(temp), fdelname) != NULL) {
        if (strncmp(temp, "姓名：", strlen("姓名：")) == 0) {
            
            sscanf(temp, "姓名：%49s", name_in_file);
            name_in_file[strcspn(name_in_file, "\n")] = 0; 
 
            if (strcmp(name_in_file, name) == 0) {
                
                for(int i=0;i<=10;i++){
                fgets(temp,sizeof(temp),fdelname);}      
                
            }
        }
        
        fprintf(Newflie, "%s", temp);
    }
     fclose(fdelname);
     fclose(Newflie);
    
     system("pause");

 }
 void find(){
    printf("成绩查找\n");
     printf("请输入姓名\n");
    FILE *fp=fopen("scoresystem.txt","r");
     char name[40];
     scanf("%39s",name);
       char temp[100];
       char name_in_file[50];
     while((fgets(temp,sizeof(temp),fp))!=NULL){
         if (strncmp(temp, "姓名：", strlen("姓名：")) == 0) {
            
            sscanf(temp, "姓名：%49s", name_in_file);
            name_in_file[strcspn(name_in_file, "\n")] = 0; 
 
            if (strcmp(name_in_file, name) == 0){
              for(int i=0;i<6;i++){ 
              fgets(temp,sizeof(temp),fp);
            }
            printf("你的成绩是：\n");
            for(int j=0;j<5;j++){
              printf("%s",temp);
              fgets(temp,sizeof(temp),fp);
              
            }
            break;
            }

     }
     }
     fclose(fp);
     system("pause");
 
 }

 void sort(){
    printf("成绩排序\n");
    FILE *fp=fopen("scoresystem.txt","r");
    
    if(fp==NULL){
      printf("没有文件\n");
     return;
    }
    FILE *fp2=fopen("process.txt","w");
     char temp[100];
     char score[5][50];
     int num[5];
      while(fgets(temp,sizeof(temp),fp)!=NULL){
        for(int i=0;i<5;i++){
          fputs(temp,fp2);
          fgets(temp,sizeof(temp),fp);
        }
        fputs(temp,fp2);
         
        for(int i=0;i<5;i++){
             fgets(score[i],50,fp);
             sscanf(score[i]," %d",&num[i]);
             
        }
        for(int j=0;j<4;j++){
             for(int z=0;z<4;z++){
                if(num[z]>num[z+1]){
                  int temp;
                   
                }
             }
        }
        

      }
          fclose(fp);
          fclose(fp2);
     system("pause");
 }
 void replace(){
  FILE *fp=fopen("scoresystem.txt","r");
   FILE *fp2=fopen("temp.txt","w");
  if(fp==NULL){
    printf("无法打开\n");
    return;
  }
    printf("成绩修改\n");
     char name[20];
     printf("请输入你的姓名\n");
      scanf("%19s",name);
       char subject[30];
       printf("你想要修改的科目\n");
       scanf("%29s",subject);
        char temp[100];
        char name_in_file[50];
        int line_num=0;
        int line_num_internal;
        int found=0;
        while(fgets(temp,sizeof(temp),fp)!=NULL){
           line_num+=1;
           if(strncmp(temp,"姓名：",strlen("姓名："))==0){
            sscanf(temp,"姓名：%49s", name_in_file);
             name_in_file[strcspn(name_in_file, "\n")] = 0; 
            if(strcmp(name_in_file,name)==0){
              for(int i=0;i<10;i++){
                   
                fgets(temp,sizeof(temp),fp);
                if(strncmp(subject,temp,strlen(subject))==0){
                    line_num_internal=i+1;
                     found=1;
                  break;
                }
              }
              }   
            }
            if(found){
              break;
            }
        }
            rewind(fp);
              int n=line_num+(line_num_internal-1);
              for(int j=0;j<n;j++){
                fgets(temp,sizeof(temp),fp);
                   fprintf(fp2,"%s",temp);
           }
        printf("你想要修改为多少分：\n");
              int newScore;
              scanf("%d",&newScore);
               fprintf(fp2,"%s：%d\n",subject,newScore);
               fgets(temp,sizeof(temp),fp);
               while(fgets(temp,sizeof(temp),fp)!=NULL){
                fprintf(fp2,"%s",temp);
               }
               fclose(fp);
               fclose(fp2);
               _rename("temp.txt", "scoresystem.txt");
     system("pause");
 }
 void menu(){
    system("cls");
    printf("\n\n\n\t\t\t    欢迎使用学生成绩管理系统\n\n\n");
    printf("\t\t\t ******************************\n");
    printf("\t\t\t *            主菜单          *\n");
    printf("\t\t\t ******************************\n\n\n");
    printf("\t\t          1 成绩输入         2 成绩删除\n\n");
    printf("\t\t          3 成绩查询         4 成绩排序\n\n");
    printf("\t\t          5 成绩修改         6 退出系统\n\n");
    printf("\t\t          请选择[1/2/3/4/5/6]: ");

    
 }
 
 
 
 int main(){
        
        int j;
        while(1)
        {menu();
             scanf("%d",&j);
              switch(j){
                case 1: input();break;
                case 2: del();break;
                case 3: find();break;
                case 4: sort();break;
                case 5: replace();break;
                case 6: exit(0);
              }       
                    
                    
                    }
                    return 0;
 }