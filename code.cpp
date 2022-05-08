#include <iostream>
#include<bits/stdc++.h>
using namespace std;
void findpath(vector<pair<int,int>> adj[],int n,int src,int des,int heu[])
{
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    pq.push({heu[src],src});
    while(pq.empty()==false)
    {
        int x=pq.top().second;
        cout<<x<<" ";
        pq.pop();
        if(x==des)
          break;
        while(pq.empty()==false)
            pq.pop();
        for(auto it:adj[x])
        {
            pq.push({it.second+heu[it.first],it.first});
            
        }
    }
}
int main()
{
    int n,m;
    cin>>n>>m;
    vector<pair<int,int>> adj[n+1];
    for(int i=0;i<m;i++)
    {
        int u,v,cost;
        cin>>u>>v>>cost;
        adj[u].push_back({v,cost});
    }
    cout<<"Enter heutistc"<<endl;
    int heu[n+1];
    for(int i=1;i<=n;i++)
    {
        cin>>heu[i];
    }
    int src,des;
    cin>>src>>des;
    findpath(adj,n,src,des,heu);
}
