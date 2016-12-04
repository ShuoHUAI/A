#include "stdio.h"
#include<iostream>
#include<queue>
using namespace std;
template<class T>
class listNode {
public:
	listNode(T &t) { data = t; leftChild = NULL; rightChild = NULL; };
	listNode *leftChild, *rightChild;
	T data;
};
template<class T>
class binaryTree {
public:
	binaryTree() { root = NULL;};
	~binaryTree() { dispose(root); };
	void preOrder(listNode<T> *t) { if (t != NULL) { cout << t->data<<"\t"; preOrder(t->leftChild); preOrder(t->rightChild); } };
	void inOrder(listNode<T> *t) { if (t != NULL) { inOrder(t->leftChild); cout << t->data<<"\t"; inOrder(t->rightChild); } };
	void postOrder(listNode<T> *t) { if (t != NULL) { postOrder(t->leftChild); postOrder(t->rightChild); cout << t->data<<"\t"; } };
	void levelOrder(listNode<T> *t);
	void dispose(listNode<T> *t) { if (t != NULL) { dispose(t->leftChild); dispose(t->rightChild); delete t; } };
    int height(listNode<T> *t){if(t==NULL) return 0;int h1 = height(t->leftChild);int h2 = height(t->rightChild);if(h1>h2) return ++h1;else 
                               return ++h2;}
	listNode<T> *root;
	int size(listNode<T> *t){if(t==NULL) return 0;int s1 = size(t->leftChild);int s2 = size(t->rightChild);return s1+s2+1;};
};
template<class T>
void binaryTree<T>::levelOrder(listNode<T> *t){
    queue< listNode<T>* > *q = new queue< listNode<T>* >();
    while(t !=NULL){
        cout<<t->data<<"\t";
        if(t->leftChild!=NULL)
            q->push(t->leftChild);
        if(t->rightChild!=NULL)
            q->push(t->rightChild);
        if(!q->empty()) {t = q->front();}
        else return;
        q->pop();
    }
}


