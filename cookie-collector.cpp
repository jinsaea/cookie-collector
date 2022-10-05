#include <SFML/Graphics.hpp>
#include <string>

using namespace sf;

class cookie_collector{
    private:
        RenderWindow* win;
    public:
        cookie_collector(){
        }

        void run(){
            while (win->isOpen())
            {
                Event e;
                while (win->pollEvent(e))
                {
                    if(e.type == Event::Closed){
                        //win->close();
                    }
                }
                win->clear();
                win->display();
            }
        }

};

int main(){
    cookie_collector game;
    game.run();

    return 0;
}