#include<iostream>	
#include<conio.h>
#include<time.h>
#include<string>

using namespace std;
//Yes I tried to make bord inside class and that just isnt feasable.
char levelOneBord[20][20] = {

	//  1   2   3   4   5   6   7   8   9   10  11  12  13  14  15  16  17  18  19  20
	  {'|','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','|',}, //1
	  {'|',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','|',}, //2
	  {'|',' ','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-',' ','|',}, //3
	  {'|',' ',' ',' ',' ',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ',' ',' ',' ','|',}, //4
	  {'|',' ',' ',' ',' ',' ','-',' ',' ',' ','|',' ',' ',' ',' ',' ',' ',' ',' ','|',}, //5
	  {'|',' ',' ',' ',' ',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ',' ',' ',' ','|',}, //6
	  {'|',' ',' ',' ',' ',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ',' ','|',' ','|',}, //7
	  {'|',' ',' ',' ',' ','|',' ','|',' ',' ','|',' ',' ',' ',' ',' ',' ','|',' ','|',}, //8
	  {'|',' ',' ',' ',' ','|',' ','|',' ',' ','|',' ',' ',' ',' ',' ',' ','|',' ','|',}, //9
	  {'|',' ',' ',' ',' ','|',' ','|',' ',' ','|',' ',' ',' ','|',' ',' ','|',' ','|',}, //10
	  {'|',' ',' ',' ',' ','|',' ','|',' ',' ','|',' ',' ',' ','|',' ',' ','|',' ','|',}, //11
	  {'|',' ',' ',' ',' ','|',' ','|',' ',' ',' ',' ',' ',' ','|',' ',' ','|',' ','|',}, //12
	  {'|',' ',' ',' ',' ','|',' ','|',' ',' ',' ',' ',' ',' ','|',' ',' ','|',' ','|',}, //13
	  {'|',' ',' ',' ',' ','|',' ','|',' ',' ',' ',' ',' ',' ','|',' ',' ','|',' ','|',}, //14
	  {'|',' ',' ',' ',' ','|',' ','|',' ',' ',' ',' ',' ',' ','|',' ',' ',' ',' ','|',}, //15
	  {'|','-','-','-','-','-',' ','-','-','-','-','-','-','-','|','-','-',' ',' ','|',}, //16
	  {'|',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','|',' ',' ',' ',' ','|',}, //17
	  {'|',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','|',}, // 18
	  {'|',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','|',}, //19
	  {'|','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','|',} //20

};







class theGame {


	char tresure = stoi("1f605", nullptr, 16);
	int tresureX = 10;
	int tresureY = rand() % 10 + 4;
	//Making moveable packman
	char packman = 'O';
	int score = 7;

	//Where should I movepackman
	char input = ' ';
	int packmanX = 1;
	int packmanY = 1;
	bool packmanMoveLeft = false;
	bool packmanMoveUp = false;



public:


	/////////////////////////////////////////////////////////////////////////////////////////////


	 /////////////////////////////////////////////Move packman and score///////////////////////////

	void moveAndScore() {
		if (input == 'a' && packmanY >= 1) {
			if (levelOneBord[packmanX][packmanY - 1] != '|' && levelOneBord[packmanX][packmanY - 1] != '-') {
				levelOneBord[packmanX][packmanY] = ' ';
				packmanY--;
				if (levelOneBord[packmanX][packmanY] == tresure) {
					score--;
				}
				levelOneBord[packmanX][packmanY] = packman;
			}
		}
		else if (input == 'd' && packmanY <= 18) {
			if (levelOneBord[packmanX][packmanY + 1] != '|' && levelOneBord[packmanX][packmanY + 1] != '-') {
				levelOneBord[packmanX][packmanY] = ' ';
				packmanY++;
				if (levelOneBord[packmanX][packmanY] == tresure) {
					score--;
				}
				levelOneBord[packmanX][packmanY] = packman;
			}
		}
		else if (input == 'w' && packmanX >= 1) {
			if (levelOneBord[packmanX - 1][packmanY] != '|' && levelOneBord[packmanX - 1][packmanY] != '-') {
				levelOneBord[packmanX][packmanY] = ' ';
				packmanX--;
				if (levelOneBord[packmanX][packmanY] == tresure) {
					score--;
				}
				levelOneBord[packmanX][packmanY] = packman;
			}
		}
		else if (input == 's' && packmanX <= 18) {
			if (levelOneBord[packmanX + 1][packmanY] != '|' && levelOneBord[packmanX + 1][packmanY] != '-') {
				levelOneBord[packmanX][packmanY] = ' ';
				packmanX++;
				if (levelOneBord[packmanX][packmanY] == tresure) {
					score--;
				}
				levelOneBord[packmanX][packmanY] = packman;
			}
		}
		system("Cls");



	}



	///////////////////////////////////////////////////////////////////////////////////////////////

	/////////////////////////////////////////////////////////////////////////////////////////////
	void print(theGame gm) {

		gm.input = _getch();
		cout << "\n\t\t\t\t\t Time :" << time(0) % 60 << "\n";
		cout << "\n\t\t\t\t\t The remainig starts to eat :" << score << "\n\n\n\n";
		for (int i = 0; i < 20; i++) {
			cout << "\t\t\t\t\t";
			for (int j = 0; j < 20; j++) {
				cout << " " << levelOneBord[i][j];
			}
			cout << "\n";
		}
	}
	///////////////////////////////////////////////////////////////////////////get input/////////

	void getInput() {

		input = _getch();
		//So this is where I decide to move packman.
		if (input == 'w') {
			packmanMoveUp = true;
		}
		else if (input == 's') {
			packmanMoveUp = false;
		}
		else if (input == 'd') {
			packmanMoveLeft = false;
		}
		else if (input == 'a') {
			packmanMoveLeft = true;
		}

	}















	theGame() {

		////////////////Placing treaure in levelOneBord./////////
		levelOneBord[tresureX][tresureY] = tresure;

		levelOneBord[4][8] = tresure;
		levelOneBord[16][15] = tresure;
		levelOneBord[16][16] = tresure;
		levelOneBord[18][1] = tresure;
		levelOneBord[18][6] = tresure;
		levelOneBord[5][8] = tresure;





		char tresure = stoi("1f605", nullptr, 16);
		int tresureX = 10;
		int tresureY = rand() % 10 + 4;
		//Making moveable packman
		char packman = 'O';
		int score = 7;

		//Where should I movepackman
		char input = ' ';
		int packmanX = 1;
		int packmanY = 1;
		bool packmanMoveLeft = false;
		bool packmanMoveUp = false;



	}

};

void execute(theGame game) {

	//////////////////////////for Execution.///////////////////////////////
	while (1) {
		game.print(game);
		game.getInput();
		game.moveAndScore();

	}
}





int main() {

	theGame myGame;

	execute(myGame);



	system("pause");
}

