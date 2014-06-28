#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

template < class N, class E >
class Edge;

template < class N, class E >
class Node 
{

typedef typename vector<Edge <N,E>* >::iterator Iterator;

public:
    N data;
    vector<Edge<N, E>*> edgeList;
    Node(N data_)
    {
        data = data_;
    }

    bool operator == (const Node<N,E> & node)
    {
        return data == node.data;
    }

    void printEdges()
    {
        Iterator it = edgeList.begin();
        for(int i = 0 ; it != edgeList.end(); ++i, ++it){
            cout << "\tEdge " << i << ", " << "data = " << (*it)->data << endl;
            cout << "\t" << data << " -> " << (*it)->targetNode->data << endl;
        }
    }

};

template < class N, class E >
class Edge 
{
public:
    E data;
    Node<N, E>* targetNode;
    Edge(E data_, Node<N, E>*targetNode_ = 0)
    {
        data = data_;
        targetNode = targetNode_;
    }
};

template < class N, class E >
class Graph 
{

typedef typename vector<Node <N,E>* >::iterator Iterator;

private:
    vector<Node<N,E>*> nodeList;

public:
    
    Graph(){}

    void print()
    {
        Iterator it = nodeList.begin();
        for( int i = 0; it != nodeList.end(); ++i , ++it){
            cout << "Node " << i << ", " << "data = " << (*it)->data << endl;
            (*it)->printEdges();
        }
    }

    Node<N,E>* insertNode(N data)
    {
        Node<N, E>* node = new Node<N, E>(data);
        nodeList.push_back(node);
        return node;
    }

    Edge<N,E>* insertEdge(Node<N, E>*source, Node<N, E>*target, E data)
    {
        Edge<N, E>* edge = new Edge<N, E>(data, target);
        source->edgeList.push_back(edge);
        return edge;
    }

    Edge<N,E>* insertEdge(N sourceData, N targetData, E data)
    {
        Node<N,E>* p = findNode(sourceData);
        Node<N,E>* q = findNode(targetData);
        if(p && q){
            return insertEdge(p, q, data);
        }
        return 0;
    }

    Node<N,E>* findNode(N data)
    {
        Iterator it = nodeList.begin();
        for(; it != nodeList.end(); ++it)
        {
            if(*(*it) == Node<N,E>(data)){
                return *it;
            }
        }
        return 0;
    }
};

int main()
{
    Graph <int, int>G;
    G.insertNode(0);
    G.insertNode(1);
    G.insertNode(2);
    G.insertNode(3);
    G.insertNode(4);

    G.insertEdge(0, 1, 10);
    G.insertEdge(0, 2, 20);
    G.insertEdge(1, 2, 30);
    G.insertEdge(1, 3, 40);
    G.insertEdge(2, 3, 50);
    G.insertEdge(3, 4, 60);

    G.print();
    return 1;
}

