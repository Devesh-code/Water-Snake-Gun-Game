 #include <iostream>
 #include <ctime>
 #include <cstdlib>
 #include <string>
 using namespace std;
 enum class Move { WATER, SNAKE, GUN };
 Move getPlayerMove(int playerNumber) {
     cout << "Player " << playerNumber << ", enter your move (water, snake, or gun): ";
     string input;
     cin >> input;
     if (input == "water")
         return Move::WATER;
     else if (input == "snake")
         return Move::SNAKE;
     else if (input == "gun")
         return Move::GUN;
     else {
         cout << "Invalid move! Please try again.\n";
         return getPlayerMove(playerNumber);
     }
 }
 string moveToString(Move move) {
     switch (move) {
         case Move::WATER:
             return "Water";
         case Move::SNAKE:
             return "Snake";
         case Move::GUN:
             return "Gun";
         default:
             return "Unknown";
     }
 }
 void determineWinner(Move player1Move, Move player2Move, int& player1Score, int& player2Score) {
     cout << "Player 1 chose: " << moveToString(player1Move) << endl;
     cout << "Player 2 chose: " << moveToString(player2Move) << endl;
     if (player1Move == player2Move) {
         cout << "It's a tie!\n";
     } else if ((player1Move == Move::WATER && player2Move == Move::GUN) ||
                (player1Move == Move::GUN && player2Move == Move::SNAKE) ||
                (player1Move == Move::SNAKE && player2Move == Move::WATER)) {
         cout << "Player 1 wins!\n";
         player1Score++;
     } else {
         cout << "Player 2 wins!\n";
         player2Score++;
     }
 }
 int main() {
     cout << "Welcome to Water Snake Gun!\n";
     int player1Score = 0;
     int player2Score = 0;
     char playAgain = 'y';
     while (playAgain == 'y') {
         Move player1Move, player2Move;
         player1Move = getPlayerMove(1);
         player2Move = getPlayerMove(2);
         determineWinner(player1Move, player2Move, player1Score, player2Score);
         cout << "Scores - Player 1: " << player1Score << ", Player 2: " << player2Score << endl;
         cout << "Play again? (y/n): ";
         cin >> playAgain;
         cout << endl;
     }
     cout << "Final Scores - Player 1: " << player1Score << ", Player 2: " << player2Score << endl;
     if (player1Score > player2Score)
         cout << "Player 1 is the winner!\n";
     else if (player2Score > player1Score)
         cout << "Player 2 is the winner!\n";
     else
         cout << "It's a tie!\n";
     cout << "Thanks for playing!\n";
     return 0;
 }