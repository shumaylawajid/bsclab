// insertion sort
#include<stdio.h>
#define N 10
void ins_sort(int a[], int n)
{int i,x,j;
for(i=1;i<n-1;i++)
{ x=a[i];
  j=i-1;
  while(x<a[j]&&j>=0)
  {a[j+1]=a[j];
  j=j-1;
  }
  a[j+1]=x;
 }
}
void main()
{int a[N],i;
printf("\nEnter %d integer values for sorting :\n",N);
for(i=0;i<N;i++)
  scanf("%d",&a[i]);
printf("\nArray before sorting :\n");
for(i=0;i<N;i++)
  printf("%d ",a[i]);
ins_sort(a,N);
printf("\nArray after sorting:\n");
for(i=0;i<N;i++)
  printf("%d ", a[i]);
}
