#ifndef MENUSTATE_H_INCLUDED
#define MENUSTATE_H_INCLUDED
#include "State.h"
#include "Button.h"

class StateManager;
class MenuState: public State {
private:
    StateManager* sm;
    bool isActive;
    Button join;
    Button host;
    Button options;
    Button exit;
    int cover;
    sf::RenderWindow window2;
public:
    MenuState(StateManager* sm);
    void handleInput(int u, int v);
    void update(float dt);
    void draw(sf::RenderWindow& window) const;
};

#endif // MENUSTATE_H_INCLUDED
