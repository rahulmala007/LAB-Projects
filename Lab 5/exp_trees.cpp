#include <bits/stdc++.h>
using namespace std;
map<string,long long > mp;
map<string,long long >::iterator it;

long long  pow(long long  base,long long  power){
    if(power<0)
        return 0;
  long long  res=1;
  for(int i=0;i<power;i++)
    res*=base;
  return res;
}

struct et
{
    string value;
    et* left, *right;
};

bool isOperator(string c)
{
    if (c == "+" || c == "-" ||
            c == "*" || c == "/" ||
            c == "^")
        return true;
    return false;
}

bool isOperator(char c)
{
    if (c == '+' || c == '-' || c == '*' || c == '/' || c == '^')
        return true;
    else return false;
}

void postorder(et *t)
{
    if(t)
    {
        postorder(t->left);
        postorder(t->right);
        cout<<t->value<<" ";
    }
}

et* newNode(string v)
{
    et *temp = new et;
    temp->left = temp->right = NULL ;
    temp->value = v;
    return temp;
};

et* constructTree(vector<string> postfix)
{
    stack<et *> st;
    et *t, *t1, *t2;

    for (int i=0; i<postfix.size() ; i++)
    {
        if (!isOperator(postfix[i]))
        {
            t = newNode(postfix[i]);
            st.push(t);
        }
        else
        {
            t = newNode(postfix[i]);

            t1 = st.top();
            st.pop();
            t2 = st.top();
            st.pop();

            t->right = t1;
            t->left = t2;

            st.push(t);
        }
    }

    t = st.top();
    st.pop();

    return t;
}

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

long long  eval(et* root)
{
    if (!root)
        return 0;

    if (!root->left && !root->right){
        bool is_number=true;
        for(int i=0;i<root->value.size();i++)
        {
            if(root->value[i]>='0'&&root->value[i]<='9')
                continue;
            else{
                is_number=false;
                break;
            }
        }
        if(is_number)
            return stoi (root->value);
        else
        {
            it=mp.find(root->value);
            return it->second;
        }
    }

    long long  l = eval(root->left);

    long long  r= eval(root->right);

    if (root->value=="+")
        return l+r;

    if (root->value=="-")
        return l-r;

    if (root->value=="*")
        return l*r;

    if (root->value=="/")
      return l/r;

    return pow(l,r);
}

int cnt=0;

bool cant_be_evaluated=false;

long long  evaluate_value(string s){
    stack<char> st;
    st.push('N');
    int l = s.length();
    vector<string> ns;
    for(int i = 0; i < l; i++)
    {
        if(s[i] >= '0' && s[i] <= '9')
        {
          int j=i;
          string str;
          while(( j<s.length() )&&(s[j] >= '0' && s[j] <= '9')){
            str.push_back(s[j]);
            j++;
          }
          i=j-1;
          ns.push_back(str);
          if(cnt)
                goto label;
          continue;
        }

        else if((s[i]>='a'&&s[i]<='z')||(s[i]>='A'&&s[i]<='Z')){
            int j=i;
            string var;
          while((s[j]>='a'&&s[j]<='z')||(s[j]>='A'&&s[j]<='Z')){
            var.push_back(s[j]);
            j++;
          }
          i=j-1;
          ns.push_back(var);
          if(cnt)
                goto label;
          continue;
        }
        else if(s[i] == ')')
        {
            label:
            while(st.top() != 'N' && st.top() != '(')
            {
                char c = st.top();
                st.pop();
                string str="";
                str+=c;
               ns.push_back(str);
            }
            if(st.top() == '(')
                st.pop();
            if(cnt)
                cnt--;
            if(cnt)
                goto label;
            else continue;
        }

        else if(s[i] == '(')

        st.push('(');

        else{
            if(s[i]=='-'&&(i==0||s[i-1]=='('||isOperator(s[i-1]))){
                cnt++;
                st.push('(');
                ns.push_back("0");
               }
            while(st.top() != 'N' && prec(s[i]) <= prec(st.top()))
            {
              if(s[i]=='^'&&st.top()=='^')
                break;
                char c = st.top();
                st.pop();
                string str="";
                str+=c;
                ns.push_back(str);
            }
            st.push(s[i]);
        }

    }
    while(st.top() != 'N')
    {
        char c = st.top();
        st.pop();
        string str="";
        str+=c;
        ns.push_back(str);
    }

    for(int i=0;i<ns.size();i++){
        if(isOperator(ns[i]))
            continue;
        bool is_number=true;
        for(int j=0;j<ns[i].size();j++)
        {
            if(ns[i][j]>='0'&&ns[i][j]<='9')
                continue;
            else{
                is_number=false;
                break;
            }
        }
        if(!is_number){
            it=mp.find(ns[i]);
            if(it==mp.end())
            {
                cant_be_evaluated=true;
                return 0;
            }
        }
    }

    et* r = constructTree(ns);

    long long  result=eval(r);
    return result;
}

