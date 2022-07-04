#include <vector>

#ifndef LAB7_chessDesk_H
#define LAB7_chessDesk_H

class figura {
	public:
		struct f_position {
			unsigned int x, y;
		};
	
		enum f_color { white, black };
		
		enum f_type { p, N, B, R, Q, K };
	
	private:
		f_position position;
		f_color color;
		f_type type;
	
	public:
		figura(const f_position, const f_color, const f_type);
		figura();
		
		void setposition(const f_position);
		void setcolor(const f_color);
		void settype(const f_type);
		
		char f_type_in_char();
		
		f_position getposition() {
			return position;
		}
		f_color getcolor() {
			return color;
		}
		f_type gettype() {
			return type;
		}
};
		
class chessDesk
{
	std::vector<figura> figures;
	
	public:
		static const char* C_x_pols;
		static const char* C_y_pols;
		
		chessDesk();
		
		bool check_pole(figura::f_position, figura&);
		
		unsigned int figures_count();
		
		void ShowDesk();
};

const char* chessDesk::C_x_pols = "ABCDEFGH";
const char* chessDesk::C_y_pols = "12345678";

#endif
