#ifndef APPLICATION_HPP
#define APPLICATION_HPP

#include "Widget.hpp"
#include <vector>

class application {
protected:
    std::vector<Widget*> widgets;
    int focus;
public:
    application();
    virtual ~application();
    void register_widget(Widget* w);
    void event_loop();
    virtual void save_action() = 0;
};

#endif