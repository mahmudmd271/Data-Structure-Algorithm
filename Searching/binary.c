#include <stdio.h>

int main()
{
    int size,n;
    printf("Enter size of array: ");
    scanf("%d",&size);

    int a[size];

    printf("Enter the number of elements of array: ");
    scanf("%d",&n);

    printf("Enter the sorted elements of the array: ");
    for (int i=0; i<n; i++)
        scanf("%d",&a[i]);

    int key;
    printf("Enter the number you want to search: ");
    scanf("%d",&key);

    int left=0;
    int right=n-1;
    int result=-1;

    while (left<=right)
    {

        int mid=left+(right-left)/2;

        if(a[mid]==key)
        {
            result=mid;
            break;
        }

        else if(a[mid]<key)
            left=mid+1;

        else
            right=mid-1;
    }

    if (result!=-1)
        printf("Element found at index: %d\nElement found at position: %d\n",result,result+1);
    else
        printf("Element not found\n");

    return 0;
}
