#include "application.hpp"
#include "AmobaWidget.hpp"
#include "NumericWidget.hpp"
#include "SelectorWidget.hpp"
#include "LabelWidget.hpp"
#include "JatekMester.hpp"
#include <vector>
#include <string>

using namespace std;

class AmobaApp : public application {
private:
    JatekMester jm;
    AmobaWidget* tabla;
    NumericWidget* nyero_hossz_widget;
    SelectorWidget* ellenfel_widget;
    SelectorWidget* szin_widget_;

public:
    AmobaApp() {
        tabla = new AmobaWidget(this, 20, 50, 50, &jm);


        new LabelWidget(this, 370, 40, "Gyozelemhez szukseges hossz:");
        nyero_hossz_widget = new NumericWidget(this, 400, 50, 150, 40, 4, 6);


        new LabelWidget(this, 400, 140, "Jatekmod kivalasztasa:");
        vector<string> modok = {"Ember vs Ember", "Ember vs Gep"};
        ellenfel_widget = new SelectorWidget(this, 400, 150, 150, 40, modok, 2);

        new LabelWidget(this, 400,280,"Palya hatterszine:");
        vector<string> szinek = {"Kek", "Zold", "Szurke", "Feher", "Piros"};
        szin_widget_ = new SelectorWidget(this, 400, 300, 150, 40, szinek, 5);


        new LabelWidget(this, 10, 400, "Beallitas alkalmazasa ES Uj jatek: ENTER");


        new LabelWidget(this, 10, 580, "Karita Arpad Ferenc - PZ7GGI");
    }

    virtual void save_action() override {
        int nyero_hossz = nyero_hossz_widget->get_num_value();
        bool gep = (ellenfel_widget->get_str_value() == "Ember vs Gep");
        string valasztott_szin = szin_widget_->get_str_value();

        tabla->set_szin(valasztott_szin);
        jm.uj_jatek(nyero_hossz, gep);
    }
};

int main() {
    AmobaApp app;
    app.event_loop();
    return 0;
}