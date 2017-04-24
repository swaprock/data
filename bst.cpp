/**********ASSIGNMENT: (GROUP A-2)****************************
Problem Statement: Beginning with an empty binary search tree, Construct binary search tree by 		         inserting the values in the order given. After constructing a binary tree -
i.Insert new node
ii. Find number of nodes in longest path
iii. Minimum data value found in the tree
iv.Change a tree so that the roles of the left and right pointers are swapped at every node
v.Search a value

DIV: A
BATCH: SA-2
ROLL NO: 30
********************************************************************/


#include<iostream>
using namespace std;
	class node
	{
		public:
			int data;
			node *leftchild;
			node *rightchild;
	};
	class bst
	{
		public:
			node *root;
		bst()
		{
			
			root=NULL;
		}
		void insert(int);
		void inorder(node*);
		void preorder(node*);
		void postorder(node*);
		void smallestelement(node*);
		void search(node*,int);
		int height(node*);
		void mirror(node*);

	};
	
	
	void bst::insert(int key)
{
		node *newnode;
		newnode=new node;
		newnode->leftchild=NULL;
		newnode->rightchild=NULL;
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
			cout<<"\n Value already exists.";
			return;
			}
			else if(temp->data>newnode->data)
			{
				if(temp->leftchild==NULL)
				{
					temp->leftchild=newnode;
					cout<<"\nNew node inserted.";
					return;
				}
			temp=temp->leftchild;
			}

			else if(temp->data<newnode->data)
			{
				if(temp->rightchild==NULL)
				{
					temp->rightchild=newnode;
					cout<<"\nNew node inserted.";
					return;
				}
			temp=temp->rightchild;
			}
		}
	}
}

	void bst::inorder(node *t)
	{
		
		if(t!=NULL)
		{
			inorder(t->leftchild);
			cout<<t->data<<"\t";
			inorder(t->rightchild);
		}
		
	}

	void bst::preorder(node *t)
	{
		if(t!=NULL)
		{
			cout<<t->data<<"\t";
			preorder(t->leftchild);
			preorder(t->rightchild);
		}
	}

	void bst::postorder(node *tp)
	{
		if(tp!=NULL)
		{
			postorder(tp->leftchild);
			postorder(tp->rightchild);
			cout<<tp->data<<"\t";
		}
	}

	void bst::smallestelement(node *p)
	{
		if(p!=NULL)
		{
			while(p->leftchild!=NULL)
			{
				p=p->leftchild;
			}
		cout<<"\nSmallest element is "<<p->data;
		}
		else
		{
			cout<<"\nTree is empty.";
		return;
		}
	}	
	
	void bst::search(node *t,int key)
	{
		
			
			if(t!=NULL)
			{
				if(t->data==key)
				{
					cout<<"\nElement is found.";
				}
				else if(t->data>key)
				{
					t=t->leftchild;
					if(t==NULL)
					cout<<"\nElement is not found.";
					else
					search(t,key);
					
				}
				else if(t->data<key)
				{
					t=t->rightchild;
					if(t==NULL)
					cout<<"\nElement is not found.";
					else
					search(t,key);
				}

					
				
			}
			else
			cout<<"\nTree is empty.";
		
	}
		int bst::height(node *temp)
		{
		
			int hleft,hright,h;
			if(temp==NULL)
			{

				return 0;
			}
		
			hleft=height(temp->leftchild);
			hright=height(temp->rightchild);
			if(hright>hleft)
			{
				
				return (hright+1);
			}	
			else
			{
				
				return (hleft+1);
			}
	
		}	

		void bst ::mirror(node *temp)
		{
			node *t;
			
			if(temp==NULL)
			{
				return;	
			}
			else
			{
				mirror(temp->leftchild);
				mirror(temp->rightchild);
				t=temp->leftchild;
				temp->leftchild=temp->rightchild;
				temp->rightchild=t;
			}
			
		}
					
