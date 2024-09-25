/*
 * C_Draw.h
 *
 *  Created on: Mar 7, 2010
 *      Author: dev
 */

#ifndef C_DRAW_H_
#define C_DRAW_H_

#include "../../include/common.h"
#include "../base/ByteCode.h"

namespace xuigenerate {

class Draw{
private:

    std::vector<GtkWidget*> window;
    std::vector<GtkWidget*> button;
    std::vector<GtkWidget*> opt, menu, item;
    std::vector<GtkWidget*> file_menu, menu_item, menu_bar, file_item, vbox, hbox, entry;
    std::vector<GtkWidget*>::const_iterator cii, cii_menu_bar,cii_file, cii_vbox,cii_hbox, cii_entry;

    char buf[128];


public:
	Draw();
	virtual ~Draw();
	static void cb_pos_menu_select( GtkWidget *item, GtkPositionType  pos );
	static void cb_update_menu_select( GtkWidget *item, GtkUpdateType  policy );
	static void cb_digits_scale( GtkAdjustment *adj );
	static void cb_page_size( GtkAdjustment *get, GtkAdjustment *set );
	static void cb_draw_value( GtkToggleButton *button );
	static GtkWidget * make_menu_item ( gchar     *name,  GCallback  callback, gpointer   data );
	static void scale_set_default_values( GtkScale *scale );
	static void create_range_controls(void);
	static void enter_callback( GtkWidget *widget,GtkWidget *entry );
	void drawingTool(char code);

};

}

#endif /* C_DRAW_H_ */
