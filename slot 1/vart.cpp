#include <bits/stdc++.h> 
using namespace std; 

struct Node 
{ 
	int key; 
	vector<Node *>child; 
}; 

Node *newNode(int key) 
{ 
	Node *temp = new Node; 
	temp->key = key; 
	return temp; 
} 

void BFS(Node * root) 
{ 
	if (root==NULL) 
		return; 
	queue<Node *> q;
	q.push(root);
	while (!q.empty()) 
	{ 
		int n = q.size(); 
		while (n > 0) 
		{ 
			Node *p = q.front(); 
			q.pop(); 
			cout << p->key << " "; 
			for (int i=0; i<p->child.size(); i++) 
				q.push(p->child[i]); 
			n--; 
		} 

		cout << endl;
	} 
} 


void insertNode(Node* root,int key)
{
	(root->child).push_back(newNode(key));
}

int main() 
{ 
	Node *root = newNode(1); 
	insertNode(root,3);
	insertNode(root,5);
	insertNode(root,2);
	insertNode(root,4);

	for(int i=0;i<4;i++)
	{
		insertNode(root->child[i],i+6);
		insertNode(root->child[i],i+7);
	}
	cout << "Level order traversal\n"; 
	BFS(root); 
	
	
} 