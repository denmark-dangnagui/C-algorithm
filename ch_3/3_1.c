#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#pragma warning(disabled:4996)
int idx;
int Heap[100];
void insertitem(int key){

}

int removemax(){
    
    return 1;
}

void upHeap(){

}

void downHeap(){

}


void printHeap(){

}

int main(){
    int num,root;
    char order = '0';
    idx = 1;
    while(order != 'q'){
        scanf("%c",&order);
        getchar();
        if(order == 'i'){
            scanf("%d",&num);
            insertitem(num);
            printf("30\n");
        }
        else if (order == 'd'){
            root = removemax();
            printf("%d\n",root);
        }
        else{
            printHeap();
        }
    }

}