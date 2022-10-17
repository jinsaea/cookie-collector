//#ifdef STORE_H
//#define STORE_H

#include <SFML/Graphics.hpp>
#include <iostream>

using namespace std;

class Store {
    protected:
        string name;
        bool mouse_present;
        sf::RectangleShape* button;
        sf::Text* text;
    public:
        Store(){
            name = "Store";
            mouse_present = false;
            button = new sf::RectangleShape(sf::Vector2f(700,120));
            
            

        }

    
        virtual void buy_item(){

        }

        void create_button(int position, sf::Color color){
            button->setFillColor(color);
            button->setOrigin(sf::Vector2f(350,60));
            button->setPosition(sf::Vector2f(1570,position));
            button->setOutlineColor(sf::Color::White);
            button->setOutlineThickness(-3);
            //win->draw(*button);
        }

        void create_text(std::string textName, int size, int xposition, int yposition, sf::Font font){
            sf::Text text(textName, font);
            text.setCharacterSize(size);
            text.setFillColor(sf::Color::Black);
            text.setStyle(sf::Text::Bold);
            text.setOrigin(sf::Vector2f(50,30));
            text.setPosition(sf::Vector2f(xposition,yposition));
        }

        bool is_mouse_present(int Mposx, int Mposy, int xpos, int ypos){
            if(Mposx < xpos+350 
               && Mposx > xpos-350
               && Mposy < ypos+60 
               && Mposy > ypos-60){
                return true;
               }
               else{
                return false;
               }
               return false;
        }

        void draw_button(sf::RenderWindow* win){
            win->draw(*button);
        }

        void draw_text(sf::RenderWindow* win){
            win->draw(*text);
        }

        ~Store(){
            // delete[] button;
            // delete[] text;

        }
};




//#endif
