#ifndef AMOBAWIDGET_HPP
#define AMOBAWIDGET_HPP

#include "Widget.hpp"
#include "JatekMester.hpp"
#include <string>

class AmobaWidget : public Widget {
private:
    JatekMester* _jm;
    int _cella_meret;
    std::string _hatterszin;
public:
    AmobaWidget(application* p, int x, int y, int cella_meret, JatekMester* jm);
    virtual void draw() override;
    virtual void handle(genv::event ev) override;
    void set_szin(std::string uj_szin) { _hatterszin = uj_szin; }
};

#endif