#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<linux/sem.h>
#include<linux/shm.h>
#define LOOPS 10
#define IPCKEY (key_t)0x11
#define SHMKEY1 (key_t)0x222
#define SHMKEY2 (key_t)0x333
void P(int semid,int index);
void V(int semid,int index);
int semid;

void V(int semid,int index)
{
    struct sembuf sem;
    sem.sem_num = index;/*信号灯数组灯的一个索引，指明哪个信号灯*/
    sem.sem_op = 1;/*加到当前信号灯的数值*/
    sem.sem_flg = 0;
    semop(semid,&sem,1);
    return;
} 
void P(int semid,int index)
{
    struct sembuf sem;
    sem.sem_num = index;
    sem.sem_op = -1;
    sem.sem_flg = 0;
    semop(semid,&sem,1);
    return;
}
int main(void)
{
    
    int i=0;
    int shmid1;
    char *s,*t,str[]="Hello world!";/*str为输入的字符，实现一个一个字符的输入，输出，s，t指针当单个字符使用，即s[0],t[0]*/
    
    semid = semget(IPCKEY,4,IPC_CREAT|0666);
    shmid1 = shmget(SHMKEY1,sizeof(char),IPC_CREAT|0666);
    s=(char *)shmat(shmid1,NULL,SHM_R|SHM_W);/* 绑定到共享内存块 */
    
    do
    {
        P(semid,0);      
        s[0]=str[i];
        printf("get\n");
        i++;       
        V(semid,2);
        
     }while(s[0]!='\0');
}      
