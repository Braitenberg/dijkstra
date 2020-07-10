// Alleen nodig voor Visual C++
#define _CRT_SECURE_NO_WARNINGS
#include "stdafx.h"

// Test programma voor class graaf_t
#include <iostream>
#include <string>
using namespace std;

#include "graaf_t.h"

void main()
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
}
