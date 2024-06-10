//
// Created by IGOR on 23.03.2024.
//

#ifndef PAMSIPROJ1_PACKET_H
#define PAMSIPROJ1_PACKET_H
// Struktura na bazie ktorej wykonywana jest komunikacja miedzy nadajnikiem i odbiornikiem
template <typename T> struct packet
{
    int packet_number;
    T data;
};

#endif //PAMSIPROJ1_PACKET_H
