#include "UI_Generate.h"

namespace xuigenerate {

	UI_Generate::UI_Generate() {
		// TODO Auto-generated constructor stub
	}

	UI_Generate::~UI_Generate() {
		// TODO Auto-generated destructor stub
	}
	
	Draw* UI_Generate::find(std::string title)
	{
		for(unsigned int i = 0; i < draw_list.size(); i++)
		{
			if(draw_list.at(i)->getTitle() == title)
				return draw_list.at(i);
		}
		return NULL;
	}

	void UI_Generate::construct(const Glib::ustring& node_name,const AttributeList& attr)
	{
		this->node_title = node_name; // Default Node title values

		if(!strcmp(node_name.c_str(),"Window")){
			std::cout << " --> Constructing Window..";
			for(xmlpp::SaxParser::AttributeList::const_iterator iter = attr.begin(); iter != attr.end(); ++iter)
				setAttributes(iter);
			Draw* window = new Draw(this->node_title);
			this->draw_list.push_back(window);
			window->drawWindow(this->node_title,this->node_x_coord,this->node_y_coord);
			std::cout << "..done!";
		}else if(!strcmp(node_name.c_str(),"Menu")){
			std::cout << " --> Constructing Menu..";
			
			for(xmlpp::SaxParser::AttributeList::const_iterator iter = attr.begin(); iter != attr.end(); ++iter)
				setAttributes(iter);
			Draw* menu = new Draw(this->node_title);
			this->draw_list.push_back(menu);
			menu->drawMenu(this->node_title); //TODO: Compile error when uncommenting this line.. Does anyone know why??
			
			std::cout << "..done!";
		}else if(!strcmp(node_name.c_str(),"Button")){
			//strcpy(byteCode[ix].c,"3");
		}else if(!strcmp(node_name.c_str(),"Event")){
			//strcpy(byteCode[ix].c,"4");
		}else if(!strcmp(node_name.c_str(),"Button")){
			//strcpy(byteCode[ix].c,"5");
		}else if(!strcmp(node_name.c_str(),"TR")){
			//strcpy(byteCode[ix].c,"6");
		}else if(!strcmp(node_name.c_str(),"TD")){
			//strcpy(byteCode[ix].c,"7");
		}else if(!strcmp(node_name.c_str(),"Table")){
			//strcpy(byteCode[ix].c,"8");
		}else if(!strcmp(node_name.c_str(),"Signal")){
			//strcpy(byteCode[ix].c,"9");
		}else if(!strcmp(node_name.c_str(),"CDATA")){
			//strcpy(byteCode[ix].c,"10");
		}else{
			std::cout << " --> Error: Unknown tag";
		}

	}
	
	void UI_Generate::setAttributes(xmlpp::SaxParser::AttributeList::const_iterator iter)
	{
		if(!strcmp(iter->name.c_str(),"name"))
			this->node_title = iter->value;
		if(!strcmp(iter->name.c_str(),"width"))
			this->node_x_coord = atoi(iter->value.c_str());
		if(!strcmp(iter->name.c_str(),"height"))
			this->node_y_coord = atoi(iter->value.c_str());
		if(!strcmp(iter->name.c_str(),"item"))
			this->item_list.push_back(iter->value.c_str());
	}

}; //End Namespace
