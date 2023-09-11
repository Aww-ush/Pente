output: main.cpp Board.cpp Player.cpp Human.cpp Computer.cpp Game.cpp Coin.cpp
	g++ -std=c++17 main.cpp Board.cpp Player.cpp Human.cpp Computer.cpp Game.cpp Coin.cpp -o output


clean:
	rm *.o