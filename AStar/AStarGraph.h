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

/// <summary>
/// 
/// For now work only with Grid and tile movement
/// </summary>
class AStarGraph
{
public:

	AStarGraph();
	~AStarGraph();

	void Init();


	void GenerateGridGraph(int width, int height);
	std::vector<AStarNode*> CalculatePath(AStarNode* StartNode, AStarNode* EndNode);


	//-----------------Modify Graph----------------//
	void AddObstacle();
	void SmoothingPath();

	

	//-----------------Acess Graph----------------//
	void LinkNodeToNode(AStarNode* nodeA, AStarNode* nodeB);

	AStarGraphType getGraphType() { return graphType; }
	void setGraphType(AStarGraphType _graphType) { graphType = _graphType; }

	void SetGridNeighbors();

	std::vector<AStarNode>& GetNodeList() { return nodeList; }

	int GetGridWidth() { return gridWidth; }
	int GetGridHeight() { return gridHeight; }

	//I decide to use * so we can return nullptr, but we can also use reference with std::pair or std::boost and return a false
	AStarNode* FindNodeInList(AStarNode node); //Can be replaced with another identifier	



private:

	int gridWidth{ 0 };
	int gridHeight{ 0 };

	void SetGridNeighbors4Dir();
	void SetGridNeighbors8Dir();


	AStarGraphType graphType{AStarGraphType::Grid4Dir};


	std::vector<AStarNode> nodeList;	//List of all the nodes in the graph

	bool unidirectional{ false };

	AStarHeuristics heuristic{this};




};

#pragma endregion
