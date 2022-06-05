#pragma once
#include <iostream>
template<class T>
struct Node {
	int index;
	T label;
	int parent;
};

template<class T>
class MyTree
{
private:
	int TreeSize = 10;
	Node<T>* root;
public:
	MyTree() { MAKENULL(); }
	void MAKENULL();
	Node<T> PARENT(int n);
	Node<T> LEFTMOST_CHILD(int n);
	Node<T> RIGHT_SIBLING(int n);
	T LABEL(int n);
	Node<T> ROOT();
	void INSERT(int n, T x, int p);
	bool ISLEAF(Node<T> n);
	void PREORDER();
	void POSTORDER();
	void INORDER();
private:
	void PREORDER(Node<T> n);
	void POSTORDER(Node<T> n);
	void INORDER(Node<T> n);
};

