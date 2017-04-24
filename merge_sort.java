/**********ASSIGNMENT: (GROUP F-22)****************************
Problem Statement: Assume we have two input and two output tapes to perform the sorting. 
	         The internal memory can hold and sort m records at a time. Write a 
	         program in java for external sorting. Find out time complexity.

DIV: A
BATCH: SA-2
ROLL NO: 30
********************************************************************/

import java.io.*;
import java.util.*;


class Sort
{
	
		
	//public int c[] = new int[20];
	void merge_sort(int n1, int n2)
	{
		int a[] = new int[n1];
		int b[] = new int[n2];
		int n3;
	n3=n1+n2;	
	 int c[] = new int[n3];
		
		
		int i,j,k;
		Scanner n= new Scanner(System.in);
		System.out.print("Enter sorted elements in array 1: ");
		for(i=0;i<n1;i++)
		{
			a[i]=n.nextInt();
		}
		System.out.print("Enter sorted elements in array 2: ");
		for(i=0;i<n2;i++)
		{
			b[i]=n.nextInt();
		}
		i=j=k=0;
	
		
		while(i < n1 && j<n2)
		{
			if(a[i] > b[j])
			{
				c[k] = b[j];
				j++;
				k++;
			}
			else
			{
				if(a[i] < b[j])
				{
					c[k] = a[i];
					i++;
					k++;
				}
				else
				{
					if(a[i] == b[j])
					{
						c[k] = a[i];
						i++;
						j++;
						k++;
					}
				}
			}

		}
			
			while(i!=n1)
			{
				c[k] = a[i];
				i++;
				k++;
			}
			
			while(j!=n2)
			{
				c[k] = b[j];
				j++;
				k++;
			}
			display(c,n3);
			
		}
		void display(int c[],int n3)
		{
			
			
				System.out.println("Merged array is ");
				for(int i=0;i<n3;i++)
			{
				System.out.print(" "+c[i]+ " ");
			}
		}
		
	}




class merge_sort
{
	public static void main(String args[])
	{
		int n1,n2;
		Sort s = new Sort();
		Scanner in =  new Scanner(System.in);
		System.out.println("\nEnter number of elements in array 1: ");
		n1 = in.nextInt();
		System.out.println("\nEnter number of elements in array 2: ");
		n2 = in.nextInt();
	
		
		s.merge_sort(n1,n2);
		//s.display(n3);
		
	}
}

/************OUTPUT*************************************
gauri@inspiringminds-Inspiron-11-3148:~/Desktop/submission$ javac merge_sort.java
gauri@inspiringminds-Inspiron-11-3148:~/Desktop/submission$ java merge_sort 

Enter number of elements in array 1: 
3

Enter number of elements in array 2: 
3
Enter sorted elements in array 1: 1 5 8
Enter sorted elements in array 2: 2 6 9
Merged array is 
 1  2  5  6  8  9
 *********************************************************/
		
