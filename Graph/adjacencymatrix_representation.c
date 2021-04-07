// gcc adjacencymatrix_representation.c -o run
// ./run n
#include <stdio.h>
#include <stdlib.h>
#include "matrix_graph.h"

void delete(int***arr,int origin,int destination)
{
    (*arr)[origin][destination]=0;
}

void insert(int***arr,int origin,int destination)
{
    (*arr)[origin][destination]=1;
}
int main(int argc,char*argv[])
{
    int noOfVertices=atoi(argv[1]);
    int **arr;
    int c;
    arr=(int**)malloc(noOfVertices*sizeof(int*));
    for(int i=0;i<noOfVertices;i++){
        arr[i]=(int*)malloc(noOfVertices*sizeof(int));
    }
    int origin=0,destination=0;
    createGraph(&arr,noOfVertices);
    while(1){  
       
        printf("Press 1 to delete an edge\n");
        printf("Press 2 to insert an edge\n");
        printf("Press 3 to display\n");
        printf("Press 4 to exit\n");
        scanf("%d",&c);
        switch(c)
        {
            case 1:
                printf("Enter vertices as origin,destination\n");
                scanf("%d %d",&origin,&destination);
                delete(&arr,origin,destination);
                break;
            
            case 2:
                printf("Enter vertices as origin,destination\n");
                scanf("%d %d",&origin,&destination);
                insert(&arr,origin,destination);
                break;
            case 3:
                display(&arr,noOfVertices);
                break;

            case 4:
                return EXIT_SUCCESS;
            
            default:
                break;
        }
    }
}
