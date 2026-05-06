// #include<stdio.h>
// #include<stdlib.h>

// #define N 10

// int x[N];

// int place(int k,int i,int x[])
// {
//     int j;
//     for(j=1;j<k;j++)
//     {
//         if(x[j]==i || abs((x[j])-i)==(abs(j-k)))
//         return 0;
//     }
//     return 1;
// }

// void N_queen(int k,int n,int x[])
// {
//     int i,j;
//     for(i=1;i<=n;i++)
//     {
//         if(place(k,i,x))
//         {
//             x[k]=i;
//             if(k==n)
//             {
//                 for(j=1;j<=n;j++)
//                 printf("%d ",x[j]);
//                 printf("\n");
//             }
//             else
//             N_queen(k+1,n,x);
//         }
//     }
// }

// int main(){
//     int n,i,j;
//     printf("Enter the size of the box:");
//     scanf("%d",&n);
//     printf("The possible solutions are:-\n");
//     N_queen(1,n,x);
//     return 0;
// }
#include<stdio.h>
int x[10];
int place(int k , int i , int x[]){
  
  int j ;
  for(j =1 ; j <k ;j++){
    if(x[j]==i || (abs(x[j]-i) ) == (abs(j-k)))
        return 0;
    

  }
  return 1;
}

void N(int k , int n , int x[]){

    int i , j ;
    for(i =1 ; i <= n ;i++){

        if(place(k , i, x)){
            x[k]=i;
            if(k==n){
                for(j =1 ; j <= n ;j++)
                printf("%d",x[j]);

                printf("\n");
            }else{
                N(k+1, n , x);
            }
        }
    }
}
int main(){

    int n ;
    printf("Enter the value : ");
    scanf("%d", &n);
    printf("the ans is : ");
    N(1, n, x);
    return 0;
}