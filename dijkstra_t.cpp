#include <iostream>
#include "graaf_t.h"
#include "dijkstra_t.h"

using namespace std;

dijkstra_tabel::dijkstra_tabel(int arg_aantal, int van) {
  // Constructor bij deze objectklasse, initialiseert de
  // interne variabelen van een object. Initialiseert ook de
  // kolommen van de tabel (de stap init van Dijkstra's algoritme),
  // daarvoor is de index van het beginknooppunt (van) nodig).

  // de tabel zit als volgt in elkaar:
  // [
  //   [ AFSTAND, VORIG_KN, AFGEHANDELD ]
  //   ...
  // ] -rb

  aantal_kol = arg_aantal;

  // Initialiseer de dijkstra tabel gevuld met "oneindig", en 0 voor het startpunt. -rb
  for(int i = 0; i < aantal_kol; i++) {
    Dijkstra_t new_line = { ONEINDIG, 0, false };
    if (i == van) { new_line.min_len = 0; }
    kol[i] = new_line;
  };
}

int	dijkstra_tabel::aantal_afgehandeld() {
  //Retourneert het aantal knooppunten waarvoor afgehandeld waar is.
  int counter = 0;

  for(int i = 0; i < aantal_kol; i++) {
    counter += is_afgehandeld(i);
  }

  return counter;
};

bool dijkstra_tabel::is_afgehandeld(int knooppunt) {
  // Retourneert een logische waarde die zegt of knooppunt knooppunt al is afgehandeld.
  return kol[knooppunt].afgehandeld;
};

int	dijkstra_tabel::min_len(int knooppunt) {
  // Retourneert de kortste lengte tot nu toe voor knooppunt.
  return kol[knooppunt].min_len;
};

int	dijkstra_tabel::vorig(int knooppunt) {
  // Retourneert de index van het voorgaande knooppunt via welk de kortste
  // lengte tot nu toe van knooppunt gevonden is.
  return kol[knooppunt].min_len;
};

void dijkstra_tabel::zet_afgehandeld(int knooppunt) {
  // Zet de status van knooppunt als afgehandeld.
  kol[knooppunt].afgehandeld = true;
};

void dijkstra_tabel::zet_nw_len(int knooppunt, int nw_len, int vorig_kn) {
  // Wijzigt de kortste lengte tot nu toe voor knooppunt;
  // wijzigt ook het voorgaande knooppunt
  kol[knooppunt].min_len = nw_len;
};

int	dijkstra_tabel::kol_min_len_niet_afgeh() {
  // Vindt de index van het knooppunt met de kortste lengte dat
  // niet afgehandeld is.
  int minimum = ONEINDIG;
  int result  = 0;

  for (int i = 0; i < aantal_kol; i++) {
    if (result > kol[i].min_len) {
      minimum = kol[i].min_len;
      result  = i;
    }
  }
  return result;
};

void dijkstra_tabel::print_tabel() {
  // Print de inhoud van de interne variabelen naar het scherm.
  // TODO
};
