/**********ASSIGNMENT: (GROUP G-27)****************************
Problem Statement: Write a Java program which will demonstrate a concept of Interfaces and 
	         packages: In this assignment design and use of customized interfaces and 
	         packages for a specific application are expected.

DIV: A
BATCH: SA-2
ROLL NO: 30
********************************************************************/

import calculator.Pack1;
import java.util.*;
interface Calci
{
	double firstNumber();
	double secondNumber();
	//void display();
}
 class Calculator implements Calci
  {
  	double a,b,res;
  	Scanner in = new Scanner(System.in);
	public double firstNumber()
 	{
     		System.out.println("Enter first number: ");
     		a=in.nextDouble();
     		return a;
     	}
     	
     	public double secondNumber()
     	{
     		
     		System.out.println("Enter second number: ");
     		b=in.nextDouble();
     		return b;
     		
     		
     		
     		
 	}
 }

  
 


class interface_
{
	public static void main (String args[])
 	{
 	Calculator c = new Calculator();
 	Scanner i = new Scanner(System.in);

  Pack1 obj=new  Pack1();
  	
	
 
	int ch;
	double x,y;
	do
	{
	System.out.println("\n\t\tMENU\n\t\t1.ADDITION\n\t\t2.SUBTRACTION\n\t\t3.MULTIPLICATION\n\t\t4.DIVISION\n\t\t5.EXIT");
	
	System.out.println("Enter your choice: ");
	ch=i.nextInt();
	
	switch(ch)
	{
		case 1:obj.add(c.firstNumber(),c.secondNumber());
		break;
		case 2:obj.sub(c.firstNumber(),c.secondNumber());
		break;
		case 3:obj.mul(c.firstNumber(),c.secondNumber());
		break;
		case 4:obj.div(c.firstNumber(),c.secondNumber());
		break;
		case 5:break;
	}
			
	
	
	
	}while(ch!=5);

 

   }
}
/**********************OUTPUT********************************
gauri@inspiringminds-Inspiron-11-3148:~$ cd Desktop/
gauri@inspiringminds-Inspiron-11-3148:~/Desktop$ cd submission/
gauri@inspiringminds-Inspiron-11-3148:~/Desktop/submission$ cd package/
gauri@inspiringminds-Inspiron-11-3148:~/Desktop/submission/package$ javac Pack1.java 
gauri@inspiringminds-Inspiron-11-3148:~/Desktop/submission/package$ javac interface_.java 
gauri@inspiringminds-Inspiron-11-3148:~/Desktop/submission/package$ java interface_ 

		MENU
		1.ADDITION
		2.SUBTRACTION
		3.MULTIPLICATION
		4.DIVISION
		5.EXIT
Enter your choice: 
1
Enter first number: 
12
Enter second number: 
6

 Addition  = 18.0

		MENU
		1.ADDITION
		2.SUBTRACTION
		3.MULTIPLICATION
		4.DIVISION
		5.EXIT
Enter your choice: 
2
Enter first number: 
12
Enter second number: 
6

 Subtraction  = 6.0

		MENU
		1.ADDITION
		2.SUBTRACTION
		3.MULTIPLICATION
		4.DIVISION
		5.EXIT
Enter your choice: 
3
Enter first number: 
12
Enter second number: 
6

 Multiplication  = 72.0

		MENU
		1.ADDITION
		2.SUBTRACTION
		3.MULTIPLICATION
		4.DIVISION
		5.EXIT
Enter your choice: 
12

		MENU
		1.ADDITION
		2.SUBTRACTION
		3.MULTIPLICATION
		4.DIVISION
		5.EXIT
Enter your choice: 
6

		MENU
		1.ADDITION
		2.SUBTRACTION
		3.MULTIPLICATION
		4.DIVISION
		5.EXIT
Enter your choice: 
5
gauri@inspiringminds-Inspiron-11-3148:~/Desktop/submission/package$ 
*******************************************************************/
