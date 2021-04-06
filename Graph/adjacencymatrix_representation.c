// gcc adjacencymatrix_representation.c -o run
// ./run n


#include <stdio.h>
#include <stdlib.h>

void delete(int***arr,int origin,int destination)
{
    (*arr)[origin][destination]=0;
}

void insert(int***arr,int origin,int destination)
{
    (*arr)[origin][destination]=1;
}

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
