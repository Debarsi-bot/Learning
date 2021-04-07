#include <stdio.h>
#include <stdlib.h>
void display(int ***arr,int size)
{
    int i,j;
    for(i=0;i<size;i++)
        printf("\t%d",i);
    printf("\n\t");
    for(i=0;i<size;i++)
        printf("-\t");
    printf("\n");
    for(i=0;i<size;i++){
        printf("%d|      ",i);
        for(j=0;j<size;j++){
            printf("%d\t",(*arr)[i][j]);
        }
        printf("\n");
    }
}

void createGraph(int ***arr,int noOfVertices)
{
    printf("Enter -1 -1 as vertices to quit\n");
    int origin,destination;
    while(1){
        printf("Enter vertices as origin,destination\n");
        scanf("%d %d",&origin,&destination);
        if(origin==-1&&destination==-1)
            return;
        if(origin<0||destination<0||origin>=noOfVertices||destination>=noOfVertices)
        {
            printf("Invalid vertices\n");
            continue;
        }
        (*arr)[origin][destination]=1;
        
    }
}

void initializeDoubleDimArray(int***arr,int size){
    (*arr)=(int**)malloc(size*sizeof(int*));
    for(int i=0;i<size;i++)
        {
            (*arr)[i]=(int*)malloc(size*sizeof(int));
        }
}
