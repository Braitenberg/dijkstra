#include <iostream>
#include "graaf_t.h"
#include "dijkstra_t.h"
using namespace std;

graaf_t::graaf_t(string arg_naam) {
  // Constructor bij deze objectklasse, initialiseert de interne
  // variabelen van een object (dus ook de verbindingsmatrix!).

  aantal_kn = 0;
  graaf_naam = arg_naam;
}

void graaf_t::zet_naam (string arg_naam) {
  // Wijzigt de interne variabele naam_graaf.
  graaf_naam = arg_naam;
}

int graaf_t::zoek_knooppunt (string arg_label) {
  // Zoekt naar het label van het knooppunt in de array
  // kn_labels. Retourneert de bijbehorende index van de array
  // kn_labels of de waarde ONEINDIG als het label niet wordt gevonden.
  int found = ONEINDIG;

  for(int i = 0; i < aantal_kn; i++) {
    if (kn_labels[i] == arg_label) {
      found = i;
      break;
    }
  }

  return found;
}

void graaf_t::voeg_knooppunt_toe (string arg_label) {
  // Verhoogt aantal_knooppunten met 1 en slaat het label
  // van het nieuwe knooppunt op in de array kn_labels.
  kn_labels[aantal_kn] = arg_label;
  aantal_kn++;
}

void graaf_t::voeg_kant_toe (string van_label, string naar_label, int gewicht) {
  // Slaat het gewicht van de nieuwe kant op in de juiste
  // elementen van de verbindingsmatrix (dus tweemaal!).
  matrix[zoek_knooppunt(van_label)][zoek_knooppunt(naar_label)] = gewicht;
  matrix[zoek_knooppunt(naar_label)][zoek_knooppunt(van_label)] = gewicht;
}

void graaf_t::print_graaf() {
  // Print de inhoud van de interne variabelen naar het scherm.
  string knooppunten = "";
  string kanten      = "";

  // formateer de knooppunten -rb
  for(int i = 0; i < aantal_kn; i++) {
    knooppunten += kn_labels[i];
    if (i != (aantal_kn - 1)) {
      knooppunten += ", ";
    }
  }

  // formateer de matrix -rb
  for(int i = 0; i < aantal_kn; i++) {
    for(int j = 0; j < aantal_kn; j++) {
      kanten += to_string(matrix[i][j]);
      if (j != 3) {
        kanten += '\t';
      }
    }
    if (i != (aantal_kn - 1)) {
      kanten += '\n';
    }
  }

  cout << "Naam graaf:"         << "\t\t" << graaf_naam  << "\n";
  cout << "Aantal knooppunten:" << "\t" << aantal_kn   << "\n";
  cout << "Knooppunten:"        << "\t\t" << knooppunten << "\n";
  cout << kanten << '\n';
}

kortste_pad_t graaf_t::dijkstra (string van_label, string naar_label) {
  // Vindt het kortste pad in de graaf van knooppunt van_label
  // naar knooppunt naar_label.
  // dijkstra_t D(aantal_kn, van_label);

  // vul de tabel
  // voor ieder knooppunt, bereken de afstand tussen het knooppunt met van_label
  // en het knooppunt met naar_label

  dijkstra_tabel T(aantal_kn, zoek_knooppunt(van_label));

  kortste_pad_t pad = { "NULL", 0 };
  return pad; //todo: zou een kortste_pad_t moeten teruggeven
}
