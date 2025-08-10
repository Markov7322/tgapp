#include "collectpostsworker.h"
#include <QThread>
#include <QRegularExpression>
#include <QTimer>

CollectPostsWorker::CollectPostsWorker(const QString &channelUrl, QObject *parent)
    : QThread(parent), m_url(channelUrl) {}

void CollectPostsWorker::run() {
    // Placeholder implementation: simulate collecting posts
    // TODO: integrate Telegram TDLib logic here
    const int total = 5; // simulate 5 posts
    for (int i = 1; i <= total; ++i) {
        QThread::sleep(1);
        m_posts << QString("https://t.me/%1/%2").arg("demo_channel").arg(i);
        emit progress(i, total);
    }
    emit finished();
}
