#ifndef TREE_H
#define TREE_H

#include "treenode.h"

// TODO your code goes here:
template<typename T>
class BinarySearchTree {
private:
    unique_ptr<TreeNode<T>> root;
public:
    BinarySearchTree() {
    }

    void write(ostream &os) const {
        root->write(os);
    }

    TreeNode<T> *insert(const T &item) {
        TreeNode<T> *insert = new TreeNode<T>(item);
        if (!root.get()) {
            root.reset(insert);
            return insert;
        }
        TreeNode<T> *temp = root.get();
        check(temp, insert);
        return 0;
    }

    TreeNode<T> *check(TreeNode<T> *temp, TreeNode<T> *insert) {
        //smaller
        if (insert->data < temp->data) {
            return left(temp, insert);
        }
            //bigger
        else if (temp->data < insert->data) {
            return right(temp, insert);
        } else {
            return 0;
        }
    }

    TreeNode<T> *left(TreeNode<T> *temp, TreeNode<T> *insert) {
        if (temp->leftChild.get() == nullptr) {
            temp->setLeftChild(insert);
        } else {
            temp = temp->leftChild.get();
            right(temp, insert);
        }
        if (temp->parent) {
            return 0;
        }
        return insert;
    }

    TreeNode<T> *right(TreeNode<T> *temp, TreeNode<T> *insert) {
        if (temp->rightChild.get() == nullptr) {
            temp->setRightChild(insert);
        }
        else {
            temp = temp->rightChild.get();
            left(temp, insert);
        }
        if (temp->parent) {
            return 0;
        }
        return insert;
    }

    TreeNode<T> *find(T newNode) {
        TreeNode<T> *location = root.get();
        do {
            if (newNode < location->data) {
                location = location->leftChild.get();
            }
            else if (location->data < newNode) {
                location = location->rightChild.get();
            }
            else {
                return location;
            }
        } while (location);
        return 0;
    }

    void makeCopy(const BinarySearchTree<T> &insertTree, TreeNode<T> *node) {
        this->insert(node->data);
        if (node->leftChild != nullptr) {
            makeCopy(insertTree, node->leftChild.get());
        }
        if (node->rightChild != nullptr) {
            makeCopy(insertTree, node->rightChild.get());
        }

    }

    BinarySearchTree(const BinarySearchTree &copy) {
        makeCopy(copy, copy.root.get());
    }

    //assignemtn
    BinarySearchTree operator=(const BinarySearchTree &copy) {
        makeCopy(copy, copy.root.get());
        return copy;
    }


    //ADVANCED PART

TreeNodeIterator<T>begin(){
        TreeNodeIterator<T>itr = TreeNodeIterator<T>(nullptr);
        TreeNode<T>* current = nullptr;
        if(root){
            current = root.get();
            itr = TreeNodeIterator<T>(current);
            while(current->leftChild){
                current = current->leftChild.get();
                itr = TreeNodeIterator<T>(current);
            }
        }
        return itr;
    }

    TreeNodeIterator<T>end(){
        TreeNodeIterator<T> theEnd = TreeNodeIterator<T>(nullptr);
        return theEnd;
    }

    int maxDepth(){
        int depth = 0;
        if(root){
            depth = root->maxDepth();
        }
        return depth;
    }

