#include<bits/stdc++.h>
#define ll long long
using namespace std;
struct node{
	ll us;
	ll ch;
	node* l;
	node* r;
	ll h;
};
node* root=NULL;
ll max_val[2]= {0,-1};
node* newNode(ll a,ll b){
	node* newnode=new node();
	newnode->us=a;
	newnode->l=NULL;
	newnode->r=NULL;
	newnode->h=1;
	newnode->ch=b;
	return newnode;
}

  ll height(node *n)
{
    if (n == NULL)  return 0;
    else return n->h;
}


node* rightRotate(node *y)
{
    node *x = y->l;
    node *T2 = x->r;

    x->r = y;
    y->l = T2;

    y->h = max(height(y->l),
                    height(y->r)) + 1;
    x->h = max(height(x->l),
                    height(x->r)) + 1;

    return x;
}

node *leftRotate(node *x)
{
    node *y = x->r;
    node *T2 = y->l;
    y->l = x;
    x->r = T2;
    x->h = max(height(x->l),
                    height(x->r)) + 1;
    y->h = max(height(y->l),
                    height(y->r)) + 1;

    return y;
}

ll getBalance(node *n)
{
    if (n == NULL)
        return 0;
    return height(n->l) - height(n->r);
}

node* insert(node* node, ll k, ll c)
{

    if (node == NULL)
        return(newNode(k,c));

    if (k < node->us)
        node->l = insert(node->l, k,c);
    else if (k > node->us)  node->r = insert(node->r, k,c);
    else return node;


    node->h = 1 + max(height(node->l),
                        height(node->r));

    ll bal = getBalance(node);

    if (bal > 1 && k < node->l->us)
        return rightRotate(node);


    if (bal < -1 && k > node->r->us)
        return leftRotate(node);


    if (bal > 1 && k > node->l->us)
    {
        node->l = leftRotate(node->l);
        return rightRotate(node);
    }

    if (bal < -1 && k < node->r->us)
    {
        node->r = rightRotate(node->r);
        return leftRotate(node);
    }
    return node;
}

node* Search(node* rt,ll k)
{
	if(rt==NULL) return NULL;
	if(k==rt->us) return rt;
	else if(k< rt->us) return Search(rt->l,k);
	else return Search(rt->r,k);
}

void freeTree(node* root)
{	if(root ==NULL) return;
	freeTree(root->l);
	freeTree(root->r);
	delete(root);
}

int main()
{
	ll n;
	cin>>n;
	ll t;
	cin>>t;
	while(t--)
	{
		ll a,b,c;
			cin>>a;
			if(a==1)
			{	cin>>b>>c;
				node* node=Search(root,b);
				if(node!=NULL)
				{
					node->ch=node->ch+c;
					if(node->ch>=max_val[1]) 
					{
						max_val[0]=node->us;
						max_val[1]=node->ch;
					}
					
				}else{
					root=insert(root,b,c);
					node=Search(root,b);
					if(node->ch>=max_val[1]) 
					{
						max_val[1]=node->ch;
						max_val[0]=node->us;
					}	
				}
			}
			else if(a==2){
				if(root==NULL) cout<<"No data available."<<endl;
				else cout<<max_val[0]<<endl;
			}
		}
	freeTree(root);
	}	
