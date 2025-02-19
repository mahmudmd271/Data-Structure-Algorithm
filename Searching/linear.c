#include <stdio.h>

int main()
{
    int size,n;
    printf("Enter size of array: ");
    scanf("%d",&size);

    int a[size];

    printf("Enter the number of elements of array: ");
    scanf("%d",&n);

    printf("Enter The Elements: ");
    for (int i=0; i<n; i++)
        scanf("%d",&a[i]);


    int key, idx = -1;
    printf("Enter the number you want to search: ");
    scanf("%d",&key);

    for (int i=0; i<n; i++)
    {
        if (key==a[i])
        {
            idx=i;
            break;
        }
    }
    if (idx!=-1)
        printf("The Number was found at index: %d\nThe Number was found at position: %d\n",idx,idx+1);

    else
        printf("Nothing found\n");


    return 0;
}