void infixToPostfix(string s)
{


    bool is_assignment=false;
    int i;
    for(i=0;i<s.length();i++)
    {
        if(s[i]=='='){
            is_assignment=true;
            break;
        }
    }
    if(is_assignment){
        long long  value=evaluate_value(s.substr(i+1,s.length()-i-2));
        string variable=s.substr(1,i-1);
        if(cant_be_evaluated){
            cout<<"CANT BE EVALUATED\n";
            cant_be_evaluated=false;
        }
        else{
            it=mp.find(variable);
            if(it==mp.end())
                mp.insert({variable,value});
            else
                it->second=value;
        }
        return;
    }


    std::stack<char> st;
    st.push('N');
    int l = s.length();
    vector<string> ns;
    for(int i = 0; i < l; i++)
    {
        if(s[i] >= '0' && s[i] <= '9')
        {
          int j=i;
          string str;
          while(( j<s.length() )&&(s[j] >= '0' && s[j] <= '9')){
            str.push_back(s[j]);
            j++;
          }
          i=j-1;
          ns.push_back(str);
          if(cnt)
                goto label;
          continue;
        }

        else if((s[i]>='a'&&s[i]<='z')||(s[i]>='A'&&s[i]<='Z')){
            int j=i;
            string var;
          while((s[j]>='a'&&s[j]<='z')||(s[j]>='A'&&s[j]<='Z')){
            var.push_back(s[j]);
            j++;
          }
          i=j-1;
          ns.push_back(var);
          if(cnt)
                goto label;
          continue;
        }
        else if(s[i] == ')')
        {
            label:
            while(st.top() != 'N' && st.top() != '(')
            {
                char c = st.top();
                st.pop();
                string str="";
                str+=c;
               ns.push_back(str);
            }
            if(st.top() == '(')
                st.pop();
            if(cnt)
                cnt--;
            if(cnt)
                goto label;
            else continue;
        }

        else if(s[i] == '(')

        st.push('(');

        else{
            if(s[i]=='-'&&(i==0||s[i-1]=='('||isOperator(s[i-1]))){
                cnt++;
                st.push('(');
                ns.push_back("0");
               }
            while(st.top() != 'N' && prec(s[i]) <= prec(st.top()))
            {
              if(s[i]=='^'&&st.top()=='^')
                break;
                char c = st.top();
                st.pop();
                string str="";
                str+=c;
                ns.push_back(str);
            }
            st.push(s[i]);
        }

    }
    while(st.top() != 'N')
    {
        char c = st.top();
        st.pop();
        string str="";
        str+=c;
        ns.push_back(str);
    }

    for(int i=0;i<ns.size();i++){
        if(isOperator(ns[i]))
            continue;
        bool is_number=true;
        for(int j=0;j<ns[i].size();j++)
        {
            if(ns[i][j]>='0'&&ns[i][j]<='9')
                continue;
            else{
                is_number=false;
                break;
            }
        }
        if(!is_number){
            it=mp.find(ns[i]);
            if(it==mp.end())
            {
                cout<<"CANT BE EVALUATED\n";
                return;
            }
        }
    }

    et* r = constructTree(ns);

    long long  result=eval(r);
    cout<<result<<"\n";
}



int main()
{
  long long  n;
  cin>>n;
  cin.ignore();
  while(n--){
    long long  rows;
    cin>>rows;
    cin.ignore();
    while(rows--){
      string str="(",str2;
      getline(cin,str2);
      str+=str2;
      str+=")";
      infixToPostfix(str);
    }
    mp.clear();
  }
    return 0;
}
