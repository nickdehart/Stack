#include <iostream>		//for cout
#include <cstdlib>
#include <string>		//for string
#include <vector>		//for vector
#include "stack.h"		//for stack

using namespace std;		//to use std functions
using namespace StackStructure;	//to use stack functions

void evaluate(Stack<string> &s, int condition);
//evaluates the postfix expression
void getExpression(vector<string> & v, string &s, int &condition);
//gets a infix expression from keyboard
void opManage(string & x, Stack<string> &s, Stack<string> &stk);
//manages operators, puts them in correct places
int valid(char con, int &LP, int &RP, int &prev);
//checks the validity of input characters
bool operators(string &s);
//simple check to see if it is an operator

int main() 
{// main function
	int condition = 0;		//integer to hold condition
    Stack<string> opStack;  //stack to hold operators
	vector<string> infix;	//vector to hold infix operation
	string input;			//string to store input from keyboard
	Stack<string> output;	//stack to hold postfix operation
	string exit = "exit";	//string for exit condition
	string space = " ";		//string to compare space character

while(input != exit)	//while exit not typed in
{//while
    input.clear();  //clear variables from prior expressions
    output.clear(); //clear
	infix.clear();	//clear
	opStack.clear();//clear
	condition = 0;	//clear
	getExpression(infix, input, condition);	//get an infix expression
	if(input == exit)	//if exit typed
	  return(0);		//exit program
	
  if(condition < 3)		//if expression can be converted
	{//if
	for(auto & x : infix)	//walk through vector
	  {//for
	  if(operators(x))				//if operator
	    opManage(x,output,opStack);	//manage the operator
	  else (output.push(x));		//else push to output
	  }//for

	cout << "Postfix expression: " << output;	//output expression
	while(!opStack.empty())			//get whatever operators
	{cout << opStack.top() << ' ';	//are still in operator stack
	 output.push(opStack.top());	//add them to output stack as well
	 opStack.pop();}				//remove from operator stack
	 
	cout<< "\nPostfix evaluation: " << output << " = "; 
	if(condition < 2)				//if expression can be evaluated
	  evaluate(output, condition);	//evaluate
	else
	{cout << "\nCan't evaluate expression with variables.";}
	cout << "\n\n";		//otherwise provide explaination
	}//if
  else if(condition == 3)	//if mis-matched parentheses
  {cout << "Error: Expression has mis-matched parentheses.\n\n";}
  else if(condition == 4)	//if operators are invalid
  {cout << "Error: Operators/Operands are invalid.\n\n";}
  else if(condition == 5)	//if an invalid character was entered
  {cout << "Error: Invalid character(s) were entered.\n\n";}
}//while
return(0);	//exit program
}//main function

//gets an expression from keyboard
void getExpression(vector<string> &v, string &s, int &condition)
{//function
int LP = 0;		//counter for left parentheses
int RP = 0;		//counter for right parentheses
int prev = 0;	//condition of previous character

cout << "Enter infix expression ('exit' to quit): ";
	getline(cin,s);	//get infix expression

if(s == "exit")	//if exit typed
  return;		//leave function
cout << "\n\n";	//create buffer		
int k = 0;		//counter
string place;	//place holder
  while(k < s.length())		//while still walking through string
    {//while
	prev = valid(s.at(k), LP, RP, prev);
	//check validity of character
	if(prev > condition)	//if condition needs to be escalated
	  condition = prev;		//escalate it
	if(s.at(k) != ' ')			//if not equal to space
	  place.push_back(s.at(k));	//add character to place holder
	else	
	  {//else
	  v.push_back(place);  //or else put place in vector
	  place.clear();	   //clear place holder
	  }//else
	k++;	//increment counter
    }//while
	v.push_back(place); //put final place in vector
	if(LP != RP)	//if parentheses dont match
	 condition = 3;	//escalate condition
  return;	//return to caller
}//function

//manages operators
void opManage(string & x, Stack<string> &s, Stack<string> &stk)
{//function
string LP = "("; //declare strings
string RP = ")"; //in order to
string m = "*";  //compare with
string d = "/";  //other strings
string a = "+";  //from stacks
string u = "-";  //or x variable
string space = " ";

  if((stk.empty()) && (x != RP))
    stk.push(x);			//push operator into stack if empty and not )
  else if(x == LP)			//
    stk.push(x);			//always push a left (
  else if(x == RP)			// if )
    {while(!stk.empty() && (stk.top() != LP))
	  {s.push(stk.top());	//push ops onto stack
	   stk.pop();}			//pop from ops
	   stk.pop();}			//pop LP
  else if((x == m) || (x == d))
    {//else if
	if((stk.top() == m) || (stk.top() == d))
	  {s.push(stk.top());	//if * * push
	   stk.pop();			//pop from stack
	   stk.push(x);}		//push x onto stack
	else stk.push(x);		//else higher P, push on top
	}//else if
  else if((x == a) || (x == u)) //if add or sub
    {//else if
	if((stk.top() == a) || (stk.top() == u))
	  {s.push(stk.top());	//if + + push
	   stk.pop();			//pop from stack
	   stk.push(x);}		//push x onto stack
	else if((stk.top() == m) || (stk.top() == d))
	  {//else if2
	  while((!stk.empty()) && (stk.top() != LP))
	    {s.push(stk.top());	
		 stk.pop();}
	  stk.push(x);
	  }//else if 2
	else stk.push(x);
	}//else if
}// function

