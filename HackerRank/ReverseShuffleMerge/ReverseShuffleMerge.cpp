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
    unordered_set<string> resultSet;
    vector<string> result;

    do
    {
        resultSet.insert(s);

    } while(next_permutation(s.begin(), s.end()));

    result.assign(resultSet.begin(), resultSet.end());
    
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
    unordered_set<string> resultSet;
    vector<string> result;
    
    for(string each : temp)
    {
        resultSet.insert(each.substr(0, n));
    }

    result.assign(resultSet.begin(), resultSet.end());
    
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
    unordered_set<string> lastStageSet;
    vector<string> lastStageVector;
    unordered_set<string> tempStage;

    {
        vector<string> subStringRaw = combine(inputStr, inputStr.size() / 2);

        for(string each : subStringRaw)
        {
            if(isLexicographicallySmall(each))
            {
                tempStage.insert(each);
            }
        }
    }


    for(string one : tempStage)
    {
        unordered_set<string> tempSet;

        {
            vector<string> tempVector = mergeListWithString(shuffle(one), reverse(one));

            tempSet.insert(begin(tempVector), end(tempVector));
        }
        
        for(string oneTemp : tempSet)
        {
            size_t found = oneTemp.find(one);

            if(found!=string::npos)
            {
                lastStageSet.insert(one);
            }
        }
        
    }

    lastStageVector.assign(begin(lastStageSet), end(lastStageSet));

    result = getLexicographicallySmallest(lastStageVector);
    
    return result;
}