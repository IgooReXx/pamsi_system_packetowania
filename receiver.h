//
// Created by IGOR on 24.03.2024.
//

#ifndef PAMSIPROJ1_RECEIVER_H
#define PAMSIPROJ1_RECEIVER_H

#include "priorityQueue.h"
#include "packet.h"
#include <string>

/* Klasa modulu odpowiedzialna za odebranie pakietow i odtworzenie oryginalnej wiadomosci. */

template <typename T> class receiver {

    priorityQueue<T> receivedPackets; // obiekt odpowiedzialny za przechowywanie i sortowanie odebranych pakietow

public:
    receiver() = default;
    void receive(packet<T>* arrayPtr, int numberOfPackets);
    std::string messageConstructor();

};


#endif //PAMSIPROJ1_RECEIVER_H
