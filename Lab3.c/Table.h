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
        int SZ = 3;//max size of table
        static const int size = 5;
        struct Item item[];
    public:
        Table(int SZ = 10){};
        Table(struct Item1);
        Table(int SZ, struct Item1);
        int inseart(Item);
        int search(const int );
        Table & operator + (struct Item &);
        Table & operator - (const int );
        std::ostream & operator == (std::ostream&) const;
        int getItemKey(int& i){return item[i].key; };
        char getItemWord(int& i){return *item[i].word; };
        Table & delete_element(int& );
        std::ostream & print_table(std::ostream&) const;
        std::ostream & delete_table(std::ostream&);
        int getSZ();
        void setSZ(int );
        int get_size();
        void setItemSize(int );
        void set_item(int& );
        int hash(int key){return key%3;};
        Item getItem(int& i){return item[i];};
    };

    template<class T>
    int getNum(T &a) {
        std::cin >> a;
        if (!std::cin.good())
            return -1;
        return 1;
    }
    
}
