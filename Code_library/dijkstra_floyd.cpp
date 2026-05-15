/********************************************************************************
* WARNING: Please do not remove or modify this comment block.
 *
 * Student Information:
 * Name: Malak Elsayed
 * Student ID: 900223286
 * Section Number: Section 1
 *
 * Instructions:
 * - Fill out your name, student ID, and section number above.
 * - This information is mandatory for the submission of your assignment.
 * - Do not modify this file beyond the specified tasks and guidelines.
 *
 ********************************************************************************/

#include "dijkstra.h"
#include "floyd.h"
#include "graph.h"
#include <vector>
#include <queue>
#include <functional>

using namespace std;

vector<int> dijkstra(int src) {
    vector<int> dist(n, 1e9);
    // Min-heap priority queue 
    priority_queue<
        pair<int, int>,                       
        vector<pair<int, int>>,              
        greater<pair<int, int>>              // To makes it a min-heap
    > pq;

    dist[src] = 0; // The distance from source to itself is equal to 0

    pq.push({0, src}); // push source node into priority queue

    while (!pq.empty()) { // loop until pq becomes empty

        int d = pq.top().first; // current shortest distance
        int u = pq.top().second; // current node

        pq.pop(); // remove top element from pq

        // If the distance is greater than the recorded distance, skip 
        if (d > dist[u])
            continue;

        // Traverse all neighbors of node u
        for (auto edge : adjList[u]) {

            int v = edge.first; // Neighbor node
            int w = edge.second; // Edge weight

            // relaxation step
            if (dist[u] + w < dist[v]) {

                dist[v] = dist[u] + w; // update shorter distance

                pq.push({dist[v], v}); // push updated distance into pq
            }
        }
    }

    return dist; 
}

vector<vector<int>> repeatedDijkstra() {
    vector<vector<int>> all(n, vector<int>(n));

    // Run Dijkstra from every node
    for (int i = 0; i < n; i++) {

        all[i] = dijkstra(i); // Store shortest distances from node i
    }

    return all; // Return all-pairs shortest paths
}



vector<vector<int>> floydWarshall() {
    vector<vector<int>> dist = adjMatrix;

    for (int k = 0; k < n; k++) { // intermediate node

        for (int i = 0; i < n; i++) { // source node

            for (int j = 0; j < n; j++) { // destination node

                // Check if path through k is shorter
                if (dist[i][k] + dist[k][j] < dist[i][j]) {

                    dist[i][j] = dist[i][k] + dist[k][j]; // update shortest distance
                }
            }
        }
    }

    return dist; 
}