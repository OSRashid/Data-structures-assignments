#include <iostream>
#include <algorithm>
#include <regex>
#include <cstdlib>
#include <stdlib.h>
#include <string.h>
#include <fstream>
#include <sstream>
#include <assert.h>
#include <iomanip>
using namespace std;

class BST {
    public :
    float date;
    string name;
    string strDate;
    BST* right;
    BST* left;
    ~BST(){
    }

};

BST* insertChild(BST* Child, float newData , string stringDate , string newName){
	if(Child == NULL){
    Child = new BST();
    assert(Child != NULL);
	Child->date = newData;
	Child->strDate = stringDate;
	Child->name = newName;
	Child->left = NULL;
	Child->right = NULL;
	}
	else if(newData <= Child->date){
		Child->left = insertChild(Child->left, newData, stringDate , newName);
	}
	else{
		Child->right = insertChild(Child->right, newData, stringDate , newName);
	}
	return Child;
}

bool check(BST* Child, float data) {
	if(Child == NULL) {
		return false;
	}
	else if(Child->date == data) {
		return true;
	}
	else if(data <= Child->date) {
		return check(Child->left,data);
	}
	else {
		return check(Child->right,data);
	}
}


BST* findChild(BST* Child, float data) {
    if(data < Child->date)
        return findChild(Child->left, data);
    else if(data > Child->date)
        return findChild(Child->right, data);
    else
        return Child;
}


BST* deleteChild(BST* Child, float data) {

    if(Child == NULL) {
        return Child;
    }
    if(data < Child->date)
        Child->left = deleteChild(Child->left,data);
	else if (data > Child->date)
        Child->right = deleteChild(Child->right,data);
	else {

		if(Child->left == NULL && Child->right == NULL) {
			delete Child;
			Child = NULL;
		}
		else if(Child->left == NULL) {
			BST* spare ;
			spare = Child;
			Child = Child->right;
			delete spare;
		}
		else if(Child->right == NULL) {
			BST* spare;
			spare = Child;
			Child = Child->left;
			delete spare;
		}
		else {
			BST* spare;

			spare = Child;
			while(spare->left != NULL)
				spare = spare->left;

			Child->date = spare->date;
			Child->name = spare->name;
			Child->strDate = spare->strDate;
			Child->right = deleteChild(Child->right,spare->date);
		}
	}
	return Child;
}

void traverse(BST* Child) {

    if(Child == NULL){
        return;}

	traverse(Child->left);
	if (Child->name != " "){
		cout<<Child->name << " " << Child->strDate << endl;
	}
	traverse(Child->right);
	if (Child->name == " " && Child->left == NULL && Child->right == NULL){
			cout<<"Empty Planner"<<endl;
			return;
	}
}

void DeleteBST(BST* child){
		if (child == NULL)
			return;
		DeleteBST(child->left);
		DeleteBST(child->right);
		delete child;
	}

void addMeeting(string name, string day, string hour , BST* Tree ){

    bool err = false;
    if (name[0] != '\"' || name.back() != '\"'){
        cout<<"Invalid title"<<endl;
        err = true;
        }
    if (!(day.find_first_not_of( "0123456789" ) == string::npos)){
        cout<<"Invalid day"<<endl;
        err = true;
    }
    else if (stoi(day) < 1 || stoi(day) > 365){
        cout<<"Invalid day"<<endl;
        err = true;
    }
    if (!(hour.find_first_not_of( "0123456789" ) == string::npos)){
        cout<<"Invalid hour"<<endl;
        err = true;
    }
    else if (stoi(hour) < 0 || stoi(hour) > 23){
        cout<<"Invalid hour"<<endl;
        err = true;
    }
    if (err == true)
        return;

    string strDate = day + " " + hour;

    string dayM = string(3 - day.length(), '0') + day;
    string  hourM = string(2 - hour.length(), '0') + hour;

    float storingINT = stof(dayM + "." + hourM);

    if (check(Tree,storingINT )){
        cout<<"Conflict"<<" "<<day<<" "<<hour<<endl;
        return;
    }

    insertChild(Tree, storingINT , strDate, name);
}

