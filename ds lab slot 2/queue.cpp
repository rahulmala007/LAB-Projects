#include <bits/stdc++.h> 
using namespace std; 
struct Queue  
{  	
	int front, rear, size;  
    int capacity;  
    int* array;  
};
     
Queue* createQueue(int capacity)  
{  
    Queue* queue = new Queue(); 
    queue->capacity = capacity;  
    queue->front = queue->size = 0;  
    queue->rear = capacity - 1; 
    queue->array = new int[(queue->capacity * sizeof(int))];  
    return queue;  
}  


int isFull(Queue* queue)  
{ return (queue->size == queue->capacity); }  
  
int isEmpty(Queue* queue)  
{ return (queue->size == 0); }  
  
void enqueue(Queue* queue, int item)  
{  
    if (isFull(queue)) 
	{
		cout<<"Queue is Full"<<endl;
		return;
	 } 
    queue->rear = (queue->rear + 1) % queue->capacity;  
    queue->array[queue->rear] = item;  
    queue->size = queue->size + 1;   
}  
  
void dequeue(Queue* queue)  
{  
    if (isEmpty(queue)) 
	{
		cout<<"Queue is Empty"<<endl;
		return;
	 } 
    int item = queue->array[queue->front];  
    queue->front = (queue->front + 1) % queue->capacity;  
    queue->size = queue->size - 1;  
    return;  
}   
void front(Queue* queue)  
{  
    if (isEmpty(queue))
	{
		cout<<"Queue is empty";
		return;
	  }  
        
    cout<<queue->array[queue->front]<<endl;  
}  
void rear(Queue* queue)  
{  
    if (isEmpty(queue)) {
    	cout<<"Queue is Empty"<<endl;
    	return;
	}  
    cout<< queue->array[queue->rear]<<endl;  
} 

void print(Queue *queue)
{
	int *arr=queue->array;
	for(int i=0;i<queue->size;i++)
	{
		cout<<(*(arr+i))<<" ";
	}
	cout<<endl;
}
int main()
{
	Queue *q=createQueue(2);
	enqueue(q,10);
	enqueue(q,20);
	enqueue(q,40);
	front(q);
	rear(q);
	print(q);
	dequeue(q);
	dequeue(q);
	dequeue(q);
	dequeue(q);
	dequeue(q);
	delete(q);
 } 
