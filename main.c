#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <gtk/gtk.h>
#include "kolorki.h"
#include "strona_startowa.h"

struct wspolrzedne
{
    int i;
    int j;
    struct laczenie* dane;
};

bool czy_wygrana1(struct laczenie * dane)
{
    int suma=-1;
    int xa=dane->x;
    while(xa>=0 && dane->y>=0 && dane->plansza[xa][dane->y]==(dane->znak)%2)
    {
        suma++;
        xa-=1;
    }
    xa=dane->x;
    while(xa<dane->rozmiar && dane->y<dane->rozmiar && dane->plansza[xa][dane->y]==(dane->znak)%2)
    {
        suma++;
        xa+=1;
    }
    if (suma>=dane->trudnosc)
    {
        return true;
    }

    suma=-1;
    xa=dane->x;
    int ya=dane->y;
    while(xa>=0 && ya>=0 && dane->plansza[xa][ya]==(dane->znak)%2)
    {
        suma++;
        ya-=1;
    }
    xa=dane->x;
    ya=dane->y;
    while(xa<dane->rozmiar && ya<dane->rozmiar && dane->plansza[xa][ya]==(dane->znak)%2)
    {
        suma++;
        ya+=1;
    }
    if (suma>=dane->trudnosc)
    {

        return true;
    }

    suma=-1;
    xa=dane->x;
    ya=dane->y;
    while(xa>=0 && ya>=0 && dane->plansza[xa][ya]==(dane->znak)%2)
    {
        suma++;
        xa-=1;
        ya-=1;
    }
    xa=dane->x;
    ya=dane->y;
    while(xa<dane->rozmiar && ya<dane->rozmiar && dane->plansza[xa][ya]==(dane->znak)%2)
    {
        suma++;
        xa+=1;
        ya+=1;
    }
    if (suma>=dane->trudnosc)
    {
        return true;
    }
    suma=-1;
    xa=dane->x;
    ya=dane->y;
    while(xa>=0 && ya<dane->rozmiar && dane->plansza[xa][ya]==(dane->znak)%2)
    {
        suma++;
        xa-=1;
        ya+=1;
    }
    xa=dane->x;
    ya=dane->y;
    while(xa<dane->rozmiar && ya>=0 && dane->plansza[xa][ya]==(dane->znak)%2)
    {
        suma++;
        xa+=1;
        ya-=1;
    }
    if (suma>=dane->trudnosc)
    {
        return true;
    }

    return false;

}

int czy_wygrana2(struct laczenie * dane)
{
    int y2=dane->y;
    int znak2=dane->znak;
    for(int i=dane->rozmiar-1; i>=0; i--)
    {
        dane->y=i;
        dane->znak=dane->plansza[dane->x][i];
        if(czy_wygrana1(dane)==true)
        {
            dane->y=y2;
            dane->znak=znak2;
            return dane->plansza[dane->x][i];
        }
    }
    return -1;
}

