#ifndef __PESSOA_HPP__
#define __PESSOA_HPP__

typedef struct pessoa * Pessoa;


Pessoa cria_pessoa(char * cpf, char * nome, char * nascimento, char * rg, char * sexo);

int pega_linha(Pessoa pessoa);
int pega_coluna(Pessoa pessoa);
char * pega_nome(Pessoa pessoa);
void escolher_assento(Pessoa pessoa, int linha, int coluna);
Pessoa reserva(Pessoa passageiro);
int verifica_disponibilidade(int matriz);
void escolher_voo(Pessoa pessoa, char * voo);
char * pega_voo(Pessoa pessoa);

#endif