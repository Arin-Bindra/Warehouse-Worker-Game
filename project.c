/* The Warehouse */

/* Arin Bindra */

#include "project.h"

/*
The TimeWorked function takes in 4 inputs. An initial time and an end time.
This function finds the difference between the two times in seconds.
*/
int TimeWorked(int minuteA, int secondA, int minuteB, int secondB)
{
	int timeA, timeB;

	// Converting minutes into seconds, then adding to find a total number of seconds
	timeA = (minuteA * 60) + secondA;
	timeB = (minuteB * 60) + secondB;
	
	// Checks if time A or B is bigger so when subtracting there is no negative
	if (timeA >= timeB) {
		return timeA - timeB;
	} else {
		return timeB - timeA;
	} 
}

/*
WarehouseAdress function takes a maximum value as input, and then finds the largest
prime number under that maximum value.
*/
int WarehouseAddress(int maximum)
{
	int value = 0;
	int max = 1;

	//Setting for loop for i to equal all values under the maximum value
	for (int i = 2; i < maximum; i++) {

		value = 0;
		//Setting a for loop to find if any values divide into i
		for (int j = 2; j <= (i/2); j++) {
			if ((i%j) == 0) { //If j is able to divide into i, then loop breaks and i is increased
				value = 1;
				break;
			}
		}

		//For loop to determine largest prime number
		if (value == 0) {
			if (i > max) {
				max = i;
			}
		}
	}

	return max;
}

/*
The Advertise function takes a string as an input. The positions of the string
are then rotated one postion to the left, whilst the character in the first
position wraps around to the last position.
*/
void Advertise(char *words)
{
	int i = 0;
	char a = words[0];

	//Placing the values one position to the left 
	while (words[i] !=  '\0') {
		if (words[i + 1] != '\0') { //if statment to make sure the last character is not cut off
			words[i] = words[i+1];
		} else if (words[i + 1] == '\0') {
			break;
		}
		i++;
	}

	words[i] = a; // swapping the first and last characters
}

/*
This function finds and returns the lowest unique number from an array. Takes the 
length of the array and the array as inputs.
*/
int WinningBid(int *values, int length)
{
	int count;
	int high = values[0];
	int unique;
	int temp[MAX_ARRAY_SIZE];
	int index = 0;
	
	//For loop to find the largest number in the array
	for (int q = 0; q < length; q++) {
		if (values[q] > high) {
			high = values[q];
		}
	}

	unique = high; 
	//Integrated for loop to find the value which occurs in the array
	for (int i = 0; i < length; i++) {
		count = 0;
		for (int j = 0; j < length; j++) {
			if (values[i] == values[j]) {
				count++;
			}
		}
		for (int z = 0; z < length; z++) { //creating loop to store all of the count values in array
			temp[i] = count;
		}
		if ((count == 1) && (unique > values[i])) {
			unique = values[i];
		} 
	}

	//For loop to determine if there are no unique values in array;
	for (int p = 0; p < length; p++) {
		if (temp[p] == 1) {
			index = 1;
			break;
		}
	}

	//If there are no unique values loop will return -1, if there are then the lowest unique value will be returned
	if (index == 1) {
		return unique;
	} else {
		return -1;
	}

}

/*
The BoxDesign function creates a string which looks like a box using the width and height inputs.
The centre of the "box" is then marked.
*/
void BoxDesign(char *design, int width, int height)
{
	int i;

	//For loop creates string with ascii "spaces"
	for (i = 0; i < ((width + 1) * height) - 1; i++) {
		design[i] = 32; //32 = (sp)
	}

	//For loop creates left column with ascii value
	for (i = 0; i < ((width + 1) * height) - 1; i = i + width + 1) {
		design[i] = 42; //42 = *
	}
	
	//For loop sets right column with ascii value
	for (i = width - 1; i < ((width + 1) * height) - 1; i = width + i + 1) {
		design[i] = 42;
	}
	
	//For loop sets bottom row as ascii value
	for (i = ((width + 1) * height) - width - 1; i < ((width + 1) * height) - 1; i++) {
		design[i] = 42;
	}
	
	//For loop sets top tow with ascii value
	for (i = 0; i < width - 1; i++) {
		design[i] = 42;
	}

	//For loop sets end of each column to new line
	for (i = width; i < (width + 1) * height; i = width + i + 1) {
		design[i] = '\n';
	}

	//Setting X's in centre of box
	if (width > 2 || height > 2) {

		if (((width % 2) != 0) && ((height % 2) != 0)) { //When both height and width are odd numbers
			
			design[(((width + 1) * height) / 2) - 1] = 88; //88 = X (ascii)

		} else if (((width % 2) == 0) && ((height % 2) != 0)) { //When width is even and height is odd
			
			design[(((width + 1) * height) - 2) / 2] = 88; //total string length /2
			design[((((width + 1) * height) - 2) / 2) + 1] = 88;

		} else if ((width % 2 != 0) && (height % 2 == 0)) { //When width is odd and height is even
			
			design[((height / 2) * (width + 1)) - (((width + 1) / 2) + 1) + width + 1] = 88;
			design[((height / 2) * (width + 1)) - (((width + 1) / 2) + 1)] = 88;
			
		} else if ((width % 2 == 0) && (height % 2 == 0)) { //When both width and height are even
			
			design[((((((width + 1) * height) - 1) / 2) - (width / 2)) + width + 1) - 1] = 88;
			design[(((((width + 1) * height) - 1) / 2) - (width / 2)) + width + 1] = 88;
			design[(((((width + 1) * height) - 1) / 2) - (width / 2)) - 1] = 88;
			design[((((width + 1) * height) - 1) / 2) - (width / 2)] = 88;
		}
	}


	//Setting \0 at end of string 
	design[(width + 1) * height] = '\0';

}

