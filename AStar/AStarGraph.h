#pragma once
#pragma region AStar


#include <iostream>
#include <vector>
#include <queue>

#include "AStarNode.h"
#include "AStarHeuristics.h"

enum AStarGraphType
{
	Grid8Dir,
	Grid4Dir,
};

struct GraphData
{
	
};


class AStarGraph
{
public:

	AStarGraph();
	~AStarGraph();
	void Init();

	void AddObstacle();

	void SmoothingPath();

	void LinkNodeToNode(AStarNode* nodeA, AStarNode* nodeB);

	AStarGraphType getGraphType() { return graphType; }
	void setGraphType(AStarGraphType _graphType) { graphType = _graphType; }

	std::vector<AStarNode*> CalculatePath(AStarNode* StartNode, AStarNode* EndNode);

	//-----------------Graph----------------//
	void GenerateGridGraph(int width, int height);
	void SetGridNeighbors();



private:

	AStarNode* FindNodeInList(AStarNode node); //Can be replaced with another identifier

	void SetGridNeighbors4Dir();
	void SetGridNeighbors8Dir();


	AStarGraphType graphType{AStarGraphType::Grid4Dir};

	bool breakTie{false};
	bool weightedGraph{ false };

	/*
	AStarNode* StartNode{ nullptr };
	AStarNode* EndNode{ nullptr };*/

	std::vector<AStarNode> nodeList;

	bool unidirectional{ false };

	AStarHeuristics heuritic;


	int gridWidth{ 0 };
	int gridHeight{ 0 };

};

#pragma endregion
