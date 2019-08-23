/******************************************************************************
*  * Copyright (C) 2017 by Alex Fosdick - University of Colorado
*   *
*    * Redistribution, modification or use of this software in source or binary
*     * forms is permitted as long as the files maintain this copyright. Users are 
*      * permitted to modify this and use it to learn about the field of embedded
*       * software. Alex Fosdick and the University of Colorado are not liable for any
*        * misuse of this material. 
*         *
*          *****************************************************************************/
/**
*  * @file <stats.c> 
*   * @brief <This program takes an array of numbers, and calculates some statistics>  
*    *
*     * <Given an array of unsigned char data items, this program takes the array, sort it from maximum to minimum number, 
* 	    * then calculates the mean, median, maximum and minimum
*       *  values of the array.>
*        * @author <Jose Arguello>
	*         * @date <08/16/2019>
*          *
*           */

#include <stdio.h>
#include "stats.h"
/* Size of the Data Set */
#define SIZE (40)

int main(void){

	unsigned char a[SIZE] = {34, 201, 190, 154, 8, 194, 2, 6,
		114, 88, 45, 76, 123, 87, 25, 23,
		200, 122, 150, 90, 92, 87, 177, 244,
		201, 6, 12, 60, 8, 2, 5, 67,
		7, 87, 250, 230, 99, 3, 100, 90};


    /* Other Variable Declarations Go Here */
		int median = 0, maximum = 0, minimum = 0, mean = 0;

    /* Statistics and Printing Functions Go Here */

		printf("\n*Here are the elements of the test array: \n\n");
		print_array(a, SIZE);

		printf("\n\n*The Sorted array from maximum to minimum: \n");
		sort_array(a, SIZE);

		median = find_median(a, SIZE);

		maximum = find_maximum(a, SIZE);
		minimum = find_minimum(a, SIZE);
		mean = find_mean(a, SIZE);

		print_statistics(median, maximum, minimum, mean);
	}

/* Add other Implementation File Code Here */
	void print_statistics(int s1, int s2, int s3, int s4){
		printf("\n\n*Here are all the statistics\n");
		printf("Median: %d\n",s1);
		printf("Maximum: %d\n",s2);
		printf("Minimum: %d\n",s3);
		printf("Mean: %d\n",s4);
	}


	void print_array(unsigned char array[], int length){

		for(int i = 0; i < length; i++){

			printf("%d ",array[i]);

		}
	}

	void sort_array(unsigned char array[], int length){
// Declare some local variables
		int i = 0, j = 0, temp = 0;

		for(i = 0; i < length; i++){

			for(j = 0; j < length - 1; j++){
				if(array[j] < array[j+1]){
					temp = array[j];
					array[j] = array[j+1];
					array[j+1] = temp;
				}
			}
		}

		for(i = 0; i < length; i++){
			printf("\na[%d] : %d",i, array[i]);
		}

		printf("\n");
	}

	int find_median(unsigned char array[], int length){
	// this function will be used once the array is already sorted.
		int median = 0;
	//The number of elements is even, the formula for a median for an even
	// number of elements is: 
		median = (array[(length-1)/2] + array[length/2])/2.0;
		return median;

	}

	int find_maximum(unsigned char array[], int length){

		int i, maximum = array[0];

		for(i = 1; i < length; i++){

			if(array[i] > maximum){
				maximum = array[i];
			}
		}

		return maximum; 
	}

	int find_minimum(unsigned char array[], int length){
		int i, minimum = array[0];

		for(i = 1; i < length; i++){
			if(array[i] < minimum){
				minimum = array[i];
			}
		}

		return minimum; 
	}

	int find_mean(unsigned char array[], int length){
		int i = 0, summ = 0, mean = 0;
		for(i = 0; i < length; i++){
			summ += array[i];
		}

		mean = summ/length;

		return mean;
	}
