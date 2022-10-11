#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>


using namespace sf;

class cookie_collector{
    private:
        RenderWindow* win;
        Vector2i* Mpos;
        RectangleShape* button;
    public:

        
        cookie_collector(){
            win = new RenderWindow(VideoMode(1920,1080), 
            "Cookie Collector: The best game ever by Jordan and Sebastian",
            Style::Fullscreen);
        }


        // void get_mouse_position(){
        //     //get the mouse position relative to the window
        //     Mpos->x = Mouse::getPosition(*win).x * 1920/win->getSize().x;
        //     Mpos->y = Mouse::getPosition(*win).y * 1080/win->getSize().y;
            
        //     //std::cout << Mpos->x << " " << Mpos->y << std::endl; //outputs mouse coords
        // }

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

            RectangleShape button(Vector2f(700,120));
            button.setFillColor(Color::Yellow);
            button.setOrigin(Vector2f(350,60));
            button.setPosition(Vector2f(1570,60));
            button.setOutlineColor(Color::White);
            button.setOutlineThickness(-3);

            Font font;
            if ( !font.loadFromFile("greback_grotesque/GrebackGrotesquePERSONAL-Regular.otf") ) {
                std::cout << "Error loading font" << std::endl;
            }
            Text store("Store", font);
            store.setCharacterSize(60);
            store.setFillColor(Color::Black);
            store.setStyle(Text::Bold);
            store.setOrigin(Vector2f(50,30));
            store.setPosition(Vector2f(1570,60));


            RectangleShape button2(Vector2f(700,120));
            button2.setFillColor(Color::Red);
            button2.setOrigin(Vector2f(350,60));
            button2.setPosition(Vector2f(1570,180));
            button2.setOutlineColor(Color::White);
            button2.setOutlineThickness(-3);

            Text building("Buildings", font);
            building.setCharacterSize(60);
            building.setFillColor(Color::Black);
            building.setStyle(Text::Bold);
            building.setOrigin(Vector2f(75,30));
            building.setPosition(Vector2f(1570,180));


            RectangleShape button3(Vector2f(700,120));
            button3.setFillColor(Color::Red);
            button3.setOrigin(Vector2f(350,60));
            button3.setPosition(Vector2f(1570,300));
            button3.setOutlineColor(Color::White);
            button3.setOutlineThickness(-3);

            Text building1("Building 1, Cost: ", font);
            building1.setCharacterSize(60);
            building1.setFillColor(Color::Black);
            building1.setStyle(Text::Bold);
            building1.setOrigin(Vector2f(160,30));
            building1.setPosition(Vector2f(1570,300));

            RectangleShape button4(Vector2f(700,120));
            button4.setFillColor(Color::Red);
            button4.setOrigin(Vector2f(350,60));
            button4.setPosition(Vector2f(1570,420));
            button4.setOutlineColor(Color::White);
            button4.setOutlineThickness(-3);

            Text building2("Building 2, Cost: ", font);
            building2.setCharacterSize(60);
            building2.setFillColor(Color::Black);
            building2.setStyle(Text::Bold);
            building2.setOrigin(Vector2f(160,30));
            building2.setPosition(Vector2f(1570,420));

            RectangleShape button5(Vector2f(700,120));
            button5.setFillColor(Color::Red);
            button5.setOrigin(Vector2f(350,60));
            button5.setPosition(Vector2f(1570,540));
            button5.setOutlineColor(Color::White);
            button5.setOutlineThickness(-3);

            Text building3("Building 3, Cost: ", font);
            building3.setCharacterSize(60);
            building3.setFillColor(Color::Black);
            building3.setStyle(Text::Bold);
            building3.setOrigin(Vector2f(160,30));
            building3.setPosition(Vector2f(1570,540));

            RectangleShape button6(Vector2f(700,120));
            button6.setFillColor(Color::Blue);
            button6.setOrigin(Vector2f(350,60));
            button6.setPosition(Vector2f(1570,660));
            button6.setOutlineColor(Color::White);
            button6.setOutlineThickness(-3);

            Text upgrades("Upgrades", font);
            upgrades.setCharacterSize(60);
            upgrades.setFillColor(Color::Black);
            upgrades.setStyle(Text::Bold);
            upgrades.setOrigin(Vector2f(95,30));
            upgrades.setPosition(Vector2f(1570,660));

            RectangleShape button7(Vector2f(700,120));
            button7.setFillColor(Color::Blue);
            button7.setOrigin(Vector2f(350,60));
            button7.setPosition(Vector2f(1570,780));
            button7.setOutlineColor(Color::White);
            button7.setOutlineThickness(-3);

            Text upgrades1("Increase Cookie Value", font);
            upgrades1.setCharacterSize(40);
            upgrades1.setFillColor(Color::Black);
            upgrades1.setStyle(Text::Bold);
            upgrades1.setOrigin(Vector2f(170,50));
            upgrades1.setPosition(Vector2f(1570,780));

