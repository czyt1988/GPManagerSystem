#include "MoistureMeterWatcher.h"
#include "ui_MoistureMeterWatcher.h"

MoistureMeterWatcher::MoistureMeterWatcher(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::MoistureMeterWatcher)
{
    ui->setupUi(this);
}

MoistureMeterWatcher::~MoistureMeterWatcher()
{
    delete ui;
}

