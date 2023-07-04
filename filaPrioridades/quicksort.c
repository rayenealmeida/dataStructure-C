#include <stdio.h>

typedef int Item;
#define less(A,B) ((A) < (B))
#define exch(A, B){Item tmp = A; A=B; B=A;}
#define cmpexch(A,B) {if(less(A,B)) exch(A,B);}

int partition(int *v, int begin, int end){
    int i = begin -1;
    int j = end;

    for(;;){
        while(less(v[++i], v[end])){}

        while(less(v[end], v[--j])){
            if(j == begin){
                break;
            }
        }
        if(i>=j){
            break;
        }
        exch(v[i], v[j]);
    }
    exch(v[i],v[end]);
    return i;
}

void quicksort(Item *v, int begin, int end){
    if(begin >=end){
        return;
    }
    int mid = (begin + end)/2;
    cmpexch(v[mid], v[end]);
        cmpexch(v[begin],v[mid]);
            cmpexch(v[end], v[mid]);
    

    int p = partion(v,begin,end);
    quicksort(v, begin, end);
    quicksort(v, begin, end);
}