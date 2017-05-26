#include "stdafx.h"
#include "BarGraph.h"
#include "Point.h"
#include "PointGraph.h"
#include "iostream"
#include <string.h>
#include <sstream>
#include <algorithm>
#include <functional>
#include<conio.h>

BarGraph::BarGraph()
{
}


BarGraph::~BarGraph()
{
}

void BarGraph::draw(string title, int(&x_axis)[10], int(&y_axis)[10], string xtitle, string ytitle)
{
	bool end = true;
	int first, second, ii, jj;
	int count = 0;
	cout << "******************************" << endl;
	cout << "		  Bar GRAPH		   " << endl;
	cout << "******************************\n\n\n" << endl;
	cout << "Y-axis: " << ytitle << "            " << title << "         \n\n\n" << endl;
	while (x_axis[count] > 0)
	{
		count = count + 1;
	}
	int aa[10];
	for (ii = 0; ii < count; ii++) {
		aa[ii] = y_axis[ii];
	}
	for (ii = 0; ii < count; ii++) {
		for (jj = 0; jj < count; jj++) {
			string stars(y_axis[jj], '*');
			if (y_axis[jj] == aa[ii]) {
				cout << xtitle + to_string(x_axis[ii]) << "* " << stars << to_string(y_axis[jj]) << endl;
			}
		}
	}
	string stars(count * 6, '*');
	cout << "\t" << stars << endl;
	cout << "\t *\t X-axis:  " << xtitle << endl;
	_getch();
}