#include "MyTree.cpp"

using namespace std;

int main() 
{
	MyTree<string> tree;
	tree.INSERT(0, "*", 0);
	tree.INSERT(1, "+", 0);
	tree.INSERT(2, "/", 0);
	tree.INSERT(3, "^", 1);
	tree.INSERT(4, "3", 1);
	tree.INSERT(5, "a", 2);
	tree.INSERT(6, "+", 2);
	tree.INSERT(7, "a", 3);
	tree.INSERT(8, "b", 6);
	tree.INSERT(9, "c", 6);
	cout << "PREORDER: " << endl;
	tree.PREORDER();
	cout << "\n\nPOSTORDER: " << endl;
	tree.POSTORDER();
	cout << "\n\nINORDER: " << endl;
	tree.INORDER();
	return 0;
}