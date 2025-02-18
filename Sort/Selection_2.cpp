#include<bits/stdc++.h>
using namespace std;

void selection_sort(int a[], int n)
{
    int i, j, min_idx, temp;
    long long int compare = 0, swap = 0;
    for (i = 0; i < n - 1; i++)
    {
        min_idx = i;
        for (j = i + 1; j < n; j++)
        {
            compare++;
            if (a[j] < a[min_idx])
            {
                min_idx = j;
            }
        }
        if (min_idx != i)
        {
            temp = a[i];
            a[i] = a[min_idx];
            a[min_idx] = temp;
            swap++;
        }
    }
    cout << endl << "Swap Number= " << swap << endl << "Comparison number= " << compare << endl;
}

int main()
{
    int len=1000; //Length of the Array is fixed to 1000
    int rang;
    cin >> rang;
    clock_t start_time, end_time;
    double selection_time;

    cout<<"Enter elements range: "<<rang;
    int arr[len];
    srand(time(0));
    for (int i = 0; i < len; i++)
    {
        arr[i] = rand() % rang + 1; //range of the elements taken for assignment, 1 to 100,500,1000,5000,10000,50000

    }

    start_time = clock();
    selection_sort(arr, len);
    end_time = clock();

    selection_time = (double)(end_time - start_time) / CLOCKS_PER_SEC;

    cout << "Time for selection sort: " << selection_time;

}
