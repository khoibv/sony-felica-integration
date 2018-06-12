// FeliCaConsole01.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "FelicaWrapper.h"

using namespace std;

int main(void);
void error_routine(void);
void print_vector(char* title, unsigned char* vector, int length);

int _tmain(int argc, _TCHAR* argv[])
{
	Felica::Wrapper felicaClient;

	if (!felicaClient.initializeLibrary()) {
		felicaClient.log("Can't initialize library.");
		felicaClient.errorRoutine();
        return EXIT_FAILURE;
	} else {
		cout << "Initialize OK." << endl;
	}

	if (!felicaClient.openReaderWriterAuto()) {
		cerr << "Can't open reader writer." << endl;
		felicaClient.errorRoutine();
        return EXIT_FAILURE;
	} else {
		cout << "Open reader/writer OK." << endl;
	}

    unsigned char number_of_cards = 0;

    structure_card_information card_information;
    unsigned char card_idm[8];
    unsigned char card_pmm[8];
    card_information.card_idm = card_idm;
    card_information.card_pmm = card_pmm;

	if (!felicaClient.pollingAndGetCardInformation(&number_of_cards, &card_information)) {
		cerr << "Can't find FeliCa." << endl;
        return EXIT_FAILURE;
    }

	cout << "number of cards: " << number_of_cards << endl;

    print_vector("card IDm:", card_idm, sizeof(card_idm));
    print_vector("card PMm:", card_pmm, sizeof(card_pmm));

	if (!felicaClient.closeReaderWriter()) {
		cerr << "Can't close reader writer." << endl;
        return EXIT_FAILURE;
    }

	if (!felicaClient.disposeLibrary()) {
		cerr << "Can't dispose library." << endl;
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}

void print_vector(char* title, unsigned char* vector, int length)
{
    if (title != NULL) {
        fprintf(stdout, "%s ", title);
    }

    int i;
    for (i = 0; i < length - 1; i++) {
        fprintf(stdout, "%02x ", vector[i]);
    }
    fprintf(stdout, "%02x", vector[length - 1]);
    fprintf(stdout, "\n");
}
