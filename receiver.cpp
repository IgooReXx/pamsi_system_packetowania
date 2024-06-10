//
// Created by IGOR on 02.04.2024.
//
#include "string"
#include "receiver.h"
// Zalozenie operacji wysylania wiadomosci znakowych
// https://stackoverflow.com/questions/495021/why-can-templates-only-be-implemented-in-the-header-file
template class receiver<std::string>;

// Funkcja symulujaca odbior pakietow poprzez zakolejkowanie ich w receivedPackets
template<> void receiver<std::string>::receive(packet<std::string>* arrayPtr, int numberOfPackets)
{
    for(int packetIterator = 0; packetIterator<numberOfPackets; packetIterator++)
    {
        receivedPackets.enqueue_with_priority(arrayPtr[packetIterator].data, arrayPtr[packetIterator].packet_number);
    }
}

// Funkcja odpowiedzialna za odtworzenie wiadomosci poprzez zdjemowanie pakietu o najwyzszym priorytecie
// oraz dodanie zawartosci tego pakietu do receivedMessage
template<> std::string receiver<std::string>::messageConstructor()
{
    std::string receivedMessage;
    while (!receivedPackets.is_empty())
    {
        node<std::string> currentPacket = receivedPackets.dequeue_max_priority();
        receivedMessage.append(currentPacket.data);
    }
    return receivedMessage;
}