Dynamic Leaderboard System for Online Games
BACSE105 Data Structures and Algorithms (FALL 2025-2026)
Sivasankaran Sankar - 25BCE2650
Course Instructor: Dr. P. Antony Seba
SCHOOL OF COMPUTER SCIENCE AND ENGINEERING
VELLORE INSTITUTE OF TECHNOLOGY
VELLORE
April 7, 2026
Problem Statement
In online games, players gain or lose points continuously. The system must maintain a leaderboard that shows players in descending order of scores. It should also allow score updates, display the highest scoring players, and find the rank of a specific player efficiently.
Objective
The objective of this project is to design and implement a leaderboard system that stores player details, updates scores, sorts players based on scores, displays rankings, retrieves the top players, and finds the rank of any player.
Data (Data fields used to build solution)
The data fields used are Player ID, Player Name, and Player Score. Player ID is unique for each player. Player Name identifies the player, and Player Score is used to determine ranking.
Data Structures Used
This project uses an array of structures. Each structure stores the details of one player such as ID, name, and score. The array is used to manage all players, and sorting is used to maintain leaderboard order.
Algorithm Design
First, player details are stored in an array. Whenever a new player is added, the details are inserted into the array. When a player’s score is updated, the corresponding score is modified. After every insertion or update, the array is sorted in descending order of score. To display the leaderboard, the sorted array is printed from top to bottom. To get the top-k players, the first k records are displayed.
To find a player’s rank, the array is searched after sorting, and the position is returned as rank.
Optimization Techniques
A simple direct approach is used so that the logic is easy to understand and implement. Structures are used to organize player details neatly. Sorting after updates ensures correct ranking at all times. This approach is suitable for small datasets and clearly demonstrates core DSA concepts.
Implementation
#include <stdio.h>
#include <string.h>
#define MAX 100
struct Player {
int id;
char name[50];
int score;
};
struct Player players[MAX];
int n = 0;
void sortLeaderboard() {
int i, j;
struct Player temp;
for (i = 0; i < n - 1; i++) {
for (j = 0; j < n - i - 1; j++) {
if (players[j].score < players[j + 1].score) {
temp = players[j];
players[j] = players[j + 1];
players[j + 1] = temp;
}
}
}
}
void addPlayer(int id, char name[], int score) {
players[n].id = id;
strcpy(players[n].name, name);
players[n].score = score;
n++;
sortLeaderboard();
}
void updateScore(int id, int newScore) {
int i;
for (i = 0; i < n; i++) {
if (players[i].id == id) {
players[i].score = newScore;
break;
}
}
sortLeaderboard();
}
void displayLeaderboard() {
int i;
printf("\nLeaderboard:\n");
printf("Rank\tID\tName\tScore\n");
for (i = 0; i < n; i++) {
printf("%d\t%d\t%s\t%d\n", i + 1, players[i].id, players[i].name, players[i].score);
}
}
void getTopK(int k) {
int i;
printf("\nTop %d Players:\n", k);
printf("Rank\tID\tName\tScore\n");
for (i = 0; i < k && i < n; i++) {
printf("%d\t%d\t%s\t%d\n", i + 1, players[i].id, players[i].name, players[i].score);
}
}
void getRank(int id) {
int i;
for (i = 0; i < n; i++) {
if (players[i].id == id) {
printf("\nPlayer %s (ID: %d) Rank = %d\n", players[i].name, id, i + 1);
return;
}
}
printf("\nPlayer not found.\n");
}
int main() {
addPlayer(1, "Andrew", 120);
addPlayer(2, "Tom", 200);
addPlayer(3, "Jack", 150);
displayLeaderboard();
updateScore(1, 250);
displayLeaderboard();
getTopK(2);
getRank(3);
updateScore(3, 300);
displayLeaderboard();
return 0;
}
Sample Input and Output
Set 1 Input: Add Player 1 Andrew 120, Add Player 2 Tom 200, Add Player 3 Jack 150 Output:
1.
Tom – 200
2.
Jack – 150
3.
Andrew – 120
Set 2 Input: Update Andrew score to 250 Output:
1.
Andrew – 250
2.
Tom – 200
3.
Jack – 150
Set 3 Input: Get Top 2 Players Output:
1.
Andrew – 250
2.
Tom – 200
Set 4 Input: Get Rank of Player ID 3 Output: Rank of Jack = 3
Set 5 Input: Update Jack score to 300 Output:
1.
Jack – 300
2.
Andrew – 250
3.
Tom – 200
Time and Space Complexity Analysis
Adding a player takes O(1), but sorting takes O(n²). Updating a score takes O(n) for search and O(n²) for sorting. Displaying leaderboard takes O(n). Top-k retrieval takes O(k). Finding rank takes O(n). Space complexity is O(n).
Conclusion
This project implements a simple and effective leaderboard system. It demonstrates the use of arrays, structures, sorting, and searching. The system correctly handles updates, rankings, and queries, making it suitable for understanding fundamental DSA concepts.
References
[1] T. H. Cormen, C. E. Leiserson, R. L. Rivest and C. Stein, Introduction to Algorithms, 3rd ed., Cambridge, MA, USA: MIT Press, 2009.
[2] R. Thareja, Data Structures Using C, 2nd ed., New Delhi, India: Oxford University Press, 2014.
[3] B. W. Kernighan and D. M. Ritchie, The C Programming Language, 2nd ed., Englewood Cliffs, NJ, USA: Prentice Hall, 1988.
[4] GeeksforGeeks, “Data Structures,” [Online]. Available: https://www.geeksforgeeks.org/data-structures/
[5] GeeksforGeeks, “Sorting Algorithms,” [Online]. Available: https://www.geeksforgeeks.org/sorting-algorithms/
