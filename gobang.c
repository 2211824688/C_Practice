#include<stdio.h>

#define BOARD_SIZE 20
#define PLAYER_1 'X'
#define PLAYER_2 'O'
#define EMPTY_CELL '.'

void print_board(char board[BOARD_SIZE][BOARD_SIZE]);   // 打印棋盘
char check_winner(char board[BOARD_SIZE][BOARD_SIZE], int x, int y, char current_player);   // 检查赢家
void print_intervals();      // 打印分隔符

int main() {
    char board[BOARD_SIZE][BOARD_SIZE];         // 棋盘
    char current_player = PLAYER_1;         // 记录当前的玩家
    char winner = EMPTY_CELL;               // 记录赢家

    // 初始化棋盘
    for (int i = 0; i < BOARD_SIZE; i++)
    {
        for (int j = 0; j < BOARD_SIZE; j++)
        {
            board[i][j] = EMPTY_CELL;
        }
    }

    while (winner == EMPTY_CELL) {
        print_board(board);
        printf("请玩家 %c 输入行数和列数(0-%d), 请使用空格隔开\n", current_player, BOARD_SIZE-1);

        int x = 0, y = 0;   // 行数和列数
        scanf("%d %d", &x, &y);
        if (x >= 0 && x < BOARD_SIZE && y >= 0 && y < BOARD_SIZE && board[x][y] == EMPTY_CELL) {
            // 有效输入
            board[x][y] = current_player;
            char c = check_winner(board, x, y, current_player);
            if (c != EMPTY_CELL) {  // 游戏结束 跳出循环
                winner = c;
                break;
            }     
            else {   // 切换玩家
                current_player = (current_player == PLAYER_1) ? PLAYER_2 : PLAYER_1;
            }                          
        } else {
            // 无效输入
            puts("当前输入无效或者当前位置已经存在棋子, 请重新检查输入");
            continue;
        }
        print_intervals();
    }

    print_board(board);
    printf("游戏结束, 玩家 %c 赢得游戏!", winner);
    return 0;
}


void print_board(char board[BOARD_SIZE][BOARD_SIZE]) {
    for (int i = 0; i < BOARD_SIZE; i++)
    {
        for (int j = 0; j < BOARD_SIZE; j++)
        {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

char check_winner(char board[BOARD_SIZE][BOARD_SIZE], int x, int y, char current_player) {
    int directions[4][2] = {{0,1}, {1,0}, {1,1}, {1, -1}};
    for (int i = 0; i < 4; i++) {
        int count = 1;              // 记录一排连续棋子数
        int dx = directions[i][0];  // 行偏移
        int dy = directions[i][1];  // 列偏移
        
        int tx = x + dx;
        int ty = y + dy;
        // 检查当前方向的连续棋子数
        while (tx >= 0 && tx < BOARD_SIZE && ty >= 0 && ty < BOARD_SIZE && board[tx][ty] == current_player) {
            count++;
            tx += dx;
            ty += dy;
        }

        // 检查当前方向反向的连续棋子数
        tx = x - dx;
        ty = y - dy;
        while (tx >= 0 && tx < BOARD_SIZE && ty >= 0 && ty < BOARD_SIZE && board[tx][ty] == current_player) {
            count++;
            tx -= dx;
            ty -= dy;
        }

        if (count >= 3) {   
            return current_player;
        }
    }
    return EMPTY_CELL;
}

void print_intervals() {
    for (int i = 0; i < BOARD_SIZE; i++) {
        printf("- ");
    }
    printf("\n");
}