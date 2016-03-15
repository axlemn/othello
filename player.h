#ifndef __PLAYER_H__
#define __PLAYER_H__

#include <iostream>
#include "common.h"
#include "board.h"
#include <stdlib.h>
#include <time.h> 
using namespace std;

class Player {

public:
    Player(Side side);
    ~Player();
    
    Move *doMove(Move *opponentsMove, int msLeft);
    Move *doMinimaxMove(Move *opponentsMove, int msLeft, int iter);
    Move *doSimpleMove(Move *opponentsMove, int msLeft);

    // AMUN: Overwrites current board with given board.
    void setBoard(Board *board);

    // Flag to tell if the player is running within the test_minimax context
    bool testingMinimax;

private:
	Board board;
	int moves_made;
	Side player_side;
	Side opponent_side;

};

#endif
