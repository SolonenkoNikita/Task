#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QColor>
#include <QPushButton>
#include <QApplication>
#include <QFile>
#include <QXmlStreamReader>
#include <QVBoxLayout>
#include <QWidget>
#include <QDebug>
#include <QTimer>

#include <vector>

#include "random.h"
#include "timer.h"
#include "weather.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(const QString&, QWidget *parent = nullptr);

    ~MainWindow();

private slots:

    void on_button_click(size_t);

    void update_timer();

    void on_temp_fetched(double);

    void on_error_occurred(const QString&);

private:

    void help_for_button(size_t);

    void init_values();

    void init_buttons();

    void initialization_colors();

    bool check_values(int) const;

    void change_color_text();

    void setupConnections();

private:

    const int second_ = 1000;

    const size_t buttons_size_ = 9;

    const size_t min_id = 0;

    const size_t max_id = 9;

    const size_t sizes_ = 10;

    size_t counter_ = 0;

    std::vector<QPushButton*> buttons_;

    std::vector<int> values_;

    std::vector<std::pair<QString, QColor>> colors_ =
    {
        { QString("white"), Qt::white},
        { QString("black"), Qt::black },
        { QString("brown"), QColor(165, 42, 42) },
        { QString("blue"),  Qt::blue },
        { QString("cyan"),  Qt::cyan },
        { QString("red"),   Qt::red },
        { QString("yellow"), Qt::yellow },
        { QString("green"),  Qt::green },
        { QString("gray"),  Qt::gray },
        { QString("pink"),  Qt::magenta }
    };

    Random random_;

    Timer timer_;

    QTimer* timer_qt_;

    Weather* weather_;

    Ui::MainWindow *ui;
};

#endif
