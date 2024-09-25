/*
 * X_UI.h
 *
 *  Created on: Mar 7, 2010
 *      Author: dev
 */

#ifndef X_UI_H_
#define X_UI_H_
#include "../../../include/common.h"
#include "curl/curl.h"

namespace xuigenerate {

class X_UI {
public:
	X_UI();
	virtual ~X_UI();

	static int http_writer(char *data, size_t size, size_t nmemb, std::string *buffer);
	static int ftp_writer(char *data, size_t size, size_t nmemb, std::string *buffer);
	static int flash_writer(char *data, size_t size, size_t nmemb, std::string *buffer);
	static int writer(char *data, size_t size, size_t nmemb, std::string *buffer);

	void X_UI_Main_Handler(char *protocolName, char *URI);

};

}

#endif /* X_UI_H_ */
