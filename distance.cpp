#include <iostream>
#include <fstream>
#include <vector>
#include <math.h>
using namespace std;

double calc(double x, double y, double z);
double calcV(vector<double> & vdC);

int main(int argc, char** argv)
{
	double x = 0.0;  // atof(argv[1]);
	double y = 0.0; // atof(argv[2]);
	double z = 0.0; // atof(argv[3]);

	double result = calc(x,y,z);
	
	//cout << result << endl;
	
	vector<vector<double> > vvdInput;
	vector<double> vdTemp;
	vector<double> vdDist;
	vdTemp.resize(3);
	vvdInput.clear();

	ifstream inputdata ("test_in.txt");

	
	while (!inputdata.eof()) {
		inputdata >> vdTemp[0] >> vdTemp[1] >> vdTemp[2];
		vvdInput.push_back(vdTemp);
	}
	inputdata.close();

	vdDist.resize(vvdInput.size());
	for (int i=0; i<vvdInput.size(); i++) {
		x = vvdInput[i][0];
		y = vvdInput[i][1];
		z = vvdInput[i][2];
		result = calc(x,y,z);
		vdDist[i] = calcV(vvdInput[i]);
		cout << vvdInput[i][0] << " " << vvdInput[i][1] << " " << vvdInput[i][2] << " " << result << " " << vdDist[i] << endl;
	}
	
	int icount = 0;

	ofstream outputdata ("test_out.txt");
	for (int i=0; i<vvdInput.size(); i++) {
		if (vdDist[i] > 200.0) {
			icount++;
		}
		outputdata << (int)vdDist[i] << endl;

	}
	outputdata << icount << endl;
	outputdata.close();

}

double calc (double x, double y, double z) {
	double d = sqrt(pow(x,2)+pow(y,2)+pow(z,2));
	//cout << d << endl;
	return d;
}

double calcV(vector<double> & vdC) {
	double d = sqrt(pow(vdC[0],2)+pow(vdC[1],2)+pow(vdC[2],2));
	return d;
}