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
int BinaryTree<T>::count(){
    return size;
}

template<class T>
void BinaryTree<T>::add(T element){
    if (elementIsNotNull(element)) {
        return;
    }
    
    if (root == nullptr) {
        root = TreeNode<T>(element, nullptr);
        size++;
        return;
    }
    
    TreeNode<T> node = root;
    TreeNode<T> parent = node.parent;
    int cmp;
    while (node != nullptr) {
        parent = node;
        cmp = compareable(node.element, element);
        if (cmp > 0) {
            node = node.right;
        } else if (cmp < 0) {
            node = node.left;
        } else { //相等
            return;
        }
    }
    if (cmp > 0) {
        parent.right = new TreeNode<T>(element, parent);
    } else {
        parent.left = new TreeNode<T>(element, parent);
    }
    size++;
}

template <class T>
void BinaryTree<T>::remove(T element) {
    
}

template <class T>
bool BinaryTree<T>::contains(T element) {
    return false;
}

template <class T>
bool BinaryTree<T>::isEmpty(){
    return size == 0;
}


template <class T>
void BinaryTree<T>::clear(){
    
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

#pragma mark -- private method
template<class T>
bool BinaryTree<T>::elementIsNotNull(T element) {
    if (element == nullptr) {
        return true;
    }
    
    return false;
}

template<class T>
int BinaryTree<T>::compareable(T element1, T element2){
   return compareable(element1, element2);
}

template<class T>
void BinaryTree<T>::preorderTraversalNode(TreeNode<T> node){
    
}


template<class T>
void BinaryTree<T>::inorderTraversalNode(TreeNode<T> node){
    
}

template<class T>
void BinaryTree<T>::postorderTraversalNode(TreeNode<T> node){
    
}
