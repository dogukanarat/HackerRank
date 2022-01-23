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

    do {

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
    vector<string> result;
    
    if( n == 0)
    {
        // nothing
    }
    else if(n == 1)
    {
        for(int i = 0; i < s.size(); i++)
        {
            result.push_back(&s[i]);
        }
    }
    else if(n > 0)
    {
        for(int i = 0; i < s.size(); i++)
        {
            const char t = s[i];
            string st = s.erase(i, 1);
            vector<string> temp = combine(st, n - 1);
            for(auto it = temp.begin(); it != temp.end(); it++)
            {
                result.push_back(string(&t) + *it);
            } 
        }
    }
    
    return result;
}

bool ReverseShuffleMerge::isSmall(string s)
{
    bool result = true;
    int diff; 
    
    for(int index = 1; index < s.size(); index++)
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

vector<string> ReverseShuffleMerge::mergeList(string str, vector<string> list)
{
    vector<string> result; 
    
    for(auto eStr : list)
    {
        vector<string> temp = merge(str, eStr);
        result.insert(end(result), begin(temp), end(temp));
    }
    
    return result;
}

string ReverseShuffleMerge::reverseShuffleMerge(string s)
{
    string result;
    vector<string> listSubStr = combine(s, s.size() / 2);
    
    for(string subStr : listSubStr)
    {
        if(isSmall(subStr))
        {
            vector<string> subList = mergeList(reverse(subStr), shuffle(subStr));
            
            for(string sStr : subList)
            {
                if(sStr == subStr)
                {
                    result = subStr;
                }
            }
        }
    }
    
    return result;
}