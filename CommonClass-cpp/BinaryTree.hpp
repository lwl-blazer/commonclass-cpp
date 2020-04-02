//
//  BinaryTree.hpp
//  CommonClass-cpp
//
//  Created by luowailin on 2020/3/31.
//  Copyright © 2020 luowailin. All rights reserved.
//

#ifndef BinaryTree_hpp
#define BinaryTree_hpp

#include <stdio.h>
#include <functional>

//二叉搜索树
template <typename T>
struct TreeNode {
    T element;
    TreeNode left;
    TreeNode right;
    TreeNode parent;
    TreeNode(T e, TreeNode p){
        element = e;
        parent = p;
    }
};

template<class T>
class BinaryTree {
private:
    std::function<void (T element)>block;
    void preorderTraversalNode(TreeNode<T> node);
    void inorderTraversalNode(TreeNode<T> node);
    void postorderTraversalNode(TreeNode<T> node);

    TreeNode<T> predecessor(TreeNode<T> node);
    TreeNode<T> successor(TreeNode<T> node);
protected:
    TreeNode<T> root;
    
public:
    int size;
    
    BinaryTree();
    ~BinaryTree();

    void add(T element);
    bool isEmpty();
    void clear();
    int treeHeight();
  
    /** 层序遍历
     * 计算二叉树的高度
     * 判断一棵树是否为完全二叉树
     */
    void levelOrderTraversalUsingClosure(std::function<void (T element)> const &func);
    
    /**前序遍历
     * 先根节点(再左子树再右子树)
     */
    void preorderTraversalUsingBlock(std::function<void (T element)> const &func);
    
    /**中序遍历
     * 先左子树 再根节点 再右子树
     */
    void inorderTraversalUsingBlock(std::function<void (T element)> const &func);
    
    /**后序遍历
     * 先左子树 再右子树 后根节点
     * 适用于一些先子后父的操作
     **/
    void postorderTraversalUsingBlock(std::function<void (T element)> const &func);
};

#endif /* BinaryTree_hpp */
