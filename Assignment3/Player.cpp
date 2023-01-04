#include "Player.h"
#include <iostream>
using namespace std;

Player::Player(int x, int y) : Object(x,y){

	icon = '&';

}

void Player::move(int x, int y){

	//Lowest possible object = object with a below link not equal to null?
	//Note, only floor objects will have their next and prev not set to null
	//Therefore navigate all the way to the bottom(lowest possible object)
	//from there work with and set all the next and previous' of the player object and floor object
	//once thats done go back up and set update all its links

	int horizR = 1, horizL = -1, vertU = -1, vertD = 1, stat = 0;

	if (x != stat || y != stat){ // no movement		
		// go to the floor first before testing null
		Object* findbelow = below; // if its below is null we can only assume that its not on the map

		if (findbelow){

			//gets you the lowest possible floor
			while (findbelow->below)
				findbelow = findbelow->below;	
	
				if (x == horizR && y == stat){ //one right
				
				if (findbelow->nextHoriz){// if there is an object there

					//update its position
					Object* newfloor = findbelow->nextHoriz;

					xPos = newfloor->getCoord(0);
					yPos = newfloor->getCoord(1);

				    //update above and below first

					Object* highest = NULL; // inserted the player on top of the highest object on that space

					highest = newfloor->above; // what if its null?

					//update the players below and above links

					if (!highest){ // if its null set the links as follows
						
						below->above = this->above;

						if (this->above)
							this->above->below = below;

						below = newfloor; 
						above = NULL; 

						newfloor->above = this;

					}
					else {

						while (highest->above)
							highest = highest->above;
						
						below->above = this->above;

						if (this->above)
							this->above->below = below;

						below = highest;
						above = NULL;
						highest->above = this;

					}
				}
			}
			else if (x == horizL && y == stat){ // one left
				
				if (findbelow->prevHoriz){

				Object* newfloor = findbelow->prevHoriz;

				xPos = newfloor->getCoord(0);
				yPos = newfloor->getCoord(1);

				Object* highest = NULL;
				highest = newfloor->above;

				if (!highest){ 

					below->above = this->above;
						
					if (this->above)
						this->above->below = below;

					below = newfloor; 
					above = NULL; 

					newfloor->above = this;

				}
				else{

					while (highest->above)
						highest = highest->above;

					below->above = this->above;

					if (this->above)
						this->above->below = below;

					below = highest;
					above = NULL;
					highest->above = this;

					}
				}
			}
			else if ( x == stat && y == vertU){ // one up
				
				if (findbelow->prevVert){

				Object* newfloor = findbelow->prevVert;

				xPos = newfloor->getCoord(0);
				yPos = newfloor->getCoord(1);

				Object* highest = NULL;
				highest = newfloor->above;

				if (!highest){ 

					below->above = this->above;

					if (this->above)
						this->above->below = below;

					below = newfloor; 
					above = NULL; 

					newfloor->above = this;
				}
				else{

					while (highest->above)
						highest = highest->above;

					below->above = this->above;

					if (this->above)
						this->above->below = below;

					below = highest;
					above = NULL;
					highest->above = this;

					}
				}
			}
			else if ( x == stat && y == vertD){

				if (findbelow->nextVert){

				Object* newfloor = findbelow->nextVert;

				xPos = newfloor->getCoord(0);
				yPos = newfloor->getCoord(1);

				Object* highest = NULL;

				highest = newfloor->above; 

				if (!highest){  

					below->above = this->above;

					if (this->above)
						this->above->below = below;
					
					below = newfloor; 
					above = NULL; 

					newfloor->above = this;

				}
				else{

					while (highest->above)
						highest = highest->above;

					below->above = this->above;

					if (this->above)
						this->above->below = below;
					
					below = highest;
					above = NULL;
					highest->above = this;

					}
				}
			}
			else if ( x == horizR && y == vertU){ //one right and one up
				
				if (findbelow->nextHoriz){ 
				
					if (findbelow->nextHoriz->prevVert){

					Object* newfloor = findbelow->nextHoriz->prevVert;
					
					xPos = newfloor->getCoord(0);
					yPos = newfloor->getCoord(1);

					Object* highest = NULL;

					highest = newfloor->above;

					if (!highest){  

						below->above = this->above;

						if (this->above)
							this->above->below = below;
					
						below = newfloor; 
						above = NULL; 

						newfloor->above = this;

					}
					else{

						while (highest->above)
							highest = highest->above;

						below->above = this->above;

						if (this->above)
							this->above->below = below;					

						below = highest;
						above = NULL;
						highest->above = this;

						}
					}
				}
				else if (findbelow->prevVert){ 
				
						if (findbelow->prevVert->nextHoriz){

						Object* newfloor = findbelow->prevVert->nextHoriz;

						xPos = newfloor->getCoord(0);
						yPos = newfloor->getCoord(1);

					Object* highest = NULL; 
					highest = newfloor->above;

					if (!highest){

						below->above = this->above;

						if (this->above)
							this->above->below = below;

						below = newfloor; 
						above = NULL; 
						newfloor->above = this;

					}
					else{

						while (highest->above)
							highest = highest->above;

						below->above = this->above;

						if (this->above)
							this->above->below = below;
							
						below = highest;
						above = NULL;
						highest->above = this;

					}
				}
			}
		}
		else if ( x == horizR && y == vertD){ //one right one down

			if (findbelow->nextHoriz){ 
				
				if (findbelow->nextHoriz->nextVert){ 

					Object* newfloor = findbelow->nextHoriz->nextVert;

					xPos = newfloor->getCoord(0);
					yPos = newfloor->getCoord(1);

					Object* highest = NULL;
					highest = newfloor->above;

					if (!highest){

						below->above = this->above;

						if (this->above)
							this->above->below = below;
							
						below = newfloor; 
						above = NULL; 

						newfloor->above = this;
					}
					else{

						while (highest->above)
							highest = highest->above;

						below->above = this->above;

						if (this->above)
							this->above->below = below;
							
						below = highest;
						above = NULL;
						highest->above = this;

					}
				}
			}
			else if (findbelow->nextVert){  
				
					if (findbelow->nextVert->nextHoriz){

					Object* newfloor = findbelow->nextVert->nextHoriz;

					xPos = newfloor->getCoord(0);
					yPos = newfloor->getCoord(1);

					Object* highest = NULL;
					highest = newfloor->above; 

					if (!highest){

						below->above = this->above;

						if (this->above)
							this->above->below = below;

						below = newfloor; 
						above = NULL; 

						newfloor->above = this;
					}
					else {

						while (highest->above)
							highest = highest->above;

						below->above = this->above;

						if (this->above)
							this->above->below = below;
							
						below = highest;
						above = NULL;
						highest->above = this;

					}
				}
			}
		}
		else if ( x == horizL && y == vertU) { //one left one up

			if (findbelow->prevHoriz){ 
				
				if (findbelow->prevHoriz->prevVert){ 

					Object* newfloor = findbelow->prevHoriz->prevVert;

					xPos = newfloor->getCoord(0);
					yPos = newfloor->getCoord(1);

					Object* highest = NULL;
					highest = newfloor->above; 

					if (!highest){ 

						below->above = this->above; 

						if (this->above)
							this->above->below = below;
							
						below = newfloor; 
						above = NULL; 

						newfloor->above = this;
					}
					else {

						while (highest->above)
							highest = highest->above;

						below->above = this->above;

						if (this->above)
							this->above->below = below;
							
						below = highest;
						above = NULL;
						highest->above = this;

					}
				}
			}
			else if (findbelow->prevVert){  
				
					if (findbelow->prevVert->prevHoriz){

					Object* newfloor = findbelow->prevVert->prevHoriz;

					xPos = newfloor->getCoord(0);
					yPos = newfloor->getCoord(1);

					Object* highest = NULL;
					highest = newfloor->above;

					if (!highest){

						below->above = this->above;

						if (this->above)
							this->above->below = below;
							
						below = newfloor; 
						above = NULL; 

						newfloor->above = this;
					}
					else {

						while (highest->above)
							highest = highest->above;

						below->above = this->above;

						if (this->above)
							this->above->below = below;
							
						below = highest;
						above = NULL;
						highest->above = this;
					
					}
				}
			}			
		} 
		else if ( x == horizL && y == vertD) { //one left one down

			if (findbelow->prevHoriz){ 

				if (findbelow->prevHoriz->nextVert){

					Object* newfloor = findbelow->prevHoriz->nextVert;

					xPos = newfloor->getCoord(0);
					yPos = newfloor->getCoord(1);

					Object* highest = NULL; 
					highest = newfloor->above;

					if (!highest){

						below->above = this->above;

						if (this->above)
							this->above->below = below;
							
						below = newfloor; 
						above = NULL; 
						newfloor->above = this;
					}
					else{

						while (highest->above)
							highest = highest->above;

						below->above = this->above;

						if (this->above)
							this->above->below = below;
							
						below = highest;
						above = NULL;
						highest->above = this;

						}
					}
				}
				else if (findbelow->nextVert){

						if (findbelow->nextVert->prevHoriz){

						Object* newfloor = findbelow->nextVert->prevHoriz;

						xPos = newfloor->getCoord(0);
						yPos = newfloor->getCoord(1);

						Object* highest = NULL;
						highest = newfloor->above; 

						if (!highest){
							below->above = this->above;

							if (this->above)
								this->above->below = below;
							
							below = newfloor; 
							above = NULL; 

							newfloor->above = this;
						}
						else
						{

							while (highest->above)
								highest = highest->above;

							below->above = this->above;

							if (this->above)
								this->above->below = below;
							
							below = highest;
							above = NULL;
							highest->above = this;
					
						}	
					}
				}			
			}
		} 
	}
}


