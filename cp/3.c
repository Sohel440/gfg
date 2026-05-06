#include<stdio.h>

int prt(int arr[] , int s , int e){
    int pivot = arr[s];
    int i = s + 1;
     int temp;
    int j = e;
    do
    {
        while(arr[i] <= pivot){
            i++;
        }
        while(arr[j] > pivot){
            j--;
        }
        if(i < j){
            temp = arr[i];
            arr[i]= arr[j];
            arr[j] = temp;
        }


    } while (i<j);

    temp = arr[s];
    arr[s]= arr[j];
    arr[j] = temp;
    return j;
     

}
void quick(int arr[] , int s , int e){
    if(s <= e){
        int p = prt(arr, s , e);
        quick(arr, s , p-1);;
        quick(arr , p+1 , e);

    }
}
int main(){

    int arr[]={12 , 300 , 4};
    quick(arr, 0 , 3);
    int i;
    for ( i = 0; i < 3; i++)
    {
       printf("%d ", arr[i]);
    }
    

    return 0;

}