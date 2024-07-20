bool isCyclic(int V, vector<int> adj[]) {
        // code here
        queue<int> q;
        vector<int> in(V,0);
        for(int i=0;i<V;i++){
            for(auto j:adj[i]) in[j]++;
        }
        for(int i=0;i<V;i++) {
            if(in[i]==0) q.push(i);
        }
        int cur=V;
        while(q.size()){
            auto curr=q.front();
            q.pop();
            cur--;
            for(auto i:adj[curr]){
                in[i]--;
                if(in[i]==0) q.push(i);
            }
        }
        return !(cur==0);
    }