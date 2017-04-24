/**********ASSIGNMENT NO:(GROUP A-6)****************************
Problem Statement:Convert given binary tree into threaded binary tree. Analyze time and space      	               complexity of the algorithm.
DIV: A
BATCH: SA-2
ROLL NO: 30
********************************************************************/

#include<iostream>
#include<cstdlib>
using namespace std;

class node
{
	public:
		int data;
		node *left;
		node *right;
		bool rbit,lbit;
};

class Thread
{
		int count;
		node *a[50];

	public:

		node *root,*dummy;
		Thread()
		{
			root=NULL;
			count=0;
		}
		void insert(int);
		void array(node*);
		void convert(node*);
		node *insuc(node*);
		void tbt_disp();
		void inorder(node*);
};

//Insertion of nodes
void Thread::insert(int key)
{
	node *newnode;
	newnode=new node();
	newnode->left=NULL;
	newnode->right=NULL;
	newnode->data=key;
	if(root==NULL)
	{
		root=newnode;
		return;
	}
	else
	{
		node *temp;
		temp=root;
		while(temp!=NULL)
		{
			if(temp->data==newnode->data)
			{
				cout<<"\nNode already exist.";
				return;
			}
			else if(temp->data>newnode->data)
			{
				if(temp->left==NULL)
				{
					temp->left=newnode;
					cout<<"\nNode added at left..";
					return;	
				}	
				temp=temp->left;
			}
			else if(temp->data<newnode->data)
			{
				if(temp->right==NULL)
				{
					temp->right=newnode;
					cout<<"\nNode added at right..";
					return;
				}	
				temp=temp->right;
			}
		}
	}
}

//Inorder Traversal	
void Thread::inorder(node *temp)
{
	if(temp!=NULL)
	{
		inorder(temp->left);
		cout<<temp->data<<" ";
		inorder(temp->right);
	}
}

//Display Tree	
void Thread::array(node *temp)
{

	if(temp!=NULL)
	{
		array(temp->left);
		a[count++]=temp;
		if(temp->left!=NULL)
        	{
        		temp->lbit=1;
                }
        	else
        	{
                        temp->lbit=0;
                }
        	if (temp->right!=NULL)
        	{
        		temp->rbit=1;
                }
        	else
        	{
                        temp->rbit=0;
                }
		array(temp->right);
	}
}

//Converting Binary Tree into Threaded Binary Tree
void Thread::convert(node *temp)
{
	int i;

	dummy=new node();
	dummy->data=99;
	dummy->lbit=1;
	dummy->rbit=1;
	dummy->left=temp;
	dummy->right=dummy;
	
	
	if(a[0]->rbit==0)
		a[0]->right=a[1];

	a[0]->left=dummy;


	if(a[count-1]->lbit==0)
		a[count-1]->left=a[count-2];

	a[count-1]->right=dummy;

	for(i=1;i<count-1;i++)
	{		
		if(a[i]->lbit==0)
			a[i]->left=a[i-1];
		if(a[i]->rbit==0)
			a[i]->right=a[i+1];
	}
//	root=dummy;	
}

//Traversing Of Successor
node* Thread::insuc(node *temp)
{
	if(temp->rbit==1)
	{
		temp=temp->right;
		while(temp->lbit==1)
		{
			temp=temp->left;
		}
		return(temp);
	}
	else
		return(temp->right);
}

//Display Of Thread Binary Tree
void Thread::tbt_disp()
{
	node *temp;
	temp=dummy->left;
	cout<<"\n";
	while(temp->lbit==1)
		temp=temp->left;
	while(temp!=dummy)
	{
		cout<<" "<<temp->data;
		temp=insuc(temp);
	}
}
	
//Main method
int main()
{
	Thread t;
	int ch,ele,k;
	do
	{
		cout<<"\nMENU\n1.Insert\n2.Threaded Binary Tree\n3.Exit";
		cout<<"\nEnter your choice: ";
		cin>>ch;
	switch(ch)
	{
		case 1:	cout<<"\nEnter value to be inserted: ";
			cin>>ele;
			t.insert(ele);
			break;

		
		case 2:	cout<<"\nThreaded Binary Tree is ";
			t.array(t.root);
			t.convert(t.root);
			t.tbt_disp();
			cout<<endl;
			break;

		case 3:exit(0);
	}		
	}while(ch<=4);
return 0;
}

/******************OUTPUT*************************************
gauri@inspiringminds-Inspiron-11-3148:~$ cd Desktop/
gauri@inspiringminds-Inspiron-11-3148:~/Desktop$ cd submission/
gauri@inspiringminds-Inspiron-11-3148:~/Desktop/submission$ g++ 3.cpp 
gauri@inspiringminds-Inspiron-11-3148:~/Desktop/submission$ ./a.out 

MENU
1.Insert
2.Threaded Binary Tree
3.Exit
Enter your choice: 1

Enter value to be inserted: 11

MENU
1.Insert
2.Threaded Binary Tree
3.Exit
Enter your choice: 1

Enter value to be inserted: 21

Node added at right..
MENU
1.Insert
2.Threaded Binary Tree
3.Exit
Enter your choice: 1

Enter value to be inserted: 23

Node added at right..
MENU
1.Insert
2.Threaded Binary Tree
3.Exit
Enter your choice: 1

Enter value to be inserted: 45

Node added at right..
MENU
1.Insert
2.Threaded Binary Tree
3.Exit
Enter your choice: 1

Enter value to be inserted: 23

Node already exist.
MENU
1.Insert
2.Threaded Binary Tree
3.Exit
Enter your choice: 1

Enter value to be inserted: 10

Node added at left..
MENU
1.Insert
2.Threaded Binary Tree
3.Exit
Enter your choice: 1

Enter value to be inserted: 19

Node added at left..
MENU
1.Insert
2.Threaded Binary Tree
3.Exit
Enter your choice: 1

Enter value to be inserted: 8

Node added at left..
MENU
1.Insert
2.Threaded Binary Tree
3.Exit
Enter your choice: 1

Enter value to be inserted: 45

Node already exist.
MENU
1.Insert
2.Threaded Binary Tree
3.Exit
Enter your choice: 1

Enter value to be inserted: 32

Node added at left..
MENU
1.Insert
2.Threaded Binary Tree
3.Exit
Enter your choice: 2

Threaded Binary Tree is 
 8 10 11 19 21 23 32 45

MENU
1.Insert
2.Threaded Binary Tree
3.Exit
Enter your choice: 3
gauri@inspiringminds-Inspiron-11-3148:~/Desktop/submission$
***************************************************************/
