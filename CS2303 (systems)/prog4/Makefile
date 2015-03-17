## start of makefile

prog4: prog4.o Tree.o Line.o Word.o 
	g++ -o prog4 prog4.o 

prog4.o: prog4.cpp Tree.h  
	g++ -Wall -c prog4.cpp 

Tree.o: Tree.h Tree.cpp 
	g++ -Wall -c Tree.cpp 

Line.o: Line.cpp Line.h 
	g++ -Wall -c Line.cpp 

Word.o:  Word.cpp  Word.h
	g++ -Wall -c Word.cpp 




clean:
	rm *.o
## End of the Makefile
