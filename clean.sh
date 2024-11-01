#!/bin/bash

# Clean all build artifacts
echo "Cleaning build artifacts..."

# Remove object files
find . -type f -name "*.o" -exec rm -f {} +

# Remove Makefile
rm -f Makefile

# Remove qmake stash files
rm -f .qmake.stash

# Remove application bundle
rm -rf MySteg.app

# Remove moc (meta-object compiler) generated files
rm -f moc_*

# Optional: remove other build directories if used
rm -rf build/
rm -rf debug/
rm -rf release/

echo "Cleaned all build artifacts."
