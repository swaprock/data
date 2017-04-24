/**********ASSIGNMENT: (GROUP G-29)****************************
Problem Statement: Write a program on template and exception handling in Java: in this assignment 		         multiple templates are to be designed as a pattern and these patterns to be 
                   used to take decisions.

DIV: A
BATCH: SA-2
ROLL NO: 30
********************************************************************/


import java.lang.Exception;
import java.util.*;

class DivByZero extends Exception
{
	DivByZero(String msg)
	{
		super(msg);
	}
}
class exception1
{
	public static void main(String args[])
	{
		int a,b;
		Scanner in = new Scanner(System.in);
					System.out.println("Enter 1st number :");
					a=in.nextInt();
					System.out.println("Enter 2nd number :");
					b=in.nextInt();
					
					
						try
						{
						if(b==0)
					throw new DivByZero("Divisor cannot be Zero as the answer tends to infinity\n");
						
						
					{
						System.out.println("Division ::"+(a/b));
					}
					}
						catch(DivByZero e)
						{
							System.out.println("Exception Occured :"+e.getMessage());
						}
					
				
			
					finally
					{
						System.out.println("End of program.");
					}
					}
				}	
	

/***********************OUTPUT***************************
gauri@inspiringminds-Inspiron-11-3148:~/Desktop/submission$ javac exception1.java 
gauri@inspiringminds-Inspiron-11-3148:~/Desktop/submission$ java exception1 
Enter 1st number :
12
Enter 2nd number :
0
Exception Occured :Divisor cannot be Zero as the answer tends to infinity

End of program.
gauri@inspiringminds-Inspiron-11-3148:~/Desktop/submission$ java exception1 Enter 1st number :
12
Enter 2nd number :
6
Division ::2
End of program.
gauri@inspiringminds-Inspiron-11-3148:~/Desktop/submission$

*********************************************************/		
