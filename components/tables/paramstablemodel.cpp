#include "paramstablemodel.h"

ParamsTableModel::ParamsTableModel(QObject *parent)
    : QAbstractTableModel(parent)
{}

QVariant ParamsTableModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (role != Qt::DisplayRole)
        return QVariant();

    if(orientation == Qt::Horizontal){
        if(role == Qt::DisplayRole){
            switch(section){
            case 0:
                return QVariant(tr(""));
            case 1:
                return QVariant(tr("Name"));
            case 2:
                return QVariant(tr("Value"));
            case 3:
                return QVariant(tr("Comment"));
            }

        }
    }
    return QVariant();
}

bool ParamsTableModel::setHeaderData(int section,
                                     Qt::Orientation orientation,
                                     const QVariant &value,
                                     int role)
{
    if (value != headerData(section, orientation, role)) {
        // FIXME: Implement me!
        emit headerDataChanged(orientation, section, section);
        return true;
    }
    return false;
}

int ParamsTableModel::rowCount(const QModelIndex &parent) const
{
    if (parent.isValid())
        return 0;

    // FIXME: Implement me!
    return 1;
}

int ParamsTableModel::columnCount(const QModelIndex &parent) const
{
    if (parent.isValid())
        return 0;

    // FIXME: Implement me!

    return 4;
}

QVariant ParamsTableModel::data(const QModelIndex &index, int role) const
{
    // FIXME: Implement me!
    if(role == Qt::DisplayRole){
        return QString("Hello %1 %2")
            .arg(index.row())
            .arg(index.column());
    }
    return QVariant();
}
/*
bool ParamsTableModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    if (data(index, role) != value) {
        // FIXME: Implement me!
        emit dataChanged(index, index, {role});
        return true;
    }
    return false;
}

Qt::ItemFlags ParamsTableModel::flags(const QModelIndex &index) const
{
    if (!index.isValid())
        return Qt::NoItemFlags;

    return QAbstractItemModel::flags(index) | Qt::ItemIsEditable; // FIXME: Implement me!
}

bool ParamsTableModel::insertRows(int row, int count, const QModelIndex &parent)
{
    beginInsertRows(parent, row, row + count - 1);
    // FIXME: Implement me!
    endInsertRows();
    return true;
}

bool ParamsTableModel::insertColumns(int column, int count, const QModelIndex &parent)
{
    beginInsertColumns(parent, column, column + count - 1);
    // FIXME: Implement me!
    endInsertColumns();
    return true;
}

bool ParamsTableModel::removeRows(int row, int count, const QModelIndex &parent)
{
    beginRemoveRows(parent, row, row + count - 1);
    // FIXME: Implement me!
    endRemoveRows();
    return true;
}

bool ParamsTableModel::removeColumns(int column, int count, const QModelIndex &parent)
{
    beginRemoveColumns(parent, column, column + count - 1);
    // FIXME: Implement me!
    endRemoveColumns();
    return true;
}
*/
