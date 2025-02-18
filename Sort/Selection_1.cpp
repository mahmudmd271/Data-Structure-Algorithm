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
    int len;
    cin >> len; //Values taken for the assignmet: 1000,5000,10000,50000,100000,500000
    clock_t start_time, end_time;
    double selection_time;

    cout << "Enter Array Length: " << len;
    int arr[len];
    srand(time(0));
    for (int i = 0; i < len; i++)
    {
        arr[i] = rand() % 100 + 1; //range of the elements is fixed, 1 to 100
    }

    start_time = clock();
    selection_sort(arr, len);
    end_time = clock();

    selection_time = (double)(end_time - start_time) / CLOCKS_PER_SEC;

    cout << "Time for selection sort: " << selection_time;

}
