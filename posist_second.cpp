#include <bits/stdc++.h>

using namespace std;
int global_id=1;
struct node{
    time_t Datetime=time(0);
    string name,address,mobile,phone;
    float value;
  unsigned int nodenumber;
  unsigned int node_id;
  struct node * parent_ref;
  struct node * child_ref;
  unsigned int child_id;
   string  pass;
   int key;
};

string encrypt(string str,int key)
{
    for(int i=0;str[i]!='\0';i++)
    {
        str[i]=str[i]+key;
    }
    return str;
}
void enter_details(struct node * ptr)
{
    cout<<"Enter Key";
    cin>>ptr->key;
    
    cout<<" enter node password";
    cin>>ptr->pass;
    ptr->pass=encrypt(ptr->pass,ptr->key);
    
   
    cout<<"Enter Name";
    cin>>ptr->name;
    ptr->name=encrypt(ptr->name,ptr->key);
    cout<<"Enter Address";
    cin>>ptr->address;
    ptr->address=encrypt(ptr->address,ptr->key);
    cout<<"Enter Mobile";
    cin>>ptr->mobile;
    ptr->mobile=encrypt(ptr->mobile,ptr->key);
    
    cout<<"Enter Phone";
    cin>>ptr->phone;
    ptr->phone=encrypt(ptr->phone,ptr->key);
    
    cout<<"Enter Value";
    cin>>ptr->value;
    
    
    ptr->nodenumber=global_id;
    global_id++;
    
}
int main()
{
    vector< pair<struct node * ,int> > v_start;
    vector<struct node * > v_end;
    
    char ch='y';
    int option =1;
    while(ch=='y')
    {
        cout<<"Enter option"<<endl;
        cin>>option;
        if(option==1)
        {
            //cout<<"do you want seprate chain or with existing "<<v.size()<<" node exists , 1 for new branch , 2 for existing (with two enter branch no.)";
                struct node * ptr= new node();
                enter_details(ptr);
                v_start.push_back(make_pair(ptr,1));
                v_end.push_back(ptr);
                ptr->node_id=1001;
                cout<<" Your node _id is "<<ptr->node_id<<endl;
                ptr->parent_ref=NULL;ptr->child_ref=NULL;ptr->child_id=-1;
        }
        else if(option==2)
        {
                struct node * ptr=new node();
                
                enter_details(ptr);
                v_start.push_back(make_pair(ptr,1));
                v_end.push_back(ptr);
                ptr->node_id=((v_start.size()+1)*1000)+1;
                
                cout<<" Your node _id is "<<ptr->node_id<<endl;
                ptr->parent_ref=NULL;ptr->child_ref=NULL;ptr->child_id=-1;
        }
        else if(option==3)
        {
            int ch_no;
            cout<<"Enter the set no for new node from 0 to"<<v_start.size()-1<<endl;
            cin>>ch_no;
            struct node * ptr= new node();
            
            enter_details(ptr);
            struct node * father=v_end[ch_no];
            v_start[ch_no].second++;
            
            ptr->node_id=((ch_no+1)*1000)+v_start[ch_no].second;
            
                cout<<" Your node _id is "<<ptr->node_id<<endl;
            father->child_ref=ptr;
            father->child_id=ptr->node_id;
            ptr->parent_ref=father;ptr->child_ref=NULL;ptr->child_id=-1;
            
            v_end[ch_no]=ptr;
            
        }
        // 4 already encrypted using key and password and function encrypt
        else if(option==5)
        {
            cout<<"Checking authentication"<<endl;
            string user_pass;
            int user_key;
            int user_node_id;
            cout<<" Enter Node Id (Unique id)"<<endl;
            cin>>user_node_id;
            cout<<" Enter pass"<<endl;
            cin>>user_pass;
            cout<<" Enter key"<<endl;
            cin>>user_key;
            
            struct node * ptr;
            int row=(user_node_id/1000)-1;
            ptr=v_start[row].first;
            int col=user_node_id%10;
            col--;
            while(col)
            {
                ptr=ptr->child_ref;
                col--;
            }
            if(encrypt(user_pass,ptr->key)==ptr->pass && user_key==ptr->key)
            {
                cout<<" Welcome Admin "<<endl;
                
            }
            else
            {
                cout<<" Sorry unauthorized accesss"<<endl;
            }
            
            
        }
        else if(option==6)
        {
            cout<<"Checking authentication"<<endl;
            string user_pass;
            int user_key;
            int user_node_id;
            cout<<" Enter Node Id (Unique id)";
            cin>>user_node_id;
            cout<<" Enter pass";
            cin>>user_pass;
            cout<<" Enter key";
            cin>>user_key;
            
            struct node * ptr;
            int row=(user_node_id/1000)-1;
            ptr=v_start[row].first;
            int col=user_node_id%10;
            col--;
            while(col)
            {
                ptr=ptr->child_ref;
                col--;
            }
            if(encrypt(user_pass,ptr->key)==ptr->pass && user_key==ptr->key)
            {
                cout<<" Welcome Admin deleting your node "<<endl;
                struct node * father=ptr->parent_ref;
                struct node * son = ptr->child_ref;
                if(father==NULL)
                {
                    v_start[row].first=son;
                    son->parent_ref=NULL;
                    v_start[row].second--;
                    
                }
                else
                {
                    father->child_ref=son;
                    father->child_id=son->node_id;
                    son->parent_ref=father;
                }
            }
            else
            {
                cout<<" Sorry unauthorized accesss"<<endl;
            }
        }
        else if(option==7)
        {
            int user_node_id,parent_node_id;
            cout<<" Enter Node Id (Unique id)";
            cin>>user_node_id;
            
            cout<<" Enter Parent Node Id (Unique id)";
            cin>>parent_node_id;
            
            struct node * ptr,* ptr1;
            int row=(user_node_id/1000)-1;
            ptr=v_start[row].first;
            int col=user_node_id%10;
            col--;
            while(col)
            {
                ptr=ptr->child_ref;
                col--;
            }
            
            row=(parent_node_id/1000)-1;
            ptr1=v_start[row].first;
             col=user_node_id%10;
            col--;
            while(col)
            {
                ptr1=ptr1->child_ref;
                col--;
            }
            ptr1->child_ref=ptr;
            ptr1->child_id=ptr->node_id;
            ptr->parent_ref=ptr1;
            
        }
        else if(option==8)
        {
            int max_main=0;
            for(int i=0;i<v_start.size();i++)
            {
                max_main=max(max_main,v_start[i].second);
            }
        }
        
        cout<<"continue y/n";
        cin>>ch;
    }
    
   return 0;
}

