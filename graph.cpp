//Muhammad Ghazi
//4/3/19
//BFS DFS
//Dr. Huang

#include "graph.h"
#include <vector>
#include <iostream>


vector<Node> queue;
graph::graph() {
	count = 0;
};


void graph::addVertex(const Node node)

{
	vertices.push_back(node);
	count++;
};


void graph::addEdge(const char from, const char to)
{
	if (vertices.size() == 0)
		return;

	for (int i = 0; i < vertices.size(); i++) {
		if (vertices[i].name == from) {
			vertices[i].edges.push_back(to);
		}
		if (vertices[i].name == to) {
			vertices[i].edges.push_back(from);
		}
	}
};



void graph::print()
{
	int i = 0;
	while (i < vertices.size()) {
		cout << vertices[i].name << "->";
		if (vertices[i].edges.size() > 0) {
			for (int j = 0; j < vertices[i].edges.size(); j++) {
				cout << vertices[i].edges[j];
			}
		}
		cout << endl;
		i++;
	}
};



void graph::DFS()
{
	reset();
	cout << "\n" << endl;
	cout << "DFS: ";
	for (int i = 0; i < vertices.size(); i++)
	{
		if (vertices[i].visited == 0)
		{
			dfs(vertices[i]);
		}
	}
	cout << endl;
};


void graph::BFS()
{
	reset();
	int i, n;
	n = vertices.size();
	cout << "BFS: ";
	bfs(vertices[0]);
	cout << "\n" << endl;
	cout << endl;
}



void graph::reset()
{
	for (int i = 0; i < vertices.size(); i++)
		vertices[i].visited = 0;
	count = 0;
};



void graph::dfs(Node& node)
{
	count++;
	node.visited = count;
	cout << node.name << ", ";
	for (int i = 0; i < node.edges.size(); i++)
	if (vertices[node.edges[i] - 'a'].visited == 0)
		dfs(vertices[node.edges[i] - 'a']);
}


void graph::bfs(Node& node)
{
	count++;
	if (node.visited == 0){
		node.visited = count;
		queue.push_back(node);
	}
	for (int j = 0; j < node.edges.size(); j++){
		if (vertices[node.edges[j] - 'a'].visited == 0){
			vertices[node.edges[j] - 'a'].visited = count;
			queue.push_back(vertices[node.edges[j] - 'a']);
		}
	}

	cout << queue[0].name << ", ";
	queue.erase(queue.begin());
	if (queue.size()>0)
		bfs(queue.at(0));
};


