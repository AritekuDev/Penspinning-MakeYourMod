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
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //Left Panel Default Settings //This pattern is downloaded from www.subtlepatterns.com If you need more, that's where to get'em.
    QPixmap Panels(":/patterns/retro_intro.png");
    ui->leftPanel->setPixmap(Panels);
    //Right Panel Default Settings
    ui->rightPanel->setPixmap(Panels);
    //Center background Default Settings //This pattern is downloaded from www.subtlepatterns.com If you need more, that's where to get'em.
    QPixmap BG(":/patterns/whirlpool.png");
    ui->BackgroundCenter->setPixmap(BG);
    ui->BackgroundCenter->setScaledContents(true);
    //Waterfall Default
    QPixmap WaterfallDefault(":/Waterfall/WaterfallProporcjonalny.png");
    ui->WaterfalOriginal->setPixmap(WaterfallDefault);
    ui->Part_Body->setVisible(false);
    ui->part_leftCap->setVisible(false);
    ui->part_rightCap->setVisible(false);
    ui->part_leftCap->setVisible(false);
    ui->part_rightGrip->setVisible(false);

    ui->GroupBoxSailors->setVisible(false);
    isItLeftSailor = true;
    ui->LeftSide->setDisabled(true);
    ui->RightSide->setDisabled(false);
    ui->whatAreYouEditing->setText("Edytujesz: ");
    ui->whatAreYouEditing_2->setText("Gripy z lewej strony");
    ui->LeftSide->setVisible(true);
    ui->RightSide->setVisible(true);
    ui->LeftSideCheckbox->setVisible(false);
    ui->RightSideCheckbox->setVisible(false);
    ///
    colors[0] = "<Domyślny>";
    colors[1] = "Czarny";
    colors[2] = "Biały";
    colors[3] = "Szary";
    colors[4] = "Czerwony";
    colors[5] = "Pomarańczowy";
    colors[6] = "Żółty";
    colors[7] = "Jasnozielony";
    colors[8] = "Ciemnozielony";
    colors[9] = "Błękitny";
    colors[10] = "Niebieski";
    colors[11] = "Fioletowy";
    colors[12] = "Różowy";
    ///
    colorsEnglish[0] = "<Default>";
    colorsEnglish[1] = "Black";
    colorsEnglish[2] = "White";
    colorsEnglish[3] = "Grey";
    colorsEnglish[4] = "Red";
    colorsEnglish[5] = "Orange";
    colorsEnglish[6] = "Yellow";
    colorsEnglish[7] = "Light Green";
    colorsEnglish[8] = "Dark Green";
    colorsEnglish[9] = "Sky Blue";
    colorsEnglish[10] = "Dark Blue";
    colorsEnglish[11] = "Violet";
    colorsEnglish[12] = "Magenta";
    ///
    for(int i=0; i<13; i++){
        currentColors[i] = colors[i];
    }
    ///
    setUpTransparentButtons();
    setupColorButtons();
    setupColorButtons_2();
    partEventUpdate();
    initiateComboBoxes();
    setWindowFlags(Qt::Window);
    for(int i=0; i<5; i++){
        LeftDownStates[i] = 0;
        RightDownStates[i] = 0;
    }
    QApplication::desktop()->screenCount();
    QApplication::desktop()->screenNumber();
    QApplication::desktop()->screenGeometry(this);
}

MainWindow::~MainWindow()
{
    delete[] LeftSailorTable;
    delete[] RightSailorTable;
    delete[] colors;
    delete[] colorsEnglish;
    delete[] currentColors;
    delete[] LeftDownStates;
    delete[] RightDownStates;
    delete ui;
}

void MainWindow::setUpTransparentButtons(){
    //Text Shadow Snippet
    QGraphicsDropShadowEffect *effect = new QGraphicsDropShadowEffect(this);
    effect->setBlurRadius(10);
    effect->setColor(QColor("#000000"));
    effect->setOffset(0,0);
    QGraphicsDropShadowEffect *effect1 = new QGraphicsDropShadowEffect(this);
    effect1->setBlurRadius(10);
    effect1->setColor(QColor("#000000"));
    effect1->setOffset(0,0);
    QGraphicsDropShadowEffect *effect2 = new QGraphicsDropShadowEffect(this);
    effect2->setBlurRadius(10);
    effect2->setColor(QColor("#000000"));
    effect2->setOffset(0,0);
    QGraphicsDropShadowEffect *effect3 = new QGraphicsDropShadowEffect(this);
    effect3->setBlurRadius(10);
    effect3->setColor(QColor("#000000"));
    effect3->setOffset(0,0);
    QGraphicsDropShadowEffect *effect4 = new QGraphicsDropShadowEffect(this);
    effect4->setBlurRadius(10);
    effect4->setColor(QColor("#000000"));
    effect4->setOffset(0,0);
    QGraphicsDropShadowEffect *effect5 = new QGraphicsDropShadowEffect(this);
    effect5->setBlurRadius(10);
    effect5->setColor(QColor("#000000"));
    effect5->setOffset(0,0);
    QGraphicsDropShadowEffect *effect6 = new QGraphicsDropShadowEffect(this);
    effect6->setBlurRadius(10);
    effect6->setColor(QColor("#000000"));
    effect6->setOffset(0,0);
    QGraphicsDropShadowEffect *effect7 = new QGraphicsDropShadowEffect(this);
    effect7->setBlurRadius(10);
    effect7->setColor(QColor("#000000"));
    effect7->setOffset(0,0);
    QGraphicsDropShadowEffect *effect8 = new QGraphicsDropShadowEffect(this);
    effect8->setBlurRadius(10);
    effect8->setColor(QColor("#000000"));
    effect8->setOffset(0,0);
    QGraphicsDropShadowEffect *effect9 = new QGraphicsDropShadowEffect(this);
    effect9->setBlurRadius(10);
    effect9->setColor(QColor("#000000"));
    effect9->setOffset(0,0);
    QGraphicsDropShadowEffect *effect10 = new QGraphicsDropShadowEffect(this);
    effect10->setBlurRadius(10);
    effect10->setColor(QColor("#000000"));
    effect10->setOffset(0,0);
    QGraphicsDropShadowEffect *effect11 = new QGraphicsDropShadowEffect(this);
    effect11->setBlurRadius(10);
    effect11->setColor(QColor("#000000"));
    effect11->setOffset(0,0);
    QGraphicsDropShadowEffect *effect12 = new QGraphicsDropShadowEffect(this);
    effect12->setBlurRadius(10);
    effect12->setColor(QColor("#000000"));
    effect12->setOffset(0,0);
    QGraphicsDropShadowEffect *effect13 = new QGraphicsDropShadowEffect(this);
    effect13->setBlurRadius(15);
    effect13->setColor(QColor("#000000"));
    effect13->setOffset(0,0);
    QGraphicsDropShadowEffect *effect14 = new QGraphicsDropShadowEffect(this);
    effect14->setBlurRadius(15);
    effect14->setColor(QColor("#000000"));
    effect14->setOffset(0,0);
    QGraphicsDropShadowEffect *effect15 = new QGraphicsDropShadowEffect(this);
    effect15->setBlurRadius(15);
    effect15->setColor(QColor("#000000"));
    effect15->setOffset(0,0);
    QGraphicsDropShadowEffect *effect16 = new QGraphicsDropShadowEffect(this);
    effect16->setBlurRadius(15);
    effect16->setColor(QColor("#000000"));
    effect16->setOffset(0,0);
    //Making buttons transparent
    ui->WaterfallSwitch->setStyleSheet("QPushButton {background: transparent; color: white; font-size: 20px; font-weight: bold;}");
    ui->WaterfallSwitch->setGraphicsEffect(effect);
    ui->WaterfallSwitch->setCursor(Qt::PointingHandCursor);
    /////////////////////////////////////////////////////////
    ui->Switch_2->setStyleSheet("QPushButton {background: transparent; color: white; font-size: 20px; font-weight: bold;}");
    ui->Switch_2->setGraphicsEffect(effect1);
    ui->Switch_2->setCursor(Qt::PointingHandCursor);
    /////////////////////////////////////////////////////////
    ui->Switch_3->setStyleSheet("QPushButton {background: transparent; color: white; font-size: 20px; font-weight: bold;}");
    ui->Switch_3->setGraphicsEffect(effect2);
    ui->Switch_3->setCursor(Qt::PointingHandCursor);
    /////////////////////////////////////////////////////////
    ui->Switch_4->setStyleSheet("QPushButton {background: transparent; color: white; font-size: 20px; font-weight: bold;}");
    ui->Switch_4->setGraphicsEffect(effect3);
    ui->Switch_4->setCursor(Qt::PointingHandCursor);
    /////////////////////////////////////////////////////////
    ui->Switch_5->setStyleSheet("QPushButton {background: transparent; color: white; font-size: 20px; font-weight: bold;}");
    ui->Switch_5->setGraphicsEffect(effect4);
    ui->Switch_5->setCursor(Qt::PointingHandCursor);
    /////////////////////////////////////////////////////////
    ui->Switch_6->setStyleSheet("QPushButton {background: transparent; color: white; font-size: 20px; font-weight: bold;}");
    ui->Switch_6->setGraphicsEffect(effect5);
    ui->Switch_6->setCursor(Qt::PointingHandCursor);
    /////////////////////////////////////////////////////////
    ui->Body->setStyleSheet("QPushButton {background: transparent; color: white; font-size: 20px; font-weight: bold;}");
    ui->Body->setGraphicsEffect(effect6);
    ui->Body->setCursor(Qt::PointingHandCursor);
    /////////////////////////////////////////////////////////
    ui->Capy->setStyleSheet("QPushButton {background: transparent; color: white; font-size: 20px; font-weight: bold;}");
    ui->Capy->setGraphicsEffect(effect7);
    ui->Capy->setCursor(Qt::PointingHandCursor);
    /////////////////////////////////////////////////////////
    ui->Gripy->setStyleSheet("QPushButton {background: transparent; color: white; font-size: 20px; font-weight: bold;}");
    ui->Gripy->setGraphicsEffect(effect8);
    ui->Gripy->setCursor(Qt::PointingHandCursor);
    /////////////////////////////////////////////////////////
    this->setStyleSheet("QGroupBox::title {color: white; font-size: 20px; font-weight: bold;}");
    ui->groupBox->setGraphicsEffect(effect9);
    /////////////////////////////////////////////////////////
    ui->LabelEdit->setStyleSheet("QLabel {color: white; font-size: 15px; font-weight: bold;}");
    ui->LabelEdit->setGraphicsEffect(effect10);
    /////////////////////////////////////////////////////////
    ui->groupBox_2->setGraphicsEffect(effect11);
    /////////////////////////////////////////////////////////
    ui->WaterfalOriginal->setGraphicsEffect(effect12);
    /////////////////////////////////////////////////////////
    ui->leftPanel->setGraphicsEffect(effect13);
    /////////////////////////////////////////////////////////
    ui->rightPanel->setGraphicsEffect(effect14);
    /////////////////////////////////////////////////////////
    ui->Switch_7->setGraphicsEffect(effect15);
    ui->Switch_7->setStyleSheet("QPushButton {background: transparent; color: white; font-size: 20px; font-weight: bold;}");
    ui->Switch_7->setCursor(Qt::PointingHandCursor);
    /////////////////////////////////////////////////////////
    ui->title->setGraphicsEffect(effect16);
}

void MainWindow::setupColorButtons(){
    //White #1
    ui->CWhite->setText("");
    ui->CWhite->setStyleSheet("QPushButton { background-color:"+ColorWhite+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorWhite+"}");
    ui->CWhite->setCursor(Qt::PointingHandCursor);
    //Black #2
    ui->CBlack->setText("");
    ui->CBlack->setStyleSheet("QPushButton { background-color:"+ColorBlack+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorBlack+"}");
    ui->CBlack->setCursor(Qt::PointingHandCursor);
    //Red #3
    ui->CRed->setText("");
    ui->CRed->setStyleSheet("QPushButton { background-color:"+ColorRed+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorRed+"}");
    ui->CRed->setCursor(Qt::PointingHandCursor);
    //Yellow #4
    ui->CYellow->setText("");
    ui->CYellow->setStyleSheet("QPushButton { background-color:"+ColorYellow+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorYellow+"}");
    ui->CYellow->setCursor(Qt::PointingHandCursor);
    //Green #5
    ui->CGreen->setText("");
    ui->CGreen->setStyleSheet("QPushButton { background-color:"+ColorLightGreen+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorLightGreen+"}");
    ui->CGreen->setCursor(Qt::PointingHandCursor);
    //SkyBlue #6
    ui->CSkyBlue->setText("");
    ui->CSkyBlue->setStyleSheet("QPushButton { background-color:"+ColorSkyBlue+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorSkyBlue+"}");
    ui->CSkyBlue->setCursor(Qt::PointingHandCursor);
    //Violet #7
    ui->CViolet->setText("");
    ui->CViolet->setStyleSheet("QPushButton { background-color:"+ColorViolet+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorViolet+"}");
    ui->CViolet->setCursor(Qt::PointingHandCursor);
    //Pink #8
    ui->CPink->setText("");
    ui->CPink->setStyleSheet("QPushButton { background-color:"+ColorPink+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorPink+"}");
    ui->CPink->setCursor(Qt::PointingHandCursor);
    //Transparent #9
    ui->CTransparent->setText("");
    ui->CTransparent->setStyleSheet("QPushButton { background-color:"+ColorTransparent+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorTransparent+"}");
    ui->CTransparent->setCursor(Qt::PointingHandCursor);
    //Dark Blue #10
    ui->CDarkBlue->setText("");
    ui->CDarkBlue->setStyleSheet("QPushButton { background-color:"+ColorDarkBlue+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorDarkBlue+"}");
    ui->CDarkBlue->setCursor(Qt::PointingHandCursor);
    //Orange #11
    ui->COrange->setText("");
    ui->COrange->setStyleSheet("QPushButton { background-color:"+ColorOrange+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorOrange+"}");
    ui->COrange->setCursor(Qt::PointingHandCursor);
}

void MainWindow::setupColorButtons_2(){
    //White #1
    ui->CWhite_2->setText("");
    ui->CWhite_2->setStyleSheet("QPushButton { background-color:"+ColorWhite+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorWhite+"}");
    ui->CWhite_2->setCursor(Qt::PointingHandCursor);
    //Black #2
    ui->CBlack_2->setText("");
    ui->CBlack_2->setStyleSheet("QPushButton { background-color:"+ColorBlack+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorBlack+"}");
    ui->CBlack_2->setCursor(Qt::PointingHandCursor);
    //Red #3
    ui->CRed_2->setText("");
    ui->CRed_2->setStyleSheet("QPushButton { background-color:"+ColorRed+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorRed+"}");
    ui->CRed_2->setCursor(Qt::PointingHandCursor);
    //Yellow #4
    ui->CYellow_2->setText("");
    ui->CYellow_2->setStyleSheet("QPushButton { background-color:"+ColorYellow+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorYellow+"}");
    ui->CYellow_2->setCursor(Qt::PointingHandCursor);
    //Green #5
    ui->CGreen_2->setText("");
    ui->CGreen_2->setStyleSheet("QPushButton { background-color:"+ColorLightGreen+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorLightGreen+"}");
    ui->CGreen_2->setCursor(Qt::PointingHandCursor);
    //SkyBlue #6
    ui->CSkyBlue_2->setText("");
    ui->CSkyBlue_2->setStyleSheet("QPushButton { background-color:"+ColorSkyBlue+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorSkyBlue+"}");
    ui->CSkyBlue_2->setCursor(Qt::PointingHandCursor);
    //Violet #7
    ui->CViolet_2->setText("");
    ui->CViolet_2->setStyleSheet("QPushButton { background-color:"+ColorViolet+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorViolet+"}");
    ui->CViolet_2->setCursor(Qt::PointingHandCursor);
    //Pink #8
    ui->CPink_2->setText("");
    ui->CPink_2->setStyleSheet("QPushButton { background-color:"+ColorPink+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorPink+"}");;
    ui->CPink_2->setCursor(Qt::PointingHandCursor);
    //Transparent #9
    ui->CTransparent_2->setText("");
    ui->CTransparent_2->setStyleSheet("QPushButton { background-color:"+ColorTransparent+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorTransparent+"}");
    ui->CTransparent_2->setCursor(Qt::PointingHandCursor);
    //Dark Blue #10
    ui->CDarkBlue_2->setText("");
    ui->CDarkBlue_2->setStyleSheet("QPushButton { background-color:"+ColorDarkBlue+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorDarkBlue+"}");
    ui->CDarkBlue_2->setCursor(Qt::PointingHandCursor);
    //Orange #11
    ui->COrange_2->setText("");
    ui->COrange_2->setStyleSheet("QPushButton { background-color:"+ColorOrange+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorOrange+"}");
    ui->COrange_2->setCursor(Qt::PointingHandCursor);
}

