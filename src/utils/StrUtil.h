#ifndef STRUTIL_H
#define STRUTIL_H

#include <QObject>
#include <QDebug>
#include <QJsonDocument>
#include <QJsonObject>

class StrUtil : public QObject
{
    Q_OBJECT
public:
    explicit StrUtil(QObject *parent = nullptr);
    static QJsonObject byteArrayToJsonObject(const QByteArray &byteArray)
    {
        // 将 QByteArray 转换为 QJsonDocument
        QJsonDocument jsonDoc = QJsonDocument::fromJson(byteArray);

        // 检查是否转换成功
        if (!jsonDoc.isNull() && jsonDoc.isObject()) {
            // 将 QJsonDocument 转换为 QJsonObject 并返回
            return jsonDoc.object();
        } else {
            qDebug() << "Failed to parse JSON.";
            // 如果转换失败，返回一个空的 QJsonObject
            return QJsonObject();
        }
    }
    /**
     * @brief convertTimeToSeconds 时间字符串转换成秒
     * @param timeStr
     * @return
     */
    static double convertTimeToSeconds(QString *timeStr) {
        QTime time = QTime::fromString(*timeStr, "hh:mm:ss.zzz");
        int hoursToSeconds = time.hour() * 3600;
        int minutesToSeconds = time.minute() * 60;
        int seconds = time.second();
        int milliseconds = time.msec();
        return hoursToSeconds + minutesToSeconds + seconds + milliseconds / 1000.0;
    }

signals:

};

#endif // STRUTIL_H
