#include <SFML/Graphics.hpp>
#include <string>
#include <time.h>
#include <random>

class Cookie{
    private:
        int value;
        sf::CircleShape* body;
        std::string cookie_type;
        sf::Color cookie_colour;
        float* spawn_rate;
        bool collected;
        
    public:
        Cookie(){
            body = new sf::CircleShape(25);
            body->setFillColor(sf::Color(230, 189, 115, 255));
            body->setPosition(-50,-50);
            body->setOrigin(25,25);
            //this->cookie_type = cookie_type;
            collected = true;
            value = 1;

            srand(time(0));
        }
        
        Cookie(std::string type) : Cookie(){
            if(type.compare("choc chip")){
                value = 1;
                body->setFillColor(sf::Color(230, 189, 115, 255));
            }
            else if(type.compare("chocolate")){
                value = 2;
                body->setFillColor(sf::Color::Red);
            }
            else if(type.compare("macadamia")){
                value = 5;
                body->setFillColor(sf::Color::Blue);
            }
        }

        void draw(sf::RenderWindow* win){
            if(!collected){
                body->move(0,6);
                win->draw(*body);
                if(body->getPosition().y > 1100) {
                    spawn(win->getSize().x, false);
                }
            }
        }

        //randomly sets the position of cookies when spawned/collected
        //if its the first spawn, place randomly along y, otherwise spawn at y = -25
        void spawn(int x, bool initial){
            if(!initial){
                body->setPosition(rand() % x*2/5 + 100, -25);
            } else {
                body->setPosition(rand() % x*2/5 + 100, rand() % 1080);
            }

            collected = false;
        }

        sf::Vector2f get_position(){
            return body->getPosition();
        }

        void set_type(std::string type) {cookie_type = type;}
        
        void set_cookie_value(int value){this->value = value;}
        int get_cookie_value(){return value;}
        void set_cookie_colour(sf::Color colour){body->setFillColor(colour);}

        std::string get_cookie_type(){return cookie_type;}

        void set_collected(bool collected) {
            this->collected = collected;
        }

        ~Cookie(){
            delete body;
        }
};