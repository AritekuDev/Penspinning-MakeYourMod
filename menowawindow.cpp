/*Programisto! Ten kod został udostępniony na platformie github: https://github.com/AritekuDev/PenspinningMakeYourMod
 Pod licencją MIT. Proszę, nie usuwaj z niego żadnych informacji o realnych autorach Aplikacji, tj Artur Koniec - Ariteku.pl
 Proszę cię też by program nie uległ zmianie w więcej niż 30%.
 Kosztował mnie on naprawdę wiele czasu i serca, więc uszanuj to, i zastosuj się proszę do powyższych sentencji.
 Pozdrawiam - Arteq - Ariteku.pl - Pełnoprawny autor Penspinning: Make your Mod.
*/
/*Programmer! This code was shared with everyone on github platform under link: https://github.com/AritekuDev/PenspinningMakeYourMod
Under the MIT licence. Please, do not remove any information about real author of application - Artur Koniec - Ariteku.pl
Please, don't change this app in more than 30%.
It cost me a lot of time and hearth, so please respect this fact, and don't ignore aboves sentences.
Greetings - Arteq - Ariteku.pl - The real author of Penspinning: Make your Mod.
*/
#include "menowawindow.h"
#include "ui_menowawindow.h"

menowawindow::menowawindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::menowawindow)
{
    ui->setupUi(this);
    QPixmap Panels(":/patterns/retro_intro.png");
    ui->leftPanel->move(0,0);
    ui->leftPanel->resize(150,750);
    ui->leftPanel->setPixmap(Panels);
    ui->leftPanel->setScaledContents(true);
    //Right Panel Default Settings
    ui->rightPanel->move(850,0);
    ui->rightPanel->resize(150,750);
    ui->rightPanel->setPixmap(Panels);
    ui->rightPanel->setScaledContents(true);
    //Center background Default Settings //This pattern is downloaded from www.subtlepatterns.com If you need more, that's where to get'em.
    ui->BackgroundCenter->move(150,0);
    ui->BackgroundCenter->resize(700,750);
    QPixmap BG(":/patterns/whirlpool.png");
    ui->BackgroundCenter->setPixmap(BG);
    ui->BackgroundCenter->setScaledContents(true);
    //Menowa Default
    QPixmap MenowaDefault(":/Menowa/MenowaLight/big.png");
    ui->MenowaOriginal->setPixmap(MenowaDefault);
    ui->LeftSideRB->setChecked(true);
    ui->HighLayerRB->setChecked(true);
    isSailorMenuVisible = false;
    ui->GroupBoxSailors->setVisible(false);
    ui->pushButton->setCursor(Qt::PointingHandCursor);

    ///
    ui->pushButton->setStyleSheet("background: transparent; color: white; font-size: 20px; font-weight: bold;}");
    ui->comboBox5->setVisible(false);
    ui->label_15->setVisible(false);
    ui->comboBox2->setVisible(false);
    ui->label_12->setVisible(false);
    ui->label_11->setText("Pierwszy + Drugi");
    ui->comboBox_mod->addItem("Light");
    ui->whatAreYouEditing->setAlignment(Qt::AlignRight);
    ui->whatAreYouEditing->setText("Edytujesz: Lewą");
    ui->whatAreYouEditing_2->setAlignment(Qt::AlignLeft);
    ui->whatAreYouEditing_2->setText("górną warstwe gripów");
    ui->LeftSideRB->setVisible(true);
    ui->RightSideRB->setVisible(true);
    ui->HighLayerRB->setVisible(true);
    ui->LowLayerRB->setVisible(true);
    ui->LeftSideButton->setVisible(false);
    ui->RightSideButton->setVisible(false);
    ui->HighLayerButton->setVisible(false);
    ui->LowLayerButton->setVisible(false);
    ui->HighLayerButton->setDisabled(true);
    ui->LeftSideButton->setDisabled(true);
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
    for(int i=0; i<5; i++){
        LeftHighStates[i] = 0;
        RightHighStates[i] = 0;
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

menowawindow::~menowawindow()
{
    delete[] LeftSailorTable;
    delete[] RightSailorTable;
    delete[] LeftSecondSailorTable;
    delete[] RightSecondSailorTable;
    delete[] LeftHighStates;
    delete[] RightHighStates;
    delete[] LeftDownStates;
    delete[] RightDownStates;
    delete[] colors;
    delete[] colorsEnglish;
    delete[] currentColors;
    delete ui;
}
void menowawindow::setUpTransparentButtons(){
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
    QGraphicsDropShadowEffect *effect17 = new QGraphicsDropShadowEffect(this);
    effect17->setBlurRadius(15);
    effect17->setColor(QColor("#000000"));
    effect17->setOffset(0,0);
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
    ui->LabelEdit->setStyleSheet("QLabel {color: white; font-size: 15px; font-weight: bold; text-align: center;}");
    ui->LabelEdit->setGraphicsEffect(effect10);
    /////////////////////////////////////////////////////////
    ui->groupBox_2->setGraphicsEffect(effect11);
    /////////////////////////////////////////////////////////
    ui->MenowaOriginal->setGraphicsEffect(effect12);
    /////////////////////////////////////////////////////////
    ui->leftPanel->setGraphicsEffect(effect13);
    /////////////////////////////////////////////////////////
    ui->rightPanel->setGraphicsEffect(effect14);
    /////////////////////////////////////////////////////////
    ui->title->setGraphicsEffect(effect15);
    /////////////////////////////////////////////////////////
    ui->comboBox_mod->setGraphicsEffect(effect16);
    /////////////////////////////////////////////////////////
    ui->pushButton->setGraphicsEffect(effect17);
}
void menowawindow::setupColorButtons(){
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
void menowawindow::setupColorButtons_2(){
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
void menowawindow::partEventUpdate(){
    switch(PartState)
    {
    case 1: //Body jest wybrane

    ui->CRed->setVisible(true); //#1
    ui->CYellow->setVisible(true); //#2
    ui->CGreen->setVisible(true); //#3
    ui->CPink->setVisible(true); //#4
    ui->CViolet->setVisible(true); //#5
    ui->CSkyBlue->setVisible(true); //#6
    ui->CWhite->setVisible(true); //#7 <-- Always Visible
    ui->CBlack->setVisible(true); //#8 <-- Always Visible
    ui->CTransparent->setVisible(false); //#9
    ui->CDarkBlue->setVisible(true); //#10
    ui->COrange->setVisible(true);

    ui->CRed_2->setVisible(true); //#1
    ui->CYellow_2->setVisible(true); //#2
    ui->CGreen_2->setVisible(true); //#3
    ui->CPink_2->setVisible(true); //#4
    ui->CViolet_2->setVisible(true); //#5
    ui->CSkyBlue_2->setVisible(true); //#6
    ui->CWhite_2->setVisible(true); //#7 <-- Always Visible
    ui->CBlack_2->setVisible(true); //#8 <-- Always Visible
    ui->CTransparent_2->setVisible(false); //#9
    ui->CDarkBlue_2->setVisible(true); //#10
    ui->COrange_2->setVisible(true);
    if(isItPolish){
        ui->LabelEdit->setText("Edytujesz: BODY");
        ui->groupBox->setTitle("Lewe Body");
        ui->groupBox_2->setTitle("Prawe Body");
    }else{
        ui->LabelEdit->setText("Editing: BODY");
        ui->groupBox->setTitle("Left Body");
        ui->groupBox_2->setTitle("Right Body");
    }
    ui->groupBox_2->setVisible(true);

    switch(LeftBodyColorState)
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
    switch(RightBodyColorState)
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
            ui->CTransparent_2->setStyleSheet("QPushButton { background-color:"+ColorTransparent+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorTransparent+"}");
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
            ui->CTransparent_2->setStyleSheet("QPushButton { background-color:"+ColorTransparent+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorTransparent+"}");

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
            ui->CTransparent_2->setStyleSheet("QPushButton { background-color:"+ColorTransparent+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorTransparent+"}");

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
            ui->CTransparent_2->setStyleSheet("QPushButton { background-color:"+ColorTransparent+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorTransparent+"}");
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
             ui->CTransparent_2->setStyleSheet("QPushButton { background-color:"+ColorTransparent+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorTransparent+"}");
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
             ui->CTransparent_2->setStyleSheet("QPushButton { background-color:"+ColorTransparent+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorTransparent+"}");
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
             ui->CTransparent_2->setStyleSheet("QPushButton { background-color:"+ColorTransparent+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorTransparent+"}");

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
             ui->CTransparent_2->setStyleSheet("QPushButton { background-color:"+ColorTransparent+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorTransparent+"}");

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
            ui->CTransparent_2->setStyleSheet("QPushButton { background-color:"+ColorTransparent+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorTransparent+"}");

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
            ui->CTransparent_2->setStyleSheet("QPushButton { background-color:"+ColorTransparent+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorTransparent+"}");
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
    ui->CWhite->setVisible(true); //#7 <-- Always Visible
    ui->CBlack->setVisible(true); //#8 <-- Always Visible
    ui->CTransparent->setVisible(true);
    ui->CDarkBlue->setVisible(true);
    ui->COrange->setVisible(true);

    ui->CRed_2->setVisible(true); //#1
    ui->CYellow_2->setVisible(true); //#2
    ui->CGreen_2->setVisible(true); //#3
    ui->CPink_2->setVisible(true); //#4
    ui->CViolet_2->setVisible(true); //#5
    ui->CSkyBlue_2->setVisible(true); //#6
    ui->CWhite_2->setVisible(true); //#7 <-- Always Visible
    ui->CBlack_2->setVisible(true); //#8 <-- Always Visible
    ui->CTransparent_2->setVisible(true);
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
        ui->CTransparent->setStyleSheet("QPushButton { background-color:"+ColorTransparent+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorTransparent+"}");
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
        ui->CTransparent->setStyleSheet("QPushButton { background-color:"+ColorTransparent+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorTransparent+"}");
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
        ui->CTransparent->setStyleSheet("QPushButton { background-color:"+ColorTransparent+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorTransparent+"}");
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
        ui->CTransparent->setStyleSheet("QPushButton { background-color:"+ColorTransparent+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorTransparent+"}");
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
        ui->CTransparent->setStyleSheet("QPushButton { background-color:"+ColorTransparent+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorTransparent+"}");
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
        ui->CTransparent->setStyleSheet("QPushButton { background-color:"+ColorTransparent+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorTransparent+"}");
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
        ui->CTransparent->setStyleSheet("QPushButton { background-color:"+ColorTransparent+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorTransparent+"}");
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
        ui->CTransparent->setStyleSheet("QPushButton { background-color:"+ColorTransparent+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorTransparent+"}");
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
        ui->CTransparent->setStyleSheet("QPushButton { background-color:"+ColorTransparent+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorTransparent+"}");
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
        ui->CTransparent->setStyleSheet("QPushButton { background-color:"+ColorTransparent+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorTransparent+"}");
    }break;
    case 10:
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
        ui->COrange->setStyleSheet("QPushButton { background-color:"+ColorOrange+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorOrange+"}");
        ui->CTransparent->setStyleSheet("QPushButton { background-color:"+ColorTransparent+"; border: 2px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorTransparent+"}");
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
        ui->CTransparent_2->setStyleSheet("QPushButton { background-color:"+ColorTransparent+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorTransparent+"}");

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
        ui->CTransparent_2->setStyleSheet("QPushButton { background-color:"+ColorTransparent+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorTransparent+"}");

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
        ui->CTransparent_2->setStyleSheet("QPushButton { background-color:"+ColorTransparent+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorTransparent+"}");

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
        ui->CTransparent_2->setStyleSheet("QPushButton { background-color:"+ColorTransparent+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorTransparent+"}");

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
        ui->CTransparent_2->setStyleSheet("QPushButton { background-color:"+ColorTransparent+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorTransparent+"}");

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
        ui->CTransparent_2->setStyleSheet("QPushButton { background-color:"+ColorTransparent+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorTransparent+"}");

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
        ui->CTransparent_2->setStyleSheet("QPushButton { background-color:"+ColorTransparent+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorTransparent+"}");

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
        ui->CTransparent_2->setStyleSheet("QPushButton { background-color:"+ColorTransparent+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorTransparent+"}");

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
        ui->CTransparent_2->setStyleSheet("QPushButton { background-color:"+ColorTransparent+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorTransparent+"}");

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
        ui->CTransparent_2->setStyleSheet("QPushButton { background-color:"+ColorTransparent+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorTransparent+"}");

    }break;
    case 10:
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
        ui->COrange_2->setStyleSheet("QPushButton { background-color:"+ColorOrange+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorOrange+"}");
        ui->CTransparent_2->setStyleSheet("QPushButton { background-color:"+ColorTransparent+"; border: 2px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorTransparent+"}");

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
        ui->LabelEdit->setText("Użyj kompozycji<br>pasków");
        ui->groupBox->setTitle("Left Grip");
        ui->groupBox_2->setTitle("Right Grip");
    }else{
        ui->LabelEdit->setText("<small>Use Anyballs composition</small>");
        ui->groupBox->setTitle("Left Grip");
        ui->groupBox_2->setTitle("Right Grip");
    }
    ui->LabelEdit->setAlignment(Qt::AlignCenter);

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

void menowawindow::onColorClicked(){
    if(PartState == 1){
        if(isItLeftBody == true){
        switch(LeftBodyColorState)
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
             ui->CDarkBlue->setStyleSheet("QPushButton { background-color:"+ColorDarkBlue+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorDarkBlue+"}");
             ui->COrange->setStyleSheet("QPushButton { background-color:"+ColorOrange+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorOrange+"}");
             ///
             ui->Part_leftBody->setVisible(false);
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
            ui->CDarkBlue->setStyleSheet("QPushButton { background-color:"+ColorDarkBlue+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorDarkBlue+"}");
            ui->COrange->setStyleSheet("QPushButton { background-color:"+ColorOrange+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorOrange+"}");

            QPixmap bodyGreen(":/Menowa/Left/Body/MenowaLight/Bodyleft/green.png");
            ui->Part_leftBody->setPixmap(bodyGreen);
            ui->Part_leftBody->setVisible(true);
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
            ui->CDarkBlue->setStyleSheet("QPushButton { background-color:"+ColorDarkBlue+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorDarkBlue+"}");
            ui->COrange->setStyleSheet("QPushButton { background-color:"+ColorOrange+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorOrange+"}");

            QPixmap bodyRed(":/Menowa/Left/Body/MenowaLight/Bodyleft/red.png");
            ui->Part_leftBody->setPixmap(bodyRed);
            ui->Part_leftBody->setVisible(true);
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
            ui->CDarkBlue->setStyleSheet("QPushButton { background-color:"+ColorDarkBlue+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorDarkBlue+"}");
            ui->COrange->setStyleSheet("QPushButton { background-color:"+ColorOrange+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorOrange+"}");

            QPixmap bodyYellow(":/Menowa/Left/Body/MenowaLight/Bodyleft/yellow.png");
            ui->Part_leftBody->setPixmap(bodyYellow);
            ui->Part_leftBody->setVisible(true);
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
            ui->CDarkBlue->setStyleSheet("QPushButton { background-color:"+ColorDarkBlue+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorDarkBlue+"}");
            ui->COrange->setStyleSheet("QPushButton { background-color:"+ColorOrange+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorOrange+"}");

            //Body Color change
            QPixmap bodyBlack(":/Menowa/Left/Body/MenowaLight/Bodyleft/black.png");
            ui->Part_leftBody->setPixmap(bodyBlack);
            ui->Part_leftBody->setVisible(true);
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
            ui->CDarkBlue->setStyleSheet("QPushButton { background-color:"+ColorDarkBlue+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorDarkBlue+"}");
            ui->COrange->setStyleSheet("QPushButton { background-color:"+ColorOrange+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorOrange+"}");

            QPixmap bodyBlue(":/Menowa/Left/Body/MenowaLight/Bodyleft/skyblue.png");
            ui->Part_leftBody->setPixmap(bodyBlue);
            ui->Part_leftBody->setVisible(true);
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
            ui->CDarkBlue->setStyleSheet("QPushButton { background-color:"+ColorDarkBlue+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorDarkBlue+"}");
            ui->COrange->setStyleSheet("QPushButton { background-color:"+ColorOrange+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorOrange+"}");

            QPixmap bodyViolet(":/Menowa/Left/Body/MenowaLight/Bodyleft/violet.png");
            ui->Part_leftBody->setPixmap(bodyViolet);
            ui->Part_leftBody->setVisible(true);
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
            ui->CDarkBlue->setStyleSheet("QPushButton { background-color:"+ColorDarkBlue+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorDarkBlue+"}");
            ui->COrange->setStyleSheet("QPushButton { background-color:"+ColorOrange+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorOrange+"}");

            QPixmap bodyPink(":/Menowa/Left/Body/MenowaLight/Bodyleft/pink.png");
            ui->Part_leftBody->setPixmap(bodyPink);
            ui->Part_leftBody->setVisible(true);
        } break;
        case 8: //DarkBlue
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
          QPixmap bodyBlue(":/Menowa/Left/Body/MenowaLight/Bodyleft/darkblue.png");
          ui->Part_leftBody->setPixmap(bodyBlue);
          ui->Part_leftBody->setVisible(true);
         }break;
        case 9: //Orange
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
          QPixmap bodyOrange(":/Menowa/Left/Body/MenowaLight/Bodyleft/orange.png");
          ui->Part_leftBody->setPixmap(bodyOrange);
          ui->Part_leftBody->setVisible(true);
         }break;
      }
        }
        else if(isItLeftBody == false){
            switch(RightBodyColorState){
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
              ui->Part_rightBody->setVisible(false);
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
              QPixmap rightCapGreen(":/Menowa/Right/Body/MenowaLight/Bodyright/green.png");
              ui->Part_rightBody->setPixmap(rightCapGreen);
              ui->Part_rightBody->setVisible(true);
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
              QPixmap rightCapRed(":/Menowa/Right/Body/MenowaLight/Bodyright/red.png");
              ui->Part_rightBody->setPixmap(rightCapRed);
              ui->Part_rightBody->setVisible(true);
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
              QPixmap rightCapYellow(":/Menowa/Right/Body/MenowaLight/Bodyright/yellow.png");
              ui->Part_rightBody->setPixmap(rightCapYellow);
              ui->Part_rightBody->setVisible(true);
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
              QPixmap rightCapBlack(":/Menowa/Right/Body/MenowaLight/Bodyright/black.png");
              ui->Part_rightBody->setPixmap(rightCapBlack);
              ui->Part_rightBody->setVisible(true);
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
              QPixmap rightCapSkyBlue(":/Menowa/Right/Body/MenowaLight/Bodyright/skyblue.png");
              ui->Part_rightBody->setPixmap(rightCapSkyBlue);
              ui->Part_rightBody->setVisible(true);
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
              QPixmap rightCapViolet(":/Menowa/Right/Body/MenowaLight/Bodyright/violet.png");
              ui->Part_rightBody->setPixmap(rightCapViolet);
              ui->Part_rightBody->setVisible(true);
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
              QPixmap rightCapPink(":/Menowa/Right/Body/MenowaLight/Bodyright/pink.png");
              ui->Part_rightBody->setPixmap(rightCapPink);
              ui->Part_rightBody->setVisible(true);
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
              QPixmap rightCapDarkBlue(":/Menowa/Right/Body/MenowaLight/Bodyright/darkblue.png");
              ui->Part_rightBody->setPixmap(rightCapDarkBlue);
              ui->Part_rightBody->setVisible(true);
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
              QPixmap rightCapOrange(":/Menowa/Right/Body/MenowaLight/Bodyright/orange.png");
              ui->Part_rightBody->setPixmap(rightCapOrange);
              ui->Part_rightBody->setVisible(true);
             }break;
            }
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
            ui->CTransparent->setStyleSheet("QPushButton { background-color:"+ColorTransparent+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorTransparent+"}");
            QPixmap leftCapWhite(":/Menowa/Left/Capy/MenowaLight/Capleft/white.png");
            ui->part_leftCap->setPixmap(leftCapWhite);
            ui->part_leftCap->setVisible(true);
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
             ui->CTransparent->setStyleSheet("QPushButton { background-color:"+ColorTransparent+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorTransparent+"}");
            QPixmap leftCapGreen(":/Menowa/Left/Capy/MenowaLight/Capleft/lightgreen.png");
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
             ui->CTransparent->setStyleSheet("QPushButton { background-color:"+ColorTransparent+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorTransparent+"}");
            QPixmap leftCapRed(":/Menowa/Left/Capy/MenowaLight/Capleft/red.png");
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
             ui->CTransparent->setStyleSheet("QPushButton { background-color:"+ColorTransparent+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorTransparent+"}");
            QPixmap leftCapYellow(":/Menowa/Left/Capy/MenowaLight/Capleft/yellow.png");
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
             ui->CTransparent->setStyleSheet("QPushButton { background-color:"+ColorTransparent+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorTransparent+"}");
            ui->part_leftCap->setVisible(false);
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
             ui->CTransparent->setStyleSheet("QPushButton { background-color:"+ColorTransparent+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorTransparent+"}");
            QPixmap leftCapSkyBlue(":/Menowa/Left/Capy/MenowaLight/Capleft/skyblue.png");
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
             ui->CTransparent->setStyleSheet("QPushButton { background-color:"+ColorTransparent+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorTransparent+"}");
            ///
            QPixmap leftCapViolet(":/Menowa/Left/Capy/MenowaLight/Capleft/violet.png");
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
             ui->CTransparent->setStyleSheet("QPushButton { background-color:"+ColorTransparent+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorTransparent+"}");
            ///
            QPixmap leftCapPink(":/Menowa/Left/Capy/MenowaLight/Capleft/pink.png");
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
             ui->CTransparent->setStyleSheet("QPushButton { background-color:"+ColorTransparent+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorTransparent+"}");
            ///
            QPixmap leftCapDarkBlue(":/Menowa/Left/Capy/MenowaLight/Capleft/darkblue.png");
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
            ui->CTransparent->setStyleSheet("QPushButton { background-color:"+ColorTransparent+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorTransparent+"}");
            ///
            QPixmap leftCapOrange(":/Menowa/Left/Capy/MenowaLight/Capleft/orange.png");
            ui->part_leftCap->setPixmap(leftCapOrange);
            ui->part_leftCap->setVisible(true);
           }break;
          case 10:
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
            ui->COrange->setStyleSheet("QPushButton { background-color:"+ColorOrange+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorOrange+"}");
            ui->CTransparent->setStyleSheet("QPushButton { background-color:"+ColorTransparent+"; border: 2px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorTransparent+"}");
            ///
            QPixmap leftCapGrey(":/Menowa/Left/Capy/MenowaLight/Capleft/grey.png");
            ui->part_leftCap->setPixmap(leftCapGrey);
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
              ui->CTransparent_2->setStyleSheet("QPushButton { background-color:"+ColorTransparent+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorTransparent+"}");
              QPixmap rightCapWhite(":/Menowa/Right/Capy/MenowaLight/Capright/white.png");
              ui->part_rightCap->setPixmap(rightCapWhite);
              ui->part_rightCap->setVisible(true);
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
              ui->CTransparent_2->setStyleSheet("QPushButton { background-color:"+ColorTransparent+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorTransparent+"}");

              QPixmap rightCapGreen(":/Menowa/Right/Capy/MenowaLight/Capright/lightgreen.png");
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
              ui->CTransparent_2->setStyleSheet("QPushButton { background-color:"+ColorTransparent+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorTransparent+"}");

              QPixmap rightCapRed(":/Menowa/Right/Capy/MenowaLight/Capright/red.png");
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
              ui->CTransparent_2->setStyleSheet("QPushButton { background-color:"+ColorTransparent+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorTransparent+"}");

              QPixmap rightCapYellow(":/Menowa/Right/Capy/MenowaLight/Capright/yellow.png");
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
              ui->CTransparent_2->setStyleSheet("QPushButton { background-color:"+ColorTransparent+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorTransparent+"}");
              ui->part_rightCap->setVisible(false);
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
              ui->CTransparent_2->setStyleSheet("QPushButton { background-color:"+ColorTransparent+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorTransparent+"}");

              QPixmap rightCapSkyBlue(":/Menowa/Right/Capy/MenowaLight/Capright/skyblue.png");
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
              ui->CTransparent_2->setStyleSheet("QPushButton { background-color:"+ColorTransparent+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorTransparent+"}");

              QPixmap rightCapViolet(":/Menowa/Right/Capy/MenowaLight/Capright/violet.png");
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
              ui->CTransparent_2->setStyleSheet("QPushButton { background-color:"+ColorTransparent+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorTransparent+"}");

              QPixmap rightCapPink(":/Menowa/Right/Capy/MenowaLight/Capright/pink.png");
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
              ui->CTransparent_2->setStyleSheet("QPushButton { background-color:"+ColorTransparent+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorTransparent+"}");

              QPixmap rightCapDarkBlue(":/Menowa/Right/Capy/MenowaLight/Capright/darkblue.png");
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
              ui->CTransparent_2->setStyleSheet("QPushButton { background-color:"+ColorTransparent+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorTransparent+"}");

              QPixmap rightCapOrange(":/Menowa/Right/Capy/MenowaLight/Capright/orange.png");
              ui->part_rightCap->setPixmap(rightCapOrange);
              ui->part_rightCap->setVisible(true);
             }break;
            case 10:
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
              ui->COrange_2->setStyleSheet("QPushButton { background-color:"+ColorOrange+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorOrange+"}");
              ui->CTransparent_2->setStyleSheet("QPushButton { background-color:"+ColorTransparent+"; border: 2px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorTransparent+"}");

              QPixmap rightCapGrey(":/Menowa/Right/Capy/MenowaLight/Capright/grey.png");
              ui->part_rightCap->setPixmap(rightCapGrey);
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
                QPixmap leftGripWhite("");
                ui->part_leftGrip->setPixmap(leftGripWhite);
                ui->part_leftGrip->setVisible(true);
            }break;
            case 1:
            {
                ui->CWhite->setStyleSheet("QPushButton { background-color:"+ColorWhite+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorWhite+"}");
                ui->CBlack->setStyleSheet("QPushButton { background-color:"+ColorBlack+"; border: 2px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorBlack+"}");
                ui->CTransparent->setStyleSheet("QPushButton { background-color:"+ColorTransparent+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+ColorTransparent+"}");
                ///
                QPixmap leftGripBlack("");
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
                QPixmap rightGripWhite("");
                ui->part_rightGrip->setPixmap(rightGripWhite);
                ui->part_rightGrip->setVisible(true);
            }break;
            case 1:
            {
                ui->CWhite_2->setStyleSheet("QPushButton { background-color:"+ColorWhite+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorWhite+"}");
                ui->CBlack_2->setStyleSheet("QPushButton { background-color:"+ColorBlack+"; border: 2px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+DColorBlack+"}");
                ui->CTransparent_2->setStyleSheet("QPushButton { background-color:"+ColorTransparent+"; border: 1px solid #000; border-radius: 3px;} QPushButton:hover {background-color:"+ColorTransparent+"}");
                ///
                QPixmap rightGripBlack("");
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


void menowawindow::initiateComboBoxes()
{
  for(int i=0; i<13; i++){
      ui->comboBox1->addItem(currentColors[i]);
      ui->comboBox2->addItem(currentColors[i]);
      ui->comboBox3->addItem(currentColors[i]);
      ui->comboBox4->addItem(currentColors[i]);
      ui->comboBox5->addItem(currentColors[i]);
  }

}
void menowawindow::updateComboBoxes()
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
    ui->comboBox1->clear();
    ui->comboBox2->clear();
    ui->comboBox3->clear();
    ui->comboBox4->clear();
    ui->comboBox5->clear();
    initiateComboBoxes();
}
void menowawindow::on_Body_released()
{
    PartState = 1;
    partEventUpdate();
}

