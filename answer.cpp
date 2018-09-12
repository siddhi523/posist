
 


#include <bits/stdc++.h>
using namespace std;

void input(void);
class TimeStamp{
    
    public:
    
    string date_time;
    
    void put(string date_time1)
    {
        date_time=date_time1;
    }
    
    string getDateTime()
    {
        return date_time;
    }
    
};

struct Data{
  
 int id; 
 string name;
 float value;
 
  unordered_set<string> stringSet; 
  stringSet.insert(name); 
    stringSet.insert(id); 
    stringSet.insert(value); 
};

struct node{
  
  TimeStamp Datetime;
  struct Data* data;
  unsigned int NodeNumber;
  unsigned int NodeId;
  struct node *ref;
  vector<struct node*> child;
};

map<int,struct node*> HashValue;

static int number=0;
string datetime()
{
     time_t tt;
    struct tm * ti;
    time (&tt);
    ti = localtime(&tt);
 
    return asctime(ti);
}

unsigned int unique()
{
    return rand();
}

string encrypt(string value){
    char key ='H';
    string output = value;
    
    for (int i = 0; i < value.size(); i++)
        output[i] = value[i] ^ key;
    
    return output;
}

void input(int head,vector<struct node*> headnodes)
{
   
    int size = headnodes.size();
    string name,password,algo="mysecretalgo";
    float value;
    int id;
    cout<<"NAME:\n  Id:\n  Value :\n Password :<<endl";
    
    cin>>name>>id>>value>>password;
    
    struct node *node1 = new node();
    struct Data *data1=new Data();
    string date = datetime();
    TimeStamp time;
    time.put(date);
    node1->Datetime=time;
    data1->name=encrypt(name);
    data1->id=encrypt(id);
    data1->value=encrypt(value);
    data1->password=encrypt(password);
    data1->algo=encrypt(algo);
    
    node1->data=data1;
    node1->NodeNumber=++number;
    node1->NodeId=unique();
    
    
    if(head==-1)
    {
        node1->ref=NULL;
        headnodes.push_back(node1);
    }
    else
    {
        HashValue[head]->child.push_back(node1);
        node1->ref=HashValue[head];
    
    }
    
    HashValue[number]=node1;
    return;
}

bool printverify(string password,string algo)
{
        string password1=encrypt(password);
        string algo1=encrypt("mysecretalgo");
        
        map<int,struct node*>::iterator it=HashValue.begin();
        int flag=0;
        
        for(;it!=HashValue.end(); it++)
        {
            if(it->second->data->password==password1 && it->second->data->algo==algo1)
            {
                flag=1;
                
               
                cout<<encrypt(it->second->data->name)<<endl;
                cout<<encrypt(it->second->data->id)<<endl;
                cout<<encrypt(it->second->data->value)<<endl;
                
                break;
            }
        }
        
        if(flag==1)
        return true;
        
        return false;
}

int c=0;

void longest(struct node* root,int &ma)
{
    	if(root==NULL)
            return;
    
 		   c++;
    
    		for(int i=0; i<root->child.size(); i++)
            {
                longest(root->child[i],ma);
            }
    
    	if(c>ma)
            ma=c;
}

void levels(struct node* root,int c,int &ma)
{
    	if(root==NULL)
            return;
      
    		for(int i=0; i<root->child.size(); i++)
            {
                levels(root->child[i],c+1,ma);
            }
    
    	if(c>ma)
            ma=c;
}

void merge(struct node* first,struct node * second)
{
    if (!first) 
        return second; 
    if (!second) 
        return first; 
    first->data += second->data; 
    first->left = merge(first->left, second->left); 
    first->right = merge(first->right, second->right); 
    return t1; 
}

int main()
{
    vector<struct node *> headnodes;
    cout<<"1 :  create first node\n";
    cout<<"2 :  create multi set of first node\n";
    cout<<"3 :  create new node to any set of node\n";
    cout<<"4 : create an algo to encrypt data\n";
    cout<<"5 : verify owner with key\n";
    cout<<"6 : break any node\n";
    cout<<"7 : change owner of node\n";
    cout<<"8 : longest chain of main node\n";
    cout<<"9 : longest chain of sub node among set of node\n";
    cout<<"10 : merge two sets\n";
    
    
    while(1)
    {
     
        int num;
        cin>>num;
        
        
        if(num==11)
        break;
     
     
     
        if(num==1)
        {
            cout<<"hi";
            input(-1,headnodes);
        }
     
        if(num==2)
        {
            cout<<"enter no. of sets\n";
            int sets;
            cin>>sets;
            
            while(sets--)
            {
                input(-1,headnodes);
            }
        }
        
        if(num==3)
        {
            int nodenum;
            cout<<"enter node number";
            cin>>nodenum;
            
            input(nodenum,headnodes);
        }
        
        if(num==4)
        {
            string password,algo;
            cout<<"Enter password and algo key";
            
            bool k=printverify(password,algo);
        }
        
        if(num==5)
        {
            string password,algo;
            cout<<"Enter password and algo key";
            
            bool k=printverify(password,algo);
            
            if(k)
            cout<<"verified";
            else
            cout<<"not verified";
            
            cout<<endl;
        }
        
        if(num==6)
        {
            int nodenum;
            cout<<"enter node number";
            cin>>nodenum;
            HashValue.erase(nodenum);
        }
        
        if(num==7)
        {
            int nodenum1,nodenum2;
            cout<<"enter node number of first node and new owner";
            cin>>nodenum1>>nodenum2;
            
            struct node* first=HashValue[nodenum1];
            struct node* newowner=HashValue[nodenum2];
            
            first->ref->child.erase(first->child.begin()+nodenum1);
            newowner->child.push_back(first);
            first->ref=newowner;
        }
        
        if(num==8)
        {
            int ma=0;
            c=0;
            
            for(int i=0; i<headnodes.size(); i++)
            	longest(headnodes[i],ma);
            
            cout<<ma<<endl;
        }
    
    	if(num==9)
        {
            int ma=0;
            
            for(int i=0; i<headnodes.size(); i++)
            	levels(headnodes[i],0,ma);
            
            cout<<ma<<endl;
        }
        
        if(num==10)
        {
            int nodenum1,nodenum2;
            cout<<"enter nodenumbers of 1 & 2";
            cin>>nodenum1>>nodenum2;
            
            struct node* first=HashValue[nodenum1];
            struct node* second=HashValue[nodenum2];
            
            merge(first,second,headnodes);
        }
     
    }
    
   return 0;
}
