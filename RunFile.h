#include <string>
#include "Customer.h"
#include "GenQueue.h"

using namespace std;

class RunFile
{
	public:
		RunFile();
		~RunFile();

		void read(string inFile);
		void simulation();

		int numberOfOpenWindows;
		int numberOfStudents;
		int timeOfService;
		int clockTick;

		//Customer* *serviceWindow; //pointing whats at in the linked list 
		int *serviceWindows;
		int *idleTime;

		//creating queue of type customer
		GenQueue<Customer> *testQueue = new GenQueue<Customer>();

		//DoublyLinkedList<Customer*> theVirtualLine;

};
