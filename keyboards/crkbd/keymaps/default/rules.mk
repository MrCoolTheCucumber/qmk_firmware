MCU = RP2040             # Explicitly sets the controller (optional if handled by command line)
BOOTLOADER = rp2040      # Sets bootloader type
CONVERT_TO = promicro_rp2040 # Ensures pin conversion for Sea-Picro

# Feature Flags
MOUSEKEY_ENABLE = yes    # Enables Mouse Keys (for your Nav layer)
EXTRAKEY_ENABLE = yes    # Enables Media keys (Volume, Brightness)
CONSOLE_ENABLE = no      # Disables debug console (saves space)
COMMAND_ENABLE = no      # Disables extra QMK commands (saves space)
COMBO_ENABLE = yes       # Enables the Combos used in your keymap
CAPS_WORD_ENABLE = yes   # Enables the Caps Word behavior
ENCODER_ENABLE = no      # Enables the Rotary Encoders
LTO_ENABLE = yes         # Optimizes firmware size