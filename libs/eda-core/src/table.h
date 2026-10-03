//
// Created by Ayush on 03-10-2026.
//

#ifndef EXOPLANET_EDA_TABLE_H
#define EXOPLANET_EDA_TABLE_H
#include <filesystem>
#include <optional>
#include <string>
#include <unordered_map>
#include <vector>
#include <optional>
#include <istream>
#include <span>


class table
{
public:
    table() = default;
    [[nodiscard]] static std::optional<table> load_csv(std::istream& in);
    [[nodiscard]] static std::optional<table> load_csv_file(const std::filesystem::path& pathName);

    [[nodiscard]] const std::vector<std::string>& column_names() const noexcept
    {
        return names_;
    };

    [[nodiscard]] std::span<const double> column(std::string_view name) const;
    [[nodiscard]] size_t column_count() const;
    [[nodiscard]] size_t row_count() const;

private:
    // Allows lookups with std::string_view without allocating a std::string, SMART find
    struct stringhash
    {
        using is_transparent = void;
        size_t operator()(std::string_view name) const noexcept
        {
            return std::hash<std::string_view>{}(name);
        };
    };

    [[nodiscard]] static double parse_cell(std::string_view s);
    std::unordered_map<std::string, std::vector<double>, stringhash, std::equal_to<>> columns_;
    std::vector<std::string> names_;
    size_t row_count_{};
};


#endif //EXOPLANET_EDA_TABLE_H