//
//  BinaryTree.cpp
//  CommonClass-cpp
//
//  Created by luowailin on 2020/3/31.
//  Copyright © 2020 luowailin. All rights reserved.
//

#include "BinaryTree.hpp"

BinaryTree::BinaryTree(){
    size = 0;
}

BinaryTree::~BinaryTree(){
    
}

bool BinaryTree::isEmpty(){
    return size == 0;
}

void BinaryTree::clear(){
    
}

int BinaryTree::treeHeight(){
    return 0;
}

template<class T> void BinaryTree::levelOrderTraversalUsingClosure(const std::function<void (T)> &func){
    func(nullptr);
}

template<class T> void BinaryTree::preorderTraversalUsingBlock(const std::function<void (T)> &func){
    
}

template<class T> void BinaryTree::inorderTraversalUsingBlock(const std::function<void (T)> &func){
    
}

template<class T> void BinaryTree::postorderTraversalUsingBlock(const std::function<void (T)> &func){
    
}

template<class T> TreeNode<T> BinaryTree::successor(TreeNode<T> node){
    return nullptr;
}

template<class T> TreeNode<T> BinaryTree::predecessor(TreeNode<T> node){
    return nullptr;
}
