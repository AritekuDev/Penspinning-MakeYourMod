/*Programisto! Ten kod został udostępniony na platformie github: https://github.com/AritekuDev/PenspinningMakeYourMod
 Pod licencją MIT. Proszę, nie usuwaj z niego żadnych informacji o realnych autorach Aplikacji, tj Artur Koniec - Ariteku.pl
 Proszę cię też by program nie uległ zmianie w więcej niż 30%.
 Kosztował mnie on naprawdę wiele czasu i serca, więc uszanuj to, i zastosuj się proszę do powyższych sentencji.
 Pozdrawiam - Arteq - Ariteku.pl - Pełnoprawny autor Penspinning: Make your Mod
*/
/*Programmer! This code was shared with everyone on github platform under link: https://github.com/AritekuDev/PenspinningMakeYourMod
Under the MIT licence. Please, do not remove any information about real author of application - Artur Koniec - Ariteku.pl
Please, don't change this app in more than 30%.
It cost me a lot of time and hearth, so please respect this fact, and don't ignore aboves sentences.
Greetings - Arteq - Ariteku.pl - The real author of Penspinning: Make your Mod.
*/
#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
