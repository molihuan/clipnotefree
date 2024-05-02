#ifndef COMMONUTIL_H
#define COMMONUTIL_H

#include <QObject>
#include <QUrl>
#include <QDesktopServices>
#include <qt_windows.h>
#include <QThread>
#include <QProcess>


class CommonUtil : public QObject
{
    Q_OBJECT
public:
    explicit CommonUtil(QObject *parent = nullptr);
    static bool openUrl(QString url){
//        QUrl url("https://www.yuque.com/zhangyewuxianxiaozhang/ghzwdl/befieqdxi16hbhix");
        return QDesktopServices::openUrl(QUrl(url));
    }

    /**
     * @brief simulateCtrlV 模拟Ctrl+V
     */
    static void simulateCtrlV(){
#ifdef Q_OS_WIN
        INPUT inputs[4] = {};
        inputs[0].type = INPUT_KEYBOARD;
        inputs[0].ki.wVk = VK_RCONTROL;
        inputs[1].type = INPUT_KEYBOARD;
        inputs[1].ki.wVk = 'V';
        inputs[2].type = INPUT_KEYBOARD;
        inputs[2].ki.wVk = 'V';
        inputs[2].ki.dwFlags = KEYEVENTF_KEYUP;
        inputs[3].type = INPUT_KEYBOARD;
        inputs[3].ki.wVk = VK_RCONTROL;
        inputs[3].ki.dwFlags = KEYEVENTF_KEYUP;
        SendInput(1, &inputs[0], sizeof(INPUT));
        QThread::msleep(100);
        SendInput(1, &inputs[1], sizeof(INPUT));
        SendInput(1, &inputs[2], sizeof(INPUT));
        SendInput(1, &inputs[3], sizeof(INPUT));
#endif
#ifdef Q_OS_MAC
#endif
    }
    /**
     * @brief simulateCtrlC 模拟Ctrl+C
     */
    static void simulateCtrlC(){
#ifdef Q_OS_WIN
        INPUT inputs[4] = {};
        inputs[0].type = INPUT_KEYBOARD;
        inputs[0].ki.wVk = VK_RCONTROL;
        inputs[1].type = INPUT_KEYBOARD;
        inputs[1].ki.wVk = 'C';
        inputs[2].type = INPUT_KEYBOARD;
        inputs[2].ki.wVk = 'C';
        inputs[2].ki.dwFlags = KEYEVENTF_KEYUP;
        inputs[3].type = INPUT_KEYBOARD;
        inputs[3].ki.wVk = VK_RCONTROL;
        inputs[3].ki.dwFlags = KEYEVENTF_KEYUP;
        SendInput(1, &inputs[0], sizeof(INPUT));
        QThread::msleep(100);
        SendInput(1, &inputs[1], sizeof(INPUT));
        SendInput(1, &inputs[2], sizeof(INPUT));
        SendInput(1, &inputs[3], sizeof(INPUT));
#endif
#ifdef Q_OS_MAC
#endif
    }

    /**
     * @brief isProcessRunning 判断进程是否正在运行
     * @param processName
     * @return
     */
    static bool isProcessRunning(QString processName){
        QProcess process;
#ifdef Q_OS_WIN
        process.start("tasklist");
#else
        process.start("pgrep", QStringList() << processName);
#endif
        process.waitForFinished();
        QString output = process.readAllStandardOutput();
        return output.toLower().contains(processName);
    }

signals:

};

#endif // COMMONUTIL_H
