// To Detect Cycle in a graph using Topological sort as Topological sort works only on DAG(Directed Acyclic Graph ) 

#include<iostream>
#include<unordered_map>
#include<vector> 
#include<queue>
using namespace std ;


class Graph{

    int v ;
    unordered_map<int,vector<int>>adjL;

    public : 
    Graph(int v)
    {
        this->v = v ;
    }

//     Graph creation from matrix 
    void CreateGraph(vector<vector<int>>edges)
    {
        for(int i = 0 ;i<v;i++)
        {
            for(int j =0 ;j<v;j++)
            {
                if(edges[i][j]==1)
                {
                    adjL[i].push_back(j);
                }
            }
        }
    }
// Printing Graph 
    void printGraph()
    {
        for(auto i : adjL)
        {
            cout<<i.first;
            for(auto v : adjL[i.first])
            {
                cout<<"->"<<v ;
            }
            cout<<endl ;
        }
    }

//     for Cycle Detection 
    bool isCycle(vector<bool>&visited)
    {
        queue<int>que ;
        vector<int>inDegree(v,0); //to keep count of indegree of a node 
        int count = 0 ;

        
//         Counting each indegree 
        for(int i = 0 ;i<v;i++)
        {
            for(auto j : adjL[i])
            {
                inDegree[j]++;
            }
        }
        
//         the Node having 0 indegree is pushed into queue 

        for(int i = 0 ;i<v;i++)
        {
            if(inDegree[i]==0)
            {
                que.push(i);
                visited[i]=true ;
                count++;
            }
        }

//         while queue is not empty we will keep traversing to it's child and decreasing their indegree 
        while(!que.empty())
        {
            int node = que.front();
            que.pop();

            for(auto j : adjL[node])
            {
                inDegree[j]--;
                visited[j]==true ;
                if(inDegree[j]==0)
                {
                    que.push(j);
                    count++;
                }
            }
        }


        if(count==v)//if count is equal to v that means no cycle is there 
        {
            return false ;
        }
        else //id count is not equal to v that means not all node are pushed to the queue
        {
            return true ;
        }
    }

    

};


int main()
{
    int v ;
    cout<<"Enter The No. of vertices : ";
    cin>> v ;

    vector<vector<int>>edges(v,vector<int>(v)) ;
    cout<<"Enter relation between nodes : ";
    for(int i = 0 ;i<v;i++)
    {
        for(int j = 0 ;j<v;j++)
        {
            cin>>edges[i][j];
        }
    }
    Graph g(v);

    // creating and printing graph 
    g.CreateGraph(edges);
    g.printGraph();

    // Detect Cycle Using BFS 
    vector<bool>visited(v,false);
    for(int i = 0 ;i<v;i++)
    {
        if(!visited[i] && g.isCycle(visited))
        {
            cout<<"cycle Exists " ;
            return 0 ;
        }
    }
    cout<<"No such Cycle Exists ";


     return 0 ;
}
