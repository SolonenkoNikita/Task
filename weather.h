#ifndef WEATHER_H
#define WEATHER_H

#include <QObject>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QUrlQuery>

class Weather : public QObject
{
    Q_OBJECT

public:
    explicit Weather(QObject *parent = nullptr);

    void fetch_temperature(const QString&);

signals:
    void temp_fetched(double);

    void error_occurred(const QString&);

private slots:
    void on_network_reply_finished(QNetworkReply*);

private:
    QNetworkAccessManager* network_manager_;

    const QString api_key_ = "926c10ba2f5817e59cec8acaaab51ffc";
};

#endif
