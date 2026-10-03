//
// Created by Ayush on 03-10-2026.
//

#include "table.h"
#include <iostream>
#include <rapidcsv.h>

std::optional<table> table::load_csv(std::istream& is)
{
    try
    {
        rapidcsv::Document doc(is,
            rapidcsv::LabelParams(0, -1),
            rapidcsv::SeparatorParams(),
            rapidcsv::ConverterParams(),
            rapidcsv::LineReaderParams(true, '#')
            );

        table t{};
        const auto& cols = doc.GetColumnNames();
        if (cols.empty()) return t;
        t.row_count_ = doc.GetRowCount();
        for (const auto& header: cols)
        {
            t.columns_[header] = doc.GetColumn<double>(header);
        }
        return t;
    }
    catch (const std::exception& e)
    {
        std::cerr << "Error parsing CSV file: " << e.what() << std::endl;
        return std::nullopt;
    }
}

std::optional<table> table::load_csv_file(const std::filesystem::path& path)
{
    try
    {
        std::ifstream ifs(path);
        return load_csv(ifs);
    }
    catch (const std::exception& e)
    {
        std::cerr << "Error parsing CSV file: " << e.what() << std::endl;
        return std::nullopt;
    }
}

std::span<const double> table::column(std::string_view name) const
{
    auto it = columns_.find(name);
    if (it == columns_.end()) throw std::out_of_range("Column missing: " + std::string(name));
    return it->second;
}

size_t table::row_count() const
{
    return row_count_;
}

size_t table::column_count() const
{
    return columns_.size();
}

static double parse_cell(std::string_view s)
{
    return 0.0;
}