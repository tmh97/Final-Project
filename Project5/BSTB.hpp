/*
 * BTSB.hpp
 *
 *  Created on: Dec 4, 2016
 *      Author: thomashuber
 */

#ifndef BSTB_HPP_
#define BSTB_HPP_

#include <iostream>
#include "NodeTB.hpp"

class BSTB{
	NodeTB *root;
	int count;

public:
	BSTB();
	~BSTB();
	void deleteTree(NodeTB *tmp);
	bool insert(string x);
	void printTreeio();
	void printTreeio(NodeTB *n);
	void printTreePre();
	void printTreePre(NodeTB *n);
	void printTreePost();
	void printTreePost(NodeTB *n);
	bool search(string x);
	bool search(NodeTB *n, string x);
	void adjustBalances(NodeTB *n);
	NodeTB *rotateRight(NodeTB *n);
	NodeTB *rotateLeft(NodeTB *n);
};



#endif /* BSTB_HPP_ */
