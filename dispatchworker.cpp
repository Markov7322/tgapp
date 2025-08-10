#include "dispatchworker.h"
#include <QThread>
#include <QFile>
#include <QTextStream>

DispatchWorker::DispatchWorker(Mode mode,
                               const QString &usersFile,
                               const QString &groupName,
                               const QString &message,
                               QObject *parent)
    : QThread(parent), m_mode(mode), m_usersFile(usersFile), m_group(groupName), m_message(message) {}

void DispatchWorker::run() {
    // Placeholder: simulate sending messages or invites
    // TODO: integrate Telegram TDLib logic here
    QFile f(m_usersFile);
    QStringList lines;
    if (f.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QTextStream in(&f);
        while (!in.atEnd()) lines << in.readLine();
    }
    int total = lines.size();
    if (total == 0) {
        emit finished();
        return;
    }
    for (int i = 0; i < total; ++i) {
        QThread::sleep(1);
        emit log(QString("Processed %1").arg(lines.at(i)));
        emit progress(i + 1, total);
    }
    emit finished();
}
