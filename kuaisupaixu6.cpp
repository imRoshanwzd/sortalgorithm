#include <iostream>

using namespace std;


void qsort(int a[],int start,int end)
{
	if (start>=end)
	{
		return;
	}
	 int i=start;
	 int j=end;

	 int k=a[i];

	 while(i<j)
	 {
		while(i<j&&a[j]>=k)j--;
		a[i]=a[j];
		while(i<j&&a[i]<=k)i++;
		a[j]=a[i];
	 }
	 a[i]=k;

	 qsort(a,start,i-1);
	 qsort(a,i+1,end);


}

int main()
{
	int a[]={6,5,3,3,2,1,7};
	int s=0;
	int e=6;
	qsort(a,s,e);

	for (int i=0;i<7;i++)
	{
		cout<<a[i]<<" ";
	}
	system("pause");
}