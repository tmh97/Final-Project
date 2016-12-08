/*
 * NodeTB.hpp
 *
 *  Created on: Dec 4, 2016
 *      Author: thomashuber
 */

#ifndef NODETB_HPP_
#define NODETB_HPP_

#include <iostream>
using namespace std;

class NodeTB{
	friend class BSTB;
	friend class Dish;
	string data;
	NodeTB *left;
	NodeTB *right;
	NodeTB *parent;
	int height;

public:

	NodeTB(string s);
	~NodeTB();
};




#endif /* NODETB_HPP_ */
