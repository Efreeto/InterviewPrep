//#include <memory>
//#include <cassert>
//
//#ifndef NULL
//#define NULL 0
//#endif
//
//using namespace std;
//
//class Node
//{
//	int data;
//	unique_ptr<Node> left;
//	Node* right;
//public:
//	Node();
//	~Node();
//	int addLeft(int);
//	int addRight(int);
//};
//
//Node::Node()
//{
//	left = NULL;
//	right = NULL;
//}
//
//int Node::addLeft(int value)
//{
//	if (!left)
//		return 0;
//	unique_ptr<Node> newNode (new Node);
//	newNode->data = value;
//	left = move(newNode);
//	return 1;
//}
