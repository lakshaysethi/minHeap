#include <stdio.h>
#include <stdlib.h>
int comparisonCount=0;
int index=1;
void insert(int value,int * heapArray){
    int pointerIndex = index-1;//I have taken a pointer
    int key = value;//to debug
    if(pointerIndex==0){// root is empty
        heapArray[0]=value;
    }else if(value>=heapArray[(int)(pointerIndex)/2]){//if grater just add to the end of the array
        heapArray[pointerIndex]=value;
        comparisonCount++;
    }else if(value<heapArray[(int)(pointerIndex)/2]){//if smaller swap till not smaller or root is reached
        while((value < heapArray[(int)(pointerIndex)/2])&&pointerIndex!=0 ){
                heapArray[pointerIndex]=heapArray[(int)(pointerIndex)/2];
                heapArray[(int)(pointerIndex)/2] = value;
                pointerIndex =(int)(pointerIndex/2);
                comparisonCount++;
             }
        pointerIndex = index-1;
    }




    index++;

}



int * CreateBinaryHeap(int *heap, int n){


int minheap[n];

for(int i=0;i<n;i++){//makes the heap
    insert(heap[i], minheap);
}
printf("the min heap is :\n");//prints the heap
for(int i=0;i<n;i++){
    printf("%d\n",minheap[i]);
}
printf("the minimum value in heap is : %d\n",minheap[0]);
printf("the total number of comparisons are :%d\n", comparisonCount);

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
