/*
 * Dishes.cpp
 *
 *  Created on: Dec 4, 2016
 *      Author: thomashuber
 */

#include "NodeTB.hpp"
#include "BSTB.hpp"
#include "Dish.hpp"
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

Dish::Dish(){
	string ingredients[] = {'food','foody','foodies'};
}

void Dish::mergeSort(int low, int high){


	int mid = 0;
	if(low < high){
		mid = ((low+high)/2);
		mergeSort(low, mid);
		mergeSort(mid+1, high);
		merge(low,mid,high);
	}
}
void Dish::merge(int low, int mid, int high){
	    int i = low, j = mid+1 , k = low;
	    string Temp[5];

	    while(i <= mid && j <= high) {
	        if( ingredients[i] < ingredients[j] ){
	            Temp[k].assign(ingredients[i]);
	            i++;
	        }
	        else{
	            Temp[k].assign(ingredients[j]);
	            j++;
	        }
	        k++;
	    }
	    if(i > mid ){

	        for(int h = j ;h <= high ; h++ ){

	            Temp[k].assign(ingredients[h]);
	            k++;
	        }
	    }
	    else
	        for(int h = i; h<= mid ; h++ ){
	            Temp[k].assign(ingredients[h]);
	            k++;
	        }

	   for(int i = 0; i <= high ; i++){
	       ingredients[i].assign(Temp[i]);
	   }
	}




