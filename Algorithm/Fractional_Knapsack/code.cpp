#include<iostream>

using namespace std;

double fractionalKnapsack(int val[],int wt[],int n,int capacity){
    double ratio[n];

    for(int i=0;i<n;i++){
        ratio[i] = (double)val[i] / wt[i];
    }
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            if(ratio[j]<ratio[j+1])
            {
                double tempRatio = ratio[j];
                ratio[j] = ratio[j+1];
                ratio[j+1] = tempRatio;

                int tempVal = val[j];
                val[j] = val[j+1];
                val[j+1] = tempVal;

                int tempWt = wt[j];
                wt[j] = wt[j+1];
                wt[j+1] = tempWt;
            }
        }
}
 double res = 0.0;
    int currentCapacity = capacity;

    for (int i = 0; i < n; i++) {
        if (wt[i] <= currentCapacity) {
            res += val[i];
            currentCapacity -= wt[i];
        }

        else {
            res += ((double)val[i] / wt[i]) * currentCapacity;

            break;
        }
    }

    return res;
}
int main()
{
    int n;
    cout<<"Enter total object: ";
    cin>>n;
    int val[n];
    int wt[n];
    int capacity;
    for(int i=0;i<n;i++)
    {
        cout<<"Enter Profit of "<<i+1<<"th: ";
        cin>>val[i];
        cout<<"Enter Weight of "<<i+1<<"th: ";
        cin>>wt[i];
    }
    cout<<"Enter Maximum Capacity: ";
    cin>>capacity;

    cout<<"Total Profit: "<<fractionalKnapsack(val,wt,n,capacity)<<endl;

    return 0;
}
