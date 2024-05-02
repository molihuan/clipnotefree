#include "HttpUtil.h"
#include "src/include/Constants.h"



HttpUtil::HttpUtil(QObject *parent)
    : QObject{parent}
{

}

//QString httpGet(QString link){
//    QUrl url(localHost+link);
//    QNetworkRequest request(url);
//    QNetworkReply *reply = networkManager->get(request);
//    QByteArray responseData;
//    QEventLoop loop;
//    QObject::connect(reply, &QNetworkReply::finished, &loop, &QEventLoop::quit);
//    loop.exec();
//    if (reply->error() == QNetworkReply::NoError) {
//        responseData = reply->readAll();
//    }
//    reply->deleteLater();
//    return QString::fromUtf8(responseData);
//}
