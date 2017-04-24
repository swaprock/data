/**********ASSIGNMENT: (GROUP B-10)****************************
Problem Statement: For given expression eg. a-b*c-d/e+f construct inorder sequence and 
		traverse it using postorder traversal(non recursive).

DIV: A
BATCH: SA-2
ROLL NO: 30
********************************************************************/

#include<iostream>
#include<stdlib.h>
using namespace std;

class node
{
	public:
	char data;
	node *left;
	node *right;
};

class stack
{
	public:
		int top;
		node *s[20];
		stack()
		{
			top=-1;

		}
		void push(node*);
		node *pop();
		int empty();
		int full();
		void display();
};

class etree
{
	stack st;

	public:
		node *root;
		etree()
		{
			root=NULL;
		}
		void make_etree();
		void infix(node*);
		void prefix(node*);
		void postfix(node*);
};

void stack::push(node *temp)
{
	if(!full())
	{
		top++;
		s[top]=temp;
	}
}

node *stack::pop()
{
	node *t=new node();
	if(!empty())
	{
		t=s[top];
		top--;
		return(t);
	}
	else
		top=-1;
		return(NULL);
}

int stack::empty()
{
	if(top==-1)
	{
		cout<<"\nStack is empty"<<endl;
		return(1);
	}
	else
		return(0);
}

int stack::full()
{
	if(top==19)
	{
		cout<<"\nStack is full"<<endl;
		return(1);
	}
	else
		return(0);
}

void stack::display()
{
	if(top==-1)
	{
		cout<<"\nStack is empty";
		return;
	}
	for(int i=top;i>=0;i--)
	{
		cout<<s[i]<<"\t";
	}
};

void etree::infix(node *t)
{
	if(t!=NULL)
	{
		infix(t->left);
		cout<<"  "<<t->data;
		infix(t->right);
	}
}

void etree::prefix(node *t)
{
	if(t!=NULL)
	{
		cout<<"  "<<t->data;
		prefix(t->left);
		prefix(t->right);
	}
}

void etree::postfix(node *t)
{
	if(t!=NULL)
	{
		postfix(t->left);
		postfix(t->right);
		cout<<"  "<<t->data;
	}
}

void etree::make_etree()
{
	node *r,*l,*t;
	char a[20];
	cout<<"\nEnter postfix expression:";
	cin>>a;
	for(int i=0;a[i]!='\0';i++)
	{
		if(a[i]=='+'||a[i]=='-'||a[i]=='*'||a[i]=='/'||a[i]=='^')
		{
			r=st.pop();
			l=st.pop();
			t=new node();
			t->data=a[i];
			t->right=r;
			t->left=l;
			st.push(t);
		}
		else
		{
			t=new node();
			t->data=a[i];
			t->left=NULL;
			t->right=NULL;
			st.push(t);
		}
	}
	root=t;
}

int main()
{
	int ch;
	node *ele;
	stack s;
	etree e;
	while(1)
	{
		cout<<"\nOPERATIONS"<<endl;
		cout<<"\n1.Make expression Tree\n2.Infix Expression\n3.Prefix Expression\n4.Postfix Expression\n5.Exit"<<endl;
		cout<<"\nEnter your choice:"<<endl;
		cin>>ch;
		switch(ch)
		{
			case 1:	e.make_etree();
				break;

			case 2:	e.infix(e.root);
				break;

			case 3:	e.prefix(e.root);
				break;

			case 4:	e.postfix(e.root);
				break;

			case 5: exit(1);
				break;
		}
	}
return 0;
}
/****************OUTPUT*****************************
gauri@inspiringminds-Inspiron-11-3148:~$ cd Desktop/
gauri@inspiringminds-Inspiron-11-3148:~/Desktop$ cd submission/
gauri@inspiringminds-Inspiron-11-3148:~/Desktop/submission$ g++ expression.cpp 
gauri@inspiringminds-Inspiron-11-3148:~/Desktop/submission$ ./a.out 

OPERATIONS

1.Make expression Tree
2.Infix Expression
3.Prefix Expression
4.Postfix Expression
5.Exit

Enter your choice:
1

Enter postfix expression:ab+

OPERATIONS

1.Make expression Tree
2.Infix Expression
3.Prefix Expression
4.Postfix Expression
5.Exit

Enter your choice:
2
  a  +  b
OPERATIONS

1.Make expression Tree
2.Infix Expression
3.Prefix Expression
4.Postfix Expression
5.Exit

Enter your choice:
3
  +  a  b
OPERATIONS

1.Make expression Tree
2.Infix Expression
3.Prefix Expression
4.Postfix Expression
5.Exit

Enter your choice:
4
  a  b  +
OPERATIONS

1.Make expression Tree
2.Infix Expression
3.Prefix Expression
4.Postfix Expression
5.Exit

Enter your choice:
5
gauri@inspiringminds-Inspiron-11-3148:~/Desktop/submission$ 
*****************************************************************/
