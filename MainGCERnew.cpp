#include <iostream>
#include <fstream>
//#include "TeleopPioneer.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
using namespace std;

class TeleopPioneer
{
public:
	TeleopPioneer()
    {
		linear_ = 1;
		angular_ = 1;
		flag = 1;
    }
	void usr_drive();
	void auto_drive(int);
private:
	void joyCallBack(char a);
	int joyCall();
	int linear_ ;
	int angular_ ;
	int flag ;
};
void TeleopPioneer::auto_drive(int count)
{
	if(count%2 == 0)
	{
		cout<<"\nRobot is automatically driving to the nearest location!";
		//cout<<"\nSound Played!";
		system("start WINNER.mp3");
		cout<<"I am the nearest position!";
	}
	else
	{
		cout<<"\nRobot is automatically driving to the farthest location!";
		// cout<<"\nSound Played!";
		system("start WINNER.mp3");
		cout<<"I am at the farthest position!";
	}
}
void TeleopPioneer::usr_drive()
{
	char u;
	cout<<"\nEnter Controller: ";
	cin>>u;
	this->joyCallBack(u);

}


int TeleopPioneer::joyCall()
{
   cout<<"Inside wii mote function!";
   return 0;
}
void TeleopPioneer::joyCallBack(char a)
{
	//if(joy->buttons[10]==1)
	if(a=='W' || a=='w')
	{
		flag = 0;
		cout<<"Switching to Wii Mote Controller!";
		joyCall();
	}
	int n;
//	if(joy->buttons[11]==1)
	if(a=='P' || a == 'p')
	{
		flag =1;
		cout<<"Working with PS3 Controller!";
		cout<<"\nEnter number(4,5,6,7) : ";
		cin>>n;
//		if(joy->buttons[4]==1)
		if(n==4)
		{
			// vel.linear.x = 0.2*joy->buttons[4];
			cout<<"You are going up";
		}
		if(n==5)
		{
			cout<<"You are going right";
		}
		if(n==6)
		{
			cout<<"You are going down";
		}
		if(n==7)
		{
			cout<<"You are going left";
		}
		if(n==9)
		{
			cout<<"Stopped!";
		}
	}
}


// TeleopPioneer test1;

// functions
void write_dist(double);
void functionCall();
void generate_perf_dists();
double read_artag(); // returns distance between human and robot
// double write_dist_moved();

// number of conditions
int n_comfort = 6;
int n_perf_exp = 6;
int min_n_pref = 2;

// return positions
double dist_near = 0.25;
double dist_far = 5.0;
double dist_choice = 0.0;

// selected distances
const int n_dists = 10;
float dist[n_dists] = {0.25,0.75,1.25,1.75,2.25,2.75,3.25,3.75,4.25,4.75};


//function definitions
void write_dist(double vale)
{
	// move to this position
	cout<<"\n Writing distance to file";
	ofstream myfile;
	myfile.open ("write.csv",ios::ate | ios::app);
	if(myfile.is_open())
	{
	myfile<<vale<<",";
	myfile.close();
	}
	else {cout<<"Unable to open file!";}
}

void functionCall()
{
	int y;
	ifstream myfile;
	myfile.open ("UserID.txt");
	if(myfile.is_open())
		   	{
		   			myfile>>y;   // change it to READ SYSTEM TIME
		   	}
		    else
		    {
		   	    cout<<"\nUnable to open file!";
		   	}
		   y= y+1;
		   ofstream out;
		   out.open ("UserID.txt", ios::ate);
		   out<<y;
		   out.close();
		   int uid = y;
		   ofstream in;
		   cout<<"I am here!";
			  in.open ("write.csv",ios::ate | ios::app);
			  if(in.is_open())
			  	   	{
			  	   			in<<"\n"<<uid<<",";
			  	   			in.close();
			  	   	}
			  	    	else
			  	    	{
			  	   		    cout<<"\nUnable to open file!";
			  	   		}
}
double read_artag()
{
	double val;
	srand (time(NULL));
	val = rand()%5+1;
	cout<<"Returning ARTag reading that is the distance between human and robot!\n";
	return val;
}
float value;
void generate_perf_dists()
{
	value = dist[int(rand()%10)];
	cout<<"Writing distance to file\n";
	cout<<value<<endl;
	ofstream myfile;
	myfile.open ("write.csv",ios::ate | ios::app);
	if(myfile.is_open())
	{
	  myfile<<value<<",";
	  myfile.close();
	}
	else
	{
		cout<<"Unable to open file!";
	}
}
// main file
int main()
{
	//int v;
	// open file!!
	functionCall();
	// int count = 0;
	TeleopPioneer Test[6];
	double comf_dist[n_comfort];
	//int len = int(sizeof(comf_dist)/sizeof(double));
    for (int i = 0; i < 6; ++i)
 	{
    	Test[i].usr_drive();
    	comf_dist[i] = read_artag();
	    write_dist(comf_dist[i]);
		//comf_dist[1] = write_dist();
		// return_dist =
		Test[i].auto_drive(i);
 	}
	dist_choice = (comf_dist[0] + comf_dist[1]) / 2; // calculating the choice position

	// performance exploration
	float perf_exp_dist[n_perf_exp];
	for(int i= 0;i<n_perf_exp;i++)
	{
	 generate_perf_dists();// generate_performance dists is a function
	}
}


/*double write_dist_moved()
{
	double value;
	value = 1 + (rand()%6);
	cout<<"\n Writing distance to file";
	return value;
}
*/
/*namespace std {

Teleop::Teleop() {
	// TODO Auto-generated constructor stub

}

Teleop::~Teleop() {
	// TODO Auto-generated destructor stub
}*/

