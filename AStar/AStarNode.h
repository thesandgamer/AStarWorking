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
	~AStarNode() = default;

	void Init();


	float getMoveCost();
	float getDiagonalCost();


	void AddNeighbor(AStarNode* neighbor);
	std::vector<AStarNode*>& getNeighbors();


	//=========] For position
	int getX() { return x; }
	int getY() { return y; }
	void setX(int _x) { x = _x; }
	void setY(int _y) { y = _y; }


	AStarNode* cameFromNode{ nullptr };
	double cost {0};


private:
	int x{ 0 };
	int y{ 0 };

	float moveCost{ 1 };	//To add more detail for movement cost: https://theory.stanford.edu/~amitp/GameProgramming/MovementCosts.html
	//++Question: are we put the diagonal cost of movement in node or in Heurstic
	float diagonalCost{ std::sqrt(moveCost) };



	//Voisins 
	//std::vector<AStarNode*> neighbors;
	std::vector<AStarNode*> neighbors{};	//Link to all his neighbors //Put unique pointer	//Maybe use Set



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

	bool operator >(const const AStarNode& other)
	{
		if (this->cost > other.cost) return true;
		else return false;
	}
	bool operator <(const const AStarNode& other)
	{
		if (this->cost < other.cost) return true;
		else return false;
	}

	bool operator >=(const const AStarNode& other)
	{
		if (this->cost >= other.cost) return true;
		else return false;
	}
	bool operator <=(const const AStarNode& other)
	{
		if (this->cost <= other.cost) return true;
		else return false;
	}
};


#pragma endregion
