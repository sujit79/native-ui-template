/*
 * UI_Design.h
 *
 *  Created on: Mar 7, 2010
 *      Author: dev
 */

#ifndef UI_DESIGN_H_
#define UI_DESIGN_H_

#include "../../include/common.h"
#include "ByteCode.h"
#include "Base_Class.h"
#include "UI_Generate.h"


namespace xuigenerate {

class UI_Design: public xmlpp::SaxParser
{

private:
	Base_Class *baseClass[256];
	ByteCode *bytecode;

public:
	UI_Design();
	virtual ~UI_Design();
	ByteCode *returnbytecode();



protected:
	 //overrides:
	 virtual void on_start_document();
	 virtual void on_end_document();
	 virtual void on_start_element(const Glib::ustring& name,
                               const AttributeList& properties);
	 virtual void on_end_element(const Glib::ustring& name);
	 virtual void on_characters(const Glib::ustring& characters);
	 virtual void on_comment(const Glib::ustring& text);
	 virtual void on_warning(const Glib::ustring& text);
	 virtual void on_error(const Glib::ustring& text);
	 virtual void on_fatal_error(const Glib::ustring& text);
};

}

#endif /* UI_DESIGN_H_ */
