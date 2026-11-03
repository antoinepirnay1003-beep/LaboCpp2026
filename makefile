Test1: Test1.o Event.o
	g++ -o Test1 Test1.o Event.o

Test2: Test2.o Event.o Time.o Timing.o
	g++ -o Test2 Test2.o Event.o Time.o Timing.o

Test3: Test3.o Event.o Time.o Timing.o
	g++ -o Test3 Test3.o Event.o Time.o Timing.o

Test4: Test4.o Event.o Time.o Timing.o Schedulable.o Professor.o Group.o Classroom.o
	g++ -o Test4 Test4.o Event.o Time.o Timing.o Schedulable.o Professor.o Group.o Classroom.o

Test5: Test5.o Event.o Time.o Timing.o Schedulable.o Professor.o Group.o Classroom.o Exception.o TimeException.o TimingException.o
	g++ -o Test5 Test5.o Event.o Time.o Timing.o Schedulable.o Professor.o Group.o Classroom.o Exception.o TimeException.o TimingException.o

Test6: Test6.o Event.o Time.o Timing.o Schedulable.o Professor.o Group.o Classroom.o Exception.o TimeException.o TimingException.o
	g++ -o Test6 Test6.o Event.o Time.o Timing.o Schedulable.o Professor.o Group.o Classroom.o Exception.o TimeException.o TimingException.o

Test1.o: Test1.cpp
	g++ -c Test1.cpp

Test2.o: Test2.cpp
	g++ -c Test2.cpp

Test3.o: Test3.cpp
	g++ -c Test3.cpp

Test4.o: Test4.cpp
	g++ -c Test4.cpp

Test5.o: Test5.cpp
	g++ -c Test5.cpp
	
Test6.o: Test6.cpp
	g++ -c Test6.cpp

Event.o: Event.cpp
	g++ -c Event.cpp

Time.o: Time.cpp
	g++ -c Time.cpp

Timing.o: Timing.cpp
	g++ -c Timing.cpp

Schedulable.o: Schedulable.cpp
	g++ -c Schedulable.cpp

Professor.o: Professor.cpp
	g++ -c Professor.cpp

Group.o: Group.cpp
	g++ -c Group.cpp

Classroom.o: Classroom.cpp
	g++ -c Classroom.cpp

Exception.o: Exception.cpp
	g++ -c Exception.cpp

TimeException.o: TimeException.cpp
	g++ -c TimeException.cpp

TimingException.o: TimingException.cpp
	g++ -c TimingException.cpp

clean:
	rm -f *.o Test1 Test2 Test3 Test4 Test5
