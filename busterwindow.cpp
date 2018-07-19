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
#include "busterwindow.h"
#include "ui_busterwindow.h"

busterwindow::busterwindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::busterwindow)
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
    QPixmap WaterfallDefault(":/Buster/BusterCyl/full.png");
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
    ui->comboBox_3->setVisible(false);
    ui->comboBox_4->setVisible(false);
    ui->label_5->setVisible(false);
    ui->label_6->setVisible(false);
    ui->LeftSideCheckbox->setChecked(true);
    ///
    colors[0] = "<Domyślny>";
    colors[1] = "Czarny";
    colors[2] = "Biały";
    colors[3] = "Szary";
    colors[4] = "Czerwony";
    colors[5] = "Pomarańczowy";
    colors[6] = "Żółty";
    colors[7] = "Zielony";
    colors[8] = "Błękitny";
    colors[9] = "Niebieski";
    colors[10] = "Fioletowy";
    colors[11] = "Różowy";
    ///
    colorsEnglish[0] = "<Default>";
    colorsEnglish[1] = "Black";
    colorsEnglish[2] = "White";
    colorsEnglish[3] = "Grey";
    colorsEnglish[4] = "Red";
    colorsEnglish[5] = "Orange";
    colorsEnglish[6] = "Yellow";
    colorsEnglish[7] = "Green";
    colorsEnglish[8] = "Sky Blue";
    colorsEnglish[9] = "Dark Blue";
    colorsEnglish[10] = "Violet";
    colorsEnglish[11] = "Magenta";
    ///
    for(int i=0; i<13; i++){
        currentColors[i] = colors[i];
    }
    ///
    for(int i=0; i<5; i++){
        LeftDownStates[i] = 0;
        RightDownStates[i] = 0;
    }
    ///
    setUpTransparentButtons();
    setupColorButtons();
    setupColorButtons_2();
    partEventUpdate();
    initiateComboBoxes();
    setWindowFlags(Qt::Window);
    QApplication::desktop()->screenCount();
    QApplication::desktop()->screenNumber();
    QApplication::desktop()->screenGeometry(this);
}

