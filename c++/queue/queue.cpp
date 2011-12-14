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
	    QUEUE()
	    {
			front=rear=NULL;
			cout<<"queue()\n";
        }
		~QUEUE();
		int insert(char v);
		int remove(char &v);
		int empty();
};
QUEUE::NODE::NODE(char v)
{
	elem=v;
	next=NULL;
}


QUEUE::~QUEUE()
{
	NODE *p=NULL;
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
	if(p==NULL)return 0;
	if(front==NULL){
		front=p;
	}
	else{
			rear->next=p;
			
	}
	rear=p;
	//cout<<v;
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
	if(front==NULL&&rear==NULL)return 1;
	else return 0;
}

int main(void)
{
	QUEUE q;
	char v;
	q.insert('a');
	q.insert('b');
	
}


        		
