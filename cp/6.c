// #include<stdio.h>
// #include<conio.h>
// int s[10],d,n,set[10],count=0;
// void display(int);
// int flag=0;
// void main()
// {
// int subset(int,int);
// int i;
// //clrscr();
// printf("Enter the number of elements in set\n");
// scanf("%d",&n);
// printf("Enter the set values\n");
// for(i=0;i<n;++i)
// scanf("%d",&s[i]);
// printf("Enter the sum\n");
// scanf("%d",&d);
// printf("The progrm output is\n");
// subset(0,0);
// if(flag==0)
// printf("there is no solution");
// getch();
// }
// int subset(int sum,int i)
// {
// if(sum==d)
// {
// flag=1;
// display(count);
// return;
// }
// if(sum>d||i>=n)
// return;
// else
// {
// set[count]=s[i];


// count++;
// subset(sum+s[i],i+1);
// count--;
// subset(sum,i+1);
// }
// }
// void display(int count)
// {
// int i;
// printf("{");
// for(i=0;i<count;i++)
// printf("%d",set[i]);
// printf("}");
// }

// 
// #include<stdio.h>
// int d , s[10], set[10] ,n, count;
// int flag =1;

// void display(int count ){

//    int i ;
//    printf("[");
//    for( i = 0 ; i < count ;i++){
//     printf("%d", set[i]);
//     printf("]");
//    }
// }
// int subset(int sum , int i){

//     if(sum == d){
//         flag=1;
//         display(count);

//         return;
//     }
//     if(sum > d|| i >=n){
//         return;
//     }
//     else{

//         set[count] = s[i];

//         count++;
//         subset(sum+s[i] , i+1);
//         count--;
//         subset(sum ,i+1);

//     }
// }
// int main(){
// // int subset(int,int);
// int i;
// //clrscr();
// printf("Enter the number of elements in set\n");
// scanf("%d",&n);
// printf("Enter the set values\n");
// for(i=0;i<n;++i)
// scanf("%d",&s[i]);
// printf("Enter the sum\n");
// scanf("%d",&d);
// printf("The progrm output is\n");
// subset(0,0);
// if(flag==0)
// printf("there is no solution");

// }

// #include<stdio.h>
// int d , sum , count, n , s[10], set[10];
// int flag =1;
// void display(int count){
//     int i ;
//     printf("{");

//     for ( i = 0; i < count; i++)
//     {
//         printf("%d,", set[i]);
      

//     }
//       printf("}");
    
// }

// int subset(int sum , int i){

//     if(sum == d){
//         flag=1;
//         display(count);
//         return;

//     }
//     if(sum > d || i >= n){
//         return;
//     }
//     else{
//         set[count] = s[i];

//         count++;
//         subset(sum+s[i] , i+1);
//         count--;
//         subset(sum,i+1);

//     }
// }
// int main(){

    // int i ;
    // printf("Enter the no of element: ");
    // scanf("%d" , &n);
    // printf("Enter the set:");
    // for ( i = 0; i < n; i++)
    // {
    //     scanf("%d", &s[i]);
        
    // }
    // printf("Enter the sum : ");
    // scanf("%d", &d);
    // subset(0,0);
    // if(flag ==0)
    // printf("We can't make set by this sum: ");
    // return 0;
    
// }
#include<stdio.h>
int s[10] , set[10], d ,n, sum , count;
int flag =1;
void display(int count){
    int j ;
    printf("{");
    for(j =0 ; j <count ; j++){
        printf("%d,", set[j]);
    }
    printf("}");
}
int subset(int sum , int i){
    if(sum == d){
        flag =1;
        display(count);
        return ;

    }
    if(sum >d || i>= n){
        return;
    }
    else{
        set[count]= s[i];
        count++;
        subset(sum + s[i] , i+1);
        count--;
        subset(sum , i+1);


    }
}
int main(){
   

 int i ;
 printf("Enter the no of element: ");
 scanf("%d", &n);
 printf("Enter the set: ");
 for(i =0; i <n ;i++){
    scanf("%d", &s[i]);

 }
 printf("Enter the sum: ");
 scanf("%d", &d);

 subset(0,0);
 if(flag==0){
    printf("NOt valid");
 }

}


