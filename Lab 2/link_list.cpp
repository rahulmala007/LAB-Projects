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
	if(head==NULL) 
	{
		cout<<"-1"<<endl;
		
	}
	else{
	Node* x=head->next;
	free(head);
	head=x;

	}
	

}

void Del(int x,int y)
{	Node * temp=NULL;
	if(head==NULL) 
	{
		cout<<"-1"<<endl;
		return;	
	}
	Node* prev=head;
	if(prev->x==x && prev->y==y) 
	{
		DelFirst();
		return;
	}
	int check=0;
	while(prev!=NULL)
	{	
		if(prev!=NULL)temp=prev->next;
		
		if(temp!=NULL)
		{

			if(temp->x==x && temp->y==y) {
			check=1;
			prev->next=temp->next;
			free(temp);
			}
			
		}
		 prev=prev->next;

		
	}
	if(check==0) cout<<"-1"<<endl;
	return;

}

int Search(float d)
{	int count=0;
	if(head==NULL) return -1;
	else{
		Node * temp=head;
		while(temp!=NULL)
		{
			if(dist(temp->x,temp->y)<=d) count++;
			temp=temp->next;
		}
		if(count>0) return count;
		else return -1;
	}

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
	if(head==NULL)
	{
		return 0;
	} 
	Node* temp=head;
	int l=0;
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
				cout<<Search(d)<<endl;
		}
		else if(a==5)
		{
			cin>>b>>c;
			if(Search(b,c)) cout<<"True"<<endl;
			else cout<<"False"<<endl;
		}
		else
		{
			cout<<length()<<endl;
		}


	}

}