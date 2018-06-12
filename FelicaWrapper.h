#include "felica.h"

namespace Felica 
{
	class Wrapper
	{
	public:

		// This API closes the Reader/Writer.
		// Once this API is executed, the Reader/Writer mode is reset to 0
		bool closeReaderWriter(
			void
		);

		// Releases the library.
		// If a Reader/Writer has been opened, it is automatically closed.
		bool disposeLibrary(
			void
		);

		// Output error of Felica device
		void errorRoutine(
			void
		);

		// Initializes the library
		bool initializeLibrary(
			void
		);

		// Output log
		void log(
			const char* logContent
		);

		// Automatically identifies and opens a Reader/Writer
		bool openReaderWriterAuto(
			void
		);

		// Polls and gets information about a card (Polling command)
		// number_of_cards [OUT] Number of cards captured (=1)
		// card_information [OUT] Information about the first card
		//						  Prepare this area on the application side.
		//						  card_idm; // IDm of the card (8 bytes)
		//						  card_pmm; // PMm of the card (8 bytes)
		bool pollingAndGetCardInformation(
			unsigned char* number_of_cards,               // Number of cards  n (1 <= n <= 3) (1 byte)
			structure_card_information* card_information  // Information of the first card
		);

	};
}
