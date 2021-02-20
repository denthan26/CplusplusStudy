//#include <iostream>
//#include "Sales_item.h"
//
//int main()
//{
//    Sales_item item1, item2;
//
//    std::cin >> item1 >> item2;   //read a pair of transactions
//    std::cout << item1 + item2 << std::endl; //print their sum
//
//    return 0;
//}
//#include <iostream>
//#include "Sales_item.h"
//
//int main()
//{
//    Sales_item item1, item2;
//
//    std::cin >> item1 >> item2;
//    // first check that item1 and item2 represent the same book
//    if (item1.same_isbn(item2)) {
//        std::cout << item1 + item2 << std::endl;
//        return 0;   // indicate success
//    }
//    else {
//        std::cerr << "Data must refer to same ISBN"
//            << std::endl;
//        return -1;  // indicate failure
//    }
//}

//#include <iostream>
//#include "Sales_item.h"
//
//int main()
//{
//    // declare variables to hold running sum and data for the next record 
//    Sales_item total, trans;
//
//    // is there data to process?
//    if (std::cin >> total) {
//        // if so, read the transaction records 
//        while (std::cin >> trans)
//            if (total.same_isbn(trans))
//                // match: update the running total 
//                total = total + trans;
//            else {
//                // no match: print & assign to total
//                std::cout << total << std::endl;
//                total = trans;
//            }
//        // remember to print last record
//        std::cout << total << std::endl;
//    }
//    else {
//        // no input!, warn the user
//        std::cout << "No data?!" << std::endl;
//        return -1;  // indicate failure
//    }
//
//    return 0;
//}
//#include <ctime>    //   ████████  ██████  ████████  ████████  ██  ██████  ██
//#include <curses.h> //      ██     ██         ██     ██    ██  ██  ██      ██
//#include <stdlib.h> //      ██     ████       ██     ████████  ██  ██████  ██
//#include <string.h> //      ██     ██         ██     ██  ██    ██      ██
//#include <unistd.h> //      ██     ██████     ██     ██    ██  ██  ██████  ██
//typedef int I; I x = 431424, y = 598356, r = 427089, f = 247872, g = 799248, h, c = 348480, p = 615696
//, t, a[20][10], b[7][4] = { {x,y,x,y},{r,p,r,p},{c,c,c,c},{599636,431376,598336,432192
//},{411985,610832,415808,595540},{f,g,f,g},{614928,399424,615744,428369} }, s = 0; I N
//(I x, I y) {
//	return 3 & b[p][x] >> y;
//}I S(I x, I y, I r, I v) {
//	for (I i = 0; i < 8; i += 2)a[N(r, i * 2
//	) + y][N(r, (i * 2) + 2) + x] = v;
//}I F() {
//	for (I c = 0; c < 20; c++) {
//		move(1 + c, 1); for (auto& z : a[c]) {
//			z&& attron(262176 | z << 8); printw("  "); attroff(262176 | z << 8);
//		}
//	}move(21, 1); printw("S"
//		"core: %d", s); refresh();
//}I P() {
//	y = g = 0; p = rand() % 7; r = h = rand() % 4; x = f = rand() % (10 - N(r,
//		16));
//}I U() { S(f, g, h, 0); S(f = x, g = y, h = r, p + 1); }I R() {
//	for (I q = y; q <= y + N(r, 18); q++) {
//		c = 1
//			; for (auto& z : a[q])c *= z; if (!c)continue; for (I c = q - 1; c > 0; c--)memcpy(&a[c + 1][0], &a[c
//			][0], 40); memset(&a[0][0], 0, 10); s++;
//	}
//}I C(I x, I y, I r) {
//	if (y + N(r, 18) > 19)return 1; S
//	(f, g, h, 0); c = 0; for (I i = 0; i < 8; i += 2)a[y + N(r, i * 2)][x + N(r, (i * 2) + 2)] && c++; S(f, g, h, p + 1)
//		; return c;
//}I T() {
//	if (++t > 30) {
//		t = 0; if (C(x, y + 1, r)) { if (!y)return 0; R(); P(); }
//		else y++;
//		U();
//	}return 1;
//}I L() {
//	while (T()) {
//		usleep(10000); if ((c = getch()) == 97 && x > 0 && !C(x - 1, y,
//			r))x--; if (c == 100 && x + N(r, 16) < 9 && !C(x + 1, y, r))x++; if (c == 115) {
//			while (!C(x, y + 1, r)) {
//				y++
//					; U();
//			}R(); P();
//		}if (c == 119) { ++r %= 4; while (x + N(r, 16) > 9)x--; if (C(x, y, r)) { x = f; r = h; } }if
//			(c == 113)return 0; U(); F();
//	}
//}I main() {
//	srand(time(0)); initscr(); start_color(); for (c
//		= 1; c < 8; c++) {
//		init_pair(c, c, 0);
//	}P(); resizeterm(22, 22); noecho(); timeout(0); curs_set
//	(0); box(stdscr, 0, 0); L(); endwin();
//} // Conor Taylor
#include <ctime>
#include <curses.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

