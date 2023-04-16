// to find if a graph cam be divided into two parts 

#include<iostream>
#include<vector>
#include<unordered_map>
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

    bool checkBipartite(int curN,vector<int>color,int curC)
    {
        color[curN]=curC;

        for(auto v : adjL[curN])
        {
            if(color[v]==color[curN])
            return false ;

            if(color[v]==-1)
            {
                int colV = 1-curC ;
                if(checkBipartite(v,color,colV)==false)
                return false ;
            }
        }

        return true ;
    }

    
};


int main()
{
    int v ;
    cout<<"Enter the vertices : ";
    cin>>v ;
    vector<int>color(v,-1);

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

   //To find if A graph is Bipartite 

    for(int i = 0 ;i<v;i++)
    {
        if(color[i]==-1 && g.checkBipartite(i,color,1))
        {
            cout<<"Bipartite ";
            return 0;
        }
    }
   
    cout<<" Not Bipartite";


    return 0 ;
}



