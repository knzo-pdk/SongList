#pragma once
#include<string>

using namespace std;

struct Node
{
	void* data_;
	Node* next_;
	Node* prev_;
	Node()
	{
		data_ = 0;
		prev_ = 0;
		next_ = 0;
	}
};


class LinkedList
{
private:
	Node* first_;
	Node* last_;
	Node* curNode_;
	long listLen_;
public:
	LinkedList();
	~LinkedList();
	void AddLinkToBack(void* ptr);
	void* RemoveThisLink(Node* node);
	void* RemoveLinkFromFront();
	void* GetFirstNode();
	
	void* RemoveALink();
	void* FindANode(void* mp3Ptr);
	void* GetNextNode();
	long GetListLength();
};
