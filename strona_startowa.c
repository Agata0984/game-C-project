#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <gtk/gtk.h>
#include <string.h>
#include "kolorki.h"


void ustawienia1(GtkWidget *widget, gpointer user_data)
{
    struct laczenie * dane=(struct laczenie*)user_data;
    dane->rozmiar=6;
    GdkColor color, color2;
    gdk_color_parse ("red", &color);
    gtk_widget_modify_fg (widget, GTK_STATE_NORMAL, &color);
    gdk_color_parse ("black", &color2);
    gtk_widget_modify_fg (dane->st[1], GTK_STATE_NORMAL, &color2);
    gtk_widget_modify_fg (dane->st[2], GTK_STATE_NORMAL, &color2);
}

void ustawienia2(GtkWidget *widget, gpointer user_data)
{
    struct laczenie * dane=(struct laczenie*)user_data;
    dane->rozmiar=7;
    GdkColor color, color2;
    gdk_color_parse ("red", &color);
    gtk_widget_modify_fg (widget, GTK_STATE_NORMAL, &color);
    gdk_color_parse ("black", &color2);
    gtk_widget_modify_fg (dane->st[0], GTK_STATE_NORMAL, &color2);
    gtk_widget_modify_fg (dane->st[2], GTK_STATE_NORMAL, &color2);
}

void ustawienia3(GtkWidget *widget, gpointer user_data)
{
    struct laczenie * dane=(struct laczenie*)user_data;
    dane->rozmiar=10;
    GdkColor color, color2;
    gdk_color_parse ("red", &color);
    gtk_widget_modify_fg (widget, GTK_STATE_NORMAL, &color);
    gdk_color_parse ("black", &color2);
    gtk_widget_modify_fg (dane->st[1], GTK_STATE_NORMAL, &color2);
    gtk_widget_modify_fg (dane->st[0], GTK_STATE_NORMAL, &color2);
}

void ustawienia4(GtkWidget *widget, gpointer user_data)
{
    struct laczenie * dane=(struct laczenie*)user_data;
    dane->trudnosc=4;
    GdkColor color, color2;
    gdk_color_parse ("red", &color);
    gtk_widget_modify_fg (widget, GTK_STATE_NORMAL, &color);
    gdk_color_parse ("black", &color2);
    gtk_widget_modify_fg (dane->st[4], GTK_STATE_NORMAL, &color2);
}

void ustawienia5(GtkWidget *widget, gpointer user_data)
{
    struct laczenie * dane=(struct laczenie*)user_data;
    dane->trudnosc=5;
    GdkColor color, color2;
    gdk_color_parse ("red", &color);
    gtk_widget_modify_fg (widget, GTK_STATE_NORMAL, &color);
    gdk_color_parse ("black", &color2);
    gtk_widget_modify_fg (dane->st[3], GTK_STATE_NORMAL, &color2);
}

void poczatek(GtkWidget *widget, gpointer user_data)
{
    struct laczenie * dane=(struct laczenie*)user_data;

    GtkWidget *window1=gtk_window_new(GTK_WINDOW_TOPLEVEL);
    if(dane->trudnosc==4)
    {gtk_window_set_title(GTK_WINDOW(window1),"4 w jednej linii");}
    else{gtk_window_set_title(GTK_WINDOW(window1),"5 w jednej linii");}
    gtk_window_set_default_size(GTK_WINDOW(window1),800,900);
    gtk_window_set_position(GTK_WINDOW(window1),GTK_WIN_POS_CENTER);
    gtk_container_set_border_width(GTK_CONTAINER(window1), 30);
    g_signal_connect(G_OBJECT(window1),"destroy",G_CALLBACK(gtk_main_quit),NULL);

    inicjuj_przyciski( dane, window1);
}

