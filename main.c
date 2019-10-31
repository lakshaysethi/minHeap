#include <stdio.h>
#include <stdlib.h>

int index=1;
void insert(int value,int * heapArray){
    int pointerIndex = index-1;
    int key = value;
    if(pointerIndex==0){
        heapArray[0]=value;
    }else if(value>=heapArray[(int)(pointerIndex)/2]){//(1st -1 because we are using indexes +1 2nd - 1 because i want previous position check
        heapArray[pointerIndex]=value;

    }else if(value<heapArray[(int)(pointerIndex)/2]){
        while((value < heapArray[(int)(pointerIndex)/2])&&pointerIndex!=0 ){
                heapArray[pointerIndex]=heapArray[(int)(pointerIndex)/2];
                heapArray[(int)(pointerIndex)/2] = value;
                pointerIndex =(int)(pointerIndex/2);
             }
        pointerIndex = index-1;
    }




    index++;

}



int * CreateBinaryHeap(int *heap, int n){


int minheap[n];

for(int i=0;i<n;i++){
    insert(heap[i], minheap);
}
printf("the min heap is :\n");
for(int i=0;i<n;i++){
    printf("%d\n",minheap[i]);
}


return minheap;

}




int main()
{

int k = 100;// size of given array
int heap[k];//given array
int n = 10;//elements in heap
printf("random array is \n");
for(int i=0;i<n;i++){//inserting random elements in array
   heap[i]=rand()%100;
   printf("%d\n",heap[i]);//prints the random number in array

}



CreateBinaryHeap(heap,n);

    return 0;
}
