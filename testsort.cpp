#include <iostream>
using namespace std;


//1、插入排序
void InsertSort(int arr[],int size)
{
	int i,j=0;
	int temp;
	
	for (int i=1;i<size;i++)
	{
		temp=arr[i];
		for (j=i;j>0&&arr[j-1]>temp;j--)
		{
			arr[j]=arr[j-1];
		}
		arr[j]=temp;
	}
}
//2、希尔排序
void ShellSort(int arr[],int size)
{
	int count=0;
	int gap=size;
	while(gap>1)
	{
		gap=gap/3+1;
		for (int i=gap;i<size;i++)
		{
			for (int j=i;j>=gap;j-=gap)
			{
				if (arr[j]<arr[j-gap])
				{
					int tmp=arr[j];
					arr[j]=arr[j-gap];
					arr[j-gap]=tmp;
					count++;
				}
				else
				{
					break;
				}
			}
		}
	}
	cout<<"共移动次数："<<count<<endl;
}

//3、选择排序

void SelectSort(int arr[],int size)
{
	
	for (int i=0;i<size;i++)
	{
		int minindex=i;
		
		for (int j=i+1;j<size;j++)
		{
			if (arr[j]<arr[minindex])
			{
				minindex=j;
			}
		}
		
		if (minindex!=i)
		{
			int temp;
			temp=arr[i];
			arr[i]=arr[minindex];
			arr[minindex]=temp;
		}
	}
}

//4、冒泡排序

void BubbleSort(int arr[],int size)
{
	for (int i=0;i<size-1;i++)
	{
		for (int j=0;j<size-1-i;j++)
		{
			if (arr[j]>arr[j+1])
			{
				int temp=arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=temp;
			}
		}
	}
}

//5、归并排序

void Merge(int arr[],int* temp,int start,int mid,int end)
{
	int i=start,j=mid+1,k=start;
	while(i<=mid&&j<=end)
	{
		if (arr[i]>=arr[j])//排序稳定，如果相同，先放原序列前面的值
		{
			temp[k++]=arr[j++];
		}
		if (arr[i]<arr[j])
		{
			temp[k++]=arr[i++];
		}
	}
	while(i<=mid)
	{
		temp[k++]=arr[i++];
	}
	while(j<=end)
	{
		temp[k++]=arr[j++];
	}
	for (int i=start;i<=end;i++)
	{
		arr[i]=temp[i];
	}
}
void MergeSort(int arr[],int* temp,int start,int end)
{
	if (start>=end)
	{
		return;
	}
	int mid=(start+end)/2;

	MergeSort(arr,temp,start,mid);
	MergeSort(arr,temp,mid+1,end);
	Merge(arr,temp,start,mid,end);
}
void MergeSortBuild(int arr[],int size)
{
	int start=0;
	int end=size-1;
	int *temp=new int[size];
	MergeSort(arr,temp,start,end);

	delete []temp;

}

///6、快速排序
void QuickSort(int arr[],int start,int end)
{
	if (start>=end)
	{
		return;
	}
	int i=start;
	int j=end;
	int key=arr[i];

	while(j>i)
	{
		while(j>i&&arr[j]>=key)j--;
		arr[i]=arr[j];
		while(j>i&&arr[i]<=key)i++;
		arr[j]=arr[i];
	}
	arr[i]=key;
	QuickSort(arr,start,i-1);
	QuickSort(arr,i+1,end);
}
void QuickSortBiuld(int arr[],int size)
{
	int start=0;
	int end=size-1;
	QuickSort(arr,start,end);
}

//7、堆排序
void Adjust(int arr[],int size,int index)
{
	int left=index*2+1;
	int right=index*2+2;
	int maxid=index;
	if (left<size&&arr[left]>arr[maxid])
	{
		maxid=left;
	}
	if (right<size&&arr[right]>arr[maxid])
	{
		maxid=right;
	}
	if (maxid!=index)
	{
		swap(arr[maxid],arr[index]);
		Adjust(arr,size,maxid);
	}
	
}

void HeapSort(int arr[],int size)
{
	for (int i=size/2-1;i>=0;i--)
	{
		Adjust(arr,size,i);
	}

	for (int i=size-1;i>=1;i--)
	{
		swap(arr[0],arr[i]);
		Adjust(arr,i,0);
	}
}

// 8、基数排序
int CalcuTime(int arr[],int size)
{
	int p=10;
	int t=1;
	for (int i=0;i<size;i++)
	{
		if (arr[i]%p)
		{
			p=p*10;
			t++;
		}
	}
	return t;
}
void RadixSort(int arr[],int size)
{
	int d=CalcuTime(arr,size);

	int *Bucket=new int[10];
	int *temp=new int[size];

	int radix=1;int k=0;
	for (int i=1;i<=d;i++)
	{
		for (int j=0;j<10;j++)
		{
			Bucket[j]=0;
		}
		for (int j=0;j<size;j++)
		{
			k=(arr[j]/radix)%10;
			Bucket[k]++;
		}
		for (int j=1;j<10;j++)
		{
			Bucket[j]=Bucket[j-1]+Bucket[j];
		}
		for (int j=size-1;j>=0;j--)
		{
			k=(arr[j]/radix)%10;
			temp[Bucket[k]-1]=arr[j];
			Bucket[k]--;
		}

		for(int j=0;j<size;j++)
		{
			arr[j]=temp[j];
		}

		radix*=10;
	}

	delete[]Bucket;
	delete[]temp;
}

int main()
{
	int a[]={4,6,6,9,5,11,3,9,7,3,1};
	int n=sizeof(a)/sizeof(int);

	RadixSort(a,n);

	for (int i=0;i<n;i++)
	{
		cout<<a[i]<<" ";
	}
	cout<<endl;

	system("pause");
}