/*
The WorkerRoute function takes in an array as input. The function creates a path from the
starting point "1" to the end point "3", by changing the values in the path to "3".
*/
void WorkerRoute(int warehouse[10][10])
{
	int rowS = 0;
	int colS = 0;
	int rowF = 0;
	int colF = 0;

	//For loop to find location of "1" in 2D array
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			if (warehouse[i][j] == 1) {
				rowS = i;
				colS = j;
			}
		}
	}
	//For loop to find location of "2" in 2D array
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			if (warehouse[i][j] == 2) {
				rowF = i;
				colF = j;
			}
		}
	}

	if (colF < colS) { //deciding which direction the values will be changed to 3 in coloums
		for (int i = colF; i < colS; i++) { // 3 increasing with coloums
			if(warehouse[rowS][i] != 2) { //if statement too see if 2 is next to the 1 value
				warehouse[rowS][i] = 3; //changing values to 3 if they are in coloums path
			}
		}
	} else {
		for (int i = colF; i > colS; i--) { //3 decreasing with rows
			if (warehouse[rowS][i] != 2) {
				warehouse[rowS][i] = 3;
			}
		}
	}

	if (rowF > rowS) { //deciding which direction the values will be changing to 3 in rows
		for (int i = rowS; i < rowF; i++) {
			if (warehouse[i][colF] != 1) { //if statment to see if 1 is next to 2 value
				warehouse[i][colF] = 3;
			}
		}
	} else {
		for (int i = rowS; i > rowF; i--) {
			if (warehouse[i][colF] != 1) {
				warehouse[i][colF] = 3;
			}
		}
	}
}



