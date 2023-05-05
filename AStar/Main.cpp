#include <iostream>
#include "AStarGraph.h"

void DrawGraph( AStarGraph& graph);

int main()
{
    AStarGraph graph;
    graph.setGraphType(Grid8Dir);
    graph.GenerateGridGraph(8,8);

    DrawGraph(graph);

}

void DrawGraph( AStarGraph& graph)
{
    for (int xx = 0; xx <  graph.GetGridWidth(); xx++)
    {
        for (int yy = 0; yy < graph.GetGridWidth(); yy++)
        {
            std::cout << "[ "<< graph.FindNodeInList({xx,yy})->getX() << " " << graph.FindNodeInList({ xx,yy })->getY() << " ]";
        }
        std::cout << "\n";
    }
    std::cout << std::endl;


  
}
