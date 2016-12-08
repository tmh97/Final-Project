/*
 * NodeTB.cpp
 *
 *  Created on: Dec 4, 2016
 *      Author: thomashuber
 */

#include "NodeTB.hpp"
#include <iostream>
#include <stdlib.h>
#include <string>

using namespace std;

NodeTB::NodeTB(string s){
	left = NULL;
	right = NULL;
	parent = NULL;
	height = 0;
	data = s;
}

NodeTB::~NodeTB(){
	if(left != NULL || right != NULL){
		cout << "deletion of this Node could cause a memory leak" << endl;
	}
}


