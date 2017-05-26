#pragma once
#include "stdafx.h"
#include "Point.h"
#include "iostream"
#include <string.h>
#include "PointGraph.h"
#include <fstream>
#include <tuple>


using namespace std;

class Point
{
public:
	Point();
	~Point();
	tuple<string, string> split(string line);
	struct GraphData;
	void readData(string filename,string graphtype,bool appSort);
};

