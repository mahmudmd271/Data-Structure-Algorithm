#include<stdio.h>

int main()
{
    int size;
    printf("Size of Array: ");
    scanf("%d",&size);
    int n;
    printf("Number of elements: ");
    scanf("%d",&n);
    if(n>size)
    {
        printf("Error: Number of elements cannot greater than size of array.");
        return 1;
    }

    int a[size];

    printf("Enter elements(Sorted):\n");
    for(int i=0; i<=n-1; i++)
    {
        scanf("%d",&a[i]);
    }
    int con;
    printf("\n\n\n");
    printf("Problem Statement:\nTake an array with size and number of elements dynamically.\n\nI. Find out a specific item according to linear search.\n\nII. Find out the minimum/maximum element according to linear search.\n\nIII. Find out an item how many times it occurs according to linear search.\n\nIV. Find out a specific item according to binary search.\n\nV. if the number of elements greater than 10, than searching done by binary search; otherwise according to linear search.\n");

    printf("Enter any one condition to perform: ");
    scanf("%d",&con);

    switch(con)
    {
    case 1:
    {
        int key,index=-1;
        printf("Enter the element want to search: ");
        scanf("%d",&key);

        //case :1
        //I. Find out a specific item according to linear search.

        for(int i=0; i<=n-1; i++)
        {
            if(key==a[i])
            {
                index=i;
                break;
            }
        }
        if(index==-1)
            printf("Not Found!");
        else
            printf("Found!\nIndex: %d",index);
        break;
    }
    case 2:
    {
        int max=a[0];

        //case :2
        //II. Find out the minimum/maximum element according to linear search.

        for(int i=0; i<=n-1; i++)
        {
            if(max<a[i])
            {
                max=a[i];
            }
        }
        printf("Maximum elements: %d",max);
        break;
    }

    case 3:
    {
        int key,cnt=0;
        printf("Enter the element want to search: ");
        scanf("%d",&key);

        //case :3
        //III. Find out an item how many times it occurs according to linear search.

        for(int i=0; i<=n-1; i++)
        {
            if(key==a[i])
            {
                cnt++;
            }
        }
        if(cnt==0)
            printf("Not Found!");
        else
            printf("Found: %d times",cnt);

        break;
    }
    case 4:
    {
        int key,index=-1;
        printf("Enter the element want to search: ");
        scanf("%d",&key);

        //case :4
        //IV. Find out a specific item according to binary search.

        int begining=0;
        int ending=n-1;
        int mid;


        while(begining<=ending)
        {
            mid=(begining+ending)/2;
            if(key==a[mid])
            {
                index=mid;
                break;
            }
            else if(key<a[mid])
                ending=mid-1;
            else
                begining=mid+1;
        }
        if(index==-1)
            printf("Not Found!");
        else
            printf("Found!\nIndex: %d",index);
        break;
    }
    case 5:
    {
        int key,index=-1;
        printf("Enter the element want to search: ");
        scanf("%d",&key);

        //case :5
        //V. If the number of elements greater than 10, than searching done by binary search; otherwise according to linear search.
        if(n>10)
        {
            int begining=0;
            int ending=n-1;
            int mid;


            while(begining<=ending)
            {
                mid=(begining+ending)/2;
                if(key==a[mid])
                {
                    index=mid;
                    break;
                }
                else if(key<a[mid])
                    ending=mid-1;
                else
                    begining=mid+1;
            }
            if(index==-1)
                printf("Not Found!");
            else
                printf("Found!\nIndex: %d",index);
        }
        else
        {
            for(int i=0; i<=n-1; i++)
            {
                if(key==a[i])
                {
                    index=i;
                    break;
                }
            }
            if(index==-1)
                printf("Not Found!");
            else
                printf("Found!\nIndex: %d",index);
        }
        break;
    }

    }
    return 0;
}
