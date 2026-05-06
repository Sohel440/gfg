#include<stdio.h>
void swap(int *a , int *b){

    int temp = *a;
    *a = *b;
    *b = temp;

}
void heapify(int arr[] , int N , int i){

    int largest = i;
    int l = 2*i + 1;
    int r = 2* i + 2;

    if(l < N && arr[l] > largest){
        largest = l;

    }
    if(r < N && arr[r] > largest){
        largest = r;

    }
    if( largest != i){
        swap(&arr[i], &arr[largest]);
    heapify(arr , N , largest);

    }
}
void hreapsort(int arr[] ,int N ){
   int i;
   for (i =N/2 -1 ; i >= 0 ; i--)
   heapify(arr, N ,i);
   for ( i = N-1; i >=0 ; i--){
    swap(&arr[0] , &arr[i]);

    heapify(arr, N , 0);

   }
   
   
}
int main(){

int arr[] = {12 ,3 ,5};
hreapsort(arr, 3);
int i;
 for ( i = 0; i < 3; i++)
    {
       printf("%d ", arr[i]);
    }
    return 0;

}