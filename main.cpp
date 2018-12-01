/* to use this, 
     - write a form that calls this program with 'action=' in the <form> tag
     - call getPostData() 
     - use getField(string) to access form information 

*/
#include <iostream>
#include "htmlform.h"
#include <string.h>
#include <stdlib.h>
#include"BST.h"

void printProgram(string);   /// print the program in HTML
void binaryProgram(int);
void tableView();
using namespace std;

int main()
{
  /// complete the http header
  cout << "Content-type: text/html\n\n";

  /// build a form object
  HTMLform steps;
  steps.getPostData();

  /// Show the debugging
  cout << "Queue Parser Lab startup" << endl;
  steps.debug();

  

  /// the entire programs
  string program = steps.getField("program");
  
  printProgram(program);
  //The next line is for you to complete
  //parseProgram(program);

  return 0;
}

void printProgram(string program)
{
  //string num;
  BST tree;
  int i, j, k;
	vector<string> SS,SS1;
  string method;
	string Str = program;
  string num;
  int nums;
  int choice;
  string binaryType;
  string data;
  string checkString;
	while (!Str.empty())
	{
		//SS.push_back(Str.substr(0, Str.find(" "))); 
		SS.push_back(Str.substr(0, Str.find("\n")));
    		SS1.push_back(Str.substr(0,Str.find(",")));
		if (Str.find(" ") > Str.size()) 
		{
			break;
		}
		else
		{
			Str.erase(0, Str.find(" ") + 1);
 			Str.erase(0, Str.find("\n") + 1);
		}
	}
	for (int i = 0; i < SS.size()-1; i++)
	{
    //find method
    method = SS[i].substr(0,7);

    if(SS1[i].size() >= 9){
      num = SS[i].substr(7,2);
      nums = atoi(num.c_str());
      data = SS[i].substr(11,SS[i].size() - 10);
    }
    else if (SS1[i].size() <= 8){
      num = SS[i].substr(7,1);
      nums = atoi(num.c_str());
      data = SS[i].substr(10,SS[i].size() - 9);
    }
    //DEBUG MDETHOD , NUM and DATA
    //cout << "Method: " << method << "<br />" << endl;
    //cout << "Num: " << nums << "<br />" << endl;
    //cout << "Data: " << data << "<br />" << endl;
    tree.Insert(nums,data);
	}
  binaryType = SS[SS.size() - 1];
  if (binaryType == "PREORDER"){
    cout << "<table border = '1'>";
    tree.preorderPrint();
    cout << "</table>";
  }
  else if(binaryType == "INORDER"){
    cout << "<table border = '1'>";
    tree.inorderPrint();
    cout << "</table>";
  }
  else if (binaryType == "POSTORDER"){
    cout << "<table border = '1'>";
    tree.postorderPrint();
    cout << "</table>";
  }
 else{
 	cout << "INVALID COMMAND : " << SS[SS.size()-1] << "<br \>" << endl;
	cout << "COMMANDS VALID are: INORDER, PREORDER, POSTORDER " << "<br \>" << endl; 
 }

}