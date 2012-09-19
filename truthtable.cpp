#include "iostream"
#include "cmath"
#include "vector"
#include "string"

using namespace std;

string readInput();
vector<char> parseInput(string input);
void printVector(vector<string>inputName, vector< vector<char> > outputNumbers, int counter, int timescale);
void gatherAll(vector<string> inputName,vector <vector<char> > outputNumbers, int timescale);
int main() {
	int inputNumber,counter;
	vector<string> inputName;
	string input;
	vector < vector<char> > outputNumbers;
	vector <char> tempVector;
	int timescale;
	
		
	// Input number of inputs
	cout << "Enter the number of inputs you will be using: ";
	cin >> inputNumber;
	while(floor(inputNumber) != inputNumber) {
		cin >> inputNumber;
	}
	//Test: Check to verify input Number
	cout << "Input Number reached" << inputNumber <<endl;
	
	
	//Enter names of vectors
	for(int x=0; x<inputNumber; x++){
		string temp;
		cout << "Enter the name for input " << x << ": ";
		cin >> temp;
		inputName.push_back(temp);
		cout << x <<endl;
	}
	cout << "Vector loop passed" <<endl;
	//Test: Input out all vector names
	for(int j=0; j<inputName.size();j++){
		cout << inputName[j] <<endl;
	}
	
	//Get timescale
	cout <<"Enter integer value for timescale: ";
	cin >> timescale;
	
	cout << "//////////////" <<endl;
	cout << "//////////////" <<endl;	
	while(true){
	input = readInput();
	
	/*
	//Test: Readout input
	cout << input <<endl;
	*/
	
	//If input = end, print
	if (input == "end"){
		break;
	}
	//If input = all, run all then print
	if(input == "all"){
		gatherAll(inputName,outputNumbers,timescale);
	}
	
	//Else, parse input into vector
	tempVector = parseInput(input);
	outputNumbers.push_back(tempVector);
	counter++;
	}
	
	printVector(inputName, outputNumbers,counter,timescale);
}

string readInput(){
	string input;
	cout << "Enter a input string: ";
	cin >> input;
	return input;
}

vector<char> parseInput(string input){
	// Take each character and place into vector
	vector<char> tempVector;
	for(int i=0; i<input.size(); i++){
		tempVector.push_back(input.at(i));
	}
	//Test: Read out entire vector
	for(int i=0; i<input.size(); i++){
		cout << tempVector.at(i) <<endl;
	}
	return tempVector;
}

void printVector(vector<string>inputName, vector< vector<char> > outputNumbers, int counter, int timescale){
	for(int i=0; i<counter; i++){
		for(int j=0; j<inputName.size(); j++){
			cout << inputName.at(j) << " <= " <<outputNumbers.at(i).at(j)<<";";
		}
		cout << " #" <<timescale <<";"<<endl;
	}
	
}

void gatherAll(vector<string> inputName,vector <vector<char> > outputNumbers, int timescale) {
	int counter;
	vector<char> tempVector(inputName.size(),0);
	outputNumbers.push_back(tempVector);
	//Test: check inputsize
	cout << "Input size is: " <<inputName.size() <<endl;
	for(int i=0;i<inputName.size();i++){
		for (int j=0;j<inputName.size();j++){
			if(j<i){
				tempVector.at(i) = '0';
			}
			else{
				tempVector.at(j) = '1';
			}
		}
		//Test: output Vector
		outputNumbers.push_back(tempVector);
		counter++;
	}
	cout << "Counter" <<counter;
	printVector(inputName,outputNumbers,counter,timescale);
}
