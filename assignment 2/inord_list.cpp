#include <iostream>
#include <cstdlib>
#include<stdlib.h>
#include <string.h>
#include <fstream>
#include "inord_list.h"
#include<sstream>
#include <assert.h>
using namespace std;



void LList::Search(string arg){

    int found = 0;
    string finOP;
    int strCMP;
    LList *curr = current;
    if (curr->next == NULL){
        cout<<"Word not found"<<endl;
        return;
    }
    while(curr->next != NULL) {
        curr = curr->next;
        strCMP = (curr->word).find(arg);
        if (strCMP != -1){
            found ++;
            finOP.append(curr->word);
            finOP.append(" ");
    }
    }

    if (found == 0){
        cout<<"Word not found"<<endl;
        return;
    }

    int i=0;
    string words[found];
    string word;
    stringstream tokens(finOP);
    while (tokens >> word){
           words[i]= word;
           i++;
    }


    finOP.clear();

    sort(words,words + found);

    int line = 0;
    for (i = 0 ; i < found ; i++){
        if (words[i] == words[i+1])
            continue;
        else{
            curr = current;
            finOP.append(words[i]);
            finOP.append(":");
            finOP.append("	");
            finOP.append("lines");
            while(curr->next != NULL) {
            curr = curr->next;
            if (words[i].compare(curr->word) == 0){
            	if (curr->line == line)
            		continue;
            	else{
                finOP.append(" ");
                finOP.append(to_string(curr->line));
                line = curr->line;
            	}
              }
            }
            if (i<found-1)
            	finOP.append("\n");
            }

        line = 0;
    }
    cout << finOP <<endl;
}


void LList::containing(string arg){
    int found = 0;
    string finOP;
    int strCMP;
    LList *curr = current;
    if (curr->next == NULL){
        cout<<"Word not found"<<endl;
        return;
    }
    while(curr->next != NULL) {
        curr = curr->next;
    	strCMP = (curr->word).find(arg);
        if (strCMP != -1){
            found ++;
            finOP.append(curr->word);
            finOP.append(" ");
    }
    }

    if (found == 0){
        cout<<"Word not found"<<endl;
        return;
    }

    int i=0;
    string words[found];
    string word;
    stringstream tokens(finOP);
    while (tokens >> word){
           words[i]= word;
           i++;
    }


    finOP.clear();

    sort(words,words + found);

    int score = 1;
    for (i = 0 ; i < found ; i++){
        if (words[i] == words[i+1])
            score ++;
        else{
            finOP.append(words[i]);
            finOP.append(":");
            finOP.append(" ");
            finOP.append(to_string(score));
            score = 1;
            if (i < found-1)
                finOP.append("	");
        }

    }
    cout << finOP <<endl;
}

void LList::starting(string arg){

    int found = 0;
    string finOP;
    string strCMP;
    LList *curr = current;
    if (curr->next == NULL){
        cout<<"Word not found"<<endl;
        return;
    }
    while(curr->next != NULL) {
        curr = curr->next;
    	strCMP = (curr->word);
        if (strCMP.compare(0, arg.length(), arg) == 0){
            found ++;
            finOP.append(curr->word);
            finOP.append(" ");
    }
    }

    if (found == 0){
        cout<<"Word not found"<<endl;
        return;
    }

    int i=0;
    string words[found];
    string word;
    stringstream tokens(finOP);
    while (tokens >> word){
           words[i]= word;
           i++;
    }


    finOP.clear();

    sort(words,words + found);

    int score = 1;
    for (i = 0 ; i < found ; i++){
        if (words[i] == words[i+1])
            score ++;
        else{
            finOP.append(words[i]);
            finOP.append(":");
            finOP.append(" ");
            finOP.append(to_string(score));
            score = 1;
            if (i < found-1)
                finOP.append("	");
        }

    }
    cout << finOP <<endl;
}

void LList::mostFreq(int nOfWords){

	LList *curr = current;

    if (curr->next == NULL){
    cout<<"Incorrect number of arguments"<<endl;
    return;
    }

    string words[nOfWords];
    for (int i = 0 ; i<nOfWords ; i++){
        curr = curr->next;
        words[i] = curr->word;
    }

    sort(words,words + nOfWords);

    LList *freqTable = new LList ;
	freqTable->line = 0;
    curr = freqTable->current;

    int i;
    int score = 0;
    int maxScore = 0;

    for (i = 0 ; i<nOfWords ; i++){
        if (words[i]==words[i+1] && words[i].compare("a")!=0 && words[i].compare("an")!=0 && words[i].compare("the")!=0 && words[i].compare("in")!=0 && words[i].compare("on")!=0 && words[i].compare("of")!=0 && words[i].compare("and")!=0 && words[i].compare("is")!=0 && words[i].compare("are")!=0){
            score ++;
        }
        else if (score > maxScore && words[i].compare("a")!=0 && words[i].compare("an")!=0 && words[i].compare("the")!=0 && words[i].compare("in")!=0 && words[i].compare("on")!=0 && words[i].compare("of")!=0 && words[i].compare("and")!=0 && words[i].compare("is")!=0 && words[i].compare("are")!=0){
            maxScore = score;
            freqTable->line = score ;
            freqTable->word = words[i];
            score = 0;
            }
        else if (score == maxScore && words[i].compare("a")!=0 && words[i].compare("an")!=0 && words[i].compare("the")!=0 && words[i].compare("in")!=0 && words[i].compare("on")!=0 && words[i].compare("of")!=0 && words[i].compare("and")!=0 && words[i].compare("is")!=0 && words[i].compare("are")!=0){

            while  (curr->next != NULL){
            	curr= curr->next;
            	if (score > curr->line){
            		curr->line = score;
            		curr->word = words[i];
            	    curr = freqTable->current;
            	    goto out;
            	}

            }

            freqTable->addNode(words[i],score);
            curr = freqTable->current;
            out:;
            score = 0;
        }
        else
            score = 0;
      }

    string finOP;
    finOP.append("Most frequent word is: ");
    finOP.append(freqTable->word);

    curr = freqTable;

    do  {
    	curr= curr->next;
    	if (curr->line == freqTable->line){
    		finOP.append(" ");
    		finOP.append(curr->word);
         }

    }while (curr->next != NULL);


    cout << finOP << endl;

    delete freqTable;

}


void LList::distinct (int nOfWords){
    LList *curr = current;

    if (curr->next == NULL){
        cout<<"0"<<" distinct words"<<endl;
    return;
    }

    string words[nOfWords];
    for (int i = 0 ; i<nOfWords ; i++){
        curr = curr->next;
        words[i] = curr->word;

    }
    sort(words,words + nOfWords);
    int j;
    int duplicate = 0;
    for (j = 0 ; j<nOfWords ; j++ ){
        if (words[j]==words[j+1])
            duplicate ++;
    }
    cout<<nOfWords-duplicate<<" distinct words"<<endl;

}



void LList::CntWord(string arg ){

    int numOcc = 0;
    LList *curr = current;

    if (curr->next == NULL){
    cout << arg << " is repeated " << numOcc << " times" << endl;
    }


    while((curr->current)->next != NULL){
    curr = curr->next;
    if ((curr->word).compare(arg)==0){
        numOcc ++ ;
    }

    }

    cout << arg << " is repeated " << numOcc << " times" << endl;
}

void LList::addNode(string neWord , int corrLine ){
    LList *newList = new LList;
    assert(newList != NULL);
    last->next = newList;
    (last->next)->first = first;
    last = newList;
    newList->word = neWord;
    newList->line = corrLine;
    newList->next = NULL;
}






