#include <bits/stdc++.h>
using namespace std;

void add_edge(vector<int> adj[], int src, int dest)
{
adj[src].push_back(dest);
adj[dest].push_back(src);
}

bool BFS(vector<int> adj[], int src, int dest, int v,
int pred[], int dist[])
{

list<int> queue;


bool visited[v];


for (int i = 0; i < v; i++) {
visited[i] = false;
dist[i] = INT_MAX;
pred[i] = -1;
}

visited[src] = true;
dist[src] = 0;
queue.push_back(src);

while (!queue.empty()) {
int u = queue.front();
queue.pop_front();
for (int i = 0; i < adj[u].size(); i++) {
if (visited[adj[u][i]] == false) {
visited[adj[u][i]] = true;
dist[adj[u][i]] = dist[u] + 1;
pred[adj[u][i]] = u;
queue.push_back(adj[u][i]);

if (adj[u][i] == dest)
return true;
}
}
}

return false;
}

void printShortestDistance(vector<int> adj[], int s,
int dest, int v)
{

int pred[v], dist[v];

if (BFS(adj, s, dest, v, pred, dist) == false) {
cout << "Given source and destination"
<< " are not connected";
return;
}


vector<int> path;
int crawl = dest;
path.push_back(crawl);
while (pred[crawl] != -1) {
path.push_back(pred[crawl]);
crawl = pred[crawl];
}


cout << "Shortest path length is : "
<< dist[dest];
 
  cout << "\n";

cout << "\nThe shortest path is -\n\n";
for (int i = path.size() - 1; i >= 0; i--)
  {
if(path[i]==0)
    {
      cout<<"Shamoli (home)->"<<" ";
    }
    if(path[i]==1)
    {
      cout<<"Farmegate->"<<" ";
    }
   if(path[i]==2)
   {
     cout<<"Sia Masjid->"<<" ";
   }
    if(path[i]==3)
   {
     cout<<"Mohammadpur bus stand ->"<<" ";
   }
    if(path[i]==4)
   {
     cout<<"Salimulla Road->"<<" ";
   }
    if(path[i]==5)
   {
     cout<<"Dhaka Uddan->"<<" ";
   }
    if(path[i]==6)
    {
      cout<<"Permanent Campus";
    }
    }
}

void DFS(vector<int> adj[], int u, int dest, vector<bool>& visited,
         vector<int>& path, vector<vector<int>>& paths)
{
    visited[u] = true;
    path.push_back(u);

    if (u == dest) {
        paths.push_back(path);
    } else {
        for (int v : adj[u]) {
            if (!visited[v]) {
                DFS(adj, v, dest, visited, path, paths);
            }
        }
    }

    visited[u] = false;
    path.pop_back();
}

vector<vector<int>> findAllPaths(vector<int> adj[], int src, int dest, int v)
{
    vector<vector<int>> paths;
    vector<bool> visited(v, false);
    vector<int> path;

    DFS(adj, src, dest, visited, path, paths);

    return paths;
}


int main()
{
int v = 7;


vector<int> adj[v];


add_edge(adj, 0, 1);
add_edge(adj, 0, 2);
add_edge(adj, 2, 3);
  add_edge(adj, 2, 6);
add_edge(adj, 3, 6);
add_edge(adj, 3, 4);
add_edge(adj, 4, 5);
add_edge(adj, 5, 6);

int source = 0, dest = 6;
printShortestDistance(adj, source, dest, v);
  
 vector<vector<int>> paths = findAllPaths(adj, source, dest, v);

    if (paths.empty()) {
        cout << "There is no path from source to destination\n";
    } else {
        cout << "All possible paths from " << source << " to " << dest << " are:\n\n";
        for (auto path : paths) {
            for (int i = 0; i < path.size() - 1; i++) {
                if (path[i] == 0) {
                    cout << "Shamoli (home) -> ";
                } else if (path[i] == 1) {
                    cout << "Farmegate -> ";
                } else if (path[i] == 2) {
                    cout << "Sia Masjid -> ";
                } else if (path[i] == 3) {
                    cout << "Mohammadpur bus stand -> ";
                } else if (path[i] == 4) {
                    cout << "Salimulla Road -> ";
                } else if (path[i] == 5) {
                    cout << "Dhaka Uddan -> ";
                } else if (path[i] == 6) {
                    cout << "Permanent Campus";
                }
            }
            cout << endl;
        }
    }

cout<<endl;
  cout<<endl; 
  cout<<" For Understanding Paths:"<<endl;
  if (paths.size() == 0) {
        cout << "No path exists between " << source << " and " << dest << endl;
    } else {
        cout << "All paths between " << source << " and " << dest << ":" << endl;
        for (vector<int>& path : paths) {
            for (int u : path) {
                cout << u << " ";
            }
            cout << endl;
        }
    }
  
return 0;
}
