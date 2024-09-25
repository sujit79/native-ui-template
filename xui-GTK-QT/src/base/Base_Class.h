/*
 * Base_Class.h
 *
 *  Created on: Mar 7, 2010
 *      Author: dev
 */

#ifndef BASE_CLASS_H_
#define BASE_CLASS_H_
#include "../../include/common.h"

namespace xuigenerate {

class Base_Class {
private:
	char *language;
	char *type;
	char *version;

	char *shape;
	int *plot;
	int *color;

	char *protocol;
	void *socket;
	char *port;

	bool OneD;
	bool TwoD;
	bool ThreeD;

	void *image;
	void *video;

	void *imageProtocol;
	void *videoProtocol;
	
	

public:
	Base_Class();
	~Base_Class();

	char * getLanguage();
	void setLanguage(const char *language);
	char * getType();
	void setType(const char *type);
	char *  getVersion();
	void setVersion(const char *version);

	char * getShape();
	void setShape(const char *shape);
	int * getPlot();
	void setPlot(int *plot);
	int * getColor();
	void setColor(int *);

	char *getProtocol();
	void setProtocol(const char *protocol);
	void *getSocket();
	void setSocket(void *socket);
	char *getPort();
	void setPort(const char *port);

	bool getOneD();
	void setOneD(bool OneD);
	bool getTwoD();
	void setTwoD(bool TwoD);
	bool getThreeD();
	void setThreeD(bool ThreeD);

	void * getImage();
	void setImage(void * image);

	 void * getVideo();
	void setVideo(void * video);

	void * getImageProtocol();
	void setImageProtocol(void * imageProtocol);

	void * getVideoProtocol();
	void setVideoProtocol(void * videoProtocol);


};

}

#endif /* BASE_CLASS_H_ */
