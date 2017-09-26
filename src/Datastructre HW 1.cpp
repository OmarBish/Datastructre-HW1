//============================================================================
// Name        : Datastructre_HW1.cpp
// Author      : Omar Bishtawi
// Version     :
// Copyright   : 
// Description : arithmetic operations on polar coordinates
//============================================================================

#include <iostream>
#include <stdio.h>
#include "Polar.h"
//#include <plog/Log.h>
#include <math.h>
using namespace std;


int main() {

	//looger initialize
//	plog::init(plog::debug, "LOG.txt");
//	LOG_INFO << "operation start";

	//Test code
	Polar P1(2 , 229.);
	Polar P2(1.5 , 114);
	Polar P3,P4,P5,P6, P7, P8 , P9;


	P3 = P1+P2;
	P4 = P1-P2;
	P5 = 2 * P2;
	P6 = P3 * 3;
	cout<<"P3= "<<P3<<endl;
	cout<<"P4= "<<P4<<endl;
	cout<<"P5= "<<P5<<endl;
	cout<<"P6= "<<P6<<endl;
	cin>>P7;
	cout<<"P7: "<<P7<<endl;
	P7 += P1;
	cout<<"P7: "<<P7<<endl;
	P8=P1+P2+P3-P4;
	cout<<"P8: "<<P8<<endl;

	return 0;
}
