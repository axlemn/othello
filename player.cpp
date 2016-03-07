// Written by Alex Mun


#include "player.h"
#include "time.h"

/* HJP
 * Hong Joon Park (HJP)
 * Comments by me will be in a block preceeded by "HJP"
 */

/*
 * Constructor for the player; initialize everything here. The side your AI is
 * on (BLACK or WHITE) is passed in as "side". The constructor must finish 
 * within 30 seconds.
 */
Player::Player(Side side) {
    // Will be set to true in test_minimax.cpp.
    testingMinimax = false;

    /* 
     * DONE: Do any initialization you need to do here (setting up the board,
     * precalculating things, etc.) However, remember that you will only have
     * 30 seconds.
     */
    // HJP: Amun's var used to keep track of # of moves made so far
    moves_made = 0;
    // HJP: Keep track of the player's current side
    player_side = side;
    // HJP: Keep track of opponent's side
    if (player_side == WHITE)
    {
        opponent_side = BLACK;
    }
    else
    {
        opponent_side = WHITE;
    }

}

/*
 * Destructor for the player.
 */
Player::~Player() {
}

/*
 * Compute the next move given the opponent's last move. Your AI is
 * expected to keep track of the board on its own. If this is the first move,
 * or if the opponent passed on the last move, then opponentsMove will be NULL.
 *
 * msLeft represents the time your AI has left for the total game, in
 * milliseconds. doMove() must take no longer than msLeft, or your AI will
 * be disqualified! An msLeft value of -1 indicates no time limit.
 *
 * The move returned must be legal; if there are no valid moves for your side,
 * return NULL.
 */
Move *Player::doMove(Move *opponentsMove, int msLeft) {
    /* 
     * DONE: Implement how moves your AI should play here. You should first
     * process the opponent's opponents move before calculating your own move
     */ 
    // HJP: Implementing an AI that randomly picks a move
    // HJP: Update board to process opponent's move
    board.doMove(opponentsMove, opponent_side);

    // HJP: We now establish a list of legal moves
    std::vector<Move> legal_moves = board.possibleMoves(player_side);
    // HJP: initialize random seed
    srand (time(NULL));
    // HJP: Generate random number between 0 and length of legal_moves
    int random_move = rand() % legal_moves.size();
    // HJP: We update our board with our random move
    board.doMove(&legal_moves[random_move], player_side);
    // HJP: We return the random move among the list
    Move * move = new Move(legal_moves[random_move].getX(),
                           legal_moves[random_move].getY());
    return move;

}
