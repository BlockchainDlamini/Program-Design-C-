#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <iomanip>
#include <vector>

using namespace std;

/*
	stringToInt is a helper function that will 
	take a string called line and return the integer value
*/
int stringToInt(string line){
	stringstream s1(line);
	int temp = 0;
	s1 >> temp;
	return temp;
}

int count(string line, char ch)
{
	int count = 0; 
	
	for (int i = 0; i < line.length(); i++)
		if (ch == line[i])
			count++;
	
	return count;
}

/*Notes:

Extract the floors to visit from the text file and traverse accordingly

limit the file reads to 2, 1 Determine the number of floors, 2 read the foor data into the 2d array
read the 2d array for the floors to visit

*/
int main() {

	vector<string> flrno;
	fstream data;
	string line, visit;

	//Part 1 opening for first reading the data into the 2d array

	data.open("building.data", ios::in);
	int size;

	while (getline(data, line))
		++size;

	data.close();
	size = (size-1)/2;
	string** building = new string*[size]; //delete
	int arrsizes[size];

	//Part 2 read the floor into the textfile
	data.open("building.data", ios::in);
	getline(data,line);
	visit = line;

	while (getline(data, line))
	{	
		//cout<< line<<endl;
		int cpos = line.find(':');
		int endpos = line.length();
		int copycount = endpos - cpos + 1;

		char cid[] = " ";
		line.copy(cid, copycount, cpos + 1);
		int id = stringToInt(cid);
		
		int nsize = 0;
		getline(data, line);
		stringstream holder(line);

		nsize = count(line, ',') + 1;

		building[id] = new string[nsize];
		arrsizes[id] = nsize;

		for (int j = 0; j < nsize; j++)
			getline(holder,building[id][j],',');

		/*for (int j = 0 ; j < nsize; j++)
				cout<< building[id][j]<<" ";
		cout<<endl;*/
			
	}
	data.close();

	//Part 3 opening the 2d array for the floors to visit
	
	stringstream line2(visit);
	string floor;

	while (getline(line2,floor,','))
	{
		
		int ifloor;
		ifloor = stringToInt(floor);

		for (int i = arrsizes[ifloor] - 1; i > -1; i--)
			if (i == 0)
				cout<< building[ifloor][i];
			else 
				cout<< building[ifloor][i]<<',';

		cout<<endl;
	}
	
	//Part 4 deallocate the memory
	
	for (int i = 0; i < size; i++)
	 	delete [] building[i];
	delete building;

	return 0;
}

/*
Expected output with the given building.txt:

Sunil,Alok,Kamilah,Pratik
Tamera,Zanetta,Keyundra,Alexzander,Nickalaus,Nathania,Annamaria,Ransen,Thuy,Yousef       
Jeffry,Shira,Sereena
Janna,Shaleen,Josi,Ndidi,Indalecio,Charlotta
Kejuan,Matricia,Takiya,Karalyn,Charls
Rebbecca
Kailyn,Kenda
Katheryne,Coury,Timithy,Melisssa,Clara,Lucus,Brittony,Makoto,Latona,Rudolph
*/

