#include <iostream>
#include "AStarGraph.h"


int main()
{
    AStarGraph graph;
    graph.setGraphType(Grid8Dir);
    graph.GenerateGridGraph(4,4);

    std::cout << "Hello World!\n";

}