bool czy_ruch1(struct laczenie * dane)
{
    if(dane->plansza[dane->x][dane->y]==-1 && dane->y==(dane->rozmiar)-1)
    {
        return true;
    }
    else
    {
        if(dane->plansza[dane->x][dane->y]==-1 && dane->plansza[dane->x][dane->y+1]!=-1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
}

bool czy_ruch2(struct laczenie * dane)
{
    return dane->plansza[dane->x][dane->y] == (dane->znak)%2
           && dane->y==(dane->rozmiar-1)
           && dane->plansza[dane->x][0]==-1;
}

void ruch2(struct laczenie * dane)
{
    int licznik=0;
    for(int i=(dane->rozmiar)-1; i>0; i--)
    {
        dane->plansza[dane->x][i]=dane->plansza[dane->x][i-1];
        if(dane->plansza[dane->x][i-1]!=-1)
        {
            licznik++;
        }
    }
    dane->plansza[dane->x][dane->rozmiar-1-licznik]=(dane->znak)%2;
    dane->plansza[dane->x][dane->rozmiar-2-licznik]=(dane->znak)%2;
}

void wygrana(int znak)
{
    GtkWidget *window=gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(window),"");
    gtk_window_set_position(GTK_WINDOW(window),GTK_WIN_POS_CENTER);
    gtk_window_set_default_size(GTK_WINDOW(window),100,100);
    gtk_container_set_border_width(GTK_CONTAINER(window), 20);
    GtkWidget *grid = gtk_grid_new();
    gtk_grid_set_row_spacing(GTK_GRID(grid), 3);
    gtk_grid_set_row_homogeneous(GTK_GRID(grid), TRUE);
    gtk_grid_set_column_spacing(GTK_GRID(grid), 3);
    gtk_grid_set_column_homogeneous(GTK_GRID(grid), TRUE);
    gtk_container_add(GTK_CONTAINER(window), grid);
    g_signal_connect(G_OBJECT(window),"destroy",G_CALLBACK(gtk_main_quit),NULL);
    GtkLabel *label;
    if(znak%2==0)
    {
        label=gtk_label_new("wygrana x");
    }
    else
    {
        label=gtk_label_new("wygrana o");
    }
    gtk_grid_attach(GTK_GRID(grid),label, 0, 0,2,1);
    GtkWidget *button=gtk_button_new_with_label("zamknij");
    g_signal_connect(button, "clicked", G_CALLBACK(gtk_main_quit),NULL);
    gtk_grid_attach(GTK_GRID(grid),button, 0, 1,2,1);

    gtk_widget_show_all(window);
}

void remis()
{
    GtkWidget *window=gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(window),"");
    gtk_window_set_position(GTK_WINDOW(window),GTK_WIN_POS_CENTER);
    gtk_window_set_default_size(GTK_WINDOW(window),100,100);
    gtk_container_set_border_width(GTK_CONTAINER(window), 20);
    GtkWidget *grid = gtk_grid_new();
    gtk_grid_set_row_spacing(GTK_GRID(grid), 3);
    gtk_grid_set_row_homogeneous(GTK_GRID(grid), TRUE);
    gtk_grid_set_column_spacing(GTK_GRID(grid), 3);
    gtk_grid_set_column_homogeneous(GTK_GRID(grid), TRUE);
    gtk_container_add(GTK_CONTAINER(window), grid);
    g_signal_connect(G_OBJECT(window),"destroy",G_CALLBACK(gtk_main_quit),NULL);
    GtkLabel *label=gtk_label_new("remis");
    gtk_grid_attach(GTK_GRID(grid),label, 0, 0,2,1);
    GtkWidget *button=gtk_button_new_with_label("zamknij");
    g_signal_connect(button, "clicked", G_CALLBACK(gtk_main_quit),NULL);
    gtk_grid_attach(GTK_GRID(grid),button, 0, 1,2,1);
    gtk_widget_show_all(window);
}

