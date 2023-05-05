#pragma once
#pragma region AStar

#include <iostream>

class AStarGraph;
class AStarNode;

/// <summary>
/// Calculation of cost to a Node to another Node
/// If h=0 : A* turn into Dijistra's Algorithm
/// Decide the precision of the A* algorithm
/// It's a blaance between g and h
/// 
/// g = current to start	how far from starting node
/// h = current to end		how far from end node
/// f = g + h
/// </summary>
/// 
/// 
class AStarHeuristics
{
public:
	AStarHeuristics();
	AStarHeuristics(AStarGraph* link);
	~AStarHeuristics();



	float CalculateFCost(AStarNode* StartNode, AStarNode* CurrentNode, AStarNode* EndNode);


private:
	float CalculateHCost(AStarNode* CurrentNode, AStarNode* EndNode);
	float CalculateGCost(AStarNode* CurrentNode, AStarNode* StartNode);

	float CalculateCost(AStarNode* NodeA, AStarNode* NodeB);

	float CalculateCostForGrid4Dir(AStarNode* NodeA, AStarNode* NodeB);
	float CalculateCostForGrid8Dir(AStarNode* NodeA, AStarNode* NodeB);
	//++ToDo: any direction with euclidian distance: https://theory.stanford.edu/~amitp/GameProgramming/Heuristics.html#euclidean-distance

	AStarGraph* graph { nullptr }; //Référence vers le graph 
	//std::unique_ptr<AStarGraph> graph {nullptr};


	//========] Optimisations
	
	bool breakTie{ false }; //https://theory.stanford.edu/~amitp/GameProgramming/Heuristics.html#breaking-ties

	bool weightedGraph{ false }; //https://theory.stanford.edu/~amitp/GameProgramming/Variations.html#weighted-a-star

	//++Question: put Start and End node ref here and restet them à each iteration



	//To change dynamically the balance between speed and accuracy
	// 1 = the min cost to travel from one node to another
	// At alpha = 0: function will be one, npde cost are ignored : passable or unpassable nodes
	// g'(n) = 1 + alpha * (g(n)-1)


};

#pragma endregion 