#ifdef STORE_H

#define STORE_H

Using namespace std

class Store {
    private:
    String name;
    int cost;
    bool locked;
    public:
    virtual void buy_item();
};




#endif
