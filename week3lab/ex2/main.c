#include <stdio.h>
int size;

void bubble_sort(int arr[]){
    int i,j;
    printf("%d\n", sizeof(arr));
    for(i=0; i<sizeof(arr)/sizeof(int)-1; i++){
        for(j=0; j<sizeof(arr)/sizeof(int)-1-i;j++){
            if(arr[j]>arr[j+1]){
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

int main()
{
    int arr[5] = {0,1,4,3,2};
    size = printf("%d\n", sizeof(arr));
    bubble_sort(arr);
    int i;
    for(i=0;i<5;i++)
        printf("%d ", arr[i]);
    return 0;
}
