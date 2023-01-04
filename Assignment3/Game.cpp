#include "Game.h"
using namespace std;

Game::Game(int w, int h, string chars){

	map = new Map(w,h);
	int x = 0, y = 0; 

	//& = Player
	//# = wall
	//. = floor

	//i is the y value

	//creating objects from the string map
	int tracker = 0;
	for(int i = 0; i < h; i++){
		for (int j = 0; j < w; j++){
			
			switch(chars[tracker])
			{			
				case '&':
				{
					player = new Player(j,i);
					Floor* floor = new Floor(j,i);

					player->below = floor; //setting links
					floor->above = player;

					map->add(floor);
					break;
				}
				
				case '#':
				{
					map->add(new Wall(j,i));
					break;
				}
				
				case '.':
				{
					map->add(new Floor(j,i));
					break;
				}
				
				default:
					break;
		}

		tracker++;
		
		}
	}
}

Game::~Game(){

	delete map;
	map = NULL;

	delete player;
	player = NULL;

}

string Game::display(){
	
	return map->print();

}

void Game::update(char input){

	switch(input){
		case '1':
			player->move(-1,1);
			break;

		case '2':
			player->move(0,1);
			break;

		case '3':
			player->move(1,1);
			break;

		case '4':
			player->move(-1,0);
			break;

		// case '5':
		// 	player->move(0,0);
		// 	break;

		case '6':
			player->move(1,0);
			break;

		case '7':
			player->move(-1,-1);
			break;

		case '8':
			player->move(0,-1);
			break;

		case '9':
			player->move(1,-1);	
			break;

	}

}



