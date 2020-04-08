//
//  BinaryTree.cpp
//  CommonClass-cpp
//
//  Created by luowailin on 2020/3/31.
//  Copyright © 2020 luowailin. All rights reserved.
//

#include "BinaryTree.hpp"

template <class T>
BinaryTree<T>::BinaryTree(std::function<int (T elemenet1, T element2)> const &compareFunc){
    size = 0;
    compreBlock = compareFunc;
}

template <class T>
BinaryTree<T>::~BinaryTree(){
    
}

template <class T>
bool BinaryTree<T>::isEmpty(){
    return size == 0;
}

template <class T>
void BinaryTree<T>::clear(){
    
}

template <class T>
int BinaryTree<T>::treeHeight(){
    return 0;
}

template<class T>
void BinaryTree<T>::levelOrderTraversalUsingClosure(const std::function<void (T)> &func){
    
}

template<class T>
void BinaryTree<T>::preorderTraversalUsingBlock(const std::function<void (T)> &func){
    block = func;
    preorderTraversalNode(root);
    block = nullptr;
}

template<class T>
void BinaryTree<T>::inorderTraversalUsingBlock(const std::function<void (T)> &func){
    block = func;
    inorderTraversalNode(root);
    block = nullptr;
}

template<class T>
void BinaryTree<T>::postorderTraversalUsingBlock(const std::function<void (T)> &func){
    block = func;
    postorderTraversalNode(root);
    block = nullptr;
}

template<class T>
TreeNode<T> BinaryTree<T>::successor(TreeNode<T> node){
    return nullptr;
}

template<class T>
TreeNode<T> BinaryTree<T>::predecessor(TreeNode<T> node){
    return nullptr;
}

template<class T>
void BinaryTree<T>::add(T element){
    if (element == nullptr) {
        return;
    }
    
    if (root == nullptr) {
        root = TreeNode<T>(element, nullptr);
        size++;
        return;
    }
    
    TreeNode<T> node = root;
    TreeNode<T> parent = root;
    
    while (node != nullptr) {
        parent = node;
        
    }
}

#pragma mark -- private method
template<class T>
void BinaryTree<T>::preorderTraversalNode(TreeNode<T> node){
    
}


template<class T>
void BinaryTree<T>::inorderTraversalNode(TreeNode<T> node){
    
}

template<class T>
void BinaryTree<T>::postorderTraversalNode(TreeNode<T> node){
    
}
