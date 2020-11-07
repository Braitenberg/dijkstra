struct Dijkstra_t {
	bool	afgehandeld;
	int		min_len;
	int		vorig_kn;
};

class dijkstra_tabel {

	private :
		int			aantal_kol;
		Dijkstra_t	kol [MAX_AANT_KN];

	public :
				dijkstra_tabel (int arg_aantal, int van);
		int		aantal_afgehandeld ();
		bool	is_afgehandeld (int knooppunt);
		int		min_len (int knooppunt);
		int		vorig (int knooppunt);
		void	zet_afgehandeld (int knooppunt);
		void	zet_nw_len (int knooppunt, int nw_len, int vorig_kn);
		int		kol_min_len_niet_afgeh ();
		void	print_tabel ();
};
