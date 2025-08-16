#include<bits/stdc++.h>
using namespace std;


void Merge-Sort(int arr[],int L,int R)
{
    if(L<R)
    {
        int C = L+(R-L)/2;
        Merge-Sort(arr,L,C);
        Merge-Sort(arr,C+1,R);
        Merge(arr,L,C,R);
    }
}

void Merge(int arr,int L,int C,int R)
{
    int n1 = C-L+1;
    int n2 = R-C;
    int L[n1],R[n2]; //Temporary Array
    for(int i=0;i<=n1;i++)
        L[i]=arr[L+i];
    for(int i=0;i<=n1;i++)
        L[i]=arr[C+i+1];

    int i=0,j=0,k=L;
    while (i<n1 && j<n2){

    }
    /*____-_-_-__-___--
        Write here>>>
    */
}

void insertionSort(int arr[],int n)
{
    int i,key,j;
    for(i=1; i<n; i++)
    {
        key = arr[i];
        j = i-1;
        while(j>=0 && arr[j]>key)
        {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
}
void selectionSort(int arr[],int n)
{
    int i;
    for(i=0; i<n-1; i++)
    {
        int id = i;
        for(int j=i+1; j<n; j++)
        {
            if(arr[id]>arr[j])
                id=j;
        }
        if(id!=i)
        {
            int temp = arr[i];
            arr[i] = arr[id];
            arr[id] =temp;
        }
    }
}

void printArray(int arr[],int n)
{
    cout<< "Sorted Array: ";
    for(int i=0; i<n; i++)
    {
        cout << arr[i] <<" ";
    }
    cout<<endl;
}
int main()
{
    int n;

    cout<<"Number of elements: ";
    cin>>n;
    int arr[n];
    for(int i =0; i<n; i++)
    {
        cout<<"Element No."<<i+1<<": ";
        cin>>arr[i];
    }
//int N = sizeof(arr)/sizeof(arr[0]);
    int N = n;
    int p;
    {
        cout<<endl<<"Press 1 to continue in Inserion sort"<<endl;
        cout<<"Press 2 to continue in Seletion sort"<<endl;
        cout<<"Press 3 to continue in Merge sort"<<endl;
        cin>>p;
        switch(p)
        {
        case 1:
            insertionSort(arr,N);
            printArray(arr,N);
            break;
        case 2:
            selectionSort(arr,N);
            printArray(arr,N);
            break;
        case 3:
            Merge-Sort(arr,0,N-1);
            printArray(arr,N);
            break;
        default:
            cout<<"Invalid choice"<<endl;
            break;
        }
    }
    return 0;
}
