#include<stdio.h>
#include<conio.h>

int a[10]={1,3,4,2,5,6,9,12},b[10][10],size,merge[10],row=0,col=0,n=8,aptr=0;

void init()
{
 int i,j;
 for(i=0;i<10;i++)
  for(j=0;j<10;j++)
   b[i][j]=-1;
}

void partition()
{
 int k=0,i;
 while(k<n)
 {
  for(; k==0 || (k%size!=0 && k<n) ; k++)
  {
   b[row][col++]=a[k];
  }
  
  //if(k>n)
  //b[row][col]=a[k];
  
  //else
   {
   row++;
   col=0;
   b[row][col++]=a[k++];
   }
 }
 
 for(k=0;k<row;k++)
 {
  printf("Partition %d \n\n",k+1);
  for(i=0;i<10;i++)
  {
  if(b[k][i]==-1)
  break;
  else
  printf("%d ",b[k][i]);
  }
  printf("\n\n");
 }
}

void merger()
{
 int i,j;
 for(i=0;i<row;i++)
  {
   printf("\nEnter the order: ");
   scanf("%d",&merge[i]);
  }
  
  for(i=0;i<row;i++)
  {
   for(j=0;j<10;j++)
    {
     if(b[merge[i]-1][j]==-1)
      break;
      else
      a[aptr++]=b[merge[i]-1][j];
    }
  }
  
   for(i=0;i<aptr;i++)
   printf("%d ",a[i]);
  
}

int main()
{
printf("\nEnter the partition size: ");
scanf("%d",&size);

init();
partition();
merger();

getch();
return 0;
}
