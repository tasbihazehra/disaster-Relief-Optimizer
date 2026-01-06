#include <iostream>
#include <vector>
#include <queue>
#include <list>
#include <string>

#define INF 0x3f3f3f3f

using namespace std;
class DisasterMap {
    int V; 
    list<pair<int, int>> *adj;
    string cityNames[6] = {"Base/Airport", "Kahramanmaras", "Hatay", "Gaziantep", "Adiyaman", "Malatya"};

public:
    DisasterMap(int V) {
        this->V = V;
        adj = new list<pair<int, int>>[V];
    }

    void addRoad(int u, int v, int damageLevel) {
        adj[u].push_back(make_pair(v, damageLevel));
        adj[v].push_back(make_pair(u, damageLevel));
    }

    void findShortestPath(int src) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<int> dist(V, INF);

        pq.push(make_pair(0, src));
        dist[src] = 0;

        while (!pq.empty()) {
            int u = pq.top().second;
            pq.pop();

            for (auto i = adj[u].begin(); i != adj[u].end(); ++i) {
                int v = (*i).first;
                int weight = (*i).second;

                if (dist[v] > dist[u] + weight) {
                    dist[v] = dist[u] + weight;
                    pq.push(make_pair(dist[v], v));
                }
            }
        }

        cout << "--- TURKIYE DISASTER RELIEF ROUTE OPTIMIZATION ---" << endl;
        cout << "Origin: " << cityNames[src] << endl << endl;
        cout << "Destination City \t Road Difficulty (Weight)" << endl;
        cout << "----------------------------------------------------" << endl;
        for (int i = 0; i < V; ++i) {
            cout << cityNames[i] << " \t\t " << (dist[i] == INF ? -1 : dist[i]) << endl;
        }
    }
};

int main() {
    DisasterMap turkeyMap(6);
    turkeyMap.addRoad(0, 1, 4);  
    turkeyMap.addRoad(0, 2, 9);  
    turkeyMap.addRoad(1, 2, 2);  
    turkeyMap.addRoad(1, 3, 5);  
    turkeyMap.addRoad(2, 4, 3);  
    turkeyMap.addRoad(3, 5, 1); 

    turkeyMap.findShortestPath(0);

    return 0;
}
