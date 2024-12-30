#include <openbabel/obconversion.h>
#include <openbabel/mol.h>
#include <fstream>

using namespace OpenBabel;

int main() {
  OBConversion conv;
  conv.SetInFormat("sdf");
  OBMol obmol;
  conv.Read(&obmol, &ifs);

  return 0;
}
