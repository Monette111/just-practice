#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<assert.h>
#include<windows.h>
#define ROW 10
#define COL 10
#define MINES_NUM 10
#define KNOWN -4
#define UNKNOWN -1
#define KNOWN_MINE -3
#define Have_Mine -2 
 
 typedef struct 
 {
    int height;
    int width;
    int allmines;
    int **board;
 } boardStructure;


void addmines(boardStructure *b){
  
      int x,y;
      int putTimes =b->width * b->height * 10;//避免随机数生成在同一位置放雷的话造成无限循环
       do{
      x=rand() % b->width;//x,y为随机选取的0-width-1（height-1）的数用于选取一个坐标放雷
      y=rand() % b->height;
       assert(putTimes>0);//如果函数随机数生成始终一样会导致生成坐标重复导致无限循环，此时退出程序
       putTimes--;
       }while(b->board[y][x]==Have_Mine);//如果有雷则需要重新放雷
       b->board[y][x]=Have_Mine;//放雷
 }

void  CreateAboard(boardStructure *b){
    
    int w =b->width;
     int h =b->height;
      int numMine = b->allmines; 
      
   
     b -> board=malloc(h * sizeof(int*));//分配每列的内存
   
   for(int j=0;j<h;j++){
    b->board[j]=malloc(w*sizeof(int));//分配每行的内存
   }
  
      
    for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      b->board[i][j] = UNKNOWN;//把每个位置初始化为0即未知
      
    }
  }
for (int i = 0; i < numMine; i++) {
    addmines(b);
  }
}

void  freeBoardpointer(boardStructure * b) {
         
  for (int i = 0; i < b->height; i++) {
    
  
  free(b->board[i]);
  
  }
  free(b->board);
  
}
int countEachPlaceMINE_number(boardStructure *b,int x,int y);



 void printBoard(boardStructure * b){

   int w=b->width;
   int h=b->height;
   
   printf("      ");
   for(int c=0;c<w;c++){
    printf("%d  ",c/w);
   }//打印一行使玩家知道横坐标的十位数
   printf("\n      ");
     for(int z=0;z<w;z++){
    printf("%d  ",z%w);
   }
   printf("\n------");
   
    for(int z=0;z<w;z++){
    printf("---");
   }
    
  printf("-");
   
   printf("\n");
   for(int i=0;i<h;i++){
    printf("%d ",i/h);
    printf("%d|  ",i%h);
      for(int j=0;j<w;j++){
         if(b->board[i][j]==0){
           printf("   ");
         }
         else if(b->board[i][j]==KNOWN){
          
          printf("%d  ",countEachPlaceMINE_number(b,j,i));
         }
         else if(b->board[i][j]==KNOWN_MINE){
          printf("*  ");
         }
        else if(b->board[i][j]<0){
           printf("?  ");
           }

      }
      printf("|\n");
   }
   printf("------");
   for(int i=0;i<w;i++){
    printf("---");
   }
   printf("-");
   printf("\n      ");
   for(int i=0;i<w;i++){
    printf("%d  ",i%w);
   }
   printf("\n      ");
   for(int i=0;i<w;i++){
    printf("%d  ",i/w);
   }
   printf("\n");
   printf(" remember we all have %d bombs!\n",b->allmines);
 } 
 int countEachPlaceMINE_number(boardStructure *b,int x,int y){
   //查找x,y处周围有几颗雷
       int mine_numAround=0;
       if (x < 0 || x >= b->width || y < 0 || y >= b->height) {
        return -1; // 如果坐标超出范围，返回-1
    }
         if(b->board[y][x]!=Have_Mine){
             for (int i = -1; i <= 1; i++) {
               for (int j = -1; j <= 1; j++) {
                     int nh = y + i, nw = x + j;
                     if (nw >= 0 && nw < b->width && nh >= 0 && nh < b->height && !(i==0 && j==0) && (b->board[nh][nw]==Have_Mine||b->board[nh][nw]==KNOWN_MINE)) {
                          mine_numAround++;
                      }
                  }
              }
         }
           return mine_numAround;
          }

int checkIfWin(boardStructure *b){
  int w=b->width;
  int h=b->height;

  for(int i=0;i<h;i++){
    for(int j=0;j<w;j++){
      if(b->board[i][j]==UNKNOWN){
        return 0;
      }
      

    }
  }
  return 1;
}




void win(){
     
     char winShow[10][100]={

    "__        ___        __        ___        __        ___       _ _ _                 ",
    "\\ \\      / (_)_ __   \\ \\      / (_)_ __   \\ \\      / (_)_ __ | | | |          ",
    " \\ \\ /\\ / /| | '_ \\   \\ \\ /\\ / /| | '_ \\   \\ \\ /\\ / /| | '_ \\| | | |    ",
    "  \\ V  V / | | | | |   \\ V  V / | | | | |   \\ V  V / | | | | |_|_|_|             ",
    "  _\\_/\\_/  |_|_| |_|    \\_/\\_/  |_|_| |_|   _\\_/\\_/ _|_|_| |_(_|_|_)          ",
    " / ___|___  _ __   __ _ _ __ __ _| |_ _   _| | __ _| |_(_)_ __  ___| | | | |        ",
    "| |   / _ \\| '_ \\ / _` | '__/ _` | __| | | | |/ _` | __| | '_ \\/ __| | | | |     ",
    "| |__| (_) | | | | (_| | | | (_| | |_| |_| | | (_| | |_| | | | \\__ \\_|_|_|_|      ",
    " \\____\\___/|_| |_|\\__, |_|  \\__,_|\\__|\\__,_|_|\\__,_|\\__|_|_| |_|___(_|_|_|_)",
    "                  |___/                                                             ",
  };
  
  
for(int i=0;i<10;i++){
printf("%s\n",winShow[i]);
 
}
printf("Hey guess what? you got this you do it correctly ! you win it ! congratulations!\n");


}


