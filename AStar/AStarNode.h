#pragma once
#pragma region AStar


#include <cmath>
#include <memory>
#include <vector>


/// <summary>
/// 
/// </summary>
class AStarNode
{
public:
	AStarNode();
	AStarNode(int _x, int _y);
	~AStarNode();

	void Init();


	float getMoveCost() { return moveCost; }
	float getDiagonalCost() { return diagonalCost; }


	void AddNeighbor(AStarNode* neighbor);
	std::vector<AStarNode*> getNeighbors() { return neighbors; }


	//=========] For position
	int getX() { return x; }
	int getY() { return y; }
	void setX(int _x) { x = _x; }
	void setY(int _y) { y = _y; }


private:
	int x{ 0 };
	int y{ 0 };

	float moveCost{ 1 };
	//++Question: are we put the diagonal cost of movement in node or in Heurstic
	float diagonalCost{ std::sqrt(moveCost) };



	//Voisins 
	std::vector<AStarNode*> neighbors;
	//std::vector<std::unique_ptr<AStarNode>> neighbors;



//------------------------] Overload Operators [------------------------//
public:

	bool operator==(const AStarNode& other)
	{
		if( (x == other.x) && (y == other.y) )
		{
			return true;
		}
		else
		{
			return false;
		}
	}
};


#pragma endregion
