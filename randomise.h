//
// Created by IGOR on 23.03.2024.
//


#ifndef PAMSIPROJ1_RANDOMISE_H
#define PAMSIPROJ1_RANDOMISE_H

#include "packet.h"
#include <algorithm>

template <typename T> void randomise(packet<T>* arrayPtr, int numberOfPackets)
{
    packet<T> buffer;
    for(int arrayIndex=0; arrayIndex < numberOfPackets; arrayIndex++)
    {
        int rand_indx = (rand()%numberOfPackets);
        buffer.data = arrayPtr[arrayIndex].data;
        buffer.packet_number = arrayPtr[arrayIndex].packet_number;
        arrayPtr[arrayIndex].data = arrayPtr[rand_indx].data;
        arrayPtr[arrayIndex].packet_number = arrayPtr[rand_indx].packet_number;
        arrayPtr[rand_indx].data = buffer.data;
        arrayPtr[rand_indx].packet_number = buffer.packet_number;
    }
}

#endif //PAMSIPROJ1_RANDOMISE_H
