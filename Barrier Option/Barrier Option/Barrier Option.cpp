// Barrier Option.cpp : main project file.
/* Code by Parkin Furia, M.Sc. Financial Engineering (University of Michigan, Ann Arbor) (parkinfuria@gmail.com)
*/
#include "stdafx.h"
#include "Form1.h"
#include <iostream>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <boost/random/normal_distribution.hpp>
#include <boost/random/mersenne_twister.hpp>
#include <boost/random/variate_generator.hpp>
#include <vector>
#include <algorithm>
#include <conio.h>

template<class T>
double gen_normal_3(T &generator)
{
  return generator();
}

// Version that fills a std::vector
template<class T>
void gen_normal_3(T &generator, std::vector<double> &res)
{
  for(size_t i=0; i<res.size(); ++i)
    res[i]=generator();
}

using namespace BarrierOption;


/*
this function prices the down and out barrier option
It takes the current stock price (s0), strike price (k), barrier price (x), volatility (sigma), time-to-maturity (T), and risk-free rate (r) and returns back the price of the call and put option
*/

double* down_and_out(double s0, double k, double x, double sigma, double T, double r)   
	{boost::variate_generator<boost::mt19937, boost::normal_distribution<> >				//random number generator
    generator(boost::mt19937(time(0)),
              boost::normal_distribution<>());

	int cnt=10000,dt=1000;

	long double t=double(T)/dt;

	long double temp1,temp2;
	double sum=0,sum1=0;
	std::vector<std::vector <double>> stk_price(cnt, std::vector<double> (dt));
	std::vector <double> opt_price(cnt),opt_price1(cnt);


	for (int j=0;j<cnt;j++)																
		{
		stk_price[j][0]=s0;
		for(int i=0;i<(dt-1);i++)
			{temp1=sigma*sqrt(t)*gen_normal_3(generator);
			temp2=r-((sigma*sigma)/2);
			stk_price[j][(i+1)]=(stk_price[j][i]*exp(((temp2)*t)+(temp1)));

			}
		double* first=&stk_price[j][0];
		double* last=&stk_price[j][0]+dt;
		double* min_val=std::min_element(first,last);
	
		if (*min_val<x)													//conditioning for down and out option
		{opt_price[j]=0.00;
		opt_price1[j]=0.00;}
		else 
		{opt_price[j]=exp(-r*T)*std::max((stk_price[j][dt-1]-k),0.00);
		opt_price1[j]=exp(-r*T)*std::max((k-stk_price[j][dt-1]),0.00);}

		sum=sum+opt_price[j];
		sum1=sum1+opt_price1[j];
		}

	double call_put [2];
	call_put[0]=(sum/cnt);
	call_put[1]=(sum1/cnt);
	return &call_put[0];

	}

/*
this function prices the down and in barrier option
It takes the current stock price (s0), strike price (k), barrier price (x), volatility (sigma), time-to-maturity (T), and risk-free rate (r) and returns back the price of the call and put option
*/


double* down_and_in(double s0, double k, double x, double sigma, double T, double r)				
	{boost::variate_generator<boost::mt19937, boost::normal_distribution<> >						//randomn number generation
    generator(boost::mt19937(time(0)),
              boost::normal_distribution<>());

	int cnt=10000,dt=1000;

	long double t=double(T)/dt;

	long double temp1,temp2;
	double sum=0,sum1=0;
	std::vector<std::vector <double>> stk_price(cnt, std::vector<double> (dt));
	std::vector <double> opt_price(cnt), opt_price1(cnt);


	for (int j=0;j<cnt;j++)
		{
		stk_price[j][0]=s0;
		for(int i=0;i<(dt-1);i++)
			{temp1=sigma*sqrt(t)*gen_normal_3(generator);
			temp2=r-((sigma*sigma)/2);
			stk_price[j][(i+1)]=(stk_price[j][i]*exp(((temp2)*t)+(temp1)));

			}
		double* first=&stk_price[j][0];
		double* last=&stk_price[j][0]+dt;
		double* min_val=std::min_element(first,last);
	
		if (*min_val<x)															//conditioning for down and in barrier option
		{opt_price[j]=exp(-r*T)*std::max((stk_price[j][dt-1]-k),0.00);
		opt_price1[j]=exp(-r*T)*std::max((k-stk_price[j][dt-1]),0.00);}
		else 
		{opt_price[j]=0.00;
		opt_price1[j]=0.00;}

		sum=sum+opt_price[j];
		sum1=sum1+opt_price1[j];

		}

	double call_put [2];
	call_put[0]=(sum/cnt);
	call_put[1]=(sum1/cnt);
	return &call_put[0];

	}

