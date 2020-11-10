/*
Longest Common Subsequence problem solved using a recursive approach
*/

#include <iostream>
#include <algorithm>
#include <iomanip>
using namespace std;

// Make global so it can be accessible across all functions
const int MAX_SIZE = 20;
int lengths[MAX_SIZE][MAX_SIZE];
char directions[MAX_SIZE][MAX_SIZE];

void printLCS(string sequence, int i, int j);
void longestLength(int i, int j);

// Begin the program
int main() {

	string seqOne = "";
	string seqTwo = "";

	cout << "Please enter the first subsequence of length 20 or less: ";
	cin >> seqOne;
	cout << "Please enter the second subsequence of length 20 or less: ";
	cin >> seqTwo;

	int oneLength = seqOne.length();
	int twoLength = seqTwo.length();

	if (oneLength > MAX_SIZE || seqTwo.length() > MAX_SIZE) {
		cout << "You've entered a subsequence of length greater than 20. Program will now exit.";
		exit(EXIT_FAILURE);
	}

	// Create boundary values that equal to 0
	for (size_t i = 1; i <= oneLength; i++) {
		lengths[i][0] = 0;
	}
	for (size_t i = 1; i <= twoLength; i++) {
		lengths[0][i] = 0;
	}

	// Populate both tables with lengths/directions
	for (size_t i = 1; i <= oneLength; i++) {
		for (size_t j = 1; j <= twoLength; j++) {
			if (seqOne.at(i - 1) == seqTwo.at(j - 1)) {
				lengths[i][j] = lengths[i - 1][j - 1] + 1;
				directions[i][j] = 'd';
			}
			else if (lengths[i - 1][j] >= lengths[i][j - 1]) {
				lengths[i][j] = lengths[i - 1][j];
				directions[i][j] = 'u';
			}
			else {
				lengths[i][j] = lengths[i][j - 1];
				directions[i][j] = 'l';
			}
		}
	}
	
	longestLength(oneLength, twoLength);
	cout << endl << "Here's a sequence: ";
	printLCS(seqOne, oneLength, twoLength);
}

// Print the strings
void printLCS(string sequence, int i, int j) {

	if (i == 0 || j == 0) { return; }
	if (directions[i][j] == 'd') {
		printLCS(sequence, i - 1, j - 1);
		cout << sequence.at(i-1);
	}
	else if (directions[i][j] == 'u') {
		printLCS(sequence, i - 1, j);
	}
	else {
		printLCS(sequence, i, j - 1);
	}
}

// Find the longest length
void longestLength(int i, int j) {

	int longest = 0;

	for (int x = 0; x <= i; x++) {
		for (int y = 0; y <= j; y++) {
			cout << left << setw(2) << setfill(' ') << lengths[x][y];
			longest = max(longest, lengths[x][y]);
		}
		cout << endl;
	}
	cout << "The length of the longest subsequence is " << longest;
}