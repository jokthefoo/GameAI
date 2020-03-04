#include "PathfindingApp.h"
#include "DirectedGraph.h"
#include "FileReader.h"
#include "Pathfinding.h"
#include "Heuristic.h"


const int gridSize = 15;
const float boxSize = 50.0f;
int gridObj[gridSize][gridSize] = 
{	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{ 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0 },
	{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
	{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
	{ 0, 0, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0 },
	{ 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0 },
	{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0 },
	{ 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0 },
	{ 0, 0, 0, 1, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0 },
	{ 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0 },
	{ 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0 },
	{ 0, 0, 1, 1, 1, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0 },
	{ 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0 },
	{ 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0 },
	{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0 } };
//--------------------------------------------------------------
void PathfindingApp::setup() {
	ofBackground(51, 153, 255);

	DirectedGraph graph = BuildGraph("..\\houseGraph.txt");
	DirectedGraph bigGraph = BuildGraph("..\\rome99.txt");
	ZeroH zh;
	ClusterH ch;

	Path p = pathfindingAStar(graph, 3, 0, zh);

	DirectedGraph gridGraph = DirectedGraph::BuildGridGraph(gridSize, (int*)gridObj);
}

//--------------------------------------------------------------
void PathfindingApp::update() {
}

//--------------------------------------------------------------
void PathfindingApp::draw() {
	// Draw grid
	ofDrawGrid(boxSize, gridSize, true,false,false);

	for (int y = 0; y < gridSize; y++)
	{
		for (int x = 0; x < gridSize; x++)
		{
			if (gridObj[y][x] == 1)
			{
				ofDrawRectangle(x * boxSize, y * boxSize, boxSize, boxSize);
			}
		}
	}
}

//--------------------------------------------------------------
void PathfindingApp::keyPressed(int key) {
	if(key == 99) // c
	{
		int x = ofGetMouseX() / boxSize;
		int y = ofGetMouseY() / boxSize;

		if (gridObj[y][x])
		{
			gridObj[y][x] = 0;
		}
		else
		{
			gridObj[y][x] = 1;
		}
	}
}

//--------------------------------------------------------------
void PathfindingApp::keyReleased(int key) {

}

//--------------------------------------------------------------
void PathfindingApp::mouseMoved(int x, int y) {

}

//--------------------------------------------------------------
void PathfindingApp::mouseDragged(int x, int y, int button) {
}

//--------------------------------------------------------------
void PathfindingApp::mousePressed(int x, int y, int button) {
}

//--------------------------------------------------------------
void PathfindingApp::mouseReleased(int x, int y, int button) {

}

//--------------------------------------------------------------
void PathfindingApp::mouseEntered(int x, int y) {

}

//--------------------------------------------------------------
void PathfindingApp::mouseExited(int x, int y) {

}

//--------------------------------------------------------------
void PathfindingApp::windowResized(int w, int h) {

}

//--------------------------------------------------------------
void PathfindingApp::gotMessage(ofMessage msg) {

}

//--------------------------------------------------------------
void PathfindingApp::dragEvent(ofDragInfo dragInfo) {

}
