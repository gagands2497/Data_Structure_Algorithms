#include<iostream>
#include<stdlib.h>
using namespace std;

void merge(int input[],int temp[],int start,int end)
{
	int mid = (start + end)/2;
	int i = start,j = mid+1,k = start;
	
	while(i<=mid && j<=end)
	{
		if(input[i] < input[j])
		{
			temp[k++] = input[i++]; 
		}
		else
		{
			temp[k++] = input[j++];
		}
	}

	while(i<=mid)temp[k++] = input[i++];
	while(j<=end)temp[k++] = input[j++];

	for(int i = start;i<=end;i++)
	{
		input[i] = temp[i];
	}

}

void mergeSort(int input[],int temp[],int start,int end)
{
	if(start < end)
	{
		int mid = (start + end)/2;
		mergeSort(input,temp,start,mid);
		mergeSort(input,temp,mid+1,end);

		merge(input,temp,start,end);
	}
}

int main()
{
	int n;
	cout<<"Enter the Number"<<endl;
	cin>>n;
	int input[n];
	for(int i = 0;i<n;i++)
	{
		input[i] = rand() % 100;
	}

	int temp[n];
	int start = 0,end = n-1;
	mergeSort(input,temp,start,end);
	for(int i = 0;i<n;i++)
	{
		cout<<input[i]<<" ";
	}
}
