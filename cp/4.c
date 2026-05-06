#include<stdio.h>
void merge(int arr[] , int s , int mid , int e){
  
  int i, j, k, B[100];
  i = s;
    j = mid + 1;
    k = s;

    while (i <= mid && j <= e)
    {
        if (arr[i] < arr[j])
        {
            B[k++] = arr[i++];
            // i++;
            // k++;
        }
        else
        {
            B[k++]=arr[j++];
            
        }
    }
    while (i <= mid)
    {
        B[k++] = arr[i++];
        // k++;
        // i++;
    }
    while (j <= e)
    {
        B[k++] = arr[j++];
        // k++;
        // j++;
    }
    for (int i = s; i <= e; i++)
    {
        arr[i] = B[i];
    }
  

}
void mergeSort(int arr[], int s , int e)
{
    int mid ;
    if(s < e){
     mid = (s+e)/2;
     mergeSort(arr, s , mid);
     mergeSort(arr, mid+1 , e);
     merge(arr, s , mid , e );

    }


}
int main(){

int arr[] = {12 ,3 ,5};
mergeSort(arr, 0 ,3);
int i;
 for ( i = 0; i < 3; i++)
    {
       printf("%d ", arr[i]);
    }
    return 0;

}