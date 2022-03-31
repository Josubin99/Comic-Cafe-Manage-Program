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
   int input,select;            // ROOM ����, ����&���� ����
   int check1=0,check2=0,check3=0,check4=0,check5=0,check6=0;   // ��뿩�� üũ 
   int fd;
   int num;
   signal(SIGCLD,sig_cld);      // child���μ��� ����� sig_cld() ����
   while(1){
      printf("\n[ user1, user2, user3, user4, user5, user6 ]Select : ");
      scanf("%d",&input);
      while(input<1 || input>6){
         printf("�ٽ� �Է��� �ּ���");
         printf("\n[user1, user2, user3, user4, user5, user6 ]Select : ");
         scanf("%d",&input);
      }
      if(input == 1){      // user1 ���ý�
         printf("\n(1 = START, 2 = END, 3 = SELECT MENU) : "); 
         scanf("%d",&select);   
         if(select == 1 && check1 == 0){   
            check1 = 1;
            pid1 = fork();   // user1 ���۽� ���μ��� ����
            gettimeofday(&s1,NULL);   //���μ��� �����ð� ����
            if(pid1 < 0) perror("fork error");
            else if(pid1 == 0){
               printf("        <USER1 ������>        \n");
               time(&t);
               lt = localtime(&t);
               printf("================================\n");
               printf("���� �ð� : %d�� %d�� %d��\n",lt->tm_hour,lt->tm_min,lt->tm_sec);
               printf("================================\n");   //���μ��� �����ð� ���
               pause();   // ����� ����ɶ�(signal�� ������)���� child ���μ����� sleep��Ų��.
               exit(1);
            }
         }
         else if(select == 2 && check1 == 1){
            check1 = 0;      
            st = 1;         // user1 ���� üũ ����
            kill(pid1, SIGTERM);   // user1 ����� child ���μ��� kill
            sleep(1);
         }
         else if(select ==3 && check1 ==1){
	    fd=open("menu.txt",O_RDONLY);
	    num=read(fd,buf,MAX);
	    printf("\n");
	    write(1,buf,num);
	    printf("\n�޴��� ������ �ּ��� (1~6) : ");
	    scanf("%d",&menu_num);
	    printf(" USER%d , %d�� �޴� �ֹ� �Ϸ�", input , menu_num);
	    menu_sum1+=menu[menu_num-1];
	 close(fd);
         }
         else if(select == 1 && check1 == 1) printf("USER1 ������Դϴ�\n");   
         else if(select == 2 && check1 == 0) printf("USER1 ����ֽ��ϴ�\n");
         else if(select == 3 && check1 == 0) printf("USER1 ����� ������ �ּ���\n");
      }
         else if(input == 2){      // user2 ���ý�
         printf("\n(1 = START, 2 = END, 3 = SELECT MENU) : "); 
         scanf("%d",&select);   
         if(select == 1 && check2 == 0){   
            check2 = 1;
            pid2 = fork();   // user2 ���۽� ���μ��� ����
            gettimeofday(&s2,NULL);   //���μ��� �����ð� ����
            if(pid2 < 0) perror("fork error");
            else if(pid2 == 0){
               printf("        <USER2 ������>        \n");
               time(&t);
               lt = localtime(&t);
                                  printf("================================\n");
               printf("���� �ð� : %d�� %d�� %d��\n",lt->tm_hour,lt->tm_min,lt->tm_sec);
               printf("================================\n");   //���μ��� �����ð� ���
               pause();   // ����� ����ɶ�(signal�� ������)���� child ���μ����� sleep��Ų��.
               exit(2);
            }
         }
         else if(select == 2 && check2 == 1){
            check2 = 0;      
            st = 2;         // user2 ���� üũ ����
            kill(pid2, SIGTERM);   // user2 ����� child ���μ��� kill
            sleep(1);
         }
         else if(select ==3 && check2 ==1){
	    fd=open("menu.txt",O_RDONLY);
	    num=read(fd,buf,MAX);
	    printf("\n");
	    write(1,buf,num);
	    printf("\n�޴��� ������ �ּ��� (1~6) : ");
	    scanf("%d",&menu_num);
	    printf(" USER%d , %d�� �޴� �ֹ� �Ϸ�", input , menu_num);
	    menu_sum2+=menu[menu_num-1];
	 close(fd);
         }
         else if(select == 1 && check2 == 1) printf("USER1 ������Դϴ�\n");   
         else if(select == 2 && check2 == 0) printf("USER1 ����ֽ��ϴ�\n");
         else if(select == 3 && check2 == 0) printf("USER1 ����� ������ �ּ���\n");
      }
      else if(input == 3){      // user3 ���ý�
         printf("\n(1 = START, 2 = END, 3 = SELECT MENU) : "); 
         scanf("%d",&select);   
         if(select == 1 && check3 == 0){   
            check3 = 1;
            pid3 = fork();   // user3 ���۽� ���μ��� ����
            gettimeofday(&s3,NULL);   //���μ��� �����ð� ����
            if(pid3 < 0) perror("fork error");
            else if(pid3 == 0){
               printf("        <USER3 ������>        \n");
               time(&t);
               lt = localtime(&t);
                                  printf("================================\n");
               printf("���� �ð� : %d�� %d�� %d��\n",lt->tm_hour,lt->tm_min,lt->tm_sec);
               printf("================================\n");   //���μ��� �����ð� ���
               pause();   // ����� ����ɶ�(signal�� ������)���� child ���μ����� sleep��Ų��.
               exit(3);
            }
         }
         else if(select == 2 && check3 == 1){
            check3 = 0;      
            st = 3;         // user3 ���� üũ ����
            kill(pid3, SIGTERM);   // user3 ����� child ���μ��� kill
            sleep(1);
         }
         else if(select ==3 && check3 ==1){
	    fd=open("menu.txt",O_RDONLY);
	    num=read(fd,buf,MAX);
	    printf("\n");
	    write(1,buf,num);
	    printf("\n�޴��� ������ �ּ��� (1~6) : ");
	    scanf("%d",&menu_num);
	    printf(" USER%d , %d�� �޴� �ֹ� �Ϸ�", input , menu_num);
	    menu_sum3+=menu[menu_num-1];
	 close(fd);
         }
         else if(select == 1 && check3 == 1) printf("USER1 ������Դϴ�\n");   
         else if(select == 2 && check3 == 0) printf("USER1 ����ֽ��ϴ�\n");
         else if(select == 3 && check3 == 0) printf("USER1 ����� ������ �ּ���\n");
      }
      else if(input == 4){      // user4 ���ý�
          printf("\n(1 = START, 2 = END, 3 = SELECT MENU) : "); 
         scanf("%d",&select);   
         if(select == 1 && check4 == 0){   
            check4 = 1;
            pid4 = fork();   // user4 ���۽� ���μ��� ����
            gettimeofday(&s4,NULL);   //���μ��� �����ð� ����
            if(pid4 < 0) perror("fork error");
            else if(pid4 == 0){
               printf("        <USER4 ������>        \n");
               time(&t);
               lt = localtime(&t);
                                  printf("================================\n");
               printf("���� �ð� : %d�� %d�� %d��\n",lt->tm_hour,lt->tm_min,lt->tm_sec);
               printf("================================\n");   //���μ��� �����ð� ���
               pause();   // ����� ����ɶ�(signal�� ������)���� child ���μ����� sleep��Ų��.
               exit(4);
            }
         }
         else if(select == 2 && check4 == 1){
            check4 = 0;      
            st = 4;         // user4 ���� üũ ����
            kill(pid4, SIGTERM);   // user4 ����� child ���μ��� kill
            sleep(1);
         }
         else if(select ==3 && check4 ==1){
	    fd=open("menu.txt",O_RDONLY);
	    num=read(fd,buf,MAX);
	    printf("\n");
	    write(1,buf,num);
	    printf("\n�޴��� ������ �ּ��� (1~6) : ");
	    scanf("%d",&menu_num);
	    printf(" USER%d , %d�� �޴� �ֹ� �Ϸ�", input , menu_num);
	    menu_sum4+=menu[menu_num-1];
	 close(fd);
         }
         else if(select == 1 && check4 == 1) printf("USER1 ������Դϴ�\n");   
         else if(select == 2 && check4 == 0) printf("USER1 ����ֽ��ϴ�\n");
         else if(select == 3 && check4 == 0) printf("USER1 ����� ������ �ּ���\n");
      }
      else if(input == 5){      // user5 ���ý�
         printf("\n(1 = START, 2 = END, 3 = SELECT MENU) : "); 
         scanf("%d",&select);   
         if(select == 1 && check5 == 0){   
            check5 = 1;
            pid5 = fork();   // user5 ���۽� ���μ��� ����
            gettimeofday(&s5,NULL);   //���μ��� �����ð� ����
            if(pid5 < 0) perror("fork error");
            else if(pid5 == 0){
               printf("        <USER5 ������>        \n");
               time(&t);
               lt = localtime(&t);
                                  printf("================================\n");
               printf("���� �ð� : %d�� %d�� %d��\n",lt->tm_hour,lt->tm_min,lt->tm_sec);
               printf("================================\n");   //���μ��� �����ð� ���
               pause();   // ����� ����ɶ�(signal�� ������)���� child ���μ����� sleep��Ų��.
               exit(5);
            }
         }
         else if(select == 2 && check5 == 1){
            check5 = 0;      
            st = 5;         // user5 ���� üũ ����
            kill(pid5, SIGTERM);   // user5 ����� child ���μ��� kill
            sleep(1);
         }
         else if(select ==3 && check5 ==1){
	    fd=open("menu.txt",O_RDONLY);
	    num=read(fd,buf,MAX);
	    printf("\n");
	    write(1,buf,num);
	    printf("\n�޴��� ������ �ּ��� (1~6) : ");
	    scanf("%d",&menu_num);
	    printf(" USER%d , %d�� �޴� �ֹ� �Ϸ�", input , menu_num);
	    menu_sum5+=menu[menu_num-1];
	 close(fd);
         }
         else if(select == 1 && check5 == 1) printf("USER1 ������Դϴ�\n");   
         else if(select == 2 && check5 == 0) printf("USER1 ����ֽ��ϴ�\n");
         else if(select == 3 && check5 == 0) printf("USER1 ����� ������ �ּ���\n");
      }
      else if(input == 6){      // user6 ���ý�
         printf("\n(1 = START, 2 = END, 3 = SELECT MENU) : "); 
         scanf("%d",&select);   
         if(select == 1 && check6 == 0){   
            check6 = 1;
            pid6 = fork();   // user6 ���۽� ���μ��� ����
            gettimeofday(&s6,NULL);   //���μ��� �����ð� ����
            if(pid6 < 0) perror("fork error");
            else if(pid6 == 0){
               printf("        <USER6 ������>        \n");
               time(&t);
               lt = localtime(&t);
                                  printf("================================\n");
               printf("���� �ð� : %d�� %d�� %d��\n",lt->tm_hour,lt->tm_min,lt->tm_sec);
               printf("================================\n");   //���μ��� �����ð� ���
               pause();   // ����� ����ɶ�(signal�� ������)���� child ���μ����� sleep��Ų��.
               exit(6);
            }
         }
         else if(select == 2 && check6 == 1){
            check6 = 0;      
            st = 6;         // user6 ���� üũ ����
            kill(pid6, SIGTERM);   // user6 ����� child ���μ��� kill
            sleep(1);
         }
         else if(select ==3 && check6 ==1){
	    fd=open("menu.txt",O_RDONLY);
	    num=read(fd,buf,MAX);
	    printf("\n");
	    write(1,buf,num);
	    printf("\n�޴��� ������ �ּ��� (1~6) : ");
	    scanf("%d",&menu_num);
	    printf(" USER%d , %d�� �޴� �ֹ� �Ϸ�", input , menu_num);
	    menu_sum6+=menu[menu_num-1];
	 close(fd);
         }
         else if(select == 1 && check6 == 1) printf("USER1 ������Դϴ�\n");   
         else if(select == 2 && check6 == 0) printf("USER1 ����ֽ��ϴ�\n");
         else if(select == 3 && check6 == 0) printf("USER1 ����� ������ �ּ���\n");
      }
      else exit(0);
   sleep(1);
   }   
}
void sig_cld()
{
   switch(st){
      case 1 :    // user1 ����� ����
         printf("       <USER1 �������>       \n");
         time(&t);
         lt = localtime(&t);
         gettimeofday(&e1,NULL);      // user1 ���� �ð� ����
         sum1+=(menu_sum1+(e1.tv_sec - s1.tv_sec)*10); 
         printf("================================\n");
         printf("���� �ð� : %d�� %d�� %d��\n",lt->tm_hour,lt->tm_min,lt->tm_sec);
         printf("USER1�� �� ���ݾ� : %d��\n", menu_sum1+(e1.tv_sec-s1.tv_sec)*10);
         printf("USER1 �Ϸ� �� ���� %d��\n",sum1);
         menu_sum1=0;
         st = 0;
         break;
      case 2 :   // user2 ����� ����
         printf("       <USER2 �������>       \n");
         time(&t);
         lt = localtime(&t);
         gettimeofday(&e2,NULL);
         sum2 += menu_sum2+(e2.tv_sec - s2.tv_sec)*10;
         printf("================================\n");
         printf("���� �ð� : %d�� %d�� %d��\n",lt->tm_hour,lt->tm_min,lt->tm_sec);
         printf("USER2�� ����� : %d��\n", menu_sum2+(e2.tv_sec-s2.tv_sec)*10);
         printf("USER2�� �� ���� %d��\n",sum2);
         st = 0;
         menu_sum2=0;
         break;
      case 3 :   // user3 ����� ����
         printf("       <USER3 �������>       \n");
         time(&t);
         lt = localtime(&t);
         gettimeofday(&e3,NULL);
         sum3 += menu_sum3+(e3.tv_sec - s3.tv_sec)*10;
         printf("================================\n");
         printf("���� �ð� : %d�� %d�� %d��\n",lt->tm_hour,lt->tm_min,lt->tm_sec);
         printf("USER3�� ����� : %d��\n", menu_sum3+(e3.tv_sec-s3.tv_sec)*10);
         printf("USER3�� �� ���� %d��\n",sum3);
         st = 0;
         menu_sum3=0;
         break;
         case 4 :   // user4 ����� ����
         printf("       <USER4 �������>       \n");
         time(&t);
         lt = localtime(&t);
         gettimeofday(&e4,NULL);
         sum4 += menu_sum4 + (e4.tv_sec - s4.tv_sec)*10;
         printf("================================\n");
         printf("���� �ð� : %d�� %d�� %d��\n",lt->tm_hour,lt->tm_min,lt->tm_sec);
         printf("USER4�� ����� : %d��\n", menu_sum4+(e4.tv_sec-s4.tv_sec)*10);
         printf("USER4�� �� ���� %d��\n",sum4);
         st = 0;
         menu_sum4=0;
         break;
         case 5 :   // user5 ����� ����
         printf("       <USER5 �������>       \n");
         time(&t);
         lt = localtime(&t);
         gettimeofday(&e5,NULL);
         sum5+=menu_sum5+(e5.tv_sec - s5.tv_sec)*10;
         printf("================================\n");
         printf("���� �ð� : %d�� %d�� %d��\n",lt->tm_hour,lt->tm_min,lt->tm_sec);
         printf("USER5�� ����� : %d��\n", menu_sum5+(e5.tv_sec-s5.tv_sec)*10);
         printf("USER5�� �� ���� %d��\n",sum5);
         st = 0;
         menu_sum5=0;
         break;
         case 6 :   // user6 ����� ����
         printf("       <USER6 �������>       \n");
         time(&t);
         lt = localtime(&t);
         gettimeofday(&e6,NULL);
         printf("================================\n");
         printf("���� �ð� : %d�� %d�� %d��\n",lt->tm_hour,lt->tm_min,lt->tm_sec);
         printf("USER6�� ����� : %d��\n", menu_sum6+(e6.tv_sec-s6.tv_sec)*10);
         printf("USER6�� �� ���� %d��\n",sum6);
         st = 0;
         menu_sum6=0;
         break;
      default : break;
   }
   total = sum1 + sum2 + sum3 + sum4 + sum5 + sum6;      // ���μ����� ����־��� �ð��� ��� ����
   printf("�� ����� : %d��\n",total);
   printf("================================\n");
   signal(SIGCLD,sig_cld);
}