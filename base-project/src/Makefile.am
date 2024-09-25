bin_PROGRAMS=xuibin

src=

src+=base/Base_Class.cpp
src+=base/Base_Class.h
src+=base/UI_Design.cpp
src+=base/UI_Design.h
src+=base/UI_Generate.cpp
src+=base/UI_Generate.h
src+=base/X_UI_Network.cpp
src+=base/X_UI_Network.h
src+=base/X_UI_Network_Protocol.cpp
src+=base/X_UI_Network_Protocol.h

src+=lang/Draw.cpp
src+=lang/Draw.h

src+=xui/ui/X_UI.cpp
src+=xui/ui/X_UI.h

src+=VM/VM.cpp
src+=VM/VM.h

src+=main.cpp


flags=
flags+=-I@top_srcdir@/include
flags+=$(INCL)
flags+=$(XUIBIN_LIBXML_CFLAGS) $(GTK_PACKAGE_CFLAGS) -g3 

xuibin_SOURCES=$(src)
xuibin_CFLAGS=$(flags)
xuibin_CXXFLAGS=$(flags) 
xuibin_LDFLAGS=$(XUIBIN_LIBXML_LIBS) $(GTK_PACKAGE_LIBS) 
