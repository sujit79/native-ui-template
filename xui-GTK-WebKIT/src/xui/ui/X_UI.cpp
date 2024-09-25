/*
 * X_UI.cpp
 *
 *  Created on: Mar 7, 2010
 *      Author: dev
 */

#include "X_UI.h"

namespace xuigenerate {

	X_UI::X_UI() {
		// TODO Auto-generated constructor stub

	}

	X_UI::~X_UI() {
		// TODO Auto-generated destructor stub
	}
	
	int X_UI::http_writer(char *data, size_t size, size_t nmemb,std::string *buffer){  
	   // What we will return  
	   int result = 0;  

	   return result;
	}

	int X_UI::ftp_writer(char *data, size_t size, size_t nmemb,std::string *buffer){  
	   // What we will return  
	   int result = 0;
  
	   return result;
	}
	int X_UI::flash_writer(char *data, size_t size, size_t nmemb,std::string *buffer){  
	   // What we will return  
	   int result = 0; 

	   return result;
	}	
 
	int X_UI::writer(char *data, size_t size, size_t nmemb,std::string *buffer){  
	   // What we will return  
	   int result = 0;  
   
	   // Is there anything in the buffer?  
	   if (buffer != NULL){  
	     // Append the data to the buffer  
	     buffer->append(data, size * nmemb);  
   
	     // How much did we write?  
	     result = size * nmemb;  
	   }  
   
	   return result;  
 	}  
	void X_UI::X_UI_Main_Handler(char *protocolName, char *URI){
	
	     char* buffer;
	     char* errorBuffer;
	 
	     // Our curl objects  
	     CURL *curl;  
	     CURLcode result;  
   
	    // Create our curl handle  
            curl = curl_easy_init();  
   
            if (curl){  
	       // Now set up all of the curl options  
	       curl_easy_setopt(curl, CURLOPT_ERRORBUFFER, errorBuffer);  
	       curl_easy_setopt(curl, CURLOPT_URL, URI);  
	       curl_easy_setopt(curl, CURLOPT_HEADER, 0);  
	       curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1); 
 
	       if(!strcmp(protocolName,"plain"))
		   curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, writer);  
	       else if (!strcmp(protocolName,"http"))
		   curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, http_writer);  
	       else if (!strcmp(protocolName,"ftp"))
		   curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, ftp_writer);  
	       else if (!strcmp(protocolName,"flash"))	
		   curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, flash_writer);  

               curl_easy_setopt(curl, CURLOPT_WRITEDATA, &buffer);  
   
	       // Attempt to retrieve the remote page  
	       result = curl_easy_perform(curl);  
   
	       // Always cleanup  
	       curl_easy_cleanup(curl);  
   
	       // Did we succeed?  
	       if (result == CURLE_OK)  
	       {  
	       	 std::cout << buffer << "\n";  
	         exit(0);  
	       }  
	       else  
	       {  
        	 std::cout << "Error: [" << result << "] - " << errorBuffer;  
	         exit(-1);  
      	       }  
	     }  	
	
	}
}
