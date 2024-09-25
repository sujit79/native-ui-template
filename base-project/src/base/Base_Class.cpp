/*
 * Base_Class.cpp
 *
 *  Created on: Mar 7, 2010
 *      Author: dev
 */

#include <common.h>
#include "Base_Class.h"

namespace xuigenerate {

	Base_Class::Base_Class() {
		// TODO Auto-generated constructor stub

	}

	Base_Class::~Base_Class() {
	// TODO Auto-generated destructor stub
	}
	char * Base_Class::getLanguage(){
		return this->language;
	}

	void Base_Class::setLanguage(const char *language){
		strcpy(this->language,language);
	}

	char * Base_Class:: getType(){
		return this->type;
	}

	void Base_Class:: setType(const char *type){
		strcpy(this->type,type);
	}

	char * Base_Class:: getVersion(){
		return this->version;
	}

	void Base_Class::setVersion(const char *version){
		strcpy(this->version,version);
	}

	char * Base_Class::getShape(){
		return this->shape;
	}

	void Base_Class::setShape(const char *shape){
		strcpy(this->shape,shape);
	}

	int * Base_Class::getPlot(){
		return this->plot;
	}

	void Base_Class::setPlot(int *plot){
		this->plot= plot;
	}

	int * Base_Class::getColor(){
		return this->color;
	}


	char * Base_Class::getProtocol(){
		return this->protocol;
	}

	void Base_Class::setProtocol(const char *protocol){
		strcpy(this->protocol,protocol);
	}

	void * Base_Class::getSocket(){
		return this->socket;
	}

	void Base_Class::setSocket(void *socket){
		this->socket = socket;
	}

	char * Base_Class::getPort(){
		return this->port;
	}

	void Base_Class::setPort(const char *port){
		strcpy(this->port,port);
	}

	bool Base_Class::getOneD(){
			return OneD;
	}

	void Base_Class::setOneD(bool OneD){
		this->OneD = OneD;
	}

	bool Base_Class::getTwoD(){
		return TwoD;
	}

 	void Base_Class::setTwoD( bool TwoD){
		this->TwoD = TwoD;
	}

	bool Base_Class::getThreeD(){
		return this->ThreeD;
	}

	void Base_Class::setThreeD(bool ThreeD){
		this->ThreeD = ThreeD;
	}

	void * Base_Class::getImage(){
		return this->image;
	}

	void Base_Class::setImage(void * image){
		this->image = image;
	}

	void * Base_Class:: getVideo(){
		return this->video;
	}

	void Base_Class::setVideo(void * video){
		this->video = video;
	}

	void * Base_Class::getImageProtocol(){
		return this->imageProtocol;
	}

	void Base_Class::setImageProtocol(void * imageProtocol){
		this->imageProtocol = imageProtocol;
	}

	void * Base_Class::getVideoProtocol(){
		return this->videoProtocol;
	}

	void Base_Class::setVideoProtocol(void * videoProtocol){
		this->videoProtocol = videoProtocol;
	}
	
	void Base_Class::setMenu(char **menu){
		this->menu = menu;
	}
	
	char** Base_Class::getMenu(){
		return this->menu;
	}
}
