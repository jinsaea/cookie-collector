#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>
#include <random>


#include "cookie.h"
#include "Building.h"

using namespace sf;

class cookie_collector{
    private:
        RenderWindow* win;
        int Mposx;
        int Mposy;
        int current_cookies;

        Cookie* choc_chip;
        Cookie* chocolate;
        Cookie* macadamia;

        Bowl* bowl;

        sf::Text cookie_display;
        sf::Font font;
        Store store;
        Building Grandma;
        Building Farm;
        Building Factory;
    public:
        cookie_collector(){
            win = new RenderWindow(VideoMode(1920,1080), 
            "Cookie Collector: The best game ever by Jordan and Sebastian");
            
            spawn_choc_chip(1);
            //Building Grandma(1,5);


            cookie_display.setFont(font);
            cookie_display.setFillColor(sf::Color::White);
            cookie_display.setCharacterSize(20);
            if(!font.loadFromFile("./font.ttf")){
                std::cout << "Font not found\n";
                exit(0);
            }
            

            store.create_button(60, sf::Color::Yellow);

            Grandma.create_button(180, sf::Color::Red);

            Farm.create_button(300, sf::Color::Red);

            Factory.create_button(420,sf::Color::Red);

            bowl = new Bowl();


            // store->create_text("Store", 60, 1570, 60, font);
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
            Mposx = Mouse::getPosition(*win).x * 1920/win->getSize().x;
            Mposy = Mouse::getPosition(*win).y * 1080/win->getSize().y;
            
            //std::cout << Mpos->x << " " << Mpos->y << std::endl; //outputs mouse coords
        }

        void run(){
            // sf::Clock Clock;
	        // float Time = Clock.getElapsedTime();
	        // Clock.restart();
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

                get_mouse_position();

                //Checking if buttons are right or left clicked by the mouse and then either buying or selling an item
                if(Grandma.is_mouse_present(Mposx,Mposy,1570,180) == true){
                    if(Mouse::isButtonPressed(Mouse::Left)){
                    Grandma.buy_item(bowl);
                    }
                    if(Mouse::isButtonPressed(Mouse::Right)){
                        Grandma.sell_building(bowl);
                    }
                }

                

                // if(Time >= 1000){

                //     current_cookies = bowl->get_current_cookies() + Grandma.get_total_cps();
                //     bowl->set_current_cookies(current_cookies);
                // }
                


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
                store.draw_button(win);
                // store->draw_text(win);
                Grandma.draw_button(win);
                Farm.draw_button(win);
                Factory.draw_button(win);
                win->display();
            }
        }

        ~cookie_collector(){
            delete win;
            delete[] choc_chip;
            delete bowl;
            //delete Mposx;
        }
};

int main(){
    cookie_collector game;
    game.run();

    return 0;
}