void rysuj(struct wspolrzedne* nowe)
{
    GdkColor color,color2, color3, color4,color5, basic;
    gdk_color_parse ("red", &color);
    gdk_color_parse ("blue", &color2);
    gdk_color_parse ("green", &color3);
    gdk_color_parse ("orange", &color4);
    gdk_color_parse ("purple", &color5);
    gdk_color_parse ("black", &basic);

    for(int i=0; i<nowe->dane->rozmiar; i++)
    {
        for(int j=0; j<nowe->dane->rozmiar; j++)
        {
            if(nowe->dane->plansza[i][j]==0)
            {

                if(nowe->dane->kx==0)
                {
                    gtk_widget_modify_fg (nowe->dane->guziki[i][j], GTK_STATE_NORMAL, &basic);
                }
                else if(nowe->dane->kx==1)
                {
                    gtk_widget_modify_fg (nowe->dane->guziki[i][j], GTK_STATE_NORMAL, &color);
                }
                else if(nowe->dane->kx==2)
                {
                    gtk_widget_modify_fg (nowe->dane->guziki[i][j], GTK_STATE_NORMAL, &color2);
                }
                else if(nowe->dane->kx==3)
                {
                    gtk_widget_modify_fg (nowe->dane->guziki[i][j], GTK_STATE_NORMAL, &color3);
                }
                else if(nowe->dane->kx==4)
                {
                    gtk_widget_modify_fg (nowe->dane->guziki[i][j], GTK_STATE_NORMAL, &color4);
                }
                else if(nowe->dane->kx==5)
                {
                    gtk_widget_modify_fg (nowe->dane->guziki[i][j], GTK_STATE_NORMAL, &color5);
                }
                gtk_button_set_label(GTK_BUTTON(nowe->dane->guziki[i][j]),"x");
            }
            if(nowe->dane->plansza[i][j]==1)
            {
                if(nowe->dane->ko==0)
                {
                    gtk_widget_modify_fg (nowe->dane->guziki[i][j], GTK_STATE_NORMAL, &basic);
                }
                else if(nowe->dane->ko==1)
                {
                    gtk_widget_modify_fg (nowe->dane->guziki[i][j], GTK_STATE_NORMAL, &color);
                }
                else if(nowe->dane->ko==2)
                {
                    gtk_widget_modify_fg (nowe->dane->guziki[i][j], GTK_STATE_NORMAL, &color2);
                }
                else if(nowe->dane->ko==3)
                {
                    gtk_widget_modify_fg (nowe->dane->guziki[i][j], GTK_STATE_NORMAL, &color3);
                }
                else if(nowe->dane->ko==4)
                {
                    gtk_widget_modify_fg (nowe->dane->guziki[i][j], GTK_STATE_NORMAL, &color4);
                }
                else if(nowe->dane->ko==5)
                {
                    gtk_widget_modify_fg (nowe->dane->guziki[i][j], GTK_STATE_NORMAL, &color5);
                }
                gtk_button_set_label(GTK_BUTTON(nowe->dane->guziki[i][j]),"o");
            }
        }
    }
    if(nowe->dane->znak%2==0)
    {
        gtk_label_set_text(nowe->dane->czyj_ruch, "ruch gracza \"o\"");
    }
    else
    {
        gtk_label_set_text(nowe->dane->czyj_ruch, "ruch gracza \"x\"");
    }
}

void blad()
{
    GtkWidget *window=gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(window),"");
    gtk_window_set_position(GTK_WINDOW(window),GTK_WIN_POS_CENTER);
    gtk_window_set_default_size(GTK_WINDOW(window),100,100);
    gtk_container_set_border_width(GTK_CONTAINER(window), 20);
    GtkWidget *grid = gtk_grid_new();
    gtk_grid_set_row_spacing(GTK_GRID(grid), 3);
    gtk_grid_set_row_homogeneous(GTK_GRID(grid), TRUE);
    gtk_grid_set_column_spacing(GTK_GRID(grid), 3);
    gtk_grid_set_column_homogeneous(GTK_GRID(grid), TRUE);
    gtk_container_add(GTK_CONTAINER(window), grid);
    g_signal_connect(G_OBJECT(window),"destroy",G_CALLBACK(gtk_window_close),NULL);
    GtkLabel *label=gtk_label_new("nieprawidlowy ruch");
    gtk_grid_attach(GTK_GRID(grid),label, 0, 0,2,1);
    GtkWidget *button=gtk_button_new_with_label("zamknij");
    g_signal_connect(button, "clicked", G_CALLBACK(gtk_window_close),NULL);
    gtk_grid_attach(GTK_GRID(grid),button, 0, 1,2,1);
    gtk_widget_show_all(window);
}

