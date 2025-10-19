# AmmoWidget for Unreal Engine

A simple ammunition display widget system for Unreal Engine projects.

## Overview

This project provides a C++ implementation of an ammo widget that displays the current ammunition count using different images. The system cycles through ammunition states (0-5 bullets) and updates the UI accordingly.

## Components

### AmmoWidget (`AmmoWidget.h`, `AmmoWidget.cpp`)
- **UAmmoWidget**: A UMG widget class that displays ammunition count
- **UpdateAmmoDisplay()**: Updates the displayed image based on current ammo count
- Supports an array of slate brushes for different ammo states (0-5 bullets)

### Character (`Character.h`, `Character.cpp`)
- **AMyCharacter**: Character class with ammunition management
- Handles fire input (left mouse button)
- Cycles ammunition from 5 down to 0, then resets to 5
- Automatically updates the AmmoWidget when firing

## Setup

1. Copy the C++ files to your Unreal Engine project's Source folder
2. Add the widget to your character's Blueprint
3. Create a UMG Widget Blueprint based on UAmmoWidget
4. Add an Image component named "AmmoImage" in the widget
5. Import your ammunition sprite images and add them to the AmmoBrushes array (indices 0-5)

## Usage

The ammunition system automatically updates when the player fires:
- Each fire action decrements the ammo count
- When reaching 0, the next fire resets to maximum (5 bullets)
- The widget displays the corresponding image for the current ammo count

## Requirements

- Unreal Engine (C++ project)
- UMG (Unreal Motion Graphics) module
- Ammunition sprite images for states 0-5

## License

This project is provided as-is for educational and development purposes.
