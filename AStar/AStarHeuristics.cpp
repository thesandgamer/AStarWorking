#pragma region AStar

#include "AStarHeuristics.h"
#include "AStarGraph.h"
#include "AStarNode.h"

AStarHeuristics::AStarHeuristics()
{
}

AStarHeuristics::AStarHeuristics(AStarGraph* link): graph{link}
{
}

AStarHeuristics::~AStarHeuristics()
{
}

float AStarHeuristics::CalculateFCost(AStarNode* StartNode, AStarNode* CurrentNode, AStarNode* EndNode)
{
    return CalculateGCost(CurrentNode, StartNode) + CalculateHCost(CurrentNode, EndNode);
}


float AStarHeuristics::CalculateHCost(AStarNode* CurrentNode, AStarNode* EndNode)
{
    return CalculateCost(CurrentNode, EndNode);
}

float AStarHeuristics::CalculateGCost(AStarNode* CurrentNode, AStarNode* StartNode)
{
    return CalculateCost(CurrentNode, StartNode);
}

/// <summary>
/// To calculate cost from a node to another
/// </summary>
/// <param name="StartNode"></param>
/// <param name="EndNode"></param>
/// <returns></returns>
float AStarHeuristics::CalculateCost(AStarNode* NodeA, AStarNode* NodeB)
{
    switch (graph->getGraphType())
    {
    case Grid4Dir:
        return CalculateCostForGrid4Dir(NodeA, NodeB);
    case Grid8Dir:
        return CalculateCostForGrid8Dir(NodeA, NodeB);

    default:
        return CalculateCostForGrid4Dir(NodeA, NodeB);
    }

}



float AStarHeuristics::CalculateCostForGrid4Dir( AStarNode* NodeA,  AStarNode* NodeB)
{
    float dx = std::abs(NodeA->getX() - NodeB->getX());
    float dy = std::abs(NodeA->getY() - NodeB->getY());
    return NodeB->getMoveCost() * (dx + dy);
}

float AStarHeuristics::CalculateCostForGrid8Dir( AStarNode* NodeA,  AStarNode* NodeB)
{
    float dx = std::abs(NodeA->getX() - NodeB->getX());
    float dy = std::abs(NodeA->getY() - NodeB->getY());
    return NodeB->getMoveCost() * (dx + dy) + (NodeB->getDiagonalCost() - (2 * NodeB->getMoveCost()) ) * std::min(dx, dy);

}

#pragma endregion 