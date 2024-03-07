main1: main.cpp
	@g++ main.cpp Player.cpp Computer.cpp Human.cpp Referee.cpp Move.cpp Rock.cpp Pirate.cpp Zombie.cpp -o main
	@./main

main2: main.cpp 
	@g++ -std=c++20 -o main.out -O2 -Wall *.cpp 

clean1_bin: 
	@rm -rf main