#include <string>

using namespace std;

class RunFile
{
public:
	RunFile();
	~RunFile();

	void read( string inFile );

	int numberOfWindows;
	int numberOfStudents;
	int timeOfService;
	int clockTick;

};