// block layout is: {w-1,h-1}{x0,y0}{x1,y1}{x2,y2}{x3,y3} (two bits each)
int x = 431424, y = 598356, r = 427089, px = 247872, py = 799248, pr,
c = 348480, p = 615696, tick, board[20][10],
block[7][4] = { {x, y, x, y},
               {r, p, r, p},
               {c, c, c, c},
               {599636, 431376, 598336, 432192},
               {411985, 610832, 415808, 595540},
               {px, py, px, py},
               {614928, 399424, 615744, 428369} },
    score = 0;

// extract a 2-bit number from a block entry
int NUM(int x, int y) { return 3 & block[p][x] >> y; }

// create a new piece, don't remove old one (it has landed and should stick)
void new_piece() {
    y = py = 0;
    p = rand() % 7;
    r = pr = rand() % 4;
    x = px = rand() % (10 - NUM(r, 16));
}

// draw the board and score
void frame() {
    for (int i = 0; i < 20; i++) {
        move(1 + i, 1); // otherwise the box won't draw
        for (int j = 0; j < 10; j++) {
            board[i][j] && attron(262176 | board[i][j] << 8);
            printw("  ");
            attroff(262176 | board[i][j] << 8);
        }
    }
    move(21, 1);
    printw("Score: %d", score);
    refresh();
}

// set the value fo the board for a particular (x,y,r) piece
void set_piece(int x, int y, int r, int v) {
    for (int i = 0; i < 8; i += 2) {
        board[NUM(r, i * 2) + y][NUM(r, (i * 2) + 2) + x] = v;
    }
}

// move a piece from old (p*) coords to new
int update_piece() {
    set_piece(px, py, pr, 0);
    set_piece(px = x, py = y, pr = r, p + 1);
}

// remove line(s) from the board if they're full
void remove_line() {
    for (int row = y; row <= y + NUM(r, 18); row++) {
        c = 1;
        for (int i = 0; i < 10; i++) {
            c *= board[row][i];
        }
        if (!c) {
            continue;
        }
        for (int i = row - 1; i > 0; i--) {
            memcpy(&board[i + 1][0], &board[i][0], 40);
        }
        memset(&board[0][0], 0, 10);
        score++;
    }
}

// check if placing p at (x,y,r) will be a collision
int check_hit(int x, int y, int r) {
    if (y + NUM(r, 18) > 19) {
        return 1;
    }
    set_piece(px, py, pr, 0);
    c = 0;
    for (int i = 0; i < 8; i += 2) {
        board[y + NUM(r, i * 2)][x + NUM(r, (i * 2) + 2)] && c++;
    }
    set_piece(px, py, pr, p + 1);
    return c;
}

// slowly tick the piece y position down so the piece falls
int do_tick() {
    if (++tick > 30) {
        tick = 0;
        if (check_hit(x, y + 1, r)) {
            if (!y) {
                return 0;
            }
            remove_line();
            new_piece();
        }
        else {
            y++;
            update_piece();
        }
    }
    return 1;
}

// main game loop with wasd input checking
void runloop() {
    while (do_tick()) {
        usleep(10000);
        if ((c = getch()) == 'a' && x > 0 && !check_hit(x - 1, y, r)) {
            x--;
        }
        if (c == 'd' && x + NUM(r, 16) < 9 && !check_hit(x + 1, y, r)) {
            x++;
        }
        if (c == 's') {
            while (!check_hit(x, y + 1, r)) {
                y++;
                update_piece();
            }
            remove_line();
            new_piece();
        }
        if (c == 'w') {
            ++r %= 4;
            while (x + NUM(r, 16) > 9) {
                x--;
            }
            if (check_hit(x, y, r)) {
                x = px;
                r = pr;
            }
        }
        if (c == 'q') {
            return;
        }
        update_piece();
        frame();
    }
}

// init curses and start runloop
int main() {
    srand(time(0));
    initscr();
    start_color();
    // colours indexed by their position in the block
    for (int i = 1; i < 8; i++) {
        init_pair(i, i, 0);
    }
    new_piece();
    resizeterm(22, 22);
    noecho();
    timeout(0);
    curs_set(0);
    box(stdscr, 0, 0);
    runloop();
    endwin();
}












