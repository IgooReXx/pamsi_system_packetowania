#include <iostream>
#include "generate_packets.h"
#include "randomise.h"
#include "receiver.h"
#include "readData.h"

int main(int argc, char* argv[])
{
    /*====================== driver ================================*/
    if(argc != 5)
    {
        throw std::invalid_argument("Invalid number of arguments, must be 4");
    }
    srand(time(0));
    std::string fileName = argv[1];
    int maxData = std::stoi(argv[3]);
    int packetSize = std::stoi(argv[4]);
    int maxArraySize;
    if(packetSize == 0)
    {
        throw std::invalid_argument("Packet size cannot be 0.");
    }
    if(maxData%packetSize == 0)
    {
        maxArraySize = (maxData / packetSize);
    }
    else
    {
        maxArraySize = (maxData / packetSize) + 1;
    }
    std::string dataRead = readData(fileName);
    packet<std::string>* p = new packet<std::string>[maxArraySize];

    int pNo = generate_packets(dataRead, maxData, packetSize, p);

    randomise(p, pNo);

    /*======================== moduł ========================*/
    receiver<std::string> odb;
    odb.receive(p, pNo);
    std::cout << odb.messageConstructor();


}
