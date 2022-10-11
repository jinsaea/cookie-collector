#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>
#include <random>

#include "cookie.h"
#include "bowl.h"

using namespace sf;

class cookie_collector{
    private:
        RenderWindow* win;
        Vector2i* Mpos;

        Cookie* choc_chip;
        Cookie* chocolate;
        Cookie* macadamia;

        Bowl* bowl;

        sf::Text cookie_display;
        sf::Font font;
    public:
        cookie_collector(){
            win = new RenderWindow(VideoMode(1920,1080), 
            "Cookie Collector: The best game ever by Jordan and Sebastian");
            
            spawn_choc_chip(1);

            bowl = new Bowl();

            cookie_display.setFont(font);
            cookie_display.setFillColor(sf::Color::White);
            cookie_display.setCharacterSize(20);
            if(!font.loadFromFile("./font.ttf")){
                std::cout << "Font not found\n";
                exit(0);
            }
        }

        void spawn_choc_chip(int value){
            choc_chip = new Cookie[20];
            for (int i = 0; i < 20; i++)
            {
                choc_chip[i].set_cookie_value(value);
                choc_chip[i].spawn(1920, true);
            }
        }

        void spawn_chocolate(){

        }

        void spawn_macadamia(){

        }

        void get_mouse_position(){
            //get the mouse position relative to the window
            Mpos->x = Mouse::getPosition(*win).x * 1920/win->getSize().x;
            Mpos->y = Mouse::getPosition(*win).y * 1080/win->getSize().y;
            
            std::cout << Mpos->x << " " << Mpos->y << std::endl; //outputs mouse coords
        }

        void run(){
            while (win->isOpen())
            {   
                Event e;
                
                while (win->pollEvent(e))
                {
                    if(e.type == Event::Closed){
                        win->close();
                    }
                }

                //bowl movement
                if(Keyboard::isKeyPressed(Keyboard::A) || 
                   Keyboard::isKeyPressed(Keyboard::Left))
                    bowl->move_left();
                else if(Keyboard::isKeyPressed(Keyboard::D) ||
                        Keyboard::isKeyPressed(Keyboard::Right))
                    bowl->move_right();

                //bowl/cookie collision
                for (int i = 0; i < 20; i++)
                {
                    if(choc_chip[i].get_position().x < bowl->get_position().x + 100 &&
                       choc_chip[i].get_position().x > bowl->get_position().x - 100 &&
                       choc_chip[i].get_position().y > 960 &&
                       choc_chip[i].get_position().y < 980){
                        if(choc_chip[i].get_cookie_type().compare("choc chip"))
                        bowl->increment_cookies(1);
                        choc_chip[i].spawn(1920, false);
                    }
                }

                //display the cookie count
                std::string msg = "Cookies: " + 
                                   std::to_string(bowl->get_current_cookies());
                cookie_display.setString(msg);

                //draw the window and objects
                win->clear();
                for (int i = 0; i < 20; i++)
                {
                    choc_chip[i].draw(win);
                }
                bowl->draw(win);
                win->draw(cookie_display);
                win->display();
            }
        }

        ~cookie_collector(){
            delete win;
            delete[] choc_chip;
            delete bowl;
            delete Mpos;
        }
};

int main(){
    cookie_collector game;
    game.run();

    return 0;
}