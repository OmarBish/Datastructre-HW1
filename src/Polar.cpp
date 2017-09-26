/*
 * Polar.cpp
 *
 *  Created on: Sep 23, 2017
 *      Author: omar
 */

#include "Polar.h"
#include <math.h>
#include <iostream>
#include <stdio.h>
//#include <plog/Log.h>
#include <typeinfo>




namespace std {
// functions
	inline double sin_n(double theta){
		return theta ==M_PI||theta==-(M_PI)?(0.0):(sin(theta));
	}
	inline double cos_n(double theta){
		return theta == -(M_PI_2)||theta == M_PI_2?(0.0):(cos(theta));
	}
	double toRad(double degree){
		return degree *M_PI/180;
	}
	double toCar(double degree){
		if(degree==0&&signbit(degree)){
			return 180;
		}
		return degree*180/M_PI;
	}

//end of functions

//Constructors

//Default constructor
	Polar::Polar() {
		r=0;
		theta=0;
	}
//with parameters
	Polar::Polar(double rValue,double thetaValue){
		if(thetaValue>=360||thetaValue<=-360)thetaValue=fmod(thetaValue,360);
		r=rValue;
		theta=thetaValue;
	}

//End of constructors

// Destructor
	Polar::~Polar() {
	}
//end of destructor

//class functions
	double Polar::get_r(){
		//LOG_INFO << "get_r called";
		return r;
	}
	double Polar::get_theta(){
		//LOG_INFO << "get_theta called";
		return theta;
	}
	void Polar::set_r(double rValue){
		//LOG_INFO << "set_r called";
		r=rValue;
	}
	void Polar::set_theta(double thetaValue){
		if(thetaValue>=360||thetaValue<=-360)thetaValue=fmod(thetaValue,360);
		theta=thetaValue;
		//LOG_INFO << "set_theta called";
	}
//end of functions

//operator over loading
	Polar operator -=(Polar& p1, Polar& p2){
		//LOG_INFO <<"theta: p1: "<< p1.theta<<" p2: "<<p2.theta<<"r: p1: "<< p1.r<<" p2: "<<p2.r;
		if(p1.r<0){
			p1.r=p1.r*-1;
			p1.theta+=180;
			//LOG_INFO<<"p1.r where -ve so it was updated :- r: "<< p1.r << " Theta : "<<p1.theta;
		}
		if(p2.r<0){
			p2.r=p2.r*-1;
			p2.theta+=180;
			//LOG_INFO<<"p2.r where -ve so it was updated :- r: "<< p2.r << " Theta : "<<p2.theta;
		}
		double x1 = p1.r * cos_n(toRad(p1.theta));//LOG_INFO<<"calculate x1 : "<<x1<<" cos_n:"<<cos_n(toRad(p1.theta));
		double y1 = p1.r * sin_n(toRad(p1.theta));//LOG_INFO<<"calculate y1: "<<y1<<" sin:"<<sin_n(toRad(p1.theta));
		double x2 = p2.r * cos_n(toRad(p2.theta));//LOG_INFO<<"calculate x2 : "<<x2<<" cos:"<<cos_n(toRad(p2.theta));
		double y2 = p2.r * sin_n(toRad(p2.theta));//LOG_INFO<<"calculate y2 : "<<y2<<" sin:"<<sin_n(toRad(p2.theta));
		double x=x1-x2;double y=y1-y2;//LOG_INFO<<"X: "<<x<<"y:"<<y;
		p1.r=sqrt(pow(x,2)+pow(y,2));//LOG_INFO<<"calculate temp.r:- "<<p1.r;
		if(x==0){p1.theta=90;}//LOG_INFO<<"calculate temp.theta:- "<<p1.theta;
		else {p1.theta=toCar(atan2(y,x));}//LOG_INFO<<"calculate temp.theta:- "<<p1.theta<<"   "<<atan(y/x);
		return p1;

	}//operator -=
	Polar operator +=(Polar& p1, Polar& p2){
		if(p1.r<0){
			p1.r=p1.r*-1;
			p1.theta+=180;
			//LOG_INFO<<"p1.r where -ve so it was updated :- r: "<< p1.r << " Theta : "<<p1.theta;
		}
		if(p2.r<0){
			p2.r=p2.r*-1;
			p2.theta+=180;
			//LOG_INFO<<"p2.r where -ve so it was updated :- r: "<< p2.r << " Theta : "<<p2.theta;
		}
		double x1 = p1.r * cos_n(toRad(p1.theta));//LOG_INFO<<"calculate x1 : "<<x1<<" cos_n:"<<cos_n(toRad(p1.theta));
		double y1 = p1.r * sin_n(toRad(p1.theta));//LOG_INFO<<"calculate y1: "<<y1<<" sin:"<<sin_n(toRad(p1.theta));
		double x2 = p2.r * cos_n(toRad(p2.theta));//LOG_INFO<<"calculate x2 : "<<x2<<" cos:"<<cos_n(toRad(p2.theta));
		double y2 = p2.r * sin_n(toRad(p2.theta));//LOG_INFO<<"calculate y2 : "<<y2<<" sin:"<<sin_n(toRad(p2.theta));
		double x=x1+x2;double y=y1+y2;//LOG_INFO<<"X: "<<x<<"y:"<<y;
		//LOG_INFO<<"update r";
		p1.r=sqrt(pow(x1+x2,2.0)+pow(y1+y2,2.0));
		//LOG_INFO<<"update  theta";
		p1.r=sqrt(pow(x,2)+pow(y,2));//LOG_INFO<<"calculate temp.r:- "<<p1.r;
		if(x==0){p1.theta=90;}//LOG_INFO<<"calculate temp.theta:- "<<p1.theta;}
		else {p1.theta=toCar(atan2(y,x));}//LOG_INFO<<"calculate temp.theta:- "<<p1.theta<<"   "<<atan(y/x);}
		return p1;
	}//operator +=
	Polar operator +(Polar p1,Polar p2){
		Polar temp;
		//LOG_INFO <<"theta: p1: "<< p1.theta<<" p2: "<<p2.theta<<"r: p1: "<< p1.r<<" p2: "<<p2.r;
		if(p1.r<0){
			p1.r=p1.r*-1;
			p1.theta+=180;
			//LOG_INFO<<"p1.r where -ve so it was updated :- r: "<< p1.r << " Theta : "<<p1.theta;
		}
		if(p2.r<0){
			p2.r=p2.r*-1;
			p2.theta+=180;
			//LOG_INFO<<"p2.r where -ve so it was updated :- r: "<< p2.r << " Theta : "<<p2.theta;
		}
		double x1 = p1.r * cos_n(toRad(p1.theta));//LOG_INFO<<"calculate x1 : "<<x1<<" cos_n:"<<cos_n(toRad(p1.theta));
		double y1 = p1.r * sin_n(toRad(p1.theta));//LOG_INFO<<"calculate y1: "<<y1<<" sin:"<<sin_n(toRad(p1.theta));
		double x2 = p2.r * cos_n(toRad(p2.theta));//LOG_INFO<<"calculate x2 : "<<x2<<" cos:"<<cos_n(toRad(p2.theta));
		double y2 = p2.r * sin_n(toRad(p2.theta));//LOG_INFO<<"calculate y2 : "<<y2<<" sin:"<<sin_n(toRad(p2.theta));
		double x=x1+x2;double y=y1+y2;//LOG_INFO<<"X: "<<x<<"y:"<<y;
		temp.r=sqrt(pow(x,2)+pow(y,2));//LOG_INFO<<"calculate temp.r:- "<<temp.r;
		if(x==0){temp.theta=90;}//LOG_INFO<<"calculate temp.theta:- "<<temp.theta;}
		else {temp.theta=toCar(atan2(y,x));}//LOG_INFO<<"calculate temp.theta:- "<<temp.theta<<"   "<<atan(y/x);}
		return temp;
	}//operator +