int main()
{
	bst b;
	int val,num;
	int ch;
	int c;
	
	do
	{
		cout<<"\n\t\tMENU";
		cout<<"\n1.Insert";
		cout<<"\n2.Inorder";
		cout<<"\n3.Preorder";
		cout<<"\n4.Postorder";
		cout<<"\n5.Smallest Element.";
		cout<<"\n6.Search.";
		cout<<"\n7.Height of the tree.";
		cout<<"\n8.Mirror.";
		cout<<"\n9.exit";
	
  cout<<"\nEnter choice: ";
cin>>ch;
	switch(ch)
	{
		case 1:
			cout<<"\nEnter val: ";
			cin>>val;
			b.insert(val);
		break;
		case 2:
			if(b.root==NULL)
			cout<<"\nTree is empty";
			else
			b.inorder(b.root);
		break;
		case 3: 
			if(b.root==NULL)
			cout<<"\nTree is empty.";
			else
			b.preorder(b.root);
		break;
		case 4: 
			if(b.root==NULL)
			cout<<"\nTree is empty.";
			else
			b.postorder(b.root);
		break;
		case 5: 
			b.smallestelement(b.root);
		break;
		case 6:	cout<<"\nenter value: ";
			cin>>num;
			b.search(b.root,num);
		break;
		case 7: if(b.root==NULL)
			cout<<"\nTree is empty.";
			else
			{
				int h;
			 h=b.height(b.root);
			cout<<"\nHeight= "<<h;	
			}
		break;
		case 8: if(b.root==NULL)
			cout<"\nTree is empty.";
			else
			{
			b.mirror(b.root);
			b.inorder(b.root);
			}
		break;

		case 9: break;
	}
}while(ch!=9);
return 0;
}
/*****************************OUTPUT********************************
gauri@inspiringminds-Inspiron-11-3148:~$ cd Desktop/
gauri@inspiringminds-Inspiron-11-3148:~/Desktop$ cd submission/
gauri@inspiringminds-Inspiron-11-3148:~/Desktop/submission$ g++ 1.cpp 
gauri@inspiringminds-Inspiron-11-3148:~/Desktop/submission$ ./a.out 

		MENU
1.Insert
2.Inorder
3.Preorder
4.Postorder
5.Smallest Element.
6.Search.
7.Height of the tree.
8.Mirror.
9.exit
Enter choice: 1

Enter val: 23

		MENU
1.Insert
2.Inorder
3.Preorder
4.Postorder
5.Smallest Element.
6.Search.
7.Height of the tree.
8.Mirror.
9.exit
Enter choice: 1

Enter val: 12

New node inserted.
		MENU
1.Insert
2.Inorder
3.Preorder
4.Postorder
5.Smallest Element.
6.Search.
7.Height of the tree.
8.Mirror.
9.exit
Enter choice: 1

Enter val: 56

New node inserted.
		MENU
1.Insert
2.Inorder
3.Preorder
4.Postorder
5.Smallest Element.
6.Search.
7.Height of the tree.
8.Mirror.
9.exit
Enter choice: 1

Enter val: 32

New node inserted.
		MENU
1.Insert
2.Inorder
3.Preorder
4.Postorder
5.Smallest Element.
6.Search.
7.Height of the tree.
8.Mirror.
9.exit
Enter choice: 1

Enter val: 20

New node inserted.
		MENU
1.Insert
2.Inorder
3.Preorder
4.Postorder
5.Smallest Element.
6.Search.
7.Height of the tree.
8.Mirror.
9.exit
Enter choice: 2
12	20	23	32	56	
		MENU
1.Insert
2.Inorder
3.Preorder
4.Postorder
5.Smallest Element.
6.Search.
7.Height of the tree.
8.Mirror.
9.exit
Enter choice: 3
23	12	20	56	32	
		MENU
1.Insert
2.Inorder
3.Preorder
4.Postorder
5.Smallest Element.
6.Search.
7.Height of the tree.
8.Mirror.
9.exit
Enter choice: 4
20	12	32	56	23	
		MENU
1.Insert
2.Inorder
3.Preorder
4.Postorder
5.Smallest Element.
6.Search.
7.Height of the tree.
8.Mirror.
9.exit
Enter choice: 5

Smallest element is 12
		MENU
1.Insert
2.Inorder
3.Preorder
4.Postorder
5.Smallest Element.
6.Search.
7.Height of the tree.
8.Mirror.
9.exit
Enter choice: 6

enter value: 56

Element is found.
		MENU
1.Insert
2.Inorder
3.Preorder
4.Postorder
5.Smallest Element.
6.Search.
7.Height of the tree.
8.Mirror.
9.exit
Enter choice: 7

Height= 3
		MENU
1.Insert
2.Inorder
3.Preorder
4.Postorder
5.Smallest Element.
6.Search.
7.Height of the tree.
8.Mirror.
9.exit
Enter choice: 8
56	32	23	20	12	
		MENU
1.Insert
2.Inorder
3.Preorder
4.Postorder
5.Smallest Element.
6.Search.
7.Height of the tree.
8.Mirror.
9.exit
Enter choice: 9
gauri@inspiringminds-Inspiron-11-3148:~/Desktop/submission$ 
*************************************************************************************/
