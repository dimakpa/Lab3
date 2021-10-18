#include <iostream>
#include "Table.h"
#include "cstring"
#include "string"

namespace Lab3_1{


    Table::Table(struct Item1 item) {
        item.key = 5;
        strcpy(item.word, "CRH");
    }

    Table::Table(int SZ, struct Item1 item){
        SZ = 10;
        item.key = 5;
        strcpy(item.word, "SRH");
    }



    int Table::inseart(Item item1) {
        int i = hash(item1.key);
        int h = 3;
        int n = 0;
        int k = search(item1.key);
        if(k == -1) {
            while (Table::item[i].busy != 0 && n < SZ) {
                i = (i + h) % SZ;
                n = n + 1;
            }
            if (n < SZ) {
                if (Table::item[i].busy == -1){
                    Table::item[i].key = item1.key;
                    delete[] Table::item[i].word;
                    Table::item[i].word = item1.word;
                    Table::item[i].busy = 1;
                }
                else{
                    Table::item[i].key = item1.key;
                    Table::item[i].word = item1.word;
                    Table::item[i].busy = 1;
                }
            }
            else
                throw std::runtime_error("Table overflow!");
        }else
            throw std::runtime_error("Kollizion!");
        return SZ;
    }

    int Table::search(int key) {
        int i = hash(key);
        int h = 3;

        while (Table::item[i].busy != 0){
            if (Table::item[i].key == key && Table::item[i].busy != -1)
                return i;
            i = (i + h) % SZ;
            if (i == hash(key))
                return -1;
        }
        return -1;
    }

    Table & Table::operator + (struct Item &item1 ) {
        int rc = inseart(item1);
        return *this;
    }

    Table & Table::operator - ( int key) {
        return delete_element(key);
    }

    std::ostream & Table::operator ==( std::ostream& s) const{
        return print_table(s);
    }

    Table & Table::delete_element(int &key){
        int i = search(key);
        if (i != (-1))
            Table::item[i].busy = -1;
        else
            throw std::runtime_error("Element not founded");
        return *this;
    }

    std::ostream & Table::print_table(std::ostream& s) const {
        for(int i = SZ-1; i>=0; --i) {
            if (item[i].busy != 0 && item[i].busy != -1) {
                s << item[i].key << " ";
                s << item[i].word << std::endl;
            }
        }
        return s;
    }

    std::ostream & Table::delete_table(std::ostream& s){
        for(int i = SZ-1; i>=0; --i) {
            if (item[i].busy != 0) {
                s << item[i].key << " ";
                item[i].key = 0;
                s << item[i].word << std::endl;
                delete[] item[i].word;
                //item[i].word = nullptr;
            }
            s << "Table is clear";
        }

        return s;
    }

    void Table::set_item(int &a) {
        Table::item[a].busy = 0;
    }

}
