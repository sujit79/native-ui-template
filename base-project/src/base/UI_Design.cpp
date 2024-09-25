/*
 * UI_Design.cpp
 *
 *  Created on: Mar 7, 2010
 *      Author: dev
 */

#include "UI_Design.h"

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
		this->xml_layer = 0;
		std::cout << "<xml>" << std::endl;
	}

	void UI_Design::on_end_document()
	{
		std::cout << std:: endl << "</xml>" << std::endl;
	}

	void UI_Design::on_start_element(const Glib::ustring& name,const AttributeList& attributes)
	{
		// <Window Compilation Aesthetics>
		this->xml_layer++;
		
		for(int i=0; i < xml_layer; i++)
			std::cout << "\t";
		// </Window Compilation Aesthetics>
		
		std::cout << "<" << name.c_str();
		for(xmlpp::SaxParser::AttributeList::const_iterator iter = attributes.begin(); iter != attributes.end(); ++iter)
     	 		std::cout << " " << iter->name;
		std::cout << ">";
		
		this->gen = new UI_Generate;
		gen->construct(name,attributes);
		std::cout << std::endl;
	}

	void UI_Design::on_end_element(const Glib::ustring& name)
	{
		std::cout << std::endl;
		for(int i=0; i < xml_layer; i++)
			std::cout << "\t";
			
		std::cout << "</" << name.c_str() << ">";
		
		this->xml_layer--;
	}
	
	void UI_Design::on_characters(const Glib::ustring& text)
	{
		
	}

	void UI_Design::on_comment(const Glib::ustring& text)
	{
	  //std::cout << "on_comment(): " << text << std::endl;
	}

	void UI_Design::on_warning(const Glib::ustring& text)
	{
	  //std::cout << "on_warning(): " << text << std::endl;
	}

	void UI_Design::on_error(const Glib::ustring& text)
	{
	  //std::cout << "on_error(): " << text << std::endl;
	}

	void UI_Design::on_fatal_error(const Glib::ustring& text)
	{
	  //std::cout << "on_fatal_error(): " << text << std::endl;
	}

}; // End Namespace
