// Alleen nodig voor Visual C++
// #define _CRT_SECURE_NO_WARNINGS
// #include "stdafx.h"

#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

#include "graaf_t.h"	// object-definitie en functie-prototypes

const	string	SCHEIDINGST1	= " ";
const	string	SCHEIDINGST2	= ",";
typedef	int		foutcode;
		string	foutmelding[] =
{
	"",
	"Ongeldig sleutelwoord",
	"Onjuist aantal argumenten",
	"Knooppunt onbekend",
	"Argument moet numeriek zijn",
	"Fout bij openen bestand of bestand niet gevonden",
	"Sleutelwoord graaf ontbreekt",
};

const foutcode	OK						= 0,
				ERROR_INVALID_KEYWORD	= 1,
				ERROR_INVALID_NO_ARGS	= 2,
				ERROR_NODE_UNKNOWN		= 3,
				ERROR_ARG_NOT_NUMERIC	= 4,
				ERROR_FILE_NOT_EXIST	= 5,
				ERROR_KEYWORD_MISSING	= 6;

const foutcode	FATAL_ERROR = ERROR_FILE_NOT_EXIST;

const int	NO_KEYWORDS = 4;
const int INVALID_KEYWORD_CODE = NO_KEYWORDS + 1; // -rb

const string	sleutelwoorden[] =
{
	"graaf",
	"knooppunt",
	"kant",
	"Dijkstra"
};

const string	NUMERICALS = "0123456789";

foutcode parse_regel		(string arg_regel);
foutcode parse_graaf		(string args);
foutcode parse_knooppunt	(string args);
foutcode parse_kant			(string args);
foutcode parse_Dijkstra		(string args);
int		zoek_sw (string arg_sw);
void	print_foutmelding (int regelnr, foutcode fout);

// globale variabelen en objecten
bool graaf_gedefinieerd = false;
graaf_t	G("naam"); // maak leeg graaf-object

int main() {
	string		file_name, ingelezen_regel;
	foutcode	error_no = OK;
	int			  regel_nr = 0;

	cout << "Geef naam bestand: ";
	cin >> file_name;

	ifstream inFile(file_name.c_str());
	if (! inFile.good())
	{
		error_no = ERROR_FILE_NOT_EXIST;
		print_foutmelding (0, error_no);
	}
	while (inFile && error_no < FATAL_ERROR)
	{
		getline (inFile, ingelezen_regel);
		regel_nr++;
		error_no = parse_regel(ingelezen_regel);
		if (error_no != OK)
			print_foutmelding(regel_nr, error_no);
	}
	if (error_no == OK)
		G.print_graaf();

	inFile.close();
	return (error_no);
}

foutcode parse_regel(string arg_regel) {
	size_t		i;
	string		sleutelw, args;
	foutcode	error_no = OK;

	// i is de index van het scheidingsteken -rb
	i = arg_regel.find (SCHEIDINGST1);

	if (i!=string::npos) // als het scheidingsteken is gevonden... -rb
	{
		// Hier invullen: splitsen van arg_regel in variabele sleutelw en variabele args
		// U kunt hiervoor de functie assign gebruiken.
		string sleutelw;
		string arg;

		sleutelw.assign(arg_regel, 0, i);  //todo: ervoor zorgen dat dit geen segfault veroorzaakt
		arg.assign     (arg_regel, i, string::npos);

		// Start corresponderende functie om opdracht te parsen
		// Hier invullen: case-statements

		int sw_num = zoek_sw(sleutelw);

		switch (sw_num) {
			case 0:
				// hernoem de graaf -rb
				G.zet_naam(arg);
				break;

			case 1:
				// voeg_knooppunt_toe aan graaf -rb
				parse_knooppunt(arg);
				break;

			case 2:
				// voeg_kant_toe aan graaf -rb
				parse_kant(arg);
				break;

			case 3:
				// roep dijkstra aan op graaf -rb
				parse_Dijkstra(arg);
				break;

			 case INVALID_KEYWORD_CODE:
				 error_no = ERROR_INVALID_KEYWORD;
				 break;
		}
	}
	return error_no;
}

int zoek_sw(string arg_sw) {
	// Hier invullen: code om index van sleutelwoord te vinden uit de array
	int sw_index = INVALID_KEYWORD_CODE;
	// een loop die de sleutelwoorden doorloopt -rb
	for (int i = 0; i < NO_KEYWORDS; i++) {
		// als het sleutelwoord is gevonden, geef de index terug -rb
		if (arg_sw == sleutelwoorden[i]) {
			sw_index = i;
		}
	}
	return(sw_index);
}

foutcode parse_graaf(string args) {
	if (graaf_gedefinieerd)
		return (ERROR_INVALID_KEYWORD);
	else {
		graaf_gedefinieerd = true;
		G.zet_naam(args);
		return (OK);
	}
}

foutcode parse_knooppunt(string args) {
	if (!graaf_gedefinieerd)
		return (ERROR_KEYWORD_MISSING);
	else {
		G.voeg_knooppunt_toe(args);
		return (OK);
	}
}

foutcode parse_kant(string args) {
	string str_arg[4], rest;
	size_t	i;
	int		j=0;
	foutcode error_no = OK;

	rest	= args;
	i		= rest.find (SCHEIDINGST2);
	while (i!=string::npos && j < 3)
	{
		str_arg[j].assign (rest, 0, i);
		rest.erase (0, i+1);
		i = rest.find (SCHEIDINGST2);
		j++;
	}
	str_arg[j] = rest;
	if (j != 2)
		return (ERROR_INVALID_NO_ARGS);
	else {
		i = str_arg[2].find_first_not_of(NUMERICALS);
		if (i!=string::npos)
			return (ERROR_ARG_NOT_NUMERIC);
		else
		{
			// Hier invullen: controle of knooppunt-labels bestaan in graaf-object
			if (G.zoek_knooppunt(str_arg[2])) {
				// Zoja, terugkeren met foutcode OK
				error_no = OK;
			} else {
			  // Zonee, terugkeren met foutcode ERROR_NODE_UNKNOWN
				error_no = ERROR_NODE_UNKNOWN;
			}
		}
	}
	return error_no;
}

foutcode parse_Dijkstra(string args) {
	// Hier invullen: alle code voor de implementatie van deze functie
	// Gebruik de code bij de functie parse_kant als voorbeeld.
	return 0;
}

void print_foutmelding (int regelnr, foutcode fout) {
	cout << "Fout in regel " << regelnr << ": " << foutmelding[fout] << "\n";
}
