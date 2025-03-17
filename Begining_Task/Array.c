#include <stdio.h>

int main()
{
    int size;
    printf("Size of the array: ");
    scanf("%d",&size);

    int a[size];

    int e;
    printf("Number of elements: ");
    scanf("%d",&e);

    if(e>size)
    {
        printf("Number of elements exceeds array size.\n");
        return 1;
    }

    printf("Enter %d elements: ",e);
    for (int i=0; i<e; i++)
    {
        scanf("%d",&a[i]);
    }
    int index;
    printf("Enter the index to work on: ");
    scanf("%d", &index);

    int value=a[index];
    if(value%2!=0)
    {
        value=value*value;
        printf("Squared value: %d\n", value);

        if (value%5==0)
        {

            if (e<size)
            {
                for(int i=e+1;i>index;i--)
                {
                    a[i]=a[i-1];
                }
                scanf("%d",&a[index+1]);
                printf("Value inserted at index %d. New number of elements: %d\n",index+1,e);
            }
        }
        else
        {

            for (int i=index; i<e-1; i++)
            {
                a[i]=a[i + 1];
            }
            e--;
            printf("Indexed value deleted. New number of elements: %d\n", e);
        }
    }
    else
    {
        if(index>0)
        {
            a[index]=a[index]+a[index-1];
        }
        value=a[index];
        printf("New value at index %d after addition: %d\n", index, value);


        if(value%2==0)
        {
            if(value%2!=0)
            {
                if (index>0)
                {
                    for (int i=index-1;i<e-1;i++)
                    {
                        a[i]=a[i+1];
                    }
                    e--;
                    printf("Previous indexed value deleted. New number of elements: %d\n", e);
                }
            }
            else
            {
                for (int i=index+1;i<e-1;i++)
                {
                    a[i]=a[i+1];
                }
                e--;
                printf("Next indexed value deleted. New number of elements: %d\n", e);
            }
        }
    }
    printf("Updated array: ");
    for (int i=0;i<e;i++)
    {
        printf("%d ",a[i]);
    }
    printf("\n");

    return 0;
}
