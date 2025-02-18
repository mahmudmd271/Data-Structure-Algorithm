#include<bits/stdc++.h>
using namespace std;

void insertion_sort(int a[], int n)
{
    int i, key, j;
    long long int compare = 0, swap = 0;
    for (i = 1; i < n; i++)
    {
        key = a[i];
        j = i - 1;

        while (j >= 0 && a[j] > key)
        {
            compare++;
            a[j + 1] = a[j];
            j--;
            swap++;
        }
        compare++;
        a[j + 1] = key;

    }
    cout << endl << "Swap Number= " << swap << endl << "Comparison number= " << compare << endl;
}

int main()
{
    int len;
    cin >> len;//Values taken for the assignmet: 1000,5000,10000,50000,100000,500000
    clock_t start_time, end_time;
    double insertion_time;

    cout << "Enter Array Length: " << len;
    int arr[len];
    srand(time(0));
    for (int i = 0; i < len; i++)
    {
        arr[i] = rand() % 100 + 1;//range of the elements is fixed, 1 to 100
    }

    start_time = clock();
    insertion_sort(arr, len);
    end_time = clock();

    insertion_time = (double)(end_time - start_time) / CLOCKS_PER_SEC;

    cout << "Time for insertion sort: " << insertion_time;

}
