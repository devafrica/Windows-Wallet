// Copyright (c) 2011-2016 The Cryptonote developers
// Copyright (c) 2015-2016 XDN developers
// Copyright (c) 2016 Karbowanec developers
// Copyright (c) 2018 The ParsiCoin developers
// Copyright (c) 2019 The CryptoPayAfrica Team
// Distributed under the MIT/X11 software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#include "SortedTransactionsModel.h"
#include "TransactionsListModel.h"
#include "TransactionsModel.h"

namespace WalletGui {

TransactionsListModel::TransactionsListModel() : QSortFilterProxyModel() {
  setSourceModel(&SortedTransactionsModel::instance());
}

TransactionsListModel::~TransactionsListModel() {
}

bool TransactionsListModel::filterAcceptsColumn(int _sourceColumn, const QModelIndex& _sourceParent) const {
  quint32 column = sourceModel()->headerData(_sourceColumn, Qt::Horizontal, TransactionsModel::ROLE_COLUMN).toUInt();
  return column != TransactionsModel::COLUMN_FEE && column != TransactionsModel::COLUMN_HEIGHT && column != TransactionsModel::COLUMN_TYPE;

}

}