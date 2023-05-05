#include "AStarGraph.h"

AStarGraph::AStarGraph()
{
}

AStarGraph::~AStarGraph()
{
}


void AStarGraph::Init()
{
	
	/*StartNode = &nodeList.at(0);
	EndNode = &nodeList.at(0);*/
}

void AStarGraph::AddObstacle()
{
}


/// <summary>
/// Calculate path beteween two node
/// </summary>
/// <param name="StartNode"></param>
/// <param name="EndNode"></param>
/// <returns></returns>
std::vector<AStarNode*> AStarGraph::CalculatePath(AStarNode* StartNode, AStarNode* EndNode)
{

	std::priority_queue<AStarNode*> OpenList;
	std::priority_queue<AStarNode*> ClosedList{};

	OpenList.push(StartNode);

	while (!OpenList.empty())
	{
		AStarNode* currentNode = OpenList.top();
		if (currentNode == EndNode) break;

		for (AStarNode* next : currentNode->getNeighbors())
		{
			//Calcul du f cost du voisin
			//Si ce cost < 
		}

	}





	return std::vector<AStarNode*>();
}

/// <summary>
/// Create a Grid Graph for A* calculation
/// </summary>
/// <param name="width"></param>
/// <param name="height"></param>
void AStarGraph::GenerateGridGraph(int width, int height)
{
	gridWidth = width;
	gridHeight = height;

	for (size_t x = 0; x < width; x++)
	{
		for (size_t y = 0; y < height; y++)
		{
			nodeList.push_back(AStarNode(x,y));
		}
	}

	SetGridNeighbors();
	Init();

}

void AStarGraph::SetGridNeighbors()
{
	switch (graphType)
	{
	case Grid8Dir:
		SetGridNeighbors8Dir();
		break;
	case Grid4Dir:
		SetGridNeighbors4Dir();

		break;
	default:
		break;
	}

}


AStarNode* AStarGraph::FindNodeInList(AStarNode node)
{
	auto it = std::find(nodeList.begin(), nodeList.end(), node);
	if (it != nodeList.end())
	{
		int index = std::distance(nodeList.begin(), it);
		return &nodeList.at(index);

	}
	return nullptr;
}

void AStarGraph::SetGridNeighbors4Dir()
{
	for (AStarNode node : nodeList)	//Pour chaque node de la liste
	{
		node.AddNeighbor(FindNodeInList({ node.getX()-1, node.getY() }));
		node.AddNeighbor(FindNodeInList({ node.getX()+1, node.getY() }));
		node.AddNeighbor(FindNodeInList({ node.getX(), node.getY()-1 }));
		node.AddNeighbor(FindNodeInList({ node.getX(), node.getY()+1 }));

	}
}

void AStarGraph::SetGridNeighbors8Dir()
{
	//On va check les 8 tiles autour 
	//Check qu'on reste bien dans la grille
	//Et on va lier le node au node qu'on check

	for (AStarNode node : nodeList)	//Pour chaque node de la liste
	{
		for (size_t xx = node.getX() - 1; xx < 1; xx++)
		{
			for (size_t yy = node.getY() - 1; yy < 1; yy++)
			{
				if (xx == 0 && yy == 0) continue;
				if ((xx > 0 && xx < gridWidth) && (yy > 0 && yy < gridHeight)) //Si le node à tester est dans la grille
				{
					//Check si pas déjà voisin
					//Trouver le node et l'ajouter au node actuel en tant que voisin
					node.AddNeighbor(FindNodeInList({ (int)xx,(int)yy }));
				}
			}
		}
	}
}

void AStarGraph::SmoothingPath()
{
	//Lisser le chemin
	//Permet d'avoir un chemin plus direct
	//On va prendre le node i, puis le node suivant i+1
	//Si il n'y à pas d'obstacle entre les deux
		//On va enlever le point i+1 de la lise
	//Sinon on change i au point qui est bloqué
	//On continue jusqu'à que i+1 = node de fin

	
}

/// <summary>
/// Link a node to another to create the graph
/// </summary>
/// <param name="node to link"></param>
/// <param name="link to this one"></param>
void AStarGraph::LinkNodeToNode(AStarNode* nodeA, AStarNode* nodeB)
{
	if (unidirectional)	//Si le lien n'est que dans un direction
	{
		nodeA->AddNeighbor(nodeB);
	}
	else				//Si le lien est dans les deux directions
	{
		nodeA->AddNeighbor(nodeB);
		nodeB->AddNeighbor(nodeA);
	}

}
