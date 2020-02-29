#pragma once
#include "DirectedGraph.h"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

DirectedGraph BuildGraph(std::string filePath)
{
	std::string line;
	std::ifstream graphFile(filePath);

	DirectedGraph graph;

	int nodeCount;
	int edgeCount;
	if (graphFile.is_open())
	{
		while (std::getline(graphFile, line))
		{
			char c = line.at(0);
			std::istringstream iss(line);
			if (c == 'c')
			{
				continue;
			}
			else if (c == 'p')
			{
				int iter = 0;
				do
				{
					std::string word;
					iss >> word;
					if (iter == 2)
					{
						nodeCount = std::stoi(word);
					}
					else if (iter == 3)
					{
						edgeCount = std::stoi(word);
					}
					iter++;
				} while (iss);
				graph.constructGraph(nodeCount);
			}
			else if (c == 'a')
			{
				int iter = 0;
				int cost, source, sink;
				do
				{
					std::string word;
					iss >> word;
					if (iter == 1)
					{
						source = std::stoi(word);
					}
					else if (iter == 2)
					{
						sink = std::stoi(word);
					}
					else if (iter == 3)
					{
						cost = std::stoi(word);
					}
					iter++;
				} while (iss);
				DirectedWeightedEdge edge(cost, source, sink);
				graph.addEdge(edge);
			}
		}
		graphFile.close();
	}

	return graph;
}