void MainWindow::partEventUpdate(){
    switch(PartState)
    {
    case 1: //Body jest wybrane

    ui->CRed->setVisible(true); //#1
    ui->CYellow->setVisible(true); //#2
    ui->CGreen->setVisible(true); //#3
    ui->CPink->setVisible(true); //#4
    ui->CViolet->setVisible(true); //#5
    ui->CSkyBlue->setVisible(true); //#6
 // ui->CWhite->setVisible(true); //#7 <-- Always Visible
 // ui->CBlack->setVisible(true); //#8 <-- Always Visible
    ui->CTransparent->setVisible(false); //#9
    ui->CDarkBlue->setVisible(false); //#10
    ui->COrange->setVisible(false);

    ui->CRed_2->setVisible(true); //#1
    ui->CYellow_2->setVisible(true); //#2
    ui->CGreen_2->setVisible(true); //#3
    ui->CPink_2->setVisible(true); //#4
    ui->CViolet_2->setVisible(true); //#5
    ui->CSkyBlue_2->setVisible(true); //#6
 // ui->CWhite_2->setVisible(true); //#7 <-- Always Visible
 // ui->CBlack_2->setVisible(true); //#8 <-- Always Visible
    ui->CTransparent_2->setVisible(false); //#9
    ui->CDarkBlue_2->setVisible(false); //#10
    ui->COrange_2->setVisible(false);

    ui->groupBox_2->setVisible(false);
    if(isItPolish){
        ui->LabelEdit->setText("Edytujesz: BODY");
        ui->groupBox->setTitle("Body");
    }else{
        ui->LabelEdit->setText("Editing: BODY");
        ui->groupBox->setTitle("Body");
    }
    switch(BodyColorState)
    {

    case 0:
    {
        ui->CWhite->setStyleSheet("QPushButton { background-color:"+ColorWhite+"; border: 2px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorWhite+"}");
        ui->CGreen->setStyleSheet("QPushButton { background-color:"+ColorLightGreen+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorLightGreen+"}");
        ui->CRed->setStyleSheet("QPushButton { background-color:"+ColorRed+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorRed+"}");
        ui->CYellow->setStyleSheet("QPushButton { background-color:"+ColorYellow+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorYellow+"}");
        ui->CBlack->setStyleSheet("QPushButton { background-color:"+ColorBlack+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorBlack+"}");
        ui->CSkyBlue->setStyleSheet("QPushButton { background-color:"+ColorSkyBlue+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorSkyBlue+"}");
        ui->CViolet->setStyleSheet("QPushButton { background-color:"+ColorViolet+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorViolet+"}");
        ui->CPink->setStyleSheet("QPushButton { background-color:"+ColorPink+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorPink+"}");

    }break;
    case 1:
    {
        ui->CWhite->setStyleSheet("QPushButton { background-color:"+ColorWhite+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorWhite+"}");
        ui->CGreen->setStyleSheet("QPushButton { background-color:"+ColorLightGreen+"; border: 2px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorLightGreen+"}");
        ui->CRed->setStyleSheet("QPushButton { background-color:"+ColorRed+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorRed+"}");
        ui->CYellow->setStyleSheet("QPushButton { background-color:"+ColorYellow+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorYellow+"}");
        ui->CBlack->setStyleSheet("QPushButton { background-color:"+ColorBlack+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorBlack+"}");
        ui->CSkyBlue->setStyleSheet("QPushButton { background-color:"+ColorSkyBlue+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorSkyBlue+"}");
        ui->CViolet->setStyleSheet("QPushButton { background-color:"+ColorViolet+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorViolet+"}");
        ui->CPink->setStyleSheet("QPushButton { background-color:"+ColorPink+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorPink+"}");

    }break;
    case 2:
    {
        ui->CWhite->setStyleSheet("QPushButton { background-color:"+ColorWhite+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorWhite+"}");
        ui->CGreen->setStyleSheet("QPushButton { background-color:"+ColorLightGreen+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorLightGreen+"}");
        ui->CRed->setStyleSheet("QPushButton { background-color:"+ColorRed+"; border: 2px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorRed+"}");
        ui->CYellow->setStyleSheet("QPushButton { background-color:"+ColorYellow+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorYellow+"}");
        ui->CBlack->setStyleSheet("QPushButton { background-color:"+ColorBlack+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorBlack+"}");
        ui->CSkyBlue->setStyleSheet("QPushButton { background-color:"+ColorSkyBlue+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorSkyBlue+"}");
        ui->CViolet->setStyleSheet("QPushButton { background-color:"+ColorViolet+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorViolet+"}");
        ui->CPink->setStyleSheet("QPushButton { background-color:"+ColorPink+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorPink+"}");

    }break;
    case 3:
    {
        ui->CWhite->setStyleSheet("QPushButton { background-color:"+ColorWhite+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorWhite+"}");
        ui->CGreen->setStyleSheet("QPushButton { background-color:"+ColorLightGreen+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorLightGreen+"}");
        ui->CRed->setStyleSheet("QPushButton { background-color:"+ColorRed+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorRed+"}");
        ui->CYellow->setStyleSheet("QPushButton { background-color:"+ColorYellow+"; border: 2px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorYellow+"}");
        ui->CBlack->setStyleSheet("QPushButton { background-color:"+ColorBlack+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorBlack+"}");
        ui->CSkyBlue->setStyleSheet("QPushButton { background-color:"+ColorSkyBlue+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorSkyBlue+"}");
        ui->CViolet->setStyleSheet("QPushButton { background-color:"+ColorViolet+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorViolet+"}");
        ui->CPink->setStyleSheet("QPushButton { background-color:"+ColorPink+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorPink+"}");

    }break;
    case 4:
    {
        ui->CWhite->setStyleSheet("QPushButton { background-color:"+ColorWhite+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorWhite+"}");
        ui->CGreen->setStyleSheet("QPushButton { background-color:"+ColorLightGreen+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorLightGreen+"}");
        ui->CRed->setStyleSheet("QPushButton { background-color:"+ColorRed+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorRed+"}");
        ui->CYellow->setStyleSheet("QPushButton { background-color:"+ColorYellow+"; border: 2px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorYellow+"}");
        ui->CBlack->setStyleSheet("QPushButton { background-color:"+ColorBlack+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorBlack+"}");
        ui->CSkyBlue->setStyleSheet("QPushButton { background-color:"+ColorSkyBlue+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorSkyBlue+"}");
        ui->CViolet->setStyleSheet("QPushButton { background-color:"+ColorViolet+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorViolet+"}");
        ui->CPink->setStyleSheet("QPushButton { background-color:"+ColorPink+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorPink+"}");

    }break;
    case 5:
    {
        ui->CWhite->setStyleSheet("QPushButton { background-color:"+ColorWhite+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorWhite+"}");
        ui->CGreen->setStyleSheet("QPushButton { background-color:"+ColorLightGreen+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorLightGreen+"}");
        ui->CRed->setStyleSheet("QPushButton { background-color:"+ColorRed+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorRed+"}");
        ui->CYellow->setStyleSheet("QPushButton { background-color:"+ColorYellow+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorYellow+"}");
        ui->CBlack->setStyleSheet("QPushButton { background-color:"+ColorBlack+"; border: 2px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorBlack+"}");
        ui->CSkyBlue->setStyleSheet("QPushButton { background-color:"+ColorSkyBlue+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorSkyBlue+"}");
        ui->CViolet->setStyleSheet("QPushButton { background-color:"+ColorViolet+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorViolet+"}");
        ui->CPink->setStyleSheet("QPushButton { background-color:"+ColorPink+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorPink+"}");

    }break;
    case 6:
    {
        ui->CWhite->setStyleSheet("QPushButton { background-color:"+ColorWhite+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorWhite+"}");
        ui->CGreen->setStyleSheet("QPushButton { background-color:"+ColorLightGreen+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorLightGreen+"}");
        ui->CRed->setStyleSheet("QPushButton { background-color:"+ColorRed+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorRed+"}");
        ui->CYellow->setStyleSheet("QPushButton { background-color:"+ColorYellow+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorYellow+"}");
        ui->CBlack->setStyleSheet("QPushButton { background-color:"+ColorBlack+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorBlack+"}");
        ui->CSkyBlue->setStyleSheet("QPushButton { background-color:"+ColorSkyBlue+"; border: 2px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorSkyBlue+"}");
        ui->CViolet->setStyleSheet("QPushButton { background-color:"+ColorViolet+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorViolet+"}");
        ui->CPink->setStyleSheet("QPushButton { background-color:"+ColorPink+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorPink+"}");

    }break;
    case 7:
    {
        ui->CWhite->setStyleSheet("QPushButton { background-color:"+ColorWhite+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorWhite+"}");
        ui->CGreen->setStyleSheet("QPushButton { background-color:"+ColorLightGreen+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorLightGreen+"}");
        ui->CRed->setStyleSheet("QPushButton { background-color:"+ColorRed+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorRed+"}");
        ui->CYellow->setStyleSheet("QPushButton { background-color:"+ColorYellow+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorYellow+"}");
        ui->CBlack->setStyleSheet("QPushButton { background-color:"+ColorBlack+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorBlack+"}");
        ui->CSkyBlue->setStyleSheet("QPushButton { background-color:"+ColorSkyBlue+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorSkyBlue+"}");
        ui->CViolet->setStyleSheet("QPushButton { background-color:"+ColorViolet+"; border: 2px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorViolet+"}");
        ui->CPink->setStyleSheet("QPushButton { background-color:"+ColorPink+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorPink+"}");

    }break;
    case 8:
    {
        ui->CWhite->setStyleSheet("QPushButton { background-color:"+ColorWhite+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorWhite+"}");
        ui->CGreen->setStyleSheet("QPushButton { background-color:"+ColorLightGreen+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorLightGreen+"}");
        ui->CRed->setStyleSheet("QPushButton { background-color:"+ColorRed+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorRed+"}");
        ui->CYellow->setStyleSheet("QPushButton { background-color:"+ColorYellow+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorYellow+"}");
        ui->CBlack->setStyleSheet("QPushButton { background-color:"+ColorBlack+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorBlack+"}");
        ui->CSkyBlue->setStyleSheet("QPushButton { background-color:"+ColorSkyBlue+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorSkyBlue+"}");
        ui->CViolet->setStyleSheet("QPushButton { background-color:"+ColorViolet+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorViolet+"}");
        ui->CPink->setStyleSheet("QPushButton { background-color:"+ColorPink+"; border: 2px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorPink+"}");

    }break;
    }

    break;

    case 2: //Capy są wybrane
    ui->CRed->setVisible(true); //#1
    ui->CYellow->setVisible(true); //#2
    ui->CGreen->setVisible(true); //#3
    ui->CPink->setVisible(true); //#4
    ui->CViolet->setVisible(true); //#5
    ui->CSkyBlue->setVisible(true); //#6
 // ui->CWhite->setVisible(true); //#7 <-- Always Visible
 // ui->CBlack->setVisible(true); //#8 <-- Always Visible
    ui->CTransparent->setVisible(false);
    ui->CDarkBlue->setVisible(true);
    ui->COrange->setVisible(true);

    ui->CRed_2->setVisible(true); //#1
    ui->CYellow_2->setVisible(true); //#2
    ui->CGreen_2->setVisible(true); //#3
    ui->CPink_2->setVisible(true); //#4
    ui->CViolet_2->setVisible(true); //#5
    ui->CSkyBlue_2->setVisible(true); //#6
 // ui->CWhite_2->setVisible(true); //#7 <-- Always Visible
 // ui->CBlack_2->setVisible(true); //#8 <-- Always Visible
    ui->CTransparent_2->setVisible(false);
    ui->CDarkBlue_2->setVisible(true);
    ui->COrange_2->setVisible(true);

    ui->groupBox_2->setVisible(true);
    if(isItPolish){
        ui->LabelEdit->setText("Edytujesz: CAPY");
        ui->groupBox->setTitle("Lewy Cap");
        ui->groupBox_2->setTitle("Prawy Cap");
    }else{
        ui->LabelEdit->setText("Editing: CAPS");
        ui->groupBox->setTitle("Left Cap");
        ui->groupBox_2->setTitle("Right Cap");
    }

    switch(LeftCapColorState)
    {

    case 0:
    {
        ui->CWhite->setStyleSheet("QPushButton { background-color:"+ColorWhite+"; border: 2px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorWhite+"}");
        ui->CGreen->setStyleSheet("QPushButton { background-color:"+ColorLightGreen+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorLightGreen+"}");
        ui->CRed->setStyleSheet("QPushButton { background-color:"+ColorRed+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorRed+"}");
        ui->CYellow->setStyleSheet("QPushButton { background-color:"+ColorYellow+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorYellow+"}");
        ui->CBlack->setStyleSheet("QPushButton { background-color:"+ColorBlack+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorBlack+"}");
        ui->CSkyBlue->setStyleSheet("QPushButton { background-color:"+ColorSkyBlue+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorSkyBlue+"}");
        ui->CViolet->setStyleSheet("QPushButton { background-color:"+ColorViolet+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorViolet+"}");
        ui->CPink->setStyleSheet("QPushButton { background-color:"+ColorPink+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorPink+"}");
        ui->CDarkBlue->setStyleSheet("QPushButton { background-color:"+ColorDarkBlue+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorDarkBlue+"}");
        ui->COrange->setStyleSheet("QPushButton { background-color:"+ColorOrange+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorOrange+"}");

    }break;
    case 1:
    {
        ui->CWhite->setStyleSheet("QPushButton { background-color:"+ColorWhite+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorWhite+"}");
        ui->CGreen->setStyleSheet("QPushButton { background-color:"+ColorLightGreen+"; border: 2px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorLightGreen+"}");
        ui->CRed->setStyleSheet("QPushButton { background-color:"+ColorRed+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorRed+"}");
        ui->CYellow->setStyleSheet("QPushButton { background-color:"+ColorYellow+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorYellow+"}");
        ui->CBlack->setStyleSheet("QPushButton { background-color:"+ColorBlack+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorBlack+"}");
        ui->CSkyBlue->setStyleSheet("QPushButton { background-color:"+ColorSkyBlue+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorSkyBlue+"}");
        ui->CViolet->setStyleSheet("QPushButton { background-color:"+ColorViolet+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorViolet+"}");
        ui->CPink->setStyleSheet("QPushButton { background-color:"+ColorPink+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorPink+"}");
        ui->CDarkBlue->setStyleSheet("QPushButton { background-color:"+ColorDarkBlue+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorDarkBlue+"}");
        ui->COrange->setStyleSheet("QPushButton { background-color:"+ColorOrange+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorOrange+"}");

    }break;
    case 2:
    {
        ui->CWhite->setStyleSheet("QPushButton { background-color:"+ColorWhite+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorWhite+"}");
        ui->CGreen->setStyleSheet("QPushButton { background-color:"+ColorLightGreen+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorLightGreen+"}");
        ui->CRed->setStyleSheet("QPushButton { background-color:"+ColorRed+"; border: 2px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorRed+"}");
        ui->CYellow->setStyleSheet("QPushButton { background-color:"+ColorYellow+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorYellow+"}");
        ui->CBlack->setStyleSheet("QPushButton { background-color:"+ColorBlack+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorBlack+"}");
        ui->CSkyBlue->setStyleSheet("QPushButton { background-color:"+ColorSkyBlue+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorSkyBlue+"}");
        ui->CViolet->setStyleSheet("QPushButton { background-color:"+ColorViolet+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorViolet+"}");
        ui->CPink->setStyleSheet("QPushButton { background-color:"+ColorPink+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorPink+"}");
        ui->CDarkBlue->setStyleSheet("QPushButton { background-color:"+ColorDarkBlue+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorDarkBlue+"}");
        ui->COrange->setStyleSheet("QPushButton { background-color:"+ColorOrange+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorOrange+"}");

    }break;
    case 3:
    {
        ui->CWhite->setStyleSheet("QPushButton { background-color:"+ColorWhite+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorWhite+"}");
        ui->CGreen->setStyleSheet("QPushButton { background-color:"+ColorLightGreen+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorLightGreen+"}");
        ui->CRed->setStyleSheet("QPushButton { background-color:"+ColorRed+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorRed+"}");
        ui->CYellow->setStyleSheet("QPushButton { background-color:"+ColorYellow+"; border: 2px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorYellow+"}");
        ui->CBlack->setStyleSheet("QPushButton { background-color:"+ColorBlack+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorBlack+"}");
        ui->CSkyBlue->setStyleSheet("QPushButton { background-color:"+ColorSkyBlue+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorSkyBlue+"}");
        ui->CViolet->setStyleSheet("QPushButton { background-color:"+ColorViolet+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorViolet+"}");
        ui->CPink->setStyleSheet("QPushButton { background-color:"+ColorPink+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorPink+"}");
        ui->CDarkBlue->setStyleSheet("QPushButton { background-color:"+ColorDarkBlue+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorDarkBlue+"}");
        ui->COrange->setStyleSheet("QPushButton { background-color:"+ColorOrange+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorOrange+"}");

    }break;
    case 4:
    {
        ui->CWhite->setStyleSheet("QPushButton { background-color:"+ColorWhite+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorWhite+"}");
        ui->CGreen->setStyleSheet("QPushButton { background-color:"+ColorLightGreen+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorLightGreen+"}");
        ui->CRed->setStyleSheet("QPushButton { background-color:"+ColorRed+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorRed+"}");
        ui->CYellow->setStyleSheet("QPushButton { background-color:"+ColorYellow+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorYellow+"}");
        ui->CBlack->setStyleSheet("QPushButton { background-color:"+ColorBlack+"; border: 2px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorBlack+"}");
        ui->CSkyBlue->setStyleSheet("QPushButton { background-color:"+ColorSkyBlue+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorSkyBlue+"}");
        ui->CViolet->setStyleSheet("QPushButton { background-color:"+ColorViolet+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorViolet+"}");
        ui->CPink->setStyleSheet("QPushButton { background-color:"+ColorPink+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorPink+"}");
        ui->CDarkBlue->setStyleSheet("QPushButton { background-color:"+ColorDarkBlue+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorDarkBlue+"}");
        ui->COrange->setStyleSheet("QPushButton { background-color:"+ColorOrange+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorOrange+"}");

    }break;
    case 5:
    {
        ui->CWhite->setStyleSheet("QPushButton { background-color:"+ColorWhite+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorWhite+"}");
        ui->CGreen->setStyleSheet("QPushButton { background-color:"+ColorLightGreen+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorLightGreen+"}");
        ui->CRed->setStyleSheet("QPushButton { background-color:"+ColorRed+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorRed+"}");
        ui->CYellow->setStyleSheet("QPushButton { background-color:"+ColorYellow+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorYellow+"}");
        ui->CBlack->setStyleSheet("QPushButton { background-color:"+ColorBlack+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorBlack+"}");
        ui->CSkyBlue->setStyleSheet("QPushButton { background-color:"+ColorSkyBlue+"; border: 2px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorSkyBlue+"}");
        ui->CViolet->setStyleSheet("QPushButton { background-color:"+ColorViolet+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorViolet+"}");
        ui->CPink->setStyleSheet("QPushButton { background-color:"+ColorPink+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorPink+"}");
        ui->CDarkBlue->setStyleSheet("QPushButton { background-color:"+ColorDarkBlue+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorDarkBlue+"}");
        ui->COrange->setStyleSheet("QPushButton { background-color:"+ColorOrange+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorOrange+"}");

    }break;
    case 6:
    {
        ui->CWhite->setStyleSheet("QPushButton { background-color:"+ColorWhite+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorWhite+"}");
        ui->CGreen->setStyleSheet("QPushButton { background-color:"+ColorLightGreen+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorLightGreen+"}");
        ui->CRed->setStyleSheet("QPushButton { background-color:"+ColorRed+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorRed+"}");
        ui->CYellow->setStyleSheet("QPushButton { background-color:"+ColorYellow+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorYellow+"}");
        ui->CBlack->setStyleSheet("QPushButton { background-color:"+ColorBlack+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorBlack+"}");
        ui->CSkyBlue->setStyleSheet("QPushButton { background-color:"+ColorSkyBlue+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorSkyBlue+"}");
        ui->CViolet->setStyleSheet("QPushButton { background-color:"+ColorViolet+"; border: 2px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorViolet+"}");
        ui->CPink->setStyleSheet("QPushButton { background-color:"+ColorPink+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorPink+"}");
        ui->CDarkBlue->setStyleSheet("QPushButton { background-color:"+ColorDarkBlue+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorDarkBlue+"}");
        ui->COrange->setStyleSheet("QPushButton { background-color:"+ColorOrange+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorOrange+"}");

    }break;
    case 7:
    {
        ui->CWhite->setStyleSheet("QPushButton { background-color:"+ColorWhite+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorWhite+"}");
        ui->CGreen->setStyleSheet("QPushButton { background-color:"+ColorLightGreen+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorLightGreen+"}");
        ui->CRed->setStyleSheet("QPushButton { background-color:"+ColorRed+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorRed+"}");
        ui->CYellow->setStyleSheet("QPushButton { background-color:"+ColorYellow+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorYellow+"}");
        ui->CBlack->setStyleSheet("QPushButton { background-color:"+ColorBlack+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorBlack+"}");
        ui->CSkyBlue->setStyleSheet("QPushButton { background-color:"+ColorSkyBlue+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorSkyBlue+"}");
        ui->CViolet->setStyleSheet("QPushButton { background-color:"+ColorViolet+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorViolet+"}");
        ui->CPink->setStyleSheet("QPushButton { background-color:"+ColorPink+"; border: 2px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorPink+"}");
        ui->CDarkBlue->setStyleSheet("QPushButton { background-color:"+ColorDarkBlue+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorDarkBlue+"}");
        ui->COrange->setStyleSheet("QPushButton { background-color:"+ColorOrange+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorOrange+"}");

    }break;
    case 8:
    {
        ui->CWhite->setStyleSheet("QPushButton { background-color:"+ColorWhite+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorWhite+"}");
        ui->CGreen->setStyleSheet("QPushButton { background-color:"+ColorLightGreen+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorLightGreen+"}");
        ui->CRed->setStyleSheet("QPushButton { background-color:"+ColorRed+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorRed+"}");
        ui->CYellow->setStyleSheet("QPushButton { background-color:"+ColorYellow+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorYellow+"}");
        ui->CBlack->setStyleSheet("QPushButton { background-color:"+ColorBlack+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorBlack+"}");
        ui->CSkyBlue->setStyleSheet("QPushButton { background-color:"+ColorSkyBlue+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorSkyBlue+"}");
        ui->CViolet->setStyleSheet("QPushButton { background-color:"+ColorViolet+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorViolet+"}");
        ui->CPink->setStyleSheet("QPushButton { background-color:"+ColorPink+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorPink+"}");
        ui->CDarkBlue->setStyleSheet("QPushButton { background-color:"+ColorDarkBlue+"; border: 2px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorDarkBlue+"}");
        ui->COrange->setStyleSheet("QPushButton { background-color:"+ColorOrange+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorOrange+"}");

    }break;
    case 9:
    {
        ui->CWhite->setStyleSheet("QPushButton { background-color:"+ColorWhite+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorWhite+"}");
        ui->CGreen->setStyleSheet("QPushButton { background-color:"+ColorLightGreen+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorLightGreen+"}");
        ui->CRed->setStyleSheet("QPushButton { background-color:"+ColorRed+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorRed+"}");
        ui->CYellow->setStyleSheet("QPushButton { background-color:"+ColorYellow+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorYellow+"}");
        ui->CBlack->setStyleSheet("QPushButton { background-color:"+ColorBlack+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorBlack+"}");
        ui->CSkyBlue->setStyleSheet("QPushButton { background-color:"+ColorSkyBlue+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorSkyBlue+"}");
        ui->CViolet->setStyleSheet("QPushButton { background-color:"+ColorViolet+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorViolet+"}");
        ui->CPink->setStyleSheet("QPushButton { background-color:"+ColorPink+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorPink+"}");
        ui->CDarkBlue->setStyleSheet("QPushButton { background-color:"+ColorDarkBlue+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorDarkBlue+"}");
        ui->COrange->setStyleSheet("QPushButton { background-color:"+ColorOrange+"; border: 2px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorOrange+"}");
    }break;
    }

    switch(RightCapColorState)
    {

    case 0:
    {
        ui->CWhite_2->setStyleSheet("QPushButton { background-color:"+ColorWhite+"; border: 2px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorWhite+"}");
        ui->CGreen_2->setStyleSheet("QPushButton { background-color:"+ColorLightGreen+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorLightGreen+"}");
        ui->CRed_2->setStyleSheet("QPushButton { background-color:"+ColorRed+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorRed+"}");
        ui->CYellow_2->setStyleSheet("QPushButton { background-color:"+ColorYellow+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorYellow+"}");
        ui->CBlack_2->setStyleSheet("QPushButton { background-color:"+ColorBlack+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorBlack+"}");
        ui->CSkyBlue_2->setStyleSheet("QPushButton { background-color:"+ColorSkyBlue+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorSkyBlue+"}");
        ui->CViolet_2->setStyleSheet("QPushButton { background-color:"+ColorViolet+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorViolet+"}");
        ui->CPink_2->setStyleSheet("QPushButton { background-color:"+ColorPink+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorPink+"}");
        ui->CDarkBlue_2->setStyleSheet("QPushButton { background-color:"+ColorDarkBlue+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorDarkBlue+"}");
        ui->COrange_2->setStyleSheet("QPushButton { background-color:"+ColorOrange+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorOrange+"}");

    }break;
    case 1:
    {
        ui->CWhite_2->setStyleSheet("QPushButton { background-color:"+ColorWhite+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorWhite+"}");
        ui->CGreen_2->setStyleSheet("QPushButton { background-color:"+ColorLightGreen+"; border: 2px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorLightGreen+"}");
        ui->CRed_2->setStyleSheet("QPushButton { background-color:"+ColorRed+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorRed+"}");
        ui->CYellow_2->setStyleSheet("QPushButton { background-color:"+ColorYellow+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorYellow+"}");
        ui->CBlack_2->setStyleSheet("QPushButton { background-color:"+ColorBlack+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorBlack+"}");
        ui->CSkyBlue_2->setStyleSheet("QPushButton { background-color:"+ColorSkyBlue+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorSkyBlue+"}");
        ui->CViolet_2->setStyleSheet("QPushButton { background-color:"+ColorViolet+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorViolet+"}");
        ui->CPink_2->setStyleSheet("QPushButton { background-color:"+ColorPink+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorPink+"}");
        ui->CDarkBlue_2->setStyleSheet("QPushButton { background-color:"+ColorDarkBlue+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorDarkBlue+"}");
        ui->COrange_2->setStyleSheet("QPushButton { background-color:"+ColorOrange+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorOrange+"}");

    }break;
    case 2:
    {
        ui->CWhite_2->setStyleSheet("QPushButton { background-color:"+ColorWhite+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorWhite+"}");
        ui->CGreen_2->setStyleSheet("QPushButton { background-color:"+ColorLightGreen+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorLightGreen+"}");
        ui->CRed_2->setStyleSheet("QPushButton { background-color:"+ColorRed+"; border: 2px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorRed+"}");
        ui->CYellow_2->setStyleSheet("QPushButton { background-color:"+ColorYellow+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorYellow+"}");
        ui->CBlack_2->setStyleSheet("QPushButton { background-color:"+ColorBlack+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorBlack+"}");
        ui->CSkyBlue_2->setStyleSheet("QPushButton { background-color:"+ColorSkyBlue+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorSkyBlue+"}");
        ui->CViolet_2->setStyleSheet("QPushButton { background-color:"+ColorViolet+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorViolet+"}");
        ui->CPink_2->setStyleSheet("QPushButton { background-color:"+ColorPink+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorPink+"}");
        ui->CDarkBlue_2->setStyleSheet("QPushButton { background-color:"+ColorDarkBlue+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorDarkBlue+"}");
        ui->COrange_2->setStyleSheet("QPushButton { background-color:"+ColorOrange+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorOrange+"}");

    }break;
    case 3:
    {
        ui->CWhite_2->setStyleSheet("QPushButton { background-color:"+ColorWhite+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorWhite+"}");
        ui->CGreen_2->setStyleSheet("QPushButton { background-color:"+ColorLightGreen+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorLightGreen+"}");
        ui->CRed_2->setStyleSheet("QPushButton { background-color:"+ColorRed+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorRed+"}");
        ui->CYellow_2->setStyleSheet("QPushButton { background-color:"+ColorYellow+"; border: 2px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorYellow+"}");
        ui->CBlack_2->setStyleSheet("QPushButton { background-color:"+ColorBlack+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorBlack+"}");
        ui->CSkyBlue_2->setStyleSheet("QPushButton { background-color:"+ColorSkyBlue+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorSkyBlue+"}");
        ui->CViolet_2->setStyleSheet("QPushButton { background-color:"+ColorViolet+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorViolet+"}");
        ui->CPink_2->setStyleSheet("QPushButton { background-color:"+ColorPink+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorPink+"}");
        ui->CDarkBlue_2->setStyleSheet("QPushButton { background-color:"+ColorDarkBlue+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorDarkBlue+"}");
        ui->COrange_2->setStyleSheet("QPushButton { background-color:"+ColorOrange+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorOrange+"}");

    }break;
    case 4:
    {
        ui->CWhite_2->setStyleSheet("QPushButton { background-color:"+ColorWhite+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorWhite+"}");
        ui->CGreen_2->setStyleSheet("QPushButton { background-color:"+ColorLightGreen+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorLightGreen+"}");
        ui->CRed_2->setStyleSheet("QPushButton { background-color:"+ColorRed+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorRed+"}");
        ui->CYellow_2->setStyleSheet("QPushButton { background-color:"+ColorYellow+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorYellow+"}");
        ui->CBlack_2->setStyleSheet("QPushButton { background-color:"+ColorBlack+"; border: 2px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorBlack+"}");
        ui->CSkyBlue_2->setStyleSheet("QPushButton { background-color:"+ColorSkyBlue+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorSkyBlue+"}");
        ui->CViolet_2->setStyleSheet("QPushButton { background-color:"+ColorViolet+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorViolet+"}");
        ui->CPink_2->setStyleSheet("QPushButton { background-color:"+ColorPink+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorPink+"}");
        ui->CDarkBlue_2->setStyleSheet("QPushButton { background-color:"+ColorDarkBlue+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorDarkBlue+"}");
        ui->COrange_2->setStyleSheet("QPushButton { background-color:"+ColorOrange+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorOrange+"}");

    }break;
    case 5:
    {
        ui->CWhite_2->setStyleSheet("QPushButton { background-color:"+ColorWhite+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorWhite+"}");
        ui->CGreen_2->setStyleSheet("QPushButton { background-color:"+ColorLightGreen+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorLightGreen+"}");
        ui->CRed_2->setStyleSheet("QPushButton { background-color:"+ColorRed+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorRed+"}");
        ui->CYellow_2->setStyleSheet("QPushButton { background-color:"+ColorYellow+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorYellow+"}");
        ui->CBlack_2->setStyleSheet("QPushButton { background-color:"+ColorBlack+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorBlack+"}");
        ui->CSkyBlue_2->setStyleSheet("QPushButton { background-color:"+ColorSkyBlue+"; border: 2px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorSkyBlue+"}");
        ui->CViolet_2->setStyleSheet("QPushButton { background-color:"+ColorViolet+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorViolet+"}");
        ui->CPink_2->setStyleSheet("QPushButton { background-color:"+ColorPink+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorPink+"}");
        ui->CDarkBlue_2->setStyleSheet("QPushButton { background-color:"+ColorDarkBlue+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorDarkBlue+"}");
        ui->COrange_2->setStyleSheet("QPushButton { background-color:"+ColorOrange+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorOrange+"}");

    }break;
    case 6:
    {
        ui->CWhite_2->setStyleSheet("QPushButton { background-color:"+ColorWhite+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorWhite+"}");
        ui->CGreen_2->setStyleSheet("QPushButton { background-color:"+ColorLightGreen+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorLightGreen+"}");
        ui->CRed_2->setStyleSheet("QPushButton { background-color:"+ColorRed+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorRed+"}");
        ui->CYellow_2->setStyleSheet("QPushButton { background-color:"+ColorYellow+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorYellow+"}");
        ui->CBlack_2->setStyleSheet("QPushButton { background-color:"+ColorBlack+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorBlack+"}");
        ui->CSkyBlue_2->setStyleSheet("QPushButton { background-color:"+ColorSkyBlue+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorSkyBlue+"}");
        ui->CViolet_2->setStyleSheet("QPushButton { background-color:"+ColorViolet+"; border: 2px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorViolet+"}");
        ui->CPink_2->setStyleSheet("QPushButton { background-color:"+ColorPink+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorPink+"}");
        ui->CDarkBlue_2->setStyleSheet("QPushButton { background-color:"+ColorDarkBlue+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorDarkBlue+"}");
        ui->COrange_2->setStyleSheet("QPushButton { background-color:"+ColorOrange+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorOrange+"}");

    }break;
    case 7:
    {
        ui->CWhite_2->setStyleSheet("QPushButton { background-color:"+ColorWhite+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorWhite+"}");
        ui->CGreen_2->setStyleSheet("QPushButton { background-color:"+ColorLightGreen+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorLightGreen+"}");
        ui->CRed_2->setStyleSheet("QPushButton { background-color:"+ColorRed+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorRed+"}");
        ui->CYellow_2->setStyleSheet("QPushButton { background-color:"+ColorYellow+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorYellow+"}");
        ui->CBlack_2->setStyleSheet("QPushButton { background-color:"+ColorBlack+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorBlack+"}");
        ui->CSkyBlue_2->setStyleSheet("QPushButton { background-color:"+ColorSkyBlue+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorSkyBlue+"}");
        ui->CViolet_2->setStyleSheet("QPushButton { background-color:"+ColorViolet+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorViolet+"}");
        ui->CPink_2->setStyleSheet("QPushButton { background-color:"+ColorPink+"; border: 2px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorPink+"}");
        ui->CDarkBlue_2->setStyleSheet("QPushButton { background-color:"+ColorDarkBlue+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorDarkBlue+"}");
        ui->COrange_2->setStyleSheet("QPushButton { background-color:"+ColorOrange+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorOrange+"}");

    }break;
    case 8:
    {
        ui->CWhite_2->setStyleSheet("QPushButton { background-color:"+ColorWhite+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorWhite+"}");
        ui->CGreen_2->setStyleSheet("QPushButton { background-color:"+ColorLightGreen+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorLightGreen+"}");
        ui->CRed_2->setStyleSheet("QPushButton { background-color:"+ColorRed+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorRed+"}");
        ui->CYellow_2->setStyleSheet("QPushButton { background-color:"+ColorYellow+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorYellow+"}");
        ui->CBlack_2->setStyleSheet("QPushButton { background-color:"+ColorBlack+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorBlack+"}");
        ui->CSkyBlue_2->setStyleSheet("QPushButton { background-color:"+ColorSkyBlue+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorSkyBlue+"}");
        ui->CViolet_2->setStyleSheet("QPushButton { background-color:"+ColorViolet+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorViolet+"}");
        ui->CPink_2->setStyleSheet("QPushButton { background-color:"+ColorPink+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorPink+"}");
        ui->CDarkBlue_2->setStyleSheet("QPushButton { background-color:"+ColorDarkBlue+"; border: 2px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorDarkBlue+"}");
        ui->COrange_2->setStyleSheet("QPushButton { background-color:"+ColorOrange+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorOrange+"}");

    }break;
    case 9:
    {
        ui->CWhite_2->setStyleSheet("QPushButton { background-color:"+ColorWhite+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorWhite+"}");
        ui->CGreen_2->setStyleSheet("QPushButton { background-color:"+ColorLightGreen+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorLightGreen+"}");
        ui->CRed_2->setStyleSheet("QPushButton { background-color:"+ColorRed+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorRed+"}");
        ui->CYellow_2->setStyleSheet("QPushButton { background-color:"+ColorYellow+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorYellow+"}");
        ui->CBlack_2->setStyleSheet("QPushButton { background-color:"+ColorBlack+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorBlack+"}");
        ui->CSkyBlue_2->setStyleSheet("QPushButton { background-color:"+ColorSkyBlue+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorSkyBlue+"}");
        ui->CViolet_2->setStyleSheet("QPushButton { background-color:"+ColorViolet+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorViolet+"}");
        ui->CPink_2->setStyleSheet("QPushButton { background-color:"+ColorPink+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorPink+"}");
        ui->CDarkBlue_2->setStyleSheet("QPushButton { background-color:"+ColorDarkBlue+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorDarkBlue+"}");
        ui->COrange_2->setStyleSheet("QPushButton { background-color:"+ColorOrange+"; border: 2px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorOrange+"}");

    }break;
    }

    break;

    case 3: //Gripy są wybrane
    ui->CRed->setVisible(false); //#1
    ui->CYellow->setVisible(false); //#2
    ui->CGreen->setVisible(false); //#3
    ui->CPink->setVisible(false); //#4
    ui->CViolet->setVisible(false); //#5
    ui->CSkyBlue->setVisible(false); //#6
 // ui->CWhite->setVisible(true); //#7 <-- Always Visible
 // ui->CBlack->setVisible(true); //#8 <-- Always Visible
    ui->CTransparent->setVisible(true);
    ui->CDarkBlue->setVisible(false);
    ui->COrange->setVisible(false);

    ui->CRed_2->setVisible(false); //#1
    ui->CYellow_2->setVisible(false); //#2
    ui->CGreen_2->setVisible(false); //#3
    ui->CPink_2->setVisible(false); //#4
    ui->CViolet_2->setVisible(false); //#5
    ui->CSkyBlue_2->setVisible(false); //#6
 // ui->CWhite_2->setVisible(true); //#7 <-- Always Visible
 // ui->CBlack_2->setVisible(true); //#8 <-- Always Visible
    ui->CTransparent_2->setVisible(true);
    ui->CDarkBlue_2->setVisible(false);
    ui->COrange_2->setVisible(false);

    ui->groupBox_2->setVisible(true);
    if(isItPolish){
        ui->LabelEdit->setText("Edytujesz: GRIPY");
        ui->groupBox->setTitle("Lewy Grip");
        ui->groupBox_2->setTitle("Prawy Grip");
    }else{
        ui->LabelEdit->setText("Editing: GRIPS");
        ui->groupBox->setTitle("Left Grip");
        ui->groupBox_2->setTitle("Right Grip");
    }
    switch(LeftGripColorState)
    {

    case 0:
    {
        ui->CWhite->setStyleSheet("QPushButton { background-color:"+ColorWhite+"; border: 2px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorWhite+"}");
        ui->CTransparent->setStyleSheet("QPushButton { background-color:"+ColorTransparent+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorTransparent+"}");
        ui->CBlack->setStyleSheet("QPushButton { background-color:"+ColorBlack+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorBlack+"}");

    }break;
    case 1:
    {
        ui->CWhite->setStyleSheet("QPushButton { background-color:"+ColorWhite+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorWhite+"}");
        ui->CTransparent->setStyleSheet("QPushButton { background-color:"+ColorTransparent+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorTransparent+"}");
        ui->CBlack->setStyleSheet("QPushButton { background-color:"+ColorBlack+"; border: 2px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorBlack+"}");

    }break;
    case 2:
    {
        ui->CWhite->setStyleSheet("QPushButton { background-color:"+ColorWhite+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorWhite+"}");
        ui->CTransparent->setStyleSheet("QPushButton { background-color:"+ColorTransparent+"; border: 2px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorTransparent+"}");
        ui->CBlack->setStyleSheet("QPushButton { background-color:"+ColorBlack+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorBlack+"}");
    }break;
    }
    switch(RightGripColorState)
    {

    case 0:
    {
        ui->CWhite_2->setStyleSheet("QPushButton { background-color:"+ColorWhite+"; border: 2px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorWhite+"}");
        ui->CTransparent_2->setStyleSheet("QPushButton { background-color:"+ColorTransparent+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorTransparent+"}");
        ui->CBlack_2->setStyleSheet("QPushButton { background-color:"+ColorBlack+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorBlack+"}");

    }break;
    case 1:
    {
        ui->CWhite_2->setStyleSheet("QPushButton { background-color:"+ColorWhite+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorWhite+"}");
        ui->CTransparent_2->setStyleSheet("QPushButton { background-color:"+ColorTransparent+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorTransparent+"}");
        ui->CBlack_2->setStyleSheet("QPushButton { background-color:"+ColorBlack+"; border: 2px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorBlack+"}");

    }break;
    case 2:
    {
        ui->CWhite_2->setStyleSheet("QPushButton { background-color:"+ColorWhite+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorWhite+"}");
        ui->CTransparent_2->setStyleSheet("QPushButton { background-color:"+ColorTransparent+"; border: 2px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorTransparent+"}");
        ui->CBlack_2->setStyleSheet("QPushButton { background-color:"+ColorBlack+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorBlack+"}");
    }break;
    }

    break;

    default: PartState = 1; partEventUpdate(); break; //Jezeli jakims cudem jest wybrane cos innego, przypisz body
}
}
void MainWindow::onColorClicked(){
    if(PartState == 1){
        switch(BodyColorState)
        {

        case 0: //White (img disappear)
        {
             ui->CWhite->setStyleSheet("QPushButton { background-color:"+ColorWhite+"; border: 2px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorWhite+"}");
             ui->CGreen->setStyleSheet("QPushButton { background-color:"+ColorLightGreen+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorLightGreen+"}");
             ui->CRed->setStyleSheet("QPushButton { background-color:"+ColorRed+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorRed+"}");
             ui->CYellow->setStyleSheet("QPushButton { background-color:"+ColorYellow+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorYellow+"}");
             ui->CBlack->setStyleSheet("QPushButton { background-color:"+ColorBlack+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorBlack+"}");
             ui->CSkyBlue->setStyleSheet("QPushButton { background-color:"+ColorSkyBlue+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorSkyBlue+"}");
             ui->CViolet->setStyleSheet("QPushButton { background-color:"+ColorViolet+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorViolet+"}");
             ui->CPink->setStyleSheet("QPushButton { background-color:"+ColorPink+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorPink+"}");
             ///
             ui->Part_Body->setVisible(false);
        } break;

        case 1: //Green
        {
            ui->CWhite->setStyleSheet("QPushButton { background-color:"+ColorWhite+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorWhite+"}");
            ui->CGreen->setStyleSheet("QPushButton { background-color:"+ColorLightGreen+"; border: 2px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorLightGreen+"}");
            ui->CRed->setStyleSheet("QPushButton { background-color:"+ColorRed+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorRed+"}");
            ui->CYellow->setStyleSheet("QPushButton { background-color:"+ColorYellow+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorYellow+"}");
            ui->CBlack->setStyleSheet("QPushButton { background-color:"+ColorBlack+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorBlack+"}");
            ui->CSkyBlue->setStyleSheet("QPushButton { background-color:"+ColorSkyBlue+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorSkyBlue+"}");
            ui->CViolet->setStyleSheet("QPushButton { background-color:"+ColorViolet+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorViolet+"}");
            ui->CPink->setStyleSheet("QPushButton { background-color:"+ColorPink+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorPink+"}");
            QPixmap bodyGreen(":/Waterfall/Body/Body/green.png");
            ui->Part_Body->setPixmap(bodyGreen);
            ui->Part_Body->setVisible(true);
        } break;

        case 2: //Red
        {
            ui->CWhite->setStyleSheet("QPushButton { background-color:"+ColorWhite+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorWhite+"}");
            ui->CGreen->setStyleSheet("QPushButton { background-color:"+ColorLightGreen+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorLightGreen+"}");
            ui->CRed->setStyleSheet("QPushButton { background-color:"+ColorRed+"; border: 2px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorRed+"}");
            ui->CYellow->setStyleSheet("QPushButton { background-color:"+ColorYellow+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorYellow+"}");
            ui->CBlack->setStyleSheet("QPushButton { background-color:"+ColorBlack+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorBlack+"}");
            ui->CSkyBlue->setStyleSheet("QPushButton { background-color:"+ColorSkyBlue+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorSkyBlue+"}");
            ui->CViolet->setStyleSheet("QPushButton { background-color:"+ColorViolet+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorViolet+"}");
            ui->CPink->setStyleSheet("QPushButton { background-color:"+ColorPink+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorPink+"}");
            QPixmap bodyRed(":/Waterfall/Body/Body/red.png");
            ui->Part_Body->setPixmap(bodyRed);
            ui->Part_Body->setVisible(true);
        } break;

        case 3: //Yellow
        {
            ui->CWhite->setStyleSheet("QPushButton { background-color:"+ColorWhite+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorWhite+"}");
            ui->CGreen->setStyleSheet("QPushButton { background-color:"+ColorLightGreen+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorLightGreen+"}");
            ui->CRed->setStyleSheet("QPushButton { background-color:"+ColorRed+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorRed+"}");
            ui->CYellow->setStyleSheet("QPushButton { background-color:"+ColorYellow+"; border: 2px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorYellow+"}");
            ui->CBlack->setStyleSheet("QPushButton { background-color:"+ColorBlack+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorBlack+"}");
            ui->CSkyBlue->setStyleSheet("QPushButton { background-color:"+ColorSkyBlue+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorSkyBlue+"}");
            ui->CViolet->setStyleSheet("QPushButton { background-color:"+ColorViolet+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorViolet+"}");
            ui->CPink->setStyleSheet("QPushButton { background-color:"+ColorPink+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorPink+"}");
            QPixmap bodyYellow(":/Waterfall/Body/Body/yellow.png");
            ui->Part_Body->setPixmap(bodyYellow);
            ui->Part_Body->setVisible(true);
        } break;

        case 4:  //Black
        {
            ui->CWhite->setStyleSheet("QPushButton { background-color:"+ColorWhite+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorWhite+"}");
            ui->CGreen->setStyleSheet("QPushButton { background-color:"+ColorLightGreen+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorLightGreen+"}");
            ui->CRed->setStyleSheet("QPushButton { background-color:"+ColorRed+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorRed+"}");
            ui->CYellow->setStyleSheet("QPushButton { background-color:"+ColorYellow+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorYellow+"}");
            ui->CBlack->setStyleSheet("QPushButton { background-color:"+ColorBlack+"; border: 2px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorBlack+"}");
            ui->CSkyBlue->setStyleSheet("QPushButton { background-color:"+ColorSkyBlue+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorSkyBlue+"}");
            ui->CViolet->setStyleSheet("QPushButton { background-color:"+ColorViolet+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorViolet+"}");
            ui->CPink->setStyleSheet("QPushButton { background-color:"+ColorPink+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorPink+"}");
            //Body Color change
            QPixmap bodyBlack(":/Waterfall/Body/Body/black.png");
            ui->Part_Body->setPixmap(bodyBlack);
            ui->Part_Body->setVisible(true);
        } break;

        case 5: //Blue
        {
            ui->CWhite->setStyleSheet("QPushButton { background-color:"+ColorWhite+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorWhite+"}");
            ui->CGreen->setStyleSheet("QPushButton { background-color:"+ColorLightGreen+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorLightGreen+"}");
            ui->CRed->setStyleSheet("QPushButton { background-color:"+ColorRed+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorRed+"}");
            ui->CYellow->setStyleSheet("QPushButton { background-color:"+ColorYellow+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorYellow+"}");
            ui->CBlack->setStyleSheet("QPushButton { background-color:"+ColorBlack+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorBlack+"}");
            ui->CSkyBlue->setStyleSheet("QPushButton { background-color:"+ColorSkyBlue+"; border: 2px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorSkyBlue+"}");
            ui->CViolet->setStyleSheet("QPushButton { background-color:"+ColorViolet+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorViolet+"}");
            ui->CPink->setStyleSheet("QPushButton { background-color:"+ColorPink+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorPink+"}");
            QPixmap bodyBlue(":/Waterfall/Body/Body/skyblue.png");
            ui->Part_Body->setPixmap(bodyBlue);
            ui->Part_Body->setVisible(true);
        } break;

        case 6: //Violet
        {
            ui->CWhite->setStyleSheet("QPushButton { background-color:"+ColorWhite+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorWhite+"}");
            ui->CGreen->setStyleSheet("QPushButton { background-color:"+ColorLightGreen+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorLightGreen+"}");
            ui->CRed->setStyleSheet("QPushButton { background-color:"+ColorRed+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorRed+"}");
            ui->CYellow->setStyleSheet("QPushButton { background-color:"+ColorYellow+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorYellow+"}");
            ui->CBlack->setStyleSheet("QPushButton { background-color:"+ColorBlack+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorBlack+"}");
            ui->CSkyBlue->setStyleSheet("QPushButton { background-color:"+ColorSkyBlue+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorSkyBlue+"}");
            ui->CViolet->setStyleSheet("QPushButton { background-color:"+ColorViolet+"; border: 2px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorViolet+"}");
            ui->CPink->setStyleSheet("QPushButton { background-color:"+ColorPink+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorPink+"}");
            QPixmap bodyViolet(":/Waterfall/Body/Body/violet.png");
            ui->Part_Body->setPixmap(bodyViolet);
            ui->Part_Body->setVisible(true);
        } break;

        case 7: //Pink
        {
            ui->CWhite->setStyleSheet("QPushButton { background-color:"+ColorWhite+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorWhite+"}");
            ui->CGreen->setStyleSheet("QPushButton { background-color:"+ColorLightGreen+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorLightGreen+"}");
            ui->CRed->setStyleSheet("QPushButton { background-color:"+ColorRed+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorRed+"}");
            ui->CYellow->setStyleSheet("QPushButton { background-color:"+ColorYellow+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorYellow+"}");
            ui->CBlack->setStyleSheet("QPushButton { background-color:"+ColorBlack+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorBlack+"}");
            ui->CSkyBlue->setStyleSheet("QPushButton { background-color:"+ColorSkyBlue+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorSkyBlue+"}");
            ui->CViolet->setStyleSheet("QPushButton { background-color:"+ColorViolet+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorViolet+"}");
            ui->CPink->setStyleSheet("QPushButton { background-color:"+ColorPink+"; border: 2px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorPink+"}");
            QPixmap bodyPink(":/Waterfall/Body/Body/pink.png");
            ui->Part_Body->setPixmap(bodyPink);
            ui->Part_Body->setVisible(true);
        } break;
      }
    }

    else if(PartState == 2){
        if(isItLeftCap == true){
          switch(LeftCapColorState){
          case 0:
          {
            ui->CWhite->setStyleSheet("QPushButton { background-color:"+ColorWhite+"; border: 2px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorWhite+"}");
            ui->CGreen->setStyleSheet("QPushButton { background-color:"+ColorLightGreen+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorLightGreen+"}");
            ui->CRed->setStyleSheet("QPushButton { background-color:"+ColorRed+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorRed+"}");
            ui->CYellow->setStyleSheet("QPushButton { background-color:"+ColorYellow+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorYellow+"}");
            ui->CBlack->setStyleSheet("QPushButton { background-color:"+ColorBlack+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorBlack+"}");
            ui->CSkyBlue->setStyleSheet("QPushButton { background-color:"+ColorSkyBlue+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorSkyBlue+"}");
            ui->CViolet->setStyleSheet("QPushButton { background-color:"+ColorViolet+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorViolet+"}");
            ui->CPink->setStyleSheet("QPushButton { background-color:"+ColorPink+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorPink+"}");
            ui->CDarkBlue->setStyleSheet("QPushButton { background-color:"+ColorDarkBlue+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorDarkBlue+"}");
            ui->COrange->setStyleSheet("QPushButton { background-color:"+ColorOrange+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorOrange+"}");
            ///
            ui->part_leftCap->setVisible(false);
           }break;
          case 1:
          {
            ui->CWhite->setStyleSheet("QPushButton { background-color:"+ColorWhite+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorWhite+"}");
            ui->CGreen->setStyleSheet("QPushButton { background-color:"+ColorLightGreen+"; border: 2px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorLightGreen+"}");
            ui->CRed->setStyleSheet("QPushButton { background-color:"+ColorRed+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorRed+"}");
            ui->CYellow->setStyleSheet("QPushButton { background-color:"+ColorYellow+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorYellow+"}");
            ui->CBlack->setStyleSheet("QPushButton { background-color:"+ColorBlack+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorBlack+"}");
            ui->CSkyBlue->setStyleSheet("QPushButton { background-color:"+ColorSkyBlue+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorSkyBlue+"}");
            ui->CViolet->setStyleSheet("QPushButton { background-color:"+ColorViolet+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorViolet+"}");
            ui->CPink->setStyleSheet("QPushButton { background-color:"+ColorPink+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorPink+"}");
            ui->CDarkBlue->setStyleSheet("QPushButton { background-color:"+ColorDarkBlue+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorDarkBlue+"}");
            ui->COrange->setStyleSheet("QPushButton { background-color:"+ColorOrange+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorOrange+"}");
            ///
            QPixmap leftCapGreen(":/Waterfall/Capy/Left/Capy/Left/lightgreen.png");
            ui->part_leftCap->setPixmap(leftCapGreen);
            ui->part_leftCap->setVisible(true);
           }break;
          case 2:
          {
            ui->CWhite->setStyleSheet("QPushButton { background-color:"+ColorWhite+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorWhite+"}");
            ui->CGreen->setStyleSheet("QPushButton { background-color:"+ColorLightGreen+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorLightGreen+"}");
            ui->CRed->setStyleSheet("QPushButton { background-color:"+ColorRed+"; border: 2px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorRed+"}");
            ui->CYellow->setStyleSheet("QPushButton { background-color:"+ColorYellow+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorYellow+"}");
            ui->CBlack->setStyleSheet("QPushButton { background-color:"+ColorBlack+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorBlack+"}");
            ui->CSkyBlue->setStyleSheet("QPushButton { background-color:"+ColorSkyBlue+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorSkyBlue+"}");
            ui->CViolet->setStyleSheet("QPushButton { background-color:"+ColorViolet+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorViolet+"}");
            ui->CPink->setStyleSheet("QPushButton { background-color:"+ColorPink+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorPink+"}");
            ui->CDarkBlue->setStyleSheet("QPushButton { background-color:"+ColorDarkBlue+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorDarkBlue+"}");
            ui->COrange->setStyleSheet("QPushButton { background-color:"+ColorOrange+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorOrange+"}");
            ///
            QPixmap leftCapRed(":/Waterfall/Capy/Left/Capy/Left/red.png");
            ui->part_leftCap->setPixmap(leftCapRed);
            ui->part_leftCap->setVisible(true);
           }break;
          case 3:
          {
            ui->CWhite->setStyleSheet("QPushButton { background-color:"+ColorWhite+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorWhite+"}");
            ui->CGreen->setStyleSheet("QPushButton { background-color:"+ColorLightGreen+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorLightGreen+"}");
            ui->CRed->setStyleSheet("QPushButton { background-color:"+ColorRed+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorRed+"}");
            ui->CYellow->setStyleSheet("QPushButton { background-color:"+ColorYellow+"; border: 2px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorYellow+"}");
            ui->CBlack->setStyleSheet("QPushButton { background-color:"+ColorBlack+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorBlack+"}");
            ui->CSkyBlue->setStyleSheet("QPushButton { background-color:"+ColorSkyBlue+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorSkyBlue+"}");
            ui->CViolet->setStyleSheet("QPushButton { background-color:"+ColorViolet+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorViolet+"}");
            ui->CPink->setStyleSheet("QPushButton { background-color:"+ColorPink+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorPink+"}");
            ui->CDarkBlue->setStyleSheet("QPushButton { background-color:"+ColorDarkBlue+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorDarkBlue+"}");
            ui->COrange->setStyleSheet("QPushButton { background-color:"+ColorOrange+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorOrange+"}");
            ///
            QPixmap leftCapYellow(":/Waterfall/Capy/Left/Capy/Left/yellow.png");
            ui->part_leftCap->setPixmap(leftCapYellow);
            ui->part_leftCap->setVisible(true);
           }break;
          case 4:
          {
            ui->CWhite->setStyleSheet("QPushButton { background-color:"+ColorWhite+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorWhite+"}");
            ui->CGreen->setStyleSheet("QPushButton { background-color:"+ColorLightGreen+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorLightGreen+"}");
            ui->CRed->setStyleSheet("QPushButton { background-color:"+ColorRed+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorRed+"}");
            ui->CYellow->setStyleSheet("QPushButton { background-color:"+ColorYellow+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorYellow+"}");
            ui->CBlack->setStyleSheet("QPushButton { background-color:"+ColorBlack+"; border: 2px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorBlack+"}");
            ui->CSkyBlue->setStyleSheet("QPushButton { background-color:"+ColorSkyBlue+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorSkyBlue+"}");
            ui->CViolet->setStyleSheet("QPushButton { background-color:"+ColorViolet+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorViolet+"}");
            ui->CPink->setStyleSheet("QPushButton { background-color:"+ColorPink+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorPink+"}");
            ui->CDarkBlue->setStyleSheet("QPushButton { background-color:"+ColorDarkBlue+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorDarkBlue+"}");
            ui->COrange->setStyleSheet("QPushButton { background-color:"+ColorOrange+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorOrange+"}");
            ///
            QPixmap leftCapBlack(":/Waterfall/Capy/Left/Capy/Left/black.png");
            ui->part_leftCap->setPixmap(leftCapBlack);
            ui->part_leftCap->setVisible(true);
           }break;
          case 5:
          {
            ui->CWhite->setStyleSheet("QPushButton { background-color:"+ColorWhite+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorWhite+"}");
            ui->CGreen->setStyleSheet("QPushButton { background-color:"+ColorLightGreen+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorLightGreen+"}");
            ui->CRed->setStyleSheet("QPushButton { background-color:"+ColorRed+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorRed+"}");
            ui->CYellow->setStyleSheet("QPushButton { background-color:"+ColorYellow+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorYellow+"}");
            ui->CBlack->setStyleSheet("QPushButton { background-color:"+ColorBlack+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorBlack+"}");
            ui->CSkyBlue->setStyleSheet("QPushButton { background-color:"+ColorSkyBlue+"; border: 2px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorSkyBlue+"}");
            ui->CViolet->setStyleSheet("QPushButton { background-color:"+ColorViolet+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorViolet+"}");
            ui->CPink->setStyleSheet("QPushButton { background-color:"+ColorPink+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorPink+"}");
            ui->CDarkBlue->setStyleSheet("QPushButton { background-color:"+ColorDarkBlue+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorDarkBlue+"}");
            ui->COrange->setStyleSheet("QPushButton { background-color:"+ColorOrange+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorOrange+"}");
            ///
            QPixmap leftCapSkyBlue(":/Waterfall/Capy/Left/Capy/Left/skyblue.png");
            ui->part_leftCap->setPixmap(leftCapSkyBlue);
            ui->part_leftCap->setVisible(true);
           }break;
          case 6:
          {
            ui->CWhite->setStyleSheet("QPushButton { background-color:"+ColorWhite+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorWhite+"}");
            ui->CGreen->setStyleSheet("QPushButton { background-color:"+ColorLightGreen+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorLightGreen+"}");
            ui->CRed->setStyleSheet("QPushButton { background-color:"+ColorRed+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorRed+"}");
            ui->CYellow->setStyleSheet("QPushButton { background-color:"+ColorYellow+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorYellow+"}");
            ui->CBlack->setStyleSheet("QPushButton { background-color:"+ColorBlack+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorBlack+"}");
            ui->CSkyBlue->setStyleSheet("QPushButton { background-color:"+ColorSkyBlue+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorSkyBlue+"}");
            ui->CViolet->setStyleSheet("QPushButton { background-color:"+ColorViolet+"; border: 2px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorViolet+"}");
            ui->CPink->setStyleSheet("QPushButton { background-color:"+ColorPink+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorPink+"}");
            ui->CDarkBlue->setStyleSheet("QPushButton { background-color:"+ColorDarkBlue+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorDarkBlue+"}");
            ui->COrange->setStyleSheet("QPushButton { background-color:"+ColorOrange+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorOrange+"}");
            ///
            QPixmap leftCapViolet(":/Waterfall/Capy/Left/Capy/Left/violet.png");
            ui->part_leftCap->setPixmap(leftCapViolet);
            ui->part_leftCap->setVisible(true);
           }break;
          case 7:
          {
            ui->CWhite->setStyleSheet("QPushButton { background-color:"+ColorWhite+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorWhite+"}");
            ui->CGreen->setStyleSheet("QPushButton { background-color:"+ColorLightGreen+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorLightGreen+"}");
            ui->CRed->setStyleSheet("QPushButton { background-color:"+ColorRed+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorRed+"}");
            ui->CYellow->setStyleSheet("QPushButton { background-color:"+ColorYellow+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorYellow+"}");
            ui->CBlack->setStyleSheet("QPushButton { background-color:"+ColorBlack+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorBlack+"}");
            ui->CSkyBlue->setStyleSheet("QPushButton { background-color:"+ColorSkyBlue+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorSkyBlue+"}");
            ui->CViolet->setStyleSheet("QPushButton { background-color:"+ColorViolet+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorViolet+"}");
            ui->CPink->setStyleSheet("QPushButton { background-color:"+ColorPink+"; border: 2px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorPink+"}");
            ui->CDarkBlue->setStyleSheet("QPushButton { background-color:"+ColorDarkBlue+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorDarkBlue+"}");
            ui->COrange->setStyleSheet("QPushButton { background-color:"+ColorOrange+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorOrange+"}");
            ///
            QPixmap leftCapPink(":/Waterfall/Capy/Left/Capy/Left/pink.png");
            ui->part_leftCap->setPixmap(leftCapPink);
            ui->part_leftCap->setVisible(true);
           }break;
          case 8:
          {
            ui->CWhite->setStyleSheet("QPushButton { background-color:"+ColorWhite+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorWhite+"}");
            ui->CGreen->setStyleSheet("QPushButton { background-color:"+ColorLightGreen+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorLightGreen+"}");
            ui->CRed->setStyleSheet("QPushButton { background-color:"+ColorRed+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorRed+"}");
            ui->CYellow->setStyleSheet("QPushButton { background-color:"+ColorYellow+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorYellow+"}");
            ui->CBlack->setStyleSheet("QPushButton { background-color:"+ColorBlack+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorBlack+"}");
            ui->CSkyBlue->setStyleSheet("QPushButton { background-color:"+ColorSkyBlue+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorSkyBlue+"}");
            ui->CViolet->setStyleSheet("QPushButton { background-color:"+ColorViolet+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorViolet+"}");
            ui->CPink->setStyleSheet("QPushButton { background-color:"+ColorPink+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorPink+"}");
            ui->CDarkBlue->setStyleSheet("QPushButton { background-color:"+ColorDarkBlue+"; border: 2px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorDarkBlue+"}");
            ui->COrange->setStyleSheet("QPushButton { background-color:"+ColorOrange+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorOrange+"}");
            ///
            QPixmap leftCapDarkBlue(":/Waterfall/Capy/Left/Capy/Left/darkblue.png");
            ui->part_leftCap->setPixmap(leftCapDarkBlue);
            ui->part_leftCap->setVisible(true);
           }break;
          case 9:
          {
            ui->CWhite->setStyleSheet("QPushButton { background-color:"+ColorWhite+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorWhite+"}");
            ui->CGreen->setStyleSheet("QPushButton { background-color:"+ColorLightGreen+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorLightGreen+"}");
            ui->CRed->setStyleSheet("QPushButton { background-color:"+ColorRed+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorRed+"}");
            ui->CYellow->setStyleSheet("QPushButton { background-color:"+ColorYellow+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorYellow+"}");
            ui->CBlack->setStyleSheet("QPushButton { background-color:"+ColorBlack+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorBlack+"}");
            ui->CSkyBlue->setStyleSheet("QPushButton { background-color:"+ColorSkyBlue+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorSkyBlue+"}");
            ui->CViolet->setStyleSheet("QPushButton { background-color:"+ColorViolet+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorViolet+"}");
            ui->CPink->setStyleSheet("QPushButton { background-color:"+ColorPink+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorPink+"}");
            ui->CDarkBlue->setStyleSheet("QPushButton { background-color:"+ColorDarkBlue+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorDarkBlue+"}");
            ui->COrange->setStyleSheet("QPushButton { background-color:"+ColorOrange+"; border: 2px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorOrange+"}");
            ///
            QPixmap leftCapOrange(":/Waterfall/Capy/Left/Capy/Left/orange.png");
            ui->part_leftCap->setPixmap(leftCapOrange);
            ui->part_leftCap->setVisible(true);
           }break;
          }
        }

        else if(isItLeftCap == false){
            switch(RightCapColorState){
            case 0:
            {
              ui->CWhite_2->setStyleSheet("QPushButton { background-color:"+ColorWhite+"; border: 2px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorWhite+"}");
              ui->CGreen_2->setStyleSheet("QPushButton { background-color:"+ColorLightGreen+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorLightGreen+"}");
              ui->CRed_2->setStyleSheet("QPushButton { background-color:"+ColorRed+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorRed+"}");
              ui->CYellow_2->setStyleSheet("QPushButton { background-color:"+ColorYellow+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorYellow+"}");
              ui->CBlack_2->setStyleSheet("QPushButton { background-color:"+ColorBlack+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorBlack+"}");
              ui->CSkyBlue_2->setStyleSheet("QPushButton { background-color:"+ColorSkyBlue+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorSkyBlue+"}");
              ui->CViolet_2->setStyleSheet("QPushButton { background-color:"+ColorViolet+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorViolet+"}");
              ui->CPink_2->setStyleSheet("QPushButton { background-color:"+ColorPink+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorPink+"}");
              ui->CDarkBlue_2->setStyleSheet("QPushButton { background-color:"+ColorDarkBlue+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorDarkBlue+"}");
              ui->COrange_2->setStyleSheet("QPushButton { background-color:"+ColorOrange+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorOrange+"}");
              ///
              ui->part_rightCap->setVisible(false);
             }break;
            case 1:
            {
              ui->CWhite_2->setStyleSheet("QPushButton { background-color:"+ColorWhite+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorWhite+"}");
              ui->CGreen_2->setStyleSheet("QPushButton { background-color:"+ColorLightGreen+"; border: 2px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorLightGreen+"}");
              ui->CRed_2->setStyleSheet("QPushButton { background-color:"+ColorRed+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorRed+"}");
              ui->CYellow_2->setStyleSheet("QPushButton { background-color:"+ColorYellow+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorYellow+"}");
              ui->CBlack_2->setStyleSheet("QPushButton { background-color:"+ColorBlack+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorBlack+"}");
              ui->CSkyBlue_2->setStyleSheet("QPushButton { background-color:"+ColorSkyBlue+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorSkyBlue+"}");
              ui->CViolet_2->setStyleSheet("QPushButton { background-color:"+ColorViolet+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorViolet+"}");
              ui->CPink_2->setStyleSheet("QPushButton { background-color:"+ColorPink+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorPink+"}");
              ui->CDarkBlue_2->setStyleSheet("QPushButton { background-color:"+ColorDarkBlue+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorDarkBlue+"}");
              ui->COrange_2->setStyleSheet("QPushButton { background-color:"+ColorOrange+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorOrange+"}");
              ///
              QPixmap rightCapGreen(":/Waterfall/Capy/Right/Capy/Right/lightgreen.png");
              ui->part_rightCap->setPixmap(rightCapGreen);
              ui->part_rightCap->setVisible(true);
             }break;
            case 2:
            {
              ui->CWhite_2->setStyleSheet("QPushButton { background-color:"+ColorWhite+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorWhite+"}");
              ui->CGreen_2->setStyleSheet("QPushButton { background-color:"+ColorLightGreen+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorLightGreen+"}");
              ui->CRed_2->setStyleSheet("QPushButton { background-color:"+ColorRed+"; border: 2px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorRed+"}");
              ui->CYellow_2->setStyleSheet("QPushButton { background-color:"+ColorYellow+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorYellow+"}");
              ui->CBlack_2->setStyleSheet("QPushButton { background-color:"+ColorBlack+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorBlack+"}");
              ui->CSkyBlue_2->setStyleSheet("QPushButton { background-color:"+ColorSkyBlue+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorSkyBlue+"}");
              ui->CViolet_2->setStyleSheet("QPushButton { background-color:"+ColorViolet+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorViolet+"}");
              ui->CPink_2->setStyleSheet("QPushButton { background-color:"+ColorPink+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorPink+"}");
              ui->CDarkBlue_2->setStyleSheet("QPushButton { background-color:"+ColorDarkBlue+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorDarkBlue+"}");
              ui->COrange_2->setStyleSheet("QPushButton { background-color:"+ColorOrange+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorOrange+"}");
              ///
              QPixmap rightCapRed(":/Waterfall/Capy/Right/Capy/Right/red.png");
              ui->part_rightCap->setPixmap(rightCapRed);
              ui->part_rightCap->setVisible(true);
             }break;
            case 3:
            {
              ui->CWhite_2->setStyleSheet("QPushButton { background-color:"+ColorWhite+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorWhite+"}");
              ui->CGreen_2->setStyleSheet("QPushButton { background-color:"+ColorLightGreen+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorLightGreen+"}");
              ui->CRed_2->setStyleSheet("QPushButton { background-color:"+ColorRed+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorRed+"}");
              ui->CYellow_2->setStyleSheet("QPushButton { background-color:"+ColorYellow+"; border: 2px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorYellow+"}");
              ui->CBlack_2->setStyleSheet("QPushButton { background-color:"+ColorBlack+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorBlack+"}");
              ui->CSkyBlue_2->setStyleSheet("QPushButton { background-color:"+ColorSkyBlue+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorSkyBlue+"}");
              ui->CViolet_2->setStyleSheet("QPushButton { background-color:"+ColorViolet+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorViolet+"}");
              ui->CPink_2->setStyleSheet("QPushButton { background-color:"+ColorPink+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorPink+"}");
              ui->CDarkBlue_2->setStyleSheet("QPushButton { background-color:"+ColorDarkBlue+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorDarkBlue+"}");
              ui->COrange_2->setStyleSheet("QPushButton { background-color:"+ColorOrange+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorOrange+"}");
              ///
              QPixmap rightCapYellow(":/Waterfall/Capy/Right/Capy/Right/yellow.png");
              ui->part_rightCap->setPixmap(rightCapYellow);
              ui->part_rightCap->setVisible(true);
             }break;
            case 4:
            {
              ui->CWhite_2->setStyleSheet("QPushButton { background-color:"+ColorWhite+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorWhite+"}");
              ui->CGreen_2->setStyleSheet("QPushButton { background-color:"+ColorLightGreen+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorLightGreen+"}");
              ui->CRed_2->setStyleSheet("QPushButton { background-color:"+ColorRed+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorRed+"}");
              ui->CYellow_2->setStyleSheet("QPushButton { background-color:"+ColorYellow+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorYellow+"}");
              ui->CBlack_2->setStyleSheet("QPushButton { background-color:"+ColorBlack+"; border: 2px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorBlack+"}");
              ui->CSkyBlue_2->setStyleSheet("QPushButton { background-color:"+ColorSkyBlue+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorSkyBlue+"}");
              ui->CViolet_2->setStyleSheet("QPushButton { background-color:"+ColorViolet+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorViolet+"}");
              ui->CPink_2->setStyleSheet("QPushButton { background-color:"+ColorPink+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorPink+"}");
              ui->CDarkBlue_2->setStyleSheet("QPushButton { background-color:"+ColorDarkBlue+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorDarkBlue+"}");
              ui->COrange_2->setStyleSheet("QPushButton { background-color:"+ColorOrange+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorOrange+"}");
              ///
              QPixmap rightCapBlack(":/Waterfall/Capy/Right/Capy/Right/black.png");
              ui->part_rightCap->setPixmap(rightCapBlack);
              ui->part_rightCap->setVisible(true);
             }break;
            case 5:
            {
              ui->CWhite_2->setStyleSheet("QPushButton { background-color:"+ColorWhite+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorWhite+"}");
              ui->CGreen_2->setStyleSheet("QPushButton { background-color:"+ColorLightGreen+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorLightGreen+"}");
              ui->CRed_2->setStyleSheet("QPushButton { background-color:"+ColorRed+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorRed+"}");
              ui->CYellow_2->setStyleSheet("QPushButton { background-color:"+ColorYellow+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorYellow+"}");
              ui->CBlack_2->setStyleSheet("QPushButton { background-color:"+ColorBlack+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorBlack+"}");
              ui->CSkyBlue_2->setStyleSheet("QPushButton { background-color:"+ColorSkyBlue+"; border: 2px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorSkyBlue+"}");
              ui->CViolet_2->setStyleSheet("QPushButton { background-color:"+ColorViolet+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorViolet+"}");
              ui->CPink_2->setStyleSheet("QPushButton { background-color:"+ColorPink+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorPink+"}");
              ui->CDarkBlue_2->setStyleSheet("QPushButton { background-color:"+ColorDarkBlue+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorDarkBlue+"}");
              ui->COrange_2->setStyleSheet("QPushButton { background-color:"+ColorOrange+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorOrange+"}");
              ///
              QPixmap rightCapSkyBlue(":/Waterfall/Capy/Right/Capy/Right/skyblue.png");
              ui->part_rightCap->setPixmap(rightCapSkyBlue);
              ui->part_rightCap->setVisible(true);
             }break;
            case 6:
            {
              ui->CWhite_2->setStyleSheet("QPushButton { background-color:"+ColorWhite+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorWhite+"}");
              ui->CGreen_2->setStyleSheet("QPushButton { background-color:"+ColorLightGreen+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorLightGreen+"}");
              ui->CRed_2->setStyleSheet("QPushButton { background-color:"+ColorRed+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorRed+"}");
              ui->CYellow_2->setStyleSheet("QPushButton { background-color:"+ColorYellow+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorYellow+"}");
              ui->CBlack_2->setStyleSheet("QPushButton { background-color:"+ColorBlack+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorBlack+"}");
              ui->CSkyBlue_2->setStyleSheet("QPushButton { background-color:"+ColorSkyBlue+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorSkyBlue+"}");
              ui->CViolet_2->setStyleSheet("QPushButton { background-color:"+ColorViolet+"; border: 2px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorViolet+"}");
              ui->CPink_2->setStyleSheet("QPushButton { background-color:"+ColorPink+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorPink+"}");
              ui->CDarkBlue_2->setStyleSheet("QPushButton { background-color:"+ColorDarkBlue+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorDarkBlue+"}");
              ui->COrange_2->setStyleSheet("QPushButton { background-color:"+ColorOrange+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorOrange+"}");
              ///
              QPixmap rightCapViolet(":/Waterfall/Capy/Right/Capy/Right/violet.png");
              ui->part_rightCap->setPixmap(rightCapViolet);
              ui->part_rightCap->setVisible(true);
             }break;
            case 7:
            {
              ui->CWhite_2->setStyleSheet("QPushButton { background-color:"+ColorWhite+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorWhite+"}");
              ui->CGreen_2->setStyleSheet("QPushButton { background-color:"+ColorLightGreen+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorLightGreen+"}");
              ui->CRed_2->setStyleSheet("QPushButton { background-color:"+ColorRed+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorRed+"}");
              ui->CYellow_2->setStyleSheet("QPushButton { background-color:"+ColorYellow+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorYellow+"}");
              ui->CBlack_2->setStyleSheet("QPushButton { background-color:"+ColorBlack+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorBlack+"}");
              ui->CSkyBlue_2->setStyleSheet("QPushButton { background-color:"+ColorSkyBlue+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorSkyBlue+"}");
              ui->CViolet_2->setStyleSheet("QPushButton { background-color:"+ColorViolet+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorViolet+"}");
              ui->CPink_2->setStyleSheet("QPushButton { background-color:"+ColorPink+"; border: 2px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorPink+"}");
              ui->CDarkBlue_2->setStyleSheet("QPushButton { background-color:"+ColorDarkBlue+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorDarkBlue+"}");
              ui->COrange_2->setStyleSheet("QPushButton { background-color:"+ColorOrange+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorOrange+"}");
              ///
              QPixmap rightCapPink(":/Waterfall/Capy/Right/Capy/Right/pink.png");
              ui->part_rightCap->setPixmap(rightCapPink);
              ui->part_rightCap->setVisible(true);
             }break;
            case 8:
            {
              ui->CWhite_2->setStyleSheet("QPushButton { background-color:"+ColorWhite+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorWhite+"}");
              ui->CGreen_2->setStyleSheet("QPushButton { background-color:"+ColorLightGreen+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorLightGreen+"}");
              ui->CRed_2->setStyleSheet("QPushButton { background-color:"+ColorRed+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorRed+"}");
              ui->CYellow_2->setStyleSheet("QPushButton { background-color:"+ColorYellow+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorYellow+"}");
              ui->CBlack_2->setStyleSheet("QPushButton { background-color:"+ColorBlack+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorBlack+"}");
              ui->CSkyBlue_2->setStyleSheet("QPushButton { background-color:"+ColorSkyBlue+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorSkyBlue+"}");
              ui->CViolet_2->setStyleSheet("QPushButton { background-color:"+ColorViolet+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorViolet+"}");
              ui->CPink_2->setStyleSheet("QPushButton { background-color:"+ColorPink+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorPink+"}");
              ui->CDarkBlue_2->setStyleSheet("QPushButton { background-color:"+ColorDarkBlue+"; border: 2px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorDarkBlue+"}");
              ui->COrange_2->setStyleSheet("QPushButton { background-color:"+ColorOrange+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorOrange+"}");
              ///
              QPixmap rightCapDarkBlue(":/Waterfall/Capy/Right/Capy/Right/darkblue.png");
              ui->part_rightCap->setPixmap(rightCapDarkBlue);
              ui->part_rightCap->setVisible(true);
             }break;
            case 9:
            {
              ui->CWhite_2->setStyleSheet("QPushButton { background-color:"+ColorWhite+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorWhite+"}");
              ui->CGreen_2->setStyleSheet("QPushButton { background-color:"+ColorLightGreen+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorLightGreen+"}");
              ui->CRed_2->setStyleSheet("QPushButton { background-color:"+ColorRed+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorRed+"}");
              ui->CYellow_2->setStyleSheet("QPushButton { background-color:"+ColorYellow+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorYellow+"}");
              ui->CBlack_2->setStyleSheet("QPushButton { background-color:"+ColorBlack+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorBlack+"}");
              ui->CSkyBlue_2->setStyleSheet("QPushButton { background-color:"+ColorSkyBlue+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorSkyBlue+"}");
              ui->CViolet_2->setStyleSheet("QPushButton { background-color:"+ColorViolet+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorViolet+"}");
              ui->CPink_2->setStyleSheet("QPushButton { background-color:"+ColorPink+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorPink+"}");
              ui->CDarkBlue_2->setStyleSheet("QPushButton { background-color:"+ColorDarkBlue+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorDarkBlue+"}");
              ui->COrange_2->setStyleSheet("QPushButton { background-color:"+ColorOrange+"; border: 2px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorOrange+"}");
              ///
              QPixmap rightCapOrange(":/Waterfall/Capy/Right/Capy/Right/orange.png");
              ui->part_rightCap->setPixmap(rightCapOrange);
              ui->part_rightCap->setVisible(true);
             }break;
            }
        }
    }

    else if(PartState == 3){
        if(isItLeftGrip == true){
            switch(LeftGripColorState)
            {
            case 0:
            {
                ui->CWhite->setStyleSheet("QPushButton { background-color:"+ColorWhite+"; border: 2px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorWhite+"}");
                ui->CBlack->setStyleSheet("QPushButton { background-color:"+ColorBlack+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorBlack+"}");
                ui->CTransparent->setStyleSheet("QPushButton { background-color:"+ColorTransparent+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+ColorTransparent+"}");
                ///
                QPixmap leftGripWhite(":/Waterfall/Gripy/Left/Gripy/Left/white.png");
                ui->part_leftGrip->setPixmap(leftGripWhite);
                ui->part_leftGrip->setVisible(true);
            }break;
            case 1:
            {
                ui->CWhite->setStyleSheet("QPushButton { background-color:"+ColorWhite+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorWhite+"}");
                ui->CBlack->setStyleSheet("QPushButton { background-color:"+ColorBlack+"; border: 2px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorBlack+"}");
                ui->CTransparent->setStyleSheet("QPushButton { background-color:"+ColorTransparent+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+ColorTransparent+"}");
                ///
                QPixmap leftGripBlack(":/Waterfall/Gripy/Left/Gripy/Left/black.png");
                ui->part_leftGrip->setPixmap(leftGripBlack);
                ui->part_leftGrip->setVisible(true);

            }break;
            case 2:
            {
                ui->CWhite->setStyleSheet("QPushButton { background-color:"+ColorWhite+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorWhite+"}");
                ui->CBlack->setStyleSheet("QPushButton { background-color:"+ColorBlack+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorBlack+"}");
                ui->CTransparent->setStyleSheet("QPushButton { background-color:"+ColorTransparent+"; border: 2px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+ColorTransparent+"}");
                ///
                ui->part_leftGrip->setVisible(false);

            }break;

            }
        }
        else if(isItLeftGrip == false){
            switch(RightGripColorState)
            {
            case 0:
            {
                ui->CWhite_2->setStyleSheet("QPushButton { background-color:"+ColorWhite+"; border: 2px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorWhite+"}");
                ui->CBlack_2->setStyleSheet("QPushButton { background-color:"+ColorBlack+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorBlack+"}");
                ui->CTransparent_2->setStyleSheet("QPushButton { background-color:"+ColorTransparent+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+ColorTransparent+"}");
                ///
                QPixmap rightGripWhite(":/Waterfall/Gripy/Right/Gripy/Right/white.png");
                ui->part_rightGrip->setPixmap(rightGripWhite);
                ui->part_rightGrip->setVisible(true);
            }break;
            case 1:
            {
                ui->CWhite_2->setStyleSheet("QPushButton { background-color:"+ColorWhite+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorWhite+"}");
                ui->CBlack_2->setStyleSheet("QPushButton { background-color:"+ColorBlack+"; border: 2px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorBlack+"}");
                ui->CTransparent_2->setStyleSheet("QPushButton { background-color:"+ColorTransparent+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+ColorTransparent+"}");
                ///
                QPixmap rightGripBlack(":/Waterfall/Gripy/Right/Gripy/Right/black.png");
                ui->part_rightGrip->setPixmap(rightGripBlack);
                ui->part_rightGrip->setVisible(true);

            }break;
            case 2:
            {
                ui->CWhite_2->setStyleSheet("QPushButton { background-color:"+ColorWhite+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorWhite+"}");
                ui->CBlack_2->setStyleSheet("QPushButton { background-color:"+ColorBlack+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorBlack+"}");
                ui->CTransparent_2->setStyleSheet("QPushButton { background-color:"+ColorTransparent+"; border: 2px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+ColorTransparent+"}");
                ///
                ui->part_rightGrip->setVisible(false);

            }break;


            }

        }
    }
    else{
        PartState = 1;
    }


}

