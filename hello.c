#include<stdio.h>
#include<stdlib.h>
#include<string.h>
 void input(){
   FILE* fp=fopen("scoresystem.txt","a");
     if(fp==NULL){
      printf("�޷��򿪻򴴽�\n");
       EXIT_FAILURE;
     }
       
    char name[10];
    printf("������������\n");
    scanf("%9s", name); 
    fprintf(fp, "\n����:%s\n", name);
 
    int year;
    printf("����������꣺\n");
    scanf("%d", &year);
    fprintf(fp, "�����꣺%d\n", year);
 
    char gender;
    printf("�������Ա�(M/F): \n");
    scanf(" %c", &gender); 
    fprintf(fp, "�Ա�:%c\n", gender);
 
    char class[5];
    printf("������༶��\n");
    scanf("%4s", class);  
    fprintf(fp, "�༶:%s\n", class);
 
    char major[99];
    printf("������רҵ:\n");
    scanf("%98s", major); 
    fprintf(fp, "רҵ:%s\n", major);
 
    char college[99];
    printf("������ѧԺ: \n");
    scanf("%98s", college);
    fprintf(fp, "ѧԺ:%s\n", college);
 
    int math, introduction, c, PE, politics;
    printf("����������ɼ�:\n");
    scanf("%d", &math);
    fprintf(fp, "�����ɼ�:%d\n", math);
 
    printf("�����뵼�۳ɼ�:\n");
    scanf("%d", &introduction);
    fprintf(fp, "���۳ɼ�:%d\n", introduction);
 
    printf("������c���Գɼ�:\n");
    scanf("%d", &c);
    fprintf(fp, "c���Գɼ�:%d\n", c);
 
    printf("�����������ɼ�\n");
    scanf("%d", &PE);
    fprintf(fp, "�����ɼ�:%d\n", PE);
 
    printf("���������γɼ�:\n");
    scanf("%d", &politics);
    fprintf(fp, "���γɼ�:%d\n", politics);
 
    fclose(fp);
    

      system("pause");
 }
 void del(){
    printf("�ɼ�ɾ��\n"); 
    printf("��������Ҫɾ��������\n");
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
        if (strncmp(temp, "������", strlen("������")) == 0) {
            
            sscanf(temp, "������%49s", name_in_file);
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
    printf("�ɼ�����\n");
     printf("����������\n");
    FILE *fp=fopen("scoresystem.txt","r");
     char name[40];
     scanf("%39s",name);
       char temp[100];
       char name_in_file[50];
     while((fgets(temp,sizeof(temp),fp))!=NULL){
         if (strncmp(temp, "������", strlen("������")) == 0) {
            
            sscanf(temp, "������%49s", name_in_file);
            name_in_file[strcspn(name_in_file, "\n")] = 0; 
 
            if (strcmp(name_in_file, name) == 0){
              for(int i=0;i<6;i++){ 
              fgets(temp,sizeof(temp),fp);
            }
            printf("��ĳɼ��ǣ�\n");
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
    printf("�ɼ�����\n");
    FILE *fp=fopen("scoresystem.txt","r");
    
    if(fp==NULL){
      printf("û���ļ�\n");
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
    printf("�޷���\n");
    return;
  }
    printf("�ɼ��޸�\n");
     char name[20];
     printf("�������������\n");
      scanf("%19s",name);
       char subject[30];
       printf("����Ҫ�޸ĵĿ�Ŀ\n");
       scanf("%29s",subject);
        char temp[100];
        char name_in_file[50];
        int line_num=0;
        int line_num_internal;
        int found=0;
        while(fgets(temp,sizeof(temp),fp)!=NULL){
           line_num+=1;
           if(strncmp(temp,"������",strlen("������"))==0){
            sscanf(temp,"������%49s", name_in_file);
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
        printf("����Ҫ�޸�Ϊ���ٷ֣�\n");
              int newScore;
              scanf("%d",&newScore);
               fprintf(fp2,"%s��%d\n",subject,newScore);
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
    printf("\n\n\n\t\t\t    ��ӭʹ��ѧ���ɼ�����ϵͳ\n\n\n");
    printf("\t\t\t ******************************\n");
    printf("\t\t\t *            ���˵�          *\n");
    printf("\t\t\t ******************************\n\n\n");
    printf("\t\t          1 �ɼ�����         2 �ɼ�ɾ��\n\n");
    printf("\t\t          3 �ɼ���ѯ         4 �ɼ�����\n\n");
    printf("\t\t          5 �ɼ��޸�         6 �˳�ϵͳ\n\n");
    printf("\t\t          ��ѡ��[1/2/3/4/5/6]: ");

    
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