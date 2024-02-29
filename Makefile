main1: main.cpp
	@g++ main.cpp Player.cpp Computer.cpp Human.cpp Referee.cpp -o main
	@./main

clean1_bin: 
	@rm -rf main