void findMeeting(string day, string hour, BST* Tree ){
    bool err = false;
    if (!(day.find_first_not_of( "0123456789" ) == string::npos)){
        cout<<"Invalid day"<<endl;
        err = true;
    }
    else if (stoi(day) < 1 || stoi(day) > 365){
        cout<<"Invalid day"<<endl;
        err = true;
    }
    if (!(hour.find_first_not_of( "0123456789" ) == string::npos)){
        cout<<"Invalid hour"<<endl;
        err = true;
    }
    else if (stoi(hour) < 0 || stoi(hour) > 23){
        cout<<"Invalid hour"<<endl;
        err = true;
    }
    if (err == true)
        return;

    string strDate = day + " " + hour;

    string dayM = string(3 - day.length(), '0') + day;
    string  hourM = string(2 - hour.length(), '0') + hour;

    float storingINT = stof(dayM + "." + hourM);


    if (check(Tree,storingINT )){
        BST* found = findChild(Tree, storingINT);
        cout<<found->name<<endl;
    }
    else{
        cout<<"Empty"<<" "<<day<<" "<<hour<<endl;
        return;
    }

}

void deleteMeating(string day, string hour, BST* Tree ){
    bool err = false;
    if (!(day.find_first_not_of( "0123456789" ) == string::npos)){
        cout<<"Invalid day"<<endl;
        err = true;
    }
    else if (stoi(day) < 1 || stoi(day) > 365){
        cout<<"Invalid day"<<endl;
        err = true;
    }
    if (!(hour.find_first_not_of( "0123456789" ) == string::npos)){
        cout<<"Invalid hour"<<endl;
        err = true;
    }
    else if (stoi(hour) < 0 || stoi(hour) > 23){
        cout<<"Invalid hour"<<endl;
        err = true;
    }
    if (err == true)
        return;

    string strDate = day + " " + hour;

    string dayM = string(3 - day.length(), '0') + day;
    string  hourM = string(2 - hour.length(), '0') + hour;

    float storingINT = stof(dayM + "." + hourM);


    if (check(Tree,storingINT )){
        deleteChild(Tree, storingINT);
    }
    else{
        cout<<"Empty"<<" "<<day<<" "<<hour<<endl;
        return;
    }

}

void modifyMeeting(string nameED, string day, string hour , BST* Tree){
    bool err = false;
    if (nameED[0] != '\"' || nameED.back() != '\"'){
        cout<<"Invalid title"<<endl;
        err = true;
        }
    if (!(day.find_first_not_of( "0123456789" ) == string::npos)){
        cout<<"Invalid day"<<endl;
        err = true;
    }
    else if (stoi(day) < 1 || stoi(day) > 365){
        cout<<"Invalid day"<<endl;
        err = true;
    }
    if (!(hour.find_first_not_of( "0123456789" ) == string::npos)){
        cout<<"Invalid hour"<<endl;
        err = true;
    }
    else if (stoi(hour) < 0 || stoi(hour) > 23){
        cout<<"Invalid hour"<<endl;
        err = true;
    }
    if (err == true)
        return;

    string strDate = day + " " + hour;

    string dayM = string(3 - day.length(), '0') + day;
    string  hourM = string(2 - hour.length(), '0') + hour;

    float storingINT = stof(dayM + "." + hourM);


    if (check(Tree,storingINT )){
        BST* found = findChild(Tree, storingINT);
        found->name = nameED;
    }
    else{
        cout<<"Empty"<<" "<<day<<" "<<hour<<endl;
        return;
    }

}



