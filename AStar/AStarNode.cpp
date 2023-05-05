#include "AStarNode.h"




AStarNode::AStarNode()
{
	Init();
}

AStarNode::AStarNode(int _x, int _y): x(_x),y(_y)
{
	Init();
}


void AStarNode::Init()
{
	diagonalCost = std::sqrt(moveCost);
}

/// <summary>
/// Get the cost to move from this node to another
/// </summary>
/// <returns></returns>
float AStarNode::getMoveCost()
{
	return moveCost; 
}

float AStarNode::getDiagonalCost()
{
	return diagonalCost;
}



void AStarNode::AddNeighbor(AStarNode* neighbor)
{
	if (neighbor == nullptr) return;
	if (std::find(neighbors.begin(), neighbors.end(), neighbor)!= neighbors.end())
	{
		neighbors.push_back(neighbor);
	}
}

std::vector<AStarNode*>& AStarNode::getNeighbors()
{
	return neighbors; 
}
