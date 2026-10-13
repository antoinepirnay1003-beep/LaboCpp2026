# Remplacer tout le makefile
Test1: Test1.o Event.o
	g++ -o Test1 Test1.o Event.o

Test2: Test2.o Event.o Time.o Timing.o
	g++ -o Test2 Test2.o Event.o Time.o Timing.o

Test3: Test3.o Event.o Time.o Timing.o
	g++ -o Test3 Test3.o Event.o Time.o Timing.o

Test4: Test4.o Event.o Time.o Timing.o Schedulable.o Professor.o Group.o Classroom.o
	g++ -o Test4 Test4.o Event.o Time.o Timing.o Schedulable.o Professor.o Group.o Classroom.o

Test1.o: Test1.cpp Event.h
	g++ -c Test1.cpp

Test2.o: Test2.cpp Event.h Time.h Timing.h
	g++ -c Test2.cpp

Test3.o: Test3.cpp Event.h Time.h Timing.h
	g++ -c Test3.cpp

Test4.o: Test4.cpp Schedulable.h Professor.h Group.h Classroom.h Event.h
	g++ -c Test4.cpp

Event.o: Event.cpp Event.h Timing.h
	g++ -c Event.cpp

Time.o: Time.cpp Time.h
	g++ -c Time.cpp

Timing.o: Timing.cpp Timing.h Time.h
	g++ -c Timing.cpp

Schedulable.o: Schedulable.cpp Schedulable.h
	g++ -c Schedulable.cpp

Professor.o: Professor.cpp Professor.h Schedulable.h
	g++ -c Professor.cpp

Group.o: Group.cpp Group.h Schedulable.h
	g++ -c Group.cpp

Classroom.o: Classroom.cpp Classroom.h Schedulable.h
	g++ -c Classroom.cpp

clean:
	rm -f *.o Test1 Test2 Test3 Test4
