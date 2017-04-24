/**********ASSIGNMENT: (GROUP G-25)****************************
Problem Statement: Implement the Heap/Shell sort algorithm implemented in Java demonstrating 
	         heap/shell data structure with modularity of programming language

DIV: A
BATCH: SA-2
ROLL NO: 30
********************************************************************/

import java.util.*;

class Shell
{
	private int a[] = new int[30];
	Scanner in = new Scanner(System.in);
	void insert(int n)
	{
		for (int i=0;i<n;i++) 
		{
			a[i] = in.nextInt();
		}
	}

	void sort(int n)
	{
		int i, j, k, temp;
    	for (i = n/2;i > 0;i = i/2) 
    		
    	{
        	for (j = i;j < n;j++)
        	{
            	for(k = j - i;k >= 0;k = k - i)
            	{
                	if (a[k+i] >= a[k])
                    	break;
                	else
                	{
                    	temp = a[k];
                    	a[k] = a[k+i];
                    	a[k+i] = temp;
                	}
            	}
        	}
    	}
		
	}

	void display(int n)
	{
		for (int i=0;i<n;i++) 
		{
			System.out.print(" "+a[i]+" ");
		}
	}
}


class shell_sort
{
public static void main(String[] args) 
{
	int n;
	Shell s = new Shell();
	Scanner in = new Scanner(System.in);
	System.out.println("Enter number of elements: ");
	n = in.nextInt();
	System.out.print("Elements in the Array--> ");
	s.insert(n);
	System.out.println("Sorted elements are: ");
	s.sort(n);
	s.display(n);


}
}
/*********************OUTPUT******************************
gauri@inspiringminds-Inspiron-11-3148:~/Desktop/submission$ javac shell_sort.java 
gauri@inspiringminds-Inspiron-11-3148:~/Desktop/submission$ java shell_sort 
Enter number of elements: 
8   
Elements in the Array--> 12 3 15 10 2 5 4 7
Sorted elements are: 
 2  3  4  5  7  10  12  15 
 gauri@inspiringminds-Inspiron-11-3148:~/Desktop/submission$ 
 ***********************************************************/

