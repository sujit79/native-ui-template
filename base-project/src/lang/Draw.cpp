/*
 * C_Draw.cpp
 *
 *  Created on: Mar 7, 2010
 *      Author: dev
 */
#include "Draw.h"

//static gboolean button_press (GtkWidget *, GdkEvent *);
//static void menuitem_response (gchar *);

GtkWidget *hscale, *vscale;

namespace xuigenerate {

	Draw::Draw(std::string name){
		this->widget_name = name;
	}
	
	Draw::~Draw(){
	}

	void Draw::cb_pos_menu_select( GtkWidget       *item,
	                                GtkPositionType  pos )
	{
	    /* Set the value position on both scale widgets */
	    gtk_scale_set_value_pos (GTK_SCALE (hscale), pos);
	    gtk_scale_set_value_pos (GTK_SCALE (vscale), pos);
	}

	void Draw::cb_update_menu_select( GtkWidget     *item,
	                                   GtkUpdateType  policy )
	{
	    /* Set the update policy for both scale widgets */
	    gtk_range_set_update_policy (GTK_RANGE (hscale), policy);
	    gtk_range_set_update_policy (GTK_RANGE (vscale), policy);
	}

	void Draw::cb_digits_scale( GtkAdjustment *adj )
	{
	    /* Set the number of decimal places to which adj->value is rounded */
	    gtk_scale_set_digits (GTK_SCALE (hscale), (gint) adj->value);
	    gtk_scale_set_digits (GTK_SCALE (vscale), (gint) adj->value);
	}

	void Draw::cb_page_size( GtkAdjustment *get,
	                          GtkAdjustment *set )
	{
	    /* Set the page size and page increment size of the sample
	     * adjustment to the value specified by the "Page Size" scale */
	    set->page_size = get->value;
	    set->page_increment = get->value;

	    /* This sets the adjustment and makes it emit the "changed" signal to
	       reconfigure all the widgets that are attached to this signal.  */
	    gtk_adjustment_set_value (set, CLAMP (set->value,
						  set->lower,
						  (set->upper - set->page_size)));
	    g_signal_emit_by_name(G_OBJECT(set), "changed");
	}

	void Draw::cb_draw_value( GtkToggleButton *button )
	{
	    /* Turn the value display on the scale widgets off or on depending
	     *  on the state of the checkbutton */
	    gtk_scale_set_draw_value (GTK_SCALE (hscale), button->active);
	    gtk_scale_set_draw_value (GTK_SCALE (vscale), button->active);
	}

	/* Convenience functions */

	GtkWidget * Draw::make_menu_item ( gchar     *name,
	                                   GCallback  callback,
	                                   gpointer   data )
	{
	    GtkWidget *item;

	    item = gtk_menu_item_new_with_label (name);
	    g_signal_connect (G_OBJECT (item), "activate",
		              callback, (gpointer) data);
	    gtk_widget_show (item);

	    return item;
	}

	void Draw::scale_set_default_values( GtkScale *scale )
	{
	    gtk_range_set_update_policy (GTK_RANGE (scale),
	                                 GTK_UPDATE_CONTINUOUS);
	    gtk_scale_set_digits (scale, 1);
	    gtk_scale_set_value_pos (scale, GTK_POS_TOP);
	    gtk_scale_set_draw_value (scale, TRUE);
	}
	/* Create a new hbox with an image and a label packed into it
	 * and return the box. */

	static GtkWidget *xpm_label_box( gchar     *xpm_filename,
	                                 gchar     *label_text )
	{	
	    GtkWidget *box;
	    GtkWidget *label;
	    GtkWidget *image;

	    /* Create box for image and label */
	    box = gtk_hbox_new (FALSE, 0);
	    gtk_container_set_border_width (GTK_CONTAINER (box), 2);

	    /* Now on to the image stuff */
	    image = gtk_image_new_from_file (xpm_filename);

	    /* Create a label for the button */
	    label = gtk_label_new (label_text);

	    /* Pack the image and label into the box */
	    gtk_box_pack_start (GTK_BOX (box), image, FALSE, FALSE, 3);
	    gtk_box_pack_start (GTK_BOX (box), label, FALSE, FALSE, 3);

	    gtk_widget_show (image);
	    gtk_widget_show (label);

	    return box;
	}

	/* Our usual callback function */
	static void callback( GtkWidget *widget,
                      gpointer   data )
	{
	    g_print ("Hello again - %s was pressed\n", (char *) data);
	}

	/* Respond to a button-press by posting a menu passed in as widget.
	 *
	 * Note that the "widget" argument is the menu being posted, NOT
	 * the button that was pressed.
	 */

	static gboolean button_press( GtkWidget *widget,
                              GdkEvent *event, gpointer data )
	{

	    if (event->type == GDK_BUTTON_PRESS) {
	        GdkEventButton *bevent = (GdkEventButton *) event; 
	        gtk_menu_popup (GTK_MENU (widget), NULL, NULL, NULL, NULL,
                        bevent->button, bevent->time);
	        /* Tell calling code that we have handled this event; the buck
	         * stops here. */
	        return TRUE;
      	    }

   	 /* Tell calling code that we have not handled this event; pass it on. */
	    return FALSE;
	}


	/* Print a string when a menu item is selected */

	static void menuitem_response( gchar *string )
	{	
	    printf ("%s\n", string);
	}
	
	void Draw::drawWindow(std::string title, int x, int y)
	{
		this->widget = gtk_window_new(GTK_WINDOW_TOPLEVEL);
		gtk_widget_set_size_request (GTK_WIDGET(this->widget), x, y);
		g_signal_connect(G_OBJECT(this->widget),"destroy",G_CALLBACK(gtk_main_quit),NULL);
		gtk_window_set_title(GTK_WINDOW(this->widget),title.c_str());
		gtk_widget_show (this->widget);
	}
	
	void Draw::drawMenu(std::string name)
	{
		//this->widget = gtk_menu_new();
	}

}; // End Namespace
