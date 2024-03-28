#!/bin/bash

INSTALL_DIR="/usr/local/bin"

EXECUTABLE="image_processor"

remove_files() {
    echo "Removing files..."

    # Remove executable
    if [ -f "$INSTALL_DIR/$EXECUTABLE" ]; then
        rm "$INSTALL_DIR/$EXECUTABLE"
        echo "Executable removed: $INSTALL_DIR/$EXECUTABLE"
    fi
}

uninstall() {
    echo "Uninstalling $EXECUTABLE..."

    # Call function to remove files
    remove_files

    echo "Uninstallation complete."
}

uninstall

