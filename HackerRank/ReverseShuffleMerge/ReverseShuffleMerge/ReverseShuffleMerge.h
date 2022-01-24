/**
 * @file ReverseShuffleMerge.h
 * @author Dogukan Fikri Arat
 * @brief 
 * @version 0.1
 * @date 2022-01-19
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#ifndef INCLUDED_REVERSESHUFFLEMERGE_H
#define INCLUDED_REVERSESHUFFLEMERGE_H

#include <string>
#include <iostream>
#include <vector>
#include <ctype.h>
#include <algorithm>

namespace HackerRank
{
    using namespace std;

    /**
     * @brief The BigExponential class
     * 
     */
    class ReverseShuffleMerge
    {
    public:
        /**
         * @brief Construct a new object
         * 
         */
        ReverseShuffleMerge() = default;

        /**
         * @brief Destroy the object
         * 
         */
        virtual ~ReverseShuffleMerge() = default;

        vector<string> shuffle(string);

        string reverse(string);

        vector<string> merge(string, string);

        vector<string> combine(string, int);

        bool isLexicographicallySmall(string);

        string getLexicographicallySmallest(vector<string>);

        vector<string> mergeListWithString(vector<string>, string);

        string reverseShuffleMerge(string);

    };
}

#endif // INCLUDED_REVERSESHUFFLEMERGE_H