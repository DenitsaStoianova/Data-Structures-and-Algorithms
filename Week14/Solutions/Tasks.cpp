#include "pch.h"
#include <iostream>
#include <string>
#include <queue>
#include <list>

template<typename T>
struct VertexNode // предсавяне на възел от графа 
{
	int vertexIndex; // пореден номер 
	T vertexValue; // стойност на възела

	VertexNode(int vertexIndex, const std::string& vertexValue)
	{
		this->vertexIndex = vertexIndex;
		this->vertexValue = vertexValue;
	}

	bool operator==(const VertexNode<T>& other) const 
	{
		return this->vertexIndex == other.vertexIndex && this->vertexValue == other.vertexValue; 
	}
};

template<typename T>
class Graph
{
public:
	Graph(int size);

	void addVertex(const T& value); // добавяне на нов възел
	void addEdge(const VertexNode<T>& from, const VertexNode<T>& to); // добавяне на ребро

	void BFS(const VertexNode<T>& start); // обхождане в широчина

	void DFS(const VertexNode<T>& start); // обхождане в дълбочина

	bool hasPath(const VertexNode<T>& from, const VertexNode<T>& to); // проверка дали съществува път между два възела

	void findAllPaths(const VertexNode<T>& src, const VertexNode<T>& dst); // намиране на всички възможни пътища между два възела  

private:
	std::list<VertexNode<T>> *adjacencyList;
	int maxVerticesCount;
	int currentVertexCount;

	bool isFoundAtCurrentPath(VertexNode<T> vertex, std::vector<VertexNode<T>>& path);
	void DFSHelp(const VertexNode<T>& start, bool *visited);
	void printPath(std::vector<VertexNode<T>>& path);
};

template<typename T>
Graph<T>::Graph(int size)
{
	this->maxVerticesCount = size;
	this->currentVertexCount = 0;
	this->adjacencyList = new std::list<VertexNode<T>>[size];
}

template<typename T>
void Graph<T>::addVertex(const T & value) 
{
	VertexNode<T> newVertex(this->currentVertexCount, value); // създаване на възел по подадена стойност
	this->adjacencyList[this->currentVertexCount].push_back(newVertex);
	this->currentVertexCount++;
}

template<typename T>
void Graph<T>::addEdge(const VertexNode<T>& from, const VertexNode<T>& to)
{
	this->adjacencyList[from.vertexIndex].push_back(to); // добавяне на съседа на даден възел - позиционираме се на съответната позиция в масива
}

template<typename T>
void Graph<T>::BFS(const VertexNode<T> & start)
{
	bool* visited = new bool[this->maxVerticesCount]; // маркираме вече посетените възли 
	for (int i = 0; i < this->maxVerticesCount; i++)
	{
		visited[i] = false;
	}

	std::queue<VertexNode<T>> queue;
	queue.push(start);
	visited[start.vertexIndex] = true;

	while (!queue.empty())
	{
		VertexNode<T> currentVertex = queue.front();
		queue.pop();

		std::cout << currentVertex.vertexValue << " ";

		for (typename std::list<VertexNode<T>>::iterator it = this->adjacencyList[currentVertex.vertexIndex].begin();
			it != this->adjacencyList[currentVertex.vertexIndex].end(); it++)
		{
			if (!visited[it->vertexIndex])
			{
				visited[it->vertexIndex] = true;
				queue.push(*it);
			}
		}
	}

	delete[] visited;
}

template<typename T>
void Graph<T>::DFS(const VertexNode<T> & start)
{
	bool* visited = new bool[this->maxVerticesCount];
	for (int i = 0; i < this->maxVerticesCount; i++)
	{
		visited[i] = false;
	}

	DFSHelp(start, visited);

	delete[] visited;
}

template<typename T>
void Graph<T>::DFSHelp(const VertexNode<T>& start, bool* visited)
{
	std::cout << start.vertexValue << " ";
	visited[start.vertexIndex] = true;

	for (typename std::list<VertexNode<T>>::iterator it = this->adjacencyList[start.vertexIndex].begin();
		it != this->adjacencyList[start.vertexIndex].end(); it++)
	{
		if (!visited[it->vertexIndex])
		{
			visited[it->vertexIndex] = true;
			DFSHelp(*it, visited);
		}
	}
}

