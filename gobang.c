#include<stdio.h>

#define BOARD_SIZE 20
#define PLAYER_1 'X'
#define PLAYER_2 'O'
#define EMPTY_CELL '.'

void print_board(char board[BOARD_SIZE][BOARD_SIZE]);   // ��ӡ����
char check_winner(char board[BOARD_SIZE][BOARD_SIZE], int x, int y, char current_player);   // ���Ӯ��
void print_intervals();      // ��ӡ�ָ���

int main() {
    char board[BOARD_SIZE][BOARD_SIZE];         // ����
    char current_player = PLAYER_1;         // ��¼��ǰ�����
    char winner = EMPTY_CELL;               // ��¼Ӯ��

    // ��ʼ������
    for (int i = 0; i < BOARD_SIZE; i++)
    {
        for (int j = 0; j < BOARD_SIZE; j++)
        {
            board[i][j] = EMPTY_CELL;
        }
    }

    while (winner == EMPTY_CELL) {
        print_board(board);
        printf("����� %c ��������������(0-%d), ��ʹ�ÿո����\n", current_player, BOARD_SIZE-1);

        int x = 0, y = 0;   // ����������
        scanf("%d %d", &x, &y);
        if (x >= 0 && x < BOARD_SIZE && y >= 0 && y < BOARD_SIZE && board[x][y] == EMPTY_CELL) {
            // ��Ч����
            board[x][y] = current_player;
            char c = check_winner(board, x, y, current_player);
            if (c != EMPTY_CELL) {  // ��Ϸ���� ����ѭ��
                winner = c;
                break;
            }     
            else {   // �л����
                current_player = (current_player == PLAYER_1) ? PLAYER_2 : PLAYER_1;
            }                          
        } else {
            // ��Ч����
            puts("��ǰ������Ч���ߵ�ǰλ���Ѿ���������, �����¼������");
            continue;
        }
        print_intervals();
    }

    print_board(board);
    printf("��Ϸ����, ��� %c Ӯ����Ϸ!", winner);
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
        int count = 1;              // ��¼һ������������
        int dx = directions[i][0];  // ��ƫ��
        int dy = directions[i][1];  // ��ƫ��
        
        int tx = x + dx;
        int ty = y + dy;
        // ��鵱ǰ���������������
        while (tx >= 0 && tx < BOARD_SIZE && ty >= 0 && ty < BOARD_SIZE && board[tx][ty] == current_player) {
            count++;
            tx += dx;
            ty += dy;
        }

        // ��鵱ǰ�����������������
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