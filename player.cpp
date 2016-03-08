// Written by Alex Mun and Hong Joon Park

#include "player.h"
#include "time.h"

/* HJP
 * Hong Joon Park (HJP)
 * Comments by me will be in a block preceeded by "HJP"
 */

/* HJP
 * TODO:
 * 1) [DONE]Create a board object (done in player.h upon Player construction)
 * 2) [DONE]Initialize moves_made (Amun's var to keep track of # of moves made)
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
     * TODO: Do any initialization you need to do here (setting up the board,
     * precalculating things, etc.) However, remember that you will only have
     * 30 seconds.
     */
    moves_made = 0;

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
     * TODO: Implement how moves your AI should play here. You should first
     * process the opponent's opponents move before calculating your own move
     */ 

    // start_time = timestamp()

    // num_moves = number of moves left for US to take
    // end_time = start_time + frac_use[this.moves_made] * msLeft
    
    /*
    end_time = start_time + (msLeft-100) * frac_time
    // Small amount of buffer time allotted to perform the move
    next_move = DEFAULT  TODO: determine default
    */

    std::vector<Board>;
    board_ahead = this.board.copy();
    /*
    while (current_time < end_time){
        board_ahead.valid_move(); // TODO: What's the return type here?
        for possible move in 
    // TODO refine next_move calculation
        current_time = SET;
    }
    */

    // Perform the move somehow.

    return NULL;
}