/*
this function prices the up and out barrier option
It takes the current stock price (s0), strike price (k), barrier price (x), volatility (sigma), time-to-maturity (T), and risk-free rate (r) and returns back the price of the call and put option
*/



double* up_and_out(double s0, double k, double x, double sigma, double T, double r)				
	{boost::variate_generator<boost::mt19937, boost::normal_distribution<> >					//random number generation
    generator(boost::mt19937(time(0)),
              boost::normal_distribution<>());

	int cnt=10000,dt=1000;

	long double t=double(T)/dt;

	long double temp1,temp2;
	double sum=0,sum1=0;
	std::vector<std::vector <double>> stk_price(cnt, std::vector<double> (dt));
	std::vector <double> opt_price(cnt),opt_price1(cnt);


	for (int j=0;j<cnt;j++)
		{
		stk_price[j][0]=s0;
		for(int i=0;i<(dt-1);i++)
			{temp1=sigma*sqrt(t)*gen_normal_3(generator);
			temp2=r-((sigma*sigma)/2);
			stk_price[j][(i+1)]=(stk_price[j][i]*exp(((temp2)*t)+(temp1)));

			}
		double* first=&stk_price[j][0];
		double* last=&stk_price[j][0]+dt;
		double* max_val=std::max_element(first,last);
	
		if (*max_val<x)																		//conditioning for up and out barrier option
		{opt_price[j]=0.00;
		opt_price1[j]=0.00;}
		else 
		{opt_price[j]=exp(-r*T)*std::max((stk_price[j][dt-1]-k),0.00);
		opt_price1[j]=exp(-r*T)*std::max((k-stk_price[j][dt-1]),0.00);
		}

		sum=sum+opt_price[j];
		sum1=sum1+opt_price1[j];

		}

	double call_put [2];
	call_put[0]=(sum/cnt);
	call_put[1]=(sum1/cnt);
	return &call_put[0];

	}
/**
this function prices the up an in barrier option
It takes the current stock price (s0), strike price (k), barrier price (x), volatility (sigma), time-to-maturity (T), and risk-free rate (r) and returns back the price of the call and put option

**/
double* up_and_in(double s0, double k, double x, double sigma, double T, double r)				
	{boost::variate_generator<boost::mt19937, boost::normal_distribution<> >				//random number generator
    generator(boost::mt19937(time(0)),
              boost::normal_distribution<>());

	int cnt=10000,dt=1000;

	long double t=double(T)/dt;

	long double temp1,temp2;
	double sum=0,sum1=0;
	std::vector<std::vector <double>> stk_price(cnt, std::vector<double> (dt));
	std::vector <double> opt_price(cnt),opt_price1(cnt);


	for (int j=0;j<cnt;j++)
		{
		stk_price[j][0]=s0;
		for(int i=0;i<(dt-1);i++)
			{temp1=sigma*sqrt(t)*gen_normal_3(generator);
			temp2=r-((sigma*sigma)/2);
			stk_price[j][(i+1)]=(stk_price[j][i]*exp(((temp2)*t)+(temp1)));

			}
		double* first=&stk_price[j][0];
		double* last=&stk_price[j][0]+dt;
		double* max_val=std::max_element(first,last);
	
		if (*max_val>x)																		//conditioning for up and in barrier option
		{opt_price[j]=exp(-r*T)*std::max((stk_price[j][dt-1]-k),0.00);	
		opt_price1[j]=exp(-r*T)*std::max((k-stk_price[j][dt-1]),0.00);
		}
		else 
		{opt_price[j]=0.00;
		opt_price1[j]=0.00;}

		sum=sum+opt_price[j];
		sum1=sum1+opt_price1[j];

		}

	double call_put [2];
	call_put[0]=(sum/cnt);
	call_put[1]=(sum1/cnt);
	return &call_put[0];

	}


[STAThreadAttribute]
int main(array<System::String ^> ^args)
{
	// Enabling Windows XP visual effects before any controls are created
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false); 

	// Create the main window and run it
	Application::Run(gcnew Form1());
	return 0;
}
