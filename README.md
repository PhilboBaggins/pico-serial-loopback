# Pico Serial Loopback

TODO: Add description .... what is this for... where will it be used

## Building

Run `build-debug.sh`

## Making a release

1. Complete and test code
2. Commit and push all changes
3. Tag last commit with version number (and push tag to origin)
4. Run `build-release.sh`
5. Move the following files (produced by `build-release.sh`) to the Production Share:
    1. Pico6502Helper-$VERSION.uf2
    2. Pico6502Helper-$VERSION.txt