template<typename T>
bool Graph<T>::hasPath(const VertexNode<T>& from, const VertexNode<T>& to)
{
	bool* visited = new bool[this->maxVerticesCount];
	for (int i = 0; i < this->maxVerticesCount; i++)
	{
		visited[i] = false;
	}

	std::queue<VertexNode<T>> queue;
	queue.push(from);
	visited[from.vertexIndex] = true;

	while (!queue.empty())
	{
		VertexNode<T> currentVertex = queue.front();
		queue.pop();
		
		for (typename std::list<VertexNode<T>>::iterator it = this->adjacencyList[currentVertex.vertexIndex].begin();
			it != this->adjacencyList[currentVertex.vertexIndex].end(); it++)
		{
			if (*it == to)
			{
				delete[] visited;
				return true;
			}

			if (!visited[it->vertexIndex])
			{
				visited[it->vertexIndex] = true;
				queue.push(*it);
			}
		}
	}

	delete[] visited;
	return false;
}

template<typename T>
void Graph<T>::findAllPaths(const VertexNode<T> &src, const VertexNode<T> &dst)
{
	std::queue<std::vector<VertexNode<T>>> allConstructedPaths;

	std::vector<VertexNode<T>> currentPath;
	currentPath.push_back(src);
	allConstructedPaths.push(currentPath);

	while (!allConstructedPaths.empty())
	{
		currentPath = allConstructedPaths.front();
		allConstructedPaths.pop();
		VertexNode<T> last = currentPath[currentPath.size() - 1];

		if (last == dst)
		{
			printPath(currentPath);
		}
		else
		{
			for (typename std::list<VertexNode<T>>::iterator it = this->adjacencyList[last.vertexIndex].begin();
				it != this->adjacencyList[last.vertexIndex].end(); ++it)
			{
				if (!isFoundAtCurrentPath(*it, currentPath))
				{
					std::vector<VertexNode<T>> newpath(currentPath);
					newpath.push_back(*it);
					allConstructedPaths.push(newpath);
				}
			}
		}
	}
}

template<typename T>
bool Graph<T>::isFoundAtCurrentPath(VertexNode<T> vertexToCheck, std::vector<VertexNode<T>>& path)
{
	size_t size = path.size();
	for (size_t i = 0; i < size; i++)
	{
		if (path[i] == vertexToCheck)
		{
			return true;
		}
	}
	return false;
}

template<typename T>
void Graph<T>::printPath(std::vector<VertexNode<T>>& path)
{
	size_t size = path.size();
	for (size_t i = 0; i < size; i++)
	{
		std::cout << path[i].vertexValue << " ";
	}
	std::cout << "\n";
}

int main()
{
	Graph<std::string> graph(4);

	VertexNode<std::string> vertex0(0, "zero");
	VertexNode<std::string> vertex1(1, "one");
	VertexNode<std::string> vertex2(2, "two");
	VertexNode<std::string> vertex3(3, "three");

	graph.addVertex(vertex0.vertexValue);
	graph.addVertex(vertex1.vertexValue);
	graph.addVertex(vertex2.vertexValue);
	graph.addVertex(vertex3.vertexValue);

	graph.addEdge(vertex0, vertex1);
	graph.addEdge(vertex0, vertex2);
	graph.addEdge(vertex1, vertex2);
	graph.addEdge(vertex2, vertex0);
	graph.addEdge(vertex2, vertex3);
	graph.addEdge(vertex3, vertex3);

	std::cout << "BFS: ";
	graph.BFS(vertex0);

	std::cout << "\nDFS: ";
	graph.DFS(vertex0);

	std::cout << "\nHas path between 'zero' and 'three'? ";
	graph.hasPath(vertex0, vertex3) ? std::cout << "Yes" : std::cout << "No";

	std::cout << "\nHas path between 'two' and 'one'? ";
	graph.hasPath(vertex2, vertex1) ? std::cout << "Yes" : std::cout << "No";

	std::cout << "\nHas path between 'three' and 'zero'? ";
	graph.hasPath(vertex3, vertex0) ? std::cout << "Yes" : std::cout << "No";

	std::cout << "\nAll paths between 'zero' and 'three' are:\n";
	graph.findAllPaths(vertex0, vertex3);

	return 0;
}
