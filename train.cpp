/*
Author: sttt912(https://github.com/sttt912)
Гра в хрестики нолики використовуючи фан fann
Код для навчання
*/

#include "stdafx.h"
#include "iostream"
#include "stdio.h"
#include "fann.h"
#include "floatfann.h"

using std::cout;
using std::endl;
using namespace std;


int main(int argc, char* argv[])
{
	setlocale(LC_CTYPE, "rus");

	cout << "Øàã 1\n";
	const unsigned int num_input = 9;
	const unsigned int num_output = 9;
	const unsigned int num_layers = 3;
	const unsigned int num_neurons_hidden = 256;
	const float desired_error = (const float) 0.01;
	const unsigned int max_epochs = 20000;
	const unsigned int epochs_between_reports = 2;

	fann_type *calc_out;
	fann_type input[9];

	// create

	cout << "Øàã 2. Ñîçäàíèå\n";
	struct fann *ann = fann_create_standard(num_layers, num_input,
		num_neurons_hidden, num_output);

	fann_set_activation_function_hidden(ann, FANN_SIGMOID_SYMMETRIC);
	fann_set_activation_function_output(ann, FANN_SIGMOID_SYMMETRIC);

	//train
	fann_train_on_file(ann, "user.txt", max_epochs, epochs_between_reports, desired_error);


	//input
	for (int i = 0; i <= 8; i++) {
		cin >> input[i];
	}


	calc_out = fann_run(ann, input);

	//Result... test
	printf("\nÂõîä: (%f,%f,%f,%f,%f,%f,%f,%f,%f)\n\n", input[0], input[1], input[2], input[3], input[4], input[5], input[6], input[7], input[8]);


	
	for (int i = 0; i <= 8; i++) {

		if (calc_out[i] * 10 >= 7) { 
			cout << "1\n";
		}
		else if (calc_out[i] * 10 <= -7) {
			cout << "-1\n";
		}
		else {  // èíà÷å
			cout << "0" << endl;
		}

	}


	//save
	fann_save(ann, "st.net");
	fann_destroy(ann);



	system("pause\n"); 
	return 0;
}