// evaluates the postfix expression
void evaluate(Stack<string> &s, int condition)
{//function
Stack<string> load;  //stack to reverse order of output
Stack<string> eval;	 //stack to hold evaluation
string m = "*";		//multiply
string d = "/";		//divide
string a = "+";		//add
string u = "-";		//sub
string space = " ";	//space
int iResult = 0;		//integer result
float fpResult = 0.0;	//floating result

while(!s.empty())			//while not empty
  {//while
   if(s.top() != space)		//if top != space
     {load.push(s.top());}	//push top of s into load
   s.pop();					//pop s
  }//while
 
while(!load.empty())		//while load is not empty
{//while
if(!operators(load.top()))	//if top is not an operator
  {eval.push(load.top());	//push it onto evaluation stack
   load.pop();}				//pop load stack
else						//else
  {//else
  string operation = load.top();//operation = the op
  load.pop();				//pop the op
  string o2 = eval.top();	//operand 2 = top
  eval.pop();				//pop the top
  string o1 = eval.top();	//operand 1 = next top
  eval.pop();				//pop the top
  if(condition == 0)			//if integers expected
  {//if
    int oper1 = stoi(o1,nullptr);//string to int op1
    int oper2 = stoi(o2,nullptr);//string to int op2
    if(operation == m)			//if multiply
      iResult = oper1 * oper2;
    else if(operation == d)		//if divide
      iResult = oper1 / oper2;
    else if(operation == a)		//if add
      iResult = oper1 + oper2;
    else if(operation == u)		//if sub
      iResult = oper1 - oper2;
	
    eval.push(to_string(iResult)); //push result to eval stack
  }//if
  else if(condition == 1)		//if floating points expected
  {//else if
    float oper1 = stof(o1,nullptr);//string to float op1
    float oper2 = stof(o2,nullptr);//string to float op2
    if(operation == m)			//if multiply
      fpResult = oper1 * oper2;
    else if(operation == d)		//if divide
      fpResult = oper1 / oper2;
    else if(operation == a)		//if add
      fpResult = oper1 + oper2;
    else if(operation == u)		//if sub
      fpResult = oper1 - oper2;
	
    eval.push(to_string(fpResult));//push result to eval stack
    }//esle if
  }//else
}//while
  cout << eval;	//output evaluation
}//function

int valid(char con, int &LP, int &RP, int &prev)
{
  bool operate = false;	//operation
  bool FP = false;		//floating
  bool number = false;	//number
  bool variable = false;//variable
  bool par = false;		//parentheses
  
  if(con == ' ')	//if space
    return(0);
  if ((con == '*') || (con == '/') || (con == '-'))
    operate = true; 	//if operation
  else if ((con == '(') || (con == ')') || (con == '+'))
    operate = true;		//if operation
  if(con == '(')		//if left parentheses
    {++LP;
	 par = true;}
  if(con == ')')		//if right parentheses
    {++RP;
	 par = true;}
  if(con == '.')		//if . encountered
    FP = true;
  if(con == '_')		//if underscore
    variable = true;
  else if ((con > 47) && (con < 58))
    number = true;		//if number
  else if ((con > 64) && (con < 91))
    variable = true;	//if variable
  else if ((con > 96) && (con < 123))
    variable = true;	//if variable
	
  if(par == true)
    return(-2);		//parentheses
  else if(operate == true)	//operation
    {if(prev == -1)
	   return(4);
	 else return(-1);}
  else if(FP == true)		//floating point
    return(1);
  else if(number == true)	//number
    return(0);
  else if(variable = true)	//variable
    return(2);  
  else return(5);	//not found
// return -2 == parentheses, for reference
// return -1 == operator, can evaluate expression
// return 0 == number, can evaluate expression
// return 1 == has floating point values
// return 2 == has variables, can convert, cant evaluate
// return 3 == mismatched parentheses
// return 4 == operators/operands don't match
// return 5 == invalid character
}

bool operators(string &s)
{
string LP = "(";	//declare strings
string RP = ")";
string m = "*";
string d = "/";
string a = "+";
string u = "-";

  if ((s == m) || (s == d) || (s == u))
    return true; //true if above
  else if ((s == LP) || (s == RP) || (s == a))
    return true; //true if above
  else return false; //false if not
}