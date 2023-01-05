#include "EmployeeDAO.h"

bool EmployeeDAO::saveData(Employee& employee)
{
    string sql = "insert into employee(id,name,city,position,manager_id,salary) values(\""
        + employee.getID() + "\",\"" + employee.getName() + "\",\"" + employee.getCity() + "\",\"" + employee.getStringPosition() + "\",\""
        + employee.getManager_id() + "\"," + to_string(employee.getSalary()) + "); ";
    return DatabaseUtil::getInstance().saveData(sql);
}

bool EmployeeDAO::updateData(Employee& employee)
{
    string sql = "update employee set name = \"" + employee.getName() + "\",city = \"" + employee.getCity() + "\", position =\"" + employee.getStringPosition() + "\", manager_id = \""
        + employee.getManager_id() + "\", salary = " + to_string(employee.getSalary()) + " where id = \"" + employee.getID() + "\";";
    return DatabaseUtil::getInstance().updateData(sql);
}

bool EmployeeDAO::deleteData(Employee& employee)
{
    string sql = "delete from employee where id = \"" + employee.getID() + "\";";
    return DatabaseUtil::getInstance().deleteData(sql);
}

Employee* EmployeeDAO::findData(string& id)
{
    //���ҵ���
    string sql = "select * from employee where id =\"" + id + "\";";
    int nrow, ncol;
    char** result = NULL;
    DatabaseUtil::getInstance().find(sql, &result, nrow, ncol);
    if (nrow == 0 || ncol == 0) {
        cout << "����ʧ�ܣ��޸�id  " << id << endl;
        //�ͷ���Դ
        sqlite3_free_table(result);
        return NULL;
    }
    else {
        //��ʼ�±�idx
        int idx = ncol;
        string id = result[idx];
        string name = result[idx + 1];
        string city = result[idx + 2];
        EmployeePosition position = EmployeePosition::Internship;
        if (strcmp(result[idx + 3], "Ordinary") == 0) {
            position = EmployeePosition::Ordinary;
        }
        else if (strcmp(result[idx + 3], "Senior") == 0) {
            position = EmployeePosition::Senior;
        }
        string manager_id = result[idx + 4];
        string salary = result[idx + 5];
        //�ͷ���Դ
        sqlite3_free_table(result);
        return new Employee(id, name, city, position, manager_id, atof(salary.c_str()));
    }
}

set<Employee*> EmployeeDAO::findAll()
{
    set<Employee*> ret;
    Employee* employee;
    string sql = "select * from employee;";
    int nrow, ncol;
    char** result = NULL;
    DatabaseUtil::getInstance().find(sql, &result, nrow, ncol);
    int idx = ncol;
    for (int i = 0; i < nrow; i++) {
        //���η��ʸ���employee
        string id = result[idx];
        string name = result[idx + 1];
        string city = result[idx + 2];
        EmployeePosition position = EmployeePosition::Internship;
        if (strcmp(result[idx + 3], "Ordinary") == 0) {
            position = EmployeePosition::Ordinary;
        }
        else if (strcmp(result[idx + 3], "Senior") == 0) {
            position = EmployeePosition::Senior;
        }
        string manager_id = result[idx + 4];
        string salary = result[idx + 5];
        employee = new Employee(id, name, city, position, manager_id, atof(salary.c_str()));

        //���뷵�ؼ���
        ret.insert(employee);

        //������һ��employee���ݣ�������ʼ�±�
        idx += ncol;
    }
    //�ͷ���Դ
    sqlite3_free_table(result);
    return ret;
}
