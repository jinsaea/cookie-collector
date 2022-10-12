//#ifdef STORE_H
//#define STORE_H

#include <SFML/Graphics.hpp>

using namespace std;

class Store {
    protected:
        string name;
        int cost;
        bool locked;
        sf::RectangleShape* button;
    public:
        Store(){
            name = "Store";
            cost = 0;
            locked = false;
            button = new sf::RectangleShape(sf::Vector2f(700,120));
        }
        //virtual void buy_item();

        void create_button(int position, sf::Color color){
            button->setFillColor(color);
            button->setOrigin(sf::Vector2f(350,60));
            button->setPosition(sf::Vector2f(1570,position));
            button->setOutlineColor(sf::Color::White);
            button->setOutlineThickness(-3);
            //win->draw(*button);
        }

        void draw_button(sf::RenderWindow* win){
            win->draw(*button);
        }

        ~Store(){
            //delete[] button;

        }
};




//#endif
