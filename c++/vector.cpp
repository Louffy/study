#include<iostream>
#include<vector>
using namespace std;
int main()
{
	vector<vector<int> > a;
	vector<int> b;
	for(int i=0; i<10; i++)
		b.push_back(i);
	a.push_back(b);
	cout<<b.size()<<"  "<<a.size();
}
