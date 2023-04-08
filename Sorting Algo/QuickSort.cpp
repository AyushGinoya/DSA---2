#include<iostream>
using namespace std;

int breakArray(int arr[],int s,int e)
{
    int pivot=arr[s];
    int i=s;
    int j=e;
    int cnt=0;

    for(int i=s+1;i<=e;i++)
    {
        if(arr[i]<=pivot)
        {
            cnt++;
        }
    }

    int pivotindex=s+cnt;
    swap(arr[s],arr[pivotindex]);

    while(i < pivotindex && j > pivotindex)
    {
        if(arr[i]<=pivot)
            i++;
        if(arr[j]>=pivot)
            j--;
        if(i < pivotindex && j > pivotindex)
            swap(arr[j],arr[i]);
    }

    return pivotindex;
}

void quickSort(int arr[],int s,int e)
{
    if(s>=e)
        return;

    int p=breakArray(arr,s,e);
     quickSort(arr,s,p-1);
      quickSort(arr,p+1,e);
}
int main()
{
    int arr[7]={33,54,64,775,3,22,2};

    quickSort(arr,0,6);

    for(int i=0;i<7;i++)
    {
        cout<<arr[i]<<"    ";
    }
}
