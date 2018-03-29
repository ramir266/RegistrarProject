#include <fstream>
#include <string>
#include <iostream>
#include <array>
#include "RunFile.h"

using namespace std;

/*
	Read the input file and process it. The first line should be the number of service windows. The following lines should be formatted in
	the following manner... 
		clock tick
		number of customers
		(length of service time X number of customers)

	- Once the number of service windows is determined create the serviceWindow array of type Customer
	
	- Then proceed to read the remainder of the file using the algorithm above.
		+ get the clock tick
		+ get the number of students
		for loop to get length_of_service
		+ once a length of service is retrieved add entry to the queue of customers
*/

	// number of windows
	getline( simFile, inLine );
	numberOfWindows = stoi( inLine );
	cout << "Number of windows: " << numberOfWindows << endl;

	// create array of windows
	serviceWindow = new Customer*[numberOfWindows];				// defined service window array and define limits

	for ( int i = 0; i < numberOfWindows; ++i )					// create the empty array
	{
		Customer* windowCustomer = new Customer();
		serviceWindow[ i ] = windowCustomer;
	}

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
			
			/* build virtual line but first create customer. */
			Customer* theCustomer = new Customer();
			theCustomer.BuildCustomer( clockTick, timeOfService );

			/* put the customer into the queue */
			theVirtualLine.

		}
	}

}