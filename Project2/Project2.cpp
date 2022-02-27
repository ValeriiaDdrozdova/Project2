// Project2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//project program done by : VALERIIA DROZDOVA 

#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <vector>
#include <string>
#include <map>
using namespace std;

vector<int> extrDegits(int arg);

std::string modString(std::string param) //subtract minus
{

	if (param[0] == '-') //if there is a minus 
	{
		return param.substr(1, param.size()); // substract minus
	}
	else
	{
		return param;
	}

}

vector<string> split(std::string str) //split input into numbers
{
	vector<string> stringInputs;
	std::size_t current, previous = 0;
	current = str.find(", ");
	while (current != std::string::npos) //while it is not the end
	{
		stringInputs.push_back(modString(str.substr(previous, current - previous))); //add to the vector string from the start(or after comma) to the next comma, without minus 
		previous = current + 2; // move to the place after comma
		current = str.find(", ", previous); //find comma after previous
	}
	stringInputs.push_back(modString(str.substr(previous, current - previous)));
	return stringInputs;
}

std::string NumberToString(int inpInteger) //change number into a string
{
	std::ostringstream ss;
	ss << inpInteger;
	return ss.str();
}

vector<int> StringToVectorInt(string inpString) //change string into an integer and put into vector
{
	vector<int> dig;
	for (int i = 0; i < inpString.length(); i++)
	{
		dig.push_back((inpString[i] - '0')); //change string into an integer
	}
	return dig;
}

int main()
{
	char ch;
	vector<map<int, int> > digPositions(10); //vector of 10 empty maps, for 10 digits
	map<int, int>::iterator itDigit; // iterator
	vector<int> digit;
	int inpNumber;

	std::ifstream file;
	std::string line;
	string filename;

	cout << "enter a file name: ";
	cin >> filename;

	file.open(filename + ".txt"); //open file
	while (std::getline(file, line))
	{
		if (!line.length())  //continue while it is not the end
		{
			continue;
		}
	}
	file.close();
	cout << "numbers in file: " << line;
	vector<string> strInput;
	strInput = split(line); //split line into numbers

	for (int p = 0; p < strInput.size(); p++)
	{
		digit = StringToVectorInt(strInput[p]);



		for (int pos = 0; pos < digit.size(); pos++)
		{


			if (digPositions[digit[pos]].end() == digPositions[digit[pos]].find(pos + 1)) //there is nothing in this position
			{

				digPositions[digit[pos]].insert(
					{ pos + 1, 1 }); //add to the vector
			}
			else
			{

				digPositions[digit[pos]].find(pos + 1)->second++; //increase number in second position by one
			}


		}
	}

	cout << "\nDigit statistics in " + filename + "_out.txt file." << endl;

	ofstream fout(filename + "_out.txt", ios_base::out | ios_base::trunc); //open output file

	for (int digital = 0; digital < digPositions.size(); digital++)
	{
		if (digPositions[digital].size() != 0)
		{
			fout << "\nDigit " << digital << ": ";
			for (auto itDigit = digPositions[digital].begin(); itDigit != digPositions[digital].end(); itDigit++)
			{
				fout << "(" << itDigit->first << ", " << itDigit->second << ") ";

			}

		}

	}
	fout.close(); //close output file
	return 0;

}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file

