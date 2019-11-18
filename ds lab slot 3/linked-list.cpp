#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;

struct node {
  lli x;
  struct node* ptr;
};
struct node* head=NULL;

node* create(lli t){
    node* temp= new node;
    temp->x=t;
    temp->ptr=NULL;
    return temp;
}

void insertfirst(lli t){
   node* temp=create(t);
   temp->ptr=head;
   head=temp;
}

void insertlast(lli t){
    node* temp=create(t);
    temp->ptr=NULL;
    node* temp1=head;
    node* prev;
    if(head==NULL){
        head=temp;
        return;
    }
    while(temp1!=NULL){
        prev=temp1;
        temp1=temp1->ptr;
    }
    prev->ptr=temp;
}

void insertafter(lli x, lli t){
    node* temp =create(t);
    node* temp1=head;
    while(temp1->x!=x){
        temp1=temp1->ptr;
    }
    temp->ptr=temp1->ptr;
    temp1->ptr=temp;
}
void print(){
    node* temp=head;
    while(temp!=NULL){
        cout << temp->x << " ";
        temp=temp->ptr;
    }
    cout << "\n";
}

void DeleteFirst(){
    node* temp=head;
    if(head==NULL){
        cout << "wrong";
    }else{
        head=head->ptr;
        free(temp);
    }
}

void Delete(lli x){
    node* temp=head;
    node* prev;
    while(temp->x!=x){
        prev=temp;
        temp=temp->ptr;
    }
    if(temp==head){
        DeleteFirst();
        return;
    }
    prev->ptr=temp->ptr;
    free(temp);
    temp->ptr=NULL;
}

void DeleteLast(){
    node* temp=head;
    node* prev;
    while(temp->ptr!=NULL){
        prev=temp;
        temp=temp->ptr;
    }
    prev->ptr=NULL;
    free(temp);
}

void search(lli t){
    node* temp=head;
     if(temp==NULL){
        cout << "not found"<<endl;
        return;
        }
    int n=0;
    while(temp->ptr!=NULL){
        if(temp->x==t){
        	n++;
    		}
    		temp=temp->ptr;
        }
    
    if(n==0) 
    {
    	cout<<"not found"<<endl;
	}
    else{
        cout << "found "<<n<<" times"<<endl;
    }
}

void insertbefore(lli x, lli t){
    node* temp=create(t);
    node* temp1=head;
    node* prev=NULL;
    while(temp1->x!=x){
        prev=temp1;
        temp1=temp1->ptr;
    }
    if(temp1==head){
        insertfirst(t);
        return;
    }
    prev->ptr=temp;
    temp->ptr=temp1;
}


int main(){
    lli n;
    cin >> n;
     
    search(5);
    for(lli i=1;i<=n;i++){
        insertlast(i);
    }
    //print();
    
    
    for(lli i=1;i<=n;i++){
        insertfirst(i);
    }
    //print();
    
    
    for(lli i=1;i<=n;i++){
        insertbefore(i,i);
    }
    //print();
    
    
    for(lli i=1;i<=n;i++){
        insertafter(i,i);
    }
    //print();
    
    
    for(lli i=1;i<=n;i++){
        DeleteFirst();
    }
    //print();
    
    
    for(lli i=1;i<=n;i++){
        Delete(i);
    }
    //print();
    
    
    
    for(lli i=1;i<=n;i++){
        DeleteLast();
    }
    print();
    
    search(5);
    search(4);
    search(14);
}
