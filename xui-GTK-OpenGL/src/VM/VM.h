/*
 * VM.h
 *
 *  Created on: Mar 11, 2010
 *      Author: dev
 */

#ifndef VM_H_
#define VM_H_


namespace xuigenerate {

class VM {
private:
	char *VM_Image;

public:
	VM();
	virtual ~VM();



	VM *getVM(void);

	void VM_Initiate();
	void VM_GC();
	void VM_Start_Method(char *methodName,void *param1, int countParams);
};

}

#endif /* VM_H_ */
