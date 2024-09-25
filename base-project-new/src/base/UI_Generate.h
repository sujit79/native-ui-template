/*
 * UI_Generate.h
 *
 *  Created on: Mar 7, 2010
 *      Author: dev
 */

#ifndef UI_GENERATE_H_
#define UI_GENERATE_H_
#include "../../include/common.h"
#include "../lang/Draw.h"
#include "../base/Base_Class.h"
#include "ByteCode.h"

namespace xuigenerate {

class UI_Generate {
private:
	Base_Class bClass[256][1];
public:

	UI_Generate();
	virtual ~UI_Generate();
	void showGUI(Draw *draw, ByteCode *byteCode);
	ByteCode *setGUI(ByteCode *byteCode, const Glib::ustring& name, int index, int m_index, int f_index);
	ByteCode *setGUI(ByteCode *byteCode, const Glib::ustring& name, const Glib::ustring& attrName, const Glib::ustring& attrValue); 

};

}

#endif /* UI_GENERATE_H_ */
