#ifndef TREENODE_H
#define TREENODE_H

#include <iostream>
using std::cout;
using std::cerr;
using std::endl;
using std::ostream;

#include <memory>
using std::unique_ptr;

#include <utility>
using std::pair;

// TODO your code for the TreeNode class goes here:

template<typename T>
class TreeNode {
public:
    T data;
    unique_ptr<TreeNode<T>> leftChild;
    unique_ptr<TreeNode<T>> rightChild;
    TreeNode<T> *parent;

    TreeNode(T dataIn) :
            data(dataIn),
            parent(nullptr) {}

    TreeNode(const TreeNode &t2) :
            data(t2.data),
            parent(nullptr) {}

    void setLeftChild(TreeNode *child) {
        leftChild.reset(child);
        leftChild->parent = this;
    }

    void setRightChild(TreeNode *child) {
        rightChild.reset(child);
        rightChild->parent = this;
    }

    const ostream &write(ostream &o) {
        if (leftChild) {
            leftChild->write(o);
        }
        o << " " << data << " ";
        if (rightChild) {
            rightChild->write(o);
        }
        return o;
    }

    int maxDepth(){
        int left = 0, right = 0;
        TreeNode<T>*  tempLeft  =  leftChild.get();
        TreeNode<T>*  tempRight  =  rightChild.get();
        if(leftChild) {
            left = tempLeft->maxDepth();
            ++left;
        }
        if(tempRight) {
            right = tempRight->maxDepth();
            ++right;
        }
        if(right > left){
            return right;
        }
        else
            {
            return left;
        }
    }

};

    template<typename T>
    class TreeNodeIterator {
    private:
        TreeNode<T> *treeNode;
        TreeNode<T> *temp;
    public:
       explicit TreeNodeIterator(TreeNode<T>* currentNode):
        treeNode(currentNode){}

        T& operator*(){
            return treeNode->data;
        }

        bool operator==(const TreeNodeIterator& other){
            return treeNode == other.treeNode;
        }

        bool operator!=(const TreeNodeIterator& other){
            return treeNode != other.treeNode;
        }
        TreeNode<T>  * before_successor(
                TreeNode<T> * root,
                TreeNode<T> * before,
                TreeNode<T> * successor,
                int data){
           if (root == nullptr) {
               return root;
           }
            if(root->data == data){
                    if(root->leftChild != NULL) {
                            TreeNode<T> * temp = root->leftChild.get();
                            while (temp->rightChild.get()) {
                                temp = temp->rightChild.get();
                            }
                            before = temp;
                    }
                    if (root->data > data) {
                        successor = root;
                        before_successor(root->leftChild.get(), before, successor, data);
                    }
                    else{
                        before = root;
                        before_successor(root->rightChild.get(), before, successor, data);
                    }
                    if(root->rightChild != NULL) {
                            TreeNode<T> * temp = root->rightChild.get();
                            while (temp->leftChild.get()) {
                                temp = temp->leftChild.get();
                            }
                            before = temp;
                    }
            }
            return successor;
        }

            void operator++() {
                TreeNode<T> *before, *successor;
                before = successor = NULL;
                treeNode = before_successor(treeNode, before, successor, treeNode->data);
            }

    };

// do not edit below this line

#endif