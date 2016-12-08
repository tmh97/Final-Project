/*
 * Dishes.hpp
 *
 *  Created on: Dec 4, 2016
 *      Author: thomashuber
 */

#ifndef DISH_HPP_
#define DISH_HPP_

#include <iostream>
#include "NodeTB.hpp"
#include "BSTB.hpp"

class Dish{
	BSTB *dishList;
	string ingredients[]; // string of ingredients to be sorted

public:
	void merge(int low, int mid, int high);
	void mergeSort(int low, int high);
};



#endif /* DISH_HPP_ */