void busterwindow::setUpTransparentButtons(){
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
busterwindow::~busterwindow()
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
void busterwindow::setupColorButtons(){
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

void busterwindow::setupColorButtons_2(){
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

void busterwindow::partEventUpdate(){
    switch(PartState)
    {
    case 1: //Body jest wybrane

    ui->CRed->setVisible(true); //#1
    ui->CYellow->setVisible(true); //#2
    ui->CGreen->setVisible(true); //#3
    ui->CPink->setVisible(true); //#4
    ui->CViolet->setVisible(true); //#5
    ui->CSkyBlue->setVisible(true); //#6
    ui->CWhite->setVisible(true); //#7
    ui->CBlack->setVisible(true); //#8
    ui->CTransparent->setVisible(false); //#9
    ui->CDarkBlue->setVisible(false); //#10
    ui->COrange->setVisible(false);

    ui->CRed_2->setVisible(true); //#1
    ui->CYellow_2->setVisible(true); //#2
    ui->CGreen_2->setVisible(true); //#3
    ui->CPink_2->setVisible(true); //#4
    ui->CViolet_2->setVisible(true); //#5
    ui->CSkyBlue_2->setVisible(true); //#6
    ui->CWhite_2->setVisible(true); //#7
    ui->CBlack_2->setVisible(true); //#8
    ui->CTransparent_2->setVisible(false); //#9
    ui->CDarkBlue_2->setVisible(false); //#10
    ui->COrange_2->setVisible(false);

    ui->groupBox_2->setVisible(false);
    if(isItPolish){
        ui->groupBox->setTitle("Body");
        ui->LabelEdit->setText("Edytujesz: BODY");
    }else{
        ui->groupBox->setTitle("Body");
        ui->LabelEdit->setText("Editing: BODY");
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
        ui->CYellow->setStyleSheet("QPushButton { background-color:"+ColorYellow+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorYellow+"}");
        ui->CBlack->setStyleSheet("QPushButton { background-color:"+ColorBlack+"; border: 2px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorBlack+"}");
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
    ui->CWhite->setVisible(true); //#7
    ui->CBlack->setVisible(true); //#8
    ui->CTransparent->setVisible(false);
    ui->CDarkBlue->setVisible(true);
    ui->COrange->setVisible(true);

    ui->CRed_2->setVisible(true); //#1
    ui->CYellow_2->setVisible(true); //#2
    ui->CGreen_2->setVisible(true); //#3
    ui->CPink_2->setVisible(true); //#4
    ui->CViolet_2->setVisible(true); //#5
    ui->CSkyBlue_2->setVisible(true); //#6
    ui->CWhite_2->setVisible(true); //#7
    ui->CBlack_2->setVisible(true); //#8
    ui->CTransparent_2->setVisible(false);
    ui->CDarkBlue_2->setVisible(true);
    ui->COrange_2->setVisible(true);

    ui->groupBox_2->setVisible(true);
    if(isItPolish){
    ui->groupBox->setTitle("Lewy Cap");
    ui->groupBox_2->setTitle("Prawy Cap");
    ui->LabelEdit->setText("Edytujesz: CAPY");
    }else{
        ui->groupBox->setTitle("Left Cap");
        ui->groupBox_2->setTitle("Right Cap");
        ui->LabelEdit->setText("Editing: CAPS");
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
    ui->CWhite->setVisible(false); //#7
    ui->CBlack->setVisible(false); //#8
    ui->CTransparent->setVisible(false);
    ui->CDarkBlue->setVisible(false);
    ui->COrange->setVisible(false);

    ui->CRed_2->setVisible(false); //#1
    ui->CYellow_2->setVisible(false); //#2
    ui->CGreen_2->setVisible(false); //#3
    ui->CPink_2->setVisible(false); //#4
    ui->CViolet_2->setVisible(false); //#5
    ui->CSkyBlue_2->setVisible(false); //#6
    ui->CWhite_2->setVisible(false); //#7
    ui->CBlack_2->setVisible(false); //#8
    ui->CTransparent_2->setVisible(false);
    ui->CDarkBlue_2->setVisible(false);
    ui->COrange_2->setVisible(false);

    ui->groupBox_2->setVisible(true);
    if(isItPolish){
    ui->groupBox->setTitle("Lewy Grip");
    ui->groupBox_2->setTitle("Prawy Grip");
    ui->LabelEdit->setText("Edytujesz: GRIPY");
    }else{
        ui->groupBox->setTitle("Left Grip");
        ui->groupBox_2->setTitle("Right Grip");
        ui->LabelEdit->setText("Editing: GRIPS");
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
void busterwindow::onColorClicked(){
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
            QPixmap bodyGreen(":/Buster/Body/BusterCyl/body/lightgreen.png");
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
            QPixmap bodyRed(":/Buster/Body/BusterCyl/body/red.png");
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
            QPixmap bodyYellow(":/Buster/Body/BusterCyl/body/yellow.png");
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
            QPixmap bodyBlack(":/Buster/Body/BusterCyl/body/black.png");
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
            QPixmap bodyBlue(":/Buster/Body/BusterCyl/body/skyblue.png");
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
            QPixmap bodyViolet(":/Buster/Body/BusterCyl/body/violet.png");
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
            QPixmap bodyPink(":/Buster/Body/BusterCyl/body/pink.png");
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
            QPixmap leftCapGreen(":/Buster/LeftCap/BusterCyl/capLeft/lightgreen.png");
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
            QPixmap leftCapRed(":/Buster/LeftCap/BusterCyl/capLeft/red.png");
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
            QPixmap leftCapYellow(":/Buster/LeftCap/BusterCyl/capLeft/yellow.png");
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
            QPixmap leftCapBlack(":/Buster/LeftCap/BusterCyl/capLeft/black.png");
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
            QPixmap leftCapSkyBlue(":/Buster/LeftCap/BusterCyl/capLeft/blue.png");
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
            QPixmap leftCapViolet(":/Buster/LeftCap/BusterCyl/capLeft/violet.png");
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
            QPixmap leftCapPink(":/Buster/LeftCap/BusterCyl/capLeft/pink.png");
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
            QPixmap leftCapDarkBlue(":/Buster/LeftCap/BusterCyl/capLeft/darkblue.png");
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
            QPixmap leftCapOrange(":/Buster/LeftCap/BusterCyl/capLeft/orange.png");
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
              QPixmap rightCapGreen(":/Buster/RightCap/BusterCyl/capRight/lightgreen.png");
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
              QPixmap rightCapRed(":/Buster/RightCap/BusterCyl/capRight/red.png");
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
              QPixmap rightCapYellow(":/Buster/RightCap/BusterCyl/capRight/yellow.png");
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
              QPixmap rightCapBlack(":/Buster/RightCap/BusterCyl/capRight/black.png");
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
              QPixmap rightCapSkyBlue(":/Buster/RightCap/BusterCyl/capRight/blue.png");
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
              QPixmap rightCapViolet(":/Buster/RightCap/BusterCyl/capRight/violet.png");
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
              QPixmap rightCapPink(":/Buster/RightCap/BusterCyl/capRight/pink.png");
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
              QPixmap rightCapDarkBlue(":/Buster/RightCap/BusterCyl/capRight/darkblue.png");
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
              QPixmap rightCapOrange(":/Buster/RightCap/BusterCyl/capRight/orange.png");
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

void busterwindow::initiateComboBoxes()
{
  for(int i=0; i<12; i++){
      ui->comboBox->addItem(currentColors[i]);
      ui->comboBox_2->addItem(currentColors[i]);
      ui->comboBox_3->addItem(currentColors[i]);
      ui->comboBox_4->addItem(currentColors[i]);
  }

}
void busterwindow::updateComboBoxes()
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

void busterwindow::initiateLeftSailors(){
    LeftSailorTable[0] = ui->comboBox->currentIndex();
    LeftSailorTable[1] = ui->comboBox_2->currentIndex();
    for(int i=0; i<2; i++){
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
        }break;
        case 1:
        {
            if(i == 0){
                ui->sailorLeftOne->setVisible(false);
            }
            if(i == 1){
                ui->sailorLeftTwo->setVisible(false);
            }

        }break;
        case 2:
        {
            QPixmap Left1(":/Buster/LeftSailor/S1/BusterCyl/SailorLeft/s1/white.png");
            QPixmap Left2(":/Buster/LeftSailor/S2/BusterCyl/SailorLeft/s2/white.png");
            if(i == 0){
                ui->sailorLeftOne->setPixmap(Left1);
                ui->sailorLeftOne->setVisible(true);
            }
            if(i == 1){
                ui->sailorLeftTwo->setPixmap(Left2);
                 ui->sailorLeftTwo->setVisible(true);
            }
        }break;

        case 3:
        {
            QPixmap Left2(":/Buster/LeftSailor/S1/BusterCyl/SailorLeft/s1/grey.png");
            QPixmap Left3(":/Buster/LeftSailor/S2/BusterCyl/SailorLeft/s2/grey.png");
            if(i == 0){
                ui->sailorLeftOne->setPixmap(Left2);
                ui->sailorLeftOne->setVisible(true);
            }
            if(i == 1){
                ui->sailorLeftTwo->setPixmap(Left3);
                 ui->sailorLeftTwo->setVisible(true);
            }
        }break;
        case 4:
        {
            QPixmap Left3(":/Buster/LeftSailor/S1/BusterCyl/SailorLeft/s1/red.png");
            QPixmap Left4(":/Buster/LeftSailor/S2/BusterCyl/SailorLeft/s2/red.png");
            if(i == 0){
                ui->sailorLeftOne->setPixmap(Left3);
                ui->sailorLeftOne->setVisible(true);
            }
            if(i == 1){
                ui->sailorLeftTwo->setPixmap(Left4);
                 ui->sailorLeftTwo->setVisible(true);
            }
        }break;
        case 5:
        {
            QPixmap Left4(":/Buster/LeftSailor/S1/BusterCyl/SailorLeft/s1/orange.png");
            QPixmap Left5(":/Buster/LeftSailor/S2/BusterCyl/SailorLeft/s2/orange.png");
            if(i == 0){
                ui->sailorLeftOne->setPixmap(Left4);
                ui->sailorLeftOne->setVisible(true);
            }
            if(i == 1){
                ui->sailorLeftTwo->setPixmap(Left5);
                 ui->sailorLeftTwo->setVisible(true);
            }
        }break;
        case 6:
        {
            QPixmap Left5(":/Buster/LeftSailor/S1/BusterCyl/SailorLeft/s1/yellow.png");
            QPixmap Left6(":/Buster/LeftSailor/S2/BusterCyl/SailorLeft/s2/yellow.png");
            if(i == 0){
                ui->sailorLeftOne->setPixmap(Left5);
                ui->sailorLeftOne->setVisible(true);
            }
            if(i == 1){
                ui->sailorLeftTwo->setPixmap(Left6);
                ui->sailorLeftTwo->setVisible(true);
            }
        }break;
        case 7:
        {
            QPixmap Left6(":/Buster/LeftSailor/S1/BusterCyl/SailorLeft/s1/green.png");
            QPixmap Left7(":/Buster/LeftSailor/S2/BusterCyl/SailorLeft/s2/green.png");
            if(i == 0){
                ui->sailorLeftOne->setPixmap(Left6);
                ui->sailorLeftOne->setVisible(true);
            }
            if(i == 1){
                ui->sailorLeftTwo->setPixmap(Left7);
                ui->sailorLeftTwo->setVisible(true);
            }
        }break;
        case 8:
        {
        QPixmap Left8(":/Buster/LeftSailor/S1/BusterCyl/SailorLeft/s1/blue.png");
        QPixmap Left9(":/Buster/LeftSailor/S2/BusterCyl/SailorLeft/s2/blue.png");
            if(i == 0){
                ui->sailorLeftOne->setPixmap(Left8);
                ui->sailorLeftOne->setVisible(true);
            }
            if(i == 1){
                ui->sailorLeftTwo->setPixmap(Left9);
                ui->sailorLeftTwo->setVisible(true);
            }
        }break;
        case 9:
        {
            QPixmap Left9(":/Buster/LeftSailor/S1/BusterCyl/SailorLeft/s1/darkblue.png");
            QPixmap Left10(":/Buster/LeftSailor/S2/BusterCyl/SailorLeft/s2/darkblue.png");
            if(i == 0){
                ui->sailorLeftOne->setPixmap(Left9);
                ui->sailorLeftOne->setVisible(true);
            }
            if(i == 1){
                ui->sailorLeftTwo->setPixmap(Left10);
                ui->sailorLeftTwo->setVisible(true);
            }
        }break;
        case 10:
        {
            QPixmap Left10(":/Buster/LeftSailor/S1/BusterCyl/SailorLeft/s1/violet.png");
            QPixmap Left11(":/Buster/LeftSailor/S2/BusterCyl/SailorLeft/s2/violet.png");
            if(i == 0){
                ui->sailorLeftOne->setPixmap(Left10);
                ui->sailorLeftOne->setVisible(true);
            }
            if(i == 1){
                ui->sailorLeftTwo->setPixmap(Left11);
                ui->sailorLeftTwo->setVisible(true);
            }
        }break;
        case 11:
        {
            QPixmap Left11(":/Buster/LeftSailor/S1/BusterCyl/SailorLeft/s1/pink.png");
            QPixmap Left12(":/Buster/LeftSailor/S2/BusterCyl/SailorLeft/s2/pink.png");
            if(i == 0){
                ui->sailorLeftOne->setPixmap(Left11);
                ui->sailorLeftOne->setVisible(true);
            }
            if(i == 1){
                ui->sailorLeftTwo->setPixmap(Left12);
                ui->sailorLeftTwo->setVisible(true);
            }
        }break;
        }
    }
}

void busterwindow::initiateRightSailors(){
    RightSailorTable[0] = ui->comboBox->currentIndex();
    RightSailorTable[1] = ui->comboBox_2->currentIndex();
    for(int i=0; i<2; i++){
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
        }break;
        case 1:
        {
            QPixmap Left0(":/Buster/RightSailor/S1/BusterCyl/SailorRight/S1/black.png");
            if(i == 0){
                ui->sailorRightOne->setPixmap(Left0);
                ui->sailorRightOne->setVisible(true);
            }
            if(i == 1){
                ui->sailorRightTwo->setPixmap(Left0);
                ui->sailorRightTwo->setVisible(true);
            }

        }break;
        case 2:
        {
            QPixmap Left1(":/Buster/RightSailor/S1/BusterCyl/SailorRight/S1/white.png");
            QPixmap Left2(":/Buster/RightSailor/S2/BusterCyl/SailorRight/S2/white.png");
            if(i == 0){
                ui->sailorRightOne->setPixmap(Left1);
                ui->sailorRightOne->setVisible(true);
            }
            if(i == 1){
                ui->sailorRightTwo->setPixmap(Left2);
                 ui->sailorRightTwo->setVisible(true);
            }
        }break;

        case 3:
        {
            QPixmap Left1(":/Buster/RightSailor/S1/BusterCyl/SailorRight/S1/grey.png");
            QPixmap Left2(":/Buster/RightSailor/S2/BusterCyl/SailorRight/S2/grey.png");
            if(i == 0){
                ui->sailorRightOne->setPixmap(Left1);
                ui->sailorRightOne->setVisible(true);
            }
            if(i == 1){
                ui->sailorRightTwo->setPixmap(Left2);
                 ui->sailorRightTwo->setVisible(true);
            }
        }break;
        case 4:
        {
            QPixmap Left3(":/Buster/RightSailor/S1/BusterCyl/SailorRight/S1/red.png");
            QPixmap Second(":/Buster/RightSailor/S2/BusterCyl/SailorRight/S2/red.png");
            if(i == 0){
                ui->sailorRightOne->setPixmap(Left3);
                ui->sailorRightOne->setVisible(true);
            }
            if(i == 1){
                ui->sailorRightTwo->setPixmap(Second);
                ui->sailorRightTwo->setVisible(true);
            }
        }break;
        case 5:
        {
            QPixmap Left4(":/Buster/RightSailor/S1/BusterCyl/SailorRight/S1/orange.png");
            QPixmap Second(":/Buster/RightSailor/S2/BusterCyl/SailorRight/S2/orange.png");
            if(i == 0){
                ui->sailorRightOne->setPixmap(Left4);
                ui->sailorRightOne->setVisible(true);
            }
            if(i == 1){
                ui->sailorRightTwo->setPixmap(Second);
                 ui->sailorRightTwo->setVisible(true);
            }
        }break;
        case 6:
        {
            QPixmap Left5(":/Buster/RightSailor/S1/BusterCyl/SailorRight/S1/yellow.png");
            QPixmap Second(":/Buster/RightSailor/S2/BusterCyl/SailorRight/S2/yellow.png");
            if(i == 0){
                ui->sailorRightOne->setPixmap(Left5);
                ui->sailorRightOne->setVisible(true);
            }
            if(i == 1){
                ui->sailorRightTwo->setPixmap(Second);
                ui->sailorRightTwo->setVisible(true);
            }
        }break;
        case 7:
        {
            QPixmap Left6(":/Buster/RightSailor/S1/BusterCyl/SailorRight/S1/green.png");
            QPixmap Second(":/Buster/RightSailor/S2/BusterCyl/SailorRight/S2/green.png");
            if(i == 0){
                ui->sailorRightOne->setPixmap(Left6);
                ui->sailorRightOne->setVisible(true);
            }
            if(i == 1){
                ui->sailorRightTwo->setPixmap(Second);
                ui->sailorRightTwo->setVisible(true);
            }
        }break;
        case 8:
        {
        QPixmap Left8(":/Buster/RightSailor/S1/BusterCyl/SailorRight/S1/blue.png");
        QPixmap Second(":/Buster/RightSailor/S2/BusterCyl/SailorRight/S2/blue.png");
            if(i == 0){
                ui->sailorRightOne->setPixmap(Left8);
                ui->sailorRightOne->setVisible(true);
            }
            if(i == 1){
                ui->sailorRightTwo->setPixmap(Second);
                ui->sailorRightTwo->setVisible(true);
            }
        }break;
        case 9:
        {
            QPixmap Left9(":/Buster/RightSailor/S1/BusterCyl/SailorRight/S1/darkblue.png");
            QPixmap Second(":/Buster/RightSailor/S2/BusterCyl/SailorRight/S2/darkblue.png");
            if(i == 0){
                ui->sailorRightOne->setPixmap(Left9);
                ui->sailorRightOne->setVisible(true);
            }
            if(i == 1){
                ui->sailorRightTwo->setPixmap(Second);
                ui->sailorRightTwo->setVisible(true);
            }
        }break;
        case 10:
        {
            QPixmap Left10(":/Buster/RightSailor/S1/BusterCyl/SailorRight/S1/purple.png");
            QPixmap Second(":/Buster/RightSailor/S2/BusterCyl/SailorRight/S2/violet.png");
            if(i == 0){
                ui->sailorRightOne->setPixmap(Left10);
                ui->sailorRightOne->setVisible(true);
            }
            if(i == 1){
                ui->sailorRightTwo->setPixmap(Second);
                ui->sailorRightTwo->setVisible(true);
            }
        }break;
        case 11:
        {
            QPixmap Left11(":/Buster/RightSailor/S1/BusterCyl/SailorRight/S1/pink.png");
            QPixmap Second(":/Buster/RightSailor/S2/BusterCyl/SailorRight/S2/pink.png");
            if(i == 0){
                ui->sailorRightOne->setPixmap(Left11);
                ui->sailorRightOne->setVisible(true);
            }
            if(i == 1){
                ui->sailorRightTwo->setPixmap(Second);
                ui->sailorRightTwo->setVisible(true);
            }
        }break;
        }
    }
}

void busterwindow::on_exit_released()
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

void busterwindow::on_WaterfallSwitch_released()
{
    hide();
    MainWindow *mainWindow = new MainWindow();
    mainWindow->show();
}

void busterwindow::on_CWhite_released()
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

void busterwindow::on_Body_released()
{
    PartState = 1;
    partEventUpdate();
}

void busterwindow::on_Capy_released()
{
    PartState = 2;
    partEventUpdate();
}

void busterwindow::on_Gripy_released()
{
    PartState = 3;
    partEventUpdate();
}

void busterwindow::on_CGreen_released()
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

void busterwindow::on_CRed_released()
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

void busterwindow::on_CYellow_released()
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

void busterwindow::on_CBlack_released()
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

void busterwindow::on_CSkyBlue_released()
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

void busterwindow::on_CViolet_released()
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


void busterwindow::on_CPink_released()
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

void busterwindow::on_CDarkBlue_released()
{
    if(PartState == 2){
    LeftCapColorState = 8;
    isItLeftCap = true;
    }
    onColorClicked();
}

void busterwindow::on_COrange_released()
{
    if(PartState == 2){
    LeftCapColorState = 9;
    isItLeftCap = true;
    }
    onColorClicked();
}

void busterwindow::on_CWhite_2_released()
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

void busterwindow::on_CGreen_2_released()
{
    if(PartState == 2){
        RightCapColorState = 1;
        isItLeftCap = false;
    }
    onColorClicked();
}

void busterwindow::on_CRed_2_released()
{
    if(PartState == 2){
        RightCapColorState = 2;
        isItLeftCap = false;
    }
    onColorClicked();
}

void busterwindow::on_CYellow_2_released()
{
    if(PartState == 2){
        RightCapColorState = 3;
        isItLeftCap = false;
    }
    onColorClicked();
}

void busterwindow::on_CBlack_2_released()
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

void busterwindow::on_CSkyBlue_2_released()
{
    if(PartState == 2){
        RightCapColorState = 5;
        isItLeftCap = false;
    }
    onColorClicked();
}

void busterwindow::on_CViolet_2_released()
{
    if(PartState == 2){
        RightCapColorState = 6;
        isItLeftCap = false;
    }
    onColorClicked();
}

void busterwindow::on_CPink_2_released()
{
    if(PartState == 2){
        RightCapColorState = 7;
        isItLeftCap = false;
    }
    onColorClicked();
}

void busterwindow::on_CTransparent_2_released()
{
    if(PartState == 3){
        RightGripColorState = 2;
        isItLeftGrip = false;
    }
    onColorClicked();
}


void busterwindow::on_CDarkBlue_2_released()
{
    if(PartState == 2){
        RightCapColorState = 8;
        isItLeftCap = false;
    }
    onColorClicked();
}

void busterwindow::on_COrange_2_released()
{
    if(PartState == 2){
        RightCapColorState = 9;
        isItLeftCap = false;
    }
    onColorClicked();
}

void busterwindow::on_CTransparent_released()
{
    if(PartState == 3){
        LeftGripColorState = 2;
        isItLeftGrip = true;
    }
    onColorClicked();
}



void busterwindow::on_sailorSubmit_released()
{
    if(isItLeftSailor == true){
        initiateLeftSailors();
    }
    else if(isItLeftSailor == false){
        initiateRightSailors();
    }
    setSavedStates();
}

void busterwindow::on_LeftSide_released()
{
    isItLeftSailor = true;
    ui->LeftSide->setDisabled(true);
    ui->RightSide->setDisabled(false);
    if(isItPolish){
    ui->whatAreYouEditing_2->setText("Gripy z lewej strony");
    }else{
    ui->whatAreYouEditing_2->setText("Left side grips");
    }
    readLeftState();
}

void busterwindow::on_RightSide_released()
{
    isItLeftSailor = false;
    ui->LeftSide->setDisabled(false);
    ui->RightSide->setDisabled(true);
    if(isItPolish){
    ui->whatAreYouEditing_2->setText("Gripy z prawej strony");
    }else{
    ui->whatAreYouEditing_2->setText("Right side grips");
    }
    readRightState();
}

void busterwindow::on_Switch_3_released()
{
    hide();
    menowawindow MenowaDialog;
    MenowaDialog.setModal(true);
    MenowaDialog.exec();
}

void busterwindow::on_save_2_released()
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

void busterwindow::on_save_released()
{
    if(isItPolish){
    QMessageBox::information(this,"Ta opcja będzie dostępna wkrótce!","Ta opcja będzie dostępna wkrótce!");}
    else{
    QMessageBox::information(this,"Coming Soon!","Coming Soon!");
    }
}

void busterwindow::on_open_released()
{
    if(isItPolish){
    QMessageBox::information(this,"Ta opcja będzie dostępna wkrótce!","Ta opcja będzie dostępna wkrótce!");}
    else{
    QMessageBox::information(this,"Coming Soon!","Coming Soon!");
    }
}

void busterwindow::on_language_released()
{
    changeLanguage();
}

void busterwindow::on_save_5_released()
{
    if(isItPolish == true){
    QMessageBox::information(
    this,
    "Części do Buster Cyl mod"
    ,"<h2>Części do twojej modyfikacji</h2><br><b style='text-align: center'>Buster Cyl Mod</b><ul><li>Crayola SuperTips Body(x1)</li><li>Dong-A Comssa Cap (x2)</li><li>Zebra Airfit Grip (x2)</li><li>Zebra Airfit Tip (x2)</li><li>Dong-A Comssa Backplug (x1)</li><li>Zebra Airfit Ring</li><li>Anyball Profile Grip (x0-x4 (Zależy od ilości kolorów))</li></ul>"
    );
    }else{
     QMessageBox::information(
     this,
     "Parts to Waterfall mod"
     ,"<h2>Parts to modification</h2><br><b style='text-align: center'>Buster Cyl Mod</b><ul><li>Crayola SuperTips Body (x1)</li><li>Dong-A Comssa Cap (x2)</li><li>Zebra Airfit Grip (x2)</li><li>Zebra Airfit Tip (x2)</li><li>Dong-A Comssa Backplug (x1)</li><li>Zebra Airfit Ring</li><li>Anyball Profile Grip (x0-x4 (Depend of used colors))</li></ul>"
      );
    }
}

void busterwindow::on_save_6_released()
{
    /*Programisto! Jeżeli edytujesz ten program który jest pod licencją MIT, bardzo proszę, nie usuwaj poniższej linijki o prawdziwych autorach aplikacji, oraz tego komentarza, Dziękuję!*/
    /*Programmer! If You are editing this code, remember that this app is under MIT licence, that mean you shouldn't remove any information about real app author, and this comment either. Thank You!*/
    if(isItPolish == true){
    QMessageBox::information(this,"Autorzy","<h2>Penspinning - Make your mod</h2><br>Kod źródłowy oraz grafiki zostały stworzone przez:<br> <strong>Artur Koniec  <a href='http://ariteku.pl'>Ariteku.pl</a></strong><br><br>Ogromne podziękowania dla testerów aplikacji za ich wsparcie!<br><br><b>Zabraniam kopiowania i rozpowszechniania użytych w aplikacji grafik!</b>");
    }else{
    QMessageBox::information(this,"Authors","<h2>Penspinning - Make your mod</h2><br>Source code and graphic has been created by:<br> <strong>Artur Koniec  <a href='http://ariteku.pl'>Ariteku.pl</a></strong><br><br>Special Thanks for app tester for their support!<br><br><b>I do not allow to copy the graphics used in app!</b>");
    }
}

void busterwindow::on_settins_released()
{
    QMessageBox::StandardButton reply;
    if(isItPolish == true){
    reply = QMessageBox::question(this,"Jestes Pewny/a?","Czy napewno chcesz zrestartować program?",QMessageBox::Yes|QMessageBox::No);
    }else{
    reply = QMessageBox::question(this,"Are You sure?","Do You really want to restart the application?",QMessageBox::Yes|QMessageBox::No);
    }
    if(reply == QMessageBox::Yes){
        hide();
        busterwindow BusterDialog;
        BusterDialog.setModal(true);
        BusterDialog.exec();
    }
    if(reply == QMessageBox::No){
        //Continue
    }
}

void busterwindow::on_LeftSideCheckbox_released()
{
    isItLeftSailor = true;
    ui->LeftSide->setDisabled(true);
    ui->RightSide->setDisabled(false);
    if(isItPolish){
    ui->whatAreYouEditing_2->setText("Gripy z lewej strony");
    }else{
    ui->whatAreYouEditing_2->setText("Left side grips");
    }
    readLeftState();
}

void busterwindow::on_RightSideCheckbox_released()
{
    isItLeftSailor = false;
    ui->LeftSide->setDisabled(false);
    ui->RightSide->setDisabled(true);
    if(isItPolish){
    ui->whatAreYouEditing_2->setText("Gripy z prawej strony");
    }else{
    ui->whatAreYouEditing_2->setText("Right side grips");
    }
    readRightState();
}

void busterwindow::on_toolButton_released()
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
void busterwindow::on_save_3_released()
{
    if(isItPolish == true){
    QMessageBox::about(this,"Licencje","<ul><li>Aplikacja ta została napisana w języku C++ za pomocą środowiska Qt Creator.</li><li>Aplikacja używa licencji MIT.</li><li>Kod źródłowy na GitHubie znajduję się pod <a href='https://github.com/AritekuDev/PenspinningMakeYourMod'>tym</a> linkiem.</li></ul>");
    }else{
    QMessageBox::about(this,"Licence","<ul><li>This applciation has been written in C++ language using Qt Creator IDE.</li><li>Application use MIT licence.</li><li>Source code of app is available on github under <a href='https://github.com/AritekuDev/PenspinningMakeYourMod'>this</a> link.</li></ul>");
    }
}
void busterwindow::on_save_4_released()
{
    /*Programisto! Jeżeli edytujesz mój program który jest pod licencją MIT, bardzo proszę, nie usuwaj poniższej linijki o prawdziwych autorach aplikacji, oraz tego komentarza, Dziękuję!*/
    /*Programmer! If You are editing this code, remember that this app is under MIT licence, that mean you shouldn't remove any information about real app author, and this comment either. Thank You!*/
    if(isItPolish == true){
    QMessageBox::about(this,"Kontakt z deweloperem","<h4>Znalazłeś błąd w aplikacji?</h4>Jeżeli znalazłeś jakiekolwiek błędy w aplikacji, bardzo proszę, zgłoś je do mnie na email:<br><b>aritekudev@gmail.com</b><br><h3>Poszukuje grafika do aplikacji!</h3>Jak widzisz, grafiki w aplikacji nie są zbyt dobre. Jeżeli jesteś grafikiem 2D, możesz przyczynić się do tworzenia tej aplikacji, proszę, skontaktuj się ze mną na adres:<br><strong>aritekudev@gmail.com</strong>");
    }else{
    QMessageBox::about(this,"Contact with developer","<h4>Is something wrong in app?</h4>If you found any kind of mistakes in application, please, report them to me at:<br><b>aritekudev@gmail.com</b><br><h3>I'm looking for a graphic designer for app!</h3>As you can see, these graphics of pens aren't really good. If You are 2D graphic designer, we can make this app together. Please contact with me at:<br><strong>aritekudev@gmail.com</strong>");
    }
}
void busterwindow::changeLanguage()
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
     ui->sailorSubmit->setText("Submit");
     ui->whatAreYouEditing->setText("Editing:");
     ui->pushButton->setText("Check for updates");
     updateComboBoxes();
     if(PartState == 1){
         ui->LabelEdit->setText("Editing: BODY");
         ui->groupBox->setTitle("Left Body");
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
     ui->sailorSubmit->setText("Zatwierdź");
     ui->whatAreYouEditing->setText("Edytujsz:");
     ui->pushButton->setText("Sprawdź aktualizacje");
     updateComboBoxes();
     if(PartState == 1){
         ui->LabelEdit->setText("Edytujesz: BODY");
         ui->groupBox->setTitle("Lewe Body");
         ui->groupBox_2->setTitle("Prawe Body");
     }
     else if(PartState == 2){
         ui->LabelEdit->setText("Edytujesz: CAPY");
         ui->groupBox->setTitle("Lewy Cap");
         ui->groupBox_2->setTitle("Prawy Cap");
     }
     else if(PartState == 3){
         ui->LabelEdit->setText("Użyj kompozycji<br>anyballi");
         ui->groupBox->setTitle("Lewy Grip");
         ui->groupBox_2->setTitle("Prawy Grip");
     }
     if(isItLeftSailor){
         ui->whatAreYouEditing_2->setText("Gripy z lewej strony");
     }else{
         ui->whatAreYouEditing_2->setText("Gripy z prawej strony");
     }
     isItPolish = true;
    }
}

void busterwindow::on_Switch_7_released()
{
    QDesktopServices::openUrl(QUrl(ariteku));
}

void busterwindow::on_pushButton_released()
{
    QString dirApp = qApp->applicationDirPath();
    QString dirFile = dirApp+"/maintenancetool.exe";
    QDesktopServices::openUrl(QUrl("file:///"+dirFile));
    QApplication::quit();
}
void busterwindow::saveLeftState(){
    LeftDownStates[0] = ui->comboBox->currentIndex();
    LeftDownStates[1] = ui->comboBox_2->currentIndex();
    LeftDownStates[2] = ui->comboBox_3->currentIndex();
    LeftDownStates[3] = ui->comboBox_4->currentIndex();
}
void busterwindow::saveRightState(){
    RightDownStates[0] = ui->comboBox->currentIndex();
    RightDownStates[1] = ui->comboBox_2->currentIndex();
    RightDownStates[2] = ui->comboBox_3->currentIndex();
    RightDownStates[3] = ui->comboBox_4->currentIndex();
}
void busterwindow::readLeftState(){
    ui->comboBox->setCurrentIndex(LeftDownStates[0]);
    ui->comboBox_2->setCurrentIndex(LeftDownStates[1]);
    ui->comboBox_3->setCurrentIndex(LeftDownStates[2]);
    ui->comboBox_4->setCurrentIndex(LeftDownStates[3]);
}
void busterwindow::readRightState(){
    ui->comboBox->setCurrentIndex(RightDownStates[0]);
    ui->comboBox_2->setCurrentIndex(RightDownStates[1]);
    ui->comboBox_3->setCurrentIndex(RightDownStates[2]);
    ui->comboBox_4->setCurrentIndex(RightDownStates[3]);
}
void busterwindow::setSavedStates(){
    if(isItLeftSailor == true){
        saveLeftState();
    }
    else if(isItLeftSailor == false){
        saveRightState();
    }
}
