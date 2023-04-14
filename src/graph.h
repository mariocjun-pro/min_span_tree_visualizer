#pragma once 
#include <vector>
#include <queue>
#include "node.h"
#include <memory>

using namespace std;

class Node;

using SharedNodePtr = std::shared_ptr<class Node>;

class Graph : public ISubject {
private:
	vector<SharedNodePtr> nodeArray;
	int nodeCount = 0;
public:

	enum MessageTypes { DRAWEDGE };

	// Constructor
	Graph();
	~Graph();
	SharedNodePtr insertNode(SharedNodePtr n);
	vector<SharedNodePtr>& getNodes();
	SharedNodePtr getNodeByName(string name);
	int getNodeCount();
	Edge* connectNodes(Node* a, Node* b, double edgeWeight);
	void removeNode(Node* node_to_remove);
	pair<float*,float*> getCoordsForPlot();
	void drawEdge(Edge* e);
	void resetVisitedState();
}; 

Edge* getInverseEdge(Graph& g, Edge& edge);