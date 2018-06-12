#include "StdAfx.h"
#include <iostream>
#include "felica.h"
#include "FelicaWrapper.h"

using namespace std;

namespace Felica
{
	bool Wrapper::closeReaderWriter(void)
	{
		return close_reader_writer();
	}

	bool Wrapper::disposeLibrary(void)
	{
		return dispose_library();
	}
	
	void Wrapper::errorRoutine() {
		enumernation_felica_error_type felica_error_type;
		enumernation_rw_error_type rw_error_type;
		get_last_error_types(&felica_error_type, &rw_error_type);
		cerr << "ERROR: { felica_error_type:" << felica_error_type << ", rw_error_type: " << rw_error_type << " }" << endl;
		close_reader_writer();
		dispose_library();
	}

	bool Wrapper::initializeLibrary()
	{
		return initialize_library();
	}

	void Wrapper::log(const char* logContent)
	{
		cerr << logContent << endl;
	}

	bool Wrapper::openReaderWriterAuto()
	{
		return open_reader_writer_auto();
	}

	bool Wrapper::pollingAndGetCardInformation(
			unsigned char* number_of_cards,               // Number of cards  n (1 <= n <= 3) (1 byte)
			structure_card_information* card_information  // Information of the first card
	)
	{
		structure_polling polling;
		unsigned char system_code[2] = {0x00, 0x00};
		polling.system_code = system_code;
		polling.time_slot = 0x00;

		return polling_and_get_card_information(&polling, number_of_cards, card_information);
	}
}