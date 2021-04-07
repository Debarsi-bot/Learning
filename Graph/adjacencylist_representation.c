#include <stdlib.h>
#include <stdio.h>


struct Vertex{                  //structure of node of vertex
    int info;
    struct Edge* firstEdge;
    struct Vertex* nextVertex;  
}*start=NULL;

typedef struct Vertex Vertex;

struct Edge{                    //structure of node of an edge
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
If vertex already exist a message will be printed
If the List is empty the new vertex will be set to head else 
the new vertex will be pointed as the nextVertex of the now last vertex
*/
void insertVertex(int u){
    Vertex* temp=(Vertex*)malloc(sizeof(Vertex));
    temp->info=u;
    temp->nextVertex=NULL;
    temp->firstEdge=NULL;
    if(!start){                 //if the list is empty set the new vertex as the head
        start=temp;
        return;
    }
    Vertex* it=start;
    while(it->nextVertex){      //check if the vertex already exist and also move to the end of the list
        if(it->info==u)
            break;
        it=it->nextVertex;
    }
    if(it->info==u){            //if the vertex already exist show a message
        free(temp);
        printf("Vertex already exists\n");
        return;
    }
    it->nextVertex=temp;        //attach the new vertex at the end of the list
}

/*
Function to insert an edge to the list.
The function takes as argument the source and destination vertices.
The source vertex is found and the destination vertex is inserted into the edge list
if edge already exist it will print a message
*/

void insertEdge(int source,int dest){
    Edge* temp=(Edge*)malloc(sizeof(Edge));
    Vertex* sourceVertex=returnVertex(source);
    Vertex* destinationVertex=returnVertex(dest);
    if(!sourceVertex||!destinationVertex)       //if the vertex of required edges don't exist print a message
        {
            printf("Invalid edge\n");
            return;
        }
    temp->destVertex=destinationVertex;
    temp->nextEdge=NULL;
    Edge* it=sourceVertex->firstEdge;
    if(!it){                            //if no edges of the source vertex exist set this edge as the firstEdge
        sourceVertex->firstEdge=temp;
        return;
    }
    while(it->nextEdge){                            //move to the last edge of the edge list of the vertex
        if(it->destVertex==destinationVertex)       //if the edge already exists break
            break;
        it=it->nextEdge;
        
    }
    if(it->destVertex==destinationVertex)       //if edge already exist print a message
        {
            printf("Edge already exist\n");
            return;
        }
    it->nextEdge=temp;                      //set the last edge as the required edge
}

/*
Function to delete an edge taking source and destination vertex as parameter
We find the source vertex and check its list of edges to find the destination vertex and we free that */

void deleteEdge(int source,int dest){               
    Vertex* sourceVertex=returnVertex(source);
    Vertex* destinationVertex=returnVertex(dest);
    if(!sourceVertex||!destinationVertex)               //if the vertex of the edges don't exist print a message
        {
            printf("Vertice of Edge Does not exist\n");
            return;
        }
    Edge* currentEdge=sourceVertex->firstEdge;          
    if(currentEdge->destVertex==destinationVertex)      //if the firstEdge of the vertex is the required edge
        {
            sourceVertex->firstEdge=currentEdge->nextEdge;
            free(currentEdge);
            return;
        }
    Edge* previousEdge=currentEdge;
    currentEdge=currentEdge->nextEdge;
    while(currentEdge->destVertex!=destinationVertex&&!currentEdge){    //exit when destination vertex is found or we reach end of list
        previousEdge=currentEdge;
        currentEdge=currentEdge->nextEdge;
    }
    if(!currentEdge){                                                   //if the edge is not found print a message
        printf("Edge does not exist\n");
        return;
    }
    free(currentEdge);                                                  
}

/*
Functio to delete incoming Edges of a vertex
*/
void deleteIncomingEdges(Vertex* source){
    printf("Inside deleteIncoming\n");
    Vertex* it=start;
    while(it){                              //loop to iterate through all vertices
        if(it==source){                     //we dont need to individually delete incoming vertices from the vertice that is to be deleted since the whole vertex will be deleted later
            it=it->nextVertex;
            continue;
        }
        Edge* currentEdge=it->firstEdge;
        Edge* prevEdge=it->firstEdge;
        if(!currentEdge){                   //if the edge list is empty move to the next vertex              
            it=it->nextVertex;
            continue;
        }
        if(currentEdge->destVertex==source){    //if the required edge is found at the start free the memory and set firstEdge as the next edge
            it->firstEdge=currentEdge->nextEdge;
            free(currentEdge);
            it=it->nextVertex;
            continue;
        }
        currentEdge=currentEdge->nextEdge;
        while(currentEdge!=NULL&&currentEdge->destVertex!=source){  //keep on iterrating until the list ends or the required edge with destination vertex as the vertex to be deleted is found
            prevEdge=currentEdge;
            currentEdge=currentEdge->nextEdge;
        }
        if(!currentEdge)                            //if edge is not found move to the next vertex
            {
                it=it->nextVertex;
                continue;
            }
        prevEdge->nextEdge=currentEdge->nextEdge;   //edge is found free the memory 
        free(currentEdge);
        it=it->nextVertex;
    }
}

/*
Function to delete a vertex
It deletes the vertex in the list and all the edges in other vetrices list*/

void deleteVertex(int vertexToDelete)
{
    Vertex* find=returnVertex(vertexToDelete);
    if(!find){                                  //vertex to be deleted does not exist
        printf("Vertex Not Present\n");
        return;
    }
    deleteIncomingEdges(find);                  //delete all incoming edges to the vertex
    
    Vertex* it=start;
    if(it==find){                               //if vertex is the head of the list make the next vertex as the head and free the memory
        start=it->nextVertex;
        free(it);
        return;
    }
    Vertex* it2=start;
    it=it->nextVertex;
    while(it){
        if(it==find){                           //required vertex is found, free the memory
            it2->nextVertex=it->nextVertex;
            free(it);
            return;
        }
        it2=it;
        it=it->nextVertex;
    }
}

void display()                                          //display the graph
{
    Vertex* iteratorVertex=start;
    while(iteratorVertex){
        Edge* iteratorEdge=iteratorVertex->firstEdge;
        printf("\n%d->\t",iteratorVertex->info);
        while (iteratorEdge)
        {
            printf("%d  ",iteratorEdge->destVertex->info);
            iteratorEdge=iteratorEdge->nextEdge;
        }
        printf("\n");
        iteratorVertex=iteratorVertex->nextVertex;
        
    }
}