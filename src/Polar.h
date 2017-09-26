/*
 * Polar.h
 *
 *  Created on: Sep 23, 2017
 *      Author: omar
 */

#ifndef Polar_H_
#define Polar_H_
#include <iostream>
#define PI 3.14159265359


namespace std {
//Polar start
class Polar {
private:
	double r; //Radios
	double theta;
public:

	//constructors
		Polar();//Default
		Polar(double rValue,double thetaValue);
		//Polar (Polar &p1);
	//end of constructors

	//destructors
		virtual ~Polar();
	//end of destructors

	//functions
		void set_r(double rValue);
		void set_theta(double thetaValue);
		double get_r();
		double get_theta();
	//end of functions

	//operator over loading
		friend Polar operator +=(Polar &p1, Polar &p2);
		friend Polar operator -=(Polar &p1, Polar &p2);
		void operator =(Polar p1);
		friend Polar operator +(Polar p1,Polar p2);
		friend Polar operator -(Polar p1,Polar p2);
		friend Polar operator *(int x,Polar p2);
		friend Polar operator *(Polar p2,int x);
		friend ostream& operator <<(ostream &out,Polar &p1);
		friend istream& operator >>(istream &in ,Polar &p1);
	//end of operator over loading
};
//end of Polar

} /* namespace std */

#endif /* Polar_H_ */
