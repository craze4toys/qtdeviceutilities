/****************************************************************************
**
** Copyright (C) 2016 The Qt Company Ltd.
** Contact: https://www.qt.io/licensing/
**
** This file is part of the Device Utilities module of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:GPL$
** Commercial License Usage
** Licensees holding valid commercial Qt licenses may use this file in
** accordance with the commercial license agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and The Qt Company. For licensing terms
** and conditions see https://www.qt.io/terms-conditions. For further
** information use the contact form at https://www.qt.io/contact-us.
**
** GNU General Public License Usage
** Alternatively, this file may be used under the terms of the GNU
** General Public License version 3 or (at your option) any later version
** approved by the KDE Free Qt Foundation. The licenses are as published by
** the Free Software Foundation and appearing in the file LICENSE.GPL3
** included in the packaging of this file. Please review the following
** information to ensure the GNU General Public License requirements will
** be met: https://www.gnu.org/licenses/gpl-3.0.html.
**
** $QT_END_LICENSE$
**
****************************************************************************/
#ifndef QNETWORKSETTINGSUSERAGENTPRIVATE_H
#define QNETWORKSETTINGSUSERAGENTPRIVATE_H

//
//  W A R N I N G
//  -------------
//
// This file is not part of the Qt API.  It exists for the convenience
// of other Qt classes.  This header file may change from version to
// version without notice, or even be removed.
//
// We mean it.
//

#include <QObject>
#include "qnetworksettingsuseragent.h"

QT_BEGIN_NAMESPACE

class QNetworkSettingsUserAgentPrivate : public QObject
{
    Q_OBJECT
    Q_DECLARE_PUBLIC(QNetworkSettingsUserAgent)
public:
    explicit QNetworkSettingsUserAgentPrivate(QNetworkSettingsUserAgent* parent);
    virtual ~QNetworkSettingsUserAgentPrivate() {}
    void setPassphrase(const QString &passphrase);
    void cancel();
    QString m_passphrase;
    QNetworkSettingsUserAgent *q_ptr;
};

QT_END_NAMESPACE

#endif // QNETWORKSETTINGSUSERAGENTPRIVATE_H
