class Solution {
public:
    /*
    Just find no. of different components present in a graph
    and find the no. of pairs made by each component
    */
    int bfs(int node, vector<int> adj[],vector<int> &vis){
        int nodes = 0;
        
        queue<int> q;
        q.push(node);
        
        vis[node] = 1;
        
        while(!q.empty()){
            int curnode = q.front();
            q.pop();
            nodes++; //update count of nodes
            
            for(auto it: adj[curnode]){
                
                if(vis[it] == -1){
                    q.push(it);
                    vis[it] = 1;
                }
            }
        }
        //cout<<"Nodes "<<nodes<<" ";
        return nodes;
    }
    
    long long countPairs(int n, vector<vector<int>>& edges) {
        
        //make an adj list
        vector<int> adj[n];
        
        for(auto it: edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        
        long long pairs = 0;
        long long count = 0;
        long long prevCount = 0;
        
        //make a vis array
        vector<int> vis(n,-1);
        
        for(int i=0; i<n; i++){
            
            if(vis[i] == -1){
                //get the no. of nodes present in each diff component through bfs
                count += bfs(i,adj,vis);
            }
            
            if(count == n) break; //means all nodes have been covered
            
            pairs += (count - prevCount)*(n - count); //contribution of each component
            //cout<<"pairs are "<<pairs<<" ";
            prevCount = count;
            
        }
        cout<<endl;
        return pairs;
    }
};
