#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>

using namespace sf;

class cookie_collector{
    private:
        RenderWindow* win;
        Vector2i* Mpos;
    public:
        cookie_collector(){
            win = new RenderWindow(VideoMode(1920,1080), 
            "Cookie Collector: The best game ever by Jordan and Sebastian",
            Style::Fullscreen);
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

            get_mouse_position();

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
                //win->draw(*button);
                win->display();
            }
        }

};

int main(){
    cookie_collector game;
    game.run();

    return 0;
}