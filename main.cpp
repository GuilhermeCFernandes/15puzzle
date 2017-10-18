/*
	Programa que resolve o jogo 15 puzzle utilizando dois algoritmos:
	força bruta e busca A*

	Autor: Guilherme Correa Fernandes Nusp: 9278174
*/

#define SIZE 4

#include<iostream>
#include<stdlib.h>
using namespace std;

class Board{
	int ** matrix;
	int x, y; //Coordenadas da posicao do quadrado vazio
public:
	Board();
	~Board();
	int get_pos(int x, int y);
	void set_pos(int x, int y, int value);
	int move(int dir);
	int is_solved();
};

//Funcos da classe Board

int Board::move(int dir){
	switch (dir){
		case 0:
			if(this->x > 0){
				this->matrix[x - 1][y] = this->matrix[x][y];
				this->x = this->x - 1;
				this->matrix[x][y] = 0;
			return 1;
			}
		case 1:
			if(this->y > 0){
				this->matrix[x][y - 1] = this->matrix[x][y];
				this->y = this->y - 1;
				this->matrix[x][y] = 0;
			return 1;
			}
		case 2:
			if(this->x < SIZE - 1){
				this->matrix[x + 1][y] = this->matrix[x][y];
				this->x = this->x + 1;
				this->matrix[x][y] = 0;
			return 1;
			}
		case 3:
			if(this-> y < SIZE - 1){
				this->matrix[x][y + 1] = this->matrix[x][y];
				this->y = this->y + 1;
				this->matrix[x][y] = 0;
			return 1;
			}
	}
	return 0;
}

Board::Board(){
	this->matrix = (int **) malloc (sizeof(int *) * SIZE);
	for(int i = 0; i < SIZE; i ++){
		this->matrix[i] = (int *) malloc (sizeof(int) * SIZE);
	}
}

Board::~Board(){
	for(int i = 0; i < SIZE; i ++){
		free(this->matrix[i]);
	}
	free(this->matrix);
}

void Board::set_pos(int x, int y, int value){
	this->matrix[x][y] = value;
	if(value == 0){
		this->x = x;
		this->y = y;
	}
}

int Board::get_pos(int x, int y){
	return this->matrix[x][y];
}

int Board::is_solved(){
	int aux = 1;
	for(int i = 0; i < SIZE; i ++){
		for(int j = 0; j < SIZE; j ++){
			if(aux = 16)
				return 1;
			if(aux != this->matrix[i][j])
				return 0;
			aux ++;
		}
	}
}

//Outras funcoes auxiliares

void read_board(Board * board){
	int aux;
	for(int i = 0; i < SIZE; i ++){
		for(int j = 0; j < SIZE; j ++){
			cin >> aux;
			board->set_pos(i, j, aux);
		}
	}
}

void print_board(Board * board){
	for(int i = 0; i < SIZE; i ++){
		for(int j = 0; j < SIZE; j ++){
			cout << board->get_pos(i, j) << "\t";
		}
		cout << "\n";
	}
}

void copy_board(Board * board1, Board * board2){
	for(int i = 0; i < SIZE; i ++){
		for(int j = 0; j < SIZE; j ++){
			board2->set_pos(i, j, board1->get_pos(i, j));
		}
	}
}

int test_solution(Board * board, int * solution, int n){
	for(int i = n -1; i >= 0; i --){
		if(!board->move(solution[i]))
			return 0;
	}
	return board->is_solved();
}

int brute_force_solver (Board * board){
	Board * aux;
	int * solution, n, i;

	aux = new Board;
	solution = (int *) malloc (sizeof(int));
	solution[i] = 0;
	n = 1;

	while(!test_solution(aux, solution, n)){
		for(i = 0; i < n; i ++){
			solution[i] = (solution [i] + 1) % 4;
			if(solution[i] != 0)
				break;
			if(i = n - 1){
				n ++;
				solution = (int*) realloc(solution, n * sizeof(int));
			}
		}
	}
	for(i = n -1; i >= 0; i --){
		switch (solution[i]){
			case 1:
				cout << "L";
			case 2:
				cout << "U";
			case 3:
				cout << "R";
			case 4:
				cout << "D";
		}
	}
	cout << "\n";
}

int A_solver (){

}

int main (void){

}
