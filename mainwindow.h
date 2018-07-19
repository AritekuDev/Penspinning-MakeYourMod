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
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPixmap>
#include <QMessageBox>
#include <QGraphicsDropShadowEffect>
#include <QFile>
#include <QDesktopServices>
#include <QUrl>
#include <QTextStream>
#include <QStyle>
#include <QDesktopWidget>
#include "menowawindow.h"
#include "busterwindow.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    bool MainBool = false;
    QString textVar;
    bool toogleVisible = true;
    bool isItPolish = true;
    void setUpTransparentButtons();
    void updateComboBoxes();
    void setupColorButtons();
    void setupColorButtons_2();
    void partEventUpdate();
    void onColorClicked();
    void initiateComboBoxes();
    void initiateLeftSailors();
    void initiateRightSailors();
    void changeLanguage();
    void saveLeftState();
    void saveRightState();
    void readLeftState();
    void readRightState();
    void setSavedStates();
    explicit MainWindow(QWidget *parent = 0);

    int PartState = 1;
    bool isItLeftCap = false;
    bool isItLeftGrip = false;
    bool isItLeftSailor = true;
    bool isSailorMenuVisible = false;
    bool isCheckboxesON = false;
    //////////////////
    int BodyColorState = 0;
    int LeftCapColorState = 0;
    int RightCapColorState = 0;
    int LeftGripColorState = 2;
    int RightGripColorState = 2;
    int *LeftSailorTable = new int [4];
    int *RightSailorTable = new int [4];
    int *LeftDownStates = new int[5];
    int *RightDownStates = new int[5];

    QString ColorRed = "#cf2b22"; //#1
    QString ColorWhite = "#ffffff"; //#2
    QString ColorBlack = "#0A0A0A"; //#3
    QString ColorYellow = "#cfda4d"; //#4
    QString ColorSkyBlue = "#236cdd"; //#5
    QString ColorLightGreen = "#59b93c"; //#6
    QString ColorViolet = "#8c69c7"; //#7
    QString ColorPink = "#fe5dad"; //#8
    QString ColorTransparent = "#aeafb3"; //#9
    QString ColorDarkBlue = "#242b71"; //#10
    QString ColorOrange = "#f44123"; //#11

    QString DColorRed = "#be1a11"; //#1
    QString DColorWhite = "#eeeeee"; //#2
    QString DColorBlack = "#090909"; //#3
    QString DColorYellow = "#bec93c"; //#4
    QString DColorSkyBlue = "#125bcc"; //#5
    QString DColorLightGreen = "#48a82b"; //#6
    QString DColorViolet = "#7b58b6"; //#7
    QString DColorPink = "#ed4c9c"; //#8
    QString DColorTransparent = "#9d9ea2"; //#9
    QString DColorDarkBlue = "#131a60"; //#10
    QString DColorOrange = "#e33012"; //#11
    QString ariteku = "http://www.ariteku.pl/";
    ///
    QString* colors = new QString[13];
    QString* colorsEnglish = new QString[13];
    QString* currentColors = new QString[13];
    ///
    ~MainWindow();

private slots:
    void on_exit_released();

    void on_WaterfallSwitch_released();

    void on_CWhite_released();

    void on_Body_released();

    void on_Capy_released();

    void on_Gripy_released();

    void on_CGreen_released();

    void on_CRed_released();

    void on_CYellow_released();

    void on_CBlack_released();

    void on_CSkyBlue_released();

    void on_CViolet_released();

    void on_CPink_released();

    void on_CDarkBlue_released();

    void on_COrange_released();

    void on_CWhite_2_released();

    void on_CGreen_2_released();

    void on_CRed_2_released();

    void on_CYellow_2_released();

    void on_CBlack_2_released();

    void on_CSkyBlue_2_released();

    void on_CViolet_2_released();

    void on_CPink_2_released();

    void on_CTransparent_2_released();

    void on_CDarkBlue_2_released();

    void on_COrange_2_released();

    void on_CTransparent_released();

    void on_pushButton_3_released();

    void on_sailorSubmit_released();

    void on_LeftSide_released();

    void on_RightSide_released();

    void on_Switch_3_released();

    void on_save_2_released();

    void on_save_released();

    void on_open_released();

    void on_language_released();

    void on_save_5_released();

    void on_save_6_released();

    void on_settins_released();

    void on_LeftSideCheckbox_released();

    void on_RightSideCheckbox_released();

    void on_toolButton_released();

    void on_save_4_released();

    void on_save_3_released();

    void on_Switch_2_released();

    void on_Switch_7_released();

    void on_updateApp_released();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
