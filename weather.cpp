#include "weather.h"

#include <QJsonDocument>
#include <QJsonObject>

Weather::Weather(QObject *parent) : QObject(parent),
                        network_manager_(new QNetworkAccessManager(this))
{
    connect(network_manager_, &QNetworkAccessManager::finished, this,
                            &Weather::on_network_reply_finished);
}

void Weather::fetch_temperature(const QString & city)
{
    QString url = QString("https://api.openweathermap.org/data/2.5/weather?q=%1&appid=%2").arg(city, api_key_);

    QNetworkRequest request({QUrl(url)});
    network_manager_->get(request);
}

void Weather::on_network_reply_finished(QNetworkReply* reply)
{
    if (reply->error() == QNetworkReply::NoError)
    {
        QByteArray responseData = reply->readAll();
        QJsonDocument jsonDoc(QJsonDocument::fromJson(responseData));
        QJsonObject jsonObj = jsonDoc.object();

        QJsonObject mainObj = jsonObj["main"].toObject();
        double temperature = mainObj["temp"].toDouble();
        temperature -= 273.15;

        emit temp_fetched(temperature);
    }
    else
    {
        emit error_occurred(reply->errorString());
    }
    reply->deleteLater();
}
