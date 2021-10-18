#include <iostream>


namespace Lab3_1 {
    struct Item1{
        int key;
        char *word;
    };
    struct Item{
        int key, busy;
        char *word;

    };

    class Table{
    private:
        static const int SZ = 10;//max size of table
        struct Item item[SZ];
    public:


        Table(int SZ = 10){};
        Table(struct Item1 );
        Table(int SZ, struct Item1);
        int inseart(Item);
        int search(const int);
        int getItemKey(int i){return item[i].key; };
        char getItemWord(int i){return *item[i].word; };
        void delete_elemen(int );
        std::ostream & print_table(std::ostream&) const;//возвращает элементы, пока таблица не опустеет
        std::ostream & delete_table(std::ostream&);
        void set_item(int );
        int hash(int key){return key%3;};


    };

    template<class T>
    int getNum(T &a) {
        std::cin >> a;
        if (!std::cin.good())
            return -1;
        return 1;
    }


}
