#include <common.h>
#include "base/UI_Design.h"

int main(int argc, char * argv[])
{
	/* Set up initial variables and objects */

	std::string filepath; // The xml file to use
	/* The object used for parsing the xml file */
	xuigenerate::UI_Design* parser = new xuigenerate::UI_Design;

	/* Get input files from arguments and parse them */	
	
	if(argc > 1 )
		filepath = argv[1]; // Input xml file (Ignore other arguments)
	else
	{
		std::cout << "Error: No xml file specified" << std::endl;
		exit(EXIT_FAILURE);
	}
	/* Parse document completely and set up widgets */
	gtk_init(&argc, &argv);
	try
	{
		parser->parse_file(filepath); // Parse the file
	}	
	catch(const xmlpp::exception& ex)
	{
		std::cout << "Libxml Error: " << ex.what() << std::endl;
		exit(EXIT_FAILURE);
	}
	
	gtk_main(); // Start testing (Have as argument option??)
	
	exit(EXIT_SUCCESS); // All completed;
}

