//
// Created by kubab on 16.03.2024.
//

#ifndef PAMSIPROJ1_NODE_H
#define PAMSIPROJ1_NODE_H

// Struktura na bazie ktorej zbudowana jest kolejka priorytetowa
// Posiada trzy pola na:
// klucz - na jego podstawie dokonywana jest decyzja o miejscu zakolejkowania
// data - wlasciwa dana do przechowania
// nextNode - wskaznik na nastepna komorke danych (wymagane przy implementacji z pomoca listy jednokierunkowej)

template <typename T> struct node
{
    int key;
    T data;
    node<T>* nextNode;

    node(int k, T d, node<T>* nN)
    {
        key = k;
        data = d;
        nextNode = nN;
    };
};

#endif //PAMSIPROJ1_NODE_H
