// #include<stdio.h>
// int knapsack(int W, int wt[], int val[], int n) {
//    int i, w;
//    int knap[n+1][W+1];
//    for (i = 0; i <= n; i++) {
//       for (w = 0; w <= W; w++) {
//          if (i==0 || w==0)
//             knap[i][w] = 0;
//          else if (wt[i-1] <= w)
//             knap[i][w] = max(val[i-1] + knap[i-1][w-wt[i-1]], knap[i-1][w]);
//          else
//             knap[i][w] = knap[i-1][w];
//       }
//    }
//    return knap[n][W];
// }

// int max(int a,int b){
// 	if(a>b){
// 		return a;
// 	}else{
// 		return b;
// 	}
// }
// int main(){
// 	int val[]={25,15,10};
// 	int wt[]={18,15,10};
// 	int w=20;
// 	int n=sizeof(val)/sizeof(val[0]);
// 	printf("the solution is: %d",knapsack(w,wt,val,n));
// 	return 0;
// }
#include<stdio.h>
int knapsack(int W , int wt[], int val[], int n){
 int knap[n+1][W+1];
 int i ,w;
 for(i =0 ;i <= n;i++){
    for(w = 0; w <= W;w++){
        if(i==0|| w==0)
        knap[i][w]=0;
        else if(wt[i-1] <= w)
                    knap[i][w] = max(val[i-1] + knap[i-1][w-wt[i-1]], knap[i-1][w]);
        else
        knap[i][w] = knap[i-1][w];

    }
 }
 return knap[n][W];
}
int max(int a , int b){
    if(a>b)
    return a;
    else
    return b;
}

int main(){
 	int val[]={25,15,10};
	int wt[]={18,15,10};
	int w=20;
	int n=sizeof(val)/sizeof(val[0]);
	printf("the solution is: %d",knapsack(w,wt,val,n));
	
}
