#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(const QString& str, QWidget *parent)
    : QMainWindow(parent), random_(), timer_(), timer_qt_(new QTimer(this)),
    weather_(new Weather(this))
    , ui(new Ui::MainWindow)
{

    init_values();

    ui->setupUi(this);

    ui->label->setText(std::move(QString("Counter: %1").arg(counter_)));
    ui->label2->setText(timer_.get_time());

    connect(timer_qt_, &QTimer::timeout, this, &MainWindow::update_timer);
    timer_qt_->start(second_);

    init_buttons();
    initialization_colors();
    change_color_text();

    setupConnections();

    weather_->fetch_temperature(str);
}

void MainWindow::init_values()
{
    while(values_.size() < sizes_)
    {
        int value = random_.generate(min_id, max_id);
        bool val = check_values(value);
        if(!val)
            values_.push_back(value);
    }
}

void MainWindow::update_timer()
{
    ui->label2->setText(timer_.get_time());
    this->update();
}

bool MainWindow::check_values(int value) const
{
    bool val = false;
    for(size_t i = 0, j = values_.size(); i < j; ++i)
    {
        if(value == values_[i])
            val = true;
    }
    return val;
}

void MainWindow::help_for_button(size_t ind)
{
    auto g = colors_[values_[ind]];
    buttons_[ind]->setText(std::move(g.first));
    QString s = "background-color:" + g.second.name() + ";";
    buttons_[ind]->setStyleSheet(std::move(s));
}

void MainWindow::on_button_click(size_t ind)
{
    std::swap(values_[ind], values_[sizes_ - 1]);
    help_for_button(ind);
    ++counter_;
    ui->label->setText(std::move(QString("Counter: %1").arg(counter_)));
    change_color_text();
}

void MainWindow::init_buttons()
{
    for(size_t i = 0; i < buttons_size_; ++i)
    {
        QPushButton* button = findChild<QPushButton*>(QString("square%1").arg(i + 1));
        button->setFixedSize(75, 75);
        if (button)
        {
            buttons_.push_back(button);
            connect(button, &QPushButton::clicked, this, [=]()
            {
                on_button_click(i);
            });
        }
    }
}

void MainWindow::change_color_text()
{
    for(size_t i = 0; i < buttons_size_; ++i)
    {
        auto g = colors_[values_[sizes_ - 1]];
        QPalette palette = buttons_[i]->palette();
        palette.setColor(QPalette::ButtonText, std::move(g.second));
        buttons_[i]->setPalette(std::move(palette));
    }
}

void MainWindow::initialization_colors()
{
    for(size_t i = 0; i < buttons_size_; ++i)
    {
        help_for_button(i);
    }
}

void MainWindow::setupConnections()
{
    connect(weather_, &Weather::temp_fetched, this, &MainWindow::on_temp_fetched);
    connect(weather_, &Weather::error_occurred, this, &MainWindow::on_error_occurred);
}

void MainWindow::on_temp_fetched(double temperature)
{
    ui->temp_label->setText(std::move(QString("Temperature: %1 °C").arg(temperature)));
}

void MainWindow::on_error_occurred(const QString& errorString)
{
    qDebug() << "Network Error:" << errorString;
    ui->temp_label->setText(std::move("Error fetching temperature!"));
}

MainWindow::~MainWindow()
{
    delete ui;
    delete timer_qt_;
    delete weather_;
}
