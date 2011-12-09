#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<sys/types.h>
#include<linux/sem.h>
#define LOOPS 10
void P(int semid,int index);
void V(int semid,int index);
void *subp1();
void *subp2();
int semid;
int a=0;
pthread_t p1,p2;

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

void *subp1()
{
    int i,j;
    for(i=0;i<LOOPS;i++)
    {
        P(semid,0);
        printf("subp1:a=%d\n",a);
        V(semid,1);
    }
    return;
}
void *subp2()
{
    int i,j;
    for(i=0;i<LOOPS;i++)
    {
        P(semid,1);
        a+=1;
        printf("subp2\n");
        V(semid,0);
    }
    return;
}       
int main(void)
{
    union semun semopts;
    int res;
    semid = semget(IPC_PRIVATE,2,IPC_CREAT|0666);
    semopts.val = 0;
    res = semctl(semid,0,SETVAL,semopts);
    semopts.val = 1;
    res = semctl(semid,1,SETVAL,semopts); 
    pthread_create(&p1,NULL,subp1,NULL);
    pthread_create(&p2,NULL,subp2,NULL);
    pthread_join(p1,NULL);
    pthread_join(p2,NULL);
    semctl(semid,0,IPC_RMID,0);
    return 0;
}


