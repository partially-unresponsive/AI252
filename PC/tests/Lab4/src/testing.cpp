#include "VariadicTable.h"
// #include "dummy.h"

int
main()
{
  // Tiny Table
  {
    VariadicTable<std::string, double, int, std::string> vt({"Name", "Weight", "Age", "Brother"},
                                                            10);

    vt.addRow("Crocker", 180.2, 40, "John");
    vt.addRow("Shawrma", 175.3, 38, "Andrew");
    vt.addRow("Gourmand", 140.3, 27, "Fande");

    vt.print(std::cout);
  }
}