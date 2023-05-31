

#include<iostream>
#include<vector> 
using namespace std ;

void ShortestPath(vector<vector<int>> &adjM,int v)
{
    for(int i= 0 ;i<v;i++)
    {
        for(int j = 0 ;j<v;j++)
        {
            if(adjM[i][j]==-1)
            {
                adjM[i][j]=1e9 ;//or INT_MAX for infinity 
            }
        }
    }

    //For Floyd Warshall 


    for(int i = 0 ;i<v;i++)
    {
        for(int j = 0 ;j<v;j++)
        {
            for(int k = 0 ;k<v;k++)
            {
                adjM[j][k] = min(adjM[j][k], adjM[j][i]+adjM[i][k]);
            }
        }
    }

    
}

int main()
{

    int v ;
    cout<<"Enter The No. of Vetrices : ";
    cin>>v ;

   vector<vector<int>>adjM(v,vector<int>(v));

    cout<<"Enter relation between vertices : ";
    for(int i = 0 ;i<v;i++)
    {
        for(int j = 0;j<v;j++)
        {
            cin>>adjM[i][j] ;
        }
    }

    ShortestPath(adjM,v);

    cout<<"Shortest Distance Matrix : ";
    for(int i= 0 ;i<v;i++)
    {
        for(int j = 0 ;j<v;j++)
        {
            cout<<adjM[i][j]<<" ";
        }
        cout<<endl ;
    }

    return 0 ;

}
