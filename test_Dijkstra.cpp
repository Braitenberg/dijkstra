// Alleen nodig voor Visual C++
//#define _CRT_SECURE_NO_WARNINGS
//#include "stdafx.h"

// Test programma voor class graaf_t
#include <iostream>
#include <string>
#include "graaf_t.h"
using namespace std;

int main()
{
	graaf_t			G ("Test");
	kortste_pad_t	kortste_pad;

	G.voeg_knooppunt_toe ("a");
	G.voeg_knooppunt_toe ("b");
	G.voeg_knooppunt_toe ("c");
	G.voeg_kant_toe ("a", "b", 10);
	G.voeg_kant_toe ("b", "c", 20);
	G.voeg_kant_toe ("a", "c", 50);
	G.print_graaf();

	cout << "\nStart Dijkstra's algoritme van a naar c\n";
	kortste_pad	= G.dijkstra ("a", "c");
	cout << "Kortste pad:\t\t" << kortste_pad.pad << "\n";
	cout << "Lengte van dit pad:\t" << kortste_pad.lengte << "\n";

	return 0;
}
