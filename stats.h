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

#ifndef __STATS_H__
#define __STATS_H__

void print_statistics();

	/**
 *  * @brief <This function takes an array of numbers and print all the estatistics
 *   * which are the median, mean, maximum and minimum on screen>
 *    *
 *     * <Given an array and the number of elements in it, this function prints the 
 *      * mean, median, maximum and minimum values of the array of numbers.>
 *       *
 *        * @param <array> <The array>
 *         * @param <n> <number of elements of the array>
 *          *
 *           * @return <All the statistics of the array printed on screen.>
 *            */

void print_array(unsigned char array[], int length);

/**
 *  * @brief <This function takes an array of numbers and print it on screen>
 *   *
 *    * <Given an array and the number of elements in it, this function prints all
 *	   *  the elements on screen using printf.>
 *      *
 *       * @param <array> <The array>
 *        * @param <n> <number of elements of the array>
 *         *
 *          * @return <All the elements of the array printed on screen>
 *           */

int find_median(unsigned char array[], int length);

/**
 *  * @brief <Finds the median of an array>
 *   *
 *    * <Given an array, this function calculates the median of the array.>
 *     *
 *      * @param <array> <The array>
 *       * @param <n> <number of elements of the array>
 *        *
 *         * @return <The median of the array.>
 *          */

int find_mean(unsigned char array[], int length);

/**
 *  * @brief <Finds the mean of an array>
 *   *
 *    * <Given an array, this function calculates the mean of the array.>
 *     *
 *      * @param <array> <The array>
 *       * @param <n> <number of elements of the array>
 *        *
 *         * @return <The mean of the array.>
 *          */

int find_maximum(unsigned char array[], int lentgh);

/**
 *  * @brief <Finds the maximum number of an array>
 *   *
 *    * <Given an array, this function calculates the maximum number of the array.>
 *     *
 *      * @param <array> <The array>
 *       * @param <n> <number of elements of the array>
 *        *
 *         * @return <The maximum number of the array.>
 *          */

int find_minimum(unsigned char array[], int lentgh);

/**
 *  * @brief <Finds the minimum number of an array>
 *   *
 *    * <Given an array, this function calculates the minimum number of the array.>
 *     *
 *      * @param <array> <The array>
 *       * @param <n> <number of elements of the array>
 *        *
 *         * @return <The minimum number of the array.>
 *          */

void sort_array(unsigned char array[], int length);

/**
 *  * @brief <This function takes an array of numbers and  sort from the maximum to the minimum
 *   * and print it on screen.>
 *    *
 *     * <Given an array and the number of elements in it, this function sorts from 
 *      * the greatest value to the smallest of the array and prints the array on screen.>
 *	     *  the elements on screen using printf.>
 *        *
 *         * @param <array> <The array>
 *          * @param <n> <number of elements of the array>
 *           *
 *            * @return <All the elements of the array sorted from maximum to minimum
 *             * and printed on screen>
 *              */

#endif /* __STATS_H__ */
