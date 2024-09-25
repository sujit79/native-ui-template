#ifndef C_DRAW_H_
#define C_DRAW_H_

#include "../../include/common.h"

namespace xuigenerate {

	class Draw{
		private:

    			GtkWidget *widget;
    			std::string widget_name;

		public:
			Draw(std::string name);
			virtual ~Draw();
			static void cb_pos_menu_select( GtkWidget *item, GtkPositionType  pos );
			static void cb_update_menu_select( GtkWidget *item, GtkUpdateType  policy );
			static void cb_digits_scale( GtkAdjustment *adj );
			static void cb_page_size( GtkAdjustment *get, GtkAdjustment *set );
			static void cb_draw_value( GtkToggleButton *button );
			static GtkWidget * make_menu_item ( gchar     *name,  GCallback  callback, gpointer   data );
			static void scale_set_default_values( GtkScale *scale );
			static void create_range_controls(void);
			std::string getTitle(){return this->widget_name;};
			void drawWindow(std::string title, int x, int y);
			void drawMenu(std::string name);
			
	};

}; // End Namespace

#endif /* C_DRAW_H_ */
