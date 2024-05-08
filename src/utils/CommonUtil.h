#ifndef COMMONUTIL_H
#define COMMONUTIL_H

#include <QObject>
#include <QUrl>
#include <QDesktopServices>

#include <QThread>
#include <QProcess>

#ifdef Q_OS_WIN
#include <windows.h>
//#include <qt_windows.h>
#endif
#ifdef Q_OS_MAC
#import <Cocoa/Cocoa.h>
#endif


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
        QKeySequence sequence = QKeySequence::Paste;
        QGuiApplication::postEvent(QGuiApplication::focusObject(), new QKeyEvent(QEvent::KeyPress, sequence[0], Qt::NoModifier));
        QGuiApplication::postEvent(QGuiApplication::focusObject(), new QKeyEvent(QEvent::KeyRelease, sequence[0], Qt::NoModifier));
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
        QKeySequence copySequence = QKeySequence::Copy; // Command + C
        int key = copySequence[0]; // 获取组合键
        // 发送按下和释放事件
        QGuiApplication::postEvent(QGuiApplication::focusObject(), new QKeyEvent(QEvent::KeyPress, key, Qt::MetaModifier));
        QGuiApplication::postEvent(QGuiApplication::focusObject(), new QKeyEvent(QEvent::KeyRelease, key, Qt::MetaModifier));
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
