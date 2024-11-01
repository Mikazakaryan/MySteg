# MySteg

MySteg is a steganography tool built with C++ and Qt. This project allows you to encode and decode hidden messages within audio files. 

## Prerequisites

- **Qt 5.15.x** or higher installed on your system.
  - You can install Qt via [Homebrew](https://brew.sh/) or the Qt installer from [Qt's official website](https://www.qt.io/download).
- **C++ compiler** compatible with Qt.
- **macOS** (this guide assumes macOS, but the project may also work on Linux or windows with modifications).

## Installation

### Step 1: Clone the Repository

Clone the repository to your local machine:

```bash
git clone https://github.com/username/MySteg.git
cd MySteg
```

### Step 2: Ensure `qmake` and `make` are Available

Make sure `qmake` is in your system PATH. You can verify this by running:

```bash
qmake -v
```

If `qmake` is installed correctly, this command should output the version of `qmake` and Qt.

## Usage

### Step 1: Build the Project

Use the `build.sh` script to build the project. This script runs `qmake` and `make` to compile the source code.

```bash
./build.sh
```

### Step 2: Run the Application

After building, you can run the application using the `run.sh` script:

```bash
./run.sh
```

### Step 3: Clean the Project

If you need to clean up all build artifacts, use the `clean.sh` script:

```bash
./clean.sh
```

## File Structure

- `build.sh`: Compiles the project using `qmake` and `make`.
- `run.sh`: Runs the MySteg application.
- `clean.sh`: Cleans up build artifacts.
- `MySteg.pro`: Qt project file.
- `MySteg.app`: macOS application bundle created after building.

## Scripts Overview

- **build.sh**: Compiles the project.
- **run.sh**: Launches the application.
- **clean.sh**: Removes all generated build files and artifacts.

