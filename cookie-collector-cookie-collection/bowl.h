#include <SFML/Graphics.hpp>

class Bowl
{
    private:
        sf::RectangleShape* body;
        int current_cookies;
        int total_cps;
        int total_cookies;
    public:
        Bowl(){
            body = new sf::RectangleShape(sf::Vector2f(150, 30));
            body->setFillColor(sf::Color(105, 40, 15, 255));
            body->setPosition(500, 1000);
            body->setOrigin(75,15);

            current_cookies = 0;
            total_cps = 0;
            total_cookies = 0;
        }
        sf::Vector2f get_position(){ return body->getPosition(); }
        
        int get_current_cookies(){return current_cookies;}


        void move_left(){
            if (body->getPosition().x > 150)
                body->move(-0.4, 0);
        }
        void move_right(){
            if (body->getPosition().x < 850)
                body->move(0.4, 0);
        }
        void increment_cookies(int value){
            current_cookies += value;
        }

        void set_current_cookies(int new_current){
            current_cookies = new_current;
        }

        void draw(sf::RenderWindow* win){
            win->draw(*body);       
        }

        ~Bowl(){
            delete body;
        };
};
