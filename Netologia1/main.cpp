#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <cassert>

class SqlSelectQueryBuilder
{
private:
    std::vector<std::string> columns_;
    std::string table_;
    std::map<std::string, std::string> where_conditions_;

public:
    SqlSelectQueryBuilder() = default;

    SqlSelectQueryBuilder& AddColumn(const std::string& column)
    {
        columns_.push_back(column);
        return *this;
    }

    SqlSelectQueryBuilder& AddFrom(const std::string& table)
    {
        table_ = table;
        return *this;
    }

    SqlSelectQueryBuilder& AddWhere(const std::string& column, const std::string& value)
    {
        where_conditions_[column] = value;
        return *this;
    }

    std::string BuildQuery() const
    {
        std::string query = "SELECT ";

        // Добавляем столбцы или *
        if (columns_.empty())
        {
            query += "*";
        }
        else
        {
            for (size_t i = 0; i < columns_.size(); ++i)
            {
                query += columns_[i];
                if (i != columns_.size() - 1)
                {
                    query += ", ";
                }
            }
        }

        // Добавляем таблицу
        if (!table_.empty())
        {
            query += " FROM " + table_;
        }

        // Добавляем условия WHERE
        if (!where_conditions_.empty())
        {
            query += " WHERE ";
            bool first = true;
            for (const auto& condition : where_conditions_)
            {
                if (!first)
                {
                    query += " AND ";
                }
                query += condition.first + "=" + condition.second;
                first = false;
            }
        }

        query += ";";
        return query;
    }
};

int main()
{
    SqlSelectQueryBuilder query_builder;
    query_builder.AddColumn("name").AddColumn("phone");
    query_builder.AddFrom("students");
    query_builder.AddWhere("id", "42").AddWhere("name", "John");

    std::string expected_query = "SELECT name, phone FROM students WHERE id=42 AND name=John;";
    std::string actual_query = query_builder.BuildQuery();

    assert(actual_query == expected_query && "Queries don't match!");

    return EXIT_SUCCESS;
}