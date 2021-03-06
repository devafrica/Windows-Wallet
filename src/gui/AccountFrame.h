// Copyright (c) 2011-2016 The Cryptonote developers
// Copyright (c) 2015-2016 XDN developers
// Copyright (c) 2016 Karbowanec developers
// Copyright (c) 2018 The ParsiCoin developers
// Copyright (c) 2019 The CryptoPayAfrica Team
// Distributed under the MIT/X11 software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#pragma once

#include <QFrame>

namespace Ui {
class AccountFrame;
}

namespace WalletGui {

class AccountFrame : public QFrame {
  Q_OBJECT
  Q_DISABLE_COPY(AccountFrame)

public:
  AccountFrame(QWidget* _parent);
  ~AccountFrame();

private:
  QScopedPointer<Ui::AccountFrame> m_ui;

  void updateWalletAddress(const QString& _address);
  void updateWalletBalance(quint64 _balance);
  void reset();

  Q_SLOT void copyAddress();
  Q_SLOT void showQR();
  Q_SLOT void clearLabel();

Q_SIGNALS:
  void showQRcodeSignal();

};

}