void MainWindow::initiateComboBoxes()
{
  for(int i=0; i<13; i++){
      ui->comboBox->addItem(currentColors[i]);
      ui->comboBox_2->addItem(currentColors[i]);
      ui->comboBox_3->addItem(currentColors[i]);
      ui->comboBox_4->addItem(currentColors[i]);
  }

}
void MainWindow::updateComboBoxes()
{
    if(isItPolish == true){
        for(int i=0; i<13; i++){
            currentColors[i] = colorsEnglish[i];
        }
    }else{
        for(int i=0; i<13; i++){
            currentColors[i] = colors[i];
        }
    }
    ui->comboBox->clear();
    ui->comboBox_2->clear();
    ui->comboBox_3->clear();
    ui->comboBox_4->clear();
    initiateComboBoxes();
}

void MainWindow::on_pushButton_3_released()
{
}
void MainWindow::initiateLeftSailors(){
    LeftSailorTable[0] = ui->comboBox->currentIndex();
    LeftSailorTable[1] = ui->comboBox_2->currentIndex();
    LeftSailorTable[2] = ui->comboBox_3->currentIndex();
    LeftSailorTable[3] = ui->comboBox_4->currentIndex();
    for(int i=0; i<4; i++){
        switch(LeftSailorTable[i])
        {
        case 0:
        {
            if(i == 0){
                ui->sailorLeftOne->setVisible(false);
            }
            if(i == 1){
                ui->sailorLeftTwo->setVisible(false);
            }
            if(i == 2){
                ui->sailorLeftThree->setVisible(false);
            }
            if(i == 3){
                ui->sailorLeftFour->setVisible(false);
            }
        }break;
        case 1:
        {
            QPixmap Left0(":/Waterfall/Gripy/Anyballe/Gripy/Anyballs/Left/black.png");
            if(i == 0){
                ui->sailorLeftOne->setPixmap(Left0);
                ui->sailorLeftOne->setVisible(true);
            }
            if(i == 1){
                ui->sailorLeftTwo->setPixmap(Left0);
                ui->sailorLeftTwo->setVisible(true);
            }
            if(i == 2){
                ui->sailorLeftThree->setPixmap(Left0);
                ui->sailorLeftThree->setVisible(true);

            }
            if(i == 3){
                ui->sailorLeftFour->setPixmap(Left0);
                ui->sailorLeftFour->setVisible(true);
            }

        }break;
        case 2:
        {
            QPixmap Left1(":/Waterfall/Gripy/Anyballe/Gripy/Anyballs/Left/white.png");
            if(i == 0){
                ui->sailorLeftOne->setPixmap(Left1);
                ui->sailorLeftOne->setVisible(true);
            }
            if(i == 1){
                ui->sailorLeftTwo->setPixmap(Left1);
                 ui->sailorLeftTwo->setVisible(true);
            }
            if(i == 2){
                ui->sailorLeftThree->setPixmap(Left1);
                ui->sailorLeftThree->setVisible(true);
            }
            if(i == 3){
                ui->sailorLeftFour->setPixmap(Left1);
                ui->sailorLeftFour->setVisible(true);
            }
        }break;

        case 3:
        {
            QPixmap Left2(":/Waterfall/Gripy/Anyballe/Gripy/Anyballs/Left/grey.png");
            if(i == 0){
                ui->sailorLeftOne->setPixmap(Left2);
                ui->sailorLeftOne->setVisible(true);
            }
            if(i == 1){
                ui->sailorLeftTwo->setPixmap(Left2);
                 ui->sailorLeftTwo->setVisible(true);
            }
            if(i == 2){
                ui->sailorLeftThree->setPixmap(Left2);
                ui->sailorLeftThree->setVisible(true);
            }
            if(i == 3){
                ui->sailorLeftFour->setPixmap(Left2);
                ui->sailorLeftFour->setVisible(true);
            }
        }break;
        case 4:
        {
            QPixmap Left3(":/Waterfall/Gripy/Anyballe/Gripy/Anyballs/Left/red.png");
            if(i == 0){
                ui->sailorLeftOne->setPixmap(Left3);
                ui->sailorLeftOne->setVisible(true);
            }
            if(i == 1){
                ui->sailorLeftTwo->setPixmap(Left3);
                 ui->sailorLeftTwo->setVisible(true);
            }
            if(i == 2){
                ui->sailorLeftThree->setPixmap(Left3);
                ui->sailorLeftThree->setVisible(true);
            }
            if(i == 3){
                ui->sailorLeftFour->setPixmap(Left3);
                ui->sailorLeftFour->setVisible(true);
            }
        }break;
        case 5:
        {
            QPixmap Left4(":/Waterfall/Gripy/Anyballe/Gripy/Anyballs/Left/orange.png");
            if(i == 0){
                ui->sailorLeftOne->setPixmap(Left4);
                ui->sailorLeftOne->setVisible(true);
            }
            if(i == 1){
                ui->sailorLeftTwo->setPixmap(Left4);
                 ui->sailorLeftTwo->setVisible(true);
            }
            if(i == 2){
                ui->sailorLeftThree->setPixmap(Left4);
                ui->sailorLeftThree->setVisible(true);
            }
            if(i == 3){
                ui->sailorLeftFour->setPixmap(Left4);
                ui->sailorLeftFour->setVisible(true);
            }
        }break;
        case 6:
        {
            QPixmap Left5(":/Waterfall/Gripy/Anyballe/Gripy/Anyballs/Left/yellow.png");
            if(i == 0){
                ui->sailorLeftOne->setPixmap(Left5);
                ui->sailorLeftOne->setVisible(true);
            }
            if(i == 1){
                ui->sailorLeftTwo->setPixmap(Left5);
                ui->sailorLeftTwo->setVisible(true);
            }
            if(i == 2){
                ui->sailorLeftThree->setPixmap(Left5);
                ui->sailorLeftThree->setVisible(true);
            }
            if(i == 3){
                ui->sailorLeftFour->setPixmap(Left5);
                ui->sailorLeftFour->setVisible(true);
            }
        }break;
        case 7:
        {
            QPixmap Left6(":/Waterfall/Gripy/Anyballe/Gripy/Anyballs/Left/lightgreen.png");
            if(i == 0){
                ui->sailorLeftOne->setPixmap(Left6);
                ui->sailorLeftOne->setVisible(true);
            }
            if(i == 1){
                ui->sailorLeftTwo->setPixmap(Left6);
                ui->sailorLeftTwo->setVisible(true);
            }
            if(i == 2){
                ui->sailorLeftThree->setPixmap(Left6);
                ui->sailorLeftThree->setVisible(true);
            }
            if(i == 3){
                ui->sailorLeftFour->setPixmap(Left6);
                ui->sailorLeftFour->setVisible(true);
            }
        }break;
        case 8:
        {
            QPixmap Left7(":/Waterfall/Gripy/Anyballe/Gripy/Anyballs/Left/darkgreen.png");
            if(i == 0){
                ui->sailorLeftOne->setPixmap(Left7);
                ui->sailorLeftOne->setVisible(true);
            }
            if(i == 1){
                ui->sailorLeftTwo->setPixmap(Left7);
                ui->sailorLeftTwo->setVisible(true);
            }
            if(i == 2){
                ui->sailorLeftThree->setPixmap(Left7);
                ui->sailorLeftThree->setVisible(true);}
            if(i == 3){
                ui->sailorLeftFour->setPixmap(Left7);
                ui->sailorLeftFour->setVisible(true);
            }
        }break;
        case 9:
        {
        QPixmap Left8(":/Waterfall/Gripy/Anyballe/Gripy/Anyballs/Left/skyblue.png");
            if(i == 0){
                ui->sailorLeftOne->setPixmap(Left8);
                ui->sailorLeftOne->setVisible(true);
            }
            if(i == 1){
                ui->sailorLeftTwo->setPixmap(Left8);
                ui->sailorLeftTwo->setVisible(true);
            }
            if(i == 2){
                ui->sailorLeftThree->setPixmap(Left8);
                ui->sailorLeftThree->setVisible(true);
            }
            if(i == 3){
                ui->sailorLeftFour->setPixmap(Left8);
                ui->sailorLeftFour->setVisible(true);
            }
        }break;
        case 10:
        {
            QPixmap Left9(":/Waterfall/Gripy/Anyballe/Gripy/Anyballs/Left/darkblue.png");
            if(i == 0){
                ui->sailorLeftOne->setPixmap(Left9);
                ui->sailorLeftOne->setVisible(true);
            }
            if(i == 1){
                ui->sailorLeftTwo->setPixmap(Left9);
                ui->sailorLeftTwo->setVisible(true);
            }
            if(i == 2){
                ui->sailorLeftThree->setPixmap(Left9);
                ui->sailorLeftThree->setVisible(true);
            }
            if(i == 3){
                ui->sailorLeftFour->setPixmap(Left9);
                ui->sailorLeftFour->setVisible(true);
            }
        }break;
        case 11:
        {
            QPixmap Left10(":/Waterfall/Gripy/Anyballe/Gripy/Anyballs/Left/violet.png");
            if(i == 0){
                ui->sailorLeftOne->setPixmap(Left10);
                ui->sailorLeftOne->setVisible(true);
            }
            if(i == 1){
                ui->sailorLeftTwo->setPixmap(Left10);
                ui->sailorLeftTwo->setVisible(true);
            }
            if(i == 2){
                ui->sailorLeftThree->setPixmap(Left10);
                ui->sailorLeftThree->setVisible(true);
            }
            if(i == 3){
                ui->sailorLeftFour->setPixmap(Left10);
                ui->sailorLeftFour->setVisible(true);
            }
        }break;
        case 12:
        {
            QPixmap Left11(":/Waterfall/Gripy/Anyballe/Gripy/Anyballs/Left/pink.png");
            if(i == 0){
                ui->sailorLeftOne->setPixmap(Left11);
                ui->sailorLeftOne->setVisible(true);
            }
            if(i == 1){
                ui->sailorLeftTwo->setPixmap(Left11);
                ui->sailorLeftTwo->setVisible(true);
            }
            if(i == 2){
                ui->sailorLeftThree->setPixmap(Left11);
                ui->sailorLeftThree->setVisible(true);
            }
            if(i == 3){
                ui->sailorLeftFour->setPixmap(Left11);
                ui->sailorLeftFour->setVisible(true);
            }
        }break;
        }
    }
}

