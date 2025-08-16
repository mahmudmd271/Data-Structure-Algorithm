#include<iostream>
using namespace std;
void insertionSort(int val[], int wt[], double Ratio[], int n)
{
    for (int i=1;i<n;i++)
    {
        double keyRatio =Ratio[i];
        int keyVal = val[i];
        int keyWt = wt[i];
        int j = i - 1;
        while (j >= 0 && Ratio[j] < keyRatio)
        {
            Ratio[j + 1] = Ratio[j];
            val[j + 1] = val[j];
            wt[j + 1] = wt[j];
            j--;
        }
        Ratio[j + 1] = keyRatio;
        val[j + 1] = keyVal;
        wt[j + 1] = keyWt;
    }
}
double fractionalKnapsack(int val[],int wt[],int n,int capacity)
{
    double Ratio[n];
    for(int i=0;i<n;i++)
        Ratio[i] = (double)val[i]/wt[i];

    insertionSort(val,wt,Ratio,n);

    cout<<"Sorted value-to-weight ratio: ";
    for(int i=0;i<n;i++)
    {
        cout<<Ratio[i]<<" ";
    }
    cout<<endl;

    double res=0.0;
    int currentCapacity = capacity;
    for(int i=0;i<n;i++)
    {
        if(wt[i]<=currentCapacity)
        {
            res+=val[i];
            currentCapacity-=wt[i];
        }
        else
        {
            res+=((double)val[i]/wt[i]) * currentCapacity;
            break;
        }
    }
    return res;
}
int main(){
    int n;
    cout<<"Enter total object: ";
    cin>>n;
    int val[n];
    int wt[n];
    int capacity;
    for(int i=0;i<n;i++)
    {
        cout<<"Enter profit of "<<i+1<<"th: ";
        cin>>val[i];
        cout<<"Enter weight of "<<i+1<<"th: ";
        cin>>wt[i];
    }
    cout<<endl;
    cout<<"Maximum Capacity of drone: ";
    cin>>capacity;
    cout<<endl;
    double result = fractionalKnapsack(val,wt,n,capacity);
    cout<<"Total Profit: "<<result<<endl;
    return 0;
}

