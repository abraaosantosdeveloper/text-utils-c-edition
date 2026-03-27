#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#ifdef _WIN32
#include <windows.h>
#ifdef BACKGROUND_RED
#undef BACKGROUND_RED
#endif
#ifdef BACKGROUND_GREEN
#undef BACKGROUND_GREEN
#endif
#ifdef BACKGROUND_BLUE
#undef BACKGROUND_BLUE
#endif
#endif
#include "text_utils.h"

#ifndef BACKGROUND_GREEN
#define BACKGROUND_GREEN "\x1b[42m"
#endif

int main(void)
{
    clear_screen();

    print_title_bar_heavy("Demo TextUtils em C", BOLD_BLUE, BOLD_WHITE);

    gotoxy(1, 5);
    print_red("Texto em vermelho");
    gotoxy(1, 6);
    print_green("Texto em verde");
    gotoxy(1, 7);
    print_yellow("Texto em amarelo");
    gotoxy(1, 8);
    print_blue("Texto em azul");

    /* caixas */
    draw_simple_box(1, 10, 30, 5, BRIGHT_CYAN);
    draw_double_box(35, 10, 30, 5, BRIGHT_GREEN);
    draw_round_box(69, 10, 30, 5, BRIGHT_MAGENTA);

    /* tabela com cabeçalho */
    const char *headers[] = {"ID", "Nome", "Valor"};
    const int alignments[] = {ALIGN_LEFT, ALIGN_LEFT, ALIGN_RIGHT};
    const char *data[3][3] = {
        {"1", "Item A", "10.0"},
        {"2", "Item B", "1234.56"},
        {"3", "Outro item", "7.89"}};

    draw_table_with_headers(1, 16, 15,
                            3,
                            headers,
                            3,
                            data,
                            WHITE,
                            WHITE,
                            BOLD_YELLOW,
                            alignments);

    /* barra de progresso animada */
    for (int p = 0; p <= 100; p += 10)
    {
        print_progress_bar(p, 24, WHITE, GREEN, WHITE, BACKGROUND_GREEN);
        print_info("Carregando...");
#ifdef _WIN32
        Sleep(300);
#else
        struct timespec ts = {0, 300 * 1000000};
        nanosleep(&ts, NULL);
#endif
    }
    print_success("Concluido!");

    /* campo de edição só visual */
    draw_edit_field("Nome:", 21, WHITE, WHITE);

    gotoxy(1, 30);
    printf(RESET);
    printf("\nPressione ENTER para sair...");
    getchar();

    return 0;
}
