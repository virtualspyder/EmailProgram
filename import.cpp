#include "labgui.h"

void importSystem(Fl_Widget*, void*)
{
	ifstream inFile("system.dat");
	if(!inFile)
	{
		fl_choice("No data available.", "Ok", 0, 0);	
		return;
	}

	if(fl_choice("Are you sure you want to import data?", "No", "Yes", 0) == 1)
	{
		importSystem(inFile);
		inFile.close();
		fl_choice("Data imported successfully!", "Ok", 0, 0);
		createHome();
	}
}

void export_system(Fl_Widget*, void*)
{
	ofstream outFile("system.dat");
	exportSystem(outFile);
	outFile.close();
	fl_choice("Data exported successfully!", "Ok", 0, 0);
}