void MainWindow::initiateRightSailors(){
    RightSailorTable[0] = ui->comboBox_4->currentIndex();
    RightSailorTable[1] = ui->comboBox_3->currentIndex();
    RightSailorTable[2] = ui->comboBox_2->currentIndex();
    RightSailorTable[3] = ui->comboBox->currentIndex();
    for(int i=0; i<4; i++){
        switch(RightSailorTable[i])
        {
        case 0:
        {
            if(i == 0){
                ui->sailorRightOne->setVisible(false);
            }
            if(i == 1){
                ui->sailorRightTwo->setVisible(false);
            }
            if(i == 2){
                ui->sailorRightThree->setVisible(false);
            }
            if(i == 3){
                ui->sailorRightFour->setVisible(false);
            }
        }break;
        case 1:
        {
            QPixmap Left0(":/Waterfall/Gripy/Anyballs/Gripy/Anyballs/Right/black.png");
            if(i == 0){
                ui->sailorRightOne->setPixmap(Left0);
                ui->sailorRightOne->setVisible(true);
            }
            if(i == 1){
                ui->sailorRightTwo->setPixmap(Left0);
                ui->sailorRightTwo->setVisible(true);
            }
            if(i == 2){
                ui->sailorRightThree->setPixmap(Left0);
                ui->sailorRightThree->setVisible(true);

            }
            if(i == 3){
                ui->sailorRightFour->setPixmap(Left0);
                ui->sailorRightFour->setVisible(true);
            }

        }break;
        case 2:
        {
            QPixmap Left1(":/Waterfall/Gripy/Anyballs/Gripy/Anyballs/Right/white.png");
            if(i == 0){
                ui->sailorRightOne->setPixmap(Left1);
                ui->sailorRightOne->setVisible(true);
            }
            if(i == 1){
                ui->sailorRightTwo->setPixmap(Left1);
                 ui->sailorRightTwo->setVisible(true);
            }
            if(i == 2){
                ui->sailorRightThree->setPixmap(Left1);
                ui->sailorRightThree->setVisible(true);
            }
            if(i == 3){
                ui->sailorRightFour->setPixmap(Left1);
                ui->sailorRightFour->setVisible(true);
            }
        }break;

        case 3:
        {
            QPixmap Left2(":/Waterfall/Gripy/Anyballs/Gripy/Anyballs/Right/grey.png");
            if(i == 0){
                ui->sailorRightOne->setPixmap(Left2);
                ui->sailorRightOne->setVisible(true);
            }
            if(i == 1){
                ui->sailorRightTwo->setPixmap(Left2);
                 ui->sailorRightTwo->setVisible(true);
            }
            if(i == 2){
                ui->sailorRightThree->setPixmap(Left2);
                ui->sailorRightThree->setVisible(true);
            }
            if(i == 3){
                ui->sailorRightFour->setPixmap(Left2);
                ui->sailorRightFour->setVisible(true);
            }
        }break;
        case 4:
        {
            QPixmap Left3(":/Waterfall/Gripy/Anyballs/Gripy/Anyballs/Right/red.png");
            if(i == 0){
                ui->sailorRightOne->setPixmap(Left3);
                ui->sailorRightOne->setVisible(true);
            }
            if(i == 1){
                ui->sailorRightTwo->setPixmap(Left3);
                ui->sailorRightTwo->setVisible(true);
            }
            if(i == 2){
                ui->sailorRightThree->setPixmap(Left3);
                ui->sailorRightThree->setVisible(true);
            }
            if(i == 3){
                ui->sailorRightFour->setPixmap(Left3);
                ui->sailorRightFour->setVisible(true);
            }
        }break;
        case 5:
        {
            QPixmap Left4(":/Waterfall/Gripy/Anyballs/Gripy/Anyballs/Right/orange.png");
            if(i == 0){
                ui->sailorRightOne->setPixmap(Left4);
                ui->sailorRightOne->setVisible(true);
            }
            if(i == 1){
                ui->sailorRightTwo->setPixmap(Left4);
                 ui->sailorRightTwo->setVisible(true);
            }
            if(i == 2){
                ui->sailorRightThree->setPixmap(Left4);
                ui->sailorRightThree->setVisible(true);
            }
            if(i == 3){
                ui->sailorRightFour->setPixmap(Left4);
                ui->sailorRightFour->setVisible(true);
            }
        }break;
        case 6:
        {
            QPixmap Left5(":/Waterfall/Gripy/Anyballs/Gripy/Anyballs/Right/yellow.png");
            if(i == 0){
                ui->sailorRightOne->setPixmap(Left5);
                ui->sailorRightOne->setVisible(true);
            }
            if(i == 1){
                ui->sailorRightTwo->setPixmap(Left5);
                ui->sailorRightTwo->setVisible(true);
            }
            if(i == 2){
                ui->sailorRightThree->setPixmap(Left5);
                ui->sailorRightThree->setVisible(true);
            }
            if(i == 3){
                ui->sailorRightFour->setPixmap(Left5);
                ui->sailorRightFour->setVisible(true);
            }
        }break;
        case 7:
        {
            QPixmap Left6(":/Waterfall/Gripy/Anyballs/Gripy/Anyballs/Right/lightgreen.png");
            if(i == 0){
                ui->sailorRightOne->setPixmap(Left6);
                ui->sailorRightOne->setVisible(true);
            }
            if(i == 1){
                ui->sailorRightTwo->setPixmap(Left6);
                ui->sailorRightTwo->setVisible(true);
            }
            if(i == 2){
                ui->sailorRightThree->setPixmap(Left6);
                ui->sailorRightThree->setVisible(true);
            }
            if(i == 3){
                ui->sailorRightFour->setPixmap(Left6);
                ui->sailorRightFour->setVisible(true);
            }
        }break;
        case 8:
        {
            QPixmap Left7(":/Waterfall/Gripy/Anyballs/Gripy/Anyballs/Right/darkgreen.png");
            if(i == 0){
                ui->sailorRightOne->setPixmap(Left7);
                ui->sailorRightOne->setVisible(true);
            }
            if(i == 1){
                ui->sailorRightTwo->setPixmap(Left7);
                ui->sailorRightTwo->setVisible(true);
            }
            if(i == 2){
                ui->sailorRightThree->setPixmap(Left7);
                ui->sailorRightThree->setVisible(true);}
            if(i == 3){
                ui->sailorRightFour->setPixmap(Left7);
                ui->sailorRightFour->setVisible(true);
            }
        }break;
        case 9:
        {
        QPixmap Left8(":/Waterfall/Gripy/Anyballs/Gripy/Anyballs/Right/skyblue.png");
            if(i == 0){
                ui->sailorRightOne->setPixmap(Left8);
                ui->sailorRightOne->setVisible(true);
            }
            if(i == 1){
                ui->sailorRightTwo->setPixmap(Left8);
                ui->sailorRightTwo->setVisible(true);
            }
            if(i == 2){
                ui->sailorRightThree->setPixmap(Left8);
                ui->sailorRightThree->setVisible(true);
            }
            if(i == 3){
                ui->sailorRightFour->setPixmap(Left8);
                ui->sailorRightFour->setVisible(true);
            }
        }break;
        case 10:
        {
            QPixmap Left9(":/Waterfall/Gripy/Anyballs/Gripy/Anyballs/Right/darkblue.png");
            if(i == 0){
                ui->sailorRightOne->setPixmap(Left9);
                ui->sailorRightOne->setVisible(true);
            }
            if(i == 1){
                ui->sailorRightTwo->setPixmap(Left9);
                ui->sailorRightTwo->setVisible(true);
            }
            if(i == 2){
                ui->sailorRightThree->setPixmap(Left9);
                ui->sailorRightThree->setVisible(true);
            }
            if(i == 3){
                ui->sailorRightFour->setPixmap(Left9);
                ui->sailorRightFour->setVisible(true);
            }
        }break;
        case 11:
        {
            QPixmap Left10(":/Waterfall/Gripy/Anyballs/Gripy/Anyballs/Right/violet.png");
            if(i == 0){
                ui->sailorRightOne->setPixmap(Left10);
                ui->sailorRightOne->setVisible(true);
            }
            if(i == 1){
                ui->sailorRightTwo->setPixmap(Left10);
                ui->sailorRightTwo->setVisible(true);
            }
            if(i == 2){
                ui->sailorRightThree->setPixmap(Left10);
                ui->sailorRightThree->setVisible(true);
            }
            if(i == 3){
                ui->sailorRightFour->setPixmap(Left10);
                ui->sailorRightFour->setVisible(true);
            }
        }break;
        case 12:
        {
            QPixmap Left11(":/Waterfall/Gripy/Anyballs/Gripy/Anyballs/Right/pink.png");
            if(i == 0){
                ui->sailorRightOne->setPixmap(Left11);
                ui->sailorRightOne->setVisible(true);
            }
            if(i == 1){
                ui->sailorRightTwo->setPixmap(Left11);
                ui->sailorRightTwo->setVisible(true);
            }
            if(i == 2){
                ui->sailorRightThree->setPixmap(Left11);
                ui->sailorRightThree->setVisible(true);
            }
            if(i == 3){
                ui->sailorRightFour->setPixmap(Left11);
                ui->sailorRightFour->setVisible(true);
            }
        }break;
        }
    }
}
void MainWindow::on_exit_released()
{
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this,"Jestes Pewny/a?","Czy napewno chcesz wyjść z aplikacji?",QMessageBox::Yes|QMessageBox::No);
    if(reply == QMessageBox::Yes){
      QApplication::quit();
    }
    if(reply == QMessageBox::No){
        //Continue
    }
}

