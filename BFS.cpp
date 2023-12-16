#include <iostream>
#include <bits/stdc++.h>
using namespace std;
class Solution {
    private:
    void bfs(int node,unordered_map<int,bool>&visited,vector<int>adj[],vector<int>&ans){
        queue<int>q;
        q.push(node);
        visited[node]=1;
        while(!q.empty()){
            int frontNode=q.front();
            q.pop();
            ans.push_back(frontNode);
            for(auto nbr:adj[frontNode]){
                if(!visited[nbr]){
                    q.push(nbr);
                    visited[nbr]=1;
                }
            }
        }
    }
  public:
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        unordered_map<int,bool>visited;
        vector<int>ans;
        bfs(0,visited,adj,ans);
        return ans;
        
    }
};