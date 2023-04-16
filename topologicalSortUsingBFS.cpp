// to perform topological sort using BFS 
// indegree concept is used here 

#include<iostream>
#include<vector>
#include<unordered_map> 
#include<queue>
using namespace std ;

class graph{

    public : 
    int v ;
 
    graph(int v)
    {
        this->v = v ;
               
    }
    unordered_map<int,vector<int>> adjL;


     void  createGraph(vector<vector<int>> edges)// this constructor will create a graph 
    {   
        for(int i = 0 ;i<v;i++)
        {   
            int flag = 0 ;
            for(int j = 0 ;j<v;j++)
            {
                if(edges[i][j]==1)
                {
                    adjL[i].push_back(j);
                    flag =1 ;
                }
                
           }
            
        }
    }

    void printGraph()
    {
        for(int i = 0 ;i<v;i++)
        {
           cout<<i;
            for(auto& j : adjL[i])
            {
                 cout<<"->"<<(j) ;
            }
            cout<<endl;
        }
    }

    void populateIndegree(vector<int>&inDegree)
    {   

        for(int i = 0 ;i<v;i++)
        {
            for(int &j: adjL[i])
            {
                inDegree[j]++;
            }
        }
    }

    void topologicalSort(queue<int>&topo,vector<int>&inDegree,vector<int>&result)
    {

        while(!topo.empty())
        {
            int u = topo.front();
            topo.pop();
           result.push_back(u);

        

            for(auto v : adjL[u])
            {
                inDegree[v]--;
                if(inDegree[v]==0)
                {
                topo.push(v);
                }

            } 

        }
    }

    
    
};


int main()
{
    int v ;
    cout<<"Enter the vertices : ";
    cin>>v ;
    vector<bool>visited(v,false);
    vector<int>inDegree(v,0) ;
    queue<int>topo ;
    vector<int>result ;

    graph g(v) ;
      

    // relation of edegs through matrix 
    vector<vector<int>> edges(v,vector<int>(v));
    cout<<"enter the relation betweem edges : ";
    for(int i = 0 ;i<v;i++)
    {
        for(int j = 0 ;j<v;j++)
        {
            cin>>edges[i][j];
        }
    }
    // create object of graph 
    g.createGraph(edges) ; 

    g.printGraph();

    // TOPOLOGICAL SORT 

    //step 1 :  populate indegree 

    g.populateIndegree(inDegree);
    //step 2 : the node having 0 indegree put that in 

    for(int i = 0 ;i<v;i++)
    {
        if(inDegree[i]==0)
        {
        topo.push(i);
        }
    }

    for(int i = 0 ;i<v;i++)
    {
        cout<<inDegree[i]<<" ";
    }

    
    //stpe 3 : apply simple BFS 6

    // g.topologicalSort(topo,inDegree,result);

    // //printing in topological sort order 

    // for(int i = 0 ;i<v;i++)
    // {
    //     cout<<result[i]<<" ";
    // }
    
    return 0 ;
}



