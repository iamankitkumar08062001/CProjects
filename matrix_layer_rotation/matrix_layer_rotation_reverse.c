#include<stdio.h>
#include<stdlib.h>

void make_and_initialize(int ***,int,int);
void rotate_array(int ***,int,int);
void print_array(int **,int,int);
int min(int,int);

int main()
{
	//m is number of rows
	//n is number of columns
	//r is number of rotation
	int m,n,r;
	int **array;
	scanf(" %d %d %d",&m,&n,&r);
	make_and_initialize(&array,m,n);
	int i=r;
	while(i>0)
	{
		rotate_array(&array,m,n);
		i--;
	}
	print_array(array,m,n);
	return 0;
}

void make_and_initialize(int ***array,int m,int n)
{
	int i,j;
	*array=(int **)malloc(sizeof(int *)*m);
	for(i=0;i<m;i++)
	{
		*((*array)+i)=(int *)malloc(sizeof(int)*n);
	}
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			scanf(" %d",(*((*array)+i)+j));
		}
	}
	return;
}

void rotate_array(int ***array,int m,int n)
{
	//lor stands for layer of rotation
	int lor=(min(m,n))/2;
	int i,j,k;
	//i is used for rows
	//j is used for columns
	//k is used for nor
	//m is number of rows
	//n is number of columns
	//r is number of rotation
	//temp1, temp2 is used as temporary variables
	int temp1,temp2;
	for(k=0;k<lor;k++)
	{
		//top-most layer
		for(j=n-k-1;j>=k;j--)
		{
			if(j==n-k-1)
			{
				temp1=*(*((*array)+k)+j);
				*(*((*array)+k)+j)=*(*((*array)+(k+1))+j);
				temp2=temp1;
				continue;
			}
			temp1=*(*((*array)+k)+j);
			*(*((*array)+k)+j)=temp2;
			temp2=temp1;
			//on the last iteration
			//both temp1 and temp2 will
			//contain the same value
			//which the the last value of that lor
		}
		//left-most layer
		for(i=k+1;i<m-k;i++)
		{
			temp1=*(*((*array)+i)+k);
			*(*((*array)+i)+k)=temp2;
			temp2=temp1;
			//on the last iteration
			//both temp1 and temp2 will
			//contain the same value
			//which the the last value of that lor
		}
		//bottom layer
		for(j=k+1;j<n-k;j++)
		{
			temp1=*(*((*array)+(m-k-1))+j);
			*(*((*array)+(m-k-1))+j)=temp2;
			temp2=temp1;
			//on the last iteration
			//both temp1 and temp2 will
			//contain the same value
			//which the the last value of that lor
		}
		//right-most layer
		for(i=m-k-2;i>k;i--)
		{
			temp1=*(*((*array)+i)+(n-k-1));
			*(*((*array)+i)+(n-k-1))=temp2;
			temp2=temp1;
			//on the last iteration
			//both temp1 and temp2 will
			//contain the same value
			//which the the last value of that lor
		}
	}
	return;
}

int min(int m,int n)
{
	if(m>n)
	{
		return n;
	}
	else
	{
		return m;
	}
}

void print_array(int **array,int m,int n)
{
	printf("The array is : \n");
	int i,j;
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			printf("%d ",*(*(array+i)+j));
		}
		printf("\n");
	}
}