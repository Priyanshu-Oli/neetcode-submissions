class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        vector<vector<int>>adj(n);

        for(auto &e : edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }


        vector<int>vis(n,0);

        if(edges.size()!=n-1){
            return false;
        }
        if(!dfs(0,-1,adj,vis)){
            return false;
        }

        for(int i =0;i <n ; i++){
            if(!vis[i]){
                return false;
            }
        }
        return true;

        


    }
    bool dfs(int node, int parent,vector<vector<int>>&adj,vector<int>&vis){
        vis[node]=1;

        for(int neigh :adj[node]){
            if(!vis[neigh]){

            if(!dfs(neigh, node, adj,vis)){
                return false;
            }
            }
            else if(neigh != parent){
                return false;
            }
        }
        return true;
    }
};
