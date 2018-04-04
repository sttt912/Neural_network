#include "stdafx.h"
#include "iostream"
#include "stdio.h"
#include "fann.h"
#include "floatfann.h"

using std::cout;
using std::endl;
using namespace std;

fann_type input[9];
fann_type *calc_out;



void print_input(){ //вход
	cout << "Game board\n"; 
	cout << "-" << input[1] << "-|-" << input[2] << "-|-" << input[3] << "- \n";
	cout << "-" << input[4] << "-|-" << input[5] << "-|-" << input[6] << "- \n";
	cout << "-" << input[7] << "-|-" << input[8] << "-|-" << input[9] << "- \n";
}

void print_output(){ //выход
	cout << "Game board\n";
	cout << "-" << calc_out[1] << "-|-" << calc_out[2] << "-|-" << calc_out[3] << "- \n";
	cout << "-" << calc_out[4] << "-|-" << calc_out[5] << "-|-" << calc_out[6] << "- \n";
	cout << "-" << calc_out[7] << "-|-" << calc_out[8] << "-|-" << calc_out[9] << "- \n";
}

void help(){ //help
	std::cout << "\nMenu hodov: \n";     
	std::cout << "-1-|-2-|-3-" << std::endl;
	std::cout << "-4-|-5-|-6-" << std::endl;
	std::cout << "-7-|-8-|-9-" << std::endl;
}


void new_game() { //first raund

	for (int i = 0; i <= 8; i++) {
		input[i] = 0;
	}

	help();
	print_input();
	cout << "\nVvod chisla: ";

	int a;
	cin >> a;
	input[a] = 1;
}


int main(int argc, char* argv[])
{
	setlocale(LC_CTYPE, "rus"); // вызов функции настройки локали


		struct fann *ann = fann_create_from_file("st.net");

		new_game();

		calc_out = fann_run(ann, input);


		for (int i = 0; i <= 8; i++) {

			if (calc_out[i] * 10 >= 7) {
				calc_out[i] = 1;
			}
			else if (calc_out[i] * 10 <= -7) {
				calc_out[i] = -1;
			}
			else {
				calc_out[i] = 0;
			}

		}

		print_output();

		fann_destroy(ann);
		system("pause\n"); 
		return 0;
}