//computing path matrix from powers of Adjacency matrix
#include <stdio.h>
#include "matrix_graph.h"

void multiply(int***arr1,int***arr2,int n){                         //matrix(A)=matrix(A)*matrix(B)
    int temp[n][n];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            temp[i][j]=0;
            for(int k=0;k<n;k++)
                {
                    temp[i][j]+=((*arr1)[i][k]*(*arr2)[k][j]);
                }
        }
    }
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            (*arr1)[i][j]=temp[i][j];
}

void add(int***arr1,int***arr2,int n){
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            (*arr1)[i][j]+=(*arr2)[i][j];
}

int main()
{
    int noOfVertices,origin,destination;
    printf("Enter no of vertices\n");
    scanf("%d",&noOfVertices);
    int **arr,**powerMatrix,**sum,**path;
    int c;
    initializeDoubleDimArray(&arr,noOfVertices);
    initializeDoubleDimArray(&powerMatrix,noOfVertices);
    initializeDoubleDimArray(&sum,noOfVertices);
    initializeDoubleDimArray(&path,noOfVertices);

    int maxEdges=noOfVertices*(noOfVertices-1);
    createGraph(&arr,noOfVertices);
    for (int i = 0; i < noOfVertices; i++)
    {
        for(int j=0;j<noOfVertices;j++)
            sum[i][j]=powerMatrix[i][j]=arr[i][j];
    }

    for(int i=1;i<noOfVertices;i++){
        multiply(&powerMatrix,&arr,noOfVertices);
        printf("A^%d",(i+1));
        display(&powerMatrix,noOfVertices);
        add(&sum,&powerMatrix,noOfVertices);
        printf("\n");
    }
    display(&sum,noOfVertices);
    for(int i=0;i<noOfVertices;i++)
        for(int j=0;j<noOfVertices;j++)
            path[i][j]=(sum[i][j]==0?0:1);
    printf("\nPath Matrix\n");
    display(&path,noOfVertices);


}