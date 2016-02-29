#include "Universal.h"
#include "StateSubclass.h"
#include "StateManager.h"
#include <iostream>


MenuState::MenuState(StateManager *sm):
sm(sm),
join(Button(sf::Vector2f(window_width/2.0, window_height/2.0 + 50), sf::Vector2f(100, 20), "Join Game")),
host(Button(sf::Vector2f(window_width/2.0, window_height/2.0 + 100), sf::Vector2f(100, 20), "Host Game")),
options(Button(sf::Vector2f(window_width/2.0, window_height/2.0 + 150), sf::Vector2f(100, 20), "Options")),
exit(Button(sf::Vector2f(window_width/2.0, window_height/2.0 + 200), sf::Vector2f(100, 20), "Exit"))
{
    cover = 255;
}

void MenuState::update(float dt)
{
    if(cover==0) return;
    int temp = cover - (255*dt);
    cover = std::max(temp, 0);
}

void MenuState::handleInput(int u, int v)
{
    bool leftClick = sf::Mouse::isButtonPressed(sf::Mouse::Left);
    if(leftClick && cover > 0) {
        cover = 0;
        return;
    }
    if(join.checkCollision(u, v) && leftClick){

    }
    if(host.checkCollision(u, v) && leftClick) {

    }
    if(options.checkCollision(u, v) && leftClick) {

    }
    if(exit.checkCollision(u, v) && leftClick) {

    }
}

void MenuState::draw(sf::RenderWindow &window) const
{
    join.draw(window);
    host.draw(window);
    options.draw(window);
    exit.draw(window);

    if(cover==0) return;
    sf::Vector2f curtainSize(800, 600);
    sf::RectangleShape curtain(curtainSize);
    curtain.setPosition(0, 0);
    curtain.setFillColor(sf::Color(0, 0, 0, cover));
    window.draw(curtain);
}