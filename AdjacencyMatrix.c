// to implement graph using adjacency matrix 

#include<stdio.h>
#define n 3
void representation(int final[][n],int edges[][2],int rows)
{
    for(int i = 0 ;i<rows;i++)
    {
        
            int  a = edges[i][0];
            int b = edges[i][1];
            final[a][b]=1;
        
    }
}
int main()
{
    
    // to store edges we have 2-D matrix 
    int rows ;
    int cols = 2 ;
    printf("enter the no. of rows : ");
    scanf("%d",&rows);
    int edges[10][2];
    // now put relation between different nodes or edges 

    printf("enter edges : ");
    for(int i = 0 ;i<rows;i++)
    {
        for(int j = 0 ;j<cols;j++)
        {
            scanf("%d",&edges[i][j]);
        }
    }

    
    // represent it in the form of adjacency matrix 
    int final[n][n]={0};
    representation(final,edges,rows);

    // print final representation of graph in matrix form 

    printf("representation of graph in matrix forms ");
    for(int i = 0;i<n;i++)
    {
        for(int j = 0 ;j<n;j++)
        {
            printf("%d ",final[i][j]);
        }
        printf("\n");
    }


    return 0 ;

}