void timeCountdown(int x) {
    int countdown = x; // 设置倒计时

    while (countdown > 0) {
        printf("\r%d", countdown); // 使用\r使光标回到行首
        fflush(stdout); // 清空输出缓冲区，确保立即输出
        Sleep(1000); // Windows下Sleep函数的参数是毫秒
        countdown--; // 减少倒计时
    }

    

}


void lose(){


      char theBomb[23][50] = {
"               . . .                   ",                         
"                \\|/                   ",                          
"              ---+---                  ",                        
"                /|\\                   ",                          
"               ' | '                   ",                        
"                 |                     ",                          
"                 |                     ",                           
"              --'#`--.                 ",                       
"             |#######|                 ",                       
"          _.-'#######`-._              ",                    
"       ---###############`--           ",                 
"      --#####################-         ",               
"    /#########################\\       ",              
"   |############################|      ",             
"  |##############################|     ",            
"  |##############################|     ",           
"  |##############################|     ",           
"  |##############################|     ",           
"   |############################|      ",             
"    \\#########################_/      ",              
"     `.#####################__/        ",               
"       `._###############___/          ",                 
"          `--..#####..--_ -`           ",    
    
    
    };


    char afterbomb[12][50]={

"             _.-^^---....,,--         ", 
"         _--                  --_     ",
"        <          B0MB!!!       >)   ",   
"        |                         |   ",     
"         \\._                   _./   ",
"             ```--. . , ; .--'''      ",
"                   | |   |            ",
"                .-=||  | |=-.         ",
"                `-=#$#&#$#=-'         ",
"                   | ;  :|            ",
"          _____.,-#*&$@*#&#~,._____   ",
"                   BANG!!!!           ",

    };


    // 打印图案
    for (int i = 0; i < 23; i++) {
        printf("%s\n", theBomb[i]);
    }
    
   printf("\nsorry,you accidently touch the bomb,it's booming !!!!!\n");
   
   timeCountdown(3);
   
  
   for(int i=0;i<12;i++){
        printf("%s\n",afterbomb[i]);
   }
  
  printf("you lose!!!\n");


}
 void openTheBox(boardStructure *b,int x,int y){
      
      if(b->board[y][x]==UNKNOWN){
 
         if(countEachPlaceMINE_number(b,x,y)==0){
             b->board[y][x]=0;
          for (int i = -1; i <= 1; i++) {
               for (int j = -1; j <= 1; j++) {
                     int nh = y + i, nw = x + j;
                              
                     if (nw >= 0 && nw < b->width && nh >= 0 && nh < b->height && !(i==0 && j==0) ) {
                               
                              openTheBox(b,nw,nh);
                      }  
                  }
              }
      }
      else{
        b->board[y][x]=KNOWN;
      } 
      } 
       
 }
int enterCoordinate(boardStructure *b,int x,int y){
  
  if(x>=0 && y<b->width && y>=0 && y<b->height){

  if(b->board[y][x]==KNOWN){
    return 0;
  }
  else if(b->board[y][x]==UNKNOWN){
    return 1;
  }
  else if(b->board[y][x]==Have_Mine){
   
    return -1;
  }
  }
 return -2;

}
    
int main(){

  char answer;
  
do{
  
  boardStructure * a= malloc(sizeof(boardStructure));
   srand(time(NULL));//设置当前时间为种子
   a->width  = ROW;
   a->height =COL;
   a->allmines = MINES_NUM;

    CreateAboard(a);
    printBoard(a);
    int px,py;
    int running=1;
    while(running){
        
         printf("enter x coordinate: \n");
         scanf("%d",&px);
         printf("enter y coordinate: \n");
         scanf("%d",&py);

   int result=enterCoordinate(a,px,py);
    switch(result){
        case 0:
        printf("please enter again\n");
        continue;
        case -1:
        lose();
        printf("\n the moment is here! boooooooooooom!!!!!\n");
       timeCountdown(2);
       printf("\n");

        for(int i=0;i<a->height;i++){
          for(int j=0;j<a->width;j++){
            if(a->board[i][j]==Have_Mine){
              a->board[i][j]=KNOWN_MINE;
            }
          }
        }
        running=0;
        break;
        case 1:
        openTheBox(a,px,py);
        printBoard(a);
        if(checkIfWin(a)){
          win();
          timeCountdown(2);
          printf("\n");
          for(int i=0;i<a->height;i++){
          for(int j=0;j<a->width;j++){
            if(a->board[i][j]==Have_Mine){
              a->board[i][j]=KNOWN_MINE;
            }
          }
        }
          running=0;
          break;
        }
        else{
          continue;
        }
        case -2:
        printf("wrong coordinate\n");
        break;
    }

    }
  
    printBoard(a);
    freeBoardpointer(a);
    free(a);
    
    printf("Do you want to play again? (y/n)\n");
        scanf(" %c", &answer); 
    } while (answer == 'y' || answer == 'Y');
    return 0;
}



