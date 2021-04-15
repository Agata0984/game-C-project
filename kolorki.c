#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <gtk/gtk.h>

struct laczenie
{
    int znak;
    int x;
    int y;
    int trudnosc;
    int plansza[10][10];
    int rozmiar;
    int ko;
    int kx;
    GtkWidget *guziki[10][10];
    GtkWidget *gkx;
    GtkWidget *gko;
    GtkWidget *st[5];
    GtkWidget *czyj_ruch;
    GtkWidget *grid;
};

void kolorx1(GtkWidget *widget, gpointer user_data)
{
   struct laczenie * dane=(struct laczenie*)user_data;
    dane->kx=1;
    GdkColor color;
    gdk_color_parse ("red", &color);
    gtk_widget_modify_fg (dane->gkx, GTK_STATE_NORMAL, &color);
}

void kolorx2(GtkWidget *widget, gpointer user_data)
{
    struct laczenie * dane=(struct laczenie*)user_data;
    dane->kx=2;
    GdkColor color;
    gdk_color_parse ("blue", &color);
    gtk_widget_modify_fg (dane->gkx, GTK_STATE_NORMAL, &color);
}

void kolorx3(GtkWidget *widget, gpointer user_data)
{
    struct laczenie * dane=(struct laczenie*)user_data;
    dane->kx=3;
    GdkColor color;
    gdk_color_parse ("green", &color);
    gtk_widget_modify_fg (dane->gkx, GTK_STATE_NORMAL, &color);
}

void kolorx4(GtkWidget *widget, gpointer user_data)
{
   struct laczenie * dane=(struct laczenie*)user_data;
    dane->kx=4;
    GdkColor color;
    gdk_color_parse ("orange", &color);
    gtk_widget_modify_fg (dane->gkx, GTK_STATE_NORMAL, &color);
}

void kolorx5(GtkWidget *widget, gpointer user_data)
{
    struct laczenie * dane=(struct laczenie*)user_data;
    dane->kx=5;
    GdkColor color;
    gdk_color_parse ("purple", &color);
    gtk_widget_modify_fg (dane->gkx, GTK_STATE_NORMAL, &color);
}

void koloro1(GtkWidget *widget, gpointer user_data)
{
    struct laczenie * dane=(struct laczenie*)user_data;
    dane->ko=1;
    GdkColor color;
    gdk_color_parse ("red", &color);
    gtk_widget_modify_fg (dane->gko, GTK_STATE_NORMAL, &color);
}

void koloro2(GtkWidget *widget, gpointer user_data)
{
    struct laczenie * dane=(struct laczenie*)user_data;
    dane->ko=2;
    GdkColor color;
    gdk_color_parse ("blue", &color);
    gtk_widget_modify_fg (dane->gko, GTK_STATE_NORMAL, &color);
}

void koloro3(GtkWidget *widget, gpointer user_data)
{
    struct laczenie * dane=(struct laczenie*)user_data;
    dane->ko=3;
    GdkColor color;
    gdk_color_parse ("green", &color);
    gtk_widget_modify_fg (dane->gko, GTK_STATE_NORMAL, &color);
}

void koloro4(GtkWidget *widget, gpointer user_data)
{
    struct laczenie * dane=(struct laczenie*)user_data;
    dane->ko=4;
    GdkColor color;
    gdk_color_parse ("orange", &color);
    gtk_widget_modify_fg (dane->gko, GTK_STATE_NORMAL, &color);
}

void koloro5(GtkWidget *widget, gpointer user_data)
{
    struct laczenie * dane=(struct laczenie*)user_data;
    dane->ko=5;
    GdkColor color;
    gdk_color_parse ("purple", &color);
    gtk_widget_modify_fg (dane->gko, GTK_STATE_NORMAL, &color);
}

