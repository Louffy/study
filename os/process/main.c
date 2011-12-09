#include<stdio.h>
#include<stdlib.h>
#include<linux/shm.h>
#include<sys/types.h>
#include<linux/sem.h>
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
    union semun semopts;
    int res,i;
    struct shmid_ds *buf;
    int cmd;
    int shmid1,shmid2;
    char *s,*t,ss[]="";
    pid_t p1,p2,p3;
    
    
    semid = semget(IPCKEY,4,IPC_CREAT|0666);   
    semopts.val = 1;
    res = semctl(semid,0,SETVAL,semopts);    
    semopts.val = 1;
    res = semctl(semid,1,SETVAL,semopts);  
    semopts.val = 0;
    res = semctl(semid,2,SETVAL,semopts);    
    semopts.val = 0;
    res = semctl(semid,3,SETVAL,semopts);  
    shmid1 = shmget(SHMKEY1,sizeof(char),IPC_CREAT|0666);   
    s=(char *)shmat(shmid1,NULL,SHM_R|SHM_W);
    shmid2 = shmget(SHMKEY2,sizeof(char),IPC_CREAT|0666);
    t=(char *)shmat(shmid2,NULL,SHM_R|SHM_W);
    
  
    
    if((p1=fork()) == 0){
        execv("./get",NULL);
        }
     else
     {
         if((p2=fork()) == 0){
             execv("./copy",NULL);
              }
          else
          {
              if((p3=fork())==0){
                 execv("./put",NULL);
                 }
           }
      }
      p1=wait(&p1);
      p2=wait(&p2);
      p3=wait(&p3);
      /*for(i=0;i<3;i++)
      { 
          while(-1!=wait())
              ;
      }*/
      if(semctl(semid,0,IPC_RMID,0)<0)
      printf("error");
      shmctl(shmid1,IPC_RMID,0);
      shmctl(shmid2,IPC_RMID,0);
      return 0;
}
              
        