            Text upgrades1_1("Macadamia", font);
            upgrades1_1.setCharacterSize(35);
            upgrades1_1.setFillColor(Color::Black);
            upgrades1_1.setStyle(Text::Bold);
            upgrades1_1.setOrigin(Vector2f(85,40));
            upgrades1_1.setPosition(Vector2f(1335,830));

            Text upgrades1_2("Choc Chip", font);
            upgrades1_2.setCharacterSize(35);
            upgrades1_2.setFillColor(Color::Black);
            upgrades1_2.setStyle(Text::Bold);
            upgrades1_2.setOrigin(Vector2f(80,40));
            upgrades1_2.setPosition(Vector2f(1570,830));

            Text upgrades1_3("Chocolate", font);
            upgrades1_3.setCharacterSize(35);
            upgrades1_3.setFillColor(Color::Black);
            upgrades1_3.setStyle(Text::Bold);
            upgrades1_3.setOrigin(Vector2f(80,40));
            upgrades1_3.setPosition(Vector2f(1785,830));

            RectangleShape button8(Vector2f(700,120));
            button8.setFillColor(Color::Blue);
            button8.setOrigin(Vector2f(350,60));
            button8.setPosition(Vector2f(1570,900));
            button8.setOutlineColor(Color::White);
            button8.setOutlineThickness(-3);

            Text upgrades2("Increase Cookie Spawn Rate", font);
            upgrades2.setCharacterSize(40);
            upgrades2.setFillColor(Color::Black);
            upgrades2.setStyle(Text::Bold);
            upgrades2.setOrigin(Vector2f(245,50));
            upgrades2.setPosition(Vector2f(1570,900));

            Text upgrades2_1("Macadamia", font);
            upgrades2_1.setCharacterSize(35);
            upgrades2_1.setFillColor(Color::Black);
            upgrades2_1.setStyle(Text::Bold);
            upgrades2_1.setOrigin(Vector2f(85,40));
            upgrades2_1.setPosition(Vector2f(1335,950));

            Text upgrades2_2("Choc Chip", font);
            upgrades2_2.setCharacterSize(35);
            upgrades2_2.setFillColor(Color::Black);
            upgrades2_2.setStyle(Text::Bold);
            upgrades2_2.setOrigin(Vector2f(80,40));
            upgrades2_2.setPosition(Vector2f(1570,950));

            Text upgrades2_3("Chocolate", font);
            upgrades2_3.setCharacterSize(35);
            upgrades2_3.setFillColor(Color::Black);
            upgrades2_3.setStyle(Text::Bold);
            upgrades2_3.setOrigin(Vector2f(80,40));
            upgrades2_3.setPosition(Vector2f(1785,950));

            RectangleShape button9(Vector2f(700,120));
            button9.setFillColor(Color::Blue);
            button9.setOrigin(Vector2f(350,60));
            button9.setPosition(Vector2f(1570,1020));
            button9.setOutlineColor(Color::White);
            button9.setOutlineThickness(-3);

            Text upgrades3("Increase Building Income", font);
            upgrades3.setCharacterSize(40);
            upgrades3.setFillColor(Color::Black);
            upgrades3.setStyle(Text::Bold);
            upgrades3.setOrigin(Vector2f(215,50));
            upgrades3.setPosition(Vector2f(1570,1020));

            Text upgrades3_1("Building 1", font);
            upgrades3_1.setCharacterSize(35);
            upgrades3_1.setFillColor(Color::Black);
            upgrades3_1.setStyle(Text::Bold);
            upgrades3_1.setOrigin(Vector2f(85,40));
            upgrades3_1.setPosition(Vector2f(1335,1070));

            Text upgrades3_2("Building 2", font);
            upgrades3_2.setCharacterSize(35);
            upgrades3_2.setFillColor(Color::Black);
            upgrades3_2.setStyle(Text::Bold);
            upgrades3_2.setOrigin(Vector2f(80,40));
            upgrades3_2.setPosition(Vector2f(1570,1070));

            Text upgrades3_3("Building 3", font);
            upgrades3_3.setCharacterSize(35);
            upgrades3_3.setFillColor(Color::Black);
            upgrades3_3.setStyle(Text::Bold);
            upgrades3_3.setOrigin(Vector2f(80,40));
            upgrades3_3.setPosition(Vector2f(1785,1070));



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
                win->draw(button);
                win->draw(button2);
                win->draw(button3);
                win->draw(button4);
                win->draw(button5);
                win->draw(button6);
                win->draw(button7);
                win->draw(button8);
                win->draw(button9);
                win->draw(store);
                win->draw(building);
                win->draw(building1);
                win->draw(building2);
                win->draw(building3);
                win->draw(upgrades);
                win->draw(upgrades1);
                win->draw(upgrades1_1);
                win->draw(upgrades1_2);
                win->draw(upgrades1_3);
                win->draw(upgrades2);
                win->draw(upgrades2_1);
                win->draw(upgrades2_2);
                win->draw(upgrades2_3);
                win->draw(upgrades3);
                win->draw(upgrades3_1);
                win->draw(upgrades3_2);
                win->draw(upgrades3_3);
                win->display();
            }
        }

};

int main(){
    cookie_collector game;
    game.run();

    return 0;
}