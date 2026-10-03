//
// Created by Ayush on 01-10-2026.
//
#include <catch2/catch_test_macros.hpp>
#include <rapidcsv.h>
#include <sstream>
#include <string_view>
#include <eda-core/src/table.h>

TEST_CASE("Verify integration works", "[setup]")
{
    REQUIRE(2+2 == 4);
}

TEST_CASE("Verify csv parsing", "[rapidcsv]")
{
    std::string test_csv =
        "val1,val2\n"
        "10,20\n"
        "20,40\n";
    std::stringstream ss(test_csv);
    rapidcsv::Document doc(ss);
    REQUIRE(doc.GetRowCount() == 2);
    REQUIRE(doc.GetColumnCount() == 2);
    REQUIRE(doc.GetCell<int>("val1", 0) == 10);
}

TEST_CASE("Verify table parsing", "[table]")
{
    std::istringstream ss{
        "# comment expected here\n"
        "val1,val2\n"
        "10,20\n"
        "20,40\n"
    };
    auto result = table::load_csv(ss);
    REQUIRE(result.has_value());
    const auto& tab = *result;
    REQUIRE(tab.row_count() == 2);
    REQUIRE(tab.column_count() == 2);
    REQUIRE(tab.column("val1")[0] == 10);
    REQUIRE(tab.column("val1")[1] == 20);
}

TEST_CASE("Verify comments are skipped", "[table]")
{
    std::istringstream ss{
        "# comment expected here\n"
        "val1,val2\n"
        "10,20\n"
        "20,40\n"
    };
    auto result = table::load_csv(ss);
    REQUIRE(result.has_value());
    const auto& tab = *result;
    REQUIRE(tab.row_count() == 2);
    REQUIRE(tab.column_count() == 2);
    REQUIRE(tab.column("val1")[0] == 10);
    REQUIRE(tab.column("val1")[1] == 20);
}