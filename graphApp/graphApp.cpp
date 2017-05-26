// graphApp.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include "iostream"
#include <tuple>
#include <string.h>
#include <fstream>
#include <vector>
#include <sstream>
#include <algorithm>
#include <iterator>
#include <stdarg.h>
#include <type_traits>
#include <cstring>
#include <iomanip>
#include <stdio.h>
#include <conio.h>
#include <cstring>
#include <process.h>
#include <functional>
#include "PointGraph.h"
#include "Point.h"

using namespace std;

string filename;
char ans;
bool isTxtFile(string);
void intro();		//display welcome screen
void entry_menu(string);	//display entry menu on screen
void clrscr();		//clear screen
void pointGraph(string,char);
void lineGraph(string,char);
void barGraph(string,char);
void loadFile(string);
void addData(string);


//void readData(string,struct);
//***************************************************************
//    	CLEAR SCREEN FUNCTION
//***************************************************************
void clrscr()
{
	system("cls");
}
//***************************************************************
//    	INTRODUCTION FUNCTION
//***************************************************************
void intro()
{
	cout << "*****************************************************************************************\n";
	cout << "\t Welcome to Graphing Application!!\n";
	cout << "*****************************************************************************************\n";
	cout << "\t PROJECT NAME: GRAPHING APPLICATION \n";
	cout << "\t MADE BY : NAVYA \n";
	cout << "\t UNIVERSITY : SHAFIELD UNIVERSITY \n";
}

bool isTxtFile(string filename){
    bool istxt = false;
    string ext;
    int cnt = 0;
    for(int ii = 0; ii <filename.length(); ii++ ){
        if(filename[ii] == '.'){
            for(int jj = ii; jj < filename.length(); jj++){
                ext = ext + filename[jj];
                cnt = cnt + 1;
            }
        }
    }
    if(ext == ".txt"){
        istxt = true;
    }
    return istxt;
}

void pointGraph(string filename, char doSort) {
	int cnt = 0;
    bool appSort = false;
    if(doSort == 's' || doSort == 'S'){
        appSort = true;
    }
	Point p;
	string graphtype = "pointgraph";
	p.readData(filename, graphtype, appSort);
}

void barGraph(string filename, char doSort) {
	int cnt = 0;
    bool appSort = false;
    if(doSort == 's' || doSort == 'S'){
        appSort = true;
    }
	Point p;
	string graphtype = "bargraph";
	p.readData(filename, graphtype, appSort);
}

void lineGraph(string filename, char doSort) {
	int cnt = 0;
    bool appSort = false;
    if(doSort == 's' || doSort == 'S'){
        appSort = true;
    }
	Point p;
	string graphtype = "linegraph";
	p.readData(filename, graphtype, appSort);
}

void loadFile(string filename) {

    if(isTxtFile(filename)){
        cout << "File name provided on command line is : " << filename << endl;
        entry_menu(filename);
    }
    else{
        cout << "NOTE: DEFAULT FILENAME = graphData.txt";
        cout << "Do you want to load a file?[y/n]";
        cin >> ans;
        if (ans == 'y' || ans == 'Y') {
            cout << "Please enter the filename: " << endl;
            cin >> filename;
            entry_menu(filename);
        }
        else {
            filename = "graphData.txt";
            entry_menu(filename);
        }
    }
}
void addData(string filename){
    Point p;
    ofstream addGraphData;
    addGraphData.open(filename, ios_base::app);
    string points,pointa,pointb,ans;
    if (addGraphData.is_open()) {
        while (!addGraphData.eof()) {
            cout << "Please enter the data points(eg., pointA,pointB): ";
            cin >> points;
            tie(pointa, pointb) = p.split(points);
            addGraphData << "\n" << pointa << '\t' << pointb;
            cout << "Do you want to add more?[Y/N]";
            cin >> ans;
            if(ans == "N" || ans == "n"){
                 break;
            }
        }
    }
    else{
        cout << "Error opening the file";
    }
    addGraphData.close();
}
//***************************************************************
//    	ENTRY / EDIT MENU FUNCTION
//****************************************************************

void entry_menu(string filename)
{
	char ch[2];
    char option, doSort;
	int num;
//	string filename = "graphData.txt";
	clrscr();
	cout << "******************************************************************************\n";
	cout << "\t ADMINISTRATOR MENU \n";
	cout << "******************************************************************************\n";
    cout << "To do sorting - type s after the number (eg., 1s)" << endl;
	cout << "\t ENTRY MENU \n";
	cout << "\t 1.POINT GRAPH \n";
	cout << "\t 2.LINE GRAPH \n";
	cout << "\t 3.BAR GRAPH \n";
    cout << "\t 4.ADD DATA  \n";
	cout << "\t 5.BACK TO MAIN MENU \n";
	cout << "\t Please Enter Your Choice (1-5) \n";
	cin >> ch;
	clrscr();
    option = ch[0];
    doSort = ch[1];
	switch (option)
	{
	case '1':	pointGraph(filename,doSort); break;
	case '2':	lineGraph(filename,doSort); break;
	case '3':	barGraph(filename,doSort); break;
    case '4':   addData(filename);
	case '5':	break;
	default:	cout << "\a"; entry_menu(filename);
	};
};

int main(int argv, char **argc) {
	string filename;
	char ans;
	for (int ii = 0; ii < argv; ii++) {
		filename = argc[ii];
	}

	loadFile(filename);
	char ch;
	cout.setf(ios::fixed | ios::showpoint);
	cout << setprecision(2); // program outputs decimal number to two decimal places
	clrscr();
	intro();
	do
	{
		clrscr();
		cout << "******************************************************************************\n";
		cout << "\t MAIN MENU \n";
		cout << "******************************************************************************\n";
		cout << "\t 01. LOAD FILE  \n";
		cout << "\t 02. EXIT \n";
		cout << "\t Please Select Your Option (1-2) \n";
		cin >> ch;
		clrscr();
		switch (ch)
		{
		case '1': loadFile(filename);
			break;
		case '2':
			break;
		default:cout << "\a";
		};
	} while (ch != '2');

	return 0;
}
