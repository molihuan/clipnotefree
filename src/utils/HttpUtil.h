#ifndef HTTPUTIL_H
#define HTTPUTIL_H

#include <QObject>
#include <QUrl>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QEventLoop>
#include <QUrlQuery>
#include <QDebug>
#include <QJsonDocument>
#include <QJsonObject>

class HttpUtil : public QObject
{
    Q_OBJECT
public:
    explicit HttpUtil(QObject *parent = nullptr);

    // 发送GET请求
    void get(const QString &url, const QMap<QString, QString> &params)
    {

        QNetworkAccessManager* manager= new QNetworkAccessManager();

        QUrl requestUrl(url);
        QUrlQuery query;
        for (auto it = params.constBegin(); it != params.constEnd(); ++it)
        {
            query.addQueryItem(it.key(), it.value());
        }
        requestUrl.setQuery(query);

        QNetworkRequest request(requestUrl);


        QNetworkReply *reply = manager->get(request);

        connect(reply, &QNetworkReply::finished,this, [=]() {
            handleReply(reply);
        });
    }


    // 发送POST请求
    void post(const QString &url, const QJsonObject &data)
    {
        post(url,QJsonDocument(data));
    }
    // 发送POST请求
    void post(const QString &url, const QJsonDocument &data)
    {
        post(url,data.toJson());
    }
    // 发送POST请求
    void post(const QString &url, const QString &data)
    {
        post(url,data.toUtf8());
    }
    // 发送POST请求
    void post(const QString &url, const QByteArray &data)
    {
        QNetworkAccessManager* manager= new QNetworkAccessManager();

        QNetworkRequest request(url);
        request.setHeader(QNetworkRequest::ContentTypeHeader, "application/x-www-form-urlencoded");

        QNetworkReply *reply = manager->post(request, data);

        connect(reply, &QNetworkReply::finished,this, [=]() {
            handleReply(reply);
        });
    }

signals:
     void finished(const QByteArray &data);

private:
    // 静态方法内部调用的处理响应函数
    void handleReply(QNetworkReply *reply)
    {
        if (reply->error() == QNetworkReply::NoError)
        {
            QByteArray responseData = reply->readAll();
//            qDebug() << "Response:" << responseData;
            emit finished(responseData); // 发射自定义信号
        }
        else
        {
            qDebug() << "Error:" << reply->errorString();
        }

        reply->deleteLater();
    }


};

#endif // HTTPUTIL_H
