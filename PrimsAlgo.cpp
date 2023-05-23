

#include<iostream>
#include<unordered_map>
#include<vector>
#include<climits>
using namespace std ;

class Graph{

    int v ;
    int e ;

    unordered_map<int,vector<pair<int,int>>>adjL ;
    vector<int>key ;
    vector<bool>visited ;
    vector<int>parent ;

    public : 
    Graph(int v,int e)
    {
        this->v = v ;
        this->e = e ;
        key = vector<int>(v,INT_MAX);
        visited = vector<bool>(v,false);
        parent = vector<int>(v,-1);
        key[0]=0;
        parent[0]=-1 ;


    }

    // creating Graph 

    void CreateGraph(vector<vector<int>>relation)
    {
        for(int i = 0 ;i<v;i++)
        {
            for(int j = 0 ;j<v;j++)
            {
                if(relation[i][j]!=0)
                {
                    adjL[i].push_back({j,relation[i][j]});
                }
            }
        }
    }

    
    void MinimumS(vector<pair<pair<int,int>,int>>& result)
    {
        for(int i = 0 ;i<v;i++)
        {
            int mini = INT_MAX ;
            int u ;

            for(int j = 0 ;j<v;j++)
            {

                if(visited[j]==false && key[j]<mini)
                {
                    u = j ;
                    mini = key[j];
                }

            }

            visited[u]=true ;

            for(auto it : adjL[u])
            {
                int p = it.first;
                int q = it.second ;
                if(visited[p]==false && q<key[p])
                {
                    parent[p]=u;
                    key[p]=q;
                }
            }
        }

        for(int i = 1;i<v;i++)
        {
            result.push_back({{parent[i],i},key[i]});
            
        }

     

    }


};

int main()
{
    int v ,e ;
    cout<<"Enter the number of vertex and edges : ";
    cin>>v>>e ;

    Graph g(v,e);

    vector<vector<int>>relation(v,vector<int>(v));
    cout<<"Enter the relation between edges and it's weight  ";
    for(int i= 0 ;i<v;i++)
    {
        for(int j= 0 ;j<v;j++)
        {
            cin>>relation[i][j];
        }
    }


    //graph Creation 
    g.CreateGraph(relation) ;

    vector<pair<pair<int,int>, int>> result ;
    g.MinimumS(result) ;

    int sum = 0 ;

    for(auto it : result )
    {
        sum+=it.second ;
    }

    cout<<"Minimum cost is : "<<sum ;

    return 0 ;


}