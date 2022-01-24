/**
 * @file ReverseShuffleMerge.cpp
 * @author Dogukan Fikri Arat
 * @brief 
 * @version 0.1
 * @date 2022-01-22
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include "ReverseShuffleMerge/ReverseShuffleMerge.h"

using namespace HackerRank;
using namespace std;

vector<string> ReverseShuffleMerge::shuffle(string s)
{
    vector<string> result;

    do
    {
        result.push_back(s);

    } while(next_permutation(s.begin(), s.end()));
    
    return result;
}

string ReverseShuffleMerge::reverse(string s)
{
    string result = s;

    std::reverse(result.begin(), result.end());

    return result;
}

vector<string> ReverseShuffleMerge::merge(string s1, string s2)
{
    return shuffle(s1 + s2);
}

vector<string> ReverseShuffleMerge::combine(string s, int n)
{
    vector<string> temp = shuffle(s);
    vector<string> result;
    
    for(string each : temp)
    {
        result.push_back(each.substr(0, n));
    }
    
    return result;
}

bool ReverseShuffleMerge::isLexicographicallySmall(string s)
{
    bool result = true;
    int diff; 
    
    for(size_t index = 1; index < s.size(); index++)
    {
        diff = s[index] - s[index-1];
        if(diff < 0)
        {
            result = false;
            break;
        }
    }

    return result;
}

string ReverseShuffleMerge::getLexicographicallySmallest(vector<string> stringVector)
{
    string currentSmallestString = stringVector[0];
    
    for(string one : stringVector)
    {
        if(isLexicographicallySmall(one))
        {
            if( one < currentSmallestString)
            {
                currentSmallestString = one;
            }
        }
    }
    
    return currentSmallestString;
}

vector<string> ReverseShuffleMerge::mergeListWithString(vector<string> stringVector, string str)
{
    vector<string> result; 
    
    for(auto one : stringVector)
    {
        vector<string> temp = merge(str, one);
        result.insert(end(result), begin(temp), end(temp));
    }
    
    return result;
}

string ReverseShuffleMerge::reverseShuffleMerge(string inputStr)
{
    string result;
    vector<string> lastStage;
    vector<string> subStringRaw = combine(inputStr, inputStr.size() / 2);
    vector<string> tempStage;

    for(string each : subStringRaw)
    {
        if(isLexicographicallySmall(each))
        {
            tempStage.push_back(each);
        }
    }

    for(string one : tempStage)
    {
        vector<string> temp = mergeListWithString(shuffle(one), reverse(one));
        
        for(string oneTemp : temp)
        {
            size_t found = oneTemp.find(one);

            if(found!=string::npos)
            {
                lastStage.push_back(one);
            }
        }
        
    }

    result = getLexicographicallySmallest(lastStage);
    
    return result;
}