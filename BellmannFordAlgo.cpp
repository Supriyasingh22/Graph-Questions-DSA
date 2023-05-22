

#include<iostream>
#include<vector> 
#include<limits.h>

using namespace std ;

class Graph{

    int v ;
   int e = 5 ;
    vector<vector<int>>Edges ;

    public : 
    Graph(int v)  
    {
        this->v = v ;
    }

    void createEdges(vector<vector<int>>matrix)
    {
        int idx = 0 ;
        Edges.resize(e);

          for(int i=0;i<v;i++)
            {
                for(int j=0;j<v;j++)
                {
                    if(matrix[i][j]!=0)
                    {
                        Edges[idx].push_back(i);
                        Edges[idx].push_back(j);
                        Edges[idx].push_back(matrix[i][j]);
                        idx++;

                    }

                }
            }
        

    }

    
    void findShortest(int s)
    {
        vector<int>result(v,INT_MAX);
        result[s]=0 ;

        for(int i = 0;i<v;i++)//vertex 
        {
            for(int j=0;j<v;j++)//edges             {
            {
                int u = Edges[j][0];
                int r = Edges[j][1];
                int wt = Edges[j][2];
                // cout<<u<< " "<<r<<" " << wt<<" "<<result[r]<<" "<<result[u]<<endl;
                if(result[u]!=INT_MAX && (result[u]+ wt)<result[r])
                {
                    
                    result[r]=result[u]+wt ;
                }
                


            }

        }

        for(int i=0;i<v;i++)
        {
            cout<<i<<"->"<<result[i]<<endl ;
        }
    }

   




};

int main()
{
    int v ;
    cout<<"Enter the number of vertices : ";
    cin>> v ;

    vector<vector<int>>matrix(v,vector<int>(v));

    cout<<"Enter the relation between nodes : ";
    for(int i = 0 ;i<v;i++)
    {
        for(int j = 0 ;j<v;j++)
        {
            cin>>matrix[i][j] ;
        }
    }

    int S ;
    cout<<"Enter the source : ";
    cin>>S  ;

    Graph g(v);

    g.createEdges(matrix);

    g.findShortest(S);

    return 0 ;


}