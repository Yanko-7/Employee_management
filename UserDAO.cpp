#include "UserDAO.h"

bool UserDAO::saveData(User& user)
{
    //保存
    string sql = "insert into user(id,user_name,password) values(\"" + user.id + "\",\"" + user.password + "\"); ";
    return DatabaseUtil::getInstance().saveData(sql);
}

bool UserDAO::updateData(User& user)
{
    //更新
    string sql = "update user set password = \"" + user.password + "\" where id = \"" + user.id + "\"; ";
    return DatabaseUtil::getInstance().updateData(sql);
}

bool UserDAO::deleteData(User& user)
{
    //删除
    string sql = "delete from user where id = \"" + user.id + "\"; ";
    return DatabaseUtil::getInstance().updateData(sql);
}

User* UserDAO::findData(string& id)
{
    //查找单个
    string sql = "select * from user where id =\"" + id + "\";";
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
        int idx = ncol;
        string id = result[idx];
        string name = result[idx + 1];
        string password = result[idx + 2];
        //释放资源
        sqlite3_free_table(result);
        return new User(id, password);
    }
}
