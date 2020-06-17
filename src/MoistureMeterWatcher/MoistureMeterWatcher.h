#ifndef MOISTUREMETERWATCHER_H
#define MOISTUREMETERWATCHER_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class MoistureMeterWatcher; }
QT_END_NAMESPACE

class MoistureMeterWatcher : public QWidget
{
    Q_OBJECT

public:
    MoistureMeterWatcher(QWidget *parent = nullptr);
    ~MoistureMeterWatcher();

private:
    Ui::MoistureMeterWatcher *ui;
};
#endif // MOISTUREMETERWATCHER_H
