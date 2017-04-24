
/**********ASSIGNMENT: (GROUP E-20)****************************
Problem Statement:  To create ADT that implements the set concepts
 1.add(new element) place a value into the set
 2. remove(element)
 3.contains(element) return true if  element is in collection
 4.size() return number of values in collection iterator() return an iterator
 used to loop over collection.
 5. intersection
 6.union
 7.diff bet 2 sets
 8. subset

DIV: A
BATCH: SA-2
ROLL NO: 30
********************************************************************/
#include<iostream>
using namespace std;
class set
{
  int a[10];
  int i,j,pos;
	public:

   	void intersection(set o2)
   	{
      	int n1=pos,n2=o2.pos,ans;
       	cout<<"\n intersection is ";
      	for(i=0;i<n1;i++)
      	{
	 ans=o2.contains(a[i]);
	 if(ans==1)
	 {
	  cout<<a[i]<<"\t";
	 }
     	}

   	}
       void unionSet(set o2)
       {
      set o3;
      int n1=pos,n2=o2.pos,z,ans;
      cout<<"\n union is ";
      	for(i=0;i<n1;i++)
      	{
      	o3.add(a[i]);
      	}
	for(i=0;i<n2;i++)  //o2
	{
	 ans=o3.contains(o2.a[i]);
	 if(ans==0)
	   o3.add(o2.a[i]);
	 }

	cout<<"union is ";
	o3.disp();
   }

    void DiffSet(set o2)
   {
      set o3;
      int n1=pos,n2=o2.pos,z,ans;
       cout<<"\n Difference is ";
	for(i=0;i<n2;i++)  //o2
	{
	 ans=o2.contains(a[i]);
	 if(ans==0)
	   o3.add(a[i]);
	 }

	cout<<"\ndifference is ";
	o3.disp();
   }

     void SubSet(set o2)
   {
      set o3;
      int n1=pos,n2=o2.pos,z,ans;
       cout<<"\n Subset is ";
	for(i=0,z=0;i<n1;i++)  //o2
	{
	 ans=o2.contains(a[i]);
	 if(ans==0)
	 {
	    z=1;
	    break;
	  }
	 }
	  if(z==0)
	cout<<"\n A is subset of B ";
	else
	cout<<"\n A is NOT a subset of B ";


   }


    set()
    {
      pos=0;
    }
     int size()
     {
      return(pos);
     }
      void add(int x)
      {
      a[pos]=x;
      pos++;
      }
      int contains(int x)
      {
       for(i=0;i<pos; i++)
       {
	if(a[i]==x)
	  return(1);
       }
       return(0);
      }

      void remove(int x)  ;
	  void disp();
};
 void set::disp()
 {
 // cout<<" \n Array is ";
 for(i=0;i<pos;i++)
 {
  cout<<a[i]<<"\t";

 }

 }

 void set :: remove(int x)
 {
 int z=0;
   for(i=0;i<pos && a[i]!=x;i++)
 {

 }
 if(i==pos)   // element not found
 {
  z=1;
 }
 for( ; i<pos ;i++)
 {
  a[i]=a[i+1];
 }
 if(z==0) // element found
 pos--;
  disp();
}

