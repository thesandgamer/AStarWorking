#pragma once
#pragma region AStar

#include <iostream>

class AStarGraph;
class AStarNode;


class AStarHeuristics
{
public:
	AStarHeuristics();
	~AStarHeuristics();

	float CalculateCost(AStarNode* NodeA, AStarNode* NodeB);


private:

	float CalculateCostForGrid4Dir(AStarNode* NodeA, AStarNode* NodeB);
	float CalculateCostForGrid8Dir(AStarNode* NodeA, AStarNode* NodeB);

	AStarGraph* graph { nullptr }; //Référence vers le graph 
	//std::unique_ptr<AStarGraph> graph {nullptr};// Ca marche ça?
};

#pragma endregion 