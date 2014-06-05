#include<stdio.h>
#include "player.h"
#include "board.h"
int main() {
    player_t player1;
    player_t player2;
    player1.player_name = "Pesho";
    player2.player_name = "Gosho";
    player1.player_mana.max_mana = 10;
    player2.player_mana.max_mana = 10;
    player1.player_mana.current_mana = player1.player_mana.max_mana;
    player2.player_mana.current_mana = player2.player_mana.max_mana;
    player1.player_hp = 30;
    player2.player_hp = 30;
    board_t player1_board;
    board_t player2_board;
    int turn = 1;
    init_board(&player1_board);
    init_board(&player2_board);
    //Creating first player START
    init_deck(&player1.player_deck);
    init_hand_cards(&player1.player_hand);
    //Creating first player END

    //Creating first player deck START
    card_t attacker1 = {"Green", 10, 10, 1};
    card_t attacker2 = {"Blue", 7, 3, 4};
    card_t attacker3 = {"Yellow", 6, 4, 5};
    card_t attacker4 = {"Red", 8, 2, 7};
    card_t attacker5 = {"Purple", 5, 8, 4};
    card_t attacker6 = {"Black", 2, 10, 2};
    card_t attacker7 = {"Brown", 3, 6, 1};
    card_t attacker8 = {"Gray", 5, 5, 2};
    card_t attacker9 = {"Orange", 6, 3, 3};
    card_t attacker10 = {"Lime", 4, 2, 1};
    //Creating first player deck END
    //push cards START
    push_card(attacker1, &player1.player_deck);
    push_card(attacker2, &player1.player_deck);
    push_card(attacker3, &player1.player_deck);
    push_card(attacker4, &player1.player_deck);
    push_card(attacker5, &player1.player_deck);
    push_card(attacker6, &player1.player_deck);
    push_card(attacker7, &player1.player_deck);
    push_card(attacker8, &player1.player_deck);
    push_card(attacker9, &player1.player_deck);
    push_card(attacker10, &player1.player_deck);

    printf("\n");
    //push cards END
    //Creating second player START
    init_deck(&player2.player_deck);
    init_hand_cards(&player2.player_hand);
    //Creating second player END

    //Creating second player deck START
    card_t defender1 = {"Dark_Green", 10, 10, 1};
    card_t defender2 = {"Dark_Blue", 2, 4, 4};
    card_t defender3 = {"Dark_Yellow", 3, 5, 5};
    card_t defender4 = {"Dark_Red", 5, 6, 7};
    card_t defender5 = {"Dark_Purple", 3, 3, 4};
    card_t defender6 = {"Dark_Black", 8, 1, 1};
    card_t defender7 = {"Dark_Brown", 2, 2, 1};
    card_t defender8 = {"Dark_Gray", 8, 1, 1};
    card_t defender9 = {"Dark_Orange", 5, 3, 2};
    card_t defender10 = {"Dark_Lime", 3, 2, 0, 1};
    //Creating second player deck END
    //Push cards START
    push_card(defender1, &player2.player_deck);
    push_card(defender2, &player2.player_deck);
    push_card(defender3, &player2.player_deck);
    push_card(defender4, &player2.player_deck);
    push_card(defender5, &player2.player_deck);
    push_card(defender6, &player2.player_deck);
    push_card(defender7, &player2.player_deck);
    push_card(defender8, &player2.player_deck);
    push_card(defender9, &player2.player_deck);
    push_card(defender10, &player2.player_deck);
    //Push cards END
    
        
    int i;
    for (i = 0; i < HAND_SIZE; i++) {
        draw_card(player1.player_deck.deck[player1.player_deck.top], &player1.player_hand, &player1.player_deck, 0);
        draw_card(player2.player_deck.deck[player2.player_deck.top], &player2.player_hand, &player2.player_deck, 0);
    }
    print_board(&player1_board, &player1, 1, turn);
    print_board(&player2_board, &player2, 2, turn);
    while (1) {
        
        play(&player1_board, &player2_board, &player1, &player2, turn);
      
        print_board(&player1_board, &player1, 1, turn);
        print_board(&player2_board, &player2, 2, turn);
        
        play(&player2_board, &player1_board, &player2, &player1, turn);
        
        printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
        
        print_board(&player1_board, &player1, 1, turn);
        print_board(&player2_board, &player2, 2, turn);
        
        turn++;
    }
    return 0;
}
