#include "ManagerDAO.h"

bool ManagerDAO::saveData(Manager& manager)
{
    //保存
    string sql = "insert into manager(id,name) values(\"" + manager.getID() + "\",\"" + manager.getName() + "\"); ";
    return DatabaseUtil::getInstance().saveData(sql);
}

bool ManagerDAO::updateData(Manager& manager)
{
    //更新
    string sql = "update manager set name = \"" + manager.getName() + "\" where id = \"" + manager.getID() + "\";";
    return DatabaseUtil::getInstance().updateData(sql);
}

bool ManagerDAO::deleteData(Manager& manager)
{
    //删除
    string sql = "delete from manager where id = \"" + manager.getID() + "\";";
    return DatabaseUtil::getInstance().deleteData(sql);
}

Manager* ManagerDAO::findData(string& id)
{
    //查找单个
    string sql = "select * from manager where id =\"" + id + "\";";
    int nrow, ncol;
    char** result = NULL;
    DatabaseUtil::getInstance().find(sql, &result, nrow, ncol);
    if (nrow == 0 || ncol == 0) {
        cout << "查找失败：无该id  " << id << endl;
        //释放资源
        sqlite3_free_table(result);
        return NULL;
    }
    else {
        int idxCol = ncol;
        string id = result[idxCol];
        string name = result[idxCol + 1];
        //释放资源
        sqlite3_free_table(result);
        return new Manager(id, name);
    }
}