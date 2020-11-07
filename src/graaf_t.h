#include <string>
using namespace std;

static const int MAX_AANT_KN = 100;
const int ONEINDIG = 9999;

struct kortste_pad_t {
	string	pad;
	int		lengte;
};

class graaf_t {

	private :
		int		aantal_kn;
		int 	aantal_knt;
		string	graaf_naam;
		string	kn_labels [MAX_AANT_KN]; // string.h gebruiken in hoofdprogramma
		int		matrix [MAX_AANT_KN][MAX_AANT_KN]; // tweedim. array, (rij, kolom)

	public :
				graaf_t (string arg_naam);
		void	zet_naam (string arg_naam);
		void	voeg_knooppunt_toe (string arg_label);
		void	voeg_kant_toe (string van_label, string naar_label, int gewicht);
		int 	zoek_knooppunt (string arg_label);
		void 	print_graaf ();
		int * vind_kanten (int index);
		kortste_pad_t dijkstra (string van_label, string naar_label);
};
