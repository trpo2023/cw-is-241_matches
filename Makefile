game1:game.c
		gcc -Wall -Werror -o game game.c
		clear
		./game
cl1: 
		rm game
cl2:
		rm game2
game2:game2.c
		gcc -Wall -Werror -o game2 game2.c
		clear
		./game2