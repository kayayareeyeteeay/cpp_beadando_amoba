#include "JatekMester.hpp"
#include <cstdlib>
#include <ctime>

JatekMester::JatekMester() {
    srand(time(0));
    uj_jatek(4, false);
}

void JatekMester::uj_jatek(int nyero_hossz, bool gep) {
    _jelenlegi_jatekos = 1;
    _nyertes = 0;
    _nyero_hossz = nyero_hossz;
    _gepi_ellenfel = gep;
    for (int i = 0; i < OSZLOP; ++i) {
        for (int j = 0; j < SOR; ++j) {
            _tabla[i][j] = 0;
        }
    }
}

int JatekMester::elso_szabad_sor(int oszlop) const {
    for (int y = SOR-1; y >= 0; --y) {
        if (_tabla[oszlop][y] == 0) return y;
    }
    return -1;
}

bool JatekMester::dobas(int oszlop) {
    if (_nyertes != 0 || oszlop < 0 || oszlop >= OSZLOP) return false;

    int y = elso_szabad_sor(oszlop);
    if (y != -1) {
        _tabla[oszlop][y] = _jelenlegi_jatekos;
        nyeres_ellenorzes(oszlop, y);
        if (_nyertes == 0) {
            _jelenlegi_jatekos = (_jelenlegi_jatekos == 1) ? 2 : 1;
        }
        return true;
    }
    return false;
}


bool JatekMester::teszt_nyeres(int c, int r, int p) const {
    int iranyok[4][2] = {{1,0}, {0,1}, {1,1}, {1,-1}};
    for (int d = 0; d < 4; ++d) {
        int szamlalo = 1;
        for (int i = 1; i < _nyero_hossz; ++i) {
            int nx = c + iranyok[d][0] * i;
            int ny = r + iranyok[d][1] * i;
            if (nx >= 0 && nx < OSZLOP && ny >= 0 && ny < SOR && _tabla[nx][ny] == p) szamlalo++;
            else break;
        }
        for (int i = 1; i < _nyero_hossz; ++i) {
            int nx = c - iranyok[d][0] * i;
            int ny = r - iranyok[d][1] * i;
            if (nx >= 0 && nx < OSZLOP && ny >= 0 && ny < SOR && _tabla[nx][ny] == p) szamlalo++;
            else break;
        }
        if (szamlalo >= _nyero_hossz) return true;
    }
    return false;
}

void JatekMester::nyeres_ellenorzes(int c, int r) {
    if (teszt_nyeres(c, r, _tabla[c][r])) {
        _nyertes = _tabla[c][r];
        return;
    }


    bool tele = true;
    for (int i = 0; i < OSZLOP; ++i) {
        if (_tabla[i][0] == 0) { tele = false; break; }
    }
    if (tele) _nyertes = 3;
}

void JatekMester::gepi_lepes() {
    if (_nyertes != 0 || _jelenlegi_jatekos != 2) return;


    for (int c = 0; c < OSZLOP; ++c) {
        int r = elso_szabad_sor(c);
        if (r != -1 && teszt_nyeres(c, r, 2)) { dobas(c); return; }
    }


    for (int c = 0; c < OSZLOP; ++c) {
        int r = elso_szabad_sor(c);

        if (r != -1 && teszt_nyeres(c, r, 1)) { dobas(c); return; }
    }


    int r3 = elso_szabad_sor(3);
    if (r3 != -1 && r3 > 2) { dobas(3); return; }


    int c;
    do { c = rand() % OSZLOP; } while (elso_szabad_sor(c) == -1);
    dobas(c);
}