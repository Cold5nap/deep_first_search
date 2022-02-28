#pragma once
#include <list>
#include "Node.h";
#include <iostream>;
using namespace std;
class Graph
{
private:vector<Node*> nodes;

public: bool search(Node* n, Node* findN) {
	n->setPassed();
	for (Node* adj : n->getAdj())
	{
		//�������� ��������� �� ������
		bool isBlocked = false;
		for (Node* blAdj : n->getBlockedAdj())
		{
			if (blAdj->equals(adj)) {
				isBlocked = true;
			}
		}
		//���� �� ��������
		if (!isBlocked) {
			//���� �������� �������� ����� �������
			if (adj->equals(findN)) {
				cout << adj->getName();
				return true;
			}
			//���� �������� �������� �� �������� 
			if (!adj->isPassed()) {
				adj->setPassed();
				cout << adj->getName();
				if (search(adj, findN)) {
					return true;
				}
			}
		}
	}
	return false;
}


public: void addAdj(Node* n1, Node* n2) {
	n1->addAdj(n2);
	n2->addAdj(n1);
}
public: void addBlockedAdj(Node* n1, Node* n2)
{
	n1->addBlockedAdj(n2);
	n2->addBlockedAdj(n1);
}
public: void addNode(Node* node)
{
	nodes.push_back(node);
}

public: vector<Node*> getAllNodes() {
	return nodes;
}

public: void printNodes() {
	for (Node* node : nodes) {
		string name = node->getName();
		cout << "����� " << name << " ������(";

		for (Node* adj : node->getAdj())
		{
			cout << adj->getName() << ", ";
		}
		cout << ") ��������������� ������(";
		for (Node* adj : node->getBlockedAdj())
		{
			cout << adj->getName() << ", ";
		}
		cout << ")"<< endl;
	}
}
};

