#include "MyTree.h"

template<class T>
void MyTree<T>::MAKENULL()
{
	if (root != nullptr)
		delete[]root;

	root = new Node<T>[TreeSize];
	for (int i = 0; i < TreeSize; i++)
		root[i].parent = 0;
}

template<class T>
Node<T> MyTree<T>::PARENT(int n)
{
	return root[root[n].parent];
}

template<class T>
Node<T> MyTree<T>::LEFTMOST_CHILD(int n)
{
	for (int i = n + 1; i < TreeSize; i++)
		if (root[i].parent == n) 
			return root[i];

	return root[0];
}

template<class T>
Node<T> MyTree<T>::RIGHT_SIBLING(int n) 
{
	if (root[n + 1].parent == root[n].parent) 
		return root[n + 1];

	return root[0];
}

template<class T>
T MyTree<T>::LABEL(int n) 
{
	return root[n].label;
}

template<class T>
Node<T> MyTree<T>::ROOT()
{
	return root[0];
}

template<class T>
void MyTree<T>::INSERT(int n, T x, int p) 
{
	root[n].index = n;
	root[n].label = x;
	root[n].parent = p;
}

template<class T>
bool MyTree<T>::ISLEAF(Node<T> n) 
{
	return LEFTMOST_CHILD(n.index).index == 0;
}

template<class T>
void MyTree<T>::PREORDER() 
{
	PREORDER(root[0]);
}

template<class T>
void MyTree<T>::POSTORDER() 
{
	POSTORDER(root[0]);
}

template<class T>
void MyTree<T>::INORDER() 
{
	INORDER(root[0]);
}

template<class T>
void MyTree<T>::PREORDER(Node<T> n) {
	std::cout << LABEL(n.index) << ", ";
	Node<T> ñ = LEFTMOST_CHILD(n.index);
	while (ñ.index != 0) 
	{
		PREORDER(ñ);
		ñ = RIGHT_SIBLING(ñ.index);
	}
}

template<class T>
void MyTree<T>::POSTORDER(Node<T> n) {
	Node<T> ñ = LEFTMOST_CHILD(n.index);
	while (ñ.index != 0) 
	{
		POSTORDER(ñ);
		ñ = RIGHT_SIBLING(ñ.index);
	}
	std::cout << LABEL(n.index) << ", ";
}

template<class T>
void MyTree<T>::INORDER(Node<T> n) 
{
	if (ISLEAF(n))
		std::cout << LABEL(n.index) << ", ";
	else 
	{
		Node<T> c = LEFTMOST_CHILD(n.index);
		while (c.index != 0) {
			INORDER(c);
			if (c.index == LEFTMOST_CHILD(c.parent).index) {
				std::cout << PARENT(c.index).label << ", ";
			}
			c = RIGHT_SIBLING(c.index);
		}
	}
}