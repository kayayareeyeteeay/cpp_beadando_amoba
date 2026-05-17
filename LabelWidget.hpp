#ifndef LABELWIDGET_HPP
#define LABELWIDGET_HPP

#include "Widget.hpp"
#include <string>

class LabelWidget : public Widget {
private:
    std::string _szoveg;
public:
    LabelWidget(application* p, int x, int y, std::string szoveg);
    
    virtual void draw() override;
    virtual void handle(genv::event ev) override;
};

#endif