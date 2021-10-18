#include <iostream>
#include "string"
#include "Table.h"
#include "Messeges.h"

namespace Lab3_1{

    int getNum(int &a) {
        std::cin >> a;
        if (!std::cin.good())
            return -1;
        return 1;
    }

    int dialog(const char *msgs[], int N) {
        const char *errmsg = "";
        int rc;
        int i, n;
        do {
            std::cout << errmsg << std::endl;
            errmsg = "You are wrong. Repeat, please!";

            std::cout << "Choose the number from alternatives:" << std::endl << std::endl;
            for (i = 0; i < N; ++i)
                std::cout << msgs[i] << std::endl;
            std::cout << std::endl;
            std::cout << "Make your choise -->" << std::endl;


            n = getNum(rc);
            if (n == -1)
                rc = 0;
        } while (rc < 0 || rc >= N);
        return rc;
    }
    void messege_start(Table *&ep) {
        int (*fptr[])(Table *&ep) = {nullptr,
                                     D_Add_Exempluar,
                                     D_Set_New_Element,
                                     D_Print,
                                     D_Find_Element,
                                     D_Delete_Element_by_Index,
                                     D_Delete_Elements,
                                     D_Clear_Table,

        };

        const char *msgs[] = {"0. Quit",
                              "1. Create new exemplyar",
                              "2. Set new element of Table",//  ввод значения экземпляра структуры (элемента таблицы) из входного потока;
                              "3. Print Table",// вывод таблицы в выходной поток;
                              "4. Find element of the Table",//  поиск элемента таблицы по ключу;
                              "5. Delete element by index",// выборка информации из таблицы по заданному ключу;
                              "6. Delete element",//удаление элемента из таблицы (с отметкой в поле занятости) по ключу;
                              "7. Clear table and reorganize"// чистка таблицы от “удаленных элементов” – реорганизация таблицы.
        };

        const int NMsgs = sizeof(msgs) / sizeof(msgs[0]);

        int rc;
        while (rc = dialog(msgs, NMsgs)) {
            if (fptr[rc](ep) == -1)
                break;
        }


        printf("That's all, bye!");
    }

    int D_Add_Exempluar(class Table *&ep){
        if (ep != nullptr) {
            std::cout << "The Table is not empty! Create new!" << std::endl;
            return 0;
        }
        try {
            ep = new Table;
            for (int i = 0; i<10; i++)
                ep->set_item(i);
        }
        catch (std::runtime_error& ex) {
            std::cout << ex.what() << std::endl;
            std::cout << "Table with this configuration doesn't exist! The previous Table is saved!" << std::endl;
        }
        return 0;
    }

    int D_Set_New_Element(class Table *&ep){
        int rc, m, n;
        if (ep == nullptr) {
            std::cout << "The Table is empty! Create new!" << std::endl;
            return 0;
        }
        try {
            struct Item *item = new struct Item;
            std::cout << "Write the key: ";
            n = getNum(rc);
            item->key = rc;
            char* wordd = new char [4];
            std::cout << "Word with 3 letters: ";
            std::cin >> wordd ;
            item->word = wordd;

            *ep + *item;
        }
        catch (std::runtime_error& ex) {
            std::cout << ex.what() << std::endl;
            std::cout << "Table with this configuration doesn't exist! The previous epycycloid is saved!" << std::endl;
        }
        return 0;
    }
    int D_Print(class Table *&ep){
        int rc;
        if (ep == nullptr) {
            std::cout << "The Table is empty! Create new!" << std::endl;
            return 0;
        }
        try {
            *ep == std::cout;
        }
        catch (std::runtime_error& ex) {
            std::cout << ex.what() << std::endl;
            std::cout << "Table with this configuration doesn't exist! The previous table is saved!" << std::endl;
        }
        return 0;
    }
    int D_Find_Element(class Table *&ep){
        int rc, a;
        if (ep == nullptr) {
            std::cout << "The Table is empty! Create new!" << std::endl;
            return 0;
        }
        try {
            std::cout << "Write key of element: ";
            a = getNum(rc);
            a = ep->search(rc);
            if (a == -1){
                std::cout << "Element nit founded";
            }else {
                std::cout << "Your element: ";
                std::cout << ep->getItemKey(a) << " ";
                std::cout << ep->getItemWord(a) << std::endl;
            }
        }
        catch (std::runtime_error& ex) {
            std::cout << ex.what() << std::endl;
            std::cout << "Table with this configuration doesn't exist! The previous table is saved!" << std::endl;
        }
        return 0;
    }

    int D_Delete_Element_by_Index(class Table *&ep){
        int rc, a;
        if (ep == nullptr) {
            std::cout << "The Table is empty! Create new!" << std::endl;
            return 0;
        }
        try {
            std::cout << "Write key of element: ";
            a = getNum(rc);
            std::cout << "Your element: ";
            std::cout << ep->getItemKey(rc) << " ";
            std::cout << ep->getItemWord(rc) << std::endl;
            *ep - rc ;
        }
        catch (std::runtime_error& ex) {
            std::cout << ex.what() << std::endl;
            std::cout << "Table with this configuration doesn't exist! The previous table is saved!" << std::endl;
        }
        return 0;
    }
    int D_Delete_Elements(class Table *&ep){
        int rc, a;
        if (ep == nullptr) {
            std::cout << "The Table is empty! Create new!" << std::endl;
            return 0;
        }
        try {
            std::cout << "Write key of element: ";
            a = getNum(rc);
            a = ep->search(rc);
            std::cout << "Your element: ";
            std::cout << ep->getItemKey(a) << " ";
            std::cout << ep->getItemWord(a) << std::endl;
            *ep - a;
        }
        catch (std::runtime_error& ex) {
            std::cout << ex.what() << std::endl;
            std::cout << "Table with this configuration doesn't exist! The previous table is saved!" << std::endl;
        }
        return 0;
    }
    int D_Clear_Table(class Table *&ep){
        int rc;
        if (ep == nullptr) {
            std::cout << "The Table is empty! Create new!" << std::endl;
            return 0;
        }
        try {
            ep->delete_table(std::cout);
        }
        catch (std::runtime_error& ex) {
            std::cout << ex.what() << std::endl;
            std::cout << "Epycycloid with this configuration doesn't exist! The previous epycycloid is saved!" << std::endl;
        }
        return 0;
    }
}