/*
This function moves the worker around the warehouse, pushing boxes onto their final spots. Inputs are warehouse 2d array
and move (either w,a,s,d). Once the worker moves around the obsiticles the task is finsihed.
*/
int MakeMove(int warehouse[10][10], char move)
{
	int row1 = 0;
	int col1 = 0;
	int Wcheck = 0;
	int Bcheck = 0;

	//For loop to find location of "5" in 2D array
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			if (warehouse[i][j] == 5) {
				row1 = i;
				col1 = j;
			} else if (warehouse[i][j] == 6) {
				row1 = i;
				col1 = j;
			}
		}
	}
	// if move is w then following if statement is followed "up"
	if (move == 'w') {
		if (warehouse[row1 - 1][col1] == 0) { //moving 5 or 6 when there is an empty space in front of it
			if (warehouse[row1][col1] != 6) { //moving 6 when there is an empty space in front of it
				warehouse[row1 - 1][col1] = 5; //new space changed to 5
				warehouse[row1][col1] = 0; //original space changed to 0
				row1 = row1 - 1; //only for debugging purposes
				col1 = col1; //only for debugging purposes
			}
			else { //moving 5 when there is an empty space in front of it
				warehouse[row1 - 1][col1] = 5;
				warehouse[row1][col1] = 2;
				row1 = row1 - 1;
				col1 = col1;
			}
		}
		else if ((warehouse[row1 - 1][col1] == 2) && (warehouse[row1][col1] != 6)) { //moving 5 if there is value 2 in front of it, then changing 5 into 2
			warehouse[row1 - 1][col1] = 6;
			warehouse[row1][col1] = 0;
			row1 = row1 - 1;
			col1 = col1;
		}
		else if ((warehouse[row1 - 1][col1] == 2) && (warehouse[row1][col1] == 6)) { //if there is 2 targets next to each other
			warehouse[row1 - 1][col1] = 6;
			warehouse[row1][col1] = 2;
			row1 = row1 - 1;
			col1 = col1;
		}
		else if ((warehouse[row1 - 1][col1] == 3) && (warehouse[row1 - 2][col1] != 1) && (warehouse[row1 - 2][col1] != 3)) { //if statement if there is a 3 in front of 5
			if (warehouse[row1 - 2][col1] == 2) { //when pushing value 3 onto value 2
				warehouse[row1 - 1][col1] = 5; //changing value to in front to 5
				warehouse[row1][col1] = 0; // changing value behind to 0
				row1 = row1 - 1; //changing row1 to current 5 position
				col1 = col1;
				warehouse[row1 - 1][col1] = 4; //changing value 2 to value 4
			}
			else if (warehouse[row1][col1] == 6) { //if value is 6 and pushing value 3 onto value 2
				warehouse[row1 - 1][col1] = 5; // value moves one space and changes from 6 to 5
				warehouse[row1][col1] = 2; //value changed from 6 to 2
				row1 = row1 - 1; //changing row1 to current 5 position
				col1 = col1;
				warehouse[row1 - 1][col1] = 3; //moving value 3 one space from current 5 position
			}
			else { //if value 5 pushing value 3 into empty positon
				warehouse[row1 - 1][col1] = 5; //changing one position forward to 5
				warehouse[row1][col1] = 0; //current position changes to 0
				row1 = row1 - 1; //changing row1 to current 5 position
				col1 = col1;
				warehouse[row1 - 1][col1] = 3; //moving value 3 one space from current 5 postion
			}
		}
		else if ((warehouse[row1 - 1][col1] == 4) && (warehouse[row1 - 2][col1] != 1) && (warehouse[row1 - 2][col1] != 3)) { //pushing value 4 forwards into empty space and changing back to 3
			warehouse[row1 - 1][col1] = 6; //when pushing 3, value 5 changes to 6 because it sits on what was value 2
			warehouse[row1][col1] = 0; //original position of 5 changes to 0
			row1 = row1 - 1; //changing row1 to current 6 position
			col1 = col1;
			warehouse[row1 - 1][col1] = 3; //moving value "4", which changes it to 3
		}
	}
	// if move is s then following if statement is followed "down"
	if (move == 's') {
		if (warehouse[row1 + 1][col1] == 0) {
			if (warehouse[row1][col1] != 6) {
				warehouse[row1 + 1][col1] = 5;
				warehouse[row1][col1] = 0;
				row1 = row1 + 1;
				col1 = col1;
			} else {
				warehouse[row1 + 1][col1] = 5;
				warehouse[row1][col1] = 2;
				row1 = row1 + 1;
				col1 = col1;
			}
		}
		else if ((warehouse[row1 + 1][col1] == 2) && (warehouse[row1][col1] != 6)){
			warehouse[row1 + 1][col1] = 6;
			warehouse[row1][col1] = 0;
			row1 = row1 + 1;
			col1 = col1;
		}else if ((warehouse[row1 + 1][col1] == 2) && (warehouse[row1][col1] == 6)) {
			warehouse[row1 + 1][col1] = 6;
			warehouse[row1][col1] = 2;
			row1 = row1 + 1;
			col1 = col1;
		} else if ((warehouse[row1 + 1][col1] == 3) && (warehouse[row1 + 2][col1] != 1) && (warehouse[row1 + 2][col1] != 3)) {
			if (warehouse[row1 + 2][col1] == 2) {
				warehouse[row1 + 1][col1] = 5;
				warehouse[row1][col1] = 0;
				row1 = row1 + 1;
				col1 = col1;
				warehouse[row1 + 1][col1] = 4;
			} else if (warehouse[row1][col1] == 6) {
				warehouse[row1 + 1][col1] = 5;
				warehouse[row1][col1] = 2;
				row1 = row1 + 1;
				col1 = col1;
				warehouse[row1 + 1][col1] = 3;
			} else {
				warehouse[row1 + 1][col1] = 5;
				warehouse[row1][col1] = 0;
				row1 = row1 + 1;
				col1 = col1;
				warehouse[row1 + 1][col1] = 3;
			}
		} else if ((warehouse[row1 + 1][col1] == 4) && (warehouse[row1 + 2][col1] != 1) && (warehouse[row1 + 2][col1] != 3)) {
			warehouse[row1 + 1][col1] = 6;
			warehouse[row1][col1] = 0;
			row1 = row1 + 1;
			col1 = col1;
			warehouse[row1 + 1][col1] = 3;
		}
	}
	// if move is a then following if statement is followed "left"
	if (move == 'a') {
		if (warehouse[row1][col1 - 1] == 0) {
			if (warehouse[row1][col1] != 6) {
				warehouse[row1][col1 - 1] = 5;
				warehouse[row1][col1] = 0;
				row1 = row1;
				col1 = col1 - 1;
			}
			else {
				warehouse[row1][col1 - 1] = 5;
				warehouse[row1][col1] = 2;
				row1 = row1;
				col1 = col1 - 1;
			}
		}
		else if ((warehouse[row1][col1 - 1] == 2) && (warehouse[row1][col1] != 6)){
			warehouse[row1][col1 - 1] = 6;
			warehouse[row1][col1] = 0;
			row1 = row1;
			col1 = col1 - 1;
		}
		else if ((warehouse[row1][col1 - 1] == 2) && (warehouse[row1][col1] == 6)) {
			warehouse[row1][col1 - 1] = 6;
			warehouse[row1][col1] = 2;
			row1 = row1;
			col1 = col1 - 1;
		}
		else if ((warehouse[row1][col1 - 1] == 3) && (warehouse[row1][col1 - 2] != 1) && (warehouse[row1][col1 - 2] != 3)) {
			if (warehouse[row1][col1 - 2] == 2) {
				warehouse[row1][col1 - 1] = 5;
				warehouse[row1][col1] = 0;
				row1 = row1;
				col1 = col1 - 1;
				warehouse[row1][col1 - 1] = 4;
			}
			else if (warehouse[row1][col1] == 6) {
				warehouse[row1][col1 - 1] = 5;
				warehouse[row1][col1] = 2;
				row1 = row1;
				col1 = col1 - 1;
				warehouse[row1][col1 - 1] = 3;
			}
			else {
				warehouse[row1][col1 - 1] = 5;
				warehouse[row1][col1] = 0;
				row1 = row1;
				col1 = col1 - 1;
				warehouse[row1][col1 - 1] = 3;
			}
		}
		else if ((warehouse[row1][col1 - 1] == 4) && (warehouse[row1][col1 - 2] != 1) && (warehouse[row1][col1 - 2] != 3)) {
			warehouse[row1][col1 - 1] = 6;
			warehouse[row1][col1] = 0;
			row1 = row1;
			col1 = col1 - 1;
			warehouse[row1][col1 - 1] = 3;
		}
	}
	// if move is d then following if statement is followed "right"
	if (move == 'd') {
		if (warehouse[row1][col1 + 1] == 0) {
			if (warehouse[row1][col1] != 6) {
				warehouse[row1][col1 + 1] = 5;
				warehouse[row1][col1] = 0;
				row1 = row1;
				col1 = col1 + 1;
			}
			else {
				warehouse[row1][col1 + 1] = 5;
				warehouse[row1][col1] = 2;
				row1 = row1;
				col1 = col1 + 1;
			}
		}
		else if ((warehouse[row1][col1 + 1] == 2) && (warehouse[row1][col1] != 6)){
			warehouse[row1][col1 + 1] = 6;
			warehouse[row1][col1] = 0;
			row1 = row1;
			col1 = col1 + 1;
		}
		else if ((warehouse[row1][col1 + 1] == 2) && (warehouse[row1][col1] == 6)) {
			warehouse[row1][col1 + 1] = 6;
			warehouse[row1][col1] = 2;
			row1 = row1;
			col1 = col1 + 1;
		}
		else if ((warehouse[row1][col1 + 1] == 3) && (warehouse[row1][col1 + 2] != 1) && (warehouse[row1][col1 + 2] != 3)) {
			if (warehouse[row1][col1 + 2] == 2) {
				warehouse[row1][col1 + 1] = 5;
				warehouse[row1][col1] = 0;
				row1 = row1;
				col1 = col1 + 1;
				warehouse[row1][col1 + 1] = 4;
			}
			else if (warehouse[row1][col1] == 6) {
				warehouse[row1][col1 + 1] = 5;
				warehouse[row1][col1] = 2;
				row1 = row1;
				col1 = col1 + 1;
				warehouse[row1][col1 + 1] = 3;
			}
			else {
				warehouse[row1][col1 + 1] = 5;
				warehouse[row1][col1] = 0;
				row1 = row1;
				col1 = col1 + 1;
				warehouse[row1][col1 + 1] = 3;
			}
		}
		else if ((warehouse[row1][col1 + 1] == 4) && (warehouse[row1][col1 + 2] != 1) && (warehouse[row1][col1 + 2] != 3)) {
			warehouse[row1][col1 + 1] = 6;
			warehouse[row1][col1] = 0;
			row1 = row1;
			col1 = col1 + 1;
			warehouse[row1][col1 + 1] = 3;
		}
	}

	//checking to see how many 2's and 5's are in array
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			if (warehouse[i][j] == 2) {
				Bcheck++;
			} else if (warehouse[i][j] == 5) {
				Wcheck++;
			}
		}
	}
	//if there is any 5's or 2's in array then returns 0, otherwise loop is finsihed and returns 1
	if ((Bcheck == 0) && (Wcheck == 0)) { //Bcheck represents 2's "boxes" & Wcheck represents 5's "worker". 5 has to successfully change to 6
		return 1;
	} else {
		return 0;
	}
}