    int balanceFactor(TreeNode<T>*node)const {
        return node->maxDepth(node->leftChild.get()) - node->maxDepth()(node->rightChild.get());
    }
    /*
   void leftRotation(TreeNode<T>* parent){
        T newNode = parent->data;
        TreeNode<T>* newTop = parent->rightChild.get();
        parent->rightChild.release();
        if(parent == root.get()){
            root.reset(newTop);
            insert(newNode);
        }
        else{
            parent->parent->setRightChild(newTop);
            insert(newNode);
        }
    }

    void rightRotation(TreeNode<T>* parent){
       T newNode = parent->data;
        TreeNode<T>* newTop = parent->leftChild.get();
        parent->leftChild.release();
        if(parent == root.get()){
            root.reset(newTop);
            insert(newNode);
        }
        else{
            parent->parent->setLeftChild(newTop);
            insert(newNode);
        }
    }

    void leftRightRotation(TreeNode<T>* &node){
        TreeNode<T>* oldTop = node->leftChild.get();
        TreeNode<T>* newTop = node->leftChild.get()->rightChild.get();
        node->leftChild.release();
        node->setLeftChild(newTop);
        oldTop->rightChild.release();
        newTop->setLeftChild(oldTop);
        leftRotation(node);
        rightRotation(node);
    }

    void rightLeftRotation(TreeNode<T>* &node){
        TreeNode<T>* oldTop = node->rightChild.get();
        TreeNode<T>* newTop = node->rightChild.get()->leftChild.get();
        node->rightChild.release();
        node->setLeftChild(newTop);
        oldTop->leftChild.release();
        newTop->setLeftChild(oldTop);
        rightRotation(node);
        leftRotation(node);
    }

    int balanceFactor(TreeNode<T>* temp) {
        int balanced = 0, left = 0, right = 0;
        if(temp->leftChild){
            left = maxDepth(temp->leftChild.get());
        }
        else{
            left = 0;
        }
       // left = temp->leftChild.get()->maxDepth();
        std::cout<<"left is "<<left;
        if(temp->rightChild){
            right = maxDepth(temp->rightChild.get());
        }
        else{
            right = 0;
        }
        //temp->rightChild.get();
            //right = temp->rightChild.get()->maxDepth();
            //right = rightChild.get()->maxDepth;
            std::cout<<"right is "<<right;

        balanced = left - right;
        return balanced;
    }

    void balance(TreeNode<T>* temp) {
            std::cout<<"balance"<< balanceFactor(temp);
            if (balanceFactor(temp) == 2) {
                if (!temp->parent->leftChild.get()->rightChild) {
                    rightRotation(temp);
                } else if (!temp->parent->leftChild.get()->leftChild) {
                    rightRotation(temp);
                }
            } else if (balanceFactor(temp) == -2) {
                if (!temp->parent->rightChild.get()->leftChild) {
                    leftRotation(temp);
                } else if (!temp->parent->rightChild.get()->rightChild) {
                    leftRotation(temp);
                }
            } else if (balanceFactor(temp) != 0) {
                if (!temp->parent->leftChild.get()->leftChild) {
                    leftRightRotation(temp);
                } else if (!temp->parent->rightChild.get()->rightChild) {
                    rightLeftRotation(temp);
                }
            }
            //std::cout<<"no balance ";
        }


    };*/
    TreeNode<T>* rightRotation(TreeNode<T>* parent) {
        TreeNode<T> * parentParent = parent->parent;
        if(parentParent->parent != nullptr) {
            assignPPR(parentParent, parent);
        }
        else{
        }
        updateParentRight(parentParent,parent);
    }

    TreeNode<T>* leftRotation(TreeNode<T> * parent) {
        TreeNode<T> * parentParent = parent->parent;
        if(parentParent->parent != nullptr) {
            assignPPL(parentParent, parent);
        }
        else{
        }
        updateParentLeft(parentParent,parent);
    }


    void assignPPR(TreeNode<T>* parentParent, TreeNode<T>* parent) const {
        parentParent->parent->leftChild.release();
        parentParent->parent->leftChild.reset(parent);
        parent->parent = parentParent->parent;
    }

    void assignPPL(TreeNode<T> * parentParent, TreeNode<T> * parent) const {
        parentParent->parent->rightChild.release();
        parentParent->parent->rightChild.reset(parent);
        parent->parent = parentParent->parent;
    }

    void updateParentRight(TreeNode<T>* parentParent, TreeNode<T>* parent) {
        parent->rightChild.release();
        parent->rightChild.reset(parentParent);
        parentParent->parent = parent;
        parentParent->leftChild.release();
    }

    void updateParentLeft(TreeNode<T>* parentParent, TreeNode<T>* parent) {
        parent->leftChild.release();
        parent->leftChild.reset(parentParent);
        parentParent->parent = parent;
        parentParent->rightChild.release();
    }

    void balance(TreeNode<T>* temp){
        int balanceFactor = balanceFactor(root.get());
        if (balanceFactor == 2){
            if (!temp->parent->leftChild.get()->rightChild) {
                temp = rightRotation(temp);
            } else if (!temp->parent->leftChild.get()->leftChild) {
                temp = rightRotation(temp);
            }
            else if (balanceFactor == -2){
                if (!temp->parent->rightChild.get()->leftChild) {
                    temp = leftRotation(temp);
                } else if (!temp->parent->rightChild.get()->rightChild) {
                    temp = leftRotation(temp);
                }
            }
            else{
            }
        }
    }
};


// do not edit below this line

#endif
