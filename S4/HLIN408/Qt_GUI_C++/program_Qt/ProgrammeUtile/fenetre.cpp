#include "fenetre.h"
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QLabel>
#include <QSpacerItem>
#include <QPainter>
#include <QDebug>
#include <QCloseEvent>

Fenetre::Fenetre(QWidget *parent) : QWidget(parent)
{
    //----------------------- CONFIGURATION DE LA FENETRE ----------------------//

    setWindowTitle("AF794PTE3GCMHAGHPR3V"); // C'est un code pour une loot box H1Z1 (vraiment)
    setFixedSize(600, 250); // Ne soyez pas fixé sur vos position, ouvrez votre esprit
    setWindowFlags(Qt::WindowTitleHint); //Enlever la croix, comme Christian :)

    //--------------------------- CREATION DE BOUTON ---------------------------//

    // #1 Instancier les deux boutons quitter et appuyer
    appuyer = new QPushButton("HIT", this);
    quitter = new QPushButton("Quitter", this);

    // #2 Rendre le bouton quitter non-cliquable
    quitter->setEnabled(false);

    //-------------------------- BARRE DE PROGRESSION --------------------------//
    bar = new QProgressBar(this); // Elle ira plus vite que votre connexion internet du crous
    bar->setRange(bar->x(), 588);
    bar->setTextVisible(false); // On enlève les pourcents c'est laid

    //------------------------------ LES LAYOUTS ------------------------------//
    QVBoxLayout* vL = new QVBoxLayout(this); // Tu préfères à la vertical...
    QHBoxLayout* hL = new QHBoxLayout(this); // ou à l'horizontal ?

    //------------------------------ LES WIDGETS ------------------------------//

    hL->addWidget(new QLabel("Appuyez pour arrêter la barre au bon endroit :"));

    hL->addWidget(appuyer);
    vL->addLayout(hL);

    vL->addWidget(bar);
    QHBoxLayout* hL2 = new QHBoxLayout(this); // Vous êtes tous beaux dans l'amphi... Sauf deux personnes là au fond.

    hL2->addStretch();
    hL2->addWidget(quitter);
    vL->addLayout(hL2);
    setLayout(vL); // Il y en a un qui est très beau, mais je ne peux pas dire qui. ❤

    timer = new QTimer(this); // Ils abusent vraiment avec la lettre Q, non ?
    timer->setInterval(1); // 1ms, le ping que tu n'auras jamais

    //----------------------------- SIGNAL & SLOT ----------------------------//

    // #5 Connecter le timer et les deux boutons
    connect(timer , SIGNAL(timeout()), this, SLOT(timeout()));
    connect(appuyer , SIGNAL(pressed()), this, SLOT(buttonPushed()));
    connect(quitter , SIGNAL(pressed()), this, SLOT(close()));
    timer->start(); // Allez, c'est parti mon kiki !
}

void Fenetre::timeout() {
   if(bar->value() >= bar->maximum()-2) bar->setValue(bar->minimum());
   bar->setValue(bar->value()+2);
}

void Fenetre::buttonPushed() {
    appuyer->setEnabled(false);
    timer->stop();
    if(bar->value() >= 450 && bar->value() <= 490) quitter->setEnabled(true);
    else QTimer::singleShot(1000, this, SLOT(antispam()));
}

void Fenetre::antispam() {
    appuyer->setEnabled(true);
    timer->start();
}

void Fenetre::closeEvent(QCloseEvent *e) {
    if(!quitter->isEnabled()) e->ignore();
}

void Fenetre::paintEvent(QPaintEvent *) {
    QPainter p(this);
    p.setBrush(QBrush(Qt::red));
    p.drawRect(450, bar->y()-10, 40, 40);
}
