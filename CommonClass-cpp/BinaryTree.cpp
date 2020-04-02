//
//  BinaryTree.cpp
//  CommonClass-cpp
//
//  Created by luowailin on 2020/3/31.
//  Copyright © 2020 luowailin. All rights reserved.
//

#include "BinaryTree.hpp"

template <class T>
BinaryTree<T>::BinaryTree(){
    size = 0;
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
    func(nullptr);
}

template<class T>
void BinaryTree<T>::preorderTraversalUsingBlock(const std::function<void (T)> &func){
    
}

template<class T>
void BinaryTree<T>::inorderTraversalUsingBlock(const std::function<void (T)> &func){
    
}

template<class T>
void BinaryTree<T>::postorderTraversalUsingBlock(const std::function<void (T)> &func){
    
}

template<class T>
TreeNode<T> BinaryTree<T>::successor(TreeNode<T> node){
    return nullptr;
}

template<class T>
TreeNode<T> BinaryTree<T>::predecessor(TreeNode<T> node){
    return nullptr;
}
