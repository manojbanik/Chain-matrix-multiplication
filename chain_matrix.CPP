//	This program solves the chain matrix multiplication problem.
//	Program will ask for the dimensions of the matrices intended to multiply
//	Will produce a sequence to multiply that requires minimum multiplications.



#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

#define N 10

order[N+1][N+1]={{0}};
void seq(short ,short);
long dynamic(long[]);

void main(void)
{
	int i;
	long row_col[N+1],cost;
	

	clrscr();

	printf("\nPlease enter the dimensions of the matrices :: \n\n");

	for(i=0;i<=N;i++) scanf("%ld", &row_col[i]); 

	//	Enter row, column for first matrix and then only the column for rest matrices.

	

	puts("\n\n");

	cost=dynamic(row_col);

	printf("\n\nCostforDynamic method=%ld",cost);

	getch();
}

long dynamic(long row_col[])
{
	long cost[N+1][N+1],temp;
	int i,j,k,l;

	for(i=0;i<=N;i++)
	{
		for(j=0;j<=N;j++)
		{
			if(i==j) cost[i][j]=0;
			else cost[i][j]=4294967295;
		}
	}

	for(l=1;l<N;l++)
	{
		for(i=1;i<=N-l;i++)
		{
			j=i+l;

			for(k=i;k<j;k++)
			{
				if(cost[i][j]==4294967295)
				{
					cost[i][j] = cost[i][k] + cost[k+1][j] +
									row_col[j] * row_col[k] * row_col[i-1];
					order[i][j]=k;
				}
				else
				{
					temp=cost[i][j];
					if((cost[i][k] + row_col[i-1]*row_col[j]*row_col[k]+cost[k+1][j])<cost[i][j])
						cost[i][j]= cost[i][k]+row_col[i-1]*row_col[j]*row_col[k]+cost[k+1][j];

					if(cost[i][j]<temp) order[i][j]=k;
				}
			}
		}
	}

	seq(1,N);	//	will print the sequence.

	return (cost[1][N]);
}

void seq(short i,short n)
{
	short k;
	if((n-i)>1)
	{
	  k=order[i][n];
	  printf("\n<%d, %d> * <%d,%d>" ,i,k,k+1,n);
	  if(k-i>0)
	  seq(i,k);
	  if(n-k-1>0)
	  seq(k+1,n);
	}
}