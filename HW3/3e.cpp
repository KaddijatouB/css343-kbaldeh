// 743. Network Delay Time
// [Dijkstra]

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        // Create the adjacency list
        vector<pair<int, int>> adj[101];
        for (vector<int> time : times){
            int source = time[0];
            int Location = time[1];
            int transitT = time[2];
            adj[source].push_back({transitT, Location});
        }
        // create a time array for signal time
        vector<int> signalTime(n + 1, INT_MAX);

        // create priority queue pair and push source time
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, k});

        // initialize the source time as 0
        signalTime[k] = 0;
        // Loop through the queue until becomes empty
        while (!pq.empty()) {
            int currTime = pq.top().first;
            int curr = pq.top().second;
            pq.pop();

            if (currTime > signalTime[curr]) {
                continue;
            }
            for (pair<int, int> edge : adj[curr]) {
                int time = edge.first;
                int adjNode = edge.second;
                // Update time if less than time already present in queue
                if (signalTime[adjNode] > currTime + time) {
                    signalTime[adjNode] = currTime + time;
                    //push the new time and the node in the priority queue
                    pq.push({signalTime[adjNode], adjNode});
                }
            }
        }
        // calculate and return the minimum time the signal takes to reach all nodes
        int min= INT_MIN;
        for (int i = 1; i <= n; i++) {
            min = max(min, signalTime[i]);
        }
        return min == INT_MAX ? -1 : min;
    }
};