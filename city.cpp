#include<iostream>

#include<stdlib.h>

using namespace std;
int n,mat[10][10];

class city
{
	public:	int i,k,j,w,l,wt,s[10],min;
			int mincost;

	public:	void getdata();
		 int kr(int cost[10][10],int n);

};

void city :: getdata()
{
   int e,z,row,col;
	//cout<<"\nKruskal's algorithm:";
	cout<<"\nEnter no. of cities:";
	cin>>n;
	cout<<"\nEnter no. of paths :";
	cin>>e;
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
		mat[i][j]=0;
		}
	}

	for(z=1;z<=e;z++)
	{

	  cout<<endl<<"Enter 2 cities & their charges ";
	  cin>>row>>col>>wt;
	  mat[row][col]=wt;
	  mat[col][row]=wt;
	}

cout<<endl<< " charges matrix is "<<endl;
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
		    cout<<" "<<mat[i][j];
		}
   cout<<endl;
	}

}

int city :: kr(int cost[10][10],int n)
{
	int visited[20]={0};
	int min=999,mincost=0;
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			if(cost[i][j]<min && cost[i][j]!=0)
			{
				min=cost[i][j];
					k=i;
				l=j;
			}
		}
	}
	  visited[k]=1;
	  visited[l]=1;
	mincost=cost[k][l]+mincost;
	
	 cout<<"\n min path is "<<k <<" to "<<l << " \ncharge"<<cost[k][l]<< "\nmincost "<<mincost;
	
	   cost[k][l]=0;
	   cost[l][k]=0;
int cnt=2;
int row,col;
    while(cnt<n)
	{

	for(k=1,min=999;k<=n;k++)       // row
	 {
		 
		  
		   for(i=1;i<=n;i++)       // col
		   {
			 if(cost[k][i]<min && cost[k][i]!=0 && visited[i]==0)
			 {
				  row=k;
				  col=i;
				 min=cost[k][i];
			 }
		   }//for
		 
	  }
	mincost=mincost+min;
	 cout<<"\n min path is "<<row <<" to "<<col << " \ncharge "<<cost[row][col]<< " \nmincost "<<mincost;

	cost[col][row]=0;
	 cost[row][col]=0;
	 visited[col]=1;
	 cnt++;
    }
return(mincost);
}


int main()
{
	int x;
	
	city c;
	c.getdata();
	x=c.kr(mat,n);

	cout<<"\nThe minimun charge of phone lines to connect cities is "<<x;
	return 0;
}


