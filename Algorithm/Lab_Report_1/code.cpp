#include<iostream>
#include<string>
#define MAX 100

using namespace std;

struct Employee {
    string id;
    int salary;
};

bool compare(const Employee &a, const Employee &b) {
    if (a.salary != b.salary)
        return a.salary > b.salary;
    else
        return a.id < b.id;
}

void Merge(Employee arr[], int p, int q, int r) {
    int n1 = q - p + 1;
    int n2 = r - q;
    Employee L[MAX], R[MAX];

    for (int i = 0; i < n1; i++)
        L[i] = arr[p + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[q + 1 + j];

    int i = 0, j = 0, k = p;

    while (i < n1 && j < n2) {
        if (compare(L[i], R[j])) {
            arr[k++] = L[i++];
        } else {
            arr[k++] = R[j++];
        }
    }

    while (i < n1)
        arr[k++] = L[i++];

    while (j < n2)
        arr[k++] = R[j++];
}

void mergeSort(Employee arr[], int p, int r) {
    if (p < r) {
        int q = p + (r - p) / 2;
        mergeSort(arr, p, q);
        mergeSort(arr, q + 1, r);
        Merge(arr, p, q, r);
    }
}

int Partition(Employee arr[], int low, int high) {
    Employee pivot = arr[low];
    int i = low + 1;
    int j = high;

    while (true) {
        while (i <= high && compare(arr[i], pivot))
            i++;
        while (j >= low + 1 && compare(pivot, arr[j]))
            j--;
        if (i > j)
            break;
        swap(arr[i], arr[j]);
    }
    swap(arr[low], arr[j]);
    return j;
}


void quickSort(Employee arr[], int low, int high) {
    if (low < high) {
        int pivotIndex = Partition(arr, low, high);
        quickSort(arr, low, pivotIndex - 1);
        quickSort(arr, pivotIndex + 1, high);
    }
}


void insertionSort(Employee arr[], int n) {
    for (int i = 1; i < n; i++) {
        Employee key = arr[i];
        int j = i - 1;
        while (j >= 0 && !compare(arr[j], key)) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

void selectionSort(Employee arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int id = i;
        for (int j = i + 1; j < n; j++) {
            if (!compare(arr[id], arr[j])) {
                id = j;
            }
        }
        if (id != i) {
            swap(arr[i], arr[id]);
        }
    }
}

void displayEmployees(Employee arr[], int n) {
    cout << "\nSorted Employee:\n";
    for (int i = 0; i < n; ) {
        cout << "(" << arr[i].id << arr[i].salary << ")";
        i++;
        if(i==n)
            cout<<".";
        else
            cout<<",";
    }
    cout << endl;
}

int main() {
    int n, choice;
    Employee employees[MAX];

    cout << "Number of employees: ";
    cin >> n;
    cout << "Enter Employee ID and Salary:\n";
    for (int i = 0; i < n; i++) {
        cin >> employees[i].id >> employees[i].salary;
    }

    cout << "\nSorting Options:\n";
    cout << "1. Insertion Sort\n";
    cout << "2. Selection Sort\n";
    cout << "3. Quick Sort\n";
    cout << "4. Merge Sort\n";
    cout << "Press a option: ";
    cin >> choice;

    switch (choice) {
        case 1:
            insertionSort(employees, n);
            displayEmployees(employees, n);
            break;
        case 2:
            selectionSort(employees, n);
            displayEmployees(employees, n);
            break;
        case 3:
            quickSort(employees, 0, n - 1);
            displayEmployees(employees, n);
            break;
        case 4:
            mergeSort(employees, 0, n - 1);
            displayEmployees(employees, n);
            break;
        default:
            cout << "Invalid choice\n";
            break;
    }

    return 0;
}
