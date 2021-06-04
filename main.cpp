// main function

#include <iostream>

#include "graph.h"

using namespace std;

int main(int argc, const char * argv[])
{
  if ( argc != 2 ) {
    cout << "usage: " << argv[0] << " input filename\n";
    exit(1);
  }

  string input_name = argv[1];
  ifstream input(input_name);
  if (!input) {
    cout << "Wrong or nonexisting input file\n";
    exit(1);
  }

  //Try changing this to int as well.
  Graph<string> graph;
  graph.buildGraph(input);
  if(graph.size() < 20){
    graph.displayGraph(cout);
  }
  graph.compute_indegree(); // Part 2
  bool b = graph.topological_sort(); // Part 2
  if(b){
    if(graph.size() < 20){
      graph.print_top_sort(cout);   // Part 2
    }
  }
  else
  {
    cout << "Cycle Detected.\n";
  }

  return 0;
}
