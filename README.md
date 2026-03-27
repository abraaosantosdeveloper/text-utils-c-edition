# Text Utils C

Biblioteca utilitaria em C para interfaces de terminal com:
- cores ANSI
- posicionamento de cursor
- desenho de caixas e tabelas
- barras de titulo, status e progresso

## Demonstração

Abaixo, dois prints do arquivo de demonstração que está presente no repositório para executar:

![Demonstracao da biblioteca](/docs/Demo1.png)
![Demonstracao da biblioteca](/docs/Demo2.png)


## Estrutura do projeto

- `text_utils.h`: macros e prototipos publicos.
- `text_utils_methods.c`: implementacao de todos os metodos.

## Como usar

Inclua o cabecalho no seu arquivo C:

```c
#include "text_utils.h"
```

Compile junto com a implementacao:

```bash
gcc seu_programa.c text_utils_methods.c -o app
```

## Constantes disponiveis

### Cores de texto

Exemplos: `RED`, `GREEN`, `BLUE`, `WHITE`, `BOLD_CYAN`, `BOLD_WHITE`.

### Cores de fundo

Exemplos: `BACKGROUND_RED`, `BACKGROUND_GREEN`, `BACKGROUND_BRIGHT_BLUE`.

### Reset de estilo

- `RESET`: restaura estilo/paleta padrao no terminal.

### Alinhamento

- `ALIGN_LEFT`
- `ALIGN_CENTER`
- `ALIGN_RIGHT`

## Metodos da biblioteca

### Impressao colorida

#### `void print_colored(const char *s, const char *color)`
Imprime uma string com a cor informada e reseta o estilo ao final.

#### `void print_colored_end(const char *s, const char *color, const char *end)`
Imprime string com cor e permite definir sufixo final (ex.: `"\n"`).

#### `void print_red(const char *s)`
Atalho para imprimir texto em vermelho com quebra de linha.

#### `void print_green(const char *s)`
Atalho para imprimir texto em verde com quebra de linha.

#### `void print_yellow(const char *s)`
Atalho para imprimir texto em amarelo com quebra de linha.

#### `void print_blue(const char *s)`
Atalho para imprimir texto em azul com quebra de linha.

### Cursor e tela

#### `void gotoxy(int x, int y)`
Move o cursor para a posicao `(x, y)` no terminal.

#### `void clear_screen(void)`
Limpa a tela e reposiciona o cursor no inicio.

### Utilitario de string

#### `void trim_str(char *dst, const char *src, int size)`
Copia `src` para `dst` limitando tamanho e truncando com reticencias quando necessario.

### Desenho de caixas

#### `void draw_box(int x, int y, int w, int h, const char *color, const char *charset[8])`
Desenha uma caixa generica na posicao `(x, y)` com largura `w`, altura `h`, cor e conjunto de caracteres de borda.

#### `void draw_simple_box(int x, int y, int w, int h, const char *color)`
Desenha caixa simples (borda leve).

#### `void draw_heavy_box(int x, int y, int w, int h, const char *color)`
Desenha caixa com borda pesada.

#### `void draw_double_box(int x, int y, int w, int h, const char *color)`
Desenha caixa com borda dupla.

#### `void draw_broad_box(int x, int y, int w, int h, const char *color)`
Desenha caixa com estilo largo.

#### `void draw_round_box(int x, int y, int w, int h, const char *color)`
Desenha caixa com cantos arredondados.

### Tabelas e alinhamento

#### `void draw_table_grid(int x, int y, int cols, int rows, int cell_width, const char *color)`
Desenha apenas a grade da tabela com colunas/linhas e largura de celula.

#### `void print_aligned(const char *text, int width, int alignment, const char *color)`
Imprime texto alinhado em largura fixa (`left`, `center`, `right`).

#### `void draw_table(int x, int y, int cell_width, int rows, int cols, const char *data[rows][cols], const char *grid_color, const char *data_color, const int *alignments)`
Desenha tabela completa com dados, cor da grade, cor do conteudo e alinhamento por coluna.

#### `void draw_table_with_headers(int x, int y, int cell_width, int cols, const char *headers[], int rows, const char *data[rows][cols], const char *grid_color, const char *data_color, const char *header_color, const int *alignments)`
Desenha tabela com cabecalho separado dos dados, incluindo cor dedicada para o cabecalho.

### Barras de titulo

#### `void print_title_bar(const char *text, const char *box_color, const char *text_color)`
Exibe barra de titulo com caixa simples.

#### `void print_title_bar_double(const char *text, const char *box_color, const char *text_color)`
Exibe barra de titulo com caixa dupla.

#### `void print_title_bar_broad(const char *text, const char *box_color, const char *text_color)`
Exibe barra de titulo com caixa larga.

#### `void print_title_bar_heavy(const char *text, const char *box_color, const char *text_color)`
Exibe barra de titulo com caixa pesada.

#### `void print_title_bar_round(const char *text, const char *box_color, const char *text_color)`
Exibe barra de titulo com caixa de cantos arredondados.

### Barra de progresso

#### `void print_progress_bar(double percentage, int line, const char *box_color, const char *bar_color, const char *text_color, const char *background_text_color)`
Renderiza barra de progresso em porcentagem na linha indicada.

### Barra de status e mensagens

#### `void print_status_bar(const char *text, const char *text_color)`
Mostra uma barra de status textual no terminal.

#### `void print_success(const char *text)`
Exibe mensagem de sucesso (padrao visual de sucesso).

#### `void print_info(const char *text)`
Exibe mensagem informativa.

#### `void print_warning(const char *text)`
Exibe mensagem de alerta.

#### `void print_error(const char *text)`
Exibe mensagem de erro.

### Campo de edicao simples

#### `void draw_edit_field(const char *label, int line, const char *box_color, const char *text_color)`
Desenha um campo de edicao visual com rotulo em linha especifica.

## Observacoes

- Em Windows, a implementacao prepara o terminal para ANSI automaticamente.
- Esta biblioteca foca em renderizacao visual no terminal, nao em entrada de dados complexa.
