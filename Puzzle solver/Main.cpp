#include "Water_State.h"
#include "Water.h"
#include "Puzzle_solver.h"
#include "Puzzle.h"
#include <iostream>
#include <vector>

int main(){
    Water game;
    Puzzle_solver<Water_State> solution(&game);
    solution.solve();
}
