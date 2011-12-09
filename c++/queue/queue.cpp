#include<iostream>
using namespace std;

class QUEUE
{
	struct NODE
	{
		char elem;
		NODE *next;
		NODE(char v);
	};
	NODE *front,*rear;
	public:
	    QUEUE();
		~QUEUE();
		int insert(char v);
		int remove(char &v);
		int empty();
		//int destroy();
};
QUEUE::NODE::NODE(char v)
{
	elem=v;
	next=0;
}
QUEUE::QUEUE()
{
	front=rear=0;
}
QUEUE::~QUEUE()
{
	NODE *p;
	while(front)
	{
		p=front->next;
		delete front;
		front=p;
	}
}
int QUEUE::insert(char v)
{
	NODE *p=new NODE(v);
	if(p==0)return 0;
	rear->next=p;
	p->next=0;
	rear=p;
	printf("%c\n",p->elem);
	return 1;
}
int QUEUE::remove(char &c)
{
	NODE *p=front;
    if(front==rear)return 0;
	front=p->next;
	c=p->elem;
	return 1;
}
int QUEUE::empty()
{
	if(front==rear==0)return 1;
	else return 0;
}

int main(void)
{
	QUEUE q;
	int v;
	q.insert(5);
	q.insert(6);
	
}


        		