void kolorekx(GtkWidget *widget, gpointer user_data)
{
    struct laczenie * dane=(struct laczenie*)user_data;

    GtkWidget *window1=gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(window1),"wybierz kolor x");
    gtk_window_set_default_size(GTK_WINDOW(window1),100,100);
    gtk_window_set_position(GTK_WINDOW(window1),GTK_WIN_POS_CENTER);
    gtk_container_set_border_width(GTK_CONTAINER(window1), 30);
    g_signal_connect(G_OBJECT(window1),"destroy",G_CALLBACK(gtk_window_close),NULL);

    GtkWidget *grid = gtk_grid_new();
    gtk_grid_set_row_spacing(GTK_GRID(grid), 10);
    gtk_grid_set_column_spacing(GTK_GRID(grid), 10);
    gtk_grid_set_column_homogeneous(GTK_GRID(grid), TRUE);
    gtk_container_add(GTK_CONTAINER(window1), grid);

    GtkWidget *czerwony;
    GtkWidget *niebieski;
    GtkWidget *zielony;
    GtkWidget *pomaranczowy;
    GtkWidget *fioletowy;

    czerwony=gtk_button_new();
    niebieski=gtk_button_new();
    zielony=gtk_button_new();
    pomaranczowy=gtk_button_new();
    fioletowy=gtk_button_new();

    g_signal_connect(czerwony, "clicked", G_CALLBACK(kolorx1),dane);
    g_signal_connect(czerwony, "clicked",G_CALLBACK(gtk_window_close),NULL);
    GdkColor color;
    gdk_color_parse ("red", &color);
    gtk_button_set_label(GTK_BUTTON(czerwony),"czerwony");
    gtk_widget_modify_fg (czerwony, GTK_STATE_NORMAL, &color);
    gtk_grid_attach(GTK_GRID(grid),czerwony, 0, 0,2,10);

    g_signal_connect(niebieski, "clicked", G_CALLBACK(kolorx2),dane);
    g_signal_connect(niebieski, "clicked",G_CALLBACK(gtk_window_close),NULL);
    GdkColor color2;
    gdk_color_parse ("blue", &color2);
    gtk_button_set_label(GTK_BUTTON(niebieski),"niebieski");
    gtk_widget_modify_fg (niebieski, GTK_STATE_NORMAL, &color2);
    gtk_grid_attach(GTK_GRID(grid),niebieski, 2, 0,2,10);

    g_signal_connect(zielony, "clicked", G_CALLBACK(kolorx3),dane);
    g_signal_connect(zielony, "clicked",G_CALLBACK(gtk_window_close),NULL);
    GdkColor color3;
    gdk_color_parse ("green", &color3);
    gtk_button_set_label(GTK_BUTTON(zielony),"zielony");
    gtk_widget_modify_fg (zielony, GTK_STATE_NORMAL, &color3);
    gtk_grid_attach(GTK_GRID(grid),zielony, 4, 0,2,10);

    g_signal_connect(pomaranczowy, "clicked", G_CALLBACK(kolorx4),dane);
    g_signal_connect(pomaranczowy, "clicked",G_CALLBACK(gtk_window_close),NULL);
    GdkColor color4;
    gdk_color_parse ("orange", &color4);
    gtk_button_set_label(GTK_BUTTON(pomaranczowy),"pomaranczowy");
    gtk_widget_modify_fg (pomaranczowy, GTK_STATE_NORMAL, &color4);
    gtk_grid_attach(GTK_GRID(grid),pomaranczowy, 6, 0,2,10);

    g_signal_connect(fioletowy, "clicked", G_CALLBACK(kolorx5),dane);
    g_signal_connect(fioletowy, "clicked",G_CALLBACK(gtk_window_close),NULL);
    GdkColor color5;
    gdk_color_parse ("purple", &color5);
    gtk_button_set_label(GTK_BUTTON(fioletowy),"fioletowy");
    gtk_widget_modify_fg (fioletowy, GTK_STATE_NORMAL, &color5);
    gtk_grid_attach(GTK_GRID(grid),fioletowy, 8, 0,2,10);

    gtk_widget_show_all(window1);

}

