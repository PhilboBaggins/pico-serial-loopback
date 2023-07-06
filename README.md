# Pico Serial Loopback

Firmware for making a [Raspberry Pi Pico](https://www.raspberrypi.com/documentation/microcontrollers/raspberry-pi-pico.html) present multiple USB CDC ports (virtual COM ports) which loopback to each other.

* Port 0 loops back to port 1
* Port 1 loops back to port 0
* Port 2 loops back to itself
* Port 3 loops back to itself

## Building

Run `build-debug.sh`

## Making a release

1. Complete and test code
2. Commit and push all changes
3. Tag last commit with version number (and push tag to origin)
4. Run `build-release.sh`
5. Move the following files (produced by `build-release.sh`) to the Production Share:
    1. PicoSerialLoopback-$VERSION.uf2
    2. PicoSerialLoopback-$VERSION.txt
