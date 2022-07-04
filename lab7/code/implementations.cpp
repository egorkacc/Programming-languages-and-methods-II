#include <iostream>

#include "chessDesk.h"

struct f_position {
	unsigned int x, y;
};

enum f_color { white, black };

enum f_type { p, N, B, R, Q, K };

figura::figura(const f_position new_pos, const f_color b, const f_type t) {
	setposition(new_pos);
	setcolor(b);
	settype(t);
}

figura::figura() {}

void figura::setposition(const f_position new_pos) {
	this->position = new_pos;
}

void figura::setcolor(const f_color b) {
	this->color = b;
}

void figura::settype(const f_type t) {
	this->type = t;
}

char figura::f_type_in_char() {
	if(this->color == white)
		switch(this->type) {
			case p: return 'p';
			case N: return 'N';
			case B: return 'B';
			case R: return 'R';
			case Q: return 'Q';
			case K: return 'K';
		}
	else
		switch(this->type) {
			case p: return 'P';
			case N: return 'n';
			case B: return 'b';
			case R: return 'r';
			case Q: return 'q';
			case K: return 'k';
		};
}

chessDesk::chessDesk() {
	figura::f_color color = figura::white;
	figura::f_type type = figura::p;
	figura::f_position pos = { 0, 0 };
	
	figura new_f(pos, color, type);
	
	pos.y = 1;
	for(long i = 0; i != 8; ++i) {
		pos.x = i;
		new_f.setposition(pos);
		figures.push_back(new_f);
	}
	
	type = figura::K;
	new_f.settype(type);
	
	pos.y = 0;
	pos.x = 4;
	
	new_f.setposition(pos);
	figures.push_back(new_f);
	
	type = figura::Q;
	new_f.settype(type);
	pos.y = 0;
	pos.x = 3;
	new_f.setposition(pos);
	figures.push_back(new_f);
	
	type = figura::B;
	new_f.settype(type);
	pos.y = 0;
	pos.x = 2;
	new_f.setposition(pos);
	figures.push_back(new_f);
	
	pos.y = 0;
	pos.x = 5;
	new_f.setposition(pos);
	figures.push_back(new_f);
	
	type = figura::N;
	new_f.settype(type);
	pos.y = 0;
	pos.x = 1;
	new_f.setposition(pos);
	figures.push_back(new_f);
	
	pos.y = 0;
	pos.x = 6;
	new_f.setposition(pos);
	figures.push_back(new_f);
	
	type = figura::R;
	new_f.settype(type);
	pos.y = 0;
	pos.x = 0;
	new_f.setposition(pos);
	figures.push_back(new_f);
	
	pos.y = 0;
	pos.x = 7;
	new_f.setposition(pos);
	figures.push_back(new_f);
	
	color = figura::black;
	type = figura::p;
	new_f.settype(type);
	new_f.setcolor(color);
	
	pos.y = 6;
	for(long i = 0; i != 8; ++i) {
		pos.x = i;
		new_f.setposition(pos);
		figures.push_back(new_f);
	}
	
	type = figura::K;
	new_f.settype(type);
	pos.y = 7;
	pos.x = 3;
	new_f.setposition(pos);
	figures.push_back(new_f);
	
	type = figura::Q;
	new_f.settype(type);
	pos.y = 7;
	pos.x = 4;
	new_f.setposition(pos);
	figures.push_back(new_f);
}

bool chessDesk::check_pole(figura::f_position pos, figura& how_figura) {
	for(std::vector<figura>::const_iterator it = figures.begin(); it != figures.end(); ++it) {
		figura::f_position t_pos;
		figura f = *it;
	
		t_pos = f.getposition();
		if((t_pos.x == pos.x) && (t_pos.y == pos.y)) {
			how_figura = f;
			
			return true;
		}
	}

	return false;
};

unsigned int chessDesk::figures_count() {
	return figures.size();
};

void chessDesk::ShowDesk() {
	for(long i = 0; i != 8; ++i) {
		for(long j = 0; j != 8; ++j) {
			figura::f_position pos;
			pos.x = j;
			pos.y = 7 - i;
			figura t_figura;
			
			if(check_pole(pos, t_figura))
				std::cout << t_figura.f_type_in_char();
			else
				std::cout << '*';
		}
		
		std::cout << std::endl;
	}
}
