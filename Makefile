all: Timesync

Timesync: main.o EstimateTime.o ReadCSV.o unitTest.o 
	g++ main.o EstimateTime.o ReadCSV.o unitTest.o -o Timesync

main.o: main.cpp
	g++ -c main.cpp

EstimateTime.o: EstimateTime.cpp
	g++ -c EstimateTime.cpp

ReadCSV.cpp.o: ReadCSV.cpp
	g++ -c ReadCSV.cpp

unitTest.cpp.o: unitTest.cpp
	g++ -c unitTest.cpp

clean:
	rm -rf *o Timesync
