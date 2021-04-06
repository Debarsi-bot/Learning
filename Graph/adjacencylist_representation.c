#include <stdlib.h>
#include <stdio.h>


struct Vertex{
    int info;
    struct Edge* firstEdge;
    struct Vertex* nextVertex;  
}*start=NULL;

typedef struct Vertex Vertex;

struct Edge{
    struct Vertex* destVertex;
    struct Edge* nextEdge;
};
typedef struct Edge Edge;

void deleteVertex(int u);
void insertVertex(int u);
void deleteEdge(int dest,int source);
void insertEdge(int dest,int source);
void deleteIncomingEdges(Vertex* source);
void display();
Vertex* returnVertex(int v);

int main()
{
    int u,v,c;
    while(1)
    {
        printf("Press 1 to insert a vertex\n");
        printf("Press 2 to insert an Edge\n");
        printf("Press 3 to delete a vertex\n");
        printf("Press 4 to delete an edge\n");
        printf("Press 5 to display graph\n");
        printf("Press 6 to exit\n");
        scanf("%d",&c);

        switch(c)
        {
            case 1:
                printf("Enter vertex no \n");
                scanf("%d",&u);
                insertVertex(u);
                break;

            case 2:
                printf("Enter source vertex\n");
                scanf("%d",&u);
                printf("Enter desination vertex\n");
                scanf("%d",&v);
                insertEdge(u,v);
                break;

            case 3:
                printf("Enter vertex no\n");
                scanf("%d",&u);
                deleteVertex(u);
                break;

            case 4:
                printf("Enter source vertex\n");
                scanf("%d",&u);
                printf("Enter desination vertex\n");
                scanf("%d",&v);
                deleteEdge(u,v);
                break;

            case 5:
                display();
                break;

            case 6:
                return 0;

            default:
                printf("Invalid Choice\n");
                continue;
            

        }
    }                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                     
}

/*
Function to find a specific vertex in the list
*/
Vertex* returnVertex(int v){
    Vertex* temp=start;
    while(temp!=NULL){
        if(temp->info==v)
            return temp;
        temp=temp->nextVertex;
    }
    return NULL;
}

/*
Function to insert a vertex into the list
If the List is empty the new vertex will be set to head else 
the new vertex will be pointed as the nextVertex of the now last vertex
*/
void insertVertex(int u){
    Vertex* temp=(Vertex*)malloc(sizeof(Vertex));
    temp->info=u;
    temp->nextVertex=NULL;
    temp->firstEdge=NULL;
    if(!start){
        start=temp;
        return;
    }
    Vertex* it=start;
    while(it->nextVertex)
        it=it->nextVertex;
    
    it->nextVertex=temp;
}

/*
Function to insert an edge to the list.
The function takes as argument the source and destination vertices.
The source vertex is found and the destination vertex is inserted into the edge list
*/

void insertEdge(int dest,int source){
    Edge* temp=(Edge*)malloc(sizeof(Edge));
    Vertex* sourceVertex=returnVertex(source);
    Vertex* destinationVertex=returnVertex(dest);
    if(!sourceVertex||!destinationVertex)
        {
            printf("Invalid edge\n");
            return;
        }
    temp->destVertex=destinationVertex;
    temp->nextEdge=NULL;
    Edge* it=sourceVertex->firstEdge;
    if(!it)
        sourceVertex->firstEdge=temp;
    while(it->nextEdge)
        it=it->nextEdge;
    it->nextEdge=temp;
}

/*
Function to delete an edge taking source and destination vertex as parameter
We find the source vertex and check its list of edges to find the destination vertex and we free that */

void deleteEdge(int dest,int source){
    Vertex* sourceVertex=returnVertex(source);
    Vertex* destinationVertex=returnVertex(dest);
    if(!sourceVertex||!destinationVertex)
        {
            printf("Edge Does not exist\n");
            return;
        }
    Edge* it=sourceVertex->firstEdge;
    if(it->destVertex==destinationVertex)
        {
            sourceVertex->firstEdge=it->nextEdge;
            free(it);
            return;
        }
    Edge* it2=it->nextEdge;
    while(it2->destVertex!=destinationVertex){
        it=it2;
        it2=it2->nextEdge;
    }
    it->nextEdge=it2->nextEdge;
    free(it2);
}

/*
Functio to delete incoming Edges of a vertex
*/
void deleteIncomingEdges(Vertex* source){
    Vertex* it=start;
    while(it){
        if(it==source)
            continue;
        Edge* currentEdge=it->firstEdge;
        Edge* prevEdge=it->firstEdge;
        if(currentEdge->destVertex==source){
            it->firstEdge=currentEdge->nextEdge;
            free(currentEdge);
            continue;
        }
        currentEdge=currentEdge->nextEdge;
        while(currentEdge->destVertex!=source&&currentEdge!=NULL){
            prevEdge=currentEdge;
            currentEdge=currentEdge->nextEdge;
        }
        if(!currentEdge)
            return;
        prevEdge->nextEdge=currentEdge->nextEdge;
        free(currentEdge);
        
    }
    it=it->nextVertex;
}

/*
Function to delete a vertex
It deletes the vertex in the list and all the edges in other vetrices list*/

void deleteVertex(int vertexToDelete)
{
    Vertex* find=returnVertex(vertexToDelete);
    if(!find){
        printf("Vertex Not Present\n");
        return;
    }
    deleteIncomingEdges(find);
    Vertex* it=start;
    if(it==vertexToDelete){
        start=it->nextVertex;
        free(it);
        return;
    }
    Vertex* it2=start;
    it=it->nextVertex;
    while(it){
        if(it==vertexToDelete){
            it2->nextVertex=it->nextVertex;
            free(it);
            return;
        }
    }
}

void display()
{
    Vertex* it=start;
    
}