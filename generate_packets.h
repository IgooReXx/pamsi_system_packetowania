//
// Created by IGOR on 23.03.2024.
//


#ifndef PAMSIPROJ1_GENERATE_PACKETS_H
#define PAMSIPROJ1_GENERATE_PACKETS_H

#include <string>
#include "packet.h"

template <typename T> int generate_packets(std::string dataRead, int maxData, int maxPacketSize, packet<T>* arrayPtr)
{

    int length = dataRead.length();
    if(length > maxData)
    {
        length=maxData;
    }

    std::string packet_data;
    int packet_counter = 0;
    int letter_counter = 0;
    int letter_sum = 0;



    while(letter_sum<length)
    {
        packet_data.push_back(dataRead[letter_sum]);
        letter_counter++;
        letter_sum++;
        if(letter_counter == maxPacketSize)
        {
            arrayPtr[packet_counter].data = packet_data;
            arrayPtr[packet_counter].packet_number = packet_counter;
            packet_counter++;
            packet_data.clear();
            letter_counter=0;
        }
    }

    if(letter_counter < maxPacketSize and letter_counter != 0)
    {
        arrayPtr[packet_counter].data = packet_data;
        arrayPtr[packet_counter].packet_number = packet_counter;
        packet_counter++;
    }

    return packet_counter;
}

#endif //PAMSIPROJ1_GENERATE_PACKETS_H