void MainWindow::on_WaterfallSwitch_released()
{
 //
}

void MainWindow::on_CWhite_released()
{
    //Tu nastapi zapis do zmiennej, potem metoda aktualizujaca obrazek pena na podstawie zmiennej
    if(PartState == 1){
    BodyColorState = 0;
    }
    else if(PartState == 2){
    LeftCapColorState = 0;
    isItLeftCap = true;
    }
    else if(PartState == 3){
        LeftGripColorState = 0;
        isItLeftGrip = true;
    }
    onColorClicked();
}

void MainWindow::on_Body_released()
{
    PartState = 1;
    partEventUpdate();
}

void MainWindow::on_Capy_released()
{
    PartState = 2;
    partEventUpdate();
}

void MainWindow::on_Gripy_released()
{
    PartState = 3;
    partEventUpdate();
}

void MainWindow::on_CGreen_released()
{
    if(PartState == 1){
    BodyColorState = 1;
    }
    else if(PartState == 2){
    LeftCapColorState = 1;
    isItLeftCap = true;
    }
    onColorClicked();
}

void MainWindow::on_CRed_released()
{
    if(PartState == 1){
    BodyColorState = 2;
    }
    else if(PartState == 2){
    LeftCapColorState = 2;
    isItLeftCap = true;
    }
    onColorClicked();
}

