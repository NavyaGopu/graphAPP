#pragma once
#include "Graph.h"
#include "iostream"
#include <string.h>
#include <sstream>
#include <algorithm>
#include <functional>
#include "PointGraph.h"
#include "Point.h"

using namespace std;

class PointGraph :
	public Graph
{
public:
	PointGraph();
	~PointGraph();
	void draw(string title, int (&x_axis)[10], int (&y_axis)[10], string xtitle, string ytitle);
};

