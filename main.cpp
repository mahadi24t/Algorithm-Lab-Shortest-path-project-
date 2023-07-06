#include <iostream>
#include <queue>
#include<list>
using namespace std;
 
//class representing node of a graph
class Node{
public:
  //Adjacency List of the vertex
  list<Node*> neighbors;
  string name;
  bool visited =  false;
  Node* prev = nullptr;
 
  Node(string name){ this->name = name;}
 
  //Method to connect vertices
  void addNeighbour(Node* v){
      this->neighbors.push_back(v);
      v->neighbors.push_back(this);
  }
};
 
class BFS{
  Node* start;
  Node* end;

public:
  BFS(Node* start, Node* end){
    this->start = start;
    this->end = end;
  }

  void findPath(){
    //Create queue and declare variables
    queue<Node*> Queue;
    bool reached_end = false;
    //Visit start node and add to queue
    start->visited = true;
    Queue.push(start);

    //BFS until queue is empty
    while(!Queue.empty() && !reached_end){
      //Pop a node from queue for search operation
      Node* current_node=Queue.front();
      Queue.pop();
      //Loop through neighbors nodes to find the 'end' node
      for(Node* node: current_node->neighbors){
        if(!node->visited){
          //Visit and add neighbor nodes to the queue
          node->visited= true;
          Queue.push(node);
          node->prev = current_node;
          //stop BFS if the end node is found
          if(node == end){
            reached_end = true;
            break;
          }
        }
      }
    }
    trace_route();
  }

  //Function to trace back route
  void trace_route(){
    list<Node*> route;
    Node* node = end;
    //start.prev is always null 
    //so loop until node->prev is null to trace route
    while(node != nullptr){
      route.push_front(node);
      node = node->prev;
    }

    //Display the route
    for(Node* n: route){
      cout << n->name <<" ";
    }
  }

 };

int main()
{
  //create nodes
  Node node_A("ULAB Research Building->"), node_B("Mohammadpur Bus Stand->"), node_C("Mohammadpur Tin Rasta->"), node_D("Asad Gate->"), node_E("ULAB Parmanent  Campus"),node_F("Shaymoli->"),node_G("Kollanpur->"),node_H("Technical->"),node_I("Majar Road->"),node_J("Gabtoli->"),node_M("Home->");
  //connect nodes (i.e. create graph)
  node_M.addNeighbour(&node_A);
  node_A.addNeighbour(&node_B);
  node_B.addNeighbour(&node_C);
  node_C.addNeighbour(&node_D);
  node_D.addNeighbour(&node_F);
  node_C.addNeighbour(&node_E);
  node_F.addNeighbour(&node_G);
  node_G.addNeighbour(&node_H);
  node_H.addNeighbour(&node_I);
  node_I.addNeighbour(&node_J);
  node_J.addNeighbour(&node_E);
  
  
  
  //Driver Code
  BFS bfs(&node_M, &node_E);
  bfs.findPath();
}

