#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>
#include "Store.h"


using namespace sf;

using namespace std;

class cookie_collector{
    private:
        RenderWindow* win;
        Vector2i* Mpos;
        RectangleShape* button;
        Store store;
    public:

        
        cookie_collector(){
            win = new RenderWindow(VideoMode(1920,1080), 
            "Cookie Collector: The best game ever by Jordan and Sebastian",
            Style::Fullscreen);
            //Store store;
            store.create_button(60, sf::Color::Yellow);
            //store.draw_button(win);
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

        
            Font font;
            if ( !font.loadFromFile("greback_grotesque/GrebackGrotesquePERSONAL-Regular.otf") ) {
                std::cout << "Error loading font" << std::endl;
            }
            



            //get_mouse_position();

            // if(Mpos->x < button->getPosition().x+100 
            //    && Mpos->x > button->getPosition().x-100
            //    && Mpos->y < button->getPosition().y+100 
            //    && Mpos->y > button->getPosition().y-100
            //    && Mouse::isButtonPressed(Mouse::Left)) {
            //     //flash the button
            //     if (button->getFillColor() == Color::Red)
            //         button->setFillColor(Color::Blue);
            //     else
            //         button->setFillColor(Color::Red);
            // }

                //std::cout << win->getSize().x << std::endl;

                //draw the window and objects
                win->clear();
                store.draw_button(win);
                // win->draw(button);
                // win->draw(button2);
                // win->draw(button3);
                // win->draw(button4);
                // win->draw(button5);
                // win->draw(button6);
                // win->draw(button7);
                // win->draw(button8);
                // win->draw(button9);
                // win->draw(store);
                // win->draw(building);
                // win->draw(building1);
                // win->draw(building2);
                // win->draw(building3);
                // win->draw(upgrades);
                // win->draw(upgrades1);
                // win->draw(upgrades1_1);
                // win->draw(upgrades1_2);
                // win->draw(upgrades1_3);
                // win->draw(upgrades2);
                // win->draw(upgrades2_1);
                // win->draw(upgrades2_2);
                // win->draw(upgrades2_3);
                // win->draw(upgrades3);
                // win->draw(upgrades3_1);
                // win->draw(upgrades3_2);
                // win->draw(upgrades3_3);
                win->display();
            }
        }

};

int main(){
    cookie_collector game;
    game.run();

    return 0;
}