
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std ;

bool cmp(vector<int>&a,vector<int>&b)
{
    return a[2]<b[2];
}

void Initialize(int n,vector<int>&parent,vector<int>&rank)
{
    for(int i = 0 ;i<n;i++)
    {
        parent[i]=i;
        rank[i]=0;
    }
}

int findParent(vector<int>&parent,int node)
{
    if(parent[node]==node)
    {
        return node ;
    }
    return parent[node]= findParent(parent, parent[node]);

}

void UnionSet(int u ,int v, vector<int>&parent,vector<int>&rank)
{   
    u = findParent(parent,u);
    v = findParent(parent, v);
   
    if(rank[u]<rank[v])
    {
        parent[u] = v;
    }
    else if(rank[v]<rank[u])
    {
        parent[v]=u ;
    }
    else{
        parent[v]=u ;
        rank[u]++ ;
    }


}



int main()
{
    int V ;
    cout<<"Enter the no. of nodes : ";
    cin>>V ;

    vector<vector<int>>matrix(V,vector<int>(V));
    cout<<"Enter realtion between edegs :";
    for(int i= 0 ;i<V;i++)
    {
        for(int j = 0 ;j<V;j++)
        {
            cin>>matrix[i][j];
        }
    }

    //creating edegs 
    vector<vector<int>>edges;
    
    
    for(int i = 0 ;i<matrix.size();i++)
    {
        for(int j= i+1 ;j<matrix[i].size();j++)
        {   
            if(matrix[i][j]!=0)
            {
            edges.push_back({i, j, matrix[i][j]});
            }
        }
    }

    
    sort(edges.begin(),edges.end(),cmp);

    vector<int>parent(V);
    vector<int>rank(V);

    Initialize(V,parent,rank);

    // consider each edge 
    int minWt = 0 ;
    for(int i= 0 ;i<edges.size();i++)
    {
        int u = findParent(parent,edges[i][0]);
        int v = findParent(parent, edges[i][1]);
        int wt = edges[i][2];

        if(u!=v)
        {
            minWt+=wt ;
            UnionSet(u,v,parent,rank);
        }
    }

    cout<<"Minimum Weight is :"<<minWt<<endl ;

    return 0 ;
}