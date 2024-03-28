#!/bin/bash

echo "Installing Image Processor v0.0 on your system..."

cmake . && make image_processor

echo "Image Processor has been installed on your system."
echo "You can run it by calling `image_processor` in your terminal."
