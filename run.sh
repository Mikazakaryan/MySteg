#!/bin/bash

# Path to the application bundle
APP_PATH="MySteg.app"

# Check if the application bundle exists
if [ -d "$APP_PATH" ]; then
    echo "Running MySteg application..."
    open "$APP_PATH"  # Launch the .app bundle
else
    # Check if the main executable exists inside the .app bundle
    EXECUTABLE="$APP_PATH/Contents/MacOS/MySteg"
    if [ -f "$EXECUTABLE" ]; then
        echo "Running MySteg executable..."
        "$EXECUTABLE"  # Run the main executable directly
    else
        echo "Error: MySteg.app not found. Please build the project first."
    fi
fi
