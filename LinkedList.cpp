#include "LinkedList.h"
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>

using namespace std;



LinkedList::LinkedList() {}
LinkedList::~LinkedList() {}

void LinkedList::AddLinkToBack(void* ptr) {

	
	Node* NodePtr = new Node();
	void *datahold;
	Node *temporary;

	if (listLen_ >= 2)
	{
		Node* oldLastNode = last_;
		last_->next_ = NodePtr;  //add to back of the last .
		last_ = NodePtr;		 // new last must changed after adding. 
		last_->data_ = ptr;		 // store pointer of Shell .
		NodePtr->prev_ = oldLastNode;
	}

	else if (listLen_ == 1)
	{
		last_->next_ = NodePtr;  //add to back of the last .
		last_ = NodePtr;         // new last must changed after adding.
		first_->next_ = last_;   // next_ of first_ now should point to valid node
		last_->data_ = ptr;      // store pointer of Shell .
		NodePtr->prev_ = first_;
	}

	else if (listLen_ == 0)
	{
		last_ = NodePtr;		// new last after added . 
		first_ = last_;			// because only one node in list 
		last_->data_ = ptr;		// store pointer of Shell .
		first_->prev_ = NULL;
		
	}

	listLen_++;
	return;
}


void* LinkedList::RemoveThisLink(Node* node) {

	void *datahold;
	Node *temporary;
	datahold = first_->data_;

	temporary = node;

	if (node != first_ && node != last_) {

		(node->next_)->prev_ = node->prev_;
		(node->prev_)->next_ = node->next_;

	}
	else if (node == first_) 
	{
		first_ = node->next_;
		first_->prev_ = NULL;
	}
	else if (node == last_)
	{
		last_ = node->prev_;
		last_->next_ = NULL;
	}
	listLen_--;
	delete node;
	return datahold;

}

void* LinkedList::RemoveALink() {
	void *datahold;
	Node *temp;
	if (curNode_ == NULL) {
		temp = last_;
		if (last_ != first_) {
			(temp->prev_)->next_ = NULL;
			last_ = last_->prev_;
		}
	}
	else if (curNode_->prev_ == first_) {
		temp = first_;
		first_ = curNode_;
		curNode_->prev_ = NULL;
	}
	else {
		temp = curNode_->prev_;
		curNode_->prev_ = temp->prev_;
		(temp->prev_)->next_ = curNode_;
	}
	datahold = temp->data_;
	delete temp;
	listLen_--;
	return datahold;
}


void* LinkedList::RemoveLinkFromFront() {

	void *datahold;              //Temporary hold Shell data
	Node *temporary;               // temporary hold first node
	if (first_ == NULL || listLen_ == 0) { return NULL; }
	temporary = first_;            // place holder for first_ to move on along with curNode_  
								 
	datahold = first_->data_;        // give data for first_ to be free to move on

	first_ = first_->next_;         // first_ node moving on

	delete temporary;
	listLen_ = listLen_ - 1; 
	return datahold;
}

void* LinkedList::GetFirstNode() {
	
	if (first_ == last_)
	{
		curNode_ = NULL;
	}
	else
	curNode_ = first_->next_;

	return first_->data_;
}



void* LinkedList::GetNextNode() {
	
	if (curNode_ == NULL) 
	{
		return NULL;
	}
	else 
	{
		Node* tempholder;
		tempholder = curNode_;
		curNode_ = curNode_->next_;

		return tempholder->data_;
	}
}

long LinkedList::GetListLength() {
	
	return listLen_;
}



void* LinkedList::FindANode(void* mp3Ptr) {
	void* datahold;
	Node* temporary;

	if (first_ == NULL) return NULL;
	temporary = first_;
	datahold = first_->data_;
	while (temporary->next_ != 0)
	{
		if (strcmp((char*)datahold, (char*)mp3Ptr) == 0) { return datahold; }
		datahold = temporary->data_;
	}
	return NULL;
}