void koloreko(GtkWidget *widget, gpointer user_data)
{
    struct laczenie * dane=(struct laczenie*)user_data;

    GtkWidget *window1=gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(window1),"wybierz kolor o");
    gtk_window_set_default_size(GTK_WINDOW(window1),100,100);
    gtk_window_set_position(GTK_WINDOW(window1),GTK_WIN_POS_CENTER);
    gtk_container_set_border_width(GTK_CONTAINER(window1), 30);
    g_signal_connect(G_OBJECT(window1),"destroy",G_CALLBACK(gtk_window_close),NULL);

    GtkWidget *grid = gtk_grid_new();
    gtk_grid_set_row_spacing(GTK_GRID(grid), 10);
    gtk_grid_set_column_spacing(GTK_GRID(grid), 10);
    gtk_grid_set_column_homogeneous(GTK_GRID(grid), TRUE);
    gtk_container_add(GTK_CONTAINER(window1), grid);

    GtkWidget *czerwony;
    GtkWidget *niebieski;
    GtkWidget *zielony;
    GtkWidget *pomaranczowy;
    GtkWidget *fioletowy;

    czerwony=gtk_button_new();
    niebieski=gtk_button_new();
    zielony=gtk_button_new();
    pomaranczowy=gtk_button_new();
    fioletowy=gtk_button_new();

    g_signal_connect(czerwony, "clicked", G_CALLBACK(koloro1),dane);
    g_signal_connect(czerwony, "clicked",G_CALLBACK(gtk_window_close),NULL);
    GdkColor color;
    gdk_color_parse ("red", &color);
    gtk_button_set_label(GTK_BUTTON(czerwony),"czerwony");
    gtk_widget_modify_fg (czerwony, GTK_STATE_NORMAL, &color);
    gtk_grid_attach(GTK_GRID(grid),czerwony, 0, 0,2,10);

    g_signal_connect(niebieski, "clicked", G_CALLBACK(koloro2),dane);
    g_signal_connect(niebieski, "clicked",G_CALLBACK(gtk_window_close),NULL);
    GdkColor color2;
    gdk_color_parse ("blue", &color2);
    gtk_button_set_label(GTK_BUTTON(niebieski),"niebieski");
    gtk_widget_modify_fg (niebieski, GTK_STATE_NORMAL, &color2);
    gtk_grid_attach(GTK_GRID(grid),niebieski, 2, 0,2,10);

    g_signal_connect(zielony, "clicked", G_CALLBACK(koloro3),dane);
    g_signal_connect(zielony, "clicked",G_CALLBACK(gtk_window_close),NULL);
    GdkColor color3;
    gdk_color_parse ("green", &color3);
    gtk_button_set_label(GTK_BUTTON(zielony),"zielony");
    gtk_widget_modify_fg (zielony, GTK_STATE_NORMAL, &color3);
    gtk_grid_attach(GTK_GRID(grid),zielony, 4, 0,2,10);

    g_signal_connect(pomaranczowy, "clicked", G_CALLBACK(koloro4),dane);
    g_signal_connect(pomaranczowy, "clicked",G_CALLBACK(gtk_window_close),NULL);
    GdkColor color4;
    gdk_color_parse ("orange", &color4);
    gtk_button_set_label(GTK_BUTTON(pomaranczowy),"pomaranczowy");
    gtk_widget_modify_fg (pomaranczowy, GTK_STATE_NORMAL, &color4);
    gtk_grid_attach(GTK_GRID(grid),pomaranczowy, 6, 0,2,10);

    g_signal_connect(fioletowy, "clicked", G_CALLBACK(koloro5),dane);
    g_signal_connect(fioletowy, "clicked",G_CALLBACK(gtk_window_close),NULL);
    GdkColor color5;
    gdk_color_parse ("purple", &color5);
    gtk_button_set_label(GTK_BUTTON(fioletowy),"fioletowy");
    gtk_widget_modify_fg (fioletowy, GTK_STATE_NORMAL, &color5);
    gtk_grid_attach(GTK_GRID(grid),fioletowy, 8, 0,2,10);

    gtk_widget_show_all(window1);
}
