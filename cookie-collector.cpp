#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>
#include <random>
#include <vector>

#include "cookie.h"
#include "bowl.h"
//#include "upgrade_spawn_rate.h" only include once store class is done, also write ifndef for headers

using namespace sf;

class cookie_collector{
    private:
        RenderWindow* win;
        Vector2i* Mpos;

        Cookie** cookie;

        Cookie* choc_chip;
        Cookie* chocolate;
        Cookie* macadamia;

        int* num_of_cookies;

        Bowl* bowl;

        sf::Text cookie_display;
        sf::Font font;
    public:
        cookie_collector(){
            win = new RenderWindow(VideoMode(1920,1080), 
            "Cookie Collector: The best game ever by Jordan and Sebastian");
            win->setFramerateLimit(60);

            cookie = new Cookie*[3];
            
            cookie[0] = choc_chip;
            cookie[1] = chocolate;
            cookie[2] = macadamia;

            num_of_cookies = new int[3];
            num_of_cookies[0] = 5;
            num_of_cookies[1] = 2;
            num_of_cookies[2] = 0;
            
            spawn_choc_chip(1, num_of_cookies[0]);
            spawn_chocolate(2, num_of_cookies[1]);
            spawn_macadamia(5, num_of_cookies[2]);

            bowl = new Bowl();

            cookie_display.setFont(font);
            cookie_display.setFillColor(sf::Color::White);
            cookie_display.setCharacterSize(20);
            if(!font.loadFromFile("./font.ttf")){
                std::cout << "Font not found\n";
                exit(0);
            }
        }

        //spawn the cookies
        void spawn_choc_chip(int value, int amount){
            choc_chip = new Cookie[amount];
            for (int i = 0; i < amount; i++)
            {
                choc_chip[i].set_cookie_value(value);
                choc_chip[i].set_cookie_colour(sf::Color(230, 189, 115, 255));
                choc_chip[i].set_type("choc chip");
                choc_chip[i].spawn(1920, true);
            }
        }
        void spawn_chocolate(int value, int amount){
            chocolate = new Cookie[amount];
            for (int i = 0; i < amount; i++)
            {
                chocolate[i].set_cookie_value(value);
                chocolate[i].set_cookie_colour(sf::Color::Red);
                chocolate[i].spawn(1920, true);
            }
        }
        void spawn_macadamia(int value, int amount){
            macadamia = new Cookie[amount];
            for (int i = 0; i < amount; i++)
            {
                macadamia[i].set_cookie_value(value);
                macadamia[i].set_cookie_colour(sf::Color::Blue);
                macadamia[i].spawn(1920, true);
            }
        }

        void get_mouse_position(){
            //get the mouse position relative to the window
            Mpos->x = Mouse::getPosition(*win).x * 1920/win->getSize().x;
            Mpos->y = Mouse::getPosition(*win).y * 1080/win->getSize().y;
            
            std::cout << Mpos->x << " " << Mpos->y << std::endl; //outputs mouse coords
        }

        //bowl/cookie collision
        void detect_collision(Cookie* cookie, int num_of_cookies){
            for (int i = 0; i < num_of_cookies; i++)
            {
                if(cookie[i].get_position().x < bowl->get_position().x + 100 &&
                cookie[i].get_position().x > bowl->get_position().x - 100 &&
                cookie[i].get_position().y > 960 &&
                cookie[i].get_position().y < 980){
                    bowl->increment_cookies(cookie->get_cookie_value());
                    cookie[i].spawn(1920, false);
                }
            }
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

                //move the bowl
                if(Keyboard::isKeyPressed(Keyboard::A) || 
                   Keyboard::isKeyPressed(Keyboard::Left))
                    bowl->move_left();
                else if(Keyboard::isKeyPressed(Keyboard::D) ||
                        Keyboard::isKeyPressed(Keyboard::Right))
                    bowl->move_right();

                detect_collision(choc_chip, num_of_cookies[0]);
                detect_collision(chocolate, num_of_cookies[1]);
                detect_collision(macadamia, num_of_cookies[2]);

                //display the cookie count
                std::string msg = "Cookies: " + 
                                   std::to_string(bowl->get_current_cookies());
                cookie_display.setString(msg);

                //draw the window and objects
                win->clear();

                for (int i = 0; i < num_of_cookies[0]; i++)
                    choc_chip[i].draw(win);
                for (int i = 0; i < num_of_cookies[1]; i++)
                    chocolate[i].draw(win);
                for (int i = 0; i < num_of_cookies[2]; i++)
                    macadamia[i].draw(win);

                //std::cout << &cookie[0][0] << " " << &choc_chip[0] << std::endl;

                //if click on upgrade spawn rate, run set_spawn_rate then the spawn function again

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
            delete cookie;
            delete choc_chip;
            delete macadamia;
            delete chocolate;
        }
};

int main(){
    cookie_collector game;
    game.run();

    return 0;
}