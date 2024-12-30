#include <openbabel/obconversion.h>
#include <openbabel/mol.h>
#include <openbabel/generic.h>
#include <openbabel/graphsym.h>
#include <openbabel/atom.h>
#include <fstream>
#include <iostream>

using namespace OpenBabel;

int main()
{
  OBConversion conv;
  conv.SetInFormat("sdf");

  std::ifstream ifs("/Users/guanwang/Documents/GitHub/lanl2tz/open-babel-symmetry/resource/molecule.sdf");
  if (!ifs)
  {
    std::cerr << "Error: Failed to open molecule.sdf" << std::endl;
    if (std::ifstream("/Users/guanwang/Documents/GitHub/lanl2tz/open-babel-symmetry/resource/molecule.sdf").fail())
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

  OBGraphSym symmetry(&obmol);
  std::vector<unsigned int> symmetry_classes;
  std::cout << "Point Group: " << symmetry.GetSymmetry(symmetry_classes) << std::endl;
  for (auto &sym_class : symmetry_classes)
  {
    std::cout << sym_class << " ";
  }

  std::cout << std::endl;

  for (size_t i = 0; i < obmol.NumAtoms(); i++)
  {
    std::cout << "Atom " << obmol.GetAtomById(i)->GetAtomicNum() << ", ID: " << i << " is in symmetry class " << symmetry_classes[i] << std::endl;
  }

  return 0;
}
