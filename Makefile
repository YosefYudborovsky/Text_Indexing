all:
	g++ -std=c++11 MainBST.cpp BinarySearchTree.cpp BinaryNode.cpp NotFoundException.cpp -o BST

clean:
	rm *.o
	rm BST