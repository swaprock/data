/**********ASSIGNMENT: (GROUP C-15)****************************
Problem Statement: Implement all the functions of a dictionary (ADT) using hashing.
Data: Set of (key, value) pairs, Keys are mapped to values, Keys must be comparable, Keys
must be unique
Standard Operations: Insert(key, value), Find(key), Delete(key).

DIV: A
BATCH: SA-2
ROLL NO: 30
********************************************************************/

#include<iostream>
using namespace std;
#define MAX 10

class HashTab
{
	private:
			struct DCT
			{
				int k;
				int val;
			}a[MAX];
	public:
			int DivMethod(int);
			void init();
			void insert(int,int,int);
			void display();
			void size();
			int search(int);
			void deleteRec(int);
};

void HashTab :: init()
{
	for (int i = 0; i < MAX; ++i)
	{
		a[i].k=-1;
		a[i].val=-1;

	}
}

int HashTab :: DivMethod(int num)
{
	int key;
	key=num%10;
	return key;
}

void HashTab :: insert(int index,int key,int value)
{
	int flag,i,cnt=0;
	flag=0;
	if(a[index].k==-1)
	{
		a[index].k=key;
		a[index].val=value;
	}
	else
	{
		i=0;
		while(i<MAX)
		{
			if(a[i].k!=-1)
				cnt++;
			i++;
		}
		if(cnt==MAX)
			cout<<"\nEntry Table is Full";
	}
	for (int i =index+1; i < MAX; ++i)
	{
		if(a[i].k==-1)
		{
			a[i].k=key;
			a[i].val=value;
			flag=1;
			break;
		}
		for (int i = 0; i < index && flag==0; ++i)
		{
			if(a[i].k==-1)
			{
				a[i].k=key;
				a[i].val=value;
				flag=1;
				break;
			}
		}
	}
}

void HashTab :: display()
{
	int i;
	cout<<"\n Dictionary Table: ";
	cout<<"\n-------------------------------------------------";
	for (int i = 0; i < MAX; ++i)
	{
		cout<<"\n "<<i<<" "<<a[i].k<<" "<<a[i].val;

	}
	cout<<"\n-------------------------------------------------------";
}

void HashTab :: size()
{
	int len=0,i;
	for (int i = 0; i < MAX; ++i)
	{
		if(a[i].k!=-1)
			len++;
	}
	cout<<"\nThe size of dictionary is "<<len;
	
}

int HashTab :: search(int search_key)
{
	int i,j,status=0;
	i=DivMethod(search_key);
	if(a[i].k==search_key)
	{
		cout<<"\n The record is present at location "<<i;
		status=1;
		return i;
	}
	if(a[i].k!=search_key)
	{
		for (int j = i; j< MAX; j++)
		{
			if(a[j].k==search_key)
			{
				cout<<"\n The record is present at location "<<j;
				status=1;
				return j;
			}
		}
		for (int j= 0; j<i;j++)
		{	
			if(a[j].k==search_key)
			{
				cout<<"\n The record is present at location "<<j;
				status=1;
				return j;
			}
			
		}
	}
		if(status== 0)
		{
			cout<<"\n The record is not present.";
			return -99;
		}

}

void HashTab :: deleteRec(int key)
{
	int index;
	index=search(key);
	if(index!=-99)
	{
		a[index].k=-1;
		a[index].val=-1;
		cout<<"\nThe record is deleted.";

	}
}

int main()
{
	int key,value,Hkey,search_key,choice;
	char ans;
	int index;
	HashTab obj;
	cout<<"\nDictionary using Hashing function.";
	obj.init();
	do
	{
		cout<<"\n1.Insert.\n2.Display.\n3.Search.\n4.Deletion.\n5.exit";
		cout<<"\nEnter your choice: ";
		cin>>choice;
		switch(choice)
		{
			case 1: cout<<"\nEnter key: ";
					cin>>key;
					cout<<"\nEnter value: ";
					cin>>value;
					Hkey=obj.DivMethod(key);
					obj.insert(Hkey,key,value);
			break;

			case 2: obj.display();
					obj.size();
			break;

			case 3: cout<<"\nEnter key to be searched: ";
					cin>>search_key;
					index=obj.search(search_key);
			break;

			case 4: cout<<"\nEnter key to be deleted: ";
					cin>> search_key;
					obj.deleteRec(search_key);
			break;
			case 5: break;
		}
	}while(choice!=5);
		}
/*****************OUTPUT**************************
gauri@inspiringminds-Inspiron-11-3148:~$ cd Desktop/
gauri@inspiringminds-Inspiron-11-3148:~/Desktop$ cd submission/
gauri@inspiringminds-Inspiron-11-3148:~/Desktop/submission$ g++ hash.cpp 
gauri@inspiringminds-Inspiron-11-3148:~/Desktop/submission$ ./a.out 

Dictionary using Hashing function.
1.Insert.
2.Display.
3.Search.
4.Deletion.
5.exit
Enter your choice: 1

Enter key: 15

Enter value: 150

1.Insert.
2.Display.
3.Search.
4.Deletion.
5.exit
Enter your choice: 1

Enter key: 18

Enter value: 180

1.Insert.
2.Display.
3.Search.
4.Deletion.
5.exit
Enter your choice: 1

Enter key: 20

Enter value: 200

1.Insert.
2.Display.
3.Search.
4.Deletion.
5.exit
Enter your choice: 1

Enter key: 9

Enter value: 90

1.Insert.
2.Display.
3.Search.
4.Deletion.
5.exit
Enter your choice: 1

Enter key: 4

Enter value: 40

1.Insert.
2.Display.
3.Search.
4.Deletion.
5.exit
Enter your choice: 1

Enter key: 5

Enter value: 50

1.Insert.
2.Display.
3.Search.
4.Deletion.
5.exit
Enter your choice: 2

 Dictionary Table: 
-------------------------------------------------
 0 20 200
 1 20 200
 2 4 40
 3 5 50
 4 4 40
 5 15 150
 6 15 150
 7 4 40
 8 18 180
 9 18 180
-------------------------------------------------------
The size of dictionary is 10
1.Insert.
2.Display.
3.Search.
4.Deletion.
5.exit
Enter your choice: 3

Enter key to be searched: 5

 The record is present at location 3
1.Insert.
2.Display.
3.Search.
4.Deletion.
5.exit
Enter your choice: 4

Enter key to be deleted: 18

 The record is present at location 8
The record is deleted.
1.Insert.
2.Display.
3.Search.
4.Deletion.
5.exit
Enter your choice: 2

 Dictionary Table: 
-------------------------------------------------
 0 20 200
 1 20 200
 2 4 40
 3 5 50
 4 4 40
 5 15 150
 6 15 150
 7 4 40
 8 -1 -1
 9 18 180
-------------------------------------------------------
The size of dictionary is 9
1.Insert.
2.Display.
3.Search.
4.Deletion.
5.exit
Enter your choice: 2

 Dictionary Table: 
-------------------------------------------------
 0 20 200
 1 20 200
 2 4 40
 3 5 50
 4 4 40
 5 15 150
 6 15 150
 7 4 40
 8 -1 -1
 9 18 180
-------------------------------------------------------
The size of dictionary is 9
1.Insert.
2.Display.
3.Search.
4.Deletion.
5.exit
Enter your choice: 5
gauri@inspiringminds-Inspiron-11-3148:~/Desktop/submission$ 

***************************************************************/		
