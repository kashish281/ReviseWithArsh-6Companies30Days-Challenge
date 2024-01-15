class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> dist(n,vector<int>(n,1e9));
        //creating asjancy matrix
        for(auto node : edges){
            dist[node[0]][node[1]] = node[2];
            dist[node[1]][node[0]] = node[2];

        }
        //setting distance of node to itself = 0 
        for(int i=0;i<n;i++) dist[i][i]=0;
        //applying Floyd Warshall algorithm to find min distance between each node
        for(int k=0;k<n;k++){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                 if((dist[i][j] > dist[i][k] + dist[k][j]) && dist[i][k] !=1e9 && dist[k][j] !=1e9){
                        dist[i][j] = dist[i][k] + dist[k][j];
                    }
                }
            }
        }
        // check for cities
        int mincnt = n;
        int city = 0;
        for (int i = 0; i < n; i++) {
            int cnt = 0;
            for (int j = 0; j < n; j++) {
                if (dist[i][j] <= distanceThreshold) {
                    cnt++;
                }
            }
            if (mincnt >= cnt) {
                mincnt = cnt;
                city = i;
            }
        }
        return city;
    }
};