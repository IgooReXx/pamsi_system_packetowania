//
// Created by kubab on 16.03.2024.
//

#ifndef PAMSIPROJ1_PRIORITYQUEUE_H
#define PAMSIPROJ1_PRIORITYQUEUE_H

#include "node.h"
#include <stdexcept>

// Struktura kolejki priorytetowej oparta na liscie jednokierunkowej z uzyciem wskaznikow pierwszego i ostatniego elementu

template <typename T> class priorityQueue {

    node<T> *head;
    node<T> *tail;

public:

    priorityQueue()
    {
        head = nullptr;
        tail = nullptr;
    };

    // Funkcja odpowiedzialna za zakolejkowanie pojedynczej komorki
    // Na podstawie aktualnego stanu kolejki oraz klucza
    // podejmowana jest decyzja o utworzeniu i umieszczeniu
    // nowej komorki o zadanych parametrach data oraz priority
    // Podczas kolejkowania dokonywanie jest sortowanie na bazie kluczy
    void enqueue_with_priority(T data, int priority)
    {
        if (head == nullptr and tail == nullptr) {          // jesli kolejka jest pusta
            head = new node<T>(priority, data, nullptr);
            tail = head;
        } else if (priority < head->key) {
            node<T> *temp = head;
            head = new node<T>(priority, data, temp);
        } else {                                           // przypadek osiagniecia konca kolejki
            node<T> *temp = head;
            while (temp->nextNode != nullptr and priority > temp->nextNode->key) {
                temp = temp->nextNode;
            }
            temp->nextNode = new node<T>(priority, data, temp->nextNode);
            if (temp->nextNode->nextNode == nullptr) {
                tail = temp->nextNode->nextNode;
            }
        }
    }


    // Funkcja odpowiedzialna za zdekolejkowanie komorki o najwyzszym priorytecie
    // Najwyzszy priorytet definiowany jest tutaj poprzez najnizsza wartosc klucza
    // ze wzgledu na uprzednie posortowanie kolejki zdejmowany jest zawsze pierwszy element
    // Wyrzuca blad out_of_range w przypadku proby zdekolejkowania pustej kolejki
    node<T> dequeue_max_priority()
    {
        if(is_empty())
        {
            throw std::out_of_range ("Out of Bounds");
        }
        node<T> temp = *head;
        node<T>* prev_head = head;
        head = head->nextNode;
        if (head == nullptr)
            tail = nullptr;
        delete prev_head;
        return temp;
    }

    // Funkcja odpowiedzialna za wskazanie, czy kolejka jest pusta
    bool is_empty()
    {
        if(head == nullptr and tail == nullptr) return true;
        return false;
    }

};


#endif //PAMSIPROJ1_PRIORITYQUEUE_H
