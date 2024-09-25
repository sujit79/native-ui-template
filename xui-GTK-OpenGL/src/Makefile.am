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
AM_CXXFLAGS=$(XUIBIN_LIBXML_CFLAGS) $(GTK_PACKAGE_CFLAGS) $(XUIBIN_LIBCURL_CFLAGS) $(XUIBIN_GTK_MM_CFLAGS)

xuibin_SOURCES=$(src)
xuibin_CFLAGS=$(flags) $(INCL) $(CFLAGS) 
xuibin_LDFLAGS=$(XUIBIN_LIBXML_LIBS) $(GTK_PACKAGE_LIBS) $(XUIBIN_LIBCURL_LIBS) $(XUI_BIN_GTK_MM_LIBS)
