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
#include <string>


class Dish{
	BSTB *dishList;
	string ingredients[]; // string of ingredients to be sorted
	string name;

public:
	void merge(int low, int mid, int high);
	void mergeSort(int low, int high);
	void Dish(string name, string ing1, string ing2, string ing3);
};

void Dish(string Name, string ing1, string ing2, string ing3) {
	name = Name;
	ingredients[] = [ing1, ing2, ing3];

}

#endif /* DISH_HPP_ */
