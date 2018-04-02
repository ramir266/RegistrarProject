#include <fstream>
#include <iostream>
#include <string>
#include <array>
#include "RunFile.h"
//#include "GenQueue.h"

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

RunFile::RunFile()
{
	numberOfOpenWindows = 0;
	numberOfStudents = 0;
	timeOfService = 0;
	clockTick = 0;
}

RunFile::~RunFile(){}

void RunFile::read( string inFile )
{
	//GenQueue<Customer> *testQueue = new GenQueue<Customer>();

	fstream simFile;
	string inLine;

	simFile.open(inFile.c_str());

	// number of windows
	getline( simFile, inLine );
	numberOfOpenWindows = stoi(inLine);
	cout << "Number of windows: " << numberOfOpenWindows << endl;

	// create array of windows
	/*serviceWindow = new Customer*[numberOfWindows];				// defined service window array and define limits

	for ( int i = 0; i < numberOfWindows; ++i )					// create the empty array
	{
		Customer* windowCustomer = new Customer();
		serviceWindow[ i ] = windowCustomer;
	}*/

	serviceWindows = new int[numberOfOpenWindows];				// defined service window array and define limits


	for ( int i = 1; i <= numberOfOpenWindows; ++i )					// create the empty array
	{
		serviceWindows[ i ] = 0;
	}

	// loop until eof
	while (getline( simFile, inLine ))
	{
		// get the clock tick
		clockTick = stoi(inLine);
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
			theCustomer->BuildCustomer( clockTick, timeOfService );
			cout<<"This is the specific customer's clock tick: " << theCustomer->timeInLine<<endl;
			cout<<"This is the specific customer's length of service: "<< theCustomer->timeService<<endl;
			cout<<"This is the specific customer's waiting time: "<< theCustomer->timeWaiting<<endl;

			//putting customers into queue
			testQueue->enqueue(theCustomer);
			cout<<testQueue->getSize()<<endl;
		}
	}
}

void RunFile::simulation()
{
	int clock = 0;
	bool finished = false; 
	int emptyWindows = numberOfOpenWindows;  // iniialize emptyWindows to be number of windows

	while(finished != true)
	{
		//declaring the intial time
		cout<<"Clock Tick: "<<clock<<endl;

		if(!testQueue->isEmpty()) //checking whether queue of students is emptY
		{
			if(testQueue->peekFront()->timeInLine <= clock) // peek at customer at head to see timeInLine
			{
				if (emptyWindows > 0)		//NEED TO CHECK IF OPEN WINDOW
				{	
					for(int i = 1; i <= numberOfOpenWindows; ++i) //array of open windows
					{
						if(serviceWindows[i] == 0 && !testQueue->getSize() == 0 && testQueue->peekFront()->timeInLine <= clock)
						{
							Customer* temp1 = testQueue->dequeue();  
							serviceWindows[i] = temp1->timeService+1;
							// statistics for how long customer was waiting in line
							emptyWindows--;
							cout << "Customer entered window number: " << i << endl;
							//cout << "Number of empty windows: " << emptyWindows << endl;
						}
						else 
						{
							cout << "Break out of for loop\n";
							continue;
						}
						cout<<"Window "<< i <<" occupied for: "<< serviceWindows[i] <<endl;
					}
				}
			}
			else
			{
				cout << "No customers at clock tick: " << clock << endl;
			}
		}
		for(int i = 1; i <= numberOfOpenWindows; i++)
		{
			if(serviceWindows[i]!=0)
			{
				serviceWindows[i]--;
				cout << "new time of service for window " << i << " : " << serviceWindows[i] << endl;
				if (serviceWindows[i] == 0)
				{
					emptyWindows++;
					//statistics here
					cout << "incremented emptyWindows to: " << emptyWindows << endl;
				}
				
			}
		}
		clock++;	
			/*
			else  // what's happening here?
			{
				if(serviceWindows[i] == 0)
				{
					emptyWindows++;
				}
				else
					serviceWindows[i]--; 
			}*/
		/*if( testQueue->isEmpty() == true)
		{
			cout << "Reached the end of the queue!\n";
		}*/

		if(emptyWindows == numberOfOpenWindows && testQueue->isEmpty() == true)
		{
			finished = true;
			cout  << "Did I get here?\n";
			//cout<<"Empty Windows: "<<emptyWindows<<"\nOpen Windows: "<<numberOfOpenWindows<<endl;
		}

		if (clock == 40)
			break;
	}

}