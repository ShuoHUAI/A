/*************************************************************************
	>> File Name: binarySearchTree.cpp
	>> Author:HuaiShuo 
	>> Created Time: Sun 04 Dec 2016 12:11:11 PM CST
 ************************************************************************/

#include<iostream>
#include</home/huaishuo/workspace/ds/binaryTree.cpp>
using namespace std;
template<class T>
void insert(binaryTree< pair<int,T> > &binary,pair<int,T> &thePair){
    listNode< pair<int,T> > *p = binary.root,*pp=NULL;
    while (p!=NULL){
        pp = p;//这样就保证了pp是p的父节点
        if(thePair.first<p->data.first)
            p = p->leftChild;
        else{
            if(thePair.first>p->data.first)
                p = p->rightChild;
            else{
                p->data.second=thePair.second;
                return;
            }
        }
    }
    listNode< pair<int,T> > *newNode = new listNode< pair<int,T> >(thePair);
    if(binary.root!=NULL)
        if(thePair.first<pp->data.first)
            pp->leftChild = newNode;
        else
            pp->rightChild = newNode;
    else
        binary.root = newNode;
}
template<class T>
void output(listNode< pair<int,T> > *t){
    if(t != NULL){
        output(t->leftChild);
        cout<<"The key :"<<t->data.first<<" The element :"<<t->data.second<<endl;
        output(t->rightChild);
    }
}
int main(){
    binaryTree< pair <int,int> > *one = new binaryTree< pair<int,int> >();
    cout<<"Please enter the number of the elements"<<endl;
    int n,a,b;
    cin>>n;
    for(int i = 0;i<n;i++){
        cin>>a>>b;
        pair<int,int> *p = new pair<int,int>(a,b);
        insert(*one,*p);
    }
    cout<<"Output..."<<endl;
    output(one->root);
    return 0;
}
