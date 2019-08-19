#include<bits/stdc++.h>

using namespace std;

struct treenode
{
    int i;
    treenode* left,* right,* parent;
};

int prec(char c)
{
    if(c == '^')
    return 3;
    else if(c == '*' || c == '/')
    return 2;
    else if(c == '+' || c == '-')
    return 1;
    else
    return -1;
}

bool ischar(char a)
{
    if(a=='+'||a=='-'||a=='*'||a=='/'||a=='^'){
    return true;}

    return false;
}

int mapo(char c)
{
    switch(c)
    {
        case '+': return -1;
        case '-': return -2;
        case '*': return -3;
        case '/': return -4;
        case '^': return -5;
    }
}

stack<int> postfix(char *s)
{
    stack<int> S,O;
    int f=0,a;
    O.push('N');
    for(int i=0;i<strlen(s);i++)
    {
        if(s[i]>='0'&&s[i]<='9')
        {
            if(f)
            {
                a=S.top();
                S.pop();
                S.push(a*10+s[i]-'0');
            }
            else
            {
                S.push(s[i]-'0');
                f=1;
            }
        }

        else
        {
            f=0;
            if(s[i]=='(')
                O.push('(');
            else if(s[i]==')')
            {
                while(O.top()!='N'&&O.top()!='(')
                {
                    char c=O.top();
                    O.pop();
                    S.push(mapo(c));
                }
                if(O.top()=='(')
                    O.pop();
            }
            else if(ischar(s[i]))
            {
                while(O.top()!='N'&&O.top()!='('&&prec(s[i])<=prec(O.top()))
                {
                    char c=O.top();
                    O.pop();
                    S.push(mapo(c));
                }
                O.push(s[i]);
            }
        }
    }
    while(O.top()!='N')
        {
            char c=O.top();
            O.pop();
            S.push(mapo(c));
        }
    return S;
}

treenode * newNode(int v)
{
    treenode * temp=new treenode;
    temp->left = NULL;
    temp->right = NULL;
    temp->i = v;
    return temp;
}

treenode * etree(stack<int> s)
{
    treenode *t,*t1,*t2;
    stack<treenode *> st;
    while(!s.empty())
    {
        if(s.top()>=0)
        {
            t=newNode(s.top());
            s.pop();
            st.push(t);
        }
        else
        {
            t=newNode(s.top());
            t1=st.top();
            st.pop();
            t2=st.top();
            st.pop();

            t->right=t1;
            t->left=t2;

            st.push(t);
            s.pop();
        }
    }
    return t;
}


void show(stack<int> s)
{
    while(!s.empty())
    {
        int a=s.top();
        s.pop();
        cout<<a<<endl;
    }
}

void printInorder(struct treenode* node)  //inorder traversal
{
    if (node == NULL)
        return;

    printInorder(node->left);

    cout << node->i << " ";

    printInorder(node->right);
}




int eval(treenode* root)
{

    if (!root)
        return 0;
    if (!root->left && !root->right)
        return root->i;
    int l = eval(root->left);
    int r = eval(root->right);
    if (root->i==-1)
        return l+r;

    if (root->i==-2)
        return l-r;

    if (root->i==-3)
        return l*r;

    if(root->i==-4)
        return l/r;
    return pow(l,r);
}


int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int T;
        cin>>T;
        while(T--)
        {
            char s[100000];
            cin>>s;
            stack <int> S,s1;
            S=postfix(s);
            while(!S.empty())
            {
                s1.push(S.top());
                S.pop();
            }
            treenode *p=etree(s1);
            cout<<eval(p)<<endl;

        }
    }
}
