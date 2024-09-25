/*
 * UI_Generate.cpp
 *
 *  Created on: Mar 7, 2010
 *      Author: dev
 */


#include "UI_Generate.h"

static int ix = 0;
static int window_count = 0;

namespace xuigenerate {

	UI_Generate::UI_Generate() {
		// TODO Auto-generated constructor stub
	}

	UI_Generate::~UI_Generate() {
		// TODO Auto-generated destructor stub
	}
	
	void UI_Generate::showGUI(xuigenerate::Draw *draw,ByteCode *byteCode){

		int length=ix;
		
		for(int i = 0; i < length; i++){
	              std::cout << "The Byte Code is " << byteCode[i].c[0] << std::endl;
	              draw->drawingTool(byteCode[i].c[0]);
		      
		     // if(byteCode[i].c[0] == '1' ||  byteCode[i].c[0] == '2') 
		      //		i++;
		}
	}

	ByteCode* UI_Generate::setGUI(ByteCode *byteCode, const Glib::ustring& name,int index, int m_index, int f_index){

		const char *sName =  name.c_str();

		if(byteCode == NULL){
			byteCode = new ByteCode[1024];
		}

		std::cout << "Element is : " << sName << std::endl;

		if(!strcmp(sName,"Window")){
			std::cout << " Window Count is " << index - 1 << std::endl;
			strcpy(byteCode[ix].c,"1");
		}else if(!strcmp(sName,"Menu")){
			strcpy(byteCode[ix].c,"2");
			std::cout << "Menu Index is " << index - 1 << std::endl;
		}else if(!strcmp(sName,"Menu-Item")){
			strcpy(byteCode[ix].c,"3");
		}else if(!strcmp(sName,"UI-Area")){
			strcpy(byteCode[ix].c,"4");
		}else if(!strcmp(sName,"TR")){
			strcpy(byteCode[ix].c,"5");
		}else if(!strcmp(sName,"TD")){
			strcpy(byteCode[ix].c,"6");
		}else if(!strcmp(sName,"Table")){
			strcpy(byteCode[ix].c,"7");
		}else if(!strcmp(sName,"Signal")){
			strcpy(byteCode[ix].c,"8");
		}else if(!strcmp(sName,"CDATA")){
			strcpy(byteCode[ix].c,"9");
		}else{
			std::cout<<"Error....." << byteCode[ix].c << std::endl;
		}

		ix++;

		return byteCode;
	}

	ByteCode* UI_Generate::setGUI(ByteCode *byteCode, const Glib::ustring& name, const Glib::ustring& attrName, const Glib::ustring& attrValue){

		// TODO Attribute Setting Code

		if(!strcmp(name.c_str(),"shape")){
			bClass[ix][1].setShape(attrValue.c_str());
		}else if (!strcmp(name.c_str(),"type")){
			bClass[ix][1].setType(attrValue.c_str());
		}
		
		return byteCode;
	}
}
