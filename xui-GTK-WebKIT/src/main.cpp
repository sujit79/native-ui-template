
#include <../include/common.h>
#include "./base/UI_Design.h"
#include "./base/UI_Generate.h"
#include "./base/ByteCode.h"

int main(int argc, char * argv[])
{
    std::string filepath;

    xuigenerate::UI_Design *parser = new xuigenerate::UI_Design[1];
    xuigenerate::UI_Generate *ui = new xuigenerate::UI_Generate[1];
    xuigenerate::Draw *draw = new xuigenerate::Draw[1];

    ByteCode *byteCode = NULL;
    
   if(argc > 1 )
   	 filepath = argv[1]; //Allow the user to specify a different XML file to parse.
   else
 	 filepath = "Draw.xml";
    
  // Parse the entire document in one go:
    try
    {
	parser->parse_file(filepath);
	
    }	
    catch(const xmlpp::exception& ex)
    {
	 std::cout << "libxml++ exception: " << ex.what() << std::endl;
    }

    byteCode = parser->returnbytecode();

    gtk_init (&argc, &argv);

    ui->showGUI(draw, byteCode); 

    gtk_main ();

	
    exit(EXIT_FAILURE);
}	
