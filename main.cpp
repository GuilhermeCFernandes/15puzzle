/*
	Programa que resolve o jogo 15 puzzle utilizando dois algoritmos:
	força bruta e busca A*

	Autor: Guilherme Correa Fernandes Nusp: 9278174
*/

#include<iostream>
using namespace std;

typedef class Jogo{
	int ** matriz;
	int size;
	int x, y;
public:
	Jogo (int size);
	~Jogo();
	int move (char direcao);
	int get_size();
	void set_matriz();
	void print_matriz();
}Jogo;

Jogo::Jogo(int size){
	int i;
	this->size = size;
	this->matriz = (int **) malloc (this->size * sizeof (int *));
	for(i = 0; i < this->size; i ++){
		(this->matriz)[i] = (int *) malloc (this->size * sizeof(int));
	}
}

Jogo::~Jogo(){
	int i;
	for(i = 0; i < this->size; i ++){
		free((this->matriz)[i]);
	}
	x = 0;
	y = 0;
	free(this->matriz);
}

int Jogo::move (char direcao){

	int aux;
	switch(direcao){
		case 'u':
			if(this->y > 0){
				this->y -= 1;
				this->matriz[this->x][this->y] = this->matriz[this->x][this->y-1];
				this->matriz[this->x][this->y-1] = 0;
				return 1;
			}
		case 'd':
			if(this->y < this->size -1){
				this->y += 1;
				this->matriz[this->x][this->y] = this->matriz[this->x][this->y+1];
				this->matriz[this->x][this->y+1] = 0;
				return 1;
			}
		case 'l':
			if(this->x > 0){
				this->x -= 1;
				this->matriz[this->x][this->y] = this->matriz[this->x-1][this->y];
				this->matriz[this->x-1][this->y] = 0;
				return 1;
			}
		case 'r':
			if(this->x < this->size -1){
				this->x += 1;
				this->matriz[this->x][this->y] = this->matriz[this->x+1][this->y];
				this->matriz[this->x+1][this->y] = 0;
				return 1;
			}
	}
	return 0;
}

int Jogo::get_size(){
	return this->size;
}

void Jogo::print_matriz(){
	int i, j;
	for (i = 0; i < this->size; i ++){
		for(j = 0; j < this->size; j++){
			cout << this->matriz[i][j] << "\t";
		}
		cout << "\n";
	}
}

void Jogo::set_matriz(){
	int i, j;
	for(i = 0; i < this->size; i ++){
		for(j = 0; j < this->size; j ++){
			cin >> this->matriz[i][j];
			if(this->matriz[i][j] == 0){
				this->x = i;
				this->y = j;
			}
		}
	}
}

int main (void){
	Jogo * jogo;
	jogo = new Jogo(4);
	jogo->set_matriz();
	jogo->print_matriz();
	delete jogo;
	return 0;
}
