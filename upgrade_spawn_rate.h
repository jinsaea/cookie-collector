#include <SFML/Graphics.hpp>
#include <string>
#include "upgrade.h"
#include "cookie.h"

class Upgrade_Spawn_Rate : public Upgrade{
    private:

    public:
        Upgrade_Spawn_Rate(){
            
        }
        //int get_new_spawn_rate(){}
        void set_spawn_rate(int* num_of_cookies, int new_spawn_rate, Cookie* cookie_array){
            delete cookie_array;
            *num_of_cookies = new_spawn_rate;
        }

};