W celu skompilowania modulu nalezy uzyc polecenia
g++ -Wall -Wextra -pedantic -c receiver.cpp -o mod.o

W celu skompilowania drivera i dolaczenia modulu nalezy
g++ -Wall -Wextra -pedantic -o driver_zad3 main.cpp readData.cpp mod.o

Driver wywolany musi zostac z czterema dodatkowymi parametrami wystepujacymi w nastepujacej kolejnosci:
driver_zad3 fileName offset messageSize packetSize
(parametr offset pomijany jest ze wzgledu na brak omowienia go podczas zajec)
Parametry oznaczaja odpowiednio:
fileName - sciezke dostepu do pliku testowego,
messageSize - maksymalna dlugosc odczytanego bloku tekstu (odczytane zostanie mniej w przypadku braku odpowiedniej ilosci tekstu),
packetSize - maksymalna dlugosc pojedynczego pakietu.