void MainWindow::on_CYellow_released()
{
    if(PartState == 1){
    BodyColorState = 3;
    }
    else if(PartState == 2){
    LeftCapColorState = 3;
    isItLeftCap = true;
    }
    onColorClicked();
}

void MainWindow::on_CBlack_released()
{
    if(PartState == 1){
    BodyColorState = 4;
    }
    else if(PartState == 2){
    LeftCapColorState = 4;
    isItLeftCap = true;
    }
    else if(PartState == 3){
    LeftGripColorState = 1;
    isItLeftGrip = true;
    }
    onColorClicked();
}

void MainWindow::on_CSkyBlue_released()
{
    if(PartState == 1){
    BodyColorState = 5;
    }
    else if(PartState == 2){
    LeftCapColorState = 5;
    isItLeftCap = true;
    }
    onColorClicked();
}

void MainWindow::on_CViolet_released()
{
    if(PartState == 1){
    BodyColorState = 6;
    }
    else if(PartState == 2){
    LeftCapColorState = 6;
    isItLeftCap = true;
    }
    onColorClicked();
}


void MainWindow::on_CPink_released()
{
    if(PartState == 1){
    BodyColorState = 7;
    }
    else if(PartState == 2){
    LeftCapColorState = 7;
    isItLeftCap = true;
    }
    onColorClicked();
}

