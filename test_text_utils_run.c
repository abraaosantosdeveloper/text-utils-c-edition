#include <stdio.h>
#include "text_utils.h"

int main(void)
{
    clear_screen();

    print_title_bar("Teste rapido da biblioteca", BOLD_CYAN, BOLD_WHITE);

    gotoxy(1, 5);
    print_red("Mensagem de erro simulada");
    gotoxy(1, 6);
    print_green("Mensagem de sucesso simulada");
    gotoxy(1, 7);
    print_yellow("Mensagem de alerta simulada");
    gotoxy(1, 8);
    print_blue("Mensagem informativa simulada");

    draw_simple_box(1, 10, 25, 4, BRIGHT_CYAN);
    draw_double_box(28, 10, 25, 4, BRIGHT_GREEN);

    {
        const char *headers[] = {"ID", "Nome", "Pontos"};
        const int aligns[] = {ALIGN_LEFT, ALIGN_LEFT, ALIGN_RIGHT};
        const char *rows[2][3] = {
            {"1", "Ana", "10"},
            {"2", "Bruno", "9"}};

        draw_table_with_headers(1, 15, 12,
                                3,
                                headers,
                                2,
                                rows,
                                WHITE,
                                WHITE,
                                BOLD_YELLOW,
                                aligns);
    }

    print_progress_bar(68.0, 23, WHITE, GREEN, WHITE, BACKGROUND_BRIGHT_GREEN);
    print_info("Teste de interface em andamento");
    print_success("Funcoes executadas com sucesso");

    gotoxy(1, 30);
    printf(RESET "\nTeste finalizado. Pressione ENTER para sair...\n");
    getchar();
    return 0;
}
