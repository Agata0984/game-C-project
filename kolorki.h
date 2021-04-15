
void kolorx1(GtkWidget *widget, gpointer user_data);
void kolorx2(GtkWidget *widget, gpointer user_data);
void kolorx3(GtkWidget *widget, gpointer user_data);
void kolorx4(GtkWidget *widget, gpointer user_data);
void kolorx5(GtkWidget *widget, gpointer user_data);
void koloro1(GtkWidget *widget, gpointer user_data);
void koloro2(GtkWidget *widget, gpointer user_data);
void koloro3(GtkWidget *widget, gpointer user_data);
void koloro4(GtkWidget *widget, gpointer user_data);
void koloro5(GtkWidget *widget, gpointer user_data);
void kolorekx(GtkWidget *widget, gpointer user_data);
void koloreko(GtkWidget *widget, gpointer user_data);

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
