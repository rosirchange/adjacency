#include <stdio.h>
#include <deque>
using namespace std;
 

 
class GraphNode{
public:
  int id;
  deque<int>adjacency;
  int discovered;
  deque<float>weight;
 
  GraphNode(int _id){
    id = _id;
    discovered = 0;
  }
  void dump(){
    printf("Vertex: %d, I'm adjacent to: ", id);
    int i;
    for(i = 0; i<adjacency.size(); i++){
      printf("%d ", adjacency[i]);
      printf("%f    ", weight[i]);
    }
    printf("\n");
  }
};
 
deque<GraphNode*> NodeList;




int main(){
  int node_count, edge_count;
  printf("Enter no of vertices: ");
  scanf(" %d", &node_count);
  printf("Enter no of edges: ");
  scanf(" %d", &edge_count);
 
  int i, j;
  for(i = 0; i<node_count; i++){
    NodeList.push_back( new GraphNode(i) );
  }
 
  printf("Enter %d pairs of verteices: \n", edge_count);
  for( j = 0; j < edge_count; j++ ){
    int node_1, node_2;
    float w ;
    scanf("%d %d %f", &node_1, &node_2, &w);
    NodeList[node_1]->adjacency.push_back(node_2);
    NodeList[node_2]->adjacency.push_back(node_1);
    NodeList[node_1]->weight.push_back(w) ;
    NodeList[node_2]->weight.push_back(w) ;
  }
 
  for( i = 0; i < NodeList.size(); i++ ){
    NodeList[i]->dump();
  }
 
  return 0;
}
