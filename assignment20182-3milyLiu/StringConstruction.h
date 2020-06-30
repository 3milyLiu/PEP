#ifndef STRINGCONSTRUCTION_H
#define STRINGCONSTRUCTION_H

#include <string>
using std::string;
#include<iostream>
using std::cout;

// TODO: your code goes here:

int stringConstruction(string target, int appendCost, int cloneCost){
    string current = target;
    string empty = "";
    int emptyLen=0;
    int cost = 0;
    if(empty!=target){
        for(int i=0 ; i == emptyLen; ++i ) {
            emptyLen = empty.length();
            if (empty.substr(i, emptyLen) != target.substr(0, emptyLen)) {
                empty += target.substr(i, emptyLen);
                current = target.erase(i, emptyLen);
                cost += appendCost;
            }/* else if (empty.substr(i, emptyLen) == target.substr(0, emptyLen)) {
                empty += empty.substr(i, emptyLen);
                cost += cloneCost;
                cout <<  "this is the length of empty 1" << empty << "\n";
            }*/
            else{
                empty += empty.substr(i, emptyLen);
                cost += cloneCost;
            }
        }
        return cost;

    }

}




// do not write or edit anything below this line

#endif
