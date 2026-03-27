#include <stdio.h>
#include "text_utils.h"

int main(void)
{
    const char *ascii_border[8] = {
        "+", "+", "|", "+", "|", "+", "-", "-"};

    char short_name[20];

    /* Fase 1: smoke test rapido para cobrir todos os metodos da API. */
    clear_screen();

    print_title_bar("Tmp Title", BOLD_BLUE, BOLD_WHITE);
    print_title_bar_double("Tmp Title", BOLD_GREEN, BOLD_WHITE);
    print_title_bar_broad("Tmp Title", BOLD_CYAN, BOLD_WHITE);
    print_title_bar_heavy("Tmp Title", BOLD_MAGENTA, BOLD_WHITE);
    print_title_bar_round("Tmp Title", BOLD_YELLOW, BOLD_BLACK);

    draw_simple_box(2, 5, 20, 3, BRIGHT_CYAN);
    draw_heavy_box(24, 5, 20, 3, BRIGHT_GREEN);
    draw_double_box(46, 5, 20, 3, BRIGHT_YELLOW);
    draw_broad_box(68, 5, 20, 3, BRIGHT_BLUE);
    draw_round_box(90, 5, 20, 3, BRIGHT_MAGENTA);
    draw_box(2, 9, 30, 4, BRIGHT_RED, ascii_border);

    {
        const char *grid_data[2][2] = {
            {"A1", "A2"},
            {"B1", "B2"}};
        const int aligns[2] = {ALIGN_LEFT, ALIGN_RIGHT};
        const char *headers[2] = {"Col1", "Col2"};

        draw_table_grid(2, 14, 2, 2, 8, WHITE);
        draw_table(25, 14, 8, 2, 2, grid_data, WHITE, BRIGHT_CYAN, aligns);
        draw_table_with_headers(48, 14, 8, 2, headers, 2, grid_data, WHITE, WHITE, BOLD_YELLOW, aligns);
    }

    gotoxy(2, 20);
    print_colored("print_colored", BOLD_WHITE);
    gotoxy(2, 21);
    print_colored_end("print_colored_end", BRIGHT_GREEN, "\n");
    gotoxy(2, 22);
    print_red("print_red");
    gotoxy(2, 23);
    print_green("print_green");
    gotoxy(2, 24);
    print_yellow("print_yellow");
    gotoxy(2, 25);
    print_blue("print_blue");

    trim_str(short_name, "Nome extremamente comprido para teste", 16);
    gotoxy(2, 26);
    print_colored_end(short_name, BOLD_CYAN, "\n");

    print_progress_bar(67.5, 24, WHITE, GREEN, WHITE, BACKGROUND_GREEN);
    draw_edit_field("Entrada:", 21, WHITE, WHITE);
    print_status_bar("Status bar ativa", BOLD_WHITE);
    print_success("ok");
    print_info("info");
    print_warning("warn");
    print_error("error");

    /* Fase 2: tela final para screenshot em duas colunas. */
    clear_screen();

    print_title_bar("Text Utils - Demo", BOLD_BLUE, BOLD_WHITE);

    draw_round_box(2, 4, 57, 22, BRIGHT_CYAN);
    draw_round_box(62, 4, 57, 22, BRIGHT_GREEN);

    gotoxy(4, 6);
    print_colored("Coluna Esquerda", BOLD_BRIGHT_CYAN);
    gotoxy(4, 7);
    print_colored_end("Nomes coloridos:", BOLD_WHITE, "\n");
    gotoxy(4, 8);
    print_red("Alice");
    gotoxy(4, 9);
    print_green("Bruno");
    gotoxy(4, 10);
    print_yellow("Carla");
    gotoxy(4, 11);
    print_blue("Diego");

    trim_str(short_name, "Personagem com nome bem longo", 16);
    gotoxy(4, 12);
    print_colored_end("Trim: ", WHITE, "");
    print_colored_end(short_name, BRIGHT_CYAN, "\n");

    draw_box(4, 13, 25, 4, BRIGHT_YELLOW, ascii_border);
    gotoxy(6, 14);
    print_colored("Mensagem em borda", BOLD_YELLOW);
    gotoxy(6, 15);
    print_colored("ASCII custom", BRIGHT_YELLOW);

    draw_table_grid(31, 13, 2, 2, 12, BRIGHT_CYAN);
    gotoxy(32, 14);
    print_aligned("HP", 12, ALIGN_LEFT, WHITE);
    gotoxy(45, 14);
    print_aligned("Mana", 12, ALIGN_RIGHT, WHITE);
    gotoxy(32, 16);
    print_aligned("120", 12, ALIGN_CENTER, BRIGHT_GREEN);
    gotoxy(45, 16);
    print_aligned("80", 12, ALIGN_CENTER, BRIGHT_BLUE);

    gotoxy(4, 19);
    print_colored("Bordas extras:", BOLD_WHITE);
    draw_simple_box(4, 20, 10, 3, BRIGHT_CYAN);
    draw_heavy_box(15, 20, 10, 3, BRIGHT_GREEN);
    draw_double_box(26, 20, 10, 3, BRIGHT_MAGENTA);
    draw_broad_box(37, 20, 10, 3, BRIGHT_YELLOW);
    draw_round_box(48, 20, 10, 3, BRIGHT_BLUE);

    gotoxy(64, 6);
    print_colored("Coluna Direita", BOLD_BRIGHT_GREEN);

    {
        const char *headers[] = {"ID", "Nome", "Saldo"};
        const int aligns[] = {ALIGN_LEFT, ALIGN_LEFT, ALIGN_RIGHT};
        const char *rows[3][3] = {
            {"01", "Aldoria", "1500"},
            {"02", "Brisna", "980"},
            {"03", "Cypher", "12340"}};

        draw_table_with_headers(64, 7, 10, 3, headers, 3, rows, WHITE, WHITE, BOLD_YELLOW, aligns);
    }

    {
        const int aligns2[] = {ALIGN_LEFT, ALIGN_RIGHT, ALIGN_CENTER};
        const char *rows2[2][3] = {
            {"Poção", "12", "OK"},
            {"Elixir", "4", "LOW"}};

        draw_table(64, 16, 10, 2, 3, rows2, BRIGHT_GREEN, BRIGHT_CYAN, aligns2);
    }

    gotoxy(64, 22);
    print_colored("Barras de progresso:", BOLD_WHITE);
    gotoxy(64, 23);
    print_colored("[#####-----] 50%", BRIGHT_GREEN);
    gotoxy(64, 24);
    print_colored("[########--] 80%", BRIGHT_CYAN);

    gotoxy(1, 27);
    printf(RESET "\nPressione ENTER para sair...\n");
    getchar();

    return 0;
}
