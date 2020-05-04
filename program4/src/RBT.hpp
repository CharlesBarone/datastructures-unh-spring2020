//
//  RBT.hpp
//  program4
//
//  Created by Charles Barone on 5/03/20.
//  Copyright © 2020 Charles Barone. All rights reserved.
//

#pragma once

#include <iostream>

enum Color {
	RED,
	BLACK
};

template <typename T>
struct Value {
	T value;
	Value() = default;
	Value(T t) { value = t; }
	inline bool operator>(T& t) { return value > t; }
	inline bool operator<(T& t) { return value < t; }
	inline bool operator==(T& t) { return value == t; }
};

template <typename T>
struct Node {
	Node();
	Value<T> key;
	bool color;
	Node<T> *left, *right, *parent;
};

template <typename T>
Node<T>::Node() {
	left = nullptr;
	right = nullptr;
	parent= nullptr;
}

template <typename T>
Node<T>* createRBT(const T& item) {
	Node<T>* node = new Node<T>;
	node->key.value = item;
	return node;
}

template <typename T>
void fixViolation(Node<T>*& root, Node<T>*& item) {
	Node<T> *parent_item = nullptr;
	Node<T> *grandParent_item = nullptr;
	while ((item != root) && (item->color != BLACK) && (item->parent->color == RED)) {
		parent_item = item->parent;
		grandParent_item = item->parent->parent;
		if (parent_item == grandParent_item->left) {
			Node<T>* uncle_item = grandParent_item->right;
			if (uncle_item != nullptr && uncle_item->color == RED) {
				grandParent_item->color = RED;
				parent_item->color = BLACK;
				uncle_item->color = BLACK;
				item = grandParent_item;
			} else {
				if (item == parent_item->right) {
					rotateLeft(root,parent_item);
					item = parent_item;
					parent_item = item->parent;
				}
				rotateRight(root,grandParent_item);
				std::swap(parent_item->color, grandParent_item->color);
				item = parent_item;
			}
		} else {
			Node<T>* uncle_item = grandParent_item->left;
			if ((uncle_item != nullptr) && (uncle_item->color == RED)) {
				grandParent_item->color = RED;
				parent_item->color = BLACK;
				uncle_item->color = BLACK;
				item = grandParent_item;
			} else {
				if (item == parent_item->left) {
					rotateRight(root,parent_item);
					item = parent_item;
					parent_item = item->parent;
				}
				rotateLeft(root,grandParent_item);
				std::swap(parent_item->color, grandParent_item->color);
				item = parent_item;
			}
		}
	}
	root->color = BLACK;
}

template <typename T>
Node<T>* RedBlack_insert(Node<T>* root, Node<T>* item) {
	if (root == nullptr)
		return item;
	if (item->key.value < root->key.value) {
		root->left = RedBlack_insert(root->left, item);
		root->left->parent = root;
	} else if (item->key.value > root->key.value) {
		root->right = RedBlack_insert(root->right, item);
		root->right->parent = root;
	}
	return root;
}

template <typename T>
Node<T>* insertion(Node<T>* root, const T& item) {
	Node<T>* node = createRBT(item);
	root = RedBlack_insert(root, node);
	fixViolation(root, node);
	return root;
}

template <typename T>
void rotateRight(Node<T>*& root, Node<T>*& item) {
	Node<T>* parent_left = item->left;
	item->left = parent_left->right;
	if (item->left != nullptr)
		item->left->parent = item;
	parent_left->parent = item->parent;
	if (item->parent == nullptr)
		root = parent_left;
	else if (item == item->parent->left)
		item->parent->left = parent_left;
	else
		item->parent->right = parent_left;
	parent_left->right = item;
	item->parent = parent_left;
}

template <typename T>
void rotateLeft(Node<T>*& root, Node<T>*& item) {
	Node<T>* parent_right = item->right;
	item->right = parent_right->left;
	if (item->right != nullptr)
		item->right->parent = item;
	parent_right->parent = item->parent;
	if (item->parent == nullptr)
		root = parent_right;
	else if (item == item->parent->left)
		item->parent->left = parent_right;
	else
		item->parent->right = parent_right;
	parent_right->left = item;
	item->parent = parent_right;
}

template <typename T>
void printRBT(const Node<T>* root) {
	if (root == nullptr)
		return;
	printRBT(root->left);
	std::cout << root->key.value << " ";
	printRBT(root->right);
}

template <typename T>
void Find(Node<T>* root) {
	if (root == nullptr) {
		return;
	}
	T x;
	std::cout << "\nEnter key to be found: ";
	std::cin >> x;
	Node<T>* p = root;
	auto _x = x;
	bool found = false;
	while(p != nullptr && !found) {
		if(p->key == _x)
			found = true;
		if(!found) {
			if(p->key < _x)
				p = p->right;
			else
				p = p->left;
		}
	}
	if(!found)
		std::cout << "\nNode Not Found.";
	else {
		std::cout << "\nFound Node:" << "\n\tColor: ";
		if(p->color == RED)
			std::cout << "Red";
		else
			std::cout << "Black";
		std::cout << "\n\tKey Value: " << p->key.value << std::endl;
	}
}

template <typename T>
void FindX(Node<T>* root, T x) {
	if (root == nullptr) {
		return;
	}
	Node<T>* p = root;
	auto _x = x;
	bool found = false;
	while(p != nullptr && !found) {
		if(p->key == _x)
			found = true;
		if(!found) {
			if(p->key < _x)
				p = p->right;
			else
				p = p->left;
		}
	}
	if(!found)
		std::cout << "\nNode Not Found.";
	else {
		std::cout << "\nFound Node:" << "\n\tColor: ";
		if(p->color == RED)
			std::cout << "Red";
		else
			std::cout << "Black";
		std::cout << "\n\tKey Value: " << p->key.value << std::endl;
	}
}

int Max(int x, int y) {
	if(x >= y)
		return x;
	else
		return y;
}

template <typename T>
int Height(const Node<T>* root) {
	if(root == nullptr)
		return 0;
	else
		return 1 + Max(Height(root->left), Height(root->right));
}