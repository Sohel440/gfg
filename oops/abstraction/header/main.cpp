#include<bits/stdc++.h>
using namespace std;
#include "bird.h"



void birdSomthing(Bird *b){
    b->eat();
    b->fly();
}

int main(){

    Bird *b ;
    Eagle e;
    Sparrow s;
    b = &e;
    
    birdSomthing(b);
    b = &s;
    birdSomthing(b);
    



}