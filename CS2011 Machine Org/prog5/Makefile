## start of makefile

Program5: Program5.o Board.o Source.o Mules.o Receiver.o position.o Packet.o Lists.o Board.h Source.h Mules.h Receiver.h position.h Packet.h Lists.h
	g++ -o  Program5 Program5.o Board.o Source.o Mules.o Receiver.o position.o Packet.o Lists.o

Program5.o: Program5.cpp Board.h Source.h Mules.h Receiver.h position.h Packet.h Lists.h
	g++ -c Program5.cpp 

Board.o: Board.cpp Board.h 
	g++  -c Board.cpp 

Source.o: Source.cpp Source.h
	g++  -c Source.cpp

Mules.o: Mules.cpp Mules.h
	g++  -c Mules.cpp 

Receiver.o: Receiver.cpp Receiver.h
	g++ -c Receiver.cpp 

position.o: position.cpp position.h
	g++  -c position.cpp  

Packet.o: Packet.cpp Packet.h
	g++  -c Packet.cpp  

Lists.o: Lists.cpp Lists.h 
	g++  -c Lists.cpp  







clean:
	rm *.o
## End of the Makefile
