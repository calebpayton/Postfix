/*
 * Author: Caleb A. Payton
 * Simple postfix calculator.
 */

#include<iostream>
#include<stack>
#include<string>
#include<sstream> //maniputales strings as if they were input streams

using namespace std;

bool checkOp(const string& input);
void performOp(const string& input, stack<double>& postfixStack);
  
int main() {
	stack<double> postfixStack; //stack for handling values and operations entered into calculator
	string input;	//user input
	
	cout << "\tPostfix Calculator (enter q to exit)" << endl;
	
	while(true) //while loop to keep calculator running -- q will exit program
	{
		cout << "Enter a value or operation: "; //prompt for getting user input
		cin >> input;	//read in users input

		double num;
		if(stringstream(input) >> num) //use #include<sstream> to handle numeric values  
		{
			postfixStack.push(num); //push value into postfixStack
		}
		else if(checkOp(input)) //check if input is an operator
		{
			performOp(input, postfixStack); //perform operation, pust onto postfixStack
		}
		else if(input == "q") //q to exit program
		{
			return 0;
		}
		else
		{
			cout << "Invalid input" << endl; //error handling
		}
	} //end while loop
} //end main

bool checkOp(const string& input) //function for checking if the input is an operator
{
	string operators[] = {"-","+","*","/"}; //string for handling operators
	
	for(int i = 0; i < 4; i++) 
	{
		if(input == operators[i])
		{
			return true;
		}	
	} //end for loop
	return false;	
} //end checkOp function

void performOp(const string& input, stack<double>& postfixStack) // function for performing operations
/* --!-- note: after operation is performed, push result onto postfixStack --!-- */
{
	double value1, value2, result;
	
	value1 = postfixStack.top();
	postfixStack.pop();
	
	value2 = postfixStack.top();
	postfixStack.pop();
	
	if(input == "-")
	{
		result = value2-value1; //subtraction
	}
	else if(input == "+")
	{
		result = value2+value1; //addition
	}
	else if(input == "*")
	{
		result = value2*value1; //multiplication
	}
	else
	{
		result = value2/value1; //division
	}
	//output result for user to see
	cout << "\t" << value2 << " " << input << " " << value1 << " = " << result << endl;
	postfixStack.push(result); //push result onto postfixStack
} //end performOp function
