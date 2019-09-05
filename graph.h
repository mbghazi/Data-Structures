#pragma once

#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <vector>

using namespace std;

struct Node
{
	Node(char newName) { name = newName, visited = 0; edges.clear(); }
	char name;
	int visited;
	vector<char> edges;
};

class graph
{
public:
	graph();
	void addVertex(const Node node);
	void addEdge(const char from, const char to);
	void print();
	void DFS();
	void BFS();
	void reset();
	vector<Node>& getVertices() { return vertices; }

private:
	vector<Node> vertices;
	void dfs(Node& node);
	void bfs(Node& node);
	int count;
};

#endif