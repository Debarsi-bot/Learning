#include "matrix_graph.h"
int main()
{
    int noOfVertices;
    printf("Enter no of Vertices\n");
    scanf("%d",&noOfVertices);
    int**arr,**path;
    initializeDoubleDimArray(&arr,noOfVertices);
    initializeDoubleDimArray(&path,noOfVertices);
    createGraph(&arr,noOfVertices);
    for(int i=0;i<noOfVertices;i++)
        for(int j=0;j<noOfVertices;j++)
            path[i][j]=arr[i][j];
    
    for(int k=0;k<noOfVertices;k++)
        {
            for(int i=0;i<noOfVertices;i++)
                for(int j=0;j<noOfVertices;j++)
                    path[i][j]=path[i][j]||(path[i][k]&&path[k][j]);

        }
    display(&path,noOfVertices);



}