void MainWindow::on_CDarkBlue_released()
{
    if(PartState == 2){
    LeftCapColorState = 8;
    isItLeftCap = true;
    }
    onColorClicked();
}

void MainWindow::on_COrange_released()
{
    if(PartState == 2){
    LeftCapColorState = 9;
    isItLeftCap = true;
    }
    onColorClicked();
}

void MainWindow::on_CWhite_2_released()
{
    if(PartState == 2){
        RightCapColorState = 0;
        isItLeftCap = false;
    }
    else if(PartState == 3){
        RightGripColorState = 0;
        isItLeftGrip = false;
    }
    onColorClicked();
}

void MainWindow::on_CGreen_2_released()
{
    if(PartState == 2){
        RightCapColorState = 1;
        isItLeftCap = false;
    }
    onColorClicked();
}

void MainWindow::on_CRed_2_released()
{
    if(PartState == 2){
        RightCapColorState = 2;
        isItLeftCap = false;
    }
    onColorClicked();
}

void MainWindow::on_CYellow_2_released()
{
    if(PartState == 2){
        RightCapColorState = 3;
        isItLeftCap = false;
    }
    onColorClicked();
}

void MainWindow::on_CBlack_2_released()
{
    if(PartState == 2){
        RightCapColorState = 4;
        isItLeftCap = false;
    }
    if(PartState == 3){
        RightGripColorState = 1;
        isItLeftGrip = false;
    }
    onColorClicked();
}

