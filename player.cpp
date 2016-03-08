// Written by Alex Mun and Hong Joon Park

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
    // HJP: Implementing an AI that greedily picks the move that gets the most
    // points.

    /* AMUN: Pseudocode for using multiple minimax steps
    // start_time = timestamp()

    // num_moves = number of moves left for US to take
    // end_time = start_time + frac_use[this.moves_made] * msLeft
    
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

    // HJP: Update board to process opponent's move
    board.doMove(opponentsMove, opponent_side);
    // HJP: We now establish a list of legal moves
    std::vector<Move> legal_moves = board.possibleMoves(player_side);

    // HJP: For debugging; prints list of possible moves
    // std::cerr << "List of Moves:" << std::endl;
    // for (int i = 0; i < legal_moves.size(); i++)
    // {
    //     std::cerr << "(" << legal_moves[i].getX() << ", " << legal_moves[i].getY() << ")" << std::endl;
    // }
    

    // HJP: Establish a temp. var. holding the max points to gain & the move
    // that gets those points
    int current_max = -1;
    Move * move;

    // HJP: If we have no legal moves
    if (!legal_moves.size())
    {
        return NULL;
    }
    else
    {
        // HJP: Iterate through the list of moves
        for(int i = 0; i < legal_moves.size(); i++)
        {
            // HJP: Clone board into test board for calculating pieces won
            Board * testboard = board.copy();
            testboard->doMove(&legal_moves[i], player_side);
            if (current_max < testboard->count(player_side))
            {
                current_max = testboard->count(player_side);
                move = &legal_moves[i];
            }
            // HJP: Free testboard
            delete testboard;
        }
    }
    // HJP: dynamically allocate space for returning our greedy move
    Move * return_move = new Move(move->getX(), move->getY());

    // HJP: Update the board with new move
    board.doMove(return_move, player_side);
    return return_move;
}
