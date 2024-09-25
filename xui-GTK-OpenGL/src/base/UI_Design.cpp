/*
 * UI_Design.cpp
 *
 *  Created on: Mar 7, 2010
 *      Author: dev
 */

#include "UI_Design.h"
static int ind = 0;
static int m_ind = 0;
static int f_ind = 0;

char attr[128];

namespace xuigenerate {

	UI_Design::UI_Design()
	  : xmlpp::SaxParser()
	{
	}

	UI_Design::~UI_Design()
	{
	}

	void UI_Design::on_start_document()
	{
/*	  static int refCount = 0;
	  if(refCount%4 < 2){
	  	std::cout<< "Error parsing XML File";
	  	exit(-1);
	  }
	  else{
	  	refCount++;
	    std::cout << "on_start_document()" << std::endl;
	    return;
	  }*/
	}

	void UI_Design::on_end_document()
	{
/*	  static int refCount = 0;
	  if(refCount%4 >= 2){
	  	std::cout<< "Error parsing XML File";
	  	exit(-1);
	  }
	  else
		refCount++;

	  std::cout << "on_end_document()" << std::endl;
	  return;*/
	}

	void UI_Design::on_start_element(const Glib::ustring& name,
                                   const AttributeList& attributes)
	{
/*	  static int refCount = 0;
	  if(refCount%4 < 2){
	  	std::cout<< "Error parsing XML File";
	  	exit(-1);
	  }
	  else{
		refCount++;
		return;
	  }
*/
	 strcpy(attr, name.c_str());
	 UI_Generate *gen = new UI_Generate();

	 if(strcmp(attr,"Window") && ind == 0) return;
	 if(!strcmp(attr,"Window")) ind++;
	 
//	if(strcmp(attr,"Menu") && m_ind == 0) return;
	if(!strcmp(attr,"Menu")){
		m_ind++;
	}
	if(!strcmp(attr,"Menu-Item")){
		f_ind++;
	}

	this->bytecode = gen->setGUI(this->bytecode, name, ind, m_ind, f_ind);	
	
	for(xmlpp::SaxParser::AttributeList::const_iterator iter = attributes.begin(); iter != attributes.end(); ++iter){	
	       std::cout << "  Attribute " << iter->name << " = " << iter->value << std::endl;
	       this->bytecode = gen->setGUI(this->bytecode,name, iter->name, iter->value);	
  	}

	}

	void UI_Design::on_end_element(const Glib::ustring& name)
	{
/*	  static int refCount = 0;
	  if(refCount%4 >= 2){
	  	std::cout<< "Error parsing XML File";
	  	exit(-1);
	  }
	  else{
		refCount++;
		return;
	  }
*/
          if(!strcmp(attr,"Window")) m_ind = 0;
	  std::cout << "on_end_element()" << std::endl;
	}

	void UI_Design::on_characters(const Glib::ustring& text)
	{
	  std::cout << "on_characters(): " << text << std::endl;
	}

	void UI_Design::on_comment(const Glib::ustring& text)
	{
	  std::cout << "on_comment(): " << text << std::endl;
	}

	void UI_Design::on_warning(const Glib::ustring& text)
	{
	  std::cout << "on_warning(): " << text << std::endl;
	}

	void UI_Design::on_error(const Glib::ustring& text)
	{
	  std::cout << "on_error(): " << text << std::endl;
	}

	void UI_Design::on_fatal_error(const Glib::ustring& text)
	{
	  std::cout << "on_fatal_error(): " << text << std::endl;
	}
	
	ByteCode* UI_Design:: returnbytecode(){
	  return bytecode;
	}

}