void MainWindow::on_CSkyBlue_2_released()
{
    if(PartState == 2){
        RightCapColorState = 5;
        isItLeftCap = false;
    }
    onColorClicked();
}

void MainWindow::on_CViolet_2_released()
{
    if(PartState == 2){
        RightCapColorState = 6;
        isItLeftCap = false;
    }
    onColorClicked();
}

void MainWindow::on_CPink_2_released()
{
    if(PartState == 2){
        RightCapColorState = 7;
        isItLeftCap = false;
    }
    onColorClicked();
}

void MainWindow::on_CTransparent_2_released()
{
    if(PartState == 3){
        RightGripColorState = 2;
        isItLeftGrip = false;
    }
    onColorClicked();
}


void MainWindow::on_CDarkBlue_2_released()
{
    if(PartState == 2){
        RightCapColorState = 8;
        isItLeftCap = false;
    }
    onColorClicked();
}

void MainWindow::on_COrange_2_released()
{
    if(PartState == 2){
        RightCapColorState = 9;
        isItLeftCap = false;
    }
    onColorClicked();
}

void MainWindow::on_CTransparent_released()
{
    if(PartState == 3){
        LeftGripColorState = 2;
        isItLeftGrip = true;
    }
    onColorClicked();
}



void MainWindow::on_sailorSubmit_released()
{
    if(isItLeftSailor == true){
        initiateLeftSailors();
        saveLeftState();
    }
    else if(isItLeftSailor == false){
        initiateRightSailors();
        saveRightState();
    }

}

void MainWindow::on_LeftSide_released()
{
    isItLeftSailor = true;
    ui->LeftSide->setDisabled(true);
    ui->RightSide->setDisabled(false);
    if(isItPolish){
        ui->whatAreYouEditing_2->setText("Gripy z lewej strony");
    }else{
        ui->whatAreYouEditing_2->setText("Left side Grips");
    }
    setSavedStates();
}

void MainWindow::on_RightSide_released()
{
    isItLeftSailor = false;
    ui->LeftSide->setDisabled(false);
    ui->RightSide->setDisabled(true);
    if(isItPolish){
        ui->whatAreYouEditing_2->setText("Gripy z prawej strony");
    }else{
        ui->whatAreYouEditing_2->setText("Right side Grips");
    }
    setSavedStates();
}

void MainWindow::on_Switch_3_released()
{
    hide();
    menowawindow MenowaDialog;
    MenowaDialog.setModal(true);
    MenowaDialog.exec();
}

void MainWindow::on_save_2_released()
{
    if(isSailorMenuVisible == false){
        ui->GroupBoxSailors->setVisible(true);
        isSailorMenuVisible = true;
    }
    else{
        ui->GroupBoxSailors->setVisible(false);
         isSailorMenuVisible = false;
    }
}

void MainWindow::on_save_released()
{
    if(isItPolish){
    QMessageBox::information(this,"Ta opcja będzie dostępna wkrótce!","Ta opcja będzie dostępna wkrótce!");}
    else{
    QMessageBox::information(this,"Coming Soon!","Coming Soon!");
    }
}

void MainWindow::on_open_released()
{
    if(isItPolish){
    QMessageBox::information(this,"Ta opcja będzie dostępna wkrótce!","Ta opcja będzie dostępna wkrótce!");}
    else{
    QMessageBox::information(this,"Coming Soon!","Coming Soon!");
    }
}

void MainWindow::on_language_released()
{
    changeLanguage();
}

void MainWindow::on_save_5_released()
{
    if(isItPolish == true){
        QMessageBox::information(
        this,
        "Części do Waterfall mod"
        ,"<h2>Części do Waterfall Mod</h2><br><b style='text-align: center'>Waterfall Mod</b><ul><li>Super Pirat Body (x1)</li><li>Reynolds 094 Cap (x2)</li><li>Dr.Grip Grip (x2)</li><li>Uni-Ball Signo metal Tip (x2)</li><li>Dong-A Comssa Backplug (x1)</li><li>Anyball Profile Grip (x0-x4 (Zależy od ilości kolorów))</li></ul>"
        );
    }else{
        QMessageBox::information(
        this,
        "Części do Waterfall mod"
        ,"<h2>Parts to Waterfall Mod</h2><br><b style='text-align: center'>Waterfall Mod</b><ul><li>Super Pirat Body (x1)</li><li>Reynolds 094 Cap (x2)</li><li>Dr.Grip Grip (x2)</li><li>Uni-Ball Signo metal Tip (x2)</li><li>Dong-A Comssa Backplug (x1)</li><li>Anyball Profile Grip (x0-x4 (Depends of used colors))</li></ul>"
        );
    }
}

void MainWindow::on_save_6_released()
{
    /*Programisto! Jeżeli edytujesz ten program który jest pod licencją MIT, bardzo proszę, nie usuwaj poniższej linijki o prawdziwych autorach aplikacji, oraz tego komentarza, Dziękuję!*/
    /*Programmer! If You are editing this code, remember that this app is under MIT licence, that mean you shouldn't remove any information about real app author, and this comment either. Thank You!*/
    if(isItPolish == true){
    QMessageBox::information(this,"Autorzy","<h2>Penspinning - Make your mod</h2><br>Kod źródłowy oraz grafiki zostały stworzone przez:<br> <strong>Artur Koniec  <a href='http://ariteku.pl'>Ariteku.pl</a></strong><br><br>Ogromne podziękowania dla testerów aplikacji za ich wsparcie!<br><br><b>Zabraniam kopiowania i rozpowszechniania użytych w aplikacji grafik!</b>");
    }else{
    QMessageBox::information(this,"Authors","<h2>Penspinning - Make your mod</h2><br>Source code and graphic has been created by:<br> <strong>Artur Koniec  <a href='http://ariteku.pl'>Ariteku.pl</a></strong><br><br>Special Thanks for app tester for their support!<br><br><b>I do not allow to copy the graphics used in app!</b>");
    }}

void MainWindow::on_settins_released()
{
    QMessageBox::StandardButton reply;
    if(isItPolish == true){
    reply = QMessageBox::question(this,"Jestes Pewny/a?","Czy napewno chcesz zrestartować program?",QMessageBox::Yes|QMessageBox::No);
    }else{
    reply = QMessageBox::question(this,"Are You sure?","Do You really want to restart the application?",QMessageBox::Yes|QMessageBox::No);
    }    if(reply == QMessageBox::Yes){
        qApp->quit();
        QProcess::startDetached(qApp->arguments()[0], qApp->arguments());
    }
    if(reply == QMessageBox::No){
        //Continue
    }
}

void MainWindow::on_LeftSideCheckbox_released()
{
    isItLeftSailor = true;
    ui->LeftSide->setDisabled(true);
    ui->RightSide->setDisabled(false);
    if(isItPolish){
        ui->whatAreYouEditing_2->setText("Gripy z lewej strony");
    }else{
        ui->whatAreYouEditing_2->setText("Left side Grips");
    }
}


void MainWindow::on_RightSideCheckbox_released()
{
    isItLeftSailor = false;
    ui->LeftSide->setDisabled(false);
    ui->RightSide->setDisabled(true);
    if(isItPolish){
        ui->whatAreYouEditing_2->setText("Gripy z prawej strony");
    }else{
        ui->whatAreYouEditing_2->setText("Right side Grips");
    }
}

void MainWindow::on_toolButton_released()
{
    if(isCheckboxesON == false){
        ui->LeftSide->setVisible(false);
        ui->RightSide->setVisible(false);
        ui->LeftSideCheckbox->setVisible(true);
        ui->RightSideCheckbox->setVisible(true);
        isCheckboxesON = true;
    }
    else if(isCheckboxesON == true){
        ui->LeftSide->setVisible(true);
        ui->RightSide->setVisible(true);
        ui->LeftSideCheckbox->setVisible(false);
        ui->RightSideCheckbox->setVisible(false);
        isCheckboxesON = false;
    }
}

void MainWindow::on_save_4_released()
{
    /*Programisto! Jeżeli edytujesz mój program który jest pod licencją MIT, bardzo proszę, nie usuwaj poniższej linijki o prawdziwych autorach aplikacji, oraz tego komentarza, Dziękuję!*/
    /*Programmer! If You are editing this code, remember that this app is under MIT licence, that mean you shouldn't remove any information about real app author, and this comment either. Thank You!*/
    if(isItPolish == true){
    QMessageBox::about(this,"Kontakt z deweloperem","<h4>Znalazłeś błąd w aplikacji?</h4>Jeżeli znalazłeś jakiekolwiek błędy w aplikacji, bardzo proszę, zgłoś je do mnie na email:<br><b>aritekudev@gmail.com</b><br><h3>Poszukuje grafika do aplikacji!</h3>Jak widzisz, grafiki w aplikacji nie są zbyt dobre. Jeżeli jesteś grafikiem 2D, możesz przyczynić się do tworzenia tej aplikacji, proszę, skontaktuj się ze mną na adres:<br><strong>aritekudev@gmail.com</strong>");
    }else{
    QMessageBox::about(this,"Contact with developer","<h4>Is something wrong in app?</h4>If you found any kind of mistakes in application, please, report them to me at:<br><b>aritekudev@gmail.com</b><br><h3>I'm looking for a graphic designer for app!</h3>As you can see, these graphics of pens aren't really good. If You are 2D graphic designer, we can make this app together. Please contact with me at:<br><strong>aritekudev@gmail.com</strong>");
    }
}

void MainWindow::on_Switch_2_released()
{
    hide();
    busterwindow BusterWindow;
    BusterWindow.setModal(true);
    BusterWindow.exec();
}
void MainWindow::changeLanguage()
{
    if(isItPolish == true){
     ui->save->setText("Save composition");
     ui->open->setText("Open composition");
     ui->settins->setText("Restart composition");
     ui->language->setText("Polska Wersja");
     ui->exit->setText("Exit app");
     ui->Body->setText("Body");
     ui->Capy->setText("Caps");
     ui->Gripy->setText("Grips");
     ui->save_2->setText("Anyballs composition");
     ui->save_5->setText("Parts");
     ui->save_3->setText("Licence");
     ui->save_4->setText("Contact");
     ui->save_6->setText("Authors");
     ui->LeftSide->setText("Left Side");
     ui->RightSide->setText("Right Side");
     ui->LeftSideCheckbox->setText("Left Side");
     ui->RightSideCheckbox->setText("Right Side");
     ui->label_3->setText("First");
     ui->label_4->setText("Second");
     ui->label_5->setText("Third");
     ui->label_6->setText("Four");
     ui->sailorSubmit->setText("Submit");
     ui->whatAreYouEditing->setText("Editing:");
     ui->updateApp->setText("Check for updates");
     updateComboBoxes();
     if(PartState == 1){
         ui->LabelEdit->setText("Editing: BODY");
         ui->groupBox->setTitle("Body");
         ui->groupBox_2->setTitle("Right Body");
     }
     else if(PartState == 2){
         ui->LabelEdit->setText("Editing: CAPS");
         ui->groupBox->setTitle("Left Cap");
         ui->groupBox_2->setTitle("Right Cap");
     }
     else if(PartState == 3){
         ui->LabelEdit->setText("Use Anyballs<br>composition");
         ui->groupBox->setTitle("Left Grip");
         ui->groupBox_2->setTitle("Right Grip");
     }
     if(isItLeftSailor){
     ui->whatAreYouEditing_2->setText("Left side Grips");
     }else{
     ui->whatAreYouEditing_2->setText("Right side Grips");
     }
     isItPolish = false;
    }
    else if(isItPolish == false){
     ui->save->setText("Zapisz kompozycje");
     ui->open->setText("Otwórz kompozycje");
     ui->settins->setText("Restart kompozycji");
     ui->language->setText("English Version");
     ui->exit->setText("Wyjdź");
     ui->Body->setText("Body");
     ui->Capy->setText("Capy");
     ui->Gripy->setText("Gripy");
     ui->save_2->setText("Kompozycja Anyballi");
     ui->save_5->setText("Części");
     ui->save_3->setText("Licencje");
     ui->save_4->setText("Kontakt");
     ui->save_6->setText("Autorzy");
     ui->LeftSide->setText("Lewa Strona");
     ui->RightSide->setText("Prawa Strona");
     ui->LeftSideCheckbox->setText("Lewa Strona");
     ui->RightSideCheckbox->setText("Prawa Strona");
     ui->label_3->setText("Pierwszy");
     ui->label_4->setText("Drugi");
     ui->label_5->setText("Trzeci");
     ui->label_6->setText("Czwarty");
     ui->sailorSubmit->setText("Zatwierdź");
     ui->whatAreYouEditing->setText("Edytujsz:");
     ui->updateApp->setText("Sprawdź aktualizacje");
     updateComboBoxes();
     if(PartState == 1){
         ui->LabelEdit->setText("Edytujesz: BODY");
         ui->groupBox->setTitle("Body");
         ui->groupBox_2->setTitle("Body");
     }
     else if(PartState == 2){
         ui->LabelEdit->setText("Edytujesz: CAPS");
         ui->groupBox->setTitle("Lewe Cap");
         ui->groupBox_2->setTitle("Prawe Cap");
     }
     else if(PartState == 3){
         ui->LabelEdit->setText("Użyj kompozycji<br>Sailorów");
         ui->groupBox->setTitle("Lewy Grip");
         ui->groupBox_2->setTitle("Prawy Grip");
     }
     ui->whatAreYouEditing_2->setText("Gripy z lewej strony");
     isItPolish = true;
     }
 }

void MainWindow::on_save_3_released()
{
    if(isItPolish == true){
    QMessageBox::about(this,"Licencje","<ul><li>Aplikacja ta została napisana w języku C++ za pomocą środowiska Qt Creator.</li><li>Aplikacja używa licencji MIT.</li><li>Kod źródłowy na GitHubie znajduję się pod <a href='https://github.com/AritekuDev/PenspinningMakeYourMod'>tym</a> linkiem.</li></ul>");
    }else{
    QMessageBox::about(this,"Licence","<ul><li>This applciation has been written in C++ language using Qt Creator IDE.</li><li>Application use MIT licence.</li><li>Source code of app is available on github under <a href='https://github.com/AritekuDev/PenspinningMakeYourMod'>this</a> link.</li></ul>");
    }
}

void MainWindow::on_Switch_7_released()
{
    QDesktopServices::openUrl(QUrl(ariteku));
}

void MainWindow::on_updateApp_released()
{
    QString dirApp = qApp->applicationDirPath();
    QString dirFile = dirApp+"/maintenancetool.exe";
    QDesktopServices::openUrl(QUrl("file:///"+dirFile));
    QApplication::quit();
}
void MainWindow::saveLeftState(){
    LeftDownStates[0] = ui->comboBox->currentIndex();
    LeftDownStates[1] = ui->comboBox_2->currentIndex();
    LeftDownStates[2] = ui->comboBox_3->currentIndex();
    LeftDownStates[3] = ui->comboBox_4->currentIndex();
}
void MainWindow::saveRightState(){
    RightDownStates[0] = ui->comboBox->currentIndex();
    RightDownStates[1] = ui->comboBox_2->currentIndex();
    RightDownStates[2] = ui->comboBox_3->currentIndex();
    RightDownStates[3] = ui->comboBox_4->currentIndex();
}
void MainWindow::readLeftState(){
    ui->comboBox->setCurrentIndex(LeftDownStates[0]);
    ui->comboBox_2->setCurrentIndex(LeftDownStates[1]);
    ui->comboBox_3->setCurrentIndex(LeftDownStates[2]);
    ui->comboBox_4->setCurrentIndex(LeftDownStates[3]);
}
void MainWindow::readRightState(){
    ui->comboBox->setCurrentIndex(RightDownStates[0]);
    ui->comboBox_2->setCurrentIndex(RightDownStates[1]);
    ui->comboBox_3->setCurrentIndex(RightDownStates[2]);
    ui->comboBox_4->setCurrentIndex(RightDownStates[3]);
}
void MainWindow::setSavedStates(){
    if(isItLeftSailor == true){
        readLeftState();
    }
    else if(isItLeftSailor == false){
        readRightState();
    }
}
