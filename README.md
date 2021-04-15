# game-C-project
Game made in C using Gtk library.
4 w jednej linii / 5 w jednej linii
Zasady gry:
-gra jest przewidziana dla dwóch graczy o znakach „o” i „x”.
-celem gry jest ustawienie czterech lub pięciu (w zależności od wybranego poziomu trudności) znaków w jednej kolumnie, wierszu lub przekątnej.
-możliwy jest wybór jednego z dwóch poziomów trudności:
	-łatwego polegającego na ustawieniu 4 znaków w jednej linii,
	-trudnego polegającego na ustawieniu 5 znaków w jednej linii.
-możliwy jest też wybór rozmiaru planszy, co również wpływa na poziom trudności gry, możliwe do wyboru rozmiary to:
	-mały 6x6 sprawiający, że rozgrywka jest wyjątkowo trudna,
	-klasyczny 7x7 czyli standardowy rozmiar planszy dla gry „4 w jednej linii”,
-duży 10x10 wówczas rozgrywka może stać się dłuższa, ale też ciekawsza przez większą możliwość ruchów.
-dodatkową opcją będzie możliwość wyboru koloru planszy poprzez gracza. Dostępne będą kolory: żółty, różowy, niebieski, zielony, (domyślnie biały).
-gracz stawia znak poprzez kliknięcie na odpowiednią komórkę.
-znak można postawić na trzy sposoby:
	-na samym dole pustej kolumny,
	-na pierwszy od góry znak swój lub przeciwnika,
-zabierając swój znak z samego dołu kolumny, wówczas inne znaki przesunął się, ten zostanie przeniesiony na górę kolumny, a na niego zostanie nałożony jeszcze jeden znak, ten ruch może zostać wykonany tylko jeśli w kolumnie jest jeszcze miejsce.
Gra zostanie napisana w języku programowania C z użyciem biblioteki GTK3.0.  
