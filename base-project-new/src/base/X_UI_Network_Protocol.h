/*
 * X_UI_Network_Protocol.h
 *
 *  Created on: Mar 7, 2010
 *      Author: dev
 */

#ifndef X_UI_NETWORK_PROTOCOL_H_
#define X_UI_NETWORK_PROTOCOL_H_

#include "Base_Class.h"

namespace xuigenerate {

class X_UI_Network_Protocol {
public:
	X_UI_Network_Protocol();
	virtual ~X_UI_Network_Protocol();
	void X_UI_Network_Protocol_Parse(char *protocolName);
};

}

#endif /* X_UI_NETWORK_PROTOCOL_H_ */