void zasady(GtkWidget *widget, gpointer user_data)
{
    char znak;
    char text[2000];
    int i=0;
    FILE *plik = fopen( "zasady.txt", "r" );
    znak = getc( plik );
    while( znak != EOF )
    {
        text[i]=znak;
        znak = getc( plik );
        i++;
    }
    text[i]='\0';
    fclose( plik );


GtkWidget *window2=gtk_window_new(GTK_WINDOW_TOPLEVEL);
gtk_window_set_position(GTK_WINDOW(window2),GTK_WIN_POS_CENTER);
gtk_window_set_title(GTK_WINDOW(window2),"zasady gry");
GtkWidget *dialog =gtk_message_dialog_new(GTK_WINDOW(window2),GTK_DIALOG_DESTROY_WITH_PARENT, GTK_MESSAGE_ERROR, GTK_BUTTONS_CLOSE,"%s",text);
gtk_dialog_run(GTK_DIALOG(dialog));
gtk_widget_destroy(dialog);
}

void strona_startowa(struct laczenie * dane, GtkWidget *window)
{
    GtkWidget *grid = gtk_grid_new();
    gtk_grid_set_row_spacing(GTK_GRID(grid), 10);
    gtk_grid_set_column_spacing(GTK_GRID(grid), 10);
    gtk_grid_set_column_homogeneous(GTK_GRID(grid), TRUE);
    gtk_container_add(GTK_CONTAINER(window), grid);

    GtkWidget *mala;
    GtkWidget *srednia;
    GtkWidget *duza;
    GtkWidget *latwe;
    GtkWidget *trudne;
    GtkWidget *start;
    GtkWidget *kolorx;
    GtkWidget *koloro;
    GtkWidget *instrukcja;

    mala=gtk_button_new();
    srednia=gtk_button_new();
    duza=gtk_button_new();
    latwe=gtk_button_new();
    trudne=gtk_button_new();
    start=gtk_button_new();
    kolorx=gtk_button_new();
    koloro=gtk_button_new();
    instrukcja=gtk_button_new();

    dane->gkx=kolorx;
    dane->gko=koloro;
    dane->st[0]=mala;
    dane->st[1]=srednia;
    dane->st[2]=duza;
    dane->st[3]=latwe;
    dane->st[4]=trudne;

    g_signal_connect(mala, "clicked", G_CALLBACK(ustawienia1),dane);
    gtk_button_set_label(GTK_BUTTON(mala),"6x6");
    gtk_grid_attach(GTK_GRID(grid),mala, 0, 0,2,30);

    g_signal_connect(srednia, "clicked", G_CALLBACK(ustawienia2),dane);
    gtk_button_set_label(GTK_BUTTON(srednia),"7x7");
    gtk_grid_attach(GTK_GRID(grid),srednia, 2, 0,2,30);

    g_signal_connect(duza, "clicked", G_CALLBACK(ustawienia3),dane);
    gtk_button_set_label(GTK_BUTTON(duza),"10x10");
    gtk_grid_attach(GTK_GRID(grid),duza, 4, 0,2,30);

    g_signal_connect(latwe, "clicked", G_CALLBACK(ustawienia4),dane);
    gtk_button_set_label(GTK_BUTTON(latwe),"4 w linii");
    gtk_grid_attach(GTK_GRID(grid),latwe, 0, 30,3,30);

    g_signal_connect(trudne, "clicked", G_CALLBACK(ustawienia5),dane);
    gtk_button_set_label(GTK_BUTTON(trudne),"5 w linii");
    gtk_grid_attach(GTK_GRID(grid),trudne, 3, 30,3,30);

    g_signal_connect(start, "clicked", G_CALLBACK(poczatek),dane);
    gtk_button_set_label(GTK_BUTTON(start),"start");
    gtk_grid_attach(GTK_GRID(grid),start, 0, 70,6,10);

    g_signal_connect(kolorx, "clicked", G_CALLBACK(kolorekx),dane);
    gtk_button_set_label(GTK_BUTTON(kolorx),"kolor x");
    gtk_grid_attach(GTK_GRID(grid),kolorx, 0, 80,2,5);

    g_signal_connect(koloro, "clicked", G_CALLBACK(koloreko),dane);
    gtk_button_set_label(GTK_BUTTON(koloro),"kolor o");
    gtk_grid_attach(GTK_GRID(grid),koloro, 2, 80,2,5);

    g_signal_connect(instrukcja, "clicked", G_CALLBACK(zasady),dane);
    gtk_button_set_label(GTK_BUTTON(instrukcja),"zasady gry");
    gtk_grid_attach(GTK_GRID(grid),instrukcja, 4, 80,2,5);

    gtk_widget_show_all(window);
}
