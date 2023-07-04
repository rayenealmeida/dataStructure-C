#include <stdio.h>
#include <math.h>

#include <string.h>
typedef struct{
    char* japones;
    char* portugues;
}Item;

#define key(A) ((A).japones)
#define less(A, B) (strcmp(key(A), key(B) < 0))
#define exch(A, B){Item tmp = A; A=B; B=A;}
#define cmpexch(A,B) {if(less(A,B)) exch(A,B);}

int partition(Item *v, int begin, int end){
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

int deuMerda;
void quicksort(Item *v, int begin, int end, int recursion){
    if(begin >=end){
        return;
    }

    if(recursion == 0){
        deuMerda = 1;
        return;
    }

    int mid = (begin + end)/2;
    cmpexch(v[mid], v[end]);
        cmpexch(v[begin],v[mid]);
            cmpexch(v[end], v[mid]);
    

    int p = partion(v,begin,end);
    quicksort(v, begin, end, recursion-1);
    quicksort(v, begin, end, recursion -1);
}

void introsort(Item *v, int begin, int end){
    int maxRecursion = 2*((int)log2((double)end-begin+1));

    deuMerda = 0;
    quicksort(v, begin, end, maxRecursion);

    if(deuMerda ==1){
        mergeSort(v, begin, end);
    }else{
        insertionSort(v, begin,end);

    }

}

int binarySeach(Item *v, int begin, int end, Item target){
    int mid;

    while(end >= begin){
        mid =(begin+end)/2;

        if(less(v[mid], target)){
            begin = mid+1;
        }else if(less(target,v[mid])){
            end = mid -1;
        }else{
            return mid;
        }
    }
    return -1;
}