void klikniecie(GtkWidget *widget, gpointer user_data)
{
    struct wspolrzedne * nowe=(struct wspolrzedne*)user_data;
    nowe->dane->x=nowe->i;
    nowe->dane->y=nowe->j;

    if(czy_ruch1(nowe->dane))
    {
        if((nowe->dane->znak)%2==0)
        {
            nowe->dane->plansza[nowe->i][nowe->j]=0;
        }
        else
        {
            nowe->dane->plansza[nowe->i][nowe->j]=1;
        }
        rysuj(nowe);
        if(czy_wygrana1(nowe->dane))
        {
            wygrana(nowe->dane->znak);
        }
        nowe->dane->znak+=1;
        if(nowe->dane->znak==(nowe->dane->rozmiar)*(nowe->dane->rozmiar))
        {
            remis();
        }
    }
    else
    {
        if(czy_ruch2(nowe->dane))
        {
            ruch2(nowe->dane);

            rysuj(nowe);
            if(czy_wygrana2(nowe->dane)!=-1)
            {
                wygrana(czy_wygrana2(nowe->dane));
            }
            nowe->dane->znak+=1;
            if(nowe->dane->znak==(nowe->dane->rozmiar)*(nowe->dane->rozmiar))
            {
                remis();
            }
        }
        else
        {
            blad();
        }
    }
}
void inicjuj_przyciski(struct laczenie* dane, GtkWidget *window)
{
    for(int i=0; i<(dane->rozmiar); i++)
    {
        for(int j=0; j<(dane->rozmiar); j++)
        {
            dane->plansza[i][j]=-1;
        }
    }
    GtkWidget *grid = gtk_grid_new();
    gtk_grid_set_row_spacing(GTK_GRID(grid), 3);
    gtk_grid_set_row_homogeneous(GTK_GRID(grid), TRUE);
    gtk_grid_set_column_spacing(GTK_GRID(grid), 3);
    gtk_grid_set_column_homogeneous(GTK_GRID(grid), TRUE);
    gtk_container_add(GTK_CONTAINER(window), grid);
    dane->grid=grid;

    GtkWidget *instrukcja;
    instrukcja=gtk_button_new();
    g_signal_connect(instrukcja, "clicked", G_CALLBACK(zasady),dane);
    gtk_button_set_label(GTK_BUTTON(instrukcja),"zasady gry");
    gtk_grid_attach(GTK_GRID(grid),instrukcja, dane->rozmiar-2, dane->rozmiar,2,1);

    GtkWidget *ruch;
    ruch=gtk_label_new("ruch gracza \"x\"");
    gtk_grid_attach(GTK_GRID(grid),ruch, 0, dane->rozmiar,2,1);
    dane->czyj_ruch=ruch;

    GtkWidget *button;
    for(int i=0; i<(dane->rozmiar); i++)
    {
        for(int j=0; j<(dane->rozmiar); j++)
        {
            button=gtk_button_new();
            struct wspolrzedne* nowe=malloc(sizeof(struct wspolrzedne));
            nowe->dane=dane;
            nowe->i=i;
            nowe->j=j;
            nowe->dane->guziki[i][j]=button;
            g_signal_connect(button, "clicked", G_CALLBACK(klikniecie),nowe);
            gtk_grid_attach(GTK_GRID(grid),button, i, j,1,1);
        }
    }

    gtk_widget_show_all(window);


}

int main( int argc, char **argv)
{
    gtk_init(&argc, &argv);


    GtkWidget *window=gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(window),"4 w jednej linii");
    gtk_window_set_default_size(GTK_WINDOW(window),800,800);
    gtk_window_set_position(GTK_WINDOW(window),GTK_WIN_POS_CENTER);
    gtk_container_set_border_width(GTK_CONTAINER(window), 30);
    g_signal_connect(G_OBJECT(window),"destroy",G_CALLBACK(gtk_main_quit),NULL);
    struct laczenie * proba;
    proba=(struct laczenie*)(malloc(sizeof(struct laczenie)));
    proba->znak=0;
    proba->rozmiar=7;
    proba->trudnosc=4;
    proba->ko=0;
    proba->kx=0;

    strona_startowa(proba, window);

    gtk_main();
    return 0;
}
