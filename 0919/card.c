#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct {
    int order;     
    char shape[4]; 
    int number;
    char face[3];
} trump;

void make_card(trump m_card[]) {
    int i, j;
    char shape[4][4] = {"♠", "◆", "♥", "♣"};

    for (i = 0; i < 4; i++) {
        for (j = i * 13; j < i * 13 + 13; j++) {
            m_card[j].order = i;
            strcpy(m_card[j].shape, shape[i]);
            m_card[j].number = j % 13 + 1;

            switch (m_card[j].number) {
                case 1:  strcpy(m_card[j].face, "A"); break;
                case 11: strcpy(m_card[j].face, "J"); break;
                case 12: strcpy(m_card[j].face, "Q"); break;
                case 13: strcpy(m_card[j].face, "K"); break;
                default: sprintf(m_card[j].face, "%d", m_card[j].number);
            }
        }
    }
}

void print_card(trump m_card[]) {
    int i;
    for (i = 0; i < 52; i++) {
        printf("%s %-2s ", m_card[i].shape, m_card[i].face);

        if ((i + 1) % 13 == 0) printf("\n");
    }
}

void shuffle_card(trump m_card[]) {
    int i, rnd;
    trump temp;

    srand((unsigned)time(NULL));
    for (i = 0; i < 52; i++) {
        do {
            rnd = rand() % 52;
        } while (rnd == i);  

        temp = m_card[i];
        m_card[i] = m_card[rnd];
        m_card[rnd] = temp;
    }
}
int main() {
    trump m_card[52];
    make_card(m_card);

    printf("===== 생성된 카드 =====\n");
    print_card(m_card);
    shuffle_card(m_card);

    printf("\n===== 섞은 카드 =====\n");
    print_card(m_card);

    return 0;
}