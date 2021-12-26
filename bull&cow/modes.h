#include "interface.h"
#include <conio.h>


void start(){

    menu();
    char c;
    c = getch();
    switch (c) {
        case 49:
            rules();
            break;
        case 50:
            computer();
            break;
        case 51:
            player();
            break;
        case 52:
            break;
        default:
            start();
    }
}

void computer()
{
    int turn;
    int lose = 0;
    number created;
    created.random();

    with_computer(1);
    cin >> turn;

    number cnv_turn = cnv_turn.convert(turn);
    while (cnv_turn.fwd_convert() != turn)
    {
        cin >> turn;
        cnv_turn = cnv_turn.convert(turn);
    }
    game_table list;
    list.clear();
    state check;
    check.init();
    char c;
    with_computer(4);
    check = check.checkout(created, cnv_turn);
    list.make_turn(check, cnv_turn);
    list.show();
    while (!check.victory()){

        if (!check.victory()){
            with_computer(2);
        }
        check.init();
        cin >> turn;
        number cnv_turn = cnv_turn.convert(turn);
        while (cnv_turn.fwd_convert() != turn)
        {
            cin >> turn;
            cnv_turn = cnv_turn.convert(turn);
        }
        with_computer(4);
        check = check.checkout(created, cnv_turn);
        list.make_turn(check, cnv_turn);
        list.show();
        if (list.list.size() == 10){
            lose = 1;
            break;
        }
    }
    if (lose != 1){
        with_computer(3);
    }
    else{
        with_computer(5);
        with_computer(7);
        created.print();
    }
    with_computer(6);
    c = getch();
    if (c == 78 || c == 110) {
        start();
    }
    else if (c == 89 || c == 121)
        computer();
}

void player(){

    int num;
    int turn;
    int lose;

    with_player(1);
    cin >> num;

    number created;
    created = created.convert(num);
    with_player(3);
    cin >> turn;

    number cnv_turn = cnv_turn.convert(turn);
    while (cnv_turn.fwd_convert() != turn)
    {
        cin >> turn;
        cnv_turn = cnv_turn.convert(turn);
    }
    game_table list;
    list.clear();
    state check;
    check.init();
    char c;
    with_player(4);
    check = check.checkout(created, cnv_turn);
    list.make_turn(check, cnv_turn);
    list.show();
    while (!check.victory()){

        if (!check.victory()){
            with_player(2);
        }
        check.init();
        cin >> turn;
        number cnv_turn = cnv_turn.convert(turn);
        while (cnv_turn.fwd_convert() != turn)
        {
            cin >> turn;
            cnv_turn = cnv_turn.convert(turn);
        }
        with_player(4);
        check = check.checkout(created, cnv_turn);
        list.make_turn(check, cnv_turn);
        list.show();
        if (list.list.size() == 10){
            lose = 1;
            break;
        }
    }
    if (lose != 1){
        with_player(5);
    }
    else{
        with_player(6);
    }
    with_player(7);
    c = getch();
    if (c == 78 || c == 110) {
        start();
    }
    else if (c == 89 || c == 121)
        computer();
}




