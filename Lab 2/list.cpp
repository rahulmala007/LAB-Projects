#include<bits/stdc++.h>
using namespace std;

struct Node{
	int x;
	int y;
	Node* next;
};

float dist(int x,int y)
{
	return sqrt(x*x+y*y);
}
Node* head=NULL;
Node* newnode(int x,int y)
{
	Node* node=(Node*)malloc(sizeof(Node));
	node->x=x;
	node->y=y;
	node->next=NULL;
	return node;
}

void AddFirst(int x,int y)
{

	Node* node= newnode(x,y);

	if(head==NULL) 
	{
			head=node;
			return ;
	}
	node->next=head;
	head=node;
	


}

void DelFirst()
{
	if(head==NULL) cout<<"-1"<<endl;
	Node* x=head->next;
	free(head);
	head=x;

}

void Del(int x,int y)
{	Node * temp;
	if(head==NULL) cout<<"-1"<<endl;
	Node* prev=head;
	if(prev->x==x && prev->y==y) 
	{
		DelFirst();
	}
	int check=0;
	while(prev!=NULL)
	{	temp=prev->next;
		if(temp!=NULL)
		{

			if(temp->x==x && temp->y==y) {
			check=1;
			prev->next=temp->next;
			free(temp);
		}
		else prev=prev->next;
		}
		
	}
	if(!check) cout<<"-1"<<endl;

}

void Search(float d,Node* x)
{
	Node* temp=x;
	if(x==NULL) return;

	if(dist(temp->x,temp->y)<=d) 
		{	cout<<"("<<temp->x<<","<<temp->y<<")"<<endl;
			Search(d,temp->next);
			return ;
		}
	else temp=temp->next;	
}

bool Search(int x,int y)
{
	Node* temp=head;
	if (head==NULL) return false;

	while(temp!=NULL)
	{

		if(temp->x==x && temp->y==y) return true;
		else temp =temp->next;
	}
	return false;
}


int length()
{
	if(head==NULL) return 0;
	Node* temp=head;
	int l=1;
	while(temp!=NULL)
	{
		l++;
		temp=temp->next;
	}
	return l;
}


int main()
{
	long int t;
	cin>>t;

	while(t--)
	{
		int a,b,c;
		float d;	
		cin>>a;
		if(a==1)
		{
			cin>>b;
			cin>>c;
			AddFirst(b,c);
		}
		else if(a==2)
		{
				DelFirst();
		}
		else if(a==3)
		{
				cin>>b>>c;
				Del(b,c);
		}
		else if(a==4)
		{
				cin>>d;
				Search(d,head);
		}
		else if(a==5)
		{
			cin>>b>>c;
			if(Search(b,c)) cout<<"True"<<endl;
			else cout<<"False"<<endl;
		}
		else if(a==6)
		{
			cout<<length();
		}


	}

}