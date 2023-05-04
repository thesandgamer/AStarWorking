#include "AStarNode.h"




AStarNode::AStarNode()
{
	Init();
}

AStarNode::AStarNode(int _x, int _y): x(_x),y(_y)
{
	Init();
}

AStarNode::~AStarNode()
{
}

void AStarNode::Init()
{
	diagonalCost = std::sqrt(moveCost);
}



void AStarNode::AddNeighbor(AStarNode* neighbor)
{
	if (std::find(neighbors.begin(), neighbors.end(), neighbor)!= neighbors.end()) //Cherche si le node n'est pas déjà un voisin
	{
		neighbors.push_back(neighbor);
	}
}
