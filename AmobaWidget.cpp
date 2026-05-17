#include "AmobaWidget.hpp"
#include "graphics.hpp"

using namespace genv;

AmobaWidget::AmobaWidget(application* p, int x, int y, int cella_meret, JatekMester* jm) 
    : Widget(p, x, y, 7 * cella_meret, 6 * cella_meret), _jm(jm), _cella_meret(cella_meret), _hatterszin("Kek") {}

void AmobaWidget::draw() {
    gout << move_to(_x, _y - 20) << color(255, 255, 255);
    int ny = _jm->get_nyertes();
    if (ny == 1) gout << text("Piros nyert!");
    else if (ny == 2) gout << text("Sarga nyert!");
    else if (ny == 3) gout << text("Dontetlen!");
    else {
        if (_jm->get_jelenlegi_jatekos() == 1) gout << text("Piros (1) kovetkezik.");
        else gout << text("Sarga (2) kovetkezik.");
    }


    if (_hatterszin == "Zold") gout << color(0, 150, 0);
    else if (_hatterszin == "Szurke") gout << color(100, 100, 100);
    else if (_hatterszin == "Feher") gout << color(255, 255, 255);
    else if (_hatterszin == "Piros") gout << color(255, 0,0 );
    else gout << color(0, 0, 200);

    gout << move_to(_x, _y) << box(_size_x, _size_y);

    int pad = 4;
    for (int i = 0; i < 7; ++i) {
        for (int j = 0; j < 6; ++j) {
            int ertek = _jm->get_mezo(i, j);
            if (ertek == 0) gout << color(20, 20, 20);
            else if (ertek == 1) gout << color(255, 50, 50);
            else if (ertek == 2) gout << color(255, 255, 50);

            gout << move_to(_x + i * _cella_meret + pad, _y + j * _cella_meret + pad)
                 << box(_cella_meret - 2*pad, _cella_meret - 2*pad);
        }
    }
}

void AmobaWidget::handle(event ev) {
    if (ev.type == ev_mouse && ev.button == btn_left && is_selected(ev.pos_x, ev.pos_y)) {
        int oszlop = (ev.pos_x - _x) / _cella_meret;


        if (_jm->get_jelenlegi_jatekos() == 1 || !_jm->is_gepi_ellenfel()) {
            bool sikeres = _jm->dobas(oszlop);


            if (sikeres && _jm->is_gepi_ellenfel() && _jm->get_jelenlegi_jatekos() == 2 && _jm->get_nyertes() == 0) {
                _jm->gepi_lepes();
            }
        }
    }
}