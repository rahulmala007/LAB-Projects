#include<bits/stdc++.h>
using namespace std;
struct tree 
{
    long long int i;
    tree * left,* right,* parent;
};

long long int prec(char c) 
{ 
    if(c == '^') 
    return 3; 
    else if(c == '*' || c == '/') 
    return 2; 
    else if(c == '+' || c == '-') 
    return 1; 
    else if(c=='$')
	return 4;
    return -1; 
} 

int isOperator(char c)
{
    if(c=='+'||c=='-'||c=='*'||c=='/')
    return 1;
    if(c=='^'||c=='$')
    return 2;
    return 0;
}

long long int opToInt(char c)
{
    switch(c)
    {
        case '+': return -1;
        case '-': return -2;
        case '*': return -3;
        case '/': return -4;
        case '^': return -5;
	    case '$': return -2;
    }
}

vector<long long int >Post(string s)
{
    vector<long long int>v;
    stack<long long int >st;
    long long int  f=0,a;
    st.push('N');
    for(long long int i=0;i<s.length();i++)
    {
        if(s[i]>='0'&&s[i]<='9')
        {
            if(f)
            {
                v[v.size()-1]=v[v.size()-1]*10+s[i]-'0';
            }
            else 
            {
                v.push_back(s[i]-'0');
                f=1;
            }
        }

        else 
        {
            f=0;
            if(s[i]=='(')
                st.push('(');
            else if(s[i]==')')
            {
                while(st.top()!='N'&&st.top()!='(')
                {
                    char c=st.top();
                    st.pop();
                    v.push_back(opToInt(c));
                }
                if(st.top()=='(')
                    st.pop();   
            }
            else if(isOperator(s[i])==1)
            {
                while(st.top()!='N'&&st.top()!='('&&prec(s[i])<=prec(st.top()))
                {
                    char c=st.top();
                    st.pop();
                    v.push_back(opToInt(c));
                }
                st.push(s[i]);
            }
            else if(isOperator(s[i])==2)
            {
                while(st.top()!='N'&&st.top()!='('&&prec(s[i])<prec(st.top()))
                {
                    char c=st.top();
                    st.pop();
                    v.push_back(opToInt(c));
                }
                st.push(s[i]);
            }
        }
    }
    while(st.top()!='N')
        {
            char c=st.top();
            st.pop();
            v.push_back(opToInt(c));
        }
    return v;
}

tree * newNode(long long v)
{
    tree * temp=new tree;
    temp->left = NULL;
    temp->right = NULL; 
    temp->i = v; 
    return temp; 
}

tree * etree(vector<long long int > v)
{
    tree *t,*t1,*t2;
    stack<tree *> st;
    for(int i=0;i<v.size();i++)
    {
        if(v[i]>=0)
        {
            t=newNode(v[i]);
            st.push(t);
        }
        else
        {
            t=newNode(v[i]);
            t1=st.top();
            st.pop();
            t2=st.top();
            st.pop();
            if(1)
            {t->right=t1;
            t->left=t2;}
            st.push(t);
        }
    }
    return t;
}

long long eval(tree* root)  
{  
    if (!root)  
        return 0;  
    if (!root->left && !root->right)  
        return root->i;  
    long long l = eval(root->left);  
    long long r = eval(root->right);  
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
    long long int  test;
    cin>>test;
    while(test--)
    {
        long long int q;
        cin>>q;
        while(q--)
        {
		    int u=1;
            string s;
            cin>>s;
		for(int i=0;i<s.length();i++)
		{
			if(u && s[i]=='-')
			{
				s[i]='$';
				s.insert(i,"0");
			}
			if(isOperator(s[i])||s[i]=='(')
				u=1;
			else u=0;
		}
            vector <long long > S;

            S=Post(s);
            tree *p=etree(S);
            cout<<eval(p)<<endl;
        }
    }
}
