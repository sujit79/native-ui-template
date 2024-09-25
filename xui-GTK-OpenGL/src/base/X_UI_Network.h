/*
 * X_UI_Network.h
 *
 *  Created on: Mar 7, 2010
 *      Author: dev
 */

#ifndef X_UI_NETWORK_H_
#define X_UI_NETWORK_H_


#include "Base_Class.h"
#include "X_UI_Network_Protocol.h"

namespace xuigenerate {

class X_UI_Network {
public:
	X_UI_Network();
	virtual ~X_UI_Network();

	X_UI_Network_Protocol *protocol[256];

	void X_UI_Network_Parse(char *protocolName);

};

}

#endif /* X_UI_NETWORK_H_ */
