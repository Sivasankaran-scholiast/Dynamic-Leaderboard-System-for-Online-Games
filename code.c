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
