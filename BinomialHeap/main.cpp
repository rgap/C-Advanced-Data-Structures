#include <iostream>
#include <vector>

using namespace std;

template <class K>
class Node{
public:
    K key;
    int degree;
private:
    int depth;
    Node<K>* parentNode;
    Node<K>* left;
    Node<K>* right;
    vector<Node<K>* > child;

public:

    Node(K key = 0)
    {
        key = 0;
        depth = 0;
        degree = 0;
        parentNode = NULL;
        left = NULL;
        right = NULL;
    }

    void print()
    {
        cout << "\t\tkey = " << key << endl;
        cout << "\t\tdepth = " << depth << endl;
        cout << "\t\tdegree = " << degree << endl;
    }
};

template <class K>
class BinomialHeap {

typedef typename vector<Node<K>* >::iterator Iterator;

public:
    vector<Node<K>* >* head;
    Node<K>* nodeMin;
public:
    BinomialHeap() // makeHeap
    {
        nodeMin = NULL;
        head = new vector<Node<K>* >();
    }

    void insert(K key)
    {
        BinomialHeap<K>* H_p = new BinomialHeap<K>();
        Node<K>* node = new Node<K>(key);
        H_p->head->push_back(node);

        b_union(this, H_p);
    }

    void link(Node<K>* y, Node<K>* z)
    {

    }

    BinomialHeap<K>* b_union(BinomialHeap<K>* H, BinomialHeap<K>* H_p)
    {
        head = merge(H, H_p);

        if(head->empty())
        {
            return H;
        }

        Iterator it = (*head).begin();
        for(; it != ((*head).end() - 1); ++it)
        {
            if((*it)->degree != ((*(it+1))->degree))
            {
            	cout<<"Proceso1\n";
            }
            else{
            	cout<<"Proceso2\n";
            }
        }

        return H;
    }

    vector<Node<K>* >* merge(BinomialHeap<K>* H1, BinomialHeap<K>* H2)
    {
        vector<Node<K>* >* head = new vector<Node<K>* >();

        Iterator it1 = (*(H1->head)).begin(), it2 = (*(H2->head)).begin();
        while(it1 != (*(H1->head)).end() || it2 != (*(H2->head)).end()){
            if (it1 != (*(H1->head)).end()){
                head->push_back(*it1);
                ++it1;
            }
            if (it2 != (*(H2->head)).end()){
                head->push_back(*it2);
                ++it2;
            }
        }

        return head;
    }

    void print()
    {
        Iterator it = (*head).begin();
        cout<< "Head list:\n";
        for(int i=0 ; it != (*head).end(); ++i, ++it)
        {
            cout << "\tHead " << i <<endl;
            (*it)->print();
        }
    }

};

int main(){

    BinomialHeap<int> H;
    H.insert(0);
    H.insert(1);
    H.print();

    return 0;
}
