#pragma once
#include "Graph.h"
#include "stdafx.h"
#include "BarGraph.h"
#include "Point.h"
#include "PointGraph.h"
#include "iostream"
#include <string.h>
#include <sstream>
#include <algorithm>
#include <functional>

using namespace std;

class BarGraph :
	public Graph
{
public:
	BarGraph();
	~BarGraph();
	void draw(string title, int(&x_axis)[10], int(&y_axis)[10], string xtitle, string ytitle);
};

