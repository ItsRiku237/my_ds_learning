#include <stdio.h>
// Linear search
void main()
{
    int n;
    printf("Enter size of the array : ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter element of the array :\n");
    for (int i = 0; i < n; i++)
    {
        printf("Enter element %d : ",i+1);
        scanf("%d", &arr[i]);
    }
    int key;
    printf("Enter the element which is finding : ");
    scanf("%d", &key);
    int found = 0;
    for (int i = 0; i < n; i++)
    {
        if (key == arr[i])
        {
            printf("Element %d is found in position %d (index %d ).", key, i + 1, i);
            found = 1;
            break;
        }
    }
    //0 = false
    //1 = true
    if (!found)
    {
        printf("Element %d is not found .", key);
    }
    //  if (found==0)
    // {
    //     printf("Element %d is not found .",key);
    // }
}