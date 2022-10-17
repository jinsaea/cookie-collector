#include "Store.h"
#include "bowl.h"
using namespace sf;

using namespace std;

class Building: public Store{
    protected:
        int num_of_building;
        int building_income;
        int total_cps;
        int cost;
    public:
        Building(){
            num_of_building = 0;
            building_income = 100;
            total_cps = 0;
            cost = 5;
        }
        Building(int income, int cost_of_building){
            num_of_building = 0;
            building_income = income;
            total_cps = 0;
            cost = cost_of_building;
        }

        int get_total_cps(){return total_cps;}

        void set_total_cps(){
            total_cps = num_of_building*building_income;
        }

        void buy_item(Bowl* a){
            int cookie_bank = a->get_current_cookies();
            if(cookie_bank > cost){
                cookie_bank = cookie_bank - cost;
                a->set_current_cookies(cookie_bank);
                num_of_building++;
                set_total_cps(); 
                cost = cost*2;
            }           
        }

        void set_building_income(int new_income){
            building_income = new_income;
            set_total_cps();
        }

        int get_num_of_building(){return num_of_building;}

        void sell_building(Bowl* a){
            if(num_of_building > 0){
                cost = cost/2;
                int sell_price = cost*0.6 + a->get_current_cookies();
                a->set_current_cookies(sell_price);
                num_of_building--;
                set_total_cps();
            }
        }

        int get_cost(){return cost;}

};