all: insertion extraction
insertion: insertion.cpp
	g++ -std=c++11 insertion.cpp -o insertion -Wall
extraction: extraction.cpp
	g++ -std=c++11 extraction.cpp -o extraction -Wall
