#include <iostream>
#include <string.h>
#include <stdlib.h>
#include<ctype.h>
#include<stdio.h>
#include<cstdlib>
#include <cmath>
using namespace std;

void PrintCommand(int argc, string argv[]){
    int i;
    if(argc<=2){
        cout <<"Incorrect Number of Arguments";
    }
    else
        {
        for(i=2;i<=argc-1;i++)
            cout << argv[i] << " ";
        }
}
////////////////////////////////////////////////////////////////////////////

void ReverseCommand(int argc, string argv[]){
    int i;
    if(argc<=2){
        cout <<"Incorrect Number of Arguments";
    }
    else {
        for(i=argc-1;i>1;i--)
            cout << argv[i] << " ";
    }
}
////////////////////////////////////////////////////////////////////////////

void UpperCommand(int argc, string argv[]){
    int i,j;
    if(argc<=2){
        cout <<"Incorrect Number of Arguments";
    }
    else{

        for(i=2;i<=argc-1;i++){
            int n=argv[i].length();
            char word[n];
            strcpy(word, argv[i].c_str());
            for (j=0; j<n ; j++){
            putchar(toupper(word[j]));
            }

        cout<<" ";

        }
    }
}
////////////////////////////////////////////////////////////////////////////

void ShuffleWordCommand(int argc, string argv[]){
    if(argc !=3){
      cout <<"Incorrect Number of Arguments";
    }
    else{
        int n=argv[2].length();
        char word[n];
        strcpy(word, argv[2].c_str());
        int i;
        for (i=0 ; i<=n ; i+=2){
            if ((n-1)-i == 0){
                cout<<word[i];
                break;
            }
            else if ((n-1)-i == 1){
                cout<<word[i+1]<<word[i];
                break;
            }
            cout<<word[i+1]<<word[i];
        }
    }
}
////////////////////////////////////////////////////////////////////////////

void ShuffleStatementCommand(int argc, string argv[]){
    if(argc <= 3){
        cout <<"Incorrect Number of Arguments"<<endl;
    }
    else{
        int i;
        for (i=2 ; i<=argc ; i+=2){
            if ((argc-1)-i == 0){
                cout<<argv[i];
                break;
            }
            else if ((argc-1)-i == 1){
                cout<<argv[i+1]<<" "<<argv[i]<<" ";
                break;
            }
            cout<<argv[i+1]<<" "<<argv[i]<<" ";
    }
}
}
////////////////////////////////////////////////////////////////////////////
void DeleteCommand(int argc, string argv[]){
    int i,j;
    if (argc <= 3){
        cout <<"Incorrect Number of Arguments";
        return;
    }
    int n=argv[2].length();
    for(i=0 ; i<n ; i++){
        if (isdigit(argv[2][i]) == 0){
        cout<<"Incorrect Data Type";
        return;
        }
    }

    char word[n];
    strcpy(word, argv[2].c_str());
    int k = atoi(word);

    if ((k > argc-3)||(k == 0)){
        cout <<"Incorrect Number of Arguments";
        return;
    }

    for(i=3 ; i<=argc-1 ; i++){

        if (i == k+2){
            continue;
        }

        for(j=0 ; j<argv[i].length() ; j++){
            cout<<argv[i][j];
        }
        cout<<" ";
    }
}
////////////////////////////////////////////////////////////////////////////
void MiddleCommand(int argc, string argv[]){
    if (argc <= 2){
        cout <<"Incorrect Number of Arguments";
    }
    else{
        if((argc-2) % 2 == 0){
            cout<<argv[1+(argc-2)/2]<<" "<<argv[1+1+(argc-2)/2];
        }
        else{
            int z = round((argc-2)/2);
            cout<<argv[1+z];
        }
    }
}
////////////////////////////////////////////////////////////////////////////
void AddCommand(int argc, string argv[]){
    if(argc <=2){
    cout <<"Incorrect Number of Arguments";
    }
    else{
    int i,j;
    int k = 0;
    for(i=2 ; i<argc ; i++){
        int n=argv[i].length();
        for(j=0 ; j<n ; j++){
            if (isdigit(argv[i][j]) == 0){
                cout<<"Incorrect Data Type";
                return;}
        }
    char word[n];
    strcpy(word, argv[i].c_str());
    k += atoi(word);
    }
    cout<<k;
}
}
////////////////////////////////////////////////////////////////////////////
void RandomCommand(int argc, string argv[]){
    if(argc!=6){
        cout <<"Incorrect Number of Arguments";
        }
    else{
        int i, j;
        int arr[4];
        for(i=2 ; i<argc ; i++){
        int n=argv[i].length();
            for(j=0 ; j<n ; j++){
                if (isdigit(argv[i][j]) == 0){
                    cout<<"Incorrect Data Type";
                return;}
        }
    char word[n];
    strcpy(word, argv[i].c_str());
    arr[i-2] = stoi(word);
    }
    if (arr[2]<= arr[1]){
        cout <<"Incorrect Number of Arguments";
        return;
    }
    srand(arr[3]);
    for(i=0 ; i<arr[0] ; i++){
        cout<<rand()%( arr[2] - arr[1] +1) + arr[1]<<" ";
    }
  }
}
////////////////////////////////////////////////////////////////////////////




int main(int argc, char *argv[])
{
    int i;
    string str[argc];
    for (i=0 ; i<argc ; i++){
        string z = argv[i];
        str[i]=z;
        }

    if (strcmp(argv[1] ,"print" )== 0)
    {
        PrintCommand(argc,str);
    }
////////////////////////////////
    else if (strcmp(argv[1] ,"reverse" )== 0)
    {
         ReverseCommand(argc,str);
    }
////////////////////////////////
    else if(strcmp(argv[1] ,"upper" )== 0)
    {
       UpperCommand(argc,str);
    }
////////////////////////////////
    else if (strcmp(argv[1] ,"shuffle" )== 0)
    {
        ShuffleWordCommand(argc,str);
    }
////////////////////////////////
    else if (strcmp(argv[1] ,"shuffleStatement" )== 0)
    {
    ShuffleStatementCommand(argc,str);
    }
////////////////////////////////
    else if(strcmp(argv[1] ,"delete" )== 0)
    {
        DeleteCommand(argc,str);
    }
////////////////////////////////
    else if (strcmp(argv[1] ,"middle" )== 0)
    {
        MiddleCommand(argc,str);
    }
////////////////////////////////
    else if(strcmp(argv[1] ,"add" )== 0)
    {
       AddCommand(argc,str);
    }
////////////////////////////////
   else if (strcmp(argv[1] ,"random" )== 0)
    {
       RandomCommand(argc,str);
    }
////////////////////////////////
   else{
    cout <<"Undefined Command";
    }

    return 0;
}

