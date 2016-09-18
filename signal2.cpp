#include <iostream>
#include <fstream>
#include <vector>
#include <math.h>
using namespace std;

double FindT(double daC[]);

int main (int argc, char** argv)
{
	double daInput[2];
	daInput[0] = atof(argv[1]);    // This is 1481 times the time difference between C and A
	daInput[1] = atof(argv[2]);    // This is 1481 times the time difference between A and B
	double a = daInput[0];
	double b = daInput[1];
	double daC [4];
	daC[0]=2.0*a+b;
	daC[1]=pow(a,2)+a*b+pow(b,2)/2+0.75;
	daC[2]=2.0*b;
	daC[3]=2.0*a*b+pow(b,2);

	double test = FindT(daC); // This helps find the distance from the point P to C
	double x = b*(test+a+0.5*b);
	double y = (a+0.5*b)*test+(pow(a,2)+a*b+pow(b,2)+0.75)/2.0;

	cout << test << "(" << x << "," << y << ")" << endl;
}

double FindT(double daC[]) {
	double dret;
	double daTemp [4];
	daTemp[0]=pow(daC[0],2)+pow(daC[2],2)-4;
	daTemp[1]=2.0*(daC[0]*(daC[1]-2)+daC[2]*daC[3]);
	daTemp[2]=pow(daC[1]-2,2)+pow(daC[3],2);
	daTemp[3]=pow(daTemp[1],2)-4.0*daTemp[0]*daTemp[2];
	if (daTemp[3]<0.0)
		dret = 0;
	else
		dret = (-daTemp[1]-sqrt(daTemp[3]))/(2.0*daTemp[0]);

	return dret;
	
}