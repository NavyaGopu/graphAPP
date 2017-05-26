#pragma once
#include "Graph.h"
#include "stdafx.h"
#include "Point.h"
#include "PointGraph.h"
#include "iostream"
#include <string.h>
#include <sstream>
#include <algorithm>
#include <functional>
#include<conio.h>

using namespace std;

class LineGraph :
	public Graph
{
public:
	LineGraph();
	~LineGraph();
	void draw(string title, int(&x_axis)[10], int(&y_axis)[10], string xtitle, string ytitle);
};