int main(int argc , char *argv[])
{
    BST* MyTree =  new BST;
    MyTree->date = 0;
    MyTree->name = " ";
    MyTree->right = NULL;
    MyTree->left = NULL;

    ifstream instFile;
    instFile.open (argv[1]);
    if (!instFile.is_open())
        {
          cout << "File not found";
          return 0;
        }

    int InstrCount;
    int i = 0;
    string tmpLine;
    string insWord;

    while (getline(instFile, tmpLine)){
    	if (tmpLine.empty())
    		continue;
        InstrCount = count(tmpLine.cbegin(), tmpLine.cend(), ' ')+1;


    string InsARR[InstrCount];
    stringstream insToken(tmpLine);
    while (insToken >> insWord ){
        InsARR[i] = insWord;
        i++;
    }
    i = 0;

    ///////////////////  ADD  //////////////////
    if (InsARR[0].compare("ADD")==0)
    {
        if (tmpLine.find('\"') != -1){
       	int y = tmpLine.find('\"');
       	if (tmpLine.find('\"', y+1)!= -1){
       		int x = tmpLine.find('\"',y+1 );
    		InsARR[1] = tmpLine.substr(y,x-y+1);
    		int z = tmpLine.length();

    		tmpLine = tmpLine.substr(x+2,z-x-2);


    		string parsed;
    		stringstream input_stringstream(tmpLine);
    		int k = 2;
    	    while (getline(input_stringstream,parsed,' '))
    	    {
    	        if (k > 3){
                    cout<<"Invalid arguments"<<endl;
                    goto endloop;
    	        }
    	        InsARR[k] = parsed;
    	        k++;
    	    }
       	    addMeeting(InsARR[1], InsARR[2], InsARR[3], MyTree);

               }else {
                       if (InstrCount != 4){
                       cout<<"Invalid arguments"<<endl;
                       continue;
                       }
                       else
                       addMeeting(InsARR[1], InsARR[2], InsARR[3], MyTree);
                       }

        }else{
               if (InstrCount != 4){
               cout<<"Invalid arguments"<<endl;
               continue;
               }
               else
               addMeeting(InsARR[1], InsARR[2], InsARR[3], MyTree);
               }
        endloop:;
    }

//////////////////  Find  //////////////////
    else if (InsARR[0].compare("Find")==0)
     {
      if (InstrCount != 3){
        cout<<"Invalid arguments"<<endl;
      }
      else{
        findMeeting(InsARR[1], InsARR[2], MyTree);
     }
     }
//////////////////  MOD  //////////////////
    else if (InsARR[0].compare("MOD")==0)
     {
        if (tmpLine.find('\"') != -1){
       	int y = tmpLine.find('\"');
       	if (tmpLine.find('\"', y+1)!= -1){
       		int x = tmpLine.find('\"',y+1 );
    		InsARR[1] = tmpLine.substr(y,x-y+1);
    		int z = tmpLine.length();

    		tmpLine = tmpLine.substr(x+2,z-x-2);


    		string parsed;
    		stringstream input_stringstream(tmpLine);
    		int k = 2;
    	    while (getline(input_stringstream,parsed,' '))
    	    {
    	        if (k > 3){
                    cout<<"Invalid arguments"<<endl;
                    goto endloop2;
    	        }
    	        InsARR[k] = parsed;
    	        k++;
    	    }
    	    modifyMeeting(InsARR[1], InsARR[2], InsARR[3], MyTree);

               }else {
                       if (InstrCount != 4){
                       cout<<"Invalid arguments"<<endl;
                       continue;
                       }
                       else
                    	 modifyMeeting(InsARR[1], InsARR[2], InsARR[3], MyTree);
                       }

        }else{
               if (InstrCount != 4){
               cout<<"Invalid arguments"<<endl;
               continue;
               }
               else
            	   modifyMeeting(InsARR[1], InsARR[2], InsARR[3], MyTree);
               }
        endloop2:;

     }
 //////////////////  DEL  //////////////////
    else if (InsARR[0].compare("DEL")==0)
     {
      if (InstrCount != 3){
        cout<<"Invalid arguments"<<endl;
      }
      else{
        deleteMeating(InsARR[1], InsARR[2], MyTree);
     }
     }
//////////////////  Print  //////////////////
    else if (InsARR[0].compare("Print")==0)
     {
      if (InstrCount != 1){
        cout<<"Invalid arguments"<<endl;
      }
      else{
        traverse(MyTree);
     }
     }
//////////////////  undefiend command  //////////////////
     else
      cout <<"Invalid command"<<endl;

    }

    DeleteBST(MyTree);

return 0;
}


















