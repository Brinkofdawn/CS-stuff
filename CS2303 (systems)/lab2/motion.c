

int motion (int nodeid, int row, int column, int direction){
	switch(direction){
		case Left:
				while(row!=0){// don't go off left of board!
					nodeid++; // increment nodeid 
					field [row-1] [column]= nodeid;}// set field spot 1 left to nodeid
				break;//break out of case
		case Right:
				while(row!=LENGTH-1){// don't go right off the board
					nodeid++;//increment nodeid
					field [row+1] [column]= nodeid;}// set field spot 1 right to nodeid
				break;//break out of case
		case Up:
				while(column!=0){// don't go up off the board
					nodeid++;//increment nodeid
					field [row] [column-1]= nodeid;}//set field spot 1 up to nodeid
				break;//break out of case
		case Down:
				while(column!=WIDTH-1){//don't go down off the board
					nodeid++;//increment nodeid
					field [row] [column+1]= nodeid;}//set field spot 1 down to nodeid
				break;
	}
} 
