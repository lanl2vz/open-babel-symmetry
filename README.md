# OpenBabel Symmetry Analysis

## Purpose

This repository contains a C++ application that uses the OpenBabel library to analyze molecular symmetry. The program:

- Reads molecular structures from SDF (Structure Data Format) files
- Determines the point group symmetry of molecules using OpenBabel's graph symmetry algorithms
- Classifies atoms into symmetry equivalence classes
- Outputs the point group and individual atom symmetry information

The included sample molecule (`resource/molecule.sdf`) is a C4H8 compound (cyclobutane) that demonstrates the symmetry analysis capabilities.

## Features

- **Point Group Detection**: Automatically determines the molecular point group
- **Atom Classification**: Groups topologically equivalent atoms into classes
- **SDF File Support**: Reads standard molecular file formats
- **Detailed Output**: Shows both overall symmetry and per-atom symmetry information

## Dependencies

- **OpenBabel 3.x**: Chemical file format conversion and molecular analysis library
- **CMake 3.10+**: Build system
- **C++11 compatible compiler**: GCC, Clang, or MSVC

## Building with CMake

### Prerequisites

1. **Install OpenBabel**:
   
   On macOS with Homebrew:
   ```bash
   brew install open-babel
   ```
   
   On Ubuntu/Debian:
   ```bash
   sudo apt-get install libopenbabel-dev
   ```
   
   On CentOS/RHEL:
   ```bash
   sudo yum install openbabel-devel
   ```

2. **Ensure CMake is installed**:
   ```bash
   cmake --version  # Should be 3.10 or higher
   ```

### Build Instructions

1. **Clone the repository**:
   ```bash
   git clone <repository-url>
   cd open-babel-symmetry
   ```

2. **Create a build directory**:
   ```bash
   mkdir build
   cd build
   ```

3. **Configure the project**:
   ```bash
   cmake ..
   ```
   
   If OpenBabel is installed in a non-standard location, you may need to specify the path:
   ```bash
   cmake -DOpenBabel3_DIR=/path/to/openbabel/lib/cmake/openbabel3 ..
   ```

4. **Build the project**:
   ```bash
   make
   ```
   
   Or on Windows with Visual Studio:
   ```bash
   cmake --build .
   ```

5. **Run the executable**:
   ```bash
   ./bin/main
   ```

### CMake Configuration Options

- `BUILD_SHARED_LIBS`: Set to `ON` to build shared libraries (default: `OFF`)
- `CMAKE_BUILD_TYPE`: Set build type (`Debug`, `Release`, `RelWithDebInfo`, `MinSizeRel`)

Example with custom configuration:
```bash
cmake -DCMAKE_BUILD_TYPE=Release -DBUILD_SHARED_LIBS=ON ..
```

## Usage

The program automatically reads the molecule from `resource/molecule.sdf` and outputs:

1. **Point Group**: The molecular point group symmetry
2. **Symmetry Classes**: Numerical classes for each atom
3. **Atom Details**: Atomic number, ID, and symmetry class for each atom

Example output:
```
Point Group: C2v
1 2 3 3 4 5 6 7 8 9 9 8
Atom 6, ID: 0 is in symmetry class 1
Atom 6, ID: 1 is in symmetry class 2
...
```

## File Structure

```
open-babel-symmetry/
├── CMakeLists.txt          # Main CMake configuration
├── README.md               # This file
├── src/
│   ├── CMakeLists.txt      # Source CMake configuration
│   └── main.cpp            # Main application source
├── resource/
│   └── molecule.sdf        # Sample molecule file
└── build/                  # Build directory (created during build)
    └── bin/
        └── main            # Compiled executable
```

## Troubleshooting

### OpenBabel Not Found
If CMake cannot find OpenBabel, try:
```bash
# Find where OpenBabel is installed
find /usr -name "*openbabel*" 2>/dev/null
# or
pkg-config --cflags --libs openbabel-3
```

Then specify the path in CMake:
```bash
cmake -DOpenBabel3_ROOT=/path/to/openbabel ..
```

### Compilation Errors
- Ensure you have a C++11 compatible compiler
- Check that OpenBabel development headers are installed
- Verify CMake version is 3.10 or higher

## Contributing

1. Fork the repository
2. Create a feature branch
3. Make your changes
4. Test the build process
5. Submit a pull request

## License

[Add your license information here]