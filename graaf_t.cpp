#include "graaf_t.h"

graaf_t::graaf_t(string arg_naam) {
  graaf_naam = arg_naam;
}

void graaf_t::zet_naam (string arg_naam) {

}

void graaf_t::voeg_knooppunt_toe (string arg_label) {

}

void graaf_t::voeg_kant_toe (string van_label, string naar_label, int gewicht) {

}

int graaf_t::zoek_knooppunt (string arg_label) {
  return 0;
}

void graaf_t::print_graaf() {

}

int graaf_t::Dijkstra (string van_label, string naar_label) {
  return 0; //todo: zou een kortste_pad_t moeten teruggeven
}
