#include<bits/stdc++.h>
using namespace std;

void bubble_sort(int a[], int n)
{
    int i,j,temp;
    long long int compare=0,swap=0;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n-i-1;j++)
        {
            compare++;
            if(a[j]>a[j+1])
            {
                temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
                swap++;
            }
        }
    }
    cout<<endl<<"Swap Number= "<<swap<<endl<<"Comparison number= "<<compare<<endl;
}

int main()
{
    int len=1000;//Length of the Array is fixed to 1000
    int rang;
    cin>> rang;
    clock_t start_time, end_time;
    double bubble_time;

    cout<<"Enter elements range: "<<rang;
    int arr[len];
    srand(time(0));
    for(int i=0;i<len;i++)
    {
        arr[i]=rand()%rang+1; //range of the elements taken for assignment, 1 to 100,500,1000,5000,10000,50000
    }

    start_time = clock();
    bubble_sort(arr,len);
    end_time = clock();

    bubble_time = (double)(end_time-start_time)/CLOCKS_PER_SEC;

    cout<<"Time for bubble sort: "<<bubble_time;

}
