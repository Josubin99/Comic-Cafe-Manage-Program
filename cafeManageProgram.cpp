#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <time.h>
#include <sys/stat.h>
#include <fcntl.h>
#define MAX 5000
time_t t;
struct tm *lt;
struct timeval s1,s2,s3,s4,s5,s6,e1,e2,e3,e4,e5,e6;
static int sum1=0,sum2=0,sum3=0,sum4=0,sum5=0,sum6=0;
static int user1=0,user2=0,user3=0,user4=0,user5=0,user6=0;
int menu[6]={2000,2500,2000,2000,1500,5000};
char buf[MAX];
int menu_num;
int menu_sum1=0, menu_sum2=0, menu_sum3=0, menu_sum4=0, menu_sum5=0, menu_sum6=0;

int st=0,total=0;
pid_t pid1,pid2,pid3,pid4,pid5,pid6;
void sig_cld();
main()
{
   int input,select;            // ROOM 선택, 시작&종료 선택
   int check1=0,check2=0,check3=0,check4=0,check5=0,check6=0;   // 사용여부 체크 
   int fd;
   int num;
   signal(SIGCLD,sig_cld);      // child프로세스 종료시 sig_cld() 실행
   while(1){
      printf("\n[ user1, user2, user3, user4, user5, user6 ]Select : ");
      scanf("%d",&input);
      while(input<1 || input>6){
         printf("다시 입력해 주세요");
         printf("\n[user1, user2, user3, user4, user5, user6 ]Select : ");
         scanf("%d",&input);
      }
      if(input == 1){      // user1 선택시
         printf("\n(1 = START, 2 = END, 3 = SELECT MENU) : "); 
         scanf("%d",&select);   
         if(select == 1 && check1 == 0){   
            check1 = 1;
            pid1 = fork();   // user1 시작시 프로세스 생성
            gettimeofday(&s1,NULL);   //프로세스 생성시간 저장
            if(pid1 < 0) perror("fork error");
            else if(pid1 == 0){
               printf("        <USER1 사용시작>        \n");
               time(&t);
               lt = localtime(&t);
               printf("================================\n");
               printf("시작 시간 : %d시 %d분 %d초\n",lt->tm_hour,lt->tm_min,lt->tm_sec);
               printf("================================\n");   //프로세스 생성시간 출력
               pause();   // 사용이 종료될때(signal을 받을때)까지 child 프로세스를 sleep시킨다.
               exit(1);
            }
         }
         else if(select == 2 && check1 == 1){
            check1 = 0;      
            st = 1;         // user1 종료 체크 변수
            kill(pid1, SIGTERM);   // user1 종료시 child 프로세스 kill
            sleep(1);
         }
         else if(select ==3 && check1 ==1){
	    fd=open("menu.txt",O_RDONLY);
	    num=read(fd,buf,MAX);
	    printf("\n");
	    write(1,buf,num);
	    printf("\n메뉴를 선택해 주세요 (1~6) : ");
	    scanf("%d",&menu_num);
	    printf(" USER%d , %d번 메뉴 주문 완료", input , menu_num);
	    menu_sum1+=menu[menu_num-1];
	 close(fd);
         }
         else if(select == 1 && check1 == 1) printf("USER1 사용중입니다\n");   
         else if(select == 2 && check1 == 0) printf("USER1 비어있습니다\n");
         else if(select == 3 && check1 == 0) printf("USER1 사용을 시작해 주세요\n");
      }
         else if(input == 2){      // user2 선택시
         printf("\n(1 = START, 2 = END, 3 = SELECT MENU) : "); 
         scanf("%d",&select);   
         if(select == 1 && check2 == 0){   
            check2 = 1;
            pid2 = fork();   // user2 시작시 프로세스 생성
            gettimeofday(&s2,NULL);   //프로세스 생성시간 저장
            if(pid2 < 0) perror("fork error");
            else if(pid2 == 0){
               printf("        <USER2 사용시작>        \n");
               time(&t);
               lt = localtime(&t);
                                  printf("================================\n");
               printf("시작 시간 : %d시 %d분 %d초\n",lt->tm_hour,lt->tm_min,lt->tm_sec);
               printf("================================\n");   //프로세스 생성시간 출력
               pause();   // 사용이 종료될때(signal을 받을때)까지 child 프로세스를 sleep시킨다.
               exit(2);
            }
         }
         else if(select == 2 && check2 == 1){
            check2 = 0;      
            st = 2;         // user2 종료 체크 변수
            kill(pid2, SIGTERM);   // user2 종료시 child 프로세스 kill
            sleep(1);
         }
         else if(select ==3 && check2 ==1){
	    fd=open("menu.txt",O_RDONLY);
	    num=read(fd,buf,MAX);
	    printf("\n");
	    write(1,buf,num);
	    printf("\n메뉴를 선택해 주세요 (1~6) : ");
	    scanf("%d",&menu_num);
	    printf(" USER%d , %d번 메뉴 주문 완료", input , menu_num);
	    menu_sum2+=menu[menu_num-1];
	 close(fd);
         }
         else if(select == 1 && check2 == 1) printf("USER1 사용중입니다\n");   
         else if(select == 2 && check2 == 0) printf("USER1 비어있습니다\n");
         else if(select == 3 && check2 == 0) printf("USER1 사용을 시작해 주세요\n");
      }
      else if(input == 3){      // user3 선택시
         printf("\n(1 = START, 2 = END, 3 = SELECT MENU) : "); 
         scanf("%d",&select);   
         if(select == 1 && check3 == 0){   
            check3 = 1;
            pid3 = fork();   // user3 시작시 프로세스 생성
            gettimeofday(&s3,NULL);   //프로세스 생성시간 저장
            if(pid3 < 0) perror("fork error");
            else if(pid3 == 0){
               printf("        <USER3 사용시작>        \n");
               time(&t);
               lt = localtime(&t);
                                  printf("================================\n");
               printf("시작 시간 : %d시 %d분 %d초\n",lt->tm_hour,lt->tm_min,lt->tm_sec);
               printf("================================\n");   //프로세스 생성시간 출력
               pause();   // 사용이 종료될때(signal을 받을때)까지 child 프로세스를 sleep시킨다.
               exit(3);
            }
         }
         else if(select == 2 && check3 == 1){
            check3 = 0;      
            st = 3;         // user3 종료 체크 변수
            kill(pid3, SIGTERM);   // user3 종료시 child 프로세스 kill
            sleep(1);
         }
         else if(select ==3 && check3 ==1){
	    fd=open("menu.txt",O_RDONLY);
	    num=read(fd,buf,MAX);
	    printf("\n");
	    write(1,buf,num);
	    printf("\n메뉴를 선택해 주세요 (1~6) : ");
	    scanf("%d",&menu_num);
	    printf(" USER%d , %d번 메뉴 주문 완료", input , menu_num);
	    menu_sum3+=menu[menu_num-1];
	 close(fd);
         }
         else if(select == 1 && check3 == 1) printf("USER1 사용중입니다\n");   
         else if(select == 2 && check3 == 0) printf("USER1 비어있습니다\n");
         else if(select == 3 && check3 == 0) printf("USER1 사용을 시작해 주세요\n");
      }
      else if(input == 4){      // user4 선택시
          printf("\n(1 = START, 2 = END, 3 = SELECT MENU) : "); 
         scanf("%d",&select);   
         if(select == 1 && check4 == 0){   
            check4 = 1;
            pid4 = fork();   // user4 시작시 프로세스 생성
            gettimeofday(&s4,NULL);   //프로세스 생성시간 저장
            if(pid4 < 0) perror("fork error");
            else if(pid4 == 0){
               printf("        <USER4 사용시작>        \n");
               time(&t);
               lt = localtime(&t);
                                  printf("================================\n");
               printf("시작 시간 : %d시 %d분 %d초\n",lt->tm_hour,lt->tm_min,lt->tm_sec);
               printf("================================\n");   //프로세스 생성시간 출력
               pause();   // 사용이 종료될때(signal을 받을때)까지 child 프로세스를 sleep시킨다.
               exit(4);
            }
         }
         else if(select == 2 && check4 == 1){
            check4 = 0;      
            st = 4;         // user4 종료 체크 변수
            kill(pid4, SIGTERM);   // user4 종료시 child 프로세스 kill
            sleep(1);
         }
         else if(select ==3 && check4 ==1){
	    fd=open("menu.txt",O_RDONLY);
	    num=read(fd,buf,MAX);
	    printf("\n");
	    write(1,buf,num);
	    printf("\n메뉴를 선택해 주세요 (1~6) : ");
	    scanf("%d",&menu_num);
	    printf(" USER%d , %d번 메뉴 주문 완료", input , menu_num);
	    menu_sum4+=menu[menu_num-1];
	 close(fd);
         }
         else if(select == 1 && check4 == 1) printf("USER1 사용중입니다\n");   
         else if(select == 2 && check4 == 0) printf("USER1 비어있습니다\n");
         else if(select == 3 && check4 == 0) printf("USER1 사용을 시작해 주세요\n");
      }
      else if(input == 5){      // user5 선택시
         printf("\n(1 = START, 2 = END, 3 = SELECT MENU) : "); 
         scanf("%d",&select);   
         if(select == 1 && check5 == 0){   
            check5 = 1;
            pid5 = fork();   // user5 시작시 프로세스 생성
            gettimeofday(&s5,NULL);   //프로세스 생성시간 저장
            if(pid5 < 0) perror("fork error");
            else if(pid5 == 0){
               printf("        <USER5 사용시작>        \n");
               time(&t);
               lt = localtime(&t);
                                  printf("================================\n");
               printf("시작 시간 : %d시 %d분 %d초\n",lt->tm_hour,lt->tm_min,lt->tm_sec);
               printf("================================\n");   //프로세스 생성시간 출력
               pause();   // 사용이 종료될때(signal을 받을때)까지 child 프로세스를 sleep시킨다.
               exit(5);
            }
         }
         else if(select == 2 && check5 == 1){
            check5 = 0;      
            st = 5;         // user5 종료 체크 변수
            kill(pid5, SIGTERM);   // user5 종료시 child 프로세스 kill
            sleep(1);
         }
         else if(select ==3 && check5 ==1){
	    fd=open("menu.txt",O_RDONLY);
	    num=read(fd,buf,MAX);
	    printf("\n");
	    write(1,buf,num);
	    printf("\n메뉴를 선택해 주세요 (1~6) : ");
	    scanf("%d",&menu_num);
	    printf(" USER%d , %d번 메뉴 주문 완료", input , menu_num);
	    menu_sum5+=menu[menu_num-1];
	 close(fd);
         }
         else if(select == 1 && check5 == 1) printf("USER1 사용중입니다\n");   
         else if(select == 2 && check5 == 0) printf("USER1 비어있습니다\n");
         else if(select == 3 && check5 == 0) printf("USER1 사용을 시작해 주세요\n");
      }
      else if(input == 6){      // user6 선택시
         printf("\n(1 = START, 2 = END, 3 = SELECT MENU) : "); 
         scanf("%d",&select);   
         if(select == 1 && check6 == 0){   
            check6 = 1;
            pid6 = fork();   // user6 시작시 프로세스 생성
            gettimeofday(&s6,NULL);   //프로세스 생성시간 저장
            if(pid6 < 0) perror("fork error");
            else if(pid6 == 0){
               printf("        <USER6 사용시작>        \n");
               time(&t);
               lt = localtime(&t);
                                  printf("================================\n");
               printf("시작 시간 : %d시 %d분 %d초\n",lt->tm_hour,lt->tm_min,lt->tm_sec);
               printf("================================\n");   //프로세스 생성시간 출력
               pause();   // 사용이 종료될때(signal을 받을때)까지 child 프로세스를 sleep시킨다.
               exit(6);
            }
         }
         else if(select == 2 && check6 == 1){
            check6 = 0;      
            st = 6;         // user6 종료 체크 변수
            kill(pid6, SIGTERM);   // user6 종료시 child 프로세스 kill
            sleep(1);
         }
         else if(select ==3 && check6 ==1){
	    fd=open("menu.txt",O_RDONLY);
	    num=read(fd,buf,MAX);
	    printf("\n");
	    write(1,buf,num);
	    printf("\n메뉴를 선택해 주세요 (1~6) : ");
	    scanf("%d",&menu_num);
	    printf(" USER%d , %d번 메뉴 주문 완료", input , menu_num);
	    menu_sum6+=menu[menu_num-1];
	 close(fd);
         }
         else if(select == 1 && check6 == 1) printf("USER1 사용중입니다\n");   
         else if(select == 2 && check6 == 0) printf("USER1 비어있습니다\n");
         else if(select == 3 && check6 == 0) printf("USER1 사용을 시작해 주세요\n");
      }
      else exit(0);
   sleep(1);
   }   
}
void sig_cld()
{
   switch(st){
      case 1 :    // user1 종료시 실행
         printf("       <USER1 사용종료>       \n");
         time(&t);
         lt = localtime(&t);
         gettimeofday(&e1,NULL);      // user1 종료 시간 저장
         sum1+=(menu_sum1+(e1.tv_sec - s1.tv_sec)*10); 
         printf("================================\n");
         printf("종료 시간 : %d시 %d분 %d초\n",lt->tm_hour,lt->tm_min,lt->tm_sec);
         printf("USER1의 총 사용금액 : %d원\n", menu_sum1+(e1.tv_sec-s1.tv_sec)*10);
         printf("USER1 하루 총 매출 %d원\n",sum1);
         menu_sum1=0;
         st = 0;
         break;
      case 2 :   // user2 종료시 실행
         printf("       <USER2 사용종료>       \n");
         time(&t);
         lt = localtime(&t);
         gettimeofday(&e2,NULL);
         sum2 += menu_sum2+(e2.tv_sec - s2.tv_sec)*10;
         printf("================================\n");
         printf("종료 시간 : %d시 %d분 %d초\n",lt->tm_hour,lt->tm_min,lt->tm_sec);
         printf("USER2의 사용요금 : %d원\n", menu_sum2+(e2.tv_sec-s2.tv_sec)*10);
         printf("USER2의 총 매출 %d원\n",sum2);
         st = 0;
         menu_sum2=0;
         break;
      case 3 :   // user3 종료시 실행
         printf("       <USER3 사용종료>       \n");
         time(&t);
         lt = localtime(&t);
         gettimeofday(&e3,NULL);
         sum3 += menu_sum3+(e3.tv_sec - s3.tv_sec)*10;
         printf("================================\n");
         printf("종료 시간 : %d시 %d분 %d초\n",lt->tm_hour,lt->tm_min,lt->tm_sec);
         printf("USER3의 사용요금 : %d원\n", menu_sum3+(e3.tv_sec-s3.tv_sec)*10);
         printf("USER3의 총 매출 %d원\n",sum3);
         st = 0;
         menu_sum3=0;
         break;
         case 4 :   // user4 종료시 실행
         printf("       <USER4 사용종료>       \n");
         time(&t);
         lt = localtime(&t);
         gettimeofday(&e4,NULL);
         sum4 += menu_sum4 + (e4.tv_sec - s4.tv_sec)*10;
         printf("================================\n");
         printf("종료 시간 : %d시 %d분 %d초\n",lt->tm_hour,lt->tm_min,lt->tm_sec);
         printf("USER4의 사용요금 : %d원\n", menu_sum4+(e4.tv_sec-s4.tv_sec)*10);
         printf("USER4의 총 매출 %d원\n",sum4);
         st = 0;
         menu_sum4=0;
         break;
         case 5 :   // user5 종료시 실행
         printf("       <USER5 사용종료>       \n");
         time(&t);
         lt = localtime(&t);
         gettimeofday(&e5,NULL);
         sum5+=menu_sum5+(e5.tv_sec - s5.tv_sec)*10;
         printf("================================\n");
         printf("종료 시간 : %d시 %d분 %d초\n",lt->tm_hour,lt->tm_min,lt->tm_sec);
         printf("USER5의 사용요금 : %d원\n", menu_sum5+(e5.tv_sec-s5.tv_sec)*10);
         printf("USER5의 총 매출 %d원\n",sum5);
         st = 0;
         menu_sum5=0;
         break;
         case 6 :   // user6 종료시 실행
         printf("       <USER6 사용종료>       \n");
         time(&t);
         lt = localtime(&t);
         gettimeofday(&e6,NULL);
         printf("================================\n");
         printf("종료 시간 : %d시 %d분 %d초\n",lt->tm_hour,lt->tm_min,lt->tm_sec);
         printf("USER6의 사용요금 : %d원\n", menu_sum6+(e6.tv_sec-s6.tv_sec)*10);
         printf("USER6의 총 매출 %d원\n",sum6);
         st = 0;
         menu_sum6=0;
         break;
      default : break;
   }
   total = sum1 + sum2 + sum3 + sum4 + sum5 + sum6;      // 프로세스가 살아있었던 시간을 모두 더함
   printf("총 매출액 : %d원\n",total);
   printf("================================\n");
   signal(SIGCLD,sig_cld);
}