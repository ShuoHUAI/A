/*************************************************************************
	>> File Name: binary1.cpp
	>> Author:HuaiShuo 
	>> Created Time: Sun 04 Dec 2016 12:34:10 PM CST
 ************************************************************************/

#include<iostream>
#include</home/huaishuo/workspace/ds/binaryTree.cpp>
using namespace std;
int main(){
        binaryTree<int> *one = new binaryTree<int>();
        int aa = 2;
        listNode<int> *a = new listNode<int>(aa);
        one->root = a;
        aa = 5;
        a = new listNode<int> (aa);
        one->root->leftChild=a;
        aa = 3;
        a = new listNode<int> (aa);
        one->root->rightChild=a;
        aa = 4;
        a = new listNode<int>(aa);
        one->root->leftChild->leftChild=a;
        aa = 7;
        a = new listNode<int> (aa);
        one->root->rightChild->leftChild=a;
        aa = 8;
        a = new listNode<int> (aa);
        one->root->rightChild->rightChild=a;
        cout<<endl<<"PreOrder..."<<endl;
        one->preOrder(one->root);
        cout<<endl<<"InOrder..."<<endl;
        one->inOrder(one->root);
        cout<<endl<<"PostOoder..."<<endl;
        one->postOrder(one->root);
        cout<<endl<<"LevelOrder..."<<endl;
        one->levelOrder(one->root);
        cout<<endl<<"The number of node "<<one->size(one->root)<<endl<<"The height of the binarytree "<<one->height(one->root)<<endl;
        return 0;
}