	Polar operator -(Polar p1,Polar p2){

		Polar temp;
		//LOG_INFO <<"theta: p1: "<< p1.theta<<" p2: "<<p2.theta<<"r: p1: "<< p1.r<<" p2: "<<p2.r;
		if(p1.r<0){
			p1.r=p1.r*-1;
			p1.theta+=180;
			//LOG_INFO<<"p1.r where -ve so it was updated :- r: "<< p1.r << " Theta : "<<p1.theta;
		}
		if(p2.r<0){
			p2.r=p2.r*-1;
			p2.theta+=180;
			//LOG_INFO<<"p2.r where -ve so it was updated :- r: "<< p2.r << " Theta : "<<p2.theta;
		}
		double x1 = p1.r * cos_n(toRad(p1.theta));//LOG_INFO<<"calculate x1 : "<<x1<<" cos_n:"<<cos_n(toRad(p1.theta));
		double y1 = p1.r * sin_n(toRad(p1.theta));//LOG_INFO<<"calculate y1: "<<y1<<" sin:"<<sin_n(toRad(p1.theta));
		double x2 = p2.r * cos_n(toRad(p2.theta));//LOG_INFO<<"calculate x2 : "<<x2<<" cos:"<<cos_n(toRad(p2.theta));
		double y2 = p2.r * sin_n(toRad(p2.theta));//LOG_INFO<<"calculate y2 : "<<y2<<" sin:"<<sin_n(toRad(p2.theta));
		double x=x1-x2;double y=y1-y2;//LOG_INFO<<"X: "<<x<<"y:"<<y;
		temp.r=sqrt(pow(x,2)+pow(y,2));//LOG_INFO<<"calculate temp.r:- "<<temp.r;
		if(x==0){temp.theta=90;}//LOG_INFO<<"calculate temp.theta:- "<<temp.theta;}
		else {temp.theta=toCar(atan2(y,x));}//LOG_INFO<<"calculate temp.theta:- "<<temp.theta<<"   "<<atan(y/x);}
		return temp;
	}//operator -

	Polar operator *(int x,Polar p2){
		//LOG_INFO<<"P2.R: "<<p2.r;
		p2.r*=x;
		return p2;
	}
	Polar operator *(Polar p2,int x){
		p2.r*=x;
		return p2;
	}
	ostream& operator << (ostream &out,Polar &p1){
		cout << "( "<<p1.r<<" , "<<p1.theta<<" )"<<endl;
		return out;
	}
	istream& operator >>(istream &in ,Polar &p1){
		cout << "Please enter Radius:-";
		in >> p1.r;
		cout << "Pleas enter theta in degrees :- ";
		in >> p1.theta;
		return in;
	}
	void Polar::operator =(Polar p1){
		this->r=p1.get_r();
		this->theta=p1.get_theta();
	}

//end of operator over loading

} /* namespace std */
