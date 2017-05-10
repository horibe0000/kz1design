#include <iostream>
#include <stdio.h>
#include <thread>
#include <exception>
#include <time.h>
#include "shogi.h"
#include "typedefinition.h"
#include "koma_move.h"


void print_board(){
    if (board[i]>=0){
      printf(" %d",board[i]);
    }
    if(board[i]<0){
      printf("%d",board[i]);
    }
    if (i%9==8){
      puts("");
    }
    if (board[i] != 0){
      n++;
    }
  }
  puts("");
  for (i=81;i<88;i++){
    printf("%d",board[i]);
  }
  puts("");
  for (i=91;i<98;i++){
    printf("%d",board[i]);
  }
  puts("");
  puts("");

}

void print_main(){
    for (;;){
        print_board();
        std::this_thread::sleep_for(std::chrono::milliseconds(50));
    }
}

void game_main(){
  init_board();
  int i = 0;
  move legalmove[300];
  int n;
  int turn = 1;
  for (;;turn *= -1){
      n = generate_legalmove(turn,legalmove);
      take_move(legalmove[rand()%n]);
      std::this_thread::sleep_for(std::chrono::milliseconds(100));
      i++;
      if (judge !=0){
        break;
      }
  }
}

int main(){
    srand(time(NULL));
    init_board();
    int i;
    try {
        std::thread t1(game_main);
        std::thread t2(print_main);
        t1.join();
        t2.join();
    } catch (std::exception &ex) {
        std::cerr << ex.what() << std::endl;
    }
}