void menowawindow::on_Capy_released()
{
    PartState = 2;
    partEventUpdate();
}

void menowawindow::on_Gripy_released()
{
    PartState = 3;
    partEventUpdate();
}

void menowawindow::on_CWhite_released()
{
    if(PartState == 1){
    LeftBodyColorState = 0;
    isItLeftBody = true;
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

void menowawindow::on_CGreen_released()
{
    if(PartState == 1){
    LeftBodyColorState = 1;
    isItLeftBody = true;
    }
    else if(PartState == 2){
    LeftCapColorState = 1;
    isItLeftCap = true;
    }
    onColorClicked();
}

void menowawindow::on_CRed_released()
{
    if(PartState == 1){
    LeftBodyColorState = 2;
    isItLeftBody = true;
    }
    else if(PartState == 2){
    LeftCapColorState = 2;
    isItLeftCap = true;
    }
    onColorClicked();
}

void menowawindow::on_CYellow_released()
{
    if(PartState == 1){
    LeftBodyColorState = 3;
    isItLeftBody = true;
    }
    else if(PartState == 2){
    LeftCapColorState = 3;
    isItLeftCap = true;
    }
    onColorClicked();
}

void menowawindow::on_CBlack_released()
{
    if(PartState == 1){
    LeftBodyColorState = 4;
    isItLeftBody = true;
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

void menowawindow::on_CSkyBlue_released()
{
    if(PartState == 1){
    LeftBodyColorState = 5;
    isItLeftBody = true;
    }
    else if(PartState == 2){
    LeftCapColorState = 5;
    isItLeftCap = true;
    }
    onColorClicked();
}

void menowawindow::on_CViolet_released()
{
    if(PartState == 1){
    LeftBodyColorState = 6;
    isItLeftBody = true;
    }
    else if(PartState == 2){
    LeftCapColorState = 6;
    isItLeftCap = true;
    }
    onColorClicked();
}

void menowawindow::on_CPink_released()
{
    if(PartState == 1){
    LeftBodyColorState = 7;
    isItLeftBody = true;
    }
    else if(PartState == 2){
    LeftCapColorState = 7;
    isItLeftCap = true;
    }
    onColorClicked();
}

void menowawindow::on_CTransparent_released()
{
    if(PartState == 2){
        LeftCapColorState = 10;
        isItLeftCap = true;
    }
    if(PartState == 3){
        LeftGripColorState = 2;
        isItLeftGrip = true;
    }
    onColorClicked();
}

void menowawindow::on_CDarkBlue_released()
{
    if(PartState == 1){
        LeftBodyColorState = 8;
        isItLeftBody = true;
    }
    else if(PartState == 2){
    LeftCapColorState = 8;
    isItLeftCap = true;
    }
    onColorClicked();
}

void menowawindow::on_COrange_released()
{
    if(PartState == 1){
        LeftBodyColorState = 9;
        isItLeftBody = true;
    }
    if(PartState == 2){
    LeftCapColorState = 9;
    isItLeftCap = true;
    }
    onColorClicked();
}

void menowawindow::on_CWhite_2_released()
{
    if(PartState == 1){
        RightBodyColorState = 0;
        isItLeftBody = false;
    }
    else  if(PartState == 2){
        RightCapColorState = 0;
        isItLeftCap = false;
    }
    else if(PartState == 3){
        RightGripColorState = 0;
        isItLeftGrip = false;
    }
    onColorClicked();
}

void menowawindow::on_CGreen_2_released()
{
    if(PartState == 2){
        RightCapColorState = 1;
        isItLeftCap = false;
    }
    else if(PartState == 1){
        RightBodyColorState = 1;
        isItLeftBody = false;
    }
    onColorClicked();
}

void menowawindow::on_CRed_2_released()
{
    if(PartState == 2){
        RightCapColorState = 2;
        isItLeftCap = false;
    }
    else if(PartState == 1){
        RightBodyColorState = 2;
        isItLeftBody = false;
    }
    onColorClicked();
}

void menowawindow::on_CYellow_2_released()
{
    if(PartState == 2){
        RightCapColorState = 3;
        isItLeftCap = false;
    }
    else if(PartState == 1){
        RightBodyColorState = 3;
        isItLeftBody = false;
    }
    onColorClicked();
}

void menowawindow::on_CBlack_2_released()
{
    if(PartState == 2){
        RightCapColorState = 4;
        isItLeftCap = false;
    }
    else if(PartState == 1){
        RightBodyColorState = 4;
        isItLeftBody = false;
    }
    if(PartState == 3){
        RightGripColorState = 1;
        isItLeftGrip = false;
    }
    onColorClicked();
}

void menowawindow::on_CSkyBlue_2_released()
{
    if(PartState == 2){
        RightCapColorState = 5;
        isItLeftCap = false;
    }
    else if(PartState == 1){
        RightBodyColorState = 5;
        isItLeftBody = false;
    }
    onColorClicked();
}

void menowawindow::on_CViolet_2_released()
{
    if(PartState == 2){
        RightCapColorState = 6;
        isItLeftCap = false;
    }
    else if(PartState == 1){
        RightBodyColorState = 6;
        isItLeftBody = false;
    }
    onColorClicked();
}

void menowawindow::on_CPink_2_released()
{
    if(PartState == 2){
        RightCapColorState = 7;
        isItLeftCap = false;
    }
    else if(PartState == 1){
        RightBodyColorState = 7;
        isItLeftBody = false;
    }
    onColorClicked();
}

void menowawindow::on_CDarkBlue_2_released()
{
    if(PartState == 1){
        RightBodyColorState = 8;
        isItLeftBody = false;
    }
    else if(PartState == 2){
        RightCapColorState = 8;
        isItLeftCap = false;
    }
    onColorClicked();
}

void menowawindow::on_COrange_2_released()
{
    if(PartState == 1){
        RightBodyColorState = 9;
        isItLeftBody = false;
    }
    else if(PartState == 2){
        RightCapColorState = 9;
        isItLeftCap = false;
    }
    onColorClicked();
}

void menowawindow::on_CTransparent_2_released()
{
    if(PartState == 2){
        RightCapColorState = 10;
        isItLeftCap = false;
    }
    if(PartState == 3){
        RightGripColorState = 2;
        isItLeftGrip = false;
    }
    onColorClicked();
}

void menowawindow::on_pushButton_released()
{
    QDesktopServices::openUrl(QUrl(ariteku));
}

void menowawindow::on_exit_released()
{
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this,"Jestes Pewny/a?","Czy napewno chcesz wyjść z aplikacji?<br>Upewnij się że zapisałeś swoją kompozycje, inaczej zostanie ona utracona.",QMessageBox::Yes|QMessageBox::No);
    if(reply == QMessageBox::Yes){
        QApplication::quit();
    }
    if(reply == QMessageBox::No){
        //Continue
    }
}

void menowawindow::on_settins_released()
{
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this,"Jestes Pewny/a?","Czy napewno chcesz wyjść z aplikacji?<br>Upewnij się że zapisałeś swoją kompozycje, inaczej zostanie ona utracona.",QMessageBox::Yes|QMessageBox::No);
    if(reply == QMessageBox::Yes){
        hide();
        menowawindow menowaDialog;
        menowaDialog.setModal(true);
        menowaDialog.exec();
    }
    if(reply == QMessageBox::No){
        //Continue
    }
}

void menowawindow::on_sailorSubmit_released()
{
    if(isItLeft == true){
        if(isItHigh == true){ //Lewa górna warstwa
            initiateSecondLeftSailors();
            saveSecondLeftState();
        }
        else if(isItHigh == false){ //Lewa dolna warstwa
            initiateLeftSailors();
            saveLeftState();
        }
    }
    else if(isItLeft == false){
        if(isItHigh == true){ //Prawa górna warstwa
            initiateSecondRightSailors();
            saveSecondRightState();
        }
        else if(isItHigh == false){ //Prawa dolna warstwa
            initiateRightSailors();
            saveRightState();
        }
    }
}

void menowawindow::initiateLeftSailors(){ //Lewa Strona; Dolna Warstwa
    LeftSailorTable[0] = ui->comboBox5->currentIndex();
    LeftSailorTable[1] = ui->comboBox4->currentIndex();
    LeftSailorTable[2] = ui->comboBox3->currentIndex();
    LeftSailorTable[3] = ui->comboBox2->currentIndex();
    LeftSailorTable[4] = ui->comboBox1->currentIndex();
    for(int i=0; i<5; i++){
        switch(LeftSailorTable[i])
        {
        case 0:
        {
            if(i == 0){
                ui->L1->setVisible(false);
            }
            if(i == 1){
                ui->L2->setVisible(false);
            }
            if(i == 2){
                ui->L3->setVisible(false);
            }
            if(i == 3){
                ui->L4->setVisible(false);
            }
            if(i == 4){
                ui->L5->setVisible(false);
            }
        }break;
        case 1:
        {
            if(i == 0){
                ui->L1->setVisible(false);
            }
            if(i == 1){
                ui->L2->setVisible(false);
            }
            if(i == 2){
                ui->L3->setVisible(false);
            }
            if(i == 3){
                ui->L4->setVisible(false);
            }
            if(i == 4){
                ui->L5->setVisible(false);
            }
        }break;
        case 2:
        {
            QPixmap L1(":/Menowa/Left/Anyballs/Down/L1/MenowaLight/SailorLeft/Down/L1/white.png");
            QPixmap L2(":/Menowa/Left/Anyballs/Down/L2/MenowaLight/SailorLeft/Down/L2/white.png");
            QPixmap L3(":/Menowa/Left/Anyballs/Down/L3/MenowaLight/SailorLeft/Down/L3/white.png");
            QPixmap L4(":/Menowa/Left/Anyballs/Down/L4/MenowaLight/SailorLeft/Down/L4/white.png");
            QPixmap L5(":/Menowa/Left/Anyballs/Down/L5/MenowaLight/SailorLeft/Down/L5/white.png");
            if(i == 0){
                ui->L1->setPixmap(L1);
                ui->L1->setVisible(true);
            }
            if(i == 1){
                ui->L2->setPixmap(L2);
                ui->L2->setVisible(true);
            }
            if(i == 2){
                ui->L3->setPixmap(L3);
                ui->L3->setVisible(true);

            }
            if(i == 3){
                ui->L4->setPixmap(L4);
                ui->L4->setVisible(true);
            }
            if(i == 4){
                ui->L5->setPixmap(L5);
                ui->L5->setVisible(true);
            }
        }break;

        case 3:
        {
            QPixmap L1(":/Menowa/Left/Anyballs/Down/L1/MenowaLight/SailorLeft/Down/L1/grey.png");
            QPixmap L2(":/Menowa/Left/Anyballs/Down/L2/MenowaLight/SailorLeft/Down/L2/grey.png");
            QPixmap L3(":/Menowa/Left/Anyballs/Down/L3/MenowaLight/SailorLeft/Down/L3/grey.png");
            QPixmap L4(":/Menowa/Left/Anyballs/Down/L4/MenowaLight/SailorLeft/Down/L4/grey.png");
            QPixmap L5(":/Menowa/Left/Anyballs/Down/L5/MenowaLight/SailorLeft/Down/L5/grey.png");
            if(i == 0){
                ui->L1->setPixmap(L1);
                ui->L1->setVisible(true);
            }
            if(i == 1){
                ui->L2->setPixmap(L2);
                ui->L2->setVisible(true);
            }
            if(i == 2){
                ui->L3->setPixmap(L3);
                ui->L3->setVisible(true);

            }
            if(i == 3){
                ui->L4->setPixmap(L4);
                ui->L4->setVisible(true);
            }
            if(i == 4){
                ui->L5->setPixmap(L5);
                ui->L5->setVisible(true);
            }
        }break;
        case 4:
        {
            QPixmap L1(":/Menowa/Left/Anyballs/Down/L1/MenowaLight/SailorLeft/Down/L1/red.png");
            QPixmap L2(":/Menowa/Left/Anyballs/Down/L2/MenowaLight/SailorLeft/Down/L2/red.png");
            QPixmap L3(":/Menowa/Left/Anyballs/Down/L3/MenowaLight/SailorLeft/Down/L3/red.png");
            QPixmap L4(":/Menowa/Left/Anyballs/Down/L4/MenowaLight/SailorLeft/Down/L4/red.png");
            QPixmap L5(":/Menowa/Left/Anyballs/Down/L5/MenowaLight/SailorLeft/Down/L5/red.png");
            if(i == 0){
                ui->L1->setPixmap(L1);
                ui->L1->setVisible(true);
            }
            if(i == 1){
                ui->L2->setPixmap(L2);
                 ui->L2->setVisible(true);
            }
            if(i == 2){
                ui->L3->setPixmap(L3);
                ui->L3->setVisible(true);
            }
            if(i == 3){
                ui->L4->setPixmap(L4);
                ui->L4->setVisible(true);
            }
            if(i == 4){
                ui->L5->setPixmap(L5);
                ui->L5->setVisible(true);
            }
        }break;
        case 5:
        {
            QPixmap L1(":/Menowa/Left/Anyballs/Down/L1/MenowaLight/SailorLeft/Down/L1/orange.png");
            QPixmap L2(":/Menowa/Left/Anyballs/Down/L2/MenowaLight/SailorLeft/Down/L2/orange.png");
            QPixmap L3(":/Menowa/Left/Anyballs/Down/L3/MenowaLight/SailorLeft/Down/L3/orange.png");
            QPixmap L4(":/Menowa/Left/Anyballs/Down/L4/MenowaLight/SailorLeft/Down/L4/orange.png");
            QPixmap L5(":/Menowa/Left/Anyballs/Down/L5/MenowaLight/SailorLeft/Down/L5/orange.png");
            if(i == 0){
                ui->L1->setPixmap(L1);
                ui->L1->setVisible(true);
            }
            if(i == 1){
                ui->L2->setPixmap(L2);
                 ui->L2->setVisible(true);
            }
            if(i == 2){
                ui->L3->setPixmap(L3);
                ui->L3->setVisible(true);
            }
            if(i == 3){
                ui->L4->setPixmap(L4);
                ui->L4->setVisible(true);
            }
            if(i == 4){
                ui->L5->setPixmap(L5);
                ui->L5->setVisible(true);
            }
        }break;
        case 6:
        {
            QPixmap L1(":/Menowa/Left/Anyballs/Down/L1/MenowaLight/SailorLeft/Down/L1/yellow.png");
            QPixmap L2(":/Menowa/Left/Anyballs/Down/L2/MenowaLight/SailorLeft/Down/L2/yellow.png");
            QPixmap L3(":/Menowa/Left/Anyballs/Down/L3/MenowaLight/SailorLeft/Down/L3/yellow.png");
            QPixmap L4(":/Menowa/Left/Anyballs/Down/L4/MenowaLight/SailorLeft/Down/L4/yellow.png");
            QPixmap L5(":/Menowa/Left/Anyballs/Down/L5/MenowaLight/SailorLeft/Down/L5/yellow.png");
            if(i == 0){
                ui->L1->setPixmap(L1);
                ui->L1->setVisible(true);
            }
            if(i == 1){
                ui->L2->setPixmap(L2);
                 ui->L2->setVisible(true);
            }
            if(i == 2){
                ui->L3->setPixmap(L3);
                ui->L3->setVisible(true);
            }
            if(i == 3){
                ui->L4->setPixmap(L4);
                ui->L4->setVisible(true);
            }
            if(i == 4){
                ui->L5->setPixmap(L5);
                ui->L5->setVisible(true);
            }
        }break;
        case 7:
        {
            QPixmap L1(":/Menowa/Left/Anyballs/Down/L1/MenowaLight/SailorLeft/Down/L1/lightgreen.png");
            QPixmap L2(":/Menowa/Left/Anyballs/Down/L2/MenowaLight/SailorLeft/Down/L2/lightgreen.png");
            QPixmap L3(":/Menowa/Left/Anyballs/Down/L3/MenowaLight/SailorLeft/Down/L3/lightgreen.png");
            QPixmap L4(":/Menowa/Left/Anyballs/Down/L4/MenowaLight/SailorLeft/Down/L4/lightgreen.png");
            QPixmap L5(":/Menowa/Left/Anyballs/Down/L5/MenowaLight/SailorLeft/Down/L5/lightgreen.png");
            if(i == 0){
                ui->L1->setPixmap(L1);
                ui->L1->setVisible(true);
            }
            if(i == 1){
                ui->L2->setPixmap(L2);
                 ui->L2->setVisible(true);
            }
            if(i == 2){
                ui->L3->setPixmap(L3);
                ui->L3->setVisible(true);
            }
            if(i == 3){
                ui->L4->setPixmap(L4);
                ui->L4->setVisible(true);
            }
            if(i == 4){
                ui->L5->setPixmap(L5);
                ui->L5->setVisible(true);
            }
        }break;
        case 8:
        {
            QPixmap L1(":/Menowa/Left/Anyballs/Down/L1/MenowaLight/SailorLeft/Down/L1/darkgreen.png");
            QPixmap L2(":/Menowa/Left/Anyballs/Down/L2/MenowaLight/SailorLeft/Down/L2/darkgreen.png");
            QPixmap L3(":/Menowa/Left/Anyballs/Down/L3/MenowaLight/SailorLeft/Down/L3/darkgreen.png");
            QPixmap L4(":/Menowa/Left/Anyballs/Down/L4/MenowaLight/SailorLeft/Down/L4/darkgreen.png");
            QPixmap L5(":/Menowa/Left/Anyballs/Down/L5/MenowaLight/SailorLeft/Down/L5/darkgreen.png");
            if(i == 0){
                ui->L1->setPixmap(L1);
                ui->L1->setVisible(true);
            }
            if(i == 1){
                ui->L2->setPixmap(L2);
                 ui->L2->setVisible(true);
            }
            if(i == 2){
                ui->L3->setPixmap(L3);
                ui->L3->setVisible(true);
            }
            if(i == 3){
                ui->L4->setPixmap(L4);
                ui->L4->setVisible(true);
            }
            if(i == 4){
                ui->L5->setPixmap(L5);
                ui->L5->setVisible(true);
            }
        }break;
        case 9:
        {
            QPixmap L1(":/Menowa/Left/Anyballs/Down/L1/MenowaLight/SailorLeft/Down/L1/skyblue.png");
            QPixmap L2(":/Menowa/Left/Anyballs/Down/L2/MenowaLight/SailorLeft/Down/L2/skyblue.png");
            QPixmap L3(":/Menowa/Left/Anyballs/Down/L3/MenowaLight/SailorLeft/Down/L3/skyblue.png");
            QPixmap L4(":/Menowa/Left/Anyballs/Down/L4/MenowaLight/SailorLeft/Down/L4/skyblue.png");
            QPixmap L5(":/Menowa/Left/Anyballs/Down/L5/MenowaLight/SailorLeft/Down/L5/skyblue.png");
            if(i == 0){
                ui->L1->setPixmap(L1);
                ui->L1->setVisible(true);
            }
            if(i == 1){
                 ui->L2->setPixmap(L2);
                 ui->L2->setVisible(true);
            }
            if(i == 2){
                ui->L3->setPixmap(L3);
                ui->L3->setVisible(true);
            }
            if(i == 3){
                ui->L4->setPixmap(L4);
                ui->L4->setVisible(true);
            }
            if(i == 4){
                ui->L5->setPixmap(L5);
                ui->L5->setVisible(true);
            }
        }break;
        case 10:
        {
            QPixmap L1(":/Menowa/Left/Anyballs/Down/L1/MenowaLight/SailorLeft/Down/L1/darkblue.png");
            QPixmap L2(":/Menowa/Left/Anyballs/Down/L2/MenowaLight/SailorLeft/Down/L2/darkblue.png");
            QPixmap L3(":/Menowa/Left/Anyballs/Down/L3/MenowaLight/SailorLeft/Down/L3/darkblue.png");
            QPixmap L4(":/Menowa/Left/Anyballs/Down/L4/MenowaLight/SailorLeft/Down/L4/darkblue.png");
            QPixmap L5(":/Menowa/Left/Anyballs/Down/L5/MenowaLight/SailorLeft/Down/L5/darkblue.png");
            if(i == 0){
                ui->L1->setPixmap(L1);
                ui->L1->setVisible(true);
            }
            if(i == 1){
                ui->L2->setPixmap(L2);
                 ui->L2->setVisible(true);
            }
            if(i == 2){
                ui->L3->setPixmap(L3);
                ui->L3->setVisible(true);
            }
            if(i == 3){
                ui->L4->setPixmap(L4);
                ui->L4->setVisible(true);
            }
            if(i == 4){
                ui->L5->setPixmap(L5);
                ui->L5->setVisible(true);
            }
        }break;
        case 11:
        {
            QPixmap L1(":/Menowa/Left/Anyballs/Down/L1/MenowaLight/SailorLeft/Down/L1/violet.png");
            QPixmap L2(":/Menowa/Left/Anyballs/Down/L2/MenowaLight/SailorLeft/Down/L2/violet.png");
            QPixmap L3(":/Menowa/Left/Anyballs/Down/L3/MenowaLight/SailorLeft/Down/L3/violet.png");
            QPixmap L4(":/Menowa/Left/Anyballs/Down/L4/MenowaLight/SailorLeft/Down/L4/violet.png");
            QPixmap L5(":/Menowa/Left/Anyballs/Down/L5/MenowaLight/SailorLeft/Down/L5/violet.png");
            if(i == 0){
                ui->L1->setPixmap(L1);
                ui->L1->setVisible(true);
            }
            if(i == 1){
                ui->L2->setPixmap(L2);
                 ui->L2->setVisible(true);
            }
            if(i == 2){
                ui->L3->setPixmap(L3);
                ui->L3->setVisible(true);
            }
            if(i == 3){
                ui->L4->setPixmap(L4);
                ui->L4->setVisible(true);
            }
            if(i == 4){
                ui->L5->setPixmap(L5);
                ui->L5->setVisible(true);
            }
        }break;
        case 12:
        {
            QPixmap L1(":/Menowa/Left/Anyballs/Down/L1/MenowaLight/SailorLeft/Down/L1/pink.png");
            QPixmap L2(":/Menowa/Left/Anyballs/Down/L2/MenowaLight/SailorLeft/Down/L2/pink.png");
            QPixmap L3(":/Menowa/Left/Anyballs/Down/L3/MenowaLight/SailorLeft/Down/L3/pink.png");
            QPixmap L4(":/Menowa/Left/Anyballs/Down/L4/MenowaLight/SailorLeft/Down/L4/pink.png");
            QPixmap L5(":/Menowa/Left/Anyballs/Down/L5/MenowaLight/SailorLeft/Down/L5/pink.png");
            if(i == 0){
                ui->L1->setPixmap(L1);
                ui->L1->setVisible(true);
            }
            if(i == 1){
                ui->L2->setPixmap(L2);
                 ui->L2->setVisible(true);
            }
            if(i == 2){
                ui->L3->setPixmap(L3);
                ui->L3->setVisible(true);
            }
            if(i == 3){
                ui->L4->setPixmap(L4);
                ui->L4->setVisible(true);
            }
            if(i == 4){
                ui->L5->setPixmap(L5);
                ui->L5->setVisible(true);
            }
        }break;
        }
    }
}

void menowawindow::initiateRightSailors(){ //Prawa Strona; Dolna Warstwa
    RightSailorTable[0] = ui->comboBox5->currentIndex();
    RightSailorTable[1] = ui->comboBox4->currentIndex();
    RightSailorTable[2] = ui->comboBox3->currentIndex();
    RightSailorTable[3] = ui->comboBox2->currentIndex();
    RightSailorTable[4] = ui->comboBox1->currentIndex();
    for(int i=0; i<5; i++){
        switch(RightSailorTable[i])
        {
        case 0:
        {
            if(i == 0){
                ui->R1->setVisible(false);
            }
            if(i == 1){
                ui->R2->setVisible(false);
            }
            if(i == 2){
                ui->R3->setVisible(false);
            }
            if(i == 3){
                ui->R4->setVisible(false);
            }
            if(i == 4){
                ui->R5->setVisible(false);
            }
        }break;
        case 1:
        {
            if(i == 0){
                ui->R1->setVisible(false);
            }
            if(i == 1){
                ui->R2->setVisible(false);
            }
            if(i == 2){
                ui->R3->setVisible(false);
            }
            if(i == 3){
                ui->R4->setVisible(false);
            }
            if(i == 4){
                ui->R5->setVisible(false);
            }
        }break;
        case 2:
        {
            QPixmap R1(":/Menowa/Right/Anyballs/Down/R1/MenowaLight/SailorRight/Down/R1/white.png");
            QPixmap R2(":/Menowa/Right/Anyballs/Down/R2/MenowaLight/SailorRight/Down/R2/white.png");
            QPixmap R3(":/Menowa/Right/Anyballs/Down/R3/MenowaLight/SailorRight/Down/R3/white.png");
            QPixmap R4(":/Menowa/Right/Anyballs/Down/R4/MenowaLight/SailorRight/Down/R4/white.png");
            QPixmap R5(":/Menowa/Right/Anyballs/Down/R5/MenowaLight/SailorRight/Down/R5/white.png");
            if(i == 0){
                ui->R1->setPixmap(R1);
                ui->R1->setVisible(true);
            }
            if(i == 1){
                ui->R2->setPixmap(R2);
                 ui->R2->setVisible(true);
            }
            if(i == 2){
                ui->R3->setPixmap(R3);
                ui->R3->setVisible(true);
            }
            if(i == 3){
                ui->R4->setPixmap(R4);
                ui->R4->setVisible(true);
            }
            if(i == 4){
                ui->R5->setPixmap(R5);
                ui->R5->setVisible(true);
            }
        }break;

        case 3:
        {
            QPixmap R1(":/Menowa/Right/Anyballs/Down/R1/MenowaLight/SailorRight/Down/R1/grey.png");
            QPixmap R2(":/Menowa/Right/Anyballs/Down/R2/MenowaLight/SailorRight/Down/R2/grey.png");
            QPixmap R3(":/Menowa/Right/Anyballs/Down/R3/MenowaLight/SailorRight/Down/R3/grey.png");
            QPixmap R4(":/Menowa/Right/Anyballs/Down/R4/MenowaLight/SailorRight/Down/R4/grey.png");
            QPixmap R5(":/Menowa/Right/Anyballs/Down/R5/MenowaLight/SailorRight/Down/R5/grey.png");
            if(i == 0){
                ui->R1->setPixmap(R1);
                ui->R1->setVisible(true);
            }
            if(i == 1){
                ui->R2->setPixmap(R2);
                 ui->R2->setVisible(true);
            }
            if(i == 2){
                ui->R3->setPixmap(R3);
                ui->R3->setVisible(true);
            }
            if(i == 3){
                ui->R4->setPixmap(R4);
                ui->R4->setVisible(true);
            }
            if(i == 4){
                ui->R5->setPixmap(R5);
                ui->R5->setVisible(true);
            }
        }break;
        case 4:
        {
            QPixmap R1(":/Menowa/Right/Anyballs/Down/R1/MenowaLight/SailorRight/Down/R1/red.png");
            QPixmap R2(":/Menowa/Right/Anyballs/Down/R2/MenowaLight/SailorRight/Down/R2/red.png");
            QPixmap R3(":/Menowa/Right/Anyballs/Down/R3/MenowaLight/SailorRight/Down/R3/red.png");
            QPixmap R4(":/Menowa/Right/Anyballs/Down/R4/MenowaLight/SailorRight/Down/R4/red.png");
            QPixmap R5(":/Menowa/Right/Anyballs/Down/R5/MenowaLight/SailorRight/Down/R5/red.png");
            if(i == 0){
                ui->R1->setPixmap(R1);
                ui->R1->setVisible(true);
            }
            if(i == 1){
                ui->R2->setPixmap(R2);
                 ui->R2->setVisible(true);
            }
            if(i == 2){
                ui->R3->setPixmap(R3);
                ui->R3->setVisible(true);
            }
            if(i == 3){
                ui->R4->setPixmap(R4);
                ui->R4->setVisible(true);
            }
            if(i == 4){
                ui->R5->setPixmap(R5);
                ui->R5->setVisible(true);
            }
        }break;
        case 5:
        {
            QPixmap R1(":/Menowa/Right/Anyballs/Down/R1/MenowaLight/SailorRight/Down/R1/orange.png");
            QPixmap R2(":/Menowa/Right/Anyballs/Down/R2/MenowaLight/SailorRight/Down/R2/orange.png");
            QPixmap R3(":/Menowa/Right/Anyballs/Down/R3/MenowaLight/SailorRight/Down/R3/orange.png");
            QPixmap R4(":/Menowa/Right/Anyballs/Down/R4/MenowaLight/SailorRight/Down/R4/orange.png");
            QPixmap R5(":/Menowa/Right/Anyballs/Down/R5/MenowaLight/SailorRight/Down/R5/orange.png");
            if(i == 0){
                ui->R1->setPixmap(R1);
                ui->R1->setVisible(true);
            }
            if(i == 1){
                ui->R2->setPixmap(R2);
                 ui->R2->setVisible(true);
            }
            if(i == 2){
                ui->R3->setPixmap(R3);
                ui->R3->setVisible(true);
            }
            if(i == 3){
                ui->R4->setPixmap(R4);
                ui->R4->setVisible(true);
            }
            if(i == 4){
                ui->R5->setPixmap(R5);
                ui->R5->setVisible(true);
            }
        }break;
        case 6:
        {
            QPixmap R1(":/Menowa/Right/Anyballs/Down/R1/MenowaLight/SailorRight/Down/R1/yellow.png");
            QPixmap R2(":/Menowa/Right/Anyballs/Down/R2/MenowaLight/SailorRight/Down/R2/yellow.png");
            QPixmap R3(":/Menowa/Right/Anyballs/Down/R3/MenowaLight/SailorRight/Down/R3/yellow.png");
            QPixmap R4(":/Menowa/Right/Anyballs/Down/R4/MenowaLight/SailorRight/Down/R4/yellow.png");
            QPixmap R5(":/Menowa/Right/Anyballs/Down/R5/MenowaLight/SailorRight/Down/R5/yellow.png");
            if(i == 0){
                ui->R1->setPixmap(R1);
                ui->R1->setVisible(true);
            }
            if(i == 1){
                ui->R2->setPixmap(R2);
                 ui->R2->setVisible(true);
            }
            if(i == 2){
                ui->R3->setPixmap(R3);
                ui->R3->setVisible(true);
            }
            if(i == 3){
                ui->R4->setPixmap(R4);
                ui->R4->setVisible(true);
            }
            if(i == 4){
                ui->R5->setPixmap(R5);
                ui->R5->setVisible(true);
            }
        }break;
        case 7:
        {
            QPixmap R1(":/Menowa/Right/Anyballs/Down/R1/MenowaLight/SailorRight/Down/R1/lightgreen.png");
            QPixmap R2(":/Menowa/Right/Anyballs/Down/R2/MenowaLight/SailorRight/Down/R2/lightgreen.png");
            QPixmap R3(":/Menowa/Right/Anyballs/Down/R3/MenowaLight/SailorRight/Down/R3/lightgreen.png");
            QPixmap R4(":/Menowa/Right/Anyballs/Down/R4/MenowaLight/SailorRight/Down/R4/lightgreen.png");
            QPixmap R5(":/Menowa/Right/Anyballs/Down/R5/MenowaLight/SailorRight/Down/R5/lightgreen.png");
            if(i == 0){
                ui->R1->setPixmap(R1);
                ui->R1->setVisible(true);
            }
            if(i == 1){
                ui->R2->setPixmap(R2);
                 ui->R2->setVisible(true);
            }
            if(i == 2){
                ui->R3->setPixmap(R3);
                ui->R3->setVisible(true);
            }
            if(i == 3){
                ui->R4->setPixmap(R4);
                ui->R4->setVisible(true);
            }
            if(i == 4){
                ui->R5->setPixmap(R5);
                ui->R5->setVisible(true);
            }
        }break;
        case 8:
        {
            QPixmap R1(":/Menowa/Right/Anyballs/Down/R1/MenowaLight/SailorRight/Down/R1/darkgreen.png");
            QPixmap R2(":/Menowa/Right/Anyballs/Down/R2/MenowaLight/SailorRight/Down/R2/darkgreen.png");
            QPixmap R3(":/Menowa/Right/Anyballs/Down/R3/MenowaLight/SailorRight/Down/R3/darkgreen.png");
            QPixmap R4(":/Menowa/Right/Anyballs/Down/R4/MenowaLight/SailorRight/Down/R4/darkgreen.png");
            QPixmap R5(":/Menowa/Right/Anyballs/Down/R5/MenowaLight/SailorRight/Down/R5/darkgreen.png");
            if(i == 0){
                ui->R1->setPixmap(R1);
                ui->R1->setVisible(true);
            }
            if(i == 1){
                ui->R2->setPixmap(R2);
                 ui->R2->setVisible(true);
            }
            if(i == 2){
                ui->R3->setPixmap(R3);
                ui->R3->setVisible(true);
            }
            if(i == 3){
                ui->R4->setPixmap(R4);
                ui->R4->setVisible(true);
            }
            if(i == 4){
                ui->R5->setPixmap(R5);
                ui->R5->setVisible(true);
            }
        }break;
        case 9:
        {
            QPixmap R1(":/Menowa/Right/Anyballs/Down/R1/MenowaLight/SailorRight/Down/R1/skyblue.png");
            QPixmap R2(":/Menowa/Right/Anyballs/Down/R2/MenowaLight/SailorRight/Down/R2/skyblue.png");
            QPixmap R3(":/Menowa/Right/Anyballs/Down/R3/MenowaLight/SailorRight/Down/R3/skyblue.png");
            QPixmap R4(":/Menowa/Right/Anyballs/Down/R4/MenowaLight/SailorRight/Down/R4/skyblue.png");
            QPixmap R5(":/Menowa/Right/Anyballs/Down/R5/MenowaLight/SailorRight/Down/R5/skyblue.png");
            if(i == 0){
                ui->R1->setPixmap(R1);
                ui->R1->setVisible(true);
            }
            if(i == 1){
                 ui->R2->setPixmap(R2);
                 ui->R2->setVisible(true);
            }
            if(i == 2){
                ui->R3->setPixmap(R3);
                ui->R3->setVisible(true);
            }
            if(i == 3){
                ui->R4->setPixmap(R4);
                ui->R4->setVisible(true);
            }
            if(i == 4){
                ui->R5->setPixmap(R5);
                ui->R5->setVisible(true);
            }
        }break;
        case 10:
        {
            QPixmap R1(":/Menowa/Right/Anyballs/Down/R1/MenowaLight/SailorRight/Down/R1/darkblue.png");
            QPixmap R2(":/Menowa/Right/Anyballs/Down/R2/MenowaLight/SailorRight/Down/R2/darkblue.png");
            QPixmap R3(":/Menowa/Right/Anyballs/Down/R3/MenowaLight/SailorRight/Down/R3/darkblue.png");
            QPixmap R4(":/Menowa/Right/Anyballs/Down/R4/MenowaLight/SailorRight/Down/R4/darkblue.png");
            QPixmap R5(":/Menowa/Right/Anyballs/Down/R5/MenowaLight/SailorRight/Down/R5/darkblue.png");
            if(i == 0){
                ui->R1->setPixmap(R1);
                ui->R1->setVisible(true);
            }
            if(i == 1){
                ui->R2->setPixmap(R2);
                 ui->R2->setVisible(true);
            }
            if(i == 2){
                ui->R3->setPixmap(R3);
                ui->R3->setVisible(true);
            }
            if(i == 3){
                ui->R4->setPixmap(R4);
                ui->R4->setVisible(true);
            }
            if(i == 4){
                ui->R5->setPixmap(R5);
                ui->R5->setVisible(true);
            }
        }break;
        case 11:
        {
            QPixmap R1(":/Menowa/Right/Anyballs/Down/R1/MenowaLight/SailorRight/Down/R1/violet.png");
            QPixmap R2(":/Menowa/Right/Anyballs/Down/R2/MenowaLight/SailorRight/Down/R2/violet.png");
            QPixmap R3(":/Menowa/Right/Anyballs/Down/R3/MenowaLight/SailorRight/Down/R3/violet.png");
            QPixmap R4(":/Menowa/Right/Anyballs/Down/R4/MenowaLight/SailorRight/Down/R4/violet.png");
            QPixmap R5(":/Menowa/Right/Anyballs/Down/R5/MenowaLight/SailorRight/Down/R5/violet.png");
            if(i == 0){
                ui->R1->setPixmap(R1);
                ui->R1->setVisible(true);
            }
            if(i == 1){
                ui->R2->setPixmap(R2);
                 ui->R2->setVisible(true);
            }
            if(i == 2){
                ui->R3->setPixmap(R3);
                ui->R3->setVisible(true);
            }
            if(i == 3){
                ui->R4->setPixmap(R4);
                ui->R4->setVisible(true);
            }
            if(i == 4){
                ui->R5->setPixmap(R5);
                ui->R5->setVisible(true);
            }
        }break;
        case 12:
        {
            QPixmap R1(":/Menowa/Right/Anyballs/Down/R1/MenowaLight/SailorRight/Down/R1/pink.png");
            QPixmap R2(":/Menowa/Right/Anyballs/Down/R2/MenowaLight/SailorRight/Down/R2/pink.png");
            QPixmap R3(":/Menowa/Right/Anyballs/Down/R3/MenowaLight/SailorRight/Down/R3/pink.png");
            QPixmap R4(":/Menowa/Right/Anyballs/Down/R4/MenowaLight/SailorRight/Down/R4/pink.png");
            QPixmap R5(":/Menowa/Right/Anyballs/Down/R5/MenowaLight/SailorRight/Down/R5/pink.png");
            if(i == 0){
                ui->R1->setPixmap(R1);
                ui->R1->setVisible(true);
            }
            if(i == 1){
                ui->R2->setPixmap(R2);
                 ui->R2->setVisible(true);
            }
            if(i == 2){
                ui->R3->setPixmap(R3);
                ui->R3->setVisible(true);
            }
            if(i == 3){
                ui->R4->setPixmap(R4);
                ui->R4->setVisible(true);
            }
            if(i == 4){
                ui->R5->setPixmap(R5);
                ui->R5->setVisible(true);
            }
        }break;
        }
    }
}

void menowawindow::initiateSecondLeftSailors(){ //Lewa Strona; Górna Warstwa
    LeftSecondSailorTable[0] = ui->comboBox4->currentIndex();
    LeftSecondSailorTable[1] = ui->comboBox3->currentIndex();
    //LeftSecondSailorTable[2] = ui->comboBox2->currentIndex();
    LeftSecondSailorTable[2] = 0;
    LeftSecondSailorTable[3] = ui->comboBox1->currentIndex();
    for(int i=0; i<4; i++){
        switch(LeftSecondSailorTable[i])
        {
        case 0:
        {
            if(i == 0){
                ui->SL1->setVisible(false);
            }
            if(i == 1){
                ui->SL2->setVisible(false);
            }
            if(i == 2){
                ui->SL3->setVisible(false);
            }
            if(i == 3){
                ui->SL4->setVisible(false);
            }
        }break;
        case 1:
        {
            QPixmap SL1(":/Menowa/Left/Anyballs/Up/SL1/MenowaLight/SailorLeft/Up/SL1/black.png");
            QPixmap SL3(":/Menowa/Left/Anyballs/Up/SL3/MenowaLight/SailorLeft/Up/SL3/black.png");
            QPixmap SL4(":/Menowa/Left/Anyballs/Up/SL4/MenowaLight/SailorLeft/Up/SL4/black.png");
            if(i == 0){
                ui->SL1->setPixmap(SL1);
                ui->SL1->setVisible(true);
            }
            if(i == 1){
                 ui->SL2->setVisible(false);
            }
            if(i == 2){
                ui->SL3->setPixmap(SL3);
                ui->SL3->setVisible(true);
            }
            if(i == 3){
                ui->SL4->setPixmap(SL4);
                ui->SL4->setVisible(true);
            }


        }break;
        case 2:
        {

            QPixmap SL1(":/Menowa/Left/Anyballs/Up/SL1/MenowaLight/SailorLeft/Up/SL1/white.png");
            QPixmap SL2(":/Menowa/Left/Anyballs/Up/SL2/MenowaLight/SailorLeft/Up/SL2/white.png");
            QPixmap SL3(":/Menowa/Left/Anyballs/Up/SL3/MenowaLight/SailorLeft/Up/SL3/white.png");
            QPixmap SL4(":/Menowa/Left/Anyballs/Up/SL4/MenowaLight/SailorLeft/Up/SL4/white.png");
            if(i == 0){
                ui->SL1->setPixmap(SL1);
                ui->SL1->setVisible(true);
            }
            if(i == 1){
                ui->SL2->setPixmap(SL2);
                 ui->SL2->setVisible(true);
            }
            if(i == 2){
                ui->SL3->setPixmap(SL3);
                ui->SL3->setVisible(true);
            }
            if(i == 3){
                ui->SL4->setPixmap(SL4);
                ui->SL4->setVisible(true);
            }

        }break;

        case 3:
        {
            QPixmap SL1(":/Menowa/Left/Anyballs/Up/SL1/MenowaLight/SailorLeft/Up/SL1/grey.png");
            QPixmap SL2(":/Menowa/Left/Anyballs/Up/SL2/MenowaLight/SailorLeft/Up/SL2/grey.png");
            QPixmap SL3(":/Menowa/Left/Anyballs/Up/SL3/MenowaLight/SailorLeft/Up/SL3/grey.png");
            QPixmap SL4(":/Menowa/Left/Anyballs/Up/SL4/MenowaLight/SailorLeft/Up/SL4/grey.png");
            if(i == 0){
                ui->SL1->setPixmap(SL1);
                ui->SL1->setVisible(true);
            }
            if(i == 1){
                ui->SL2->setPixmap(SL2);
                 ui->SL2->setVisible(true);
            }
            if(i == 2){
                ui->SL3->setPixmap(SL3);
                ui->SL3->setVisible(true);
            }
            if(i == 3){
                ui->SL4->setPixmap(SL4);
                ui->SL4->setVisible(true);
            }
        }break;
        case 4:
        {
            QPixmap SL1(":/Menowa/Left/Anyballs/Up/SL1/MenowaLight/SailorLeft/Up/SL1/red.png");
            QPixmap SL2(":/Menowa/Left/Anyballs/Up/SL2/MenowaLight/SailorLeft/Up/SL2/red.png");
            QPixmap SL3(":/Menowa/Left/Anyballs/Up/SL3/MenowaLight/SailorLeft/Up/SL3/red.png");
            QPixmap SL4(":/Menowa/Left/Anyballs/Up/SL4/MenowaLight/SailorLeft/Up/SL4/red.png");
            if(i == 0){
                ui->SL1->setPixmap(SL1);
                ui->SL1->setVisible(true);
            }
            if(i == 1){
                ui->SL2->setPixmap(SL2);
                 ui->SL2->setVisible(true);
            }
            if(i == 2){
                ui->SL3->setPixmap(SL3);
                ui->SL3->setVisible(true);
            }
            if(i == 3){
                ui->SL4->setPixmap(SL4);
                ui->SL4->setVisible(true);
            }

        }break;
        case 5:
        {
            QPixmap SL1(":/Menowa/Left/Anyballs/Up/SL1/MenowaLight/SailorLeft/Up/SL1/orange.png");
            QPixmap SL2(":/Menowa/Left/Anyballs/Up/SL2/MenowaLight/SailorLeft/Up/SL2/orange.png");
            QPixmap SL3(":/Menowa/Left/Anyballs/Up/SL3/MenowaLight/SailorLeft/Up/SL3/orange.png");
            QPixmap SL4(":/Menowa/Left/Anyballs/Up/SL4/MenowaLight/SailorLeft/Up/SL4/orange.png");
            if(i == 0){
                ui->SL1->setPixmap(SL1);
                ui->SL1->setVisible(true);
            }
            if(i == 1){
                ui->SL2->setPixmap(SL2);
                 ui->SL2->setVisible(true);
            }
            if(i == 2){
                ui->SL3->setPixmap(SL3);
                ui->SL3->setVisible(true);
            }
            if(i == 3){
                ui->SL4->setPixmap(SL4);
                ui->SL4->setVisible(true);
            }

        }break;
        case 6:
        {
            QPixmap SL1(":/Menowa/Left/Anyballs/Up/SL1/MenowaLight/SailorLeft/Up/SL1/yellow.png");
            QPixmap SL2(":/Menowa/Left/Anyballs/Up/SL2/MenowaLight/SailorLeft/Up/SL2/yellow.png");
            QPixmap SL3(":/Menowa/Left/Anyballs/Up/SL3/MenowaLight/SailorLeft/Up/SL3/yellow.png");
            QPixmap SL4(":/Menowa/Left/Anyballs/Up/SL4/MenowaLight/SailorLeft/Up/SL4/yellow.png");
            if(i == 0){
                ui->SL1->setPixmap(SL1);
                ui->SL1->setVisible(true);
            }
            if(i == 1){
                ui->SL2->setPixmap(SL2);
                 ui->SL2->setVisible(true);
            }
            if(i == 2){
                ui->SL3->setPixmap(SL3);
                ui->SL3->setVisible(true);
            }
            if(i == 3){
                ui->SL4->setPixmap(SL4);
                ui->SL4->setVisible(true);
            }

        }break;
        case 7:
        {
            QPixmap SL1(":/Menowa/Left/Anyballs/Up/SL1/MenowaLight/SailorLeft/Up/SL1/lightgreen.png");
            QPixmap SL2(":/Menowa/Left/Anyballs/Up/SL2/MenowaLight/SailorLeft/Up/SL2/lightgreen.png");
            QPixmap SL3(":/Menowa/Left/Anyballs/Up/SL3/MenowaLight/SailorLeft/Up/SL3/lightgreen.png");
            QPixmap SL4(":/Menowa/Left/Anyballs/Up/SL4/MenowaLight/SailorLeft/Up/SL4/lightgreen.png");
            if(i == 0){
                ui->SL1->setPixmap(SL1);
                ui->SL1->setVisible(true);
            }
            if(i == 1){
                ui->SL2->setPixmap(SL2);
                 ui->SL2->setVisible(true);
            }
            if(i == 2){
                ui->SL3->setPixmap(SL3);
                ui->SL3->setVisible(true);
            }
            if(i == 3){
                ui->SL4->setPixmap(SL4);
                ui->SL4->setVisible(true);
            }

        }break;
        case 8:
        {
            QPixmap SL1(":/Menowa/Left/Anyballs/Up/SL1/MenowaLight/SailorLeft/Up/SL1/darkgreen.png");
            QPixmap SL2(":/Menowa/Left/Anyballs/Up/SL2/MenowaLight/SailorLeft/Up/SL2/darkgreen.png");
            QPixmap SL3(":/Menowa/Left/Anyballs/Up/SL3/MenowaLight/SailorLeft/Up/SL3/darkgreen.png");
            QPixmap SL4(":/Menowa/Left/Anyballs/Up/SL4/MenowaLight/SailorLeft/Up/SL4/darkgreen.png");
            if(i == 0){
                ui->SL1->setPixmap(SL1);
                ui->SL1->setVisible(true);
            }
            if(i == 1){
                ui->SL2->setPixmap(SL2);
                 ui->SL2->setVisible(true);
            }
            if(i == 2){
                ui->SL3->setPixmap(SL3);
                ui->SL3->setVisible(true);
            }
            if(i == 3){
                ui->SL4->setPixmap(SL4);
                ui->SL4->setVisible(true);
            }

        }break;
        case 9:
        {
            QPixmap SL2(":/Menowa/Left/Anyballs/Up/SL2/MenowaLight/SailorLeft/Up/SL2/skyblue.png");
            if(i == 0){
                ui->SL1->setVisible(false);
            }
            if(i == 1){
                 ui->SL2->setPixmap(SL2);
                 ui->SL2->setVisible(true);
            }
            if(i == 2){
                ui->SL3->setVisible(false);
            }
            if(i == 3){
                ui->SL4->setVisible(false);
            }

        }break;
        case 10:
        {
            QPixmap SL1(":/Menowa/Left/Anyballs/Up/SL1/MenowaLight/SailorLeft/Up/SL1/darkblue.png");
            QPixmap SL2(":/Menowa/Left/Anyballs/Up/SL2/MenowaLight/SailorLeft/Up/SL2/darkblue.png");
            QPixmap SL3(":/Menowa/Left/Anyballs/Up/SL3/MenowaLight/SailorLeft/Up/SL3/darkblue.png");
            QPixmap SL4(":/Menowa/Left/Anyballs/Up/SL4/MenowaLight/SailorLeft/Up/SL4/darkblue.png");
            if(i == 0){
                ui->SL1->setPixmap(SL1);
                ui->SL1->setVisible(true);
            }
            if(i == 1){
                ui->SL2->setPixmap(SL2);
                 ui->SL2->setVisible(true);
            }
            if(i == 2){
                ui->SL3->setPixmap(SL3);
                ui->SL3->setVisible(true);
            }
            if(i == 3){
                ui->SL4->setPixmap(SL4);
                ui->SL4->setVisible(true);
            }

        }break;
        case 11:
        {
            QPixmap SL1(":/Menowa/Left/Anyballs/Up/SL1/MenowaLight/SailorLeft/Up/SL1/violet.png");
            QPixmap SL2(":/Menowa/Left/Anyballs/Up/SL2/MenowaLight/SailorLeft/Up/SL2/violet.png");
            QPixmap SL3(":/Menowa/Left/Anyballs/Up/SL3/MenowaLight/SailorLeft/Up/SL3/violet.png");
            QPixmap SL4(":/Menowa/Left/Anyballs/Up/SL4/MenowaLight/SailorLeft/Up/SL4/violet.png");
            if(i == 0){
                ui->SL1->setPixmap(SL1);
                ui->SL1->setVisible(true);
            }
            if(i == 1){
                ui->SL2->setPixmap(SL2);
                 ui->SL2->setVisible(true);
            }
            if(i == 2){
                ui->SL3->setPixmap(SL3);
                ui->SL3->setVisible(true);
            }
            if(i == 3){
                ui->SL4->setPixmap(SL4);
                ui->SL4->setVisible(true);
            }

        }break;
        case 12:
        {
            QPixmap SL1(":/Menowa/Left/Anyballs/Up/SL1/MenowaLight/SailorLeft/Up/SL1/pink.png");
            QPixmap SL2(":/Menowa/Left/Anyballs/Up/SL2/MenowaLight/SailorLeft/Up/SL2/pink.png");
            QPixmap SL3(":/Menowa/Left/Anyballs/Up/SL3/MenowaLight/SailorLeft/Up/SL3/pink.png");
            QPixmap SL4(":/Menowa/Left/Anyballs/Up/SL4/MenowaLight/SailorLeft/Up/SL4/pink.png");
            if(i == 0){
                ui->SL1->setPixmap(SL1);
                ui->SL1->setVisible(true);
            }
            if(i == 1){
                ui->SL2->setPixmap(SL2);
                 ui->SL2->setVisible(true);
            }
            if(i == 2){
                ui->SL3->setPixmap(SL3);
                ui->SL3->setVisible(true);
            }
            if(i == 3){
                ui->SL4->setPixmap(SL4);
                ui->SL4->setVisible(true);
            }

        }break;
        }
    }
}

void menowawindow::initiateSecondRightSailors(){ //Prawa Strona; Górna Warstwa
    RightSecondSailorTable[0] = ui->comboBox4->currentIndex();
    RightSecondSailorTable[1] = ui->comboBox3->currentIndex();
    //RightSecondSailorTable[2] = ui->comboBox2->currentIndex();
    RightSecondSailorTable[2] = 0;
    RightSecondSailorTable[3] = ui->comboBox1->currentIndex();
    for(int i=0; i<4; i++){
        switch(RightSecondSailorTable[i])
        {
        case 0:
        {
            if(i == 0){
                ui->SR1->setVisible(false);
            }
            if(i == 1){
                ui->SR2->setVisible(false);
            }
            if(i == 2){
                ui->SR3->setVisible(false);
            }
            if(i == 3){
                ui->SR4->setVisible(false);
            }
        }break;
        case 1:
        {
            QPixmap SR1(":/Menowa/Right/Anyballs/Up/SR1/MenowaLight/SailorRight/Up/SR1/black.png");
            QPixmap SR3(":/Menowa/Right/Anyballs/Up/SR3/MenowaLight/SailorRight/Up/SR3/black.png");
            QPixmap SR4(":/Menowa/Right/Anyballs/Up/SR4/MenowaLight/SailorRight/Up/SR4/black.png");
            if(i == 0){
                ui->SR1->setPixmap(SR1);
                ui->SR1->setVisible(true);
            }
            if(i == 1){
                 ui->SR2->setVisible(false);
            }
            if(i == 2){
                ui->SR3->setPixmap(SR3);
                ui->SR3->setVisible(true);
            }
            if(i == 3){
                ui->SR4->setPixmap(SR4);
                ui->SR4->setVisible(true);
            }


        }break;
        case 2:
        {
            QPixmap SR1(":/Menowa/Right/Anyballs/Up/SR1/MenowaLight/SailorRight/Up/SR1/white.png");
            QPixmap SR2(":/Menowa/Right/Anyballs/Up/SR2/MenowaLight/SailorRight/Up/SR2/white.png");
            QPixmap SR3(":/Menowa/Right/Anyballs/Up/SR3/MenowaLight/SailorRight/Up/SR3/white.png");
            QPixmap SR4(":/Menowa/Right/Anyballs/Up/SR4/MenowaLight/SailorRight/Up/SR4/white.png");
            if(i == 0){
                ui->SR1->setPixmap(SR1);
                ui->SR1->setVisible(true);
            }
            if(i == 1){
                ui->SR2->setPixmap(SR2);
                 ui->SR2->setVisible(true);
            }
            if(i == 2){
                ui->SR3->setPixmap(SR3);
                ui->SR3->setVisible(true);
            }
            if(i == 3){
                ui->SR4->setPixmap(SR4);
                ui->SR4->setVisible(true);
            }

        }break;

        case 3:
        {
            QPixmap SR1(":/Menowa/Right/Anyballs/Up/SR1/MenowaLight/SailorRight/Up/SR1/grey.png");
            QPixmap SR2(":/Menowa/Right/Anyballs/Up/SR2/MenowaLight/SailorRight/Up/SR2/grey.png");
            QPixmap SR3(":/Menowa/Right/Anyballs/Up/SR3/MenowaLight/SailorRight/Up/SR3/grey.png");
            QPixmap SR4(":/Menowa/Right/Anyballs/Up/SR4/MenowaLight/SailorRight/Up/SR4/grey.png");
            if(i == 0){
                ui->SR1->setPixmap(SR1);
                ui->SR1->setVisible(true);
            }
            if(i == 1){
                ui->SR2->setPixmap(SR2);
                 ui->SR2->setVisible(true);
            }
            if(i == 2){
                ui->SR3->setPixmap(SR3);
                ui->SR3->setVisible(true);
            }
            if(i == 3){
                ui->SR4->setPixmap(SR4);
                ui->SR4->setVisible(true);
            }


        }break;
        case 4:
        {
            QPixmap SR1(":/Menowa/Right/Anyballs/Up/SR1/MenowaLight/SailorRight/Up/SR1/red.png");
            QPixmap SR2(":/Menowa/Right/Anyballs/Up/SR2/MenowaLight/SailorRight/Up/SR2/red.png");
            QPixmap SR3(":/Menowa/Right/Anyballs/Up/SR3/MenowaLight/SailorRight/Up/SR3/red.png");
            QPixmap SR4(":/Menowa/Right/Anyballs/Up/SR4/MenowaLight/SailorRight/Up/SR4/red.png");
            if(i == 0){
                ui->SR1->setPixmap(SR1);
                ui->SR1->setVisible(true);
            }
            if(i == 1){
                ui->SR2->setPixmap(SR2);
                 ui->SR2->setVisible(true);
            }
            if(i == 2){
                ui->SR3->setPixmap(SR3);
                ui->SR3->setVisible(true);
            }
            if(i == 3){
                ui->SR4->setPixmap(SR4);
                ui->SR4->setVisible(true);
            }

        }break;
        case 5:
        {
            QPixmap SR1(":/Menowa/Right/Anyballs/Up/SR1/MenowaLight/SailorRight/Up/SR1/orange.png");
            QPixmap SR2(":/Menowa/Right/Anyballs/Up/SR2/MenowaLight/SailorRight/Up/SR2/orange.png");
            QPixmap SR3(":/Menowa/Right/Anyballs/Up/SR3/MenowaLight/SailorRight/Up/SR3/orange.png");
            QPixmap SR4(":/Menowa/Right/Anyballs/Up/SR4/MenowaLight/SailorRight/Up/SR4/orange.png");
            if(i == 0){
                ui->SR1->setPixmap(SR1);
                ui->SR1->setVisible(true);
            }
            if(i == 1){
                ui->SR2->setPixmap(SR2);
                 ui->SR2->setVisible(true);
            }
            if(i == 2){
                ui->SR3->setPixmap(SR3);
                ui->SR3->setVisible(true);
            }
            if(i == 3){
                ui->SR4->setPixmap(SR4);
                ui->SR4->setVisible(true);
            }

        }break;
        case 6:
        {
            QPixmap SR1(":/Menowa/Right/Anyballs/Up/SR1/MenowaLight/SailorRight/Up/SR1/yellow.png");
            QPixmap SR2(":/Menowa/Right/Anyballs/Up/SR2/MenowaLight/SailorRight/Up/SR2/yellow.png");
            QPixmap SR3(":/Menowa/Right/Anyballs/Up/SR3/MenowaLight/SailorRight/Up/SR3/yellow.png");
            QPixmap SR4(":/Menowa/Right/Anyballs/Up/SR4/MenowaLight/SailorRight/Up/SR4/yellow.png");
            if(i == 0){
                ui->SR1->setPixmap(SR1);
                ui->SR1->setVisible(true);
            }
            if(i == 1){
                ui->SR2->setPixmap(SR2);
                 ui->SR2->setVisible(true);
            }
            if(i == 2){
                ui->SR3->setPixmap(SR3);
                ui->SR3->setVisible(true);
            }
            if(i == 3){
                ui->SR4->setPixmap(SR4);
                ui->SR4->setVisible(true);
            }

        }break;
        case 7:
        {
            QPixmap SR1(":/Menowa/Right/Anyballs/Up/SR1/MenowaLight/SailorRight/Up/SR1/lightgreen.png");
            QPixmap SR2(":/Menowa/Right/Anyballs/Up/SR2/MenowaLight/SailorRight/Up/SR2/lightgreen.png");
            QPixmap SR3(":/Menowa/Right/Anyballs/Up/SR3/MenowaLight/SailorRight/Up/SR3/lightgreen.png");
            QPixmap SR4(":/Menowa/Right/Anyballs/Up/SR4/MenowaLight/SailorRight/Up/SR4/lightgreen.png");
            if(i == 0){
                ui->SR1->setPixmap(SR1);
                ui->SR1->setVisible(true);
            }
            if(i == 1){
                ui->SR2->setPixmap(SR2);
                 ui->SR2->setVisible(true);
            }
            if(i == 2){
                ui->SR3->setPixmap(SR3);
                ui->SR3->setVisible(true);
            }
            if(i == 3){
                ui->SR4->setPixmap(SR4);
                ui->SR4->setVisible(true);
            }

        }break;
        case 8:
        {
            QPixmap SR1(":/Menowa/Right/Anyballs/Up/SR1/MenowaLight/SailorRight/Up/SR1/darkgreen.png");
            QPixmap SR2(":/Menowa/Right/Anyballs/Up/SR2/MenowaLight/SailorRight/Up/SR2/darkgreen.png");
            QPixmap SR3(":/Menowa/Right/Anyballs/Up/SR3/MenowaLight/SailorRight/Up/SR3/darkgreen.png");
            QPixmap SR4(":/Menowa/Right/Anyballs/Up/SR4/MenowaLight/SailorRight/Up/SR4/darkgreen.png");
            if(i == 0){
                ui->SR1->setPixmap(SR1);
                ui->SR1->setVisible(true);
            }
            if(i == 1){
                ui->SR2->setPixmap(SR2);
                 ui->SR2->setVisible(true);
            }
            if(i == 2){
                ui->SR3->setPixmap(SR3);
                ui->SR3->setVisible(true);
            }
            if(i == 3){
                ui->SR4->setPixmap(SR4);
                ui->SR4->setVisible(true);
            }

        }break;
        case 9:
        {
            QPixmap SR1(":/Menowa/Right/Anyballs/Up/SR1/MenowaLight/SailorRight/Up/SR1/skyblue.png");
            QPixmap SR2(":/Menowa/Right/Anyballs/Up/SR2/MenowaLight/SailorRight/Up/SR2/skyblue.png");
            QPixmap SR3(":/Menowa/Right/Anyballs/Up/SR3/MenowaLight/SailorRight/Up/SR3/skyblue.png");
            QPixmap SR4(":/Menowa/Right/Anyballs/Up/SR4/MenowaLight/SailorRight/Up/SR4/skyblue.png");
            if(i == 0){
                ui->SR1->setPixmap(SR1);
                ui->SR1->setVisible(true);
            }
            if(i == 1){
                 ui->SR2->setPixmap(SR2);
                 ui->SR2->setVisible(true);
            }
            if(i == 2){
                ui->SR3->setPixmap(SR3);
                ui->SR3->setVisible(true);
            }
            if(i == 3){
                ui->SR4->setPixmap(SR4);
                ui->SR4->setVisible(true);
            }

        }break;
        case 10:
        {
            QPixmap SR1(":/Menowa/Right/Anyballs/Up/SR1/MenowaLight/SailorRight/Up/SR1/darkblue.png");
            QPixmap SR2(":/Menowa/Right/Anyballs/Up/SR2/MenowaLight/SailorRight/Up/SR2/darkblue.png");
            QPixmap SR3(":/Menowa/Right/Anyballs/Up/SR3/MenowaLight/SailorRight/Up/SR3/darkblue.png");
            QPixmap SR4(":/Menowa/Right/Anyballs/Up/SR4/MenowaLight/SailorRight/Up/SR4/darkblue.png");
            if(i == 0){
                ui->SR1->setPixmap(SR1);
                ui->SR1->setVisible(true);
            }
            if(i == 1){
                ui->SR2->setPixmap(SR2);
                 ui->SR2->setVisible(true);
            }
            if(i == 2){
                ui->SR3->setPixmap(SR3);
                ui->SR3->setVisible(true);
            }
            if(i == 3){
                ui->SR4->setPixmap(SR4);
                ui->SR4->setVisible(true);
            }

        }break;
        case 11:
        {
            QPixmap SR1(":/Menowa/Right/Anyballs/Up/SR1/MenowaLight/SailorRight/Up/SR1/violet.png");
            QPixmap SR2(":/Menowa/Right/Anyballs/Up/SR2/MenowaLight/SailorRight/Up/SR2/violet.png");
            QPixmap SR3(":/Menowa/Right/Anyballs/Up/SR3/MenowaLight/SailorRight/Up/SR3/violet.png");
            QPixmap SR4(":/Menowa/Right/Anyballs/Up/SR4/MenowaLight/SailorRight/Up/SR4/violet.png");
            if(i == 0){
                ui->SR1->setPixmap(SR1);
                ui->SR1->setVisible(true);
            }
            if(i == 1){
                ui->SR2->setPixmap(SR2);
                 ui->SR2->setVisible(true);
            }
            if(i == 2){
                ui->SR3->setPixmap(SR3);
                ui->SR3->setVisible(true);
            }
            if(i == 3){
                ui->SR4->setPixmap(SR4);
                ui->SR4->setVisible(true);
            }

        }break;
        case 12:
        {
            QPixmap SR2(":/Menowa/Right/Anyballs/Up/SR2/MenowaLight/SailorRight/Up/SR2/pink.png");
            if(i == 0){
                ui->SR1->setVisible(false);
            }
            if(i == 1){
                 ui->SR2->setPixmap(SR2);
                 ui->SR2->setVisible(true);
            }
            if(i == 2){
                ui->SR3->setVisible(false);
            }
            if(i == 3){
                ui->SR4->setVisible(false);
            }

        }break;
        }
    }
}

void menowawindow::on_save_6_released()
{
    /*Programisto! Jeżeli edytujesz ten program który jest pod licencją MIT, bardzo proszę, nie usuwaj poniższej linijki o prawdziwych autorach aplikacji, oraz tego komentarza, Dziękuję!*/
    /*Programmer! If You are editing this code, remember that this app is under MIT licence, that mean you shouldn't remove any information about real app author, and this comment either. Thank You!*/
    if(isItPolish == true){
    QMessageBox::information(this,"Autorzy","<h2>Penspinning - Make your mod</h2><br>Kod źródłowy oraz grafiki zostały stworzone przez:<br> <strong>Artur Koniec  <a href='http://ariteku.pl'>Ariteku.pl</a></strong><br><br>Ogromne podziękowania dla testerów aplikacji za ich wsparcie!<br><br><b>Zabraniam kopiowania i rozpowszechniania użytych w aplikacji grafik!</b>");
    }else{
    QMessageBox::information(this,"Authors","<h2>Penspinning - Make your mod</h2><br>Source code and graphic has been created by:<br> <strong>Artur Koniec  <a href='http://ariteku.pl'>Ariteku.pl</a></strong><br><br>Special Thanks for app tester for their support!<br><br><b>I do not allow to copy the graphics used in app!</b>");
    }
}

void menowawindow::on_save_4_released()
{
    if(isItPolish == true){
    QMessageBox::about(this,"Licencje","<ul><li>Aplikacja ta została napisana w języku C++ za pomocą środowiska Qt Creator.</li><li>Aplikacja używa licencji MIT.</li><li>Kod źródłowy na GitHubie znajduję się pod <a href='https://github.com/AritekuDev/PenspinningMakeYourMod'>tym</a> linkiem.</li></ul>");
    }else{
    QMessageBox::about(this,"Licence","<ul><li>This applciation has been written in C++ language using Qt Creator IDE.</li><li>Application use MIT licence.</li><li>Source code of app is available on github under <a href='https://github.com/AritekuDev/PenspinningMakeYourMod'>this</a> link.</li></ul>");
    }}
void menowawindow::on_LeftSideRB_released()
{
    isItLeft = true;
    if(isItPolish){
    ui->whatAreYouEditing->setText("Edytujesz: Lewą");
    }else{
    ui->whatAreYouEditing->setText("Editing: Left");
    }
    setSavedStates();
}

void menowawindow::on_HighLayerRB_released()
{
   isItHigh = true;
   ui->comboBox5->setVisible(false);
   ui->comboBox2->setVisible(false);
   ui->label_15->setVisible(false);
   ui->label_12->setVisible(false);
   if(isItPolish){
   ui->label_11->setText("Pierwszy + Drugi");
   ui->whatAreYouEditing_2->setText("górną warstwe gripów");
   }else{
       ui->label_11->setText("First + Second");
       ui->whatAreYouEditing_2->setText("higher layer of grips");
   }
   setSavedStates();
}

void menowawindow::on_RightSideRB_released()
{
    isItLeft = false;
    if(isItPolish){
        ui->whatAreYouEditing->setText("Edytujesz: Prawą");
    }else{
        ui->whatAreYouEditing->setText("Editing: Right");
    }
    setSavedStates();
}

void menowawindow::on_LowLayerRB_released()
{
    isItHigh = false;
    ui->comboBox5->setVisible(true);
    ui->comboBox2->setVisible(true);
    ui->label_15->setVisible(true);
    ui->label_12->setVisible(true);
    if(isItPolish){
    ui->whatAreYouEditing_2->setText(" dolną warstwe gripów");
    ui->label_11->setText("Pierwszy");
    }else{
        ui->whatAreYouEditing_2->setText(" lower layer of grip");
        ui->label_11->setText("First");
    }
    setSavedStates();
}

void menowawindow::on_save_2_released()
{
    if(isSailorMenuVisible == false){
        isSailorMenuVisible = true;
        ui->GroupBoxSailors->setVisible(true);
    }
    else if(isSailorMenuVisible == true){
        isSailorMenuVisible = false;
        ui->GroupBoxSailors->setVisible(false);
    }
}

void menowawindow::on_save_5_released()
{
if(isItPolish){
    QMessageBox::information(
    this,
    "Części do light Menowa* mod"
    ,"<h2>Części do twojej modyfikacji</h2><br><b style='text-align: center'>Light Menowa Mod</b><ul><li>Crayola Supertips Body (x2)</li><li>Color Twin Cap (x2)</li><li>Dr.Grip Tip (x2)</li><li>Crayola Supertips Connector (x1)</li><li>Anyball Profile Grip (min. x2 (Zależy od ilości kolorów))</li></ul>"
    );
}else{
    QMessageBox::information(
    this,
    "Parts for light Menowa* mod"
    ,"<h2>Parts needed for Light Menowa* Mod</h2><br><b style='text-align: center'>Light Menowa Mod</b><ul><li>Crayola Supertips Body (x2)</li><li>Color Twin Cap (x2)</li><li>Dr.Grip Tip (x2)</li><li>Crayola Supertips Connector (x1)</li><li>Anyball Profile Grip (min. x2 (Depend of used colors))</li></ul>"
    );

}
}

void menowawindow::on_save_released()
{
    if(isItPolish){
    QMessageBox::information(this,"Ta opcja będzie dostępna wkrótce!","Ta opcja będzie dostępna wkrótce!");}
    else{
    QMessageBox::information(this,"Coming Soon!","Coming Soon!");
    }
}

void menowawindow::on_open_released()
{
    if(isItPolish){
    QMessageBox::information(this,"Ta opcja będzie dostępna wkrótce!","Ta opcja będzie dostępna wkrótce!");}
    else{
    QMessageBox::information(this,"Coming Soon!","Coming Soon!");
    }
}

void menowawindow::on_language_released()
{
   changeLanguage();
}

void menowawindow::on_WaterfallSwitch_released()
{
    hide();
    MainWindow *mainWindow = new MainWindow();
    mainWindow->show();
}

void menowawindow::on_checkBox_released()
{
    if(isConnectorWhite == true){
        ui->part_connector->setVisible(false);
        isConnectorWhite = false;
    }
    else if(isConnectorWhite == false){
        QPixmap connect(":/Menowa/MenowaLight/connector.png");
        ui->part_connector->setPixmap(connect);
        ui->part_connector->setVisible(true);
        isConnectorWhite = true;
    }
}

void menowawindow::on_warning_released()
{
    QMessageBox about;
    about.setWindowTitle("Uwaga!");
    about.setText("");
    about.setInformativeText("");
    about.setStandardButtons(QMessageBox::Ok);
    about.setIconPixmap(QPixmap(":/Menowa/MenowaLight/alert.png"));
    about.setDefaultButton(QMessageBox::Ok);
    about.show();
    about.exec();
}

void menowawindow::on_toolButton_released()
{
    if(isCheckboxesON == false){
        ui->LeftSideRB->setVisible(true);
        ui->RightSideRB->setVisible(true);
        ui->HighLayerRB->setVisible(true);
        ui->LowLayerRB->setVisible(true);
        ui->LeftSideButton->setVisible(false);
        ui->RightSideButton->setVisible(false);
        ui->HighLayerButton->setVisible(false);
        ui->LowLayerButton->setVisible(false);
        isCheckboxesON = true;
    }
    else if(isCheckboxesON == true){
        ui->LeftSideRB->setVisible(false);
        ui->RightSideRB->setVisible(false);
        ui->HighLayerRB->setVisible(false);
        ui->LowLayerRB->setVisible(false);
        ui->LeftSideButton->setVisible(true);
        ui->RightSideButton->setVisible(true);
        ui->HighLayerButton->setVisible(true);
        ui->LowLayerButton->setVisible(true);
        isCheckboxesON = false;
    }
}

void menowawindow::on_Switch_2_released()
{
    hide();
    busterwindow BusterWindow;
    BusterWindow.setModal(true);
    BusterWindow.exec();
}

void menowawindow::on_save_3_released()
{
    /*Programisto! Jeżeli edytujesz ten program który jest pod licencją MIT, bardzo proszę, nie usuwaj poniższej linijki o prawdziwych autorach aplikacji, oraz tego komentarza, Dziękuję!*/
    /*Programmer! If You are editing this code, remember that this app is under MIT licence, that mean you shouldn't remove any information about real app author, and this comment either. Thank You!*/
    if(isItPolish == true){
    QMessageBox::about(this,"Kontakt z deweloperem","<h4>Znalazłeś błąd w aplikacji?</h4>Jeżeli znalazłeś jakiekolwiek błędy w aplikacji, bardzo proszę, zgłoś je do mnie na email:<br><b>aritekudev@gmail.com</b><br><h3>Poszukuje grafika do aplikacji!</h3>Jak widzisz, grafiki w aplikacji nie są zbyt dobre. Jeżeli jesteś grafikiem 2D, możesz przyczynić się do tworzenia tej aplikacji, proszę, skontaktuj się ze mną na adres:<br><strong>aritekudev@gmail.com</strong>");
    }else{
    QMessageBox::about(this,"Contact with developer","<h4>Is something wrong in app?</h4>If you found any kind of mistakes in application, please, report them to me at:<br><b>aritekudev@gmail.com</b><br><h3>I'm looking for a graphic designer for app!</h3>As you can see, these graphics of pens aren't really good. If You are 2D graphic designer, we can make this app together. Please contact with me at:<br><strong>aritekudev@gmail.com</strong>");
    }}

void menowawindow::on_LeftSideButton_released()
{
    isItLeft = true;
    ui->LeftSideButton->setDisabled(true);
    ui->RightSideButton->setDisabled(false);
    if(isItPolish == true){
    ui->whatAreYouEditing->setText("Edytujesz: Lewą");
    }else{
        ui->whatAreYouEditing->setText("Editing: Left");
    }
    setSavedStates();
}

void menowawindow::on_RightSideButton_released()
{
    isItLeft = false;
    ui->LeftSideButton->setDisabled(false);
    ui->RightSideButton->setDisabled(true);
    if(isItPolish == true){
    ui->whatAreYouEditing->setText("Edytujesz: Prawą");
    }else{
        ui->whatAreYouEditing->setText("Editing: Right");
    }
    setSavedStates();
}

void menowawindow::on_HighLayerButton_released()
{
    isItHigh = true;
    ui->comboBox5->setVisible(false);
    ui->comboBox2->setVisible(false);
    ui->label_15->setVisible(false);
    ui->label_12->setVisible(false);
    if(isItPolish == true){
    ui->label_11->setText("Pierwszy + Drugi");
    ui->whatAreYouEditing_2->setText("górną warstwe gripów");
    }else{
        ui->label_11->setText("First + Second");
        ui->whatAreYouEditing_2->setText("higher layer of grips");
    }
    ui->HighLayerButton->setDisabled(true);
    ui->LowLayerButton->setDisabled(false);
    setSavedStates();
}

void menowawindow::on_LowLayerButton_released()
{
    isItHigh = false;
    ui->comboBox5->setVisible(true);
    ui->comboBox2->setVisible(true);
    ui->label_15->setVisible(true);
    ui->label_12->setVisible(true);
    if(isItPolish == true){
    ui->whatAreYouEditing_2->setText(" dolną warstwe gripów");
    ui->label_11->setText("Pierwszy");
    }else{
        ui->whatAreYouEditing_2->setText(" lower level of grips");
        ui->label_11->setText("First");
    }
    ui->HighLayerButton->setDisabled(false);
    ui->LowLayerButton->setDisabled(true);
    setSavedStates();
}
void menowawindow::changeLanguage()
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
     ui->save_3->setText("Contact");
     ui->save_4->setText("Licence");
     ui->save_6->setText("Authors");
     ui->LeftSideButton->setText("Left Side");
     ui->RightSideButton->setText("Right Side");
     ui->HighLayerButton->setText("High Layer");
     ui->LowLayerButton->setText("Low Layer");
     ui->LeftSideRB->setText("Left Side");
     ui->RightSideRB->setText("Right Side");
     ui->HighLayerRB->setText("High Layer");
     ui->LowLayerRB->setText("Low Layer");
     ui->label_12->setText("Second");
     ui->label_13->setText("Third");
     ui->label_14->setText("Fourth");
     ui->label_15->setText("Fifth");
     ui->sailorSubmit->setText("Submit");
     ui->pushButton_2->setText("Check for updates");
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
     if(isItLeftSailor == true){
         ui->whatAreYouEditing->setText("Editing: Left");
     }else{
         ui->whatAreYouEditing->setText("Editing: Right");
     }
     if(isItHigh == true){
         ui->whatAreYouEditing_2->setText(" higher layer of grips");
     }else{
         ui->whatAreYouEditing_2->setText(" lower layer of grips");
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
     ui->save_3->setText("Kontakt");
     ui->save_4->setText("Licencje");
     ui->save_6->setText("Autorzy");
     ui->LeftSideButton->setText("Lewa Strona");
     ui->RightSideButton->setText("Prawa Strona");
     ui->HighLayerButton->setText("Górna Warstwa");
     ui->LowLayerButton->setText("Dolna Warstwa");
     ui->LeftSideRB->setText("Lewa Strona");
     ui->RightSideRB->setText("Prawa Strona");
     ui->HighLayerRB->setText("Górna Warstwa");
     ui->LowLayerRB->setText("Dolna Warstwa");
     ui->label_12->setText("Drugi");
     ui->label_13->setText("Trzeci");
     ui->label_14->setText("Czwarty");
     ui->label_15->setText("Piąty");
     ui->sailorSubmit->setText("Zatwierdź");
     ui->pushButton_2->setText("Sprawdź aktualizacje");
     updateComboBoxes();
     if(PartState == 1){
         ui->LabelEdit->setText("Edytujesz: BODY");
         ui->groupBox->setTitle("Lewe Body");
         ui->groupBox_2->setTitle("Prawe Body");
     }
     else if(PartState == 2){
         ui->LabelEdit->setText("Edytujesz: CAPS");
         ui->groupBox->setTitle("Lewy Cap");
         ui->groupBox_2->setTitle("Prawy Cap");
     }
     else if(PartState == 3){
         ui->LabelEdit->setText("Użyj kompozycji<br>anyballi");
         ui->groupBox->setTitle("Lewy Grip");
         ui->groupBox_2->setTitle("Prawy Grip");
     }
     if(isItLeftSailor == true){
         ui->whatAreYouEditing->setText("Edytujesz: Lewą");
     }else{
         ui->whatAreYouEditing->setText("Edytujesz: Prawą");
     }
     if(isItHigh == true){
         ui->whatAreYouEditing_2->setText(" górną warstwę gripów");
     }else{
         ui->whatAreYouEditing_2->setText(" dolną warstwę gripów");
     }
     isItPolish = true;
    }
}

void menowawindow::on_pushButton_2_released()
{
    QString dirApp = qApp->applicationDirPath();
    QString dirFile = dirApp+"/maintenancetool.exe";
    QDesktopServices::openUrl(QUrl("file:///"+dirFile));
    QApplication::quit();
}
void menowawindow::saveSecondLeftState(){
    LeftHighStates[0] = ui->comboBox1->currentIndex();
    LeftHighStates[2] = ui->comboBox3->currentIndex();
    LeftHighStates[3] = ui->comboBox4->currentIndex();
}
void menowawindow::saveSecondRightState(){
    RightHighStates[0] = ui->comboBox1->currentIndex();
    RightHighStates[2] = ui->comboBox3->currentIndex();
    RightHighStates[3] = ui->comboBox4->currentIndex();
}
void menowawindow::saveLeftState(){
    LeftDownStates[0] = ui->comboBox1->currentIndex();
    LeftDownStates[1] = ui->comboBox2->currentIndex();
    LeftDownStates[2] = ui->comboBox3->currentIndex();
    LeftDownStates[3] = ui->comboBox4->currentIndex();
    LeftDownStates[4] = ui->comboBox5->currentIndex();
}
void menowawindow::saveRightState(){
    RightDownStates[0] = ui->comboBox1->currentIndex();
    RightDownStates[1] = ui->comboBox2->currentIndex();
    RightDownStates[2] = ui->comboBox3->currentIndex();
    RightDownStates[3] = ui->comboBox4->currentIndex();
    RightDownStates[4] = ui->comboBox5->currentIndex();
}
void menowawindow::readSecondLeftState(){
    ui->comboBox1->setCurrentIndex(LeftHighStates[0]);
    ui->comboBox3->setCurrentIndex(LeftHighStates[2]);
    ui->comboBox4->setCurrentIndex(LeftHighStates[3]);
}
void menowawindow::readSecondRightState(){
    ui->comboBox1->setCurrentIndex(RightHighStates[0]);
    ui->comboBox3->setCurrentIndex(RightHighStates[2]);
    ui->comboBox4->setCurrentIndex(RightHighStates[3]);
}
void menowawindow::readLeftState(){
    ui->comboBox1->setCurrentIndex(LeftDownStates[0]);
    ui->comboBox2->setCurrentIndex(LeftDownStates[1]);
    ui->comboBox3->setCurrentIndex(LeftDownStates[2]);
    ui->comboBox4->setCurrentIndex(LeftDownStates[3]);
    ui->comboBox5->setCurrentIndex(LeftDownStates[4]);
}
void menowawindow::readRightState(){
    ui->comboBox1->setCurrentIndex(RightDownStates[0]);
    ui->comboBox2->setCurrentIndex(RightDownStates[1]);
    ui->comboBox3->setCurrentIndex(RightDownStates[2]);
    ui->comboBox4->setCurrentIndex(RightDownStates[3]);
    ui->comboBox5->setCurrentIndex(RightDownStates[4]);
}
void menowawindow::setSavedStates(){
    if(isItLeft == true){
        if(isItHigh == true){
            readSecondLeftState();
        }else{
            readLeftState();
        }
    }
    else if(isItLeft == false){
        if(isItHigh == true){
            readSecondRightState();
        }else{
            readRightState();
        }
    }
}













/**/
