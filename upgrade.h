#include <SFML/Graphics.hpp>
#include <string>

class Upgrade{ //button is in parent, detect button
    private:
        int new_value;
        std::string type;
        bool purchased;
    public:
        //constructor from store class
        Upgrade(int value, std::string type){
            new_value = value;
            this->type = type;
        }
        int get_new_value(){return new_value;}
        bool is_purchased(){return purchased;} //checks if upgrade is purchased
        void set_purchased(bool purchased){this->purchased = purchased;}
        void buy_item(){
            
        } //builds upon buy_item function in store class, removes from store
};