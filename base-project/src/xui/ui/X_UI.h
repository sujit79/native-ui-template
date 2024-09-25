/*
 * X_UI.h
 *
 *  Created on: Mar 7, 2010
 *      Author: dev
 */

#ifndef X_UI_H_
#define X_UI_H_

namespace xuigenerate {

class X_UI {
public:
	X_UI();
	virtual ~X_UI();

	void X_UI_Main_Handler(char *protocolName, char *URI);

};

}

#endif /* X_UI_H_ */
