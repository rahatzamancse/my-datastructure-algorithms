#pragma once

#include <iostream>
#include <map>
#include <algorithm>
#include <queue>
#include <stack>

template <typename T>
class Tree {
public:
	struct Node {
	public:
		T info;
		Node *left, *right;
		Node(T data) : info(data), left(nullptr), right(nullptr) { }
	};

	Node *t_root;
	Tree() : t_root(nullptr) {   }

	//Accessors
	Node* root() const { return t_root; }

	//Searching
	Node* bfs(T, Node* = nullptr) const;
	Node* dfs(T, Node* = nullptr) const;

	//Traversal recursive
	void recursiveInOrderTraverse(Node* = nullptr) const;
	void recursivePreOrderTraverse(Node* = nullptr) const;
	void recursivePostOrderTraverse(Node* = nullptr) const;

	//Traversal recursive
	void iterativeInOrderTraverse() const;
	void iterativePreOrderTraverse() const;
	void iterativePostOrderTraverse() const;
	void levelOrderTraverse() const;

	//Properties calculations
	int height(Node* = nullptr) const;
};