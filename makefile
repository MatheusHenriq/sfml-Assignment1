all:
	g++ main.cpp lib/shape_movement.cpp lib/shape_movement_vector.cpp -I/opt/homebrew/Cellar/sfml/3.0.0_1/include/ -std=c++17 -o prog -L/opt/homebrew/Cellar/sfml/3.0.0_1/lib/ -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio && ./prog
