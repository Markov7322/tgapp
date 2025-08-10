#pragma once
#include <QThread>
#include <QStringList>

class DispatchWorker : public QThread {
    Q_OBJECT
public:
    enum Mode { Invite, Message };
    DispatchWorker(Mode mode,
                   const QString &usersFile,
                   const QString &groupName,
                   const QString &message,
                   QObject *parent = nullptr);
signals:
    void progress(int done, int total);
    void log(const QString &text);
    void finished();
protected:
    void run() override;
private:
    Mode m_mode;
    QString m_usersFile;
    QString m_group;
    QString m_message;
};
