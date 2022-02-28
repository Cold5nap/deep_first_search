#pragma once
#include <string>;
#include <iostream>;
#include <vector>;
#include <iterator>;
using namespace std;

class Node
{
private: string name;
private: vector <Node*> adj;//������� �������
private: vector <Node*> blockedAdj;//��������������� ������� �������
private: bool isPassed_;//���������� ������� �������


public:Node(string name) {
	this->name = name;
	isPassed_ = false;
}
public: bool equals(Node* n) {
	if (n->getName() == name)return true;
	return false;
}
public: string getName() {
	return name;
}
public: void setPassed()
{
	isPassed_=true;
}
public: bool isPassed()
{
	return isPassed_;
}
public: void addAdj(Node* node)
{
	adj.push_back(node);
}
public: void addBlockedAdj(Node* blockedNode)
{
	blockedAdj.push_back(blockedNode);
}

public: vector<Node*> getAdj() {
	return adj;
}

public: vector<Node*> getBlockedAdj() {
	return blockedAdj;
}
};

