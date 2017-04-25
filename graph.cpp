#include<iostream>
#include<stdlib.h>
using namespace std;

class node
{      public:
       int data;
       node *next;
};
class graph
{      
       node *head[10];
       int a[10][10];
       int cnt;
       public:
       static int tcnt;
     
       
       void input_adjlist();
       void input_adjmatrix();
       void display_adjlist();
       void display_adjmatrix();
};

int graph::tcnt=0;
void graph::input_adjlist()
{
       int acnt;
       node *temp,*newnode;
       cout<<"\nEnter the no of nodes";
       cin>>cnt;
       for(int i=1;i<=cnt;i++)
       {
              head[i]=new node();
              cout<<"\nEnter the head node";
              cin>>head[i]->data;
              head[i]->next=NULL;
              cout<<"\nEnter the no of adjcent  nodes of "<<i<<" : ";
              cin>>acnt;
              temp=head[i];
                tcnt++;  
              for(int j=1;j<=acnt;j++)
              {
                    newnode=new node();
                    newnode->next=NULL;
                    cout<<"\nEnter the adjcent node of "<<head[i]->data<<":";
                    cin>>newnode->data;
                    temp->next=newnode;
                    temp=temp->next;
                      tcnt++;  
              }
               tcnt++;
       }
      
                     
}



 void graph::input_adjmatrix()
 {
              cout<<"Enter the no of nodes";
              cin>>cnt;
              for(int i=1;i<=cnt;i++)
              {
                            cout<<"\nEnter 1 if connected else 0 "<<i;
                            for(int j=1;j<=cnt;j++)
                            {
                                   cout<<"\nEnter 1 or 0 for : "<<i << "-->" <<j<<" : ";
                                   cin>>a[i][j];
                                     tcnt++;  
                            }
                               tcnt++;    
              }  
              
                           
 }     
 
 
 void graph::display_adjmatrix()
 {            
              cout<<"\nAdjcency matrix is\n";
              for(int i=1;i<=cnt;i++)
              {
                     for(int j=1;j<=cnt;j++)
                     {
                            cout<<"\t"<<a[i][j];
                              tcnt++;  
                            
                     }
                     cout<<endl;
                    tcnt++;  
               }
              
}                                     

void graph::display_adjlist()
{
       node *temp;
      
       for(int i=1;i<=cnt;i++)
       {
            temp=head[i];
            
            while(temp!=NULL)
            {
                 cout<<temp->data<< " -->  ";            
                 temp=temp->next;
                   tcnt++;  
            }
            cout<<"NULL";
            cout<<endl;
              tcnt++;  
       }
       tcnt++;
       
}


int main()
{
       graph g;
       int ch;
       do
       {
       cout<<"\nMENU";
       cout<<"\n1.Using adjcency list";
       cout<<"\n2.Using adjcency matrix";
       cout<<"\n3.Exit";
       cout<<"\nEnter the choice";
       cin>>ch;
       
 
       switch(ch)
       {
              case 1:
                             g.input_adjlist();
                             g.display_adjlist();
                              cout<<"\nValue of runtime counter is"<<graph::tcnt;
                             break;
     
              case 2:
                             g.input_adjmatrix();
                             g.display_adjmatrix();
                              cout<<"\nValue of runtime counter is"<<graph::tcnt;
                             break;
                                           
      
              case 3:
                            return 0;
                            break;
      }
      }while(ch<=3);
     
     
 }     
 
                                                                                                                                                  
       
