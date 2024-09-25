#ifndef _ByteCode_
#define _ByteCode_

typedef union byteCode{
	char c[10];
	struct ID{
		int i;
		int m_id;
		int f_id;
	}id;
} ByteCode;

#endif
