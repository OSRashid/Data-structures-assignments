#ifndef INORD_LIST_H_INCLUDED
#define INORD_LIST_H_INCLUDED

#include <iostream>
#include <regex>
#include <algorithm>
#include <cstdlib>
#include <stdlib.h>
#include <string.h>
#include <fstream>
#include<sstream>
#include <assert.h>
using namespace std;

class LList{

    public:

    string word;
    int line;
    LList *first;
    LList *next;
    LList *last;
    LList *current;

    LList(){
    first = this;
    current = this;
    last = this;
    next = NULL;
    }

    ~LList(){
    	if (next != NULL){
    		delete next;
    	}
    }

    void addNode(string word , int line );
    void CntWord(string arg);
    void starting (string arg);
    void distinct (int nOfWords);
    void mostFreq(int nOfWords);
    void containing(string arg);
    void Search(string arg);

};



#endif // INORD_LIST_H_INCLUDED


