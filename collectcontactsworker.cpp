#include "collectcontactsworker.h"
#include <QThread>
#include <QVariantMap>

CollectContactsWorker::CollectContactsWorker(const QStringList &posts, QObject *parent)
    : QThread(parent), m_posts(posts) {}

void CollectContactsWorker::run() {
    // Placeholder implementation: simulate collecting commenters
    // TODO: integrate Telegram TDLib logic here
    int total = m_posts.size();
    for (int i = 0; i < total; ++i) {
        QThread::sleep(1);
        QVariantMap row;
        row["user_id"] = QString("%1").arg(1000 + i);
        row["username"] = QString("user%1").arg(i);
        row["first_name"] = QString("Name%1").arg(i);
        row["last_name"] = QString("Surname%1").arg(i);
        row["t.me_link"] = QString("https://t.me/user%1").arg(i);
        m_data << row;
        emit progress(i + 1, total);
    }
    emit finished();
}
