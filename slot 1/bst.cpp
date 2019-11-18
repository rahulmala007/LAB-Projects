#include<bits/stdc++.h> 
using namespace std;

struct node 
{ 
	int key; 
	struct node *left, *right; 
}; 

struct node *newNode(int item) 
{ 
	struct node *temp = (struct node *)malloc(sizeof(struct node)); 
	temp->key = item; 
	temp->left = temp->right = NULL; 
	return temp; 
} 

void inorder(struct node *root) 
{ 
	if (root != NULL) 
	{ 
		inorder(root->left); 
		cout<<root->key<<" "; 
		inorder(root->right); 
	} 
} 

void preorder(struct node *root) 
{ 
	if (root != NULL) 
	{ 
		cout<<root->key<<" "; 
		preorder(root->left); 
		preorder(root->right); 
	} 
} 

void postorder(struct node *root) 
{ 
	if (root != NULL) 
	{ 
		postorder(root->left); 
		postorder(root->right); 
		cout<<root->key<<" "; 
	} 
} 

struct node* insert(struct node* node, int key) 
{ 
	
	if (node == NULL) return newNode(key); 
	if (key < node->key) 
		node->left = insert(node->left, key); 
	else
		node->right = insert(node->right, key); 
	return node; 
} 

struct node * minValueNode(struct node* node) 
{ 
	struct node* current = node; 
	while (current && current->left != NULL) 
		current = current->left; 

	return current; 
} 

struct node* deleteNode(struct node* root, int key) 
{ 
	
	if (root == NULL) return root; 
	if (key < root->key) 
		root->left = deleteNode(root->left, key); 
	else if (key > root->key) 
		root->right = deleteNode(root->right, key); 
	else
	{ 
		
		if (root->left == NULL) 
		{ 
			struct node *temp = root->right; 
			free(root); 
			return temp; 
		} 
		else if (root->right == NULL) 
		{ 
			struct node *temp = root->left; 
			free(root); 
			return temp; 
		} 
		struct node* temp = minValueNode(root->right); 
		root->key = temp->key; 
		root->right = deleteNode(root->right, temp->key); 
	} 
	return root; 
} 

bool  Search(struct node* root,int key)
{
	if(root==NULL) return false;
	if(key<root->key) 
	{
			Search(root->left,key);
	}
	else if(key>root->key){
			Search(root->right,key);
	}else{
		return true;
	}
}

int main() 
{ 
	
	struct node *root = NULL; 
	root = insert(root, 5); 
	root = insert(root, 3); 
	root = insert(root, 2); 
	root = insert(root, 4); 
	root = insert(root, 7); 
	root = insert(root, 6); 
	root = insert(root, 8); 

	inorder(root);
	cout<<endl;
	postorder(root);
	cout<<endl;
	preorder(root); 
	cout << endl;
	root = deleteNode(root, 2); 
	
	inorder(root); 
    cout << endl;
	root = deleteNode(root, 3); 
	
	inorder(root); 
    cout << endl;
	root = deleteNode(root, 5); 
	
	inorder(root); 
    cout << endl;

    cout<<Search(root,8)<<endl;
    cout<<Search(root,2)<<endl;
    cout<<minValueNode(root)->key<<endl;
	
} 