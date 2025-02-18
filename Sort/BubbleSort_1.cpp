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
    int len;
    cin>> len; //Values taken for the assignmet: 1000,5000,10000,50000,100000,500000
    clock_t start_time, end_time;
    double bubble_time;

    cout<<"Enter Array Length: "<<len;
    int arr[len];
    srand(time(0));
    for(int i=0;i<len;i++)
    {
        arr[i]=rand()%100+1; //range of the elements is fixed, 1 to 100
    }

    start_time = clock();
    bubble_sort(arr,len);
    end_time = clock();

    bubble_time = (double)(end_time-start_time)/CLOCKS_PER_SEC;

    cout<<"Time for bubble sort: "<<bubble_time;

}
