/*
 * Dishes.hpp
 *
 *  Created on: Dec 4, 2016
 *      Author: thomashuber
 */

#ifndef DISH_HPP_
#define DISH_HPP_

#include "NodeTB.hpp"
#include "BSTB.hpp"

#include <iostream>
#include <stdlib.h>
#include <string>


class Dish{
	BSTB *dishList;
	string ingredients[3] = new string; // string of ingredients to be sorted
	void Dish(string name, string ing1, string ing2, string ing3);
	string name;

public:
	Dish();
	void merge(int low, int mid, int high);
	void mergeSort(int low, int high);

};

void Dish::Dish(string Name, string ing1, string ing2, string ing3) {

}

#endif /* DISH_HPP_ */
