// IMP-task1-number12.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include "Graph.h";
using namespace std;
int main()
{
    setlocale(LC_ALL,"russian");

    Graph gr;

    Node* a = new Node("A");
    Node* b = new Node("B");
    Node* c = new Node("C");
    Node* d = new Node("D");
    Node* z = new Node("Z");
    Node* g = new Node("g");
    Node* k = new Node("k");

    gr.addAdj(a,c);
    gr.addAdj(a,z);
    gr.addAdj(c,k);
    gr.addAdj(c,g);
    gr.addAdj(z,g);
    gr.addAdj(z,d);
    gr.addAdj(k,d);

    gr.addBlockedAdj(a,c);
    gr.addBlockedAdj(g,z);
    //gr.addBlockedAdj(d,z);
    

    //эту функцию можно поместить в метод addblockedadj но перед этим сделать проверку наличия элементов в списке
    gr.addNode(a);
    gr.addNode(b);
    gr.addNode(c);
    gr.addNode(d);
    gr.addNode(z);
    gr.addNode(g);
    gr.addNode(k);

    gr.printNodes();

    string ans = "Путь не найден";
    Node* startNode = a;
    Node* endNode = d;

    cout << "Путь от " << startNode->getName() << " до " << endNode->getName() << " :\n" << startNode->getName();
    if (gr.search(startNode, endNode)) {//функция не печатает первый нод
        ans = "Путь найден";
    }
    cout<< endl<<ans<< endl;
}
