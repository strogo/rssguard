// This file is part of RSS Guard.
//
// Copyright (C) 2011-2016 by Martin Rotter <rotter.martinos@gmail.com>
//
// RSS Guard is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// RSS Guard is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with RSS Guard. If not, see <http://www.gnu.org/licenses/>.

#ifndef MESSAGEBROWSERPAGE_H
#define MESSAGEBROWSERPAGE_H

#include <QWebEnginePage>


class MessageBrowserPage : public QWebEnginePage {
    Q_OBJECT

  public:
    enum MessageStatusChange {
      MarkRead,
      MarkUnread,
      MarkStarred,
      MarkUnstarred
    };

    explicit MessageBrowserPage(QObject *parent = 0);

  protected:
    void javaScriptAlert(const QUrl &securityOrigin, const QString &msg);
    bool acceptNavigationRequest(const QUrl &url, NavigationType type, bool isMainFrame);

  signals:
    void messageStatusChangeRequested(int message_id, MessageBrowserPage::MessageStatusChange change);
};

#endif // MESSAGEBROWSERPAGE_H