int main()
{

int cho,no,ans;
set obj,o2,o3;
do
{

  cout<<"\n 1. Add\n 2.remove\n 3.search\n 4.size \n 5. intersection \n 6.union \n 7.difference \n 8.subset";
  cout<<"\n 9.EXIT ";
  cout<<"\n Enter choice ";
  cin>>cho;
  switch(cho)
  {
  case 1: int p,q;
  	   cout<<"\n1.Add in A.\n2.Add in B.";
  	   cout<<"\nEnter set in which elements are to be added: ";
  	   cin>>p;
  	   switch(p)
  	   {
  		case 1: cout<<"\nHow many elements in set A: ";
  			cin>>q;
  			while(q!=0)
  			{
  			cout<<"\n Enter element in set A : ";
  			cin>>no;
	  		
	  		obj.add(no);
	  		q--;
	  		}
	  		obj.disp();
	  	break;
	  	case 2: cout<<"\nHow many element in set B: ";
  			cin>>q;
  			while(q!=0)
  			{
	  		cout<<"\n Enter elements in set B: ";	
  			cin>>no;
	  		o2.add(no);
	  		q--;
	  		}
	  		o2.disp();
	  	break;
	  }
	  
  break;
  
   case 2: 
   	  cout<<"\n Enter no to be deleted : ";
	  cin>>no;
	  obj.remove(no);
	  cout<<"\n after deletion ";
	  obj.disp();
	  break;

   case 3: cout<<"\n Enter no to be search : ";
	  	cin>>no;
	 	ans= obj.contains(no);
	  	if(ans==1)
	   	 cout<<" \n element found ";
	  	else
	     	cout<<" \n element NOT found ";
 break;
  case 4: cout<<"\n size of array is : "<<obj.size();
  	cout<<"\n size of array is : "<<o2.size();
    break;

 case 5 : obj.intersection(o2);
	  break;
 case 6 : obj.unionSet(o2);
	  break;

 case 7 : obj.DiffSet(o2);
	  break;
 case 8 : obj.SubSet(o2);
	  break;


 


 
 
 case 9:break;
 default: cout<<endl<<" Invalid choice ";
 }

}while(cho!=9);


return 0;
}
/**********************OUTPUT******************************
gauri@inspiringminds-Inspiron-11-3148:~$ cd Desktop/
gauri@inspiringminds-Inspiron-11-3148:~/Desktop$ cd submission/
gauri@inspiringminds-Inspiron-11-3148:~/Desktop/submission$ g++ set.cpp 
gauri@inspiringminds-Inspiron-11-3148:~/Desktop/submission$ ./a.out 

 1. Add
 2.remove
 3.search
 4.size 
 5. intersection 
 6.union 
 7.difference 
 8.subset
 9.EXIT 
 Enter choice 1

1.Add in A.
2.Add in B.
Enter set in which elements are to be added: 1

How many elements in set A: 4

 Enter element in set A : 11 22 33 44

 Enter element in set A : 
 Enter element in set A : 
 Enter element in set A : 11	22	33	44	
 1. Add
 2.remove
 3.search
 4.size 
 5. intersection 
 6.union 
 7.difference 
 8.subset
 9.EXIT 
 Enter choice 1 

1.Add in A.
2.Add in B.
Enter set in which elements are to be added: 2 

How many element in set B: 2

 Enter elements in set B: 11 22

 Enter elements in set B: 11	22	
 1. Add
 2.remove
 3.search
 4.size 
 5. intersection 
 6.union 
 7.difference 
 8.subset
 9.EXITcd 
 Enter choice 3

 Enter no to be search : 22
 
 element found 
 1. Add
 2.remove
 3.search
 4.size 
 5. intersection 
 6.union 
 7.difference 
 8.subset
 9.EXIT 
 Enter choice 4

 size of array is : 4
 size of array is : 2
 1. Add
 2.remove
 3.search
 4.size 
 5. intersection 
 6.union 
 7.difference 
 8.subset
 9.EXITcd 
 Enter choice 2

 Enter no to be deleted : 44
11	22	33	
 after deletion 11	22	33	
 1. Add
 2.remove
 3.search
 4.size 
 5. intersection 
 6.union 
 7.difference 
 8.subset
 9.EXIT 
 Enter choice 5

 intersection is 11	22	
 1. Add
 2.remove
 3.search
 4.size 
 5. intersection 
 6.union 
 7.difference 
 8.subset
 9.EXIT 
 Enter choice 6

 union is union is 11	22	33	
 1. Add
 2.remove
 3.search
 4.size 
 5. intersection 
 6.union 
 7.difference 
 8.subset
 9.EXIT 
 Enter choice 7

 Difference is 33 
 1. Add
 2.remove
 3.search
 4.size 
 5. intersection 
 6.union 
 7.difference 
 8.subset
 9.EXIT
 Enter choice 8

 Subset is 
 A is NOT a subset of B 
 1. Add
 2.remove
 3.search
 4.size 
 5. intersection 
 6.union 
 7.difference 
 8.subset
 9.EXIT 
 Enter choice 
 gauri@inspiringminds-Inspiron-11-3148
 ***********************************************************/
