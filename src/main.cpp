#include <openbabel/obconversion.h>
#include <openbabel/mol.h>
#include <fstream>
#include <iostream>

using namespace OpenBabel;

int main()
{
  OBConversion conv;
  conv.SetInFormat("sdf");

  std::ifstream ifs("molecule.sdf");
  if (!ifs)
  {
    std::cerr << "Error: Failed to open molecule.sdf" << std::endl;
    if (std::ifstream("molecule.sdf").fail())
    {
      std::cerr << "File does not exist or is inaccessible." << std::endl;
    }
    else
    {
      std::cerr << "Unknown error occurred while opening the file." << std::endl;
    }
    return 1;
  }

  OBMol obmol;
  if (!conv.Read(&obmol, &ifs))
  {
    std::cerr << "Error: Failed to read molecule.sdf" << std::endl;
    return 1;
  }

  return 0;
}
