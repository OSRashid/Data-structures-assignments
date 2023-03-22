#include <iostream>
#include <algorithm>
#include <regex>
#include <cstdlib>
#include <stdlib.h>
#include <string.h>
#include <fstream>
#include "inord_list.h"
#include <sstream>
#include <assert.h>
using namespace std;


int main(int argc , char *argv[])
{

 ////////////// Text Preprocessing /////////////////
    LList *MyList = new LList;
    int charCnt = 0;
    int wordCnt = 0;
    if(argc != 3)
    {
        cout <<"Incorrect number of arguments"<<endl;
         return 0;
    }
    else
     {
        ifstream txtFile;
        txtFile.open (argv[1]);
        if (!txtFile.is_open())
        {
            cout << "File not found";
            return 0 ;
        }



        string Line;

        int lineIndx = 0;
        while (getline(txtFile,Line))
        {
          lineIndx++;
          transform(Line.begin(), Line.end(), Line.begin(), ::tolower);
          replace( Line.begin(), Line.end(), ',', ' ' );
          replace( Line.begin(), Line.end(), ';', ' ' );
          replace( Line.begin(), Line.end(), ':', ' ' );
          replace( Line.begin(), Line.end(), '"', ' ' );
          replace( Line.begin(), Line.end(), '&', ' ' );
          replace( Line.begin(), Line.end(), '.', ' ' );
          replace( Line.begin(), Line.end(), '[', ' ' );
          replace( Line.begin(), Line.end(), ']', ' ' );
          replace( Line.begin(), Line.end(), '{', ' ' );
          replace( Line.begin(), Line.end(), '}', ' ' );
          replace( Line.begin(), Line.end(), '(', ' ' );
          replace( Line.begin(), Line.end(), ')', ' ' );
          replace( Line.begin(), Line.end(), '?', ' ' );
          replace( Line.begin(), Line.end(), '!', ' ' );
          replace( Line.begin(), Line.end(), '`', ' ' );
          replace( Line.begin(), Line.end(), '\'' , ' ' );

          charCnt +=  Line.length();

          string word;

          stringstream token(Line);

          while (token >> word){
            wordCnt++;
            MyList->addNode(word,lineIndx);
          }

        }
    	charCnt += lineIndx;
        txtFile.close();
    }

////////////////////////////////////////////////////////////////////////////////

///////////////////////////// Reading Command //////////////////////////////////
    ifstream instFile;
    instFile.open (argv[2]);
    if (!instFile.is_open())
        {
          cout << "File not found";
          return 0;
        }


        int instCnt = 0;
        string tmpLine;
        string insWord;
        string instruction;
        string instructionARG;

    while (getline(instFile, tmpLine)){

        stringstream insToken(tmpLine);
        while (insToken >> insWord )
        {
            instCnt++;
            if (instCnt == 1){
                instruction = insWord;
            }
            if (instCnt == 2){
                instructionARG = insWord;
                transform(instructionARG.begin(), instructionARG.end(), instructionARG.begin(), ::tolower);

            }
            if (instCnt == 3){
                cout << "Incorrect number of arguments"<<endl;
                instCnt = 0;
                goto END;

            }

        }

///////////////////  wordCount  //////////////////
    if (instruction.compare("wordCount")==0)
    {
        if (instCnt != 1){
            cout << "Incorrect number of arguments"<<endl;
            goto END;
            }
        cout<<wordCnt<<" "<<"words"<<endl;
    }
//////////////////  distWords  //////////////////
    else if (instruction.compare("distWords")==0)
     {
        if (instCnt != 1){
            cout << "Incorrect number of arguments"<<endl;
            goto END;
            }
        MyList->distinct(wordCnt);
     }
//////////////////  charCount  //////////////////
    else if (instruction.compare("charCount")==0)
     {
        if (instCnt != 1){
            cout << "Incorrect number of arguments"<<endl;
            goto END;
            }
        cout<<charCnt<<" "<<"characters"<<endl;
     }
 //////////////////  frequentWord  //////////////////
    else if (instruction.compare("frequentWord")==0)
     {
        if (instCnt != 1){
            cout << "Incorrect number of arguments"<<endl;
            goto END;
            }
        MyList->mostFreq(wordCnt);
     }
//////////////////  countWord  //////////////////
    else if (instruction.compare("countWord")==0)
     {
        if (instCnt != 2){
            cout << "Incorrect number of arguments"<<endl;
            goto END;
            }
        MyList->CntWord(instructionARG);
     }
//////////////////  starting //////////////////
    else if (instruction.compare("starting")==0)
     {
        if (instCnt != 2){
            cout << "Incorrect number of arguments"<<endl;
            goto END;
            }
        MyList->starting(instructionARG);
     }
//////////////////  containing  //////////////////
    else if (instruction.compare("containing")==0)
     {
        if (instCnt != 2){
            cout << "Incorrect number of arguments"<<endl;
            goto END;
            }
        MyList->containing(instructionARG);
     }
//////////////////  search  //////////////////
    else if (instruction.compare("search")==0)
     {
        if (instCnt != 2){
            cout << "Incorrect number of arguments"<<endl;
            goto END;
            }
        MyList->Search(instructionARG);

     }
//////////////////  undefiend command  //////////////////
     else
      cout <<"Undefined command"<<endl;
///////////////// closing the instruction file //////////

    END:;

    instruction.clear();
    instructionARG.clear();
    instCnt = 0;

    }


    instFile.close();

    delete MyList;

    return 0;

  }

