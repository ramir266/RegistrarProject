#include <fstream>
#include <string>
#include <iostream>
#include "RunFile.h"

using namespace std;

RunFile::RunFile()
{
	numberOfWindows = 0;
	numberOfStudents = 0;
	timeOfService = 0;
	clockTick = 0;

}

RunFile::~RunFile(){}

// inFile has already been validated as good file
void RunFile::read( string inFile )
{
	ifstream simFile;
	simFile.open(inFile.c_str());
	string inLine;

	// number of windows
	getline( simFile, inLine );
	numberOfWindows = stoi( inLine );
	cout << "Number of windows: " << numberOfWindows << endl;

	// create array of windows

	// loop until eof
	while (getline( simFile, inLine ))
	{
		// get the clock tick
		clockTick = stoi( inLine );
		cout << "clock: " << clockTick << endl;

		// number of students at this arrival time
		getline( simFile, inLine );
		numberOfStudents = stoi( inLine );
		cout << "Students: " << numberOfStudents << endl;

		for ( int i = 0; i < numberOfStudents; ++i ) 
		{
			getline( simFile, inLine );
			timeOfService = stoi( inLine );
			cout << "Time of Service: " << timeOfService << endl;
		}
	}

}