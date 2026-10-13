Test1: Test1.o Event.o
	g++ -o Test1 Test1.o Event.o

Test2: Test2.o Event.o Time.o Timing.o
	g++ -o Test2 Test2.o Event.o Time.o Timing.o

Test3: Test3.o Event.o Time.o Timing.o
	g++ -o Test3 Test3.o Event.o Time.o Timing.o

Test1.o: Test1.cpp Event.h
	g++ -c Test1.cpp

Test2.o: Test2.cpp Event.h Time.h Timing.h
	g++ -c Test2.cpp

Test3.o: Test3.cpp Event.h Time.h Timing.h
	g++ -c Test3.cpp

Event.o: Event.cpp Event.h Timing.h
	g++ -c Event.cpp

Time.o: Time.cpp Time.h
	g++ -c Time.cpp

Timing.o: Timing.cpp Timing.h Time.h
	g++ -c Timing.cpp

clean:
	rm -f *.o Test1 Test2 Test3
