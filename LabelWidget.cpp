#include "LabelWidget.hpp"
#include "graphics.hpp"

using namespace genv;

LabelWidget::LabelWidget(application* p, int x, int y, std::string szoveg) 
    : Widget(p, x, y, 0, 0), _szoveg(szoveg) {}

void LabelWidget::draw() {

    gout << move_to(_x, _y) << color(255, 255, 255) << text(_szoveg);
}

void LabelWidget::handle(event ev) {

}