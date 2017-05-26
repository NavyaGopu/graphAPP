#include "stdafx.h"
#include "Point.h"
#include "iostream"
#include <string.h>
#include "PointGraph.h"
#include "LineGraph.h"
#include "BarGraph.h"
#include <fstream>
#include <tuple>
#include <algorithm>
#include <functional>
#include<conio.h>

using namespace std;

Point::Point()
{
}
Point::~Point()
{
}
struct GraphData
{
	string graphTitle;
	string X_axis[10];
	string Y_axis[10];
}GraphD;

tuple<string, string> Point::split(string line) {
	string word1 = "";
	string word2 = "";
	char delim[2] = "\t";
	char comma[2] = ",";
	bool found = 0;

	for (int ii = 0; ii <= line.length(); ii++) {
		if ((line[ii] != comma[0] && line[ii] != delim[0]) && !found) {
			word1 = word1 + line[ii];
		}
		else {
			found = 1;
		}
		if (found) {
			if (line[ii] == delim[0] || line[ii] == comma[0]) {

			}
			else {
				word2 = word2 + line[ii];
			}
		}
	}
	return make_tuple(word1, word2);
}

void Point::readData(string filename,string graphtype, bool appSort)
{
	bool pointgraph = false;
	bool linegraph = false;
	bool bargraph = false;
	int aa[10];
	if (graphtype == "pointgraph") {
		pointgraph = true;
	}
	if (graphtype == "linegraph") {
		linegraph = true;
	}
	if (graphtype == "bargraph") {
		bargraph = true;
	}
	string line, x, y,  data[50];
	int count = 0, a[10], b[10];
	string graphtitle, xtitle, ytitle;
	ifstream graphdata;
	graphdata.open(filename);
	if (graphdata.is_open()) {
		while (!graphdata.eof()) {
			getline(graphdata, line);
			data[count] = line;
			if (count == 0 || count == 1) {
				if (count == 0) {
					graphtitle = line;
					//				GraphD[count].graphTitle = graphtitle;
					GraphD.graphTitle = graphtitle;
				}
				if (count == 1) {
					tie(x, y) = split(line);
					xtitle = x;
					ytitle = y;
				}
			}
			else {
				tie(x, y) = split(line);
				//				GraphD[count].X_axis = x;
				//				GraphD[count].Y_axis = y;
				a[count - 2] = stoi(x);
				b[count - 2] = stoi(y);
				GraphD.X_axis[count - 2] = x;
				GraphD.Y_axis[count - 2] = y;
			}
			count = count + 1;
		}
		graphdata.close();
		if(appSort){
			sort(a, a + count, greater<int>());
		}
		if (pointgraph) {
			PointGraph p;
			p.draw(graphtitle, a, b,xtitle,ytitle);
		}
		if (graphtype == "linegraph") {
			LineGraph l;
			l.draw(graphtitle, a, b, xtitle, ytitle);
		}
		if (graphtype == "bargraph") {
			BarGraph bar;
			bar.draw(graphtitle, a, b, xtitle, ytitle);
		}
	}
	else {
		cout << "Error opening the file";
	}
	
};






