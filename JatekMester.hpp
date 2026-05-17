#ifndef JATEKMESTER_HPP
#define JATEKMESTER_HPP
const int OSZLOP = 7;
const int SOR = 6;
class JatekMester {
private:
    int _tabla[OSZLOP][SOR];
    int _jelenlegi_jatekos; 
    int _nyertes;
    int _nyero_hossz;
    bool _gepi_ellenfel;
    void nyeres_ellenorzes(int oszlop, int sor);
    bool teszt_nyeres(int c, int r, int jatekos_id) const;
    int elso_szabad_sor(int oszlop) const;

public:
    JatekMester();

    bool dobas(int oszlop);
    void gepi_lepes();
    void uj_jatek(int nyero_hossz, bool gep);

    int get_mezo(int oszlop, int sor) const { return _tabla[oszlop][sor]; }
    int get_jelenlegi_jatekos() const { return _jelenlegi_jatekos; }
    int get_nyertes() const { return _nyertes; }
    bool is_gepi_ellenfel() const { return _gepi_ellenfel; }
};

#endif