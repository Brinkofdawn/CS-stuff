## start of makefile

lab5: lab5.o event.o event.h
	g++ -o lab5 event.o lab5.o 

lab5.o: lab5.cpp event.h  
	g++  -c lab5.cpp 

event.o: event.h event.cpp 
	g++ -c event.cpp 




clean:
	rm *.o
## End of the Makefile
