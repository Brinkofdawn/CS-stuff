Arun Donti
CS2303 C03
Program 2

The program has 4 define statements at the top

HEIGHT- 
	can change height of the board

WIDTH - 
	can change width of board

TEAMSIZE- 
	can change amount of players on each team (changing this to 0 will cause an automatic team2 victory)

TURNS-
	can change number of turns



How the turn order works:

	At the beggining of the game there are two teams with equal amount of players.
	Each team will have a players with ids from 0 to TEAMSIZE-1, so each team will have 1 matching player with the same id value(they will have different team values). The program will start with id 0, look at the board[1][0] then searches rightwards to board[1][HEIGHT+1], then move onto the leftmost of the next row of the board playing space and do the same thing. It will move the players with specified id 1 space in their current direction. The prgram will then do the same thing for all ids until it has moved all the players.

	I did this because I wanted it to be somewhat random which team goes first on each set of movements for specified ids.  I know that sometimes a specific team may get to move more than 1 time in a row especially if one piece with specified id has been removed from the game, but I felt that this was the fairest way to move the pieces.   



How the current board is displayed:


	Each player is displayed on the board with their team letter and id number
		ex. A1
		B7

	Border Piece: #
	Empty  Space: -


How the directions are displayed:

	Under each current gameboard will be displayed an identical gameboard, except each player will be replaced by their directional value.

		North-N
		South-S
